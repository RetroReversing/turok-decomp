#include "context_8d698fdff8b3.h"
#line 1 "func.c"
#define B(p,o) (*(u8*)((u8*)(p)+(o)))
#define SB(p,o) (*(s8*)((u8*)(p)+(o)))
#define H(p,o) (*(u16*)((u8*)(p)+(o)))
#define SH(p,o) (*(s16*)((u8*)(p)+(o)))
#define W(p,o) (*(u32*)((u8*)(p)+(o)))
#define F(p,o) (*(f32*)((u8*)(p)+(o)))
extern double D_800F1560;
extern double D_800F1568;
extern float D_800F1570;
extern float D_800F1574;
extern float D_800F1578;
extern void func_80012E6C(void *, float);
extern void func_800130DC(void *, float, float, float);
extern void func_8001315C(void *, float, float, float);
extern void func_80012290(void *, void *);
void func_8001F4E0(void *a, void *b, s32 c, s32 d, void *e, f32 scale)
{
  struct 
  {
    f32 angle;
    f32 __repair_angle_1;
    f32 x;
    f32 y;
    f32 z;
    u8 matrix[48];
  } frame;
  u16 idx;
  double new_var;
  B(a, 0) = 0;
  H(a, 2) = H(b, 4);
  W(a, 0x24) = c;
  B(a, 1) = B(b, 0xf);
  idx = H(b, 8);
  if (idx == 0xffff)
  {
    W(a, 0x18) = 0;
  }
  else
  {
    W(a, 0x18) = (idx * 80) + ((u32) e);
  }
  frame.x = ((f32) B(b, 0x10)) * scale;
  if (B(b, 0xe) & 0x10)
  {
    frame.x = -frame.x;
  }
  frame.z = ((f32) B(b, 0x11)) * scale;
  if (B(b, 0xe) & 0x20)
  {
    frame.z = -frame.z;
  }
  frame.y = (f32) (((f64) SH(b, 0xc)) * D_800F1568);
  new_var = D_800F1560;
  F(a, 0x70) = (f32) (((f64) frame.x) + (((f64) SB(b, 0x12)) * new_var));
  F(a, 0x74) = (f32) (((f64) frame.y) + (((f64) SB(b, 0x14)) * D_800F1560));
  F(a, 0x78) = (f32) (((f64) frame.z) + (((f64) SB(b, 0x16)) * D_800F1560));
  F(a, 0x7c) = (f32) (((f64) frame.x) + (((f64) SB(b, 0x13)) * D_800F1560));
  F(a, 0x80) = (f32) (((f64) frame.y) + (((f64) SB(b, 0x15)) * D_800F1560));
  F(a, 0x84) = (f32) (((f64) frame.z) + (((f64) SB(b, 0x17)) * D_800F1560));
  switch (B(b, 0xe) & 3)
  {
    default:
      frame.__repair_angle_1 = D_800F1578;
      break;

    case 0:
      frame.angle = 0.0f;
      break;

    case 1:
      frame.angle = D_800F1570;
      break;

    case 2:
      frame.angle = D_800F1574;
      break;

  }

  func_80012E6C(frame.matrix, frame.angle);
  func_800130DC(frame.matrix, F(b, 0), F(b, 0), F(b, 0));
 do { func_8001315C(frame.matrix, frame.x, frame.y, frame.z); func_80012290(frame.matrix, ((u8 *) a) + 0x28); W(a, 4) = *((u32 *) (&frame.x)); W(a, 8) = *((u32 *) (&frame.y)); W(a, 0xc) = *((u32 *) (&frame.z)); F(a, 0x10) = 0.0f; idx = H(b, 6); if (idx == 0xffff) { W(a, 0x14) = 0; } else { W(a, 0x14) = ((u32) d) + (idx * 28); } } while (0);
  W(a, 0x88) = H(b, 0xa);
}

