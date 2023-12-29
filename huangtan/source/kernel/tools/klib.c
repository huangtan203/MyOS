#include"tools/klib.h"
#include"comm/cpu_instr.h"
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
void kernel_strncpy(char*dest,char*src,int size){
    if(!dest||!src){
        return ;
    }
    char *d=dest;
    const char*s=src;
    while(*s!='\0'&&size--){
        *d++=*s++;
    }
    if(size==0){
        *(d-1)='\0';
    }else{
        *d='\0';
    }
    return ;
}
int kernel_strncmp(const char*s1,const char*s2,int size){
    if(!s1||!s2){
        return -1;
    }
    while(*s1!='\0'&&*s2!='\0'&&size--){
        if(*s1!=*s2){
            return *s1-*s2;
        }
        s1++;
        s2++;
    }
    return 0;
}
int kernel_strlen(const char*s){
    if(!s){
        return -1;
    }
    int len=0;
    while(*s!='\0'){
        len++;
        s++;
    }
    return len;
}
void kernel_strcat(char*dest,const char*src){
    if(!dest||!src){
        return ;
    }

}
void kernel_memcpy(void*dest,void*src,int size){
    if(!dest||!src||!size){
        return ;
    }
    uint8_t*d=(uint8_t*)dest;
    uint8_t*s=(uint8_t*)src;
    while(size--){
        *d++=*s++;
    }   
}
void kernel_memset(void*dest,uint8_t value,int size){
    if(!dest||!size){
        return ;
    }
    uint8_t*d=(uint8_t*)dest;
    while(size--){
        *d++=value;
    }
}
int kernel_memcmp(void*s1,void*s2,int size){

}
void kernel_itoa(char*buf,int num,int base){

}
void kernel_sprintf(char*buf,const char*fmt,...){

}
void kernel_vsprintf(char * buffer, const char * fmt, va_list args){

}