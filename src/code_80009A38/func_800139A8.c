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

f32 func_8001349C(f32, f32);                        /* extern */
f32 func_8009E7A0(f32, f32);                        /* extern */
extern f64 D_800F0D10;

f32 func_800139A8(void *arg0) {
    f32 sp1C;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 = M2C_FIELD(arg0, f32 *, 0);
    temp_fa1 = M2C_FIELD(arg0, f32 *, 4);
    temp_fv1 = M2C_FIELD(arg0, f32 *, 8);
    temp_fa0 = (temp_fv0 * temp_fv0) + (temp_fa1 * temp_fa1) + (temp_fv1 * temp_fv1);
    if (temp_fa0 == 0.0f) {
        return 0.0f;
    }
    sp1C = temp_fa1;
    return (f32) ((f64) func_8001349C(temp_fa1 / func_8009E7A0(temp_fa0, temp_fa1), temp_fa1) - D_800F0D10);
}
