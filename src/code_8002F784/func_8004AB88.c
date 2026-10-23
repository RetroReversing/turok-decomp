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

M2C_UNK func_8004016C(s32, void *, M2C_UNK, f32);   /* extern */
s32 func_8004A7E8(s32);                             /* extern */
M2C_UNK func_8004B024(s32, void *);                 /* extern */
extern f32 D_800F2BC4;
extern f32 D_800F2BC8;
extern f64 D_800F2BD0;
extern f64 D_800F2BD8;
extern f64 D_800F2BE0;
extern f64 D_800F2BE8;
extern f64 D_800F2BF0;
extern f64 D_800F2BF8;
extern f64 D_800F2C00;
extern f64 D_800F2C08;
extern f64 D_800F2C10;
extern f64 D_800F2C18;
extern f64 D_800F2C20;
extern f64 D_800F2C28;
extern f64 D_800F2C30;
extern s32 D_80128ED4;

void func_8004AB88(s32 arg0, void *arg1) {
    f32 temp_fv1;
    f32 sp18;
    f32 sp1C;
    f32 var_fv0;
    f32 var_fv0_3;
    f32 var_fv0_2;
    f32 temp_fv0;
    f64 temp_fv0_3;
    f64 temp_fv0_4;
    register f32 temp_fv1_2;
    f64 temp_fv0_2;

    temp_fv1 = M2C_FIELD(arg1, f32 *, 0x114);
    if (D_80128ED4) {
        sp18 = D_800F2BC4;
    } else {
        sp18 = D_800F2BC8;
    }
    temp_fv0 = M2C_FIELD(arg1, f32 *, 0x124);
    if ((D_800F2BD0 < (f64) temp_fv0) || (M2C_FIELD(arg1, s32 *, 0x34) & 0x200)) {
        sp1C = temp_fv1;
        if (func_8004A7E8(arg0) == 0) {
            if (M2C_FIELD(arg1, s32 *, 0x20) != 0xE) {
                sp1C = temp_fv1;
                temp_fv0_2 = (f64) temp_fv1;
                func_8004016C(arg0, arg1, 0x3E567750, temp_fv1);
                if (temp_fv0_2 < D_800F2BD8) {
                    M2C_FIELD(arg1, s32 *, (unsigned)0x20) = 0xE;
                } else if (temp_fv0_2 < D_800F2BE0) {
                    M2C_FIELD(arg1, s32 *, 0x20) = 0xF;
                } else if (D_800F2BE8 < temp_fv0_2) {
                    M2C_FIELD(arg1, s32 *, 0x20) = (unsigned short)0x10;
                }
            }
            if (temp_fv1 < 0.0f) {
                var_fv0 = -temp_fv1;
            } else {
                var_fv0 = temp_fv1;
            }
            if ((f64) var_fv0 <= D_800F2BF0) {
                M2C_FIELD(arg1, s32 *, 0x20) = 0xD;
            }
        }
    } else if (sp18 < temp_fv0) {
        register sp1C = temp_fv1;
        if (func_8004A7E8(arg0) == 0) {
            if (M2C_FIELD(arg1, s32 *, 0x20) != 0xA) {
                sp1C = temp_fv1;
                temp_fv0_3 = (f64) temp_fv1;
                func_8004016C(arg0, arg1, 0x3DD67750, temp_fv1);
                if (temp_fv0_3 < D_800F2BF8) {
                    M2C_FIELD(arg1, s32 *, 0x20) = 0xA;
                } else if (temp_fv0_3 < D_800F2C00) {
                    M2C_FIELD(arg1, s32 *, 0x20) = 0xB;
                } else if (D_800F2C08 < temp_fv0_3) {
                    M2C_FIELD(arg1, s32 *, 0x20) = 0xC;
                }
            }
            if (temp_fv1 < 0.0f) {
                var_fv0_2 = -temp_fv1;
            } else {
                var_fv0_2 = temp_fv1;
            }
            if ((f64) var_fv0_2 <= D_800F2C10) {
                M2C_FIELD((u32)arg1, s32 *, 0x20) = 9;
            }
        }
    }
    if (M2C_FIELD(arg1, f32 *, 0x124) <= sp18) {
        temp_fv1_2 = M2C_FIELD(arg1, f32 *, 0x110);
        if (M2C_FIELD(arg1, s32 *, 0x20) != 5) {
            temp_fv0_4 = (f64) temp_fv1_2;
            if (temp_fv0_4 < D_800F2C18) {
                M2C_FIELD(arg1, s32 *, 0x20) = 5;
            } else if (temp_fv0_4 < D_800F2C20) {
                M2C_FIELD(arg1, s32 *, 0x20) = 6;
            } else if (temp_fv0_4 > D_800F2C28) {
                M2C_FIELD(arg1, s32 *, 0x20) = 7;
            }
        }
        if (temp_fv1_2 < 0.0f) {
            var_fv0_3 = -temp_fv1_2;
        } else {
            var_fv0_3 = temp_fv1_2;
        }
        if ((f64) var_fv0_3 <= D_800F2C30) {
            M2C_FIELD(arg1, s32 *, 0x20) = 4;
            if (M2C_FIELD(arg1, s16 *, 0x108) != 0) {
                func_8004B024(arg0, arg1);
            }
        }
    }
}
