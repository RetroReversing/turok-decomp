#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct F
{
  s32 flags;
  s32 a;
  s32 b;
  char pad[0x58];
  u8 count;
  u8 flag65;
} F;
extern s32 __osPfsReleasePages(F *, void *, int, s16 *, s32, u16 *, s32);
extern s32 __osCheckId(F *);
extern s32 __osPfsRWInode(F *, void *, s32, int);
extern s32 __osPfsSelectBank(F *);
extern s32 __osContRamRead(s32, s32, s32, void *);
extern s32 osPfsFindFile(F *, u16, s32, s32, s32, s32 *);
extern s32 __osContRamWrite(s32, s32, s32, void *, s32);
s32 osPfsDeleteFile(F *arg0, volatile u16 arg1, volatile s32 arg2, volatile s32 arg3, s32 arg4)
{
  u8 new_var;
  s32 offset;
  volatile s32 i;
  volatile s32 result;
  u8 data[0x28];
  s32 new_var2;
  u8 packet[224];
  s16 next;
  u16 status;
  u8 idx;
  u8 prev;
  new_var = arg0->count;
  next = 0;
  if ((arg1 == 0) || (arg2 == 0))
  {
    return 5;
  }
  if (!(arg0->flags & 1))
  {
    return 5;
  }
  new_var2 = __osCheckId(arg0);
  if (new_var2 == 2)
  {
    return 2;
  }
  if (arg0->flag65)
  {
    arg0->flag65 = 0;
    result = __osPfsSelectBank(arg0);
    if (result)
    {
      return result;
    }
  }
  result = osPfsFindFile(arg0, arg1, arg2, arg3, arg4, (s32 *) (&offset));
  if (result)
  {
    return result;
  }
  if (offset == (-1))
  {
    return 5;
  }
  result = __osContRamRead(arg0->a, arg0->b, (*((s32 *) (((char *) arg0) + 0x5c))) + offset, data + 4);
  if (result)
  {
    return result;
  }
  idx = data[10];
  prev = data[11];
  while (idx < new_var)
  {
    result = __osPfsRWInode(arg0, packet, 0, idx);
    if (result)
    {
      return result;
    }
    result = __osPfsReleasePages(arg0, packet, prev, &next, idx, &status, 1);
    if (result)
    {
      return result;
    }
    result = __osPfsRWInode(arg0, packet, 1, idx);
    if (result)
    {
      return result;
    }
    if (status == 1)
    {
      break;
    }
    idx = (u8) status;
    prev = (&status)[1];
  }

  if (idx >= new_var)
  {
    return 3;
  }
  *((s32 *) (data + 4)) = 0;
  *((s16 *) (data + 8)) = 0;
  *((s16 *) (data + 10)) = 0;
  *((s16 *) (data + 14)) = 0;
  for (i = 0; i < 16; i++)
  {
    data[20 + i] = 0;
  }

  for (i = 0; i < 4; i++)
  {
    data[16 + i] = 0;
  }

  data[12] = 0;
  result = __osContRamWrite(arg0->a, arg0->b, (*((s32 *) (((char *) arg0) + 0x5c))) + offset, data + 4, 0);
  return result;
}

