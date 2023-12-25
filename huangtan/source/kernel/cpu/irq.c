#include "cpu/irq.h"
#include "cpu/cpu.h"
#include "comm/cpu_isnstr.h"
#include "tools/log.h"
#include "os_cfg.h"
#define IDT_TABLE_NR 128
static gate_desc_t idt_table[IDT_TABLE_NR];

int irq_install(int irq_num,irq_handler_t handler){
    if(irq_num<0||irq_num>=IDT_TABLE_NR){
        return -1;
    }
    gate_desc_set(idt_table+irq_num,KERNEL_SELECTOR_CS,(uint32_t)handler, 
        GATE_P_PRESENT|GATE_DPL0|GATE_TYPE_IDT);
    return 0;
}
void irq_init(){
    //安装中断描述符
    //如果不需要借助栈段传参的话可以直接安装在idt表中
    for(int i=0;i<IDT_TABLE_NR;i++){
        gate_desc_set(idt_table+i,KERNEL_SELECTOR_CS,(uint32_t)exception_handler_unknown, 
            GATE_P_PRESENT|GATE_DPL0|GATE_TYPE_IDT);
    }
    irq_install(IRQ0_DE,exception_handler_driver);
    irq_install(IRQ1_DB,exception_handler_Debug);
    irq_install(IRQ2_NMI,exception_handler_NMI);
    irq_install(IRQ3_BP,exception_handler_breakpoint);
    irq_install(IRQ4_OF,exception_handler_overflow);
    irq_install(IRQ5_BR,exception_handler_bound_range);
    irq_install(IRQ6_UD,exception_handler_invalid_opcode);
    irq_install(IRQ7_NM,exception_handler_device_unavailable);
    irq_install(IRQ8_DF,exception_handler_double_fault);
    irq_install(IRQ10_TS,exception_handler_invalid_tss);
    irq_install(IRQ11_NP,exception_handler_segment_not_present);
    irq_install(IRQ12_SS,exception_handler_stack_segment_fault);
    irq_install(IRQ13_GP,exception_handler_general_protection);
    irq_install(IRQ14_PF,exception_handler_page_fault);
    irq_install(IRQ16_MF,exception_handler_fpu_error); 
    irq_install(IRQ17_AC,exception_handler_alignment_check);
    irq_install(IRQ18_MC,exception_handler_machine_check);
    irq_install(IRQ19_XM,exception_handler_smd_exception);
    irq_install(IRQ20_VE,exception_handler_virtual_exception);
    lidt((uint32_t)idt_table,sizeof(idt_table);

}