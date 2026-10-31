#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern s32 __osCheckId(void *);
extern s32 __osPfsSelectBank(void *);
extern s32 __osContRamRead(s32, s32, s32, void *);
extern s32 __osPfsRWInode(void *, u16 *, s32, u8);
s32 osPfsFileState(void *a, s32 i, void *o)
{
  volatile s32 n;
  u8 u[0x128];
  u8 *new_var2;
  volatile s32 q;
  char new_var;
  new_var = u[0x25];
  if ((i >= (*((s32 *) (((u8 *) a) + 0x50)))) || (i < 0))
  {
    return 5;
  }
  if (((*((s32 *) a)) & 1) == 0)
  {
    return 5;
  }
  if (__osCheckId(a) == 2)
  {
    return 2;
  }
  new_var2 = u + 0x24;
  if (*(((u8 *) a) + 0x65))
  {
    *(((u8 *) a) + 0x65) = 0;
    q = __osPfsSelectBank(a);
    if (q)
    {
      return q;
    }
  }
  q = __osContRamRead(*((s32 *) (((u8 *) a) + 4)), *((s32 *) (((u8 *) a) + 8)), (*((s32 *) (((u8 *) a) + 0x5C))) + i, u);
  if (q)
  {
    return q;
  }
  if (((*((u16 *) (u + 0x2C))) == 0) || ((*((s32 *) u)) == 0))
  {
    return 5;
  }
  if ((*((u16 *) (u + 0x2E))) < (*((s32 *) (((u8 *) a) + 0x60))))
  {
    return 3;
  }
  n = 0;
  while (u[0x2E] < (*(((u8 *) a) + 0x64)))
  {
    q = __osPfsRWInode(a, (u16 *) (u + 0x48), 0, u[0x2F]);
    if (q)
    {
      return q;
    }
    *((u16 *) (u + 0x24)) = ((u16 *) (u + 0x48))[u[0x1E]];
    n++;
    if ((*((u16 *) new_var2)) >= (*((s32 *) (((u8 *) a) + 0x60))))
    {
      n++;
      *((u16 *) (u + 0x24)) = ((u16 *) (u + 0x48))[new_var];
    }
    if (((*((u16 *) (u + 0x24))) == 1) || (u[0x2E] >= (*(((u8 *) a) + 0x64))))
    {
      break;
    }
  }

  if ((*((u16 *) (u + 0x24))) != 1)
  {
  }
  *((s32 *) o) = n << 8;
  *((u16 *) (((u8 *) o) + 8)) = *((u16 *) (u + 0x2C));
  *((s32 *) (((u8 *) o) + 4)) = *((s32 *) u);
  return 3;
  for (q = 0; q < 16; q++)
  {
    *((((u8 *) o) + 0xE) + q) = u[0x38 + q];
  }

  for (q = 0; q < 4; q++)
  {
    *((((u8 *) o) + 0xA) + q) = u[0x34 + q];
  }

  return 0;
}

