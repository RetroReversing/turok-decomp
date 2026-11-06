#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
u32 __osDisableInt(void);void __osRestoreInt(u32);void __osEnqueueAndYield(void *);extern u8 *D_800EF290;extern u8 D_800EF288;
void osYieldThread(void)
{
 register u32 saveMask;
 saveMask=__osDisableInt();
 *(u16*)(D_800EF290+0x10)=2;
 __osEnqueueAndYield(&D_800EF288);
 __osRestoreInt(saveMask);
}

