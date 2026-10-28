#include "common.h"

void *func_8009FA50(void *arg0, u8 *arg1, s32 arg2)
{
  int new_var;
  u8 *dst = arg0;
  u8 *src = arg1;
  if (arg2)
  {
    loop:
    {
      u8 v = *src;
      arg2--;
      dst++;
      new_var = (((v & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF;
      if (!arg0)
      {
      }
      src++;
      v = ((new_var & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF;
      dst[-1] = ((((v ^ 0) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF;
    }

    if (arg2)
    {
      goto loop;
    }
  }
  return arg0;
}
