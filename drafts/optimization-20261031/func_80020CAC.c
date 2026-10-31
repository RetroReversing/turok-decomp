#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct 
{
  u8 p[2];
  u16 flags;
} A;
typedef struct 
{
  u8 p[4];
  f32 x;
} F;
typedef struct 
{
  u8 p[0x20];
  f32 x;
} R;
extern void *func_8002E438();
extern A *D_800B9730;
extern R *D_800B9734;
extern u8 D_800FA3C8[];
s32 func_80020CAC(A *a, F *b, F *c, f32 *out)
{
  f32 den;
  f32 num;
  if (a == 0)
  {
    return 0;
  }
  if (!(a->flags & 1))
  {
    return 0;
  }
  if (a != D_800B9730)
  {
    D_800B9734 = func_8002E438(D_800FA3C8);
    D_800B9730 = a;
  }
  if (!D_800B9734)
  {
    return 0;
  }
  num = c->x - b->x;
  if (num == 0.0f)
  {
    if (a->flags)
    {
    }
    return 0;
  }
  *out = (D_800B9734->x - b->x) / num;
  return ((*out) > 0.0f) && ((*out) < 1.0f);
}

