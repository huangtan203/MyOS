#include "dev/console.h"
#include "tools/klib.h"
#include "comm/cpu_isnstr.h"
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
static void move_forward(console_t*console,int n){
    
}
static void show_char(console_t*console,char c){
    int offset=console->cursor_col+console->cursor_row*console->display_clos;
    disp_char_t*p=(disp_char_t*)(console->disp_base)+offset;
    p->c=c;
    p->foreground=console->foreground;
    p->background=console->background;
    move_forward(console,1);
}
int console_init(void){
    for(int i=0;i<CONSOLE_NR;i++){
        console_buf[i].disp_base=(disp_char_t *)CONSOLE_DISP_ADDR;
        console_buf[i].display_clos=CONSOLE_COL_MAX;
        console_buf[i].display_rows=CONSOLE_ROW_MAX;
        int current_pos=read_cursor_pos();
        console_buf[i].cursor_row=current_pos/console_buf[i].display_clos;
        console_buf[i].cursor_col=current_pos%console_buf[i].display_clos;
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