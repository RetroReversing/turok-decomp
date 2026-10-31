#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern s32 __osClearPage(void *, s32, u8 *, u8);
s32 __osPfsDeclearPage(void *arg0, u16 *arg1, s32 arg2, s32 *arg3, u8 arg4, s32 *arg5, s32 *arg6)
{
  volatile s32 sp4C;
  volatile s32 sp48;
  volatile s32 sp44;
  volatile s32 sp20 = 0;
  volatile s32 sp1C = 0;
  volatile s32 sp18;
  u8 temp[32];
  if (arg4 > 0)
  {
    sp18 = 1;
  }
  else
  {
    sp18 = *((s32 *) (((u8 *) arg0) + 0x60));
  }
  sp4C = sp18;
  while ((sp4C < ((0, 0x80))) && (arg1[sp4C] != 3))
  {
    sp4C++;
  }

  if (sp4C == 0x80)
  {
    *arg3 = -1;
    return sp1C;
  }
  do
  {
    temp[sp20] = 0;
    sp20++;
  }
  while (sp20 < 0x20);
  sp48 = sp4C;
  *arg5 = 1;
  sp44 = sp4C;
  sp4C++;
  {
    do
    {
      if (arg1[sp4C] == 3)
      {
        ((u8 *) arg1)[sp44 * 2] = arg4;
        ((u8 *) arg1)[(sp44 * 2) + 1] = (s8) sp4C;
        if (arg4)
        {
        }
        sp1C = __osClearPage(arg0, sp44, temp, arg4);
        if (sp1C)
        {
          ;
          return sp1C;
        }
        sp44 = sp4C;
        ++(*arg5);
      }
      sp4C++;
    }
    while ((((*arg5) < arg2) && (sp4C < 0x80)) != 0);
  }
  *arg3 = sp48;
  sp48 = sp44;
  if ((sp4C == 0x80) && ((*arg5) < arg2))
  {
    *arg6 = sp48;
  }
  else
  {
    ((u16 *) arg1)[sp48] = 1;
    sp1C = __osClearPage(arg0, sp48, temp, arg4);
    *arg6 = 0;
  }
  return sp1C;
}

