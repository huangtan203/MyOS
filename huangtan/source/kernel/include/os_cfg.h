#ifndef OS_CFG_H
#define OS_CFG_H


#define GDT_TABLE_SIZE 256
#define KERNEL_SELECTOR_CS 1<<3
#define KERNEL_SELECTOR_DS 2<<3
#define KERNEL_STACK_SIZE (8*1024)

#define OS_TICK_MS 10 //每毫秒的时钟数
#define OS_VERSION              "0.0.1" 
#endif