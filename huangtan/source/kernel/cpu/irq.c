#include "cpu/irq.h"
#include "cpu/cpu.h"
#include "comm/cpu_isnstr.h"
#include "tools/log.h"
#include "os_cfg.h"
#define IDT_TABLE_NR 128
static gate_desc_t idt_table[IDT_TABLE_NR];

static void dump_core_regs(exception_frame_t*frame){
    uint32_t esp,ss;
    if(frame->cs&0x7){
        ss=frame->ds;
        esp=frame->esp;
    }else{
        ss=frame->ss3;
        esp=frame->esp3;
    }
    
}
static void do_default_handler(exception_frame_t*frame,const char*message){
    log_printf("----------------");
    log_printf("IRQ/Exception happend:%s.",message);

    dump_core_regs(frame);
    log_printf("----------------");
    for(;;){
        hlt();
    }
}
static void init_pic(void){
    outb(PIC0_ICW1, PIC_ICW1_ALWAYS_1 | PIC_ICW1_ICW4);

    // 对应的中断号起始序号0x20
    outb(PIC0_ICW2, IRQ_PIC_START);

    // 主片IRQ2有从片
    outb(PIC0_ICW3, 1 << 2);

    // 普通全嵌套、非缓冲、非自动结束、8086模式
    outb(PIC0_ICW4, PIC_ICW4_8086);

    // 边缘触发，级联，需要配置icw4, 8086模式
    outb(PIC1_ICW1, PIC_ICW1_ICW4 | PIC_ICW1_ALWAYS_1);

    // 起始中断序号，要加上8
    outb(PIC1_ICW2, IRQ_PIC_START + 8);

    // 没有从片，连接到主片的IRQ2上
    outb(PIC1_ICW3, 2);

    // 普通全嵌套、非缓冲、非自动结束、8086模式
    outb(PIC1_ICW4, PIC_ICW4_8086);

    // 禁止所有中断, 允许从PIC1传来的中断
    outb(PIC0_IMR, 0xFF & ~(1 << 2));
    outb(PIC1_IMR, 0xFF);
}

void pic_send_eoi(int irq_num){
    irq_num-=IRQ_PIC_START;
    if(irq_num>=8){
        outb(PIC1_OCW2,PIC_OCW2_EOI);

    }
    outb(PIC0_OCW2,PIC_OCW2_EOI);
}
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
    init_pic();
}
void irq_enable(int irq_num){
    if(irq_num<IRQ_PIC_START){
        return;
    }
    irq_num-=IRQ_PIC_START;
    if(irq_num<8){
        uint8_t mask=inb(PIC0_TMR)&~(1<<irq_num);
        outb(PIC0_IMR,mask);
    }else{
        irq_num-=8;
        uint8_t mask=inb(PIC1_IMR)&~(1<<irq_num);
        outb(PIC1_IMR,mask);
    }
}

void irq_disable(int irq_num){
    if(irq_num<IRQ_PIC_START){
        return ;
    }
    irq_num-=IRQ_PIC_START;
    if(irq_num<8){
        uint8_t mask=inb(PIC0_TMR)|(1<<irq_num);
        outb(PIC0_IMR,mask);
    }else{
        irq_num-=8;
        uint8_t mask=inb(PIC1_IMR)|(1<<irq_num);
        outb(PIC1_IMR,mask);
    }
}

void irq_disable_global(void){
    cli();
}

void irq_enable_global(void){
    sti();
}

irq_state_t irq_enter_protection(void){
    irq_state_t state=read_eflags();
    irq_disable_global();
    return state;
}

void irq_leave_protection(irq_state_t state){
    write_eflags(state);
}