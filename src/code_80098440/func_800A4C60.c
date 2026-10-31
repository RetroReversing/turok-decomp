#include "common.h"

extern void alEvtqPostEvent(s32,s16*,s32); void func_800A4C60(s32 a,s16 b){s16 x[7];x[0]=10;x[2]=b;a+=0x48;alEvtqPostEvent(a,x,0);}
