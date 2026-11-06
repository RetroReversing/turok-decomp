#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
u32 __osDisableInt(void);u32 osGetCount(void);void __osRestoreInt(u32);
extern u32 D_80138F58;extern u64 D_80138F50;
u64 osGetTime(void)
{
 u32 CurrentCount;
 u32 elapseCount;
 u64 tmptime;
 register u32 savedMask;
 savedMask=__osDisableInt();
 CurrentCount=osGetCount();
 elapseCount=CurrentCount-D_80138F58;
 tmptime=D_80138F50;
 __osRestoreInt(savedMask);
 return tmptime+(u64)elapseCount;
}

