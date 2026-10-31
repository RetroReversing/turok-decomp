#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
s32 __osPfsSelectBank(void *);
s32 __osContRamWrite(s32, s32, s32, s32, s32);
s32 __osClearPage(void *arg0, s32 arg1, s32 arg2, u8 arg3)
{
  
    s32 temp_t5;
  s32 __repair_sp20_1;
  
  __repair_sp20_1 = 0;
  *((u8 *) (((char *) arg0) + 0x65)) = arg3;
  __repair_sp20_1 = __osPfsSelectBank(arg0);
  if (__repair_sp20_1 != 0)
  {
    return __repair_sp20_1;
  }
  temp_t5 = 0;
  loop_3:
  __repair_sp20_1 = __osContRamWrite(*((s32 *) (((char *) arg0) + 4)), *((s32 *) (((char *) arg0) + 8)), (arg1 * 8) + temp_t5, arg2, 0);

  if (__repair_sp20_1 == 0)
  {
    temp_t5 = temp_t5 + 1;
    temp_t5 = temp_t5;
    if (temp_t5 < 8)
    {
      goto loop_3;
    }
  }
  *((u8 *) (((char *) arg0) + 0x65)) = 0U;
  __repair_sp20_1 = __osPfsSelectBank(arg0);
  return __repair_sp20_1;
}

