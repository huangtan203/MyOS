#include "cpu/irq.h"
#include "core/task.h"
#include "ipc/sem.h"

void sem_init(sem_t *sem, int count){
    sem->count = count;
    list_init(&sem->wait_list);
}
void sem_wait(sem_t*sem){
    irq_state_t state=irq_enter_protection();
    task_t*task=task_current();
    if(sem->count<=0){
        //
        task_set_block(task);
        list_insert_last(&sem->wait_list,&task->wait_node);
        task_dispatch();
    }
    sem->count--;
    irq_leave_protection(state);
}
void sem_notify(sem_t*sem){
    irq_state_t state=irq_enter_protection();
    if(list_count(&sem->wait_list)){
        list_node_t*node=list_remove_first(&sem->wait_list);
        task_t*task=list_node_parent(node,task_t,wait_node);
        task_set_ready(task);
        task_dispatch();
    }else{
        sem->count++;
    }
    irq_leave_protection(state);
}
int sem_count(sem_t*sem){
    irq_state_t irq_state=irq_enter_protection();
    int count=sem->count;
    irq_leave_protection(irq_state);
    return count;
}