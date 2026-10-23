#include "common.h"

/* machine draft (m2c) for ido-5.3 -O2 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_8002D690(s32);                             /* extern */
s32 func_8002DC68(s32 **, s32 *, M2C_UNK);          /* extern */
M2C_UNK func_8002DD28(s32 **, s32, M2C_UNK);        /* extern */

void func_80026AD0(s32 *arg0, void *arg1) {
    s32 *sp40[2];
    s32 *sp38[2];
    s32 *sp30[4];

    func_8002DD28(&sp40[0], func_8002D690(*arg0), 0);
    if (*sp40[0] != 0) {
        M2C_FIELD(arg1, s32 *, 8) = func_8002DC68(&sp40[0], sp40[0], 0);
        func_8002DD28(&sp38[0], func_8002DC68(&sp40[0], sp40[0], 1), 0);
        M2C_FIELD(arg1, s32 *, 0) = (s32) *sp38[0];
        func_8002DD28(&sp30[2], func_8002DC68(&sp40[0], sp40[0], 2), 0);
        M2C_FIELD(arg1, s32 *, 4) = (s32) *sp30[2];
        return;
    }
    M2C_FIELD(arg1, s32 *, 8) = 0;
    M2C_FIELD(arg1, s32 *, 0) = 0;
    M2C_FIELD(arg1, s32 *, 4) = 0;
}
