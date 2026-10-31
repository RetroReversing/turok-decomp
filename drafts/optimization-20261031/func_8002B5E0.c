#include "context_8d698fdff8b3.h"
#line 1 "func.c"
#define W(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define B(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))
extern s32 D_8011A0D0;
extern u8 D_8011A070[];
extern u8 D_8011A030[];
extern u8 D_80119F70[];
extern void func_80083E20(void *);
extern void func_80012EFC(void *, s32);
void func_8002B5E0(u8 *base)
{
  u8 *p;
  u8 *q;
  u8 *r;
  u8 *s;
  u8 *new_var;
  u8 *t;
  u8 *slot;
  unsigned short i;
  unsigned short __repair_i_1;
  s32 v;
  D_8011A0D0 = 0;
  W(base, 0xC400) = (u32) base;
  W(base, 0xC404) = W(base, 0xC408);
  W(base, 0xC408) = 0;
  W(base, 0xC410) = 0;
  W(base, 0xC40C) = W(base, 0xC410);
  W(base, 0x300) = (u32) (base + 0x310);
  W(base, 0x178) = (u32) (base + 0x188);
  W(base, 0x488) = (u32) (base + 0x498);
  q = p + 0x188;
  r = p + 0x310;
  s = p + 0x498;
  t = p + 0x620;
  i = 3;
  do
  {
    W(p, 0x300) = (u32) r;
    W(p, 0x488) = (u32) s;
    W(p, 0x610) = (u32) t;
    W(p, 0x178) = (u32) q;
    i += 4;
    q += 0x620;
    t += 0x620;
    s += 0x620;
    r += 0x620;
    p += 0x620;
  }
  while (i != 0x7f);
  W(base, 0xC3F0) = 0;
  func_80083E20(D_8011A070);
  v = W(D_8011A070, 0x38) & (~1);
  W(D_8011A070, 0x38) = v;
  W(D_8011A070, 0x38) = v | 8;
  F(D_8011A070, 0x18) = 0.0f;
  F(D_8011A070, 0x20) = 0.0f;
  p = D_80119F70;
  __repair_i_1 = 0;
  do
  {
    slot = p;
    switch (__repair_i_1 & 0xFFFF)
    {
      case 0:
        H(p, 0) = -1;
        H(p, 2) = 1;
        H(p, 8) = 8192;
        H(p, 10 ^ 0) = 8192;
        break;

      case 1:
        H(p, 0) = 1;
        if (1)
      {
      }
        H(p, 2) = 1;
        p = base + 0x498;
        H(p, 8) = 0;
        H(p, 10) = 8192;
        break;

      case 2:
        H(p, 0) = 1;
        H(p, 2) = -1;
        H(p, 8) = 0;
        H(p, 10) = 0;
        break;

      case 3:
        H(p, 0) = -1;
        H(p, 2) = -1;
        H(p, 8) = 8192;
        H(p, 10) = 0;
        break;

    }

    __repair_i_1++;
    p += 16;
    H(slot, 4) = 0;
    H(slot, 6) = 0;
    B(slot, 12) = 255;
    B(slot, 13) = 255;
    B(slot, 14) = 255;
    B(slot, 15) = 255;
  }
  while (__repair_i_1 != 4);
  func_80012EFC(D_8011A030, 0x3FC90FDB);
  i = 0;
  p = base;
  do
  {
    i += 4;
    F(p, 0x198) = 0.0f;
    W(p, 0x1a0) = (u32) D_8011A070;
    B(p, 0x188) = 2;
    W(p, 0x244) = 0;
    F(p, 0x320) = 0.0f;
    W(p, 0x328) = (u32) D_8011A070;
    B(p, 0x310) = 2;
    W(p, 0x3cc) = 0;
    new_var = p;
    F(new_var, 0x4a8) = 0.0f;
    W(new_var, 0x4b0) = (u32) D_8011A070;
    B(new_var, 0x498) = 2;
    W(new_var, 0x554) = 0;
    p += 0x620;
    F(p, -0x610) = 0.0f;
    W(p, -0x608) = (u32) D_8011A070;
    B(p, -0x620) = 2;
    W(p, -0x564) = 0;
  }
  while (i != 128);
  W(base, 0xC418) = 0;
  W(base, 0xC414) = 0;
  W(base, 0xC41C) = 0;
}

