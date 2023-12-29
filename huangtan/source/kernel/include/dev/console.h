#ifndef CONSOLE_H
#define CONSOLE_H
#include "comm/types.h"

#define CONSOLE_VIDEO_BASE 0Xb8000
#define CONSOLE_DISP_ADDR 0XB8000
#define CONSOLE_DISP_END (0XB8000+32*1024)
#define CONSOLE_ROW_MAX 25
#define CONSOLE_COL_MAX 80
#define ASCII_ESC 0X1B
#define ESC_PARAM_MAX 10


typedef enum _cclor_t{
    COLOR_Black=0,
    COLOR_Blue=1,
    COLOR_Green=2,
    COLOR_Cyan=3,
    COLOR_Red=4,
    COLOR_Magenta=5,
    COLOR_Brown=6,
    COLOR_LightGray=7,
    COLOR_DarkGray=8,
    COLOR_LightBlue=9,
    COLOR_LightGreen=10,
    COLOR_LightCyan=11,
    COLOR_LightRed=12,
    COLOR_LightMagenta=13,
    COLOR_Yellow=14,
    COLOR_White=15
}cclor_t;
typedef union{
    struct{
        char c;
        char foreground:4;
        char background:3;
    };
    uint16_t v;
}disp_char_t;

typedef struct _console_t{
    disp_char_t *disp_base;
    enum{
        CONSOLE_WRITE_NORMAL,
        CONSOLE_WRITE_ESC,
        CONSOLE_WRITE_SQUARE,
    }write_state;
    int cursor_row,cursor_col; //当前编辑的行和列
    int display_rows,display_cols; //显示界面的行数和列数
    int old_cursor_row,old_cursor_col; //保存的光标位置
    cclor_t foreground,background;
    int esc_param[ESC_PARAM_MAX]; //ESC[;;参数数量
    int curr_param_index;

}console_t;

int console_init(void);
int console_write(int dev,char *data,int len);
void console_close(int dev);
#endif