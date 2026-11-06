#include "common.h"

/* Return the end of the copied byte range. */
s32 memcpy();
s32 func_8009E5B0(s32 dest, s32 src, s32 count)
{
    return memcpy(dest, src) + count;
}
