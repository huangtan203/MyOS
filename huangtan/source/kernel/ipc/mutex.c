#include "cpu/irq.h"
#include "ipc/mutex.h"

void mutex_init(mutex_t *mutex){
    mutex->locked_count=0;
    mutex->task=(task_t*)0;
    list_init(&mutex->wait_list);
}

void mutex_lock(mutex_t *mutex){
    //如果互斥锁已经被锁住，则将当前任务加入等待队列
    irq_state_t irq_state=irq_enter_protection();
    task_t*curr=task_current();
    if(mutex->locked_count==0){
        mutex->locked_count=1;
        mutex->task=curr;
    }else if(mutex->task==curr){
        mutex->locked_count++;
    }else{
        task_t*curr=task_current();
        task_set_block(curr);
        list_insert_last(&mutex->wait_list,&curr->wait_node);
        task_dispatch();
    }
    irq_leave_protection(irq_state);
}

void mutex_unlock(mutex_t *mutex){
    irq_state_t irq_state=irq_enter_protection();
    task_t*curr=task_current();
    if(mutex->task==curr){
        if(--mutex->locked_count==0){
            mutex->task=(task_t*)0;
            if(list_count(&mutex->wait_list)!=0){
                list_node_t*task_node=list_remove_first(&mutex->wait_list);
                task_t*task=list_node_parent(task_node,task_t,wait_node);
                task_set_ready(task);
                mutex->locked_count=1;
                mutex->task=task;
                task_dispatch();
            }
        }
    }
    irq_leave_protection(irq_state);
}