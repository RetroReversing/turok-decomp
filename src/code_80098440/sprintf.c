#include "common.h"

s32 func_800A7E80(void *, s8 *, s32, void *);
s32 func_8009E5B0();
s32 sprintf(s8 *arg0, volatile s32 arg1, s32 arg2, ...) {
    s32 v = func_800A7E80(func_8009E5B0, arg0, arg1, &arg2);
    if (v >= 0) arg0[v] = 0;
    return v;
}
