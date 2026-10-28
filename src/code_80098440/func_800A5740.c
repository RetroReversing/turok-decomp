#include "common.h"

extern s32 D_A4500004;
s32 func_800A5740(void)
{
  return D_A4500004 & 0xFFFFFFFFFFFFFFFFu;
}
