#include "common.h"

s32 func_80083D54(u8*a,s32 b){return *(u8*)((s32)a+b/8) & (u8)(1 << (b%8));}
