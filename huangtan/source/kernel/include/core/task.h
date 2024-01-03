#ifndef TASK_H
#define TASK_H

#include "comm/types.h"
#include "cpu/cpu.h"
#include "tools/list.h"
#define TASK_NAME_SIZE 32
#define TASK_TIME_SLICE_DEFAULT 10


typedef struct _task_t{
    enum{
        TASK_CREATED,
        TASK_RUNNING,
        TASK_SLEEP,
        TASK_READY,
        TASK_WATING
    }state;
    char name[TASK_NAME_SIZE];
    int sleep_ticks;
    int time_slice;
    int slice_ticks;
    tss_t tss;
    uint16_t tss_sel;
    list_node_t run_node;
    list_node_t all_node;
    int priority;
}task_t;

int task_init(task_t*task,const char*name,uint32_t entry,uint32_t esp);
void task_switch_from_to(task_t*from,task_t*to);
void task_set_ready(task_t*task);
void task_set_block(task_t*task);
void task_set_sleep(task_t*task,uint32_t sleep_ticks);
void task_set_wakeup(task_t*task);
int sys_yield(void);
void task_dispatch(void);
task_t*task_current(void);
void task_time_tick(void);
void sys_msleep(uint32_t ms);
typedef struct _task_manager_t{
    task_t*curr_task;
    list_t ready_list;
    list_t task_list;
    list_t sleep_list;
    task_t first_task;
    task_t idle_task;
}task_manager_t;
void task_manager_init(void);
void task_first_init(void);
task_t*task_first_task(void);
#endif