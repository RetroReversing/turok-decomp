#include "common.h"

s32 func_8002DBF8(s32, s32, s32, s32 *);
void func_80026D64(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0[0] = 0;
    arg0[1] = func_8002DBF8(arg1, arg2, arg3, arg0 + 2);
}
