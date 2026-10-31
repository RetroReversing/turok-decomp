#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern s32 D_800F17D0;
extern void func_80029D94(void);
extern void func_8002D1F8(s32, void *, void *, s32, void *, s32, s32, void *);
typedef struct 
{
  char pad[0xC414];
  s32 one;
  s32 zero;
  s32 extra;
} S;
void func_8002B2E8(S *a, s32 b, s32 c, s32 d, s32 e)
{
  s32 *new_var;
  new_var = &a->one;
  a->one = b;
  a->extra = e;
  a->zero = 0;
  if (b && b)
  {
  }
  func_8002D1F8(*new_var, a, func_80029D94, 0, &a->zero, (unsigned int) c, d, &D_800F17D0);
}

