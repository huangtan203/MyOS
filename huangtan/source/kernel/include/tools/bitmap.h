#ifndef BITMAP_H
#define BITMAP_H

#include "comm/types.h"

typedef struct _bitmap_t{
    int bit_count;
    uint8_t*bits;
}bitmap_t;
void bitmap_init(bitmap_t* bmp, uint8_t*bits,int bit_count,int init_bit);
int bitmap_byte_count(int bit_count);
int bitmap_get_bit(bitmap_t* bmp,int bit_index);
void bitmap_set_bit(bitmap_t* bmp,int bit_index,int count,int bit);
int bitmap_is_set(bitmap_t* bmp,int bit_index);
int bitmap_alloc_nbits(bitmap_t* bmp,int bit,int count);
#endif