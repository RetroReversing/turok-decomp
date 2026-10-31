#include "common.h"

/* identical to gl_func_000718C0 in 1080-decomp (matched), with its names changed by decompdecomp */
s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum)
{
    u16 data;
    u32 j;
    data = 0;
    *icsum = 0;
    *csum = *icsum;
    for (j = 0; j < 28; j += 2)
    {
        data = *(u16 *)((u8 *)ptr + j);
        *csum += data;
        *icsum += ~data;
    }
    return 0;
}
