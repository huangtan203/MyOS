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
void init_main(){
    for(;;){}
}