#ifndef KLIB_H
#define KLIB_H
#include"comm/types.h"
#include<stdarg.h>

static inline uint32_t up2(uint32_t size,uint32_t bound){
    //当bound是2的整数次幂时 这两个值是相等的
    return (size+bound-1)&~(bound-1);
    //return (size+bound-1)/bound*bound;
}

static inline uint32_t down2(uint32_t size,uint32_t bound){
    return size&~(bound-1);
    //return size/bound*bound;
}
int strings_count(char**start);
char*get_file_name(char*name);
void kernel_strcpy(char*dest,char*src);
void kernel_strncpy(char*dest,char*src,int size);
int kernel_strncmp(const char*s1,const char*s2,int size);
int kernel_strlen(const char*s);
void kernel_memcpy(void*dest,void*src,int size);
void kernel_memset(void*dest,uint8_t value,int size);
int kernel_memcmp(void*s1,void*s2,int size);
void kernel_itoa(char*buf,int num,int base);
void kernel_sprintf(char*buf,const char*fmt,...);
void kernel_vsprintf(char*buf,const char*fmt,va_list args);
//下面为了防止出错直接复制过来的
#ifndef RELEASE
#define ASSERT(condition)    \
    if (!(condition)) panic(__FILE__, __LINE__, __func__, #condition)
void panic (const char * file, int line, const char * func, const char * cond);
#else
#define ASSERT(condition)    ((void)0)
#endif
#endif