#include"tools/klib.h"
#include"comm/cpu_isntr.h"
int strings_count(char**start){
    //字符串的数量
    int count=0;
    if(start){
        while(*start++){
            count++;
        }
    }
    return count;
}
char*get_file_name(char*name){
    char*p=name;
    while(*p!='\0'){
        p++;
    }
    while(p>name&&*p!='/'&&*p!='\\'){
        p--;
    }
    return p+1;
}

void kernel_strcpy(char*dest,char*src){
    if(!dest||!src){
        return ;
    }
    while(*src!='\0'&&*dest!='\0'){  
        *dest++=*src++;
    }
    *dest='\0';
    return ;
}
void kernel_strncpy(char*dest,char*src,int size);
int kernel_strncmp(const char*s1,const char*s2,int size);
int kernel_strlen(const char*s);
void kernel_memcpy(void*dest,void*src,int size);
void kernel_memset(void*dest,uint8_t value,int size);
int kernel_memcmp(void*s1,void*s2,int size);
void kernel_itoa(char*buf,int num,int base);
void kernel_sprintf(char*buf,const char*fmt,...);
void kernel_vsprintf(char*buf,const char*fmt,va_list args);