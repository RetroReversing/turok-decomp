#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
u32 func_800A5750(void);u32 func_800A60D0(void);void func_800A5770(u32);
extern u32 D_80138F58;extern u64 D_80138F50;
u64 osGetTime(void)
{
 u32 CurrentCount;
 u32 elapseCount;
 u64 tmptime;
 register u32 savedMask;
 savedMask=func_800A5750();
 CurrentCount=func_800A60D0();
 elapseCount=CurrentCount-D_80138F58;
 tmptime=D_80138F50;
 func_800A5770(savedMask);
 return tmptime+(u64)elapseCount;
}

