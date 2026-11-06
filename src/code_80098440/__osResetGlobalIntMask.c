#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
u32 __osDisableInt(void);void __osRestoreInt(u32);extern u32 D_800EE4DC;
void __osResetGlobalIntMask(u32 interrupt)
{
 register u32 saveMask;
 saveMask=__osDisableInt();
 D_800EE4DC &= ~(interrupt & 0xfffffbfe);
 __osRestoreInt(saveMask);
}

