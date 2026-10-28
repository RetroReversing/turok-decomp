#include "common.h"

extern s32 D_80137C90[16];
extern s32 D_80137CCC;
extern s32 func_800B0D50(u16);
void func_800AA124(s32 arg0, u16 arg1)
{
  u8 *p = (u8 *) D_80137C90;
  struct Record
  {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    s16 e;
    u8 f[32];
    u8 g;
    u8 h;
  } rec;
  s32 i;
  for (i = 0; i < 16; i++)
  {
    D_80137C90[i] = 0;
  }

  D_80137CCC = 1;
  rec.a = 0xFF;
  rec.b = 3;
  rec.c = 0x21;
  rec.d = 2;
  if (!D_80137C90)
  {
  }
  rec.e = func_800B0D50(arg1) | (arg1 << 5);
  rec.g = 0xFF;
  for (i = 0; i < 32; i++)
  {
    rec.f[i] = 0xFF;
  }

  if (arg0)
  {
    for (i = 0; i < arg0; i++)
    {
      *p = 0;
      p++;
    }

  }
  *((struct Record *) p) = rec;
  p += 0x28;
  *p = 0xFE;
}
