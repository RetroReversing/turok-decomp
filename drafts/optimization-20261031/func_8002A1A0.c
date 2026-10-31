#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct 
{
  u8 pad[0xA8];
  s32 *pA8;
  u8 pad2[0xC];
  u32 b8;
} Obj;
extern s32 func_8002814C(void);
extern void CParticle__Spawn(Obj *, u32, s32);
extern void func_80031974(void *, s32, f32, Obj *, void *, s32);
extern void func_80070DA8(Obj *, u32, u32, s32, s32, s32, s32, f32);
extern f32 D_800FA3C8;
void func_8002A1A0(Obj *p)
{
  char *__repair_addr;
  s32 *base;
  s32 mode;
  u32 id;
  u32 sound;
  u32 anim;
  f32 f;
  base = p->pA8;
  if (func_8002814C())
  {
    mode = 13;
  }
  else
  {
    mode = 11;
  }
  id = *((u16 *) ((((u8 *) (*base)) + 0x38) + (mode * 2)));
  f = ((f32 *) (*base))[mode];
  sound = *((u16 *) ((((u8 *) (*base)) + 0x54) + (mode * 2)));
  anim = *((u16 *) ((((u8 *) (*base)) + 0x70) + (mode * 2)));
  if (id != 0xffff)
  {
    CParticle__Spawn(p, id, 1);
  }
  if (sound != 0xffff)
  {
    func_80070DA8(p, p->b8, sound, -1, *((s32 *) __repair_addr), *((s32 *) (((u8 *) p) + 8)), *((s32 *) (((u8 *) p) + 12)), f);
    __repair_addr = (char *) (((u8 *) p) + 4);
  }
  if (anim != 0xffff)
  {
    func_80031974(&D_800FA3C8, anim, 1.0f, p, ((u8 *) p) + 4, 0);
  }
}

