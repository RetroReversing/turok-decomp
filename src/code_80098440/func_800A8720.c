#include "common.h"

/* identical to __osSumcalc in wonder (matched), with its names changed by decompdecomp */
u16 func_800A8720(u8* ptr, int length) {
    int i;
    u32 sum = 0;
    u8* tmp = ptr;

    for (i = 0; i < length; i++) {
        sum += *tmp++;
        sum = sum & 0xFFFF;
    }

    return sum;
}
