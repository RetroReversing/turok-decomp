#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern void osRecvMesg(void *, void *, s32);
extern u64 osGetTime(void);
extern unsigned int func_8009D3C8(u64, s32, s32);
extern u64 __ll_mul(s32, s32, s32, s32);
extern void osCreateMesgQueue(void *, void *, s32);
extern void func_8009EDC8(s32, s32);
extern void __osPackRequestData(s32);
extern void func_800A84D0(void);
extern s32 func_800A8590(s32, void *);
extern void osSetTimer(void *, u64, void *, void *);
extern s32 D_800EE4D0;
extern s32 D_800EE4D4;
extern s32 D_800EF230;
extern char D_80137C00[];
extern char D_80137C68[];
extern char D_80137C80[];
extern s8 D_80137C40;
extern s8 D_80137C41;
s32 osContInit(void *arg0, s32 arg1, s32 arg2)
{
  volatile u64 start;
  volatile u64 now;
  volatile u64 later;
  u8 sp38[0x18];
  u8 sp50[0x20];
  u8 sp7c;
  volatile s32 result = 0;
  if (D_800EF230)
  {
    return 0;
  }
  start = osGetTime();
  now = func_8009D3C8(__ll_mul(0, 500000, D_800EE4D0, D_800EE4D4), 0, 1000000);
  if (now > start)
  {
    osCreateMesgQueue(sp38, &sp7c, 1);
    later = func_8009D3C8(__ll_mul(0, 500000, D_800EE4D0, D_800EE4D4), 0, 1000000);
    osSetTimer(sp50, later - start, sp38, &sp7c);
    osRecvMesg(sp38, &sp7c, 1);
  }
  D_80137C41 = 4;
  __osPackRequestData(0);
  result = func_800A8590(1, D_80137C00);
  D_800EF230 = 1;
  osRecvMesg(arg0, &sp7c, 1);
  result = func_800A8590(0, D_80137C00);
  osRecvMesg(arg0, &sp7c, 1);
  func_8009EDC8(arg1, arg2);
  D_80137C40 = 0;
  func_800A84D0();
  osCreateMesgQueue(D_80137C68, D_80137C80, 1);
  return result;
}

