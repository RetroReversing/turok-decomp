#include "common.h"

extern void func_8003983C(void *, s32);
extern u8 D_80112C18[];
typedef struct 
{
  u8 pad0[0x7ad8];
  s32 x;
  u8 pad1[0x11e8];
  s32 flags;
  u8 pad2[0x178];
  s32 owner;
} Obj;
extern Obj D_80109F10;
void func_80049B68(s32 a0, u8 *a1)
{
  Obj *p;
  *((s32 *) (a1 + 0x20)) = 0x28;
  (&D_80109F10)->owner = a0;
  (&D_80109F10)->flags |= 0x4000;
  (&D_80109F10)->owner = a0;
  (&D_80109F10)->x = 0;
  func_8003983C(D_80112C18, 0x100);
}
