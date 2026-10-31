#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct 
{
  s16 kind;
  u16 pad;
  s32 zero;
  u8 b0;
  u8 b1;
  u8 b2;
  u8 unused[5];
} Rec;
extern void alEvtqPostEvent(void *, Rec *, s32);
void func_800A4C00(char *a0, u8 a1, u8 a2)
{
  Rec rec;
  rec.kind = 2;
  rec.zero = 0;
  rec.b0 = a1 | 0xb0;
  rec.b1 = 0x5b;
  rec.b2 = a2;
  alEvtqPostEvent(a0 + 0x48, &rec, 0);
}

