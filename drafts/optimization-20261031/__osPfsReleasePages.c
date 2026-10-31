#include "context_8d698fdff8b3.h"
#line 1 "func.c"
s32 __osBlockSum(void *, u8, void *, u8);
s32 __osPfsReleasePages(void *a, void *b, u8 c, void *d, s32 e, u16 *f, u8 g)
{
  s32 result = 0;
  void **new_var;
  u16 value;
  u8 *list = b;
  u16 *ret = f;
  value = *((u16 *) (list + (c * 2)));
  if (value != 1)
  {
    if (((u8) value) > 0)
    {
      result = 1;
    }
  }
  if (result)
  {
    return 3;
  }
  *ret = value;
  if (e == 1)
  {
    list[c * 2] = 3;
  }
  new_var = &a;
  result = __osBlockSum(*new_var, c, d, g);
  if (result)
  {
    return result;
  }
  return 0;
}

