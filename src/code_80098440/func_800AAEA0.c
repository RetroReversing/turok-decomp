#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
s32 func_800AAEA0(u32 value)
{
 register u32 status;
 status=*(volatile u32*)0xA4040010;
 if(!(status&1)) return -1;
 *(volatile u32*)0xA4080000=value;
 return 0;
}

