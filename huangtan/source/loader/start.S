//进行硬件检测
//进入保护模式开启分页功能
//加载内核elf文件到0x100000处
    .code16
    .global _start
    .text
    .extern loader_entry
_start:
    //0x8000 存放在0x8000的第一条指令
    //沿用之前的寄存器状态
    jmp loader_entry
//进入32位保护模式
    .code32
    .text
    .global protect_mode_entry
    .extern load_kernel
protect_mode_entry:
    mov $16,%ax
    mov %ax,%ds 
    mov %ax,%es
    mov %ax,%fs
    mov %ax,%gs
    mov %ax,%ss
    //长跳转进入内核加载
    jmp $8,$load_kernel