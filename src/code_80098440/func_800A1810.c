#include "common.h"

extern s32 D_800EF210;
extern s32 func_800AB120(void);
extern s32 func_800AAFD0(s32, void *, s32);
extern s32 func_800A1180(s32, void *, s32);
s32 func_800A1810(void * volatile arg0, volatile s32 arg1, volatile s32 arg2, int arg3, s32 arg4, s32 arg5, s32 arg6)
{
  register s32 result;
  register s32 handle;
  if (D_800EF210 == 0)
  {
    return -1;
  }
  else
  {
    *((s16 *) arg0) = (arg2 == 0) ? (0xB) : (0xC);
    *(((s8 *) arg0) + 2) = arg1;
    *((s32 *) (((u8 *) arg0) + 4)) = arg6;
    *((s32 *) (((u8 *) arg0) + 8)) = arg4;
    *((s32 *) (((u8 *) arg0) + 12)) = arg3;
    *((s32 *) (((u8 *) arg0) + 16)) = arg5;
    *((s32 *) (((u8 *) arg0) + 20)) = 0;
    if (arg1 == 1)
    {
      handle = func_800AB120();
      result = func_800AAFD0(handle, arg0, 0);
    }
    else
    {
      handle = func_800AB120();
      result = func_800A1180(handle, arg0, 0);
    }
  }
  return result;
}
