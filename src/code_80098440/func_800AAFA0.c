#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
s32 func_800AAFA0(void)
{
 register u32 status;
 status=*(volatile u32 *)0xA410000C;
 if(status & 0x100) return 1;
 else return 0;
}

