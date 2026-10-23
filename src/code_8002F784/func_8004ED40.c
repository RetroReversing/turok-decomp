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

s32 func_8004D1C0();                                /* extern */
M2C_UNK func_8004DACC(s32, M2C_UNK);                /* extern */
extern f64 D_800F2EA0;
extern f64 D_800F2EA8;
extern f64 D_800F2EB0;
extern f64 D_800F2EB8;
extern s32 D_80128E4C;

void func_8004ED40(s32 arg0, void *arg1) {
    f32 temp_fv1;
    f32 sp1C;
    f32 var_fv0;
    f32 var_fv0_2;
    f64 temp_fv0;

    temp_fv1 = M2C_FIELD(arg1, f32 *, 0x114);
    sp1C = temp_fv1;
    if ((func_8004D1C0() == 0) && (M2C_FIELD(arg1, s32 *, 0x20) != 0x25)) {
        if (temp_fv1 < 0.0f) {
            var_fv0 = -temp_fv1;
        } else {
            var_fv0 = temp_fv1;
        }
        if (D_800F2EA0 < (f64) var_fv0) {
            M2C_FIELD(arg1, s32 *, 0x20) = 0x25;
        } else {
            temp_fv0 = (f64) temp_fv1;
            if (temp_fv0 < D_800F2EA8) {
                M2C_FIELD(arg1, s32 *, 0x20) = 0x26;
            } else if (D_800F2EB0 < temp_fv0) {
                M2C_FIELD(arg1, s32 *, 0x20) = 0x27;
            }
        }
    }
    if (temp_fv1 < 0.0f) {
        var_fv0_2 = -temp_fv1;
    } else {
        var_fv0_2 = temp_fv1;
    }
    if ((f64) var_fv0_2 <= D_800F2EB8) {
        M2C_FIELD(arg1, s32 *, 0x20) = 0x24;
    }
    if (D_80128E4C != 0) {
        func_8004DACC(arg0, 0x28);
        D_80128E4C = 0;
    }
}
