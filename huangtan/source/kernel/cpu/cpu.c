#include "comm/cpu_instr.h"
#include "cpu/cpu.h"
#include "os_cfg.h"

static segment_desc_t gdt_table[GDT_TABLE_SIZE]; 
void segment_desc_set(int selector, uint32_t base, uint32_t limit, uint8_t attr){
    segment_desc_t*desc=gdt_table+(selector>>3);
    if(limit>0xfffff){
        //长度太大改为4KB
        attr|=0x8000;
        limit>>=12;
    }
    desc->base15_0=base&0xffff;
    desc->limit15_0=limit&0xffff;
    desc->base23_16=(base>>16)&0xff;
    desc->attr=attr|(((limit>>16)&0xf)<<8);
    desc->base31_24=(base>>24)&0xff;  

}


void gate_desc_set(gate_desc_t*dest, uint32_t offset, uint16_t selector, uint8_t attr){
    dest->offset15_0=offset&0xffff;
    dest->selector=selector;
    dest->attr=attr;
    dest->offset31_16=(offset>>16)&0xffff;
}

int gdt_alloc_desc(void){
    for(int i=1;i<GDT_TABLE_SIZE;i++){
        segment_desc_t*desc=gdt_table+i;
        if(desc->attr==0){
            return i*sizeof(segment_desc_t);
        }
    }
    return -1;
}
void init_gdt(){
    for(int i=0;i<GDT_TABLE_SIZE;i++){
        segment_desc_set(i<<3,0,0,0);
    }
    segment_desc_set(KERNEL_SELECTOR_DS,0,0xffffffff,SEG_DPL0|SEG_P_PRESENT|SEG_S_NORMAL|SEG_TYPE_DATA
    |SEG_D|SEG_G|SEG_TYPE_RW);
    segment_desc_set(KERNEL_SELECTOR_CS,0,0xffffffff,SEG_DPL0|SEG_P_PRESENT|SEG_S_NORMAL|SEG_TYPE_CODE
    |SEG_D|SEG_G|SEG_TYPE_RW);

    lgdt((uint32_t)gdt_table,sizeof(gdt_table));
}
void switch_to_tss(uint32_t tss_selector){
    far_jump(tss_selector,0);
}
void cpu_init(void){
    init_gdt();
}