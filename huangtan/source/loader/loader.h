#ifndef LOADER_H
#define LOADER_H
#include "comm/types.h"
#include "comm/boot_info.h"
#include "comm/cpu_instr.h"
void protect_mode_entry(void);
extern boot_info_t boot_info;
//内存检测信息结构
typedef struct SAMP_entry{
    uint32_t BaseL;
    uint32_t BaseH;
    uint32_t LengthL;
    uint32_t LengthH;
    uint32_t Type;
    uint32_t ACPI;
}__attribute__((packed)) SAMP_entry_t;
#endif