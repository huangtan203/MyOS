#include"comm/boot_info.h"
#include"comm/cpu_instr.h"
#include"cpu/cpu.h"
#include"os_cfg.h"
#include"dev/time.h"
#include"cpu/irq.h"

static boot_info_t*init_boot_info;
void kernel_init(boot_info_t*boot_info){
    init_boot_info=boot_info;
    cpu_init(); //建立gdt表并加载
    irq_init(); //初始化中断描述表
    time_init(); //始终初始化 准备计时
}


void init_task_entry(void){
    int count=0;
    for(;;){
        log_printf("init task:%d",count++);
    }
}

void init_main(void){
    log_printf("Kernel is running...");
    log_printf("Version:%s,name:%s",OS_VERSION,"tiny x86 os");
    int count=0;
    for(;;){
        log_printf("first task:%d",count++);
    }
}