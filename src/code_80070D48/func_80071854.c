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

s32 func_8001BA24();                                /* extern */
extern f32 D_800B6B00;
extern f64 D_800F5590;

void func_80071854(void *arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, f32 *, 0x1C8) != 0.0f) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x1D0);
        if ((temp_v0 & 0x1000) && (M2C_FIELD(arg0, s16 *, 0x1DC) <= 0) && !(temp_v0 & 0x10000) && !(temp_v0 & 0x20000) && (func_8001BA24() != 0)) {
            M2C_FIELD(arg0, f32 *, 0x1C8) = (f32) ((f64) M2C_FIELD(arg0, f32 *, 0x1C8) - ((f64) D_800B6B00 * D_800F5590));
            if ((f64) M2C_FIELD(arg0, f32 *, 0x1C8) < 0.0) {
                M2C_FIELD(arg0, f32 *, 0x1C8) = 0.0f;
            }
        }
    }
}
