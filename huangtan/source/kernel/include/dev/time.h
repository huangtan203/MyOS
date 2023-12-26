#ifndef TIME_H
#define TIME_H

#include "comm/types.h"
#define PIT_OSC_FREQ 1193182

#define PIT_CHANNEL0_DATA_PORT 0X40
#define PIT_COMMAND_MODE_PORT 0X43
#define PIT_CHANNEL0 (0<<6)
#define PIT_LOAD_LOHI (3<<4)
#define PIT_MODE0 (3<<1)


void time_init();
void exception_handler_timer(void);
#endif