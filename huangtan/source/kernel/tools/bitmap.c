#include "tools/bitmap.h"
#include "tools/klib.h"

void bitmap_init(bitmap_t* bmp, uint8_t*bits,int bit_count,int init_bit){
    bmp->bits = bits;
    bmp->bit_count = bit_count;
    int bytes=bitmap_byte_count(bmp->bit_count);
    kernel_memset(bmp->bits,init_bit?0xFF:0,bytes);
}
int bitmap_byte_count(int bit_count){
    return (bit_count+7)/8;
}
int bitmap_get_bit(bitmap_t* bmp,int bit_index){
    return bmp->bits[bit_index>>3] & (1<<(bit_index%8));
}
void bitmap_set_bit(bitmap_t* bmp,int bit_index,int count,int bit){
    for(int i=0;i<count&&(bit_index<bmp->bit_count);i++,bit_index++){
        if(bit){
            bmp->bits[bit_index>>3] |= (1<<(bit_index%8));
        }else{
            bmp->bits[bit_index>>3] &= ~(1<<(bit_index%8));
        }
    }
}
int bitmap_is_set(bitmap_t* bmp,int bit_index){
    return bitmap_get_bit(bmp,bit_index)?1:0;
}
int bitmap_alloc_nbits(bitmap_t* bmp,int bit,int count){
    int search_idx=0;
    int ok_idx=0;
    while(search_idx<bmp->bit_count){
        if(bitmap_get_bit(bmp,search_idx)!=bit){
            search_idx++;
            continue;
        }
        ok_idx=search_idx;
        int i;
        for(i;i<count&&(search_idx<bmp->bit_count);i++){
            if(bitmap_get_bit(bmp,search_idx++)!=bit){
                ok_idx=-1;
                break;
            }
        }
        if(i>=count){
            bitmap_set_bit(bmp,ok_idx,count,~bit);
            return ok_idx;
        }
            
    }
    return -1;
}