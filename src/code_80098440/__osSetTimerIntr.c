#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
u32 __osDisableInt(void);u32 osGetCount(void);void __osSetCompare(u32);void __osRestoreInt(u32);
extern u32 D_80138F60;
void __osSetTimerIntr(u64 tim)
{
 u64 NewTime;
 u32 savedMask;
 savedMask=__osDisableInt();
 D_80138F60=osGetCount();
 NewTime=((u64)D_80138F60+tim);
 __osSetCompare((u32)NewTime);
 __osRestoreInt(savedMask);
}

