#include "common.h"

/* Return the end of the copied byte range. */
s32 func_8009FA50();
s32 func_8009E5B0(s32 dest, s32 src, s32 count)
{
    return func_8009FA50(dest, src) + count;
}
