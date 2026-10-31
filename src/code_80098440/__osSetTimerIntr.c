#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
u32 func_800A5750(void);u32 func_800A60D0(void);void func_800AFDC0(u32);void func_800A5770(u32);
extern u32 D_80138F60;
void __osSetTimerIntr(u64 tim)
{
 u64 NewTime;
 u32 savedMask;
 savedMask=func_800A5750();
 D_80138F60=func_800A60D0();
 NewTime=((u64)D_80138F60+tim);
 func_800AFDC0((u32)NewTime);
 func_800A5770(savedMask);
}

