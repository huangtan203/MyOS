#include"loader.h"
#include"comm/elf.h"
/*
https://blog.csdn.net/guzhou_diaoke/article/details/8479033
相互转换
LBA = （柱面号 * 一个柱面的磁头数 + 磁头号） * 一个磁道上的扇区数 + （扇区号-1）
柱面号 = LBA / （一个柱面的磁头数 * 每个磁道扇区数）
令   x = LBA % （一个柱面的磁头数 * 每个磁道扇区数）
磁头号 = x / 每个磁道上的扇区数
扇区号 = x % 每个磁道上的扇区数 + 1
这段代码是使用IO端口进行直接读取磁盘数据的方式，与之前的中断方式有一些不同。
在该代码中，使用了以下IO端口：
- `0x1F6`：端口用于选择磁盘驱动器和LBA模式。
- `0x1F2`, `0x1F3`, `0x1F4`, `0x1F5`：这些端口用于设置LBA参数，将LBA地址传递给磁盘控制器。
- `0x1F7`：用于发送读取命令和检查磁盘状态。
在实际的读取过程中，先将LBA参数发送给磁盘控制器，并发送读命令（`0x24`）到端口`0x1F7`，
然后在一个循环中不断检查磁盘状态，直到数据就绪（`0x8`状态）。之后，通过读取端口`0x1F0`中的数据来读取扇区数据，
并将其写入缓冲区。
与中断方式相比，直接使用IO端口读取磁盘数据的方式更加底层，不依赖于中断处理程序。
这使得它可以更加精确地控制和管理磁盘读取过程。但同时，这种方式需要直接操作硬件资源和IO端口，
对于不同的操作系统和硬件环境可能会有所不同，并且需要更多的注意和适配。
*/
static void read_disk(int sector,int sector_count,uint8_t*buffer){
    outb(0x1F6,0xE0);
    outb(0x1F2,(uint8_t)(sector_count>>8));
    outb(0x1F3,(uint8_t)(sector>>24));
    outb(0x1F4,0);
    outb(0x1F5,(uint8_t)0);

    outb(0x1F2,(uint8_t)(sector_count));
    outb(0x1F3,(uint8_t)(sector));
    outb(0x1F4,(uint8_t)(sector>>8));
    outb(0x1F5,(uint8_t)(sector>>16));
    outb(0x1F7,(uint8_t)0x24);

    uint16_t*data_buffer=(uint16_t*)buffer;
    while(sector_count-->0){
        while((inb(0x1F7)&0x80==0)){}
        for(int i=0;i<SECTOR_SIZE/2;i++){
            *data_buffer++=inw(0x1F0);
        }
    }
}
static uint32_t reload_elf_file(uint8_t*file_buffer){
    Elf32_Ehdr*elf_hdr=(Elf32_Ehdr*)file_buffer;
    if(elf_hdr->e_ident[0]!=0x7f || elf_hdr->e_ident[1]!='E' || elf_hdr->e_ident[2]!='L' 
    || elf_hdr->e_ident[3]!='F'){
        return 0;
    }
    for(int i=0;i<elf_hdr->e_phnum;i++){
        Elf32_Phdr*phdr=(Elf32_Phdr*)(file_buffer+elf_hdr->e_phoff)+i;
        if(phdr->p_type!=PT_LOAD){
            continue;
        }
        uint8_t *dest_addr=(uint8_t*)phdr->p_paddr;
        uint8_t *src_addr=phdr->p_offset+file_buffer;
        for(int j=0;j<phdr->p_filesz;j++){
            *dest_addr++=*src_addr++;
        }
        dest_addr=(uint8_t*)phdr->p_paddr+phdr->p_filesz;
        for(int j=0;j<phdr->p_memsz-phdr->p_filesz;j++){
            *dest_addr++=0;
        }
        
    }
    return elf_hdr->e_entry;
}
static void die(){
    for(;;){}
}
void load_kernel(void){
    //读取磁盘
    read_disk(100,500,(uint8_t*)SYS_KERNEL_LOAD_ADDR);
    uint32_t kernel_entry=reload_elf_file((uint8_t*)SYS_KERNEL_LOAD_ADDR);
    if(kernel_entry==0){
        die(-1);
    }
    ((void(*)(boot_info_t*))kernel_entry)(&boot_info);
}