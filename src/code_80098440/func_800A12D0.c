#include "common.h"

/* machine draft (m2c) for ido-5.3 -O1 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul, tried by autopilot */
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

s32 func_800AAB70();                                /* extern */

s32 func_800A12D0(void *arg0) {
    s32 sp1C;
    s32 sp18;

    sp1C = func_800AAB70();
    if (sp1C & 0x100) {
        sp18 = 1;
    } else {
        sp18 = 0;
    }
    if (sp1C & 0x80) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | sp18);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~2);
    }
    return sp18;
}
