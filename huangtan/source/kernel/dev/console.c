#include "dev/console.h"
#include "tools/klib.h"
#include "comm/cpu_instr.h"
#define CONSOLE_NR 1
static console_t console_buf[CONSOLE_NR]; 
static int read_cursor_pos(){
    int pos=0;
    outb(0x3D4,0x0F); //写低地址
    pos|=inb(0x3D5); //读高地址
    outb(0x3D4,0x0E); //写高地址
    pos|=inb(0x3D5)<<8;
    return pos;
}
static void erase_rows(console_t*console,int start,int end){
    int offset=console->display_cols*start;
    int nr_bytes=console->display_cols*(end-start+1);
    disp_char_t*dest=console->disp_base+offset;
    for(int i=0;i<nr_bytes;i++){
        dest[i].c=' ';
        dest[i].foreground = console->foreground;
        dest[i].background = console->background;
    }
}
static void scroll_up(console_t*console,int n){
    disp_char_t*dest=console->disp_base;
    disp_char_t*src=console->disp_base+console->display_cols*n;
    uint32_t size=console->display_cols*(console->cursor_row-n)*sizeof(disp_char_t);
    kernel_memcpy(dest,src,size);
    erase_rows(console,console->display_rows-n,console->display_rows-1);
    console->cursor_row-=n;
}
static void mov_to_col0(console_t*console){
    console->cursor_col=0;
}
static void move_next_line(console_t*console){
    console->cursor_row++;
    if(console->cursor_row>=console->display_rows){
        scroll_up(console,1);
    }
}
static void move_forward(console_t*console,int n){
    for(int i=0;i<n;i++){
        console->cursor_col++;
        if(console->cursor_col>=console->display_cols){
            console->cursor_col=0;
            console->cursor_row++;
            if(console->cursor_row>=console->display_rows){
                scroll_up(console,1);
            }
        }
    }
}
static void show_char(console_t*console,char c){
    int offset=console->cursor_col+console->cursor_row*console->display_cols;
    disp_char_t*p=(disp_char_t*)(console->disp_base)+offset;
    p->c=c;
    p->foreground=console->foreground;
    p->background=console->background;
    move_forward(console,1);
}
static int move_backword(console_t*console,int n){
    int status=-1;
    for(int i=0;i<n;i++){
        if(console->cursor_col>0){
            console->cursor_col--;
            status=0;
        }else{
            if(console->cursor_row>0){
                console->cursor_row--;
                console->cursor_col=console->display_cols-1;
                status=0;
            }
        }
    }
    return status;
}
static void clear_display(console_t*console){
    int size=console->display_cols*console->display_rows;
    for(int i=0;i<size;i++){
        disp_char_t*p=(disp_char_t*)(console->disp_base)+i;
        p->c=' ';
        p->foreground=console->foreground;
        p->background=console->background;
    }
}
int console_init(void){
    for(int i=0;i<CONSOLE_NR;i++){
        console_buf[i].disp_base=(disp_char_t *)CONSOLE_DISP_ADDR;
        console_buf[i].display_cols=CONSOLE_COL_MAX;
        console_buf[i].display_rows=CONSOLE_ROW_MAX;
        int current_pos=read_cursor_pos();
        console_buf[i].cursor_row=current_pos/console_buf[i].display_cols;
        console_buf[i].cursor_col=current_pos%console_buf[i].display_cols;
        console_buf[i].old_cursor_col=console_buf[i].cursor_col;
        console_buf[i].old_cursor_row=console_buf[i].cursor_row;
        console_buf[i].foreground=COLOR_White;
        console_buf[i].background=COLOR_Black;
    }
    return 0;
}
int console_write(int dev,char *data,int len){

}
void console_close(int dev){

}