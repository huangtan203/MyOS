#ifndef BOOTINFO_H
#define BOOTINFO_H
#define BOOT_RAM_REGION_MAX 10 //ram区最大数量
typedef struct _boot_info_t{
    struct {
        uint32_t start;
        uint32_t size;
    }ram_region_cfg[BOOT_RAM_REGION_MAX];
    int ram_region_count;
}boot_info_t;
#endif