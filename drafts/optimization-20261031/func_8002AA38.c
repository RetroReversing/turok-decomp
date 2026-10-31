#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern s32 func_800210C0(void *);
extern void func_8002A8F0(void *, u32);
extern void func_80070DA8(void *, s32, u32, s32, s32, s32, s32, f32);
extern void func_80031974(void *, s32, s32, void *, void *, s32);
extern void func_8002864C(void *, void *);
extern u8 D_800FA3C8;
extern u8 D_80102228;
void func_8002AA38(u8 *arg0)
{
  s32 n;
  u8 *tab;
  u8 *entries;
  u8 *rec;
  u8 *actor = arg0;
  u32 type;
  u32 sound;
  u32 anim;
  f32 val;
  if ((*((u32 *) (arg0 + 0xBC))) & 4)
  {
    tab = *((u8 **) (actor + 0xA8));
    if ((*((u32 *) (tab + 4))) & 0x800)
    {
      goto after;
    }
  }
  n = func_800210C0(*((void **) (arg0 + 0x14)));
  tab = *((u8 **) (arg0 + 0xA8));
  entries = *((u8 **) tab);
  rec = entries + (n * 2);
  type = *((u16 *) (rec + 0x38));
  sound = *((u16 *) (rec + 0x54));
  val = *((f32 *) (entries + (n * 4)));
  anim = *((u16 *) (rec + 0x70));
  if (type != 0xFFFF)
  {
    func_8002A8F0(arg0, type);
  }
  if (sound != 0xFFFF)
  {
    func_80070DA8(arg0, *((s32 *) (arg0 + 0xB8)), sound, -1, *((s32 *) (arg0 + 0x12C)), *((s32 *) (arg0 + 0x130)), *((s32 *) (arg0 + 0x134)), val);
    if ((rec && rec) && rec)
    {
    }
  }
  if (anim != 0xFFFF)
  {
    func_80031974(&D_800FA3C8, anim, 0, arg0, arg0 + 0x12C, 0);
  }
  after:
  if ((sound = *((s32 *) (arg0 + 0xF8))) == 1)
  {
    func_8002864C(&D_80102228, arg0);
  }

}

