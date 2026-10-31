#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern s32 __osPfsGetNextPage(void *, s8 *, u8 *, u16 *);
extern s32 __osCheckId(void *);
extern s32 __osPfsSelectBank(void *);
extern s32 __osContRamRead(s32, s32, s32, void *);
extern s32 __osContRamWrite(s32, s32, s32, void *, s32);
s32 osPfsReadWriteFile(u8 * volatile p, volatile s32 sector, volatile s32 write, volatile s32 start, volatile s32 bytes, void * volatile buf)
{
  volatile s32 result;
  s32 offset;
  s32 count;
  u8 block[0x20];
  u8 cache[0xE8];
  u16 id;
  u16 entry;
  s8 marker;
  u8 *data;
  if ((sector >= (*((s32 *) (p + 0x50)))) || (sector < 0))
  {
    return 5;
  }
  if ((bytes <= 0) || (bytes & 31))
  {
    return 5;
  }
  if ((start < 0) || (start & 31))
  {
    return 5;
  }
  if (!((*((u32 *) p)) & 1))
  {
    return 5;
    return 5;
  }
  if (__osCheckId(p) == 2)
  {
    return 2;
  }
  if (p[0x65])
  {
    p[0x65] = 0;
    result = __osPfsSelectBank(p);
    if (result)
    {
      return result;
    }
  }
  result = __osContRamRead(*((s32 *) (p + 4)), *((s32 *) (p + 8)), (*((s32 *) (p + 0x5c))) + sector, cache + 0xB4);
  if (result)
  {
    return result;
  }
  id = *((u16 *) (cache + 0xBA));
  if ((((id < (*((s32 *) (p + 0x60)))) || (cache[0xBA] >= p[0x64])) || (cache[0xBB] == 0)) || (cache[0xBB] >= 0x80))
  {
    if (id == 1)
    {
    }
    return 3;
  }
  if ((!write) && (!(cache[0xBC] & 2)))
  {
    return 6;
  }
  marker = -1;
  offset = start / 32;
  entry = id;
  while (offset >= 8)
  {
    result = __osPfsGetNextPage(p, &marker, block, &entry);
    if (result)
    {
      return result;
    }
    offset -= 8;
  }

  count = bytes / 32;
  data = buf;
  while (count > 0)
  {
    if (offset == 8)
    {
      result = __osPfsGetNextPage(p, &marker, block, &entry);
      if (result)
      {
        return result;
      }
      offset = 0;
    }
    if (p[0x65] != ((u8) entry))
    {
      p[0x65] = entry;
      result = __osPfsSelectBank(p);
      if (result)
      {
        return result;
      }
    }
    id = (block[1] * 8) + offset;
    if (!write)
    {
      result = __osContRamRead(*((s32 *) (p + 4)), *((s32 *) (p + 8)), id, data);
    }
    else
    {
      result = __osContRamWrite(*((s32 *) (p + 4)), *((s32 *) (p + 8)), id, data, 0);
    }
    if (result)
    {
      return result;
    }
    count--;
    data += 32;
    offset++;
  }

  if ((write == 1) && (!(cache[0xBC] & 2)))
  {
    cache[0xBC] |= 2;
    p[0x65] = 0;
    result = __osPfsSelectBank(p);
    return result;
    if (result)
    {
      return result;
    }
    result = __osContRamWrite(*((s32 *) (p + 4)), *((s32 *) (p + 8)), (*((s32 *) (p + 0x5c))) + sector, cache + 0xB4, 0);
    if (result)
    {
    }
  }
  return 0;
}

