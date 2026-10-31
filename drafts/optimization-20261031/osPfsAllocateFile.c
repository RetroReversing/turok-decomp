#include "context_8d698fdff8b3.h"
#line 1 "func.c"
s32 osPfsFreeBlocks(void *, s32 *);
s32 __osPfsDeclearPage(void *, u16 *, s32);
s32 __osCheckId(void *);
s32 __osPfsRWInode(void *, u16 *, s32, u8);
s32 osPfsFindFile(void *, u16, s32, u8 *, u8 *, s32 *);
s32 __osContRamWrite(s32, s32, s32, void *, s32);
typedef struct 
{
  s32 flags;
  s32 a;
  s32 b;
  u8 pad[0x50];
  s32 base;
  u8 count;
} Archive;
s32 osPfsAllocateFile(Archive *arg0, u16 arg1, s32 arg2, u8 *arg3, u8 *arg4, s32 arg5, s32 *arg6)
{
  s32 sp274;
  volatile long long sp270;
  s32 sp26C;
  s32 sp268;
  s32 sp264;
  s32 sp260;
  s32 sp25C;
  u16 sp15C[128];
  u16 sp5C[128];
  s16 sp46;
  
  s16 sp40;
  s32 sp3C;
  u8 sp3B;
  u8 sp3A;
  s32 sp34;
  s32 sp30;
  u8 sp2D;
  u8 sp2C;
  sp268 = 0;
  sp260 = 0;
  sp3A = 0;
  sp34 = 0;
  if ((!arg1) || (!arg2))
  {
    goto bad;
  }
  sp25C = (arg5 + 255) / 256;
  if (!(arg0->flags & 1))
  {
    return 5;
  }
  if (__osCheckId(arg0) == 2)
  {
    return 2;
  }
  sp260 = osPfsFindFile(arg0, arg1, arg2, arg3, arg4, arg6);
  if ((sp260 != 0) && (sp260 != 5))
  {
    return sp260;
  }
  if ((*arg6) != (-1))
  {
    return 9;
  }
  sp260 = osPfsFreeBlocks(arg0, &sp30);
  if (sp30 < arg5)
  {
    return 7;
  }
  if (sp25C == 0)
  {
    return 5;
  }
  sp260 = osPfsFindFile(arg0, 0, 0, 0, 0, arg6);
  if ((sp260 != 0) && (sp260 != 5))
  {
    return sp260;
  }
  if ((*arg6) == (-1))
  {
    return 8;
  }
  sp3B = 0;
  do
  {
    sp260 = __osPfsRWInode(arg0, sp15C, 0, sp3B);
    if (sp260 != 0)
    {
      return sp260;
    }
    sp260 = __osPfsDeclearPage(arg0, sp15C, sp25C);
    if (sp260 != 0)
    {
      return sp260;
    }
    if (sp274 != (-1))
    {
      if (sp34 == 0)
      {
        sp2D = sp274;
        sp2C = sp3B;
      }
      else
      {
        ((u8 *) sp5C)[sp268 * 2] = sp3B;
        ((u8 *) sp5C)[(sp268 * 2) + 1] = sp274;
        sp260 = __osPfsRWInode(arg0, sp5C, 1, sp3A);
        if (sp260 != 0)
        {
          return sp260;
        }
      }
      sp264 = 0;
      do
      {
        sp5C[sp264] = sp15C[sp264];
        sp264++;
      }
      while (sp264 < 128);
      sp34++;
      sp268 = sp26C;
      sp3A = sp3B;
      if (sp270 < sp25C)
      {
        sp25C -= sp270;
      }
      else
      {
        sp25C = 0;
        break;
      }
    }
    sp3B++;
  }
  while (sp3B < arg0->count);
  if ((sp274 == (-1)) || (sp25C > 0))
  {
    return 3;
  }
  ((u8 *) sp5C)[sp268 * 2] = sp3B;
  ((u8 *) sp5C)[(sp26C * 2) + 1] = sp274;
  sp260 = __osPfsRWInode(arg0, sp5C, 1, sp3A);
  if (sp260 != 0)
  {
    return sp260;
  }
  sp46 = 0;
  sp46 = (sp2D << 8) | sp2C;
  sp40 = arg1;
  sp3C = arg2;
  sp264 = 0;
  do
  {
    ((u8 *) (&sp3C))[16 + sp264] = *(arg3++);
    sp264++;
  }
  while (sp264 < 16);
  sp264 = 0;
  do
  {
    ((u8 *) (&sp3C))[12 + sp264] = *(arg4++);
    sp264++;
  }
  while (sp264 < 4);
  sp260 = __osContRamWrite(arg0->a, arg0->b, (*arg6) + arg0->base, &sp3C, 0);
  if (sp260 != 0)
  {
    return sp260;
  }
  return sp260;
  bad:
  return 5;

}

