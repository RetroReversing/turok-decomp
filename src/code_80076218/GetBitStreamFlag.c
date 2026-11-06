#include "common.h"

s32 GetBitStreamFlag(u8*a,s32 b){return *(u8*)((s32)a+b/8) & (u8)(1 << (b%8));}
