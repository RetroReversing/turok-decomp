#include "common.h"

extern volatile u32 D_A4600010; extern u32 D_80000308; s32 func_800A6680(u32 a0,s32 *a1){register u32 status; status=*(volatile u32 *)0xA4600010; while(status&3){status=*(volatile u32 *)0xA4600010;} *a1=*(volatile s32 *)(D_80000308|a0|0xA0000000);return 0;}
