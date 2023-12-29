#ifndef IRQ_H
#define IRQ_H
#include "comm/types.h"
#define IRQ0_DE 0
#define IRQ1_DB 1
#define IRQ2_NMI 2
#define IRQ3_BP 3
#define IRQ4_OF 4
#define IRQ5_BR 5
#define IRQ6_UD 6
#define IRQ7_NM 7
#define IRQ8_DF 8
#define IRQ10_TS 10
#define IRQ11_NP 11
#define IRQ12_SS 12
#define IRQ13_GP 13
#define IRQ14_PF 14
#define IRQ16_MF 16
#define IRQ17_AC 17
#define IRQ18_MC 18
#define IRQ19_XM 19
#define IRQ20_VE 20

#define IRQ0_TIMER 0x20
#define IRQ1_KEYBOARD 0x21

#define ERR_PAGE_P (1<<0)
#define ERR_PAGE_WR (1<<1)
#define ERR_PAGE_US (1<<1)


#define ERR_EXT (1<<0)
#define ERR_IDT (1<<1)

typedef struct _exception_frame_t{
    int gs,fs,es,ds;
    int edi,esi,ebp,esp,ebx,edx,ecx,eax;
    int num;
    int error_code;
    int eip,cs,eflags;//eip和cs，eflags也是硬件自动压入的寄存器
    int esp3,ss3;//这里指的是3特权级的栈指针 硬件自动压入的
}exception_frame_t;
typedef void (*irq_handler_t)(void);
void irq_init(void);
int irq_install(int irq_num,irq_handler_t handler);
void exception_handler_unknown(void);
void exception_handler_driver(void);
void exception_handler_Debug(void);
void exception_handler_NMI(void);
void exception_handler_breakpoint(void);
void exception_handler_overflow(void);
void exception_handler_bound_range(void);
void exception_handler_invalid_opcode(void);
void exception_handler_device_unavailable(void);
void exception_handler_double_fault(void);
void exception_handler_invalid_tss(void);
void exception_handler_segment_not_present(void);
void exception_handler_stack_segment_fault(void);
void exception_handler_general_protection(void);
void exception_handler_page_fault(void);
void exception_handler_fpu_error(void);
void exception_handler_alignment_check(void);
void exception_handler_machine_check(void);
void exception_handler_smd_exception(void);
void exception_handler_virtual_exception(void);


#define PIC0_ICW1 0X20
#define PIC0_ICW2 0X21
#define PIC0_ICW3 0X21
#define PIC0_ICW4 0X21
#define PIC0_OCW2 0X20
#define PIC0_IMR  0X21

#define PIC1_ICW1 0XA0
#define PIC1_ICW2 0XA1
#define PIC1_ICW3 0XA1
#define PIC1_ICW4 0XA1
#define PIC1_OCW2 0XA0
#define PIC1_IMR  0XA1


#define PIC_ICW1_ICW4	(1<<0)
#define PIC_ICW1_ALWAYS_1 (1<<4)
#define PIC_ICW4_8086 (1<<0)

#define PIC_OCW2_EOI (1<<5)

#define IRQ_PIC_START 0X20

void irq_enable(int irq_num);
void irq_disable(int irq_num);
void irq_disable_global(void);
void irq_enable_global(void);
typedef uint32_t irq_state_t;
irq_state_t irq_enter_protection();
void irq_leave_protection(irq_state_t state);

void pic_send_eoi(int irq_num);
#endif