#include "common.h"

s32 func_800AFDD0(void); s32 func_800A6500(volatile s32 arg0,s32 *arg1) { if(func_800AFDD0()!=0) return -1; *arg1=*(volatile s32 *)(arg0|0xA0000000); return 0; }
