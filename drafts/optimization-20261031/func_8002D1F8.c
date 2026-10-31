#include "context_8d698fdff8b3.h"
#line 1 "func.c"
/* machine draft (m2c) for ido-5.3 -O3 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul, tried by autopilot */
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

M2C_UNK CCartCache__BlockReceived(void *, s32, u32, s32); /* extern */
M2C_UNK func_8002D020(s32, s32, u32, s32);          /* extern */
s32 func_8002D120(void *, u32, s32, s32);           /* extern */
void *func_8002D1D0(void *, void **);               /* extern */
s32 func_8002E13C(s32, void **);                    /* extern */

void func_8002D1F8(void *arg0, s32 arg1, s32 arg2, M2C_UNK (*arg3)(s32, void **), void **arg4, s32 arg5, u32 arg6, s32 arg7) {
    s32 sp3C;
    void *sp38;
    void *sp34;
    s32 sp2C;
    s32 temp_v0_2;
    s32 var_a3;
    s32 var_v0;
    u32 var_t0;
    void *temp_v0;
    void *temp_v0_3;
    void *var_v0_2;

    sp38 = NULL;
    if (func_8002E13C(arg5, &sp38) != 0) {
        var_t0 = arg6;
        var_v0 = (u32) M2C_FIELD(sp38, u32 *, 0xC) < var_t0;
    } else {
        var_v0 = 1;
        var_t0 = arg6;
    }
    if (var_v0 != 0) {
        if (var_t0 & 1) {
            var_t0 += 1;
        }
        arg6 = var_t0;
        temp_v0 = func_8002D1D0(arg0, arg4);
        if (temp_v0 != NULL) {
            var_v0_2 = M2C_FIELD(arg0, void **, 0x18);
            var_a3 = 0;
            if (var_v0_2 != NULL) {
loop_8:
                if ((arg5 == M2C_FIELD(var_v0_2, s32 *, 0x10)) && ((u32) M2C_FIELD(var_v0_2, u32 *, 0x14) >= arg6)) {
                    var_a3 = 1;
                } else {
                    var_v0_2 = M2C_FIELD(var_v0_2, void **, 0x20);
                    if (var_v0_2 != NULL) {
                        goto loop_8;
                    }
                }
            }
            if (var_a3 == 0) {
                sp34 = temp_v0;
                sp3C = var_a3;
                temp_v0_2 = func_8002D120(arg0, arg6, arg2 != 0, var_a3);
                sp2C = temp_v0_2;
                if (temp_v0_2 == 0) {
                    M2C_FIELD(temp_v0, void **, 0x24) = (void *) M2C_FIELD(arg0, void **, 0x6AB0);
                    M2C_FIELD(arg0, void **, 0x6AB0) = temp_v0;
                }
            }
            if ((sp2C != 0) || (var_a3 != 0)) {
                M2C_FIELD(temp_v0, s32 *, 0) = arg1;
                M2C_FIELD(temp_v0, s32 *, 4) = arg2;
                M2C_FIELD(temp_v0, s32 *, 0x10) = arg5;
                M2C_FIELD(temp_v0, u32 *, 0x14) = arg6;
                M2C_FIELD(temp_v0, void ***, 0xC) = arg4;
                M2C_FIELD(temp_v0, M2C_UNK (**)(s32, void **), 8) = arg3;
                M2C_FIELD(temp_v0, s32 *, 0x18) = arg7;
                temp_v0_3 = M2C_FIELD(arg0, void **, 0x1C);
                if (temp_v0_3 != NULL) {
                    M2C_FIELD(temp_v0_3, void **, 0x20) = temp_v0;
                } else {
                    M2C_FIELD(arg0, void **, 0x18) = temp_v0;
                }
                M2C_FIELD(temp_v0, s32 *, 0x20) = 0;
                M2C_FIELD(temp_v0, void **, 0x1C) = (void *) M2C_FIELD(arg0, void **, 0x1C);
                M2C_FIELD(arg0, void **, 0x1C) = temp_v0;
            }
            if ((sp2C != 0) && (var_a3 == 0)) {
                func_8002D020(sp2C, arg5 & 0x3FFFFFFF, arg6, var_a3);
                CCartCache__BlockReceived(arg0, arg5, arg6, sp2C);
            }
        }
    } else {
        *arg4 = sp38;
        if (arg3 != NULL) {
            arg3(arg1, arg4);
        }
    }
}

