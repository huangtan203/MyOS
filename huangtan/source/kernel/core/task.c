#include "comm/cpu_instr.h"
#include "core/task.h"
#include "tools/klib.h"
#include "tools/log.h"
#include "os_cfg.h"


static int tss_init(task_t*task,uint32_t entry,uint32_t esp){
    
}

int task_init(task_t*task,uint32_t entry,uint32_t esp){
    
}

void simple_switch(uint32_t **from,uint32_t *to);
void task_switch_from_to(task_t*from,task_t*to){

}