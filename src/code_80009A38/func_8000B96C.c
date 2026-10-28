#include "common.h"

typedef struct Step
{
  f32 a;
  f32 b;
  f32 c;
} Step;
typedef struct State
{
  Step *p;
  s32 busy;
  f32 delay;
  f32 frame;
  f32 speed;
} State;
typedef struct Big
{
  char p0[0xf578];
  s32 x;
  char p1[0x2b8];
  s32 w;
  char p2[0x44];
  s32 y;
  char p3[8];
  s32 z;
  char p4[0x1c];
  s32 q;
} Big;
extern State D_80119950;
extern Big D_80109F10;
extern Step D_800B6BF0[];
extern char D_800B7DE4[];
extern char D_800B7DF4[];
extern char D_800F9F10[];
extern char D_80119488[];
extern char D_80119598[];
extern void func_80004504(void *, s32);
extern void func_8000F87C(void *, void *);
extern void func_80084BB0(void *);
void func_8000B96C(void)
{
  /* Advance a timed sequence and handle its loop and end markers. */
  Step *currentStep;
  f32 duration;
  if (D_80119950.busy)
  {
    return;
  }
  if (D_80119950.delay != 0.0f)
  {
    D_80119950.delay -= 1.0f;
    return;
  }
  D_80119950.frame += 1.0f;
  duration = (f32) ((s32) D_80119950.speed);
  if (duration <= D_80119950.frame)
  {
    D_80119950.p++;
 currentStep = (&D_80119950)->p; if (currentStep->a == (-2.0f)) {
      D_80119950.p = currentStep - 1;
      D_80119950.busy = 1;
      D_80109F10.z = 1;
      func_80084BB0(D_80119488);
      D_80109F10.x = 2;
      if ((D_80109F10.y == 1) && D_80109F10.w)
      {
        func_8000F87C(D_80119598, D_800B7DE4);
        D_80109F10.q = 1;
        return;
      }
      if ((D_80109F10.y == 2) && D_80109F10.w)
      {
        func_8000F87C(D_80119598, D_800B7DF4);
        D_80109F10.q = 1;
        return;
      }
      func_80004504(D_800F9F10, 0);
      return;
    }
    if (currentStep->a == (-1.0f))
    {
      func_80004504(D_800F9F10, 0);
      D_80119950.p = D_800B6BF0;
      currentStep = D_80119950.p;
      D_80119950.delay = 240.0f;
      duration = (f32) ((s32) D_80119950.speed);
    }
    D_80119950.frame -= duration;
    D_80119950.speed = currentStep->b * 21.0f;
  }
}
