#include "cpu/irq.h"
#include "core/task.h"
#include "ipc/sem.h"

void sem_init(sem_t *sem, int count){
    sem->count = count;
    list_init(&sem->wait_list);
}