#include "context_8d698fdff8b3.h"
#line 1 "func.c"
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define F(p,o) (*(float*)((char*)(p)+(o)))
extern double D_800F74F8;
extern float D_800F7500;
extern int osVirtualToPhysical(int, void *);
typedef int (*Allocator)(void *, short *, int, int, ...);
void *alResamplePull(void *ctx, short *src, int count, int arg4, int result)
{
  int __repair_literal;
  int new_var2;
  void *base = *((void **) ctx);
  short opcode = 0x140;
  int *new_var;
  int *out;
  void **new_var3;
  float x;
  int n;
  if (!count)
  {
    out = (int *) result;
    return out;
  }
  else
    if (I(ctx, 0x1c))
  {
    out = (int *) ((Allocator) (*((void **) (((char *) base) + 4))))(base, &opcode, count, arg4, result);
    if (ctx)
    {
    }
    new_var = out + 2;
    *out = (opcode & 0xffffff) | 0x0a000000;
    __repair_literal = 2;
    out[1] = ((*src) << 16) | ((count * ((unsigned long) __repair_literal)) & 0xffff);
    return new_var;
  }
  else
  {
    if (D_800F74F8 < ((double) F(ctx, 0x18)))
    {
      F(ctx, 0x18) = D_800F7500;
    }
    F(ctx, 0x18) = (float) ((int) (F(ctx, 0x18) * 32768.0f));
    F(ctx, 0x18) = F(ctx, 0x18) / 32768.0f;
 do { x = (F(ctx, 0x18) * ((float) count)) + F(ctx, 0x20); new_var3 = (void **) (((char *) base) + 4); n = (int) x; F(ctx, 0x20) = x - ((float) n); out = (int *) ((Allocator) (*new_var3))(base, &opcode, n, arg4, result); *out = (opcode & 0xffff) | 0x08000000; out[1] = ((*src) << 16) | ((count * 2) & 0xffff); out[2] = (((I(ctx, __repair_literal = 0x24) & 0xff) << 16) | 0x05000000) | ((new_var2 = (int) (F(ctx, 0x18) * 32768.0f)) & 0xffff); out[3] = osVirtualToPhysical(I(ctx, 0x14), out + 4); } while (0);
    I(ctx, 0x24) = 0;
    return out + 4;
  }
}

