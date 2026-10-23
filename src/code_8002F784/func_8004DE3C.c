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

M2C_UNK func_8004DDA8(arg0);                            /* extern */
extern f32 D_800B6B00;
extern f64 D_800F2DB0;

s32 func_8004DE3C(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, f32 *, 0x210) = (f32) (M2C_FIELD(arg1, f32 *, 0x210) + D_800B6B00);
    if ((M2C_FIELD(M2C_FIELD(arg1, void **, 0x184), f32 *, 8) < M2C_FIELD(arg1, f32 *, 0x210)) && ((f64) M2C_FIELD(arg1, f32 *, 0x14C) <= D_800F2DB0)) {
        M2C_FIELD(arg1, f32 *, 0x210) = 0.0f;
        func_8004DDA8(arg0);
    }
    return M2C_FIELD(arg1, s32 *, 0x20) != M2C_FIELD(arg1, s32 *, 0x24);
}
