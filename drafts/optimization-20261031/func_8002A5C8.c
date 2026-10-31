#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern s32 func_80019ED8(void *);
extern s32 func_800210C0(void *);
extern s32 func_800210FC(void *);
extern void func_8002A4BC(void *, s32);
extern void func_80070DA8(void *, s32, s32, s32, s32, s32, s32, f32);
extern void func_80031974(void *, s32, s32, void *, void *, s32);
extern void func_8002864C(void *, void *);
extern u8 D_800FA3C8;
extern u8 D_80102228;
void func_8002A5C8(u8 *self)
{
  char *__repair_addr;
  s32 mode;
  s32 *list;
  s32 anim;
  s32 effect;
  s32 sound;
  f32 value;
  if (func_80019ED8(*((void **) (self + 0x14))))
  {
    mode = func_800210C0(*((void **) (self + 0x14)));
  }
  else
  {
    mode = func_800210FC(*((void **) (self + 0x14)));
  }
  list = *((s32 **) (self + 0xA8));
  effect = *((u16 *) ((((u8 *) list[0]) + (mode * 2)) + 0x38));
  __repair_addr = (char *) (((u8 *) list[0]) + (mode * 4));
  value = *((f32 *) __repair_addr);
  sound = *((u16 *) ((((u8 *) list[0]) + (mode * 2)) + 0x54));
  anim = *((u16 *) ((((u8 *) list[0]) + (mode * 2)) + 0x70));
  if (effect != 0xFFFF)
  {
    func_8002A4BC(self, effect);
  }
  if (sound != 0xFFFF)
  {
    func_80070DA8(self, *((s32 *) (self + 0xB8)), sound, -1, *((s32 *) (self + 0x144)), *((s32 *) (self + 0x148)), *((s32 *) (self + 0x14C)), value);
  }
  if (anim != 0xFFFF)
  {
 ;
    func_80031974(&D_800FA3C8, anim ^ 0, 0, self, self + 0x144, 0);
  }
  if ((*((s32 *) (self + 0xFC))) == 1)
  {
    func_8002864C(&D_80102228, self);
  }
}

