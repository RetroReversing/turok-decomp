#include "common.h"

extern s32 func_800ACBAC(s32, s16 *, s32);
void func_800A4BC0(s32 a, s32 b) {
    s16 x[7];
    x[0] = 14;
    *(s32 *)(x + 2) = b;
    func_800ACBAC(a + 0x48, x, 0);
}
