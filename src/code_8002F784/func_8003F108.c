#include "common.h"

extern u8 D_80109F10[];
void func_8003F108(void *arg0)
{
  s32 i;
  u8 *p;
  u32 base;
  *((s32 *) (((u8 *) arg0) + 4)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x3D8)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x7AC)) = 0;
  *((s32 *) (((u8 *) arg0) + 0xD60)) = 0;
  i = 0;
  p = arg0;
  do
  {
    i++;
    p += 0x18;
 *((s32 *) (p + 0xB78)) = -1; *((s32 *) (p + 0xB68)) = 0;
  }
  while (i < 20);
  *((s32 *) (((u8 *) arg0) + 0xEA8)) = 0;
  i = 0;
  p = arg0;
  for (; i != 20; i++)
  {
    i += 3;
    *((s32 *) (p + 0xD78)) = 0;
    *((s32 *) (p + 0xD88)) = 0;
    *((s32 *) (p + 0xD98)) = 0;
    p += 0x40;
    *((s32 *) (p + 0xD28)) = 0;
  }

  base = (u32) D_80109F10;
  *((s32 *) arg0) = 0;
  *((volatile s32 *) (base + 0x8CC8)) = 0;
  *((s32 *) (((u8 *) arg0) + 0xD64)) = 0;
  *((s32 *) (base + 0x7AD8)) = 0;
}
