#include "common.h"

extern u8 D_800BE838[0x78];
extern s32 func_8001DE20(void *, s32);
extern s32 func_8001E9B8(void *, s32, void *, s32);
extern s32 func_8005FCA0(void *, s32, s32);
extern s32 func_8007223C(void *, f32);
extern s32 func_80073FD8(void *, f32);
void func_80076824(void *instance, f32 elapsed, s32 force)
{
  /* Update an instance and choose a flagged animation when its state permits. */
  s32 v1;
  s32 v13;
  struct Copy
  {
    u32 data[30];
  } sp20;
  sp20 = *((struct Copy *) D_800BE838);
  if (func_8001DE20(instance, *((s32 *) (((u8 *) instance) + 0x224))) == 0)
  {
    if (force)
    {
      func_80073FD8(instance, elapsed);
      return;
    }
    if (((*((s32 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x38))) << 10) >= 0)
    {
      func_8007223C(instance, elapsed);
    }
  }
  else
  {
    if (((*((s32 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x38))) << 10) < 0)
    {
      v1 = 1;
    }
    else
    {
      v1 = func_8007223C(instance, elapsed);
    }
    if (v1)
    {
      s32 v14;
      v1 = *((u32 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x38));
      if (v1 & 2)
      {
        sp20.data[2] = 1;
        v1 = *((u32 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x38));
      }
      if (v1 & 0x40)
      {
        sp20.data[5] = 1;
      }
      v13 = *((u32 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x3c));
      if (v13 & 0x40000000)
      {
        sp20.data[8] = 1;
        v13 = *((u32 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x3c));
      }
      if (v13 & 0x80000000)
      {
        sp20.data[11] = 1;
        v13 = *((u32 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x3c));
      }
      if (v13 & 0x01000000)
      {
        sp20.data[14] = 1;
        v13 = *((u32 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x3c));
      }
      if (v13 & 0x02000000)
      {
        sp20.data[17] = 1;
        v13 = *((u32 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x3c));
      }
      if (v13 & 0x20000)
      {
        sp20.data[20] = 1;
        v13 = *((u32 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x3c));
      }
      if (v13 & 0x40000)
      {
        sp20.data[23] = 1;
      }
      v14 = *((u16 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x40));
      if (v14 & 0x100)
      {
        sp20.data[26] = 1;
        v14 = *((u16 *) ((*((u32 *) (((u8 *) instance) + 0x18))) + 0x40));
      }
      if (v14 & 0x200)
      {
        sp20.data[29] = 1;
      }
      v1 = func_8001E9B8(instance, 10, &sp20, 0);
      func_8005FCA0(instance, v1, 0);
      *((u32 *) (((u8 *) instance) + 0x1D0)) |= 0x10;
    }
  }
}
