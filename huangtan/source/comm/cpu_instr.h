//一些简单汇编的封装
#ifndef CPU_INSTR_H
#define CPU_INSTR_H
#include"types.h"
static inline uint8_t inb(uint16_t port){
    uint8_t ret;
    __asm__ __volatile__("inb %[p], %[v]" : [v]"=a"(ret) : [p]"d"(port));
    //"d"表示使用通用寄存器EDX来传递输入操作数
    //"a"表示将结果存储在寄存器EAX
    return ret;
}
static inline uint16_t inw(uint16_t port){
    uint16_t ret;
    __asm__ __volatile__("in %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}
static inline void outb(uint16_t port, uint8_t val){
    __asm__ __volatile__("outb %[v],%[p]" : : [v]"a"(val), [p]"d"(port));
}
static inline void cli(){
    __asm__ __volatile__("cli");
}
static inline void sti(){  
    __asm__ __volatile__("sti");
}
static inline void hlt(){
    __asm__ __volatile__("hlt");
}
static inline void pause(){
    __asm__ __volatile__("pause");
}
static inline uint32_t rdtsc(){
    uint32_t ret;
    __asm__ __volatile__("rdtsc" : "=a"(ret));
    return ret;
}
static inline void lgdt(uint32_t start,uint32_t size){
    struct 
    {
        uint16_t limit;
        uint16_t start15_0;
        uint16_t start31_16;
    }gdt;
    gdt.limit=size-1;   
    gdt.start15_0=start&0xffff;
    gdt.start31_16=(start>>16);
    __asm__ __volatile__("lgdt %[g]" : : [g]"m"(gdt));
    
}
static inline void lidt(uint32_t start,uint32_t size){
    struct 
    {
        uint16_t limit;
        uint16_t start15_0;
        uint16_t start31_16;
    }idt;
    idt.limit=size-1;   
    idt.start15_0=start&0xffff;
    idt.start31_16=(start>>16);
    __asm__ __volatile__("lidt %0"::"m"(idt));
}
static inline uint32_t read_cr0(){
    uint32_t ret;
    __asm__ __volatile__("mov %%cr0, %[v]" : [v]"=r"(ret));
    return ret;
}
static inline void write_cr0(uint32_t val){
    __asm__ __volatile__("mov %[v], %%cr0" : : [v]"r"(val));
}
static inline uint32_t read_cr2(){
    uint32_t ret;
    __asm__ __volatile__("mov %%cr2, %[v]" : [v]"=r"(ret));
    return ret;
}
static inline void write_cr2(uint32_t val){
    __asm__ __volatile__("mov %[v], %%cr2" : : [v]"r"(val));
}
static inline uint32_t read_cr3(){
    uint32_t ret;
    __asm__ __volatile__("mov %%cr3, %[v]" : [v]"=r"(ret));
    return ret;
}
static inline void write_cr3(uint32_t val){
    __asm__ __volatile__("mov %[v], %%cr3" : : [v]"r"(val));
}
static inline uint32_t read_cr4(){
    uint32_t ret;
    __asm__ __volatile__("mov %%cr4, %[v]" : [v]"=r"(ret));
    return ret;
}
static inline void write_cr4(uint32_t val){
    __asm__ __volatile__("mov %[v], %%cr4" : : [v]"r"(val));
}
static inline void write_tr(uint16_t tss_sel){
    __asm__ __volatile__("ltr %%ax" : : "a"(tss_sel));
}
static inline uint32_t read_eflags(){
    //标志寄存器和其他寄存器不太一样不能直接通过mov指令来读取
    uint32_t ret;
    __asm__ __volatile__("pushfl; popl %%eax" : "=a"(ret));
    return ret;
}
static inline void write_eflags(uint32_t val){
    __asm__ __volatile__("pushl %%eax; popfl" : : "a"(val));
}
static inline void far_jump(uint32_t selector,uint32_t offset){
    uint32_t addr[]={offset,selector};
    //*(%[a])：这是一个间接寻址（indirect addressing）表达式。*表示要跳转到寻址结果指向的地址。(%[a])表示使用变量 a 的值作为内存地址进行间接寻址
    __asm__ __volatile__("ljmpl *(%[a])" : : [a]"r"(addr));
}
    


#endif