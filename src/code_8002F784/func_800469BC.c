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

f32 func_80019D3C(s32, s32, s32, void *);           /* extern */

void func_800469BC(void *arg0, void *arg1) {
    f64 temp_ft2;

    M2C_FIELD(arg1, s32 *, 0x20) = 7;
    temp_ft2 = (f64) func_80019D3C(M2C_FIELD(arg0, s32 *, 0x14), M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 0xC), arg0) + 50.0;
    M2C_FIELD(arg1, f32 *, 0x1E8) = 0.0f;
    M2C_FIELD(arg1, f32 *, 0x1EC) = 0.0f;
    M2C_FIELD(arg1, f32 *, 0x60) = 0.0f;
    M2C_FIELD(arg1, f32 *, 0x1E4) = (f32) temp_ft2;
}
