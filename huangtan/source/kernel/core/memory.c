#include "tools/klib.h"
#include  "tools/log.h"
#include "core/memory.h"
#include "../cpu/mmu.h"
static addr_alloc_t paddr_alloc;
static pde_t kernel_page_dir[PDE_CNT] __attribute__((aligned(MEM_PAGE_SIZE)));
static pde_t*current_page_dir(void){
    return (pde_t*)task_current()->tss.cr3;
}

static void addr_alloc_init(addr_alloc_t*alloc,uint8_t*bits,uint32_t start,uint32_t size,uint32_t page_size){
    mutex_init(&alloc->mutex);
    alloc->start = start;
    alloc->size = size;
    alloc->page_size = page_size;
    bitmap_init(&alloc->bitmap,bits,alloc->size,0);
}
static uint32_t addr_alloc_page(addr_alloc_t*alloc,int page_count){
    uint32_t addr=0;
    mutex_lock(&alloc->mutex);
    int page_index=bitmap_alloc_nbits(&alloc->bitmap,0,page_count);
    if(page_index>=0){
        addr=alloc->start+page_index*alloc->page_size;
    }
    mutex_unlock(&alloc->mutex);
    return addr;
}
static void addr_free_page(addr_alloc_t*alloc,uint32_t addr,int page_count){
    mutex_lock(&alloc->mutex);
    int page_index=(addr-alloc->start)/alloc->page_size;
    bitmap_set_bit(&alloc->bitmap,page_index,page_count,0);
    mutex_unlock(&alloc->mutex);
}

static void show_mem_info(boot_info_t *boot_info){
    log_printf("mem region:");
    for(int i=0;i<boot_info->ram_region_count;i++){
        log_printf("start:%x,size:%x",boot_info->ram_region_cfg[i].start,
        boot_info->ram_region_cfg[i].size);
    }
    log_printf("\n");
}
static uint32_t total_mem_size(boot_info_t *boot_info){
    uint32_t mem_size=0;
    for(int i=0;i<boot_info->ram_region_count;i++){
        mem_size+=boot_info->ram_region_cfg[i].size;
    }
    return mem_size;
}
pte_t* find_pte(pde_t*page_dir,uint32_t vaddr,int alloc){
    pte_t*page_table;
    pde_t*pde=page_dir+pde_index(vaddr);
    if(pde->present){
        page_table=(pte_t*)pde_paddr(pde);
    }else{
        if(alloc==0){
            return (pte_t*)0;
        }
        uint32_t pg_addr=addr_alloc_page(&paddr_alloc,1);
        if(pg_addr==0){
            return (pte_t*)0;
        }
        pde->v=pg_addr|PTE_P|PTE_W|PTE_U;
        page_table=(pte_t*)pg_addr;
        kernel_memset(page_table,0,MEM_PAGE_SIZE);
    }
    return page_table;
}
int memory_create_map(pde_t*page_dir,uint32_t vaddr,uint32_t paddr,int count,uint32_t perm){
    for(int i=0;i<count;i++){
        pte_t*pte=find_pte(page_dir,vaddr,1);
        if(pte==(pte_t*)0){
            return -1;
        }
        pte->v=paddr|perm|PTE_P;
        vaddr+=MEM_PAGE_SIZE;
        paddr+=MEM_PAGE_SIZE;
    }
    return 0;
}

void create_kernel_table(void){
    extern uint8_t s_text[],e_text[],s_data[],e_data[];
    extern uint8_t kernel_base[];
    static memory_map_t kernel_map[]={
        {kernel_base,s_text,0,PTE_W},
        {s_text,e_text,s_text,0},
        {s_data,(void*)(MEM_EBDA_START-1),s_data,PTE_W},
        {(void*)MEM_EXT_START,(void*)MEM_EXT_END,(void*)MEM_EXT_START,PTE_W},
    };
    kernel_memset(kernel_page_dir,0,sizeof(kernel_page_dir));
    for(int i=0;i<sizeof(kernel_map)/sizeof(memory_map_t);i++){
        memory_map_t*map=kernel_map+i;
        int vstart=down2((uint32_t)map->vstart,MEM_PAGE_SIZE);
        int vend=up2((uint32_t)map->vend,MEM_PAGE_SIZE);
        int page_count=(vend-vstart)/MEM_PAGE_SIZE;
        memory_create_map(kernel_page_dir,vstart,map->pstart,page_count,map->perm);
    }
}
void memory_init(boot_info_t*boot_info){
    extern uint8_t*mem_free_start;
    log_printf("mem init.");
    show_mem_info(boot_info);
    uint8_t* mem_free=(uint8_t*)&mem_free_start;
    uint32_t mem_up1MB_free=total_mem_size(boot_info)-MEM_EBDA_START;
    mem_up1MB_free=down2(mem_up1MB_free,MEM_PAGE_SIZE);
    log_printf("free memory...");
    addr_alloc_init(&paddr_alloc,mem_free,MEM_EXT_START,mem_up1MB_free, MEM_PAGE_SIZE);
    mem_free+=bitmap_byte_count(paddr_alloc.size/MEM_PAGE_SIZE);
    create_kernel_table();
    mmu_set_page_dir((uint32_t)kernel_page_dir);
}
uint32_t memory_create_uvm(void){
    //创建用户进程的页表
    pde_t*page_dir=(pde_t*)addr_alloc_page(&paddr_alloc,1);
    if(page_dir==0){
        return 0;
    }
    kernel_memset((void*)page_dir,0,MEM_PAGE_SIZE);
    uint32_t user_pde_start=pde_index(MEMORY_TASK_BASE);
    for(int i=0;i<user_pde_start;i++){
        page_dir[i].v=kernel_page_dir[i].v;
    }
    return (uint32_t)page_dir;
}
uint32_t memory_alloc_for_page_dir(uint32_t page_dir,uint32_t vaddr,uint32_t size,int perm){
    uint32_t curr_addr=vaddr;
    int page_count=up2(size,MEM_PAGE_SIZE)/MEM_PAGE_SIZE;
    vaddr=down2(vaddr,MEM_PAGE_SIZE);
    for(int i=0;i<page_count;i++){
        uint32_t paddr=addr_alloc_page(&paddr_alloc,1);
        if(paddr==0){
            log_printf("mem alloc failed...no memory");
            return 0;
        }
        int err=memory_create_map((pde_t*)page_dir,curr_addr,paddr,1,perm);
        if(err<0){
            log_printf("mem alloc failed...no memory");
            addr_free_page(&paddr_alloc,vaddr,i+1);
            return -1;
        }
        curr_addr+=MEM_PAGE_SIZE;
    }
    return 0;
}
int memory_alloc_page_for(uint32_t addr,uint32_t size,int perm){
    return memory_alloc_for_page_dir(task_current()->tss.cr3,addr,size,perm);
}
uint32_t memory_alloc_page(void){
    return addr_alloc_page(&paddr_alloc,1);
}
void memory_free_page(uint32_t addr){
    if(addr<MEMORY_TASK_BASE){
        addr_free_page(&paddr_alloc,addr,1);
    }else{
        pte_t*pte=find_pte(current_page_dir(),addr,0);
        addr_free_page(&paddr_alloc,pte_paddr(pte),1);
        pte->v=0;
    }
}
void memory_destroy_uvm(uint32_t page_dir){

}
uint32_t memory_copy_uvm(uint32_t page_dir){
    uint32_t to_page_dir=memory_create_uvm();
    if(to_page_dir==0){
        goto copy_uvm_failed;
    }
    uint32_t user_pde_start=pde_index(MEMORY_TASK_BASE);
    pde_t*pde=(pde_t*)page_dir+user_pde_start;
    for(int i=user_pde_start;i<PDE_CNT;i++,pde++){
        if(!pde->present){
            continue;
        }
        pte_t*pte=(pte_t*)pde_paddr(pde);
        for(int j=0;j<PTE_CNT;j++,pte++){
            if(!pte->present){
                continue;
            }
            uint32_t page=addr_alloc_page(&paddr_alloc,1);
            if(page==0){
                goto copy_uvm_failed;
            }
            uint32_t vaddr=(i<<22)|(j<<12);
            int err=memory_create_map((pde_t*)to_page_dir,vaddr,page,1,get_pte_perm(pte));
            if(err<0){
                goto copy_uvm_failed;
            }
            kernel_memcpy((void*)page,(void*)vaddr,MEM_PAGE_SIZE);
        }
    }
    return to_page_dir;
copy_uvm_failed:
    if(to_page_dir){
        memory_destroy_uvm(to_page_dir);
    }
    return -1;
}
uint32_t memory_get_paddr(uint32_t page_dir,uint32_t vaddr){
    pte_t*pte=find_pte(page_dir,vaddr,0);
    if(pte==(pte_t*)0){
        return 0;
    }
    return pte_paddr(pte)+vaddr&(MEM_PAGE_SIZE-1);
}
int memory_copy_uvm_data(uint32_t to,uint32_t page_dir,uint32_t from,uint32_t size){

}
char *sys_sbrk(int incr);