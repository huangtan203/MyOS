/*
    8253/8254是一种可编程定时器/计数器芯片，常用于x86体系结构中实现时钟中断。要设置8253/8254的时钟中断，需要进行以下步骤：
    确定计数器的工作模式：
    8253/8254有三个计数器，分别称为计数器0、计数器1和计数器2。每个计数器都有不同的工作模式，要根据需求选择适当的工作模式。常见的工作模式包括频率发生器模式、方波发生器模式、软件触发模式等。
    设置计数值：
    计数值决定了时钟中断发生的频率。8253/8254的计数器是16位的，可以设置计数值来控制时钟中断的频率。计数值可以通过向计数器端口（一般为0x40）写入值来设置。
    设置中断向量：
    时钟中断发生时，需要将控制流转到相应的中断处理程序。要设置中断处理程序的入口地址，可以通过向中断控制器（如8259A）设置中断向量来实现。
void setupTimerInterrupt() {
    // 设置工作模式，选择二进制计数方式和将计数器0通道作为定时器
    outportb(0x43, 0x34);

    // 设置计数值，这里假设要设置的中断频率为100Hz
    int count = 1193182 / 100;  // 计数值=时钟频率/中断频率
    outportb(0x40, count & 0xFF);
    outportb(0x40, (count >> 8) & 0xFF);

    // 设置中断向量为0x08，对应时钟中断
    setvect(0x08, interruptHandler);  // interruptHandler是中断处理程序的函数指针
}
*/

#include "dev/time.h"
#include "cpu/irq.h"
#include "comm/cpu_instr.h"
#include "os_cfg.h"


static uint32_t sys_tick;
void do_handler_timer(exception_frame_t *frame){
    sys_tick++;
    pic_send_eoi(IRQ0_TIMER);
    task_time_tick();
}

static void init_pit(void){
    uint32_t reload_count=(PIT_OSC_FREQ/(1000.0/OS_TICK_MS)); //每十毫秒tick++
    outb(PIT_COMMAND_MODE_PORT, PIT_CHANNEL0|PIT_LOAD_LOHI|PIT_MODE0); 
    outb(PIT_CHANNEL0_DATA_PORT,reload_count&0xff);
    outb(PIT_CHANNEL0_DATA_PORT,(reload_count>>8)&0xff);

    irq_install(IRQ0_TIMER, (irq_handler_t)exception_handler_timer);
    irq_enable(IRQ0_TIMER);
}

void time_init(void){
    sys_tick=0;
    init_pit();
}