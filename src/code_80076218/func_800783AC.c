#include "common.h"

s32 func_8001C348(void *, s32, s32 *, s32 *, s32 *);
s32 func_8005FCA0(void *, s32, s32);
s32 func_800719B4();
extern s32 D_800BE930;
extern s32 D_800BE934;
extern s32 D_800BE938;
extern s32 D_800BE93C;
void func_800783AC(void *arg0)
{
  void *new_var;
  s32 *new_var2;
  s32 sp44;
  s32 temp_v0_2;
  s32 sp3C;
  s32 sp38;
  s32 sp34;
  s32 sp30;
  s32 temp_a1;
  sp44 = -1;
  sp3C = D_800BE930;
  sp38 = D_800BE934;
  sp34 = D_800BE938;
  sp30 = D_800BE93C;
  if ((temp_a1 = *((s32 *) (((char *) arg0) + 0x14))) != 0)
  {
    temp_a1 = func_800719B4();
    switch (temp_a1)
    {
      case 1:
        temp_v0_2 = func_8001C348(arg0, 1, &sp3C, &sp38, &sp44);
        *((s32 *) (((char *) arg0) + 0x1D0)) = (s32) ((*((s32 *) (((char *) arg0) + 0x1D0))) & (~0x10));
        func_8005FCA0(arg0, temp_v0_2, 1);
        return;

      default:

      case 3:
        new_var2 = &sp44;
        temp_a1 = func_8001C348(arg0, 1, &sp34, &sp30, new_var2);
        new_var = arg0;
        *((s32 *) (((char *) arg0) + 0x1D0)) = (s32) ((*((s32 *) (((char *) arg0) + 0x1D0))) | 0x10);
        func_8005FCA0(new_var, temp_a1, 1);
        break;

    }

  }
}
