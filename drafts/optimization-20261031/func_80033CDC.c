#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern void func_8002D1F8(void *, void *, void *, void *, void *, s32, s32, void *);
extern s32 CCacheEntry__GetData(s32);
extern void func_80033B48(void *);
extern void func_80033C88(void *);
extern void func_8009FA50(void *, s32, s32);
extern s32 D_800B6AFC;
extern u8 D_800F1B58;
extern f64 D_800F1D50;
extern s32 D_801198C0;
extern u8 D_8011A150[];
extern u8 D_8011A190[];
extern u8 D_8011A3D0[];
extern void func_800325D4(void);
extern void func_80032678(void);
void func_80033CDC(u8 *arg0, s32 arg1)
{
  u8 *a1;
  f32 v;
  u8 *new_var2;
  s32 *new_var3;
  f32 w;
  float new_var;
  s32 i;
  s32 n;
  s32 x;
  u8 *r;
  u8 *g;
  u8 *b;
  new_var3 = (s32 *) (arg0 + 0x175D0);
  func_8009FA50(arg0 + 0x175A0, CCacheEntry__GetData(*((s32 *) (arg0 + 0x6B2C))), 0x14);
  new_var2 = arg0 + 0x10000;
  i = 0;
  *new_var3 = 1;
  a1 = new_var2;
  if ((arg0[0x175B0] & 1) && (D_801198C0 != (*((s32 *) (arg0 + 0x175EC)))))
  {
    func_80033C88(arg0);
    D_801198C0 = *((s32 *) (arg0 + 0x175EC));
  }
  if (arg0[0x175B0] & 2)
  {
    D_800B6AFC = 1;
  }
  else
  {
    D_800B6AFC = i;
  }
  func_80033B48(arg0);
  r = D_8011A150;
  g = D_8011A190;
  b = D_8011A3D0;
  i = 0;
  do
  {
    v = ((f32) (((f64) i) / D_800F1D50)) * 255.0f;
    i++;
    if (!arg0)
    {
    }
    w = (v > 255.0f) ? (255.0f) : (v);
    new_var = 255.0f;
    if (w < 0.0f)
    {
      w = 0.0f;
      n = (s32) w;
    }
    else
    {
      n = (s32) ((v > new_var) ? (255.0f) : (v));
    }
    x = ((arg0[0x175AA] * n) + (arg0[0x175AD] << 8)) >> 8;
    *(r++) = (x >= 256) ? (255) : (x);
    x = ((arg0[0x175AB] * n) + ((arg0[0x175AE] << 5) << 3)) >> 8;
    *(g++) = (x >= 256) ? (255) : (x);
    x = ((arg0[0x175AC] * n) + (arg0[0x175AF] << 8)) >> 8;
    *(b++) = (x >= 256) ? (255) : (x);
  }
  while (i != 64);
  func_8002D1F8(arg0, arg0, func_80032678, func_800325D4, arg0 + 0x6B14, *((s32 *) (arg0 + 0x6ADC)), *((s32 *) (arg0 + 0x6B44)), &D_800F1B58);
}

