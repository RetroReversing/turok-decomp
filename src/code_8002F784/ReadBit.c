#include "common.h"

s32 ReadBit(u8 *a,u32 b){if(a[b >> 3] & (u8)(0x80 >> (b & 7)))return 1;return 0;}
