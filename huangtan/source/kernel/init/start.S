#include "os_cfg.h"

      .text
      .extern kernel_init
      .extern init_main
      .global _start
_start: 
    push 4(%esp) //传指针/地址 模拟c调用函数 这里的意思是将[esp+4的值压栈],同时esp的值减4
    call kernel_init

    jmp $KERNEL_SELECTOR_CS,$gdt_reload
