
//硬件检测、进入保护模式、加载内核

__asm__(".code16gcc");
#include "loader.h"
boot_info_t boot_info;
/*使用汇编方式输出字符串
    section .data
    hello db 'Hello, World!', 0
    section .text
        global _start
    _start:
        mov si, hello    ; 字符串地址存储到SI寄存器
        call print_string   ; 调用输出字符串的函数
        ; 退出程序
        mov eax, 1
        xor ebx, ebx
        int 0x80
    print_string:
        mov ah, 0x0E     ; 功能码，表示在TTY模式下输出字符
        mov al, [si]     ; 从内存中读取字符
        cmp al, 0        ; 检查字符是否为NULL终止符
        je finished        
        int 0x10         ; 调用中断将字符输出到屏幕
        inc si           ; 增加指针，以便读取下一个字符
        jmp print_string ; 继续输出字符
    finished:
        ret
        */
static void show_msg(const char*msg){
    
    const char *c=msg;
    while(*c){
        __asm__ __volatile__("mov $0xe, %%ah\n\t"
                             "mov %[ch], %%al\n\t"
                             "int $0x10"::[ch]"r"(*c));
        c++;
    }
}

//参考如下链接进行内存检测 https://wiki.osdev.org/Detecting_Memory_(x86)#BIOS_Function:_INT_0x15.2C_AH_.3D_0xC7
/*
// load memory map to buffer - note: regparm(3) avoids stack issues with gcc in real mode
int __attribute__((noinline)) __attribute__((regparm(3))) detectMemory(SMAP_entry_t* buffer, int maxentries)
{
	uint32_t contID = 0;
	int entries = 0, signature, bytes;
	do 
	{
		__asm__ __volatile__ ("int  $0x15" 
				: "=a"(signature), "=c"(bytes), "=b"(contID)
				: "a"(0xE820), "b"(contID), "c"(24), "d"(0x534D4150), "D"(buffer));
		if (signature != 0x534D4150) 
			return -1; // error
		if (bytes > 20 && (buffer->ACPI & 0x0001) == 0)
		{
			// ignore this entry
		}
		else {
			buffer++;
			entries++;
		}
	} 
	while (contID != 0 && entries < maxentries);
	return entries;
}
 
// in your main routine - memory map is stored in 0000:1000 - 0000:2FFF for example
[...] {
	[...]
	SMAP_entry_t* smap = (SMAP_entry_t*) 0x1000;
	const int smap_size = 0x2000;
 
	int entry_count = detectMemory(smap, smap_size / sizeof(SMAP_entry_t));
 
	if (entry_count == -1) {
		// error - halt system and/or show error message
		[...]
	} else {
		// process memory map
		[...]
	}
}
*/
static void detece_momery(void){
    uint32_t contID=0;
    SAMP_entry_t smap_entry;
    int signature, bytes;
    show_msg("Detecting memory map...");
    boot_info.ram_region_count=0;
    for(int i=0;i<BOOT_RAM_REGION_MAX;i++){
        SAMP_entry_t* entry=&smap_entry;
        __asm__ __volatile__ ("int  $0x15" 
				: "=a"(signature), "=c"(bytes), "=b"(contID)
				: "a"(0xE820), "b"(contID), "c"(24), "d"(0x534D4150), "D"(entry));

        if (signature != 0x534D4150){
            show_msg("failed.\r\n");
            return ;
        }

        if(bytes>20&&(entry->ACPI&0x01)==0){
            continue;
        }
        if(entry->Type==1){
            boot_info.ram_region_cfg[boot_info.ram_region_count].start=entry->BaseL;
            boot_info.ram_region_cfg[boot_info.ram_region_count].start=entry->LengthL;
            boot_info.ram_region_count++;
            
        }
        if(contID==0){
            break;
        }
    }
    show_msg("done.\r\n");
    //show_msg("RAM regions: %d\r\n",boot_info.ram_region_count);
}
uint16_t gdt_table[][4]={
    {0,0,0,0},
    {0xFFFF,0,0x9A00,0x00CF},
    {0xFFFF,0,0x9200,0x00CF},
};
static void enter_protect_mode()
{   
    cli();
    //开启A20中线使得可以访问1M以上的地址
    uint8_t v=inb(0x92);
    outb(0x92,v|2);
    lgdt((uint32_t)gdt_table,sizeof(gdt_table));
    //打开保护模式
    uint32_t cr0=read_cr0();
    write_cr0(cr0|1<<0);
    //长跳转进入保护模式，使用长跳转清空流水线
    far_jump(8,(uint32_t)protect_mode_entry);
}
void loader_entry(void){
    show_msg("Hello, World!\n");
    detece_momery();
    enter_protect_mode();
    for(;;){}

}