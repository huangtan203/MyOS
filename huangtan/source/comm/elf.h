#ifndef ELF_H
#define ELF_H
typedef uint32_t Elf32_Addr;
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Off;
typedef uint32_t Elf32_Sword;
typedef uint32_t Elf32_Word;
#pragma pack(1)
#define EI_NIDENT 16
#define ELF_MAGIC 0x7F

#define ET_EXEC 2
#define ET_386 3 //80386处理器

#define PT_LOAD 1 //可加载类型
//https://ciphersaw.me/ctf-wiki/executable/elf/elf_structure/
typedef struct{
    char e_ident[EI_NIDENT]; //前四个字节魔数0x7f表示elf
    Elf32_Half e_type;
    Elf32_Half e_machine;
    Elf32_Word e_version; //目标文件的版本
    Elf32_Addr e_entry;
    Elf32_Off e_phoff; //程序头部表在文件中的字节偏移
    Elf32_Off e_shoff; //节头表在文件中的偏移 Section Header table OFFset 
    Elf32_Word e_flags;
    Elf32_Half e_ehsize; //ELF header size
    Elf32_Half e_phentsize; //程序头部表中每个表项的长度
    Elf32_Half e_phnum; //程序头部表的项数
    Elf32_Half e_shentsize; //节头的字节长度
    Elf32_Half e_shnum; //节头表中的项数
    Elf32_Half e_shstrndx; //字符串表索引
}Elf32_Ehdr;//elf header
typedef struct{
    Elf32_Word p_type;
    Elf32_Off p_offset;//文件开始到该段开头第一个字节的偏移
    Elf32_Addr p_vaddr;//在内存中的虚拟地址
    Elf32_Addr p_paddr;//物理地址
    Elf32_Word p_filesz;//文件镜像中的大小
    Elf32_Word p_memsz;//内存镜像中该段的大小
    Elf32_Word p_flags;//与段相关的标记
    Elf32_Word p_align;//对齐
}Elf32_Phdr;//程序头表
#pragma pack()
#endif