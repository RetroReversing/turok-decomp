#include "common.h"

s32 func_8004F9AC(u8 *a,u32 b){if(a[b >> 3] & (u8)(0x80 >> (b & 7)))return 1;return 0;}
