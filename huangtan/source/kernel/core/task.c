#include "comm/cpu_instr.h"
#include "core/task.h"
#include "tools/klib.h"
#include "tools/log.h"
#include "os_cfg.h"
#include "cpu/irq.h"
static task_manager_t task_manager;
static uint32_t idle_task_stack[IDLE_STACK_SIZE];
/*TSS（任务状态段）描述符与一般的段描述符有几个关键的区别：

1. 类型区别：
   - TSS 描述符的类型字段通常设置为特殊的 TSS 类型代码，例如 0x9。
   - 一般的段描述符可以有不同的类型，如代码段、数据段、系统段等。
2. 内容区别：
   - TSS 描述符所描述的是一个特殊的内存段，称为任务状态段。
   - 一般的段描述符描述的是代码段、数据段等常规内存段。
3. TSS 结构：
   - TSS 描述符关联着一个特殊的 TSS 结构，其中包含了任务的上下文信息。
   - 一般的段描述符并不直接关联特定的数据结构。
4. 应用场景：
   - TSS 描述符主要用于任务切换和多任务处理，保存和恢复任务的状态。
   - 一般的段描述符用于定义代码、数据等内存段的属性和位置，用于访问内存中的数据。
总体而言，TSS 描述符是一种特殊用途的段描述符，用于管理任务状态和任务切换，而一般的段描述符用于定义常规的内存段的属性和访问权限。*/
static int tss_init(task_t*task,uint32_t entry,uint32_t esp){
    int tss_sel=gdt_alloc_desc();
    if(tss_sel<0){
        log_printf("alloc tss failed.\n");
        return -1;
    }
    segment_desc_set(tss_sel,(uint32_t)&task->tss,sizeof(task->tss),
    SEG_P_PRESENT|SEG_DPL0|SEG_TYPE_TSS);
    kernel_memset(&task->tss,0,sizeof(task->tss));
    task->tss.eip=entry;
    task->tss.esp=task->tss.esp0=esp;
    task->tss.ss0=KERNEL_SELECTOR_DS;
    task->tss.eflags=EFLAGS_DEFAULT|EFLAGS_IF;
    task->tss.es=task->tss.ss=task->tss.ds=task->tss.fs=task->tss.gs=KERNEL_SELECTOR_DS;
    task->tss.cs=KERNEL_SELECTOR_CS;
    task->tss.iomap=0;
    task->tss_sel=tss_sel;
    return 0;
}

int task_init(task_t*task,const char*name,uint32_t entry,uint32_t esp){
    //(task!=(task_t*)0);
    int err=tss_init(task,entry,esp);
    if(err<0){
        log_printf("init task failed...\n");
        return err;
    }
    kernel_strncpy(task->name,name,TASK_NAME_SIZE);
    task->state=TASK_CREATED;
    task->sleep_ticks=0;
    task->priority=0;
    task->time_slice=TASK_TIME_SLICE_DEFAULT;
    task->slice_ticks=task->time_slice;
    list_node_init(&task->all_node);
    list_node_init(&task->run_node);
    list_node_init(&task->wait_node);
    irq_state_t state=irq_enter_protection();
    task_set_ready(task);
    list_insert_last(&task_manager.task_list,&task->all_node);
    irq_leave_protection(state);
    return 0;
}

void simple_switch(uint32_t **from,uint32_t *to);
void task_switch_from_to(task_t*from,task_t*to){
    switch_to_tss(to->tss_sel);
}
void task_first_init(void){
    task_init(&task_manager.idle_task,"first task",0,0);
    write_tr(task_manager.idle_task.tss_sel);
    task_manager.curr_task=&task_manager.first_task;
}

task_t*task_first_task(void){
    return &task_manager.first_task;
}
void task_set_block(task_t*task){
    if(task!=&task_manager.idle_task){
        list_remove(&task_manager.ready_list,&task->run_node);
    }
}

static void idle_task_entry(void){
    for(;;){
        hlt();
    }
}

void task_manager_init(void){
    list_init(&task_manager.ready_list);
    list_init(&task_manager.task_list);
    list_init(&task_manager.sleep_list);
    task_init(&task_manager.idle_task,"idle task",(uint32_t)idle_task_entry,(uint32_t)(idle_task_stack + IDLE_STACK_SIZE));
    task_manager.curr_task=(task_t*)0;
}

void task_set_ready(task_t*task){
    if(task!=&task_manager.idle_task){
        list_insert_last(&task_manager.ready_list,&task->run_node);
        task->state=TASK_READY;
    }
}

static task_t*task_next_run(void){
    if(list_count(&task_manager.ready_list)==0){
        return &task_manager.idle_task;
    }
    list_node_t*task_node=list_first(&task_manager.ready_list);
    return list_node_parent(task_node,task_t,run_node);
}

void task_set_sleep(task_t*task,uint32_t sleep_tick){
    if(sleep_tick<=0){
        return ;
    }
    task->sleep_ticks=sleep_tick;
    task->state=TASK_SLEEP;
    list_insert_last(&task_manager.sleep_list,&task->run_node);
}

void task_set_wakeup(task_t*task){
    list_remove(&task_manager.sleep_list,&task->run_node);
}
task_t*task_current(void){
    return task_manager.curr_task;
}
int sys_yield(void){
    irq_state_t state=irq_enter_protection();
    if(list_count(&task_manager.ready_list)>1){
        task_t*task_cur=task_current();
        task_set_block(task_cur);
        task_set_ready(task_cur);
        task_dispatch();
    }
    return 0;
}
void task_dispatch(void){
    task_t*curr_task=task_current();
    task_t*next_task=task_next_run();
    if(curr_task!=next_task){
        task_manager.curr_task=next_task;
        next_task->state=TASK_RUNNING;
        task_switch_from_to(curr_task,next_task);
    }
}
void task_time_tick(void){
    task_t*curr_task=task_current();
    irq_state_t state=irq_enter_protection();
    if(--curr_task->slice_ticks<=0){
        curr_task->slice_ticks=curr_task->time_slice;
        task_set_block(curr_task);
        task_set_ready(curr_task);
    }
    list_node_t*curr=list_first(&task_manager.sleep_list);
    while(curr){
        task_t*task=list_node_parent(curr,task_t,run_node);
        if(--task->slice_ticks<=0){
            task_set_wakeup(task);
            task_set_ready(task);
        }
        curr=list_node_next(curr);
    }
    task_dispatch();
    irq_leave_protection(state);
}
void sys_msleep(uint32_t ms){
    if(ms<OS_TICK_MS){
        ms=OS_TICK_MS;
    }
    irq_state_t state=irq_enter_protection();
    task_set_block(task_manager.curr_task);
    task_set_sleep(task_manager.curr_task,(ms+(OS_TICK_MS-1))/OS_TICK_MS);
    task_dispatch();
    irq_leave_protection(state);
}