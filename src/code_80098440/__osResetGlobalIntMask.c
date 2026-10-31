#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
u32 func_800A5750(void);void func_800A5770(u32);extern u32 D_800EE4DC;
void __osResetGlobalIntMask(u32 interrupt)
{
 register u32 saveMask;
 saveMask=func_800A5750();
 D_800EE4DC &= ~(interrupt & 0xfffffbfe);
 func_800A5770(saveMask);
}

