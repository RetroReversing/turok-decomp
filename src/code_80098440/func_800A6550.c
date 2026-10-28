#include "common.h"

s32 func_800AFDD0(void); s32 func_800A6550(s32 arg0, volatile s32 arg1) { if (func_800AFDD0()) return -1; *(volatile s32 *)(arg0 | 0xA0000000)=arg1; return 0; }
