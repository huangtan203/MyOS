#ifndef BOOTINFO_H
#define BOOTINFO_H
#define BOOT_RAM_REGION_MAX 10 //ram区最大数量
#include"types.h"
typedef struct _boot_info_t{
    struct {
        uint32_t start;
        uint32_t size;
    }ram_region_cfg[BOOT_RAM_REGION_MAX];
    int ram_region_count;
}boot_info_t;
#define SECTOR_SIZE 512
#define SYS_KERNEL_LOAD_ADDR (1024*1024) 


#endif