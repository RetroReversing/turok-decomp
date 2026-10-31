#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern s32 osVirtualToPhysical(void *);
void *_filterBuffer(void *p, s32 a, s32 b, u32 *out)
{
  volatile u32 keep;
  u32 v = a & 0xffff;
  u32 n = (b * 2) & 0xffff;
  u8 *new_var2;
  int new_var;
  u8 *new_var3;
  u32 *q;
  u32 new_var4;
  out[1] = ((v << 13) << 3) | n;
  out[0] = v | 0x08000000;
  out[2] = 0x0B000020;
  new_var2 = ((u8 *) p) + 2;
  new_var3 = ((u8 *) p) + 0x28;
  keep = (u32) p;
  q = out;
  out[3] = osVirtualToPhysical(((u8 *) p) + 8);
  do
  {
    new_var4 = *((u32 *) (((u8 *) p) + 0x2c));
    q = out + 4;
    new_var = ((u32) new_var4) & 255;
    out[4] = ((new_var << 16) | 0x0e000000) | (((u32) (*((s16 *) new_var2))) & 0xffff);
    out[5] = osVirtualToPhysical(*((void **) new_var3));
    *((u32 *) (((u8 *) p) + 0x2c)) = 0;
  }
  while (0);
  new_var = 2;
  return q + new_var;
}

