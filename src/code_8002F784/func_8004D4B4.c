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

extern f32 D_800B6B00;

void func_8004D4B4(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, f32 *, 0x258) = (f32) (M2C_FIELD(arg1, f32 *, 0x258) - D_800B6B00);
    if (M2C_FIELD(arg1, f32 *, 0x258) < 0.0f) {
        M2C_FIELD(arg1, f32 *, 0x258) = 0.0f;
    }
    M2C_FIELD(arg1, f32 *, 0x254) = (f32) (M2C_FIELD(arg1, f32 *, 0x254) - D_800B6B00);
    if (M2C_FIELD(arg1, f32 *, 0x254) < 0.0f) {
        M2C_FIELD(arg1, f32 *, 0x254) = 0.0f;
    }
}
