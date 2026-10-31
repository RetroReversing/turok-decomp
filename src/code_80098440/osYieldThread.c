#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
u32 func_800A5750(void);void func_800A5770(u32);void func_800A5DEC(void *);extern u8 *D_800EF290;extern u8 D_800EF288;
void osYieldThread(void)
{
 register u32 saveMask;
 saveMask=func_800A5750();
 *(u16*)(D_800EF290+0x10)=2;
 func_800A5DEC(&D_800EF288);
 func_800A5770(saveMask);
}

