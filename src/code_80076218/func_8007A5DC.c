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

M2C_UNK func_8005FCF4(void *, M2C_UNK, M2C_UNK);    /* extern */
extern f64 D_800F5D10;
extern f64 D_800F5D18;

void func_8007A5DC(void *arg0, M2C_UNK arg1, void *arg2, s32 arg3) {
    f32 temp_fv0;
    f32 var_fv1;
    f64 temp_fv0_2;

    temp_fv0 = M2C_FIELD(arg2, f32 *, 0);
    if (temp_fv0 < 0.0f) {
        var_fv1 = -temp_fv0;
    } else {
        var_fv1 = temp_fv0;
    }
    if ((arg3 == 1) && (M2C_FIELD(arg2, s32 *, 0x274) == 0)) {
        func_8005FCF4(arg0, 0xFB, 1);
        M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) & ~0x10);
        return;
    }
    temp_fv0_2 = (f64) var_fv1;
    if ((temp_fv0_2 < D_800F5D10) || (arg3 != 0)) {
        func_8005FCF4(arg0, 0x27, 1);
        M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) & ~0x10);
        return;
    }
    if (temp_fv0_2 <= D_800F5D18) {
        func_8005FCF4(arg0, 0x28, 1);
        M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) & ~0x10);
        return;
    }
    func_8005FCF4(arg0, 0x29, 1);
    M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) & ~0x10);
}
