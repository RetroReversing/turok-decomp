#include "context_8d698fdff8b3.h"
#line 1 "func.c"
#define I(p,o) (*(s32 *)((char *)(p)+(o)))
extern void func_8002C56C(void *, void *);
extern void func_8002C63C(void *, s32, s32);
extern s32 __scSchedule(void *, s32 *, s32 *, s32);
extern s32 osSendMesg(s32, s32, s32);
extern s32 osSpTaskYielded(void *);
extern u64 osGetTime(void);
extern u64 func_8009D3C8(u64, u64);
extern u64 __ll_mul(u64, u64);
extern f32 func_8009DA98(u64);
extern f32 D_800B6B1C;
extern f32 D_800B6B20;
extern f32 D_800B6B24;
extern f32 D_800F1A00;
extern f32 D_800F1A04;
extern f32 D_800F1A08;
extern f32 D_800F1A0C;
extern f32 D_8011A120;
extern s32 D_800BA900;
extern s32 D_800EE4D0;
extern s32 D_8011A128;
extern s32 D_8011A130;
extern s32 D_8011A138;
void func_8002BF28(void *owner)
{
  s32 out0 = 0;
  s32 mask;
  s32 dummy;
  void *task;
  s32 out1 = 0;
  u64 time;
  u64 delta;
  task = (void *) I(owner, 0x274);
  I(owner, 0x274) = 0;
  if ((I(task, 4) & 0x10) && osSpTaskYielded(((char *) task) + 0x10))
  {
    I(task, 4) |= 0x20;
    if ((I(task, 8) & 7) == 3)
    {
      I(task, 0) = I(owner, 0x268);
      I(owner, 0x268) = (s32) task;
      if (!I(owner, 0x270))
      {
        I(owner, 0x270) = (s32) task;
      }
    }
    if (I(task, 8) & 0x20)
    {
      time = osGetTime();
      delta = __ll_mul(time - (*((u64 *) (&D_8011A130))), 1000000000);
      delta = func_8009D3C8(delta, *((u64 *) (&D_800EE4D0)));
      D_8011A120 += func_8009DA98(delta) / D_800F1A00;
    }
  }
  else
  {
    I(task, 4) &= ~2;
    if (I(task, 0x10) == 1)
    {
      D_800BA900 = 0;
      if (I(task, 8) & 0x20)
      {
        time = osGetTime();
        delta = __ll_mul(time - (*((u64 *) (&D_8011A130))), 1000000000);
        delta = func_8009D3C8(delta, *((u64 *) (&D_800EE4D0)));
        D_8011A120 += func_8009DA98(delta) / D_800F1A04;
        D_800B6B24 = D_8011A120;
        time = osGetTime();
        delta = __ll_mul(time - (*((u64 *) (&D_8011A138))), 1000000000);
        delta = func_8009D3C8(delta, *((u64 *) (&D_800EE4D0)));
        D_800B6B1C = func_8009DA98(delta) / D_800F1A08;
        if (osSendMesg(I(task, 0x50), I(task, 0x54), 0) == (-1))
        {
          *((volatile u8 *) 0) = 0;
        }
      }
    }
    else
    {
      time = osGetTime();
      delta = __ll_mul(time - (*((u64 *) (&D_8011A128))), 1000000000);
      delta = func_8009D3C8(delta, *((u64 *) (&D_800EE4D0)));
      D_800B6B20 = func_8009DA98(delta) / D_800F1A0C;
      if (osSendMesg(I(task, 0x50), I(task, 0x54), 0) == (-1))
      {
        *((volatile u8 *) 0) = 0;
      }
    }
    func_8002C56C(owner, task);
  }
  dummy = I(owner, 0x274);
  mask = ((!dummy) * 2) | (!I(owner, 0x278));
  if (__scSchedule(owner, &out0, &out1, mask) != mask)
  {
    func_8002C63C(owner, out0, out1);
  }
}

