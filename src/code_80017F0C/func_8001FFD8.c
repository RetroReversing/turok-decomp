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

s32 func_8001D398();                                /* extern */
M2C_UNK func_8001FAC0(void *);                      /* extern */
M2C_UNK func_8001FE40(void *);                      /* extern */
s32 func_800717E8(s32);                             /* extern */
s32 func_80071804(s32);                             /* extern */
s32 func_80071820(s32);                             /* extern */
extern f32 D_800B6B00;
extern f64 D_800F1618;
extern s32 D_80119798;

void func_8001FFD8(void *arg0) {
    s32 sp1C;
    s32 temp_v0;

    if (D_80119798 == 0) {
        temp_v0 = func_8001D398();
        sp1C = temp_v0;
        if (func_80071820(temp_v0) != 0) {
            func_8001FE40(arg0);
            return;
        }
        if (func_80071804(sp1C) != 0) {
            func_8001FAC0(arg0);
            return;
        }
        if (func_800717E8(sp1C) != 0) {
            M2C_FIELD(arg0, f32 *, 0x17C) = (f32) ((f64) D_800B6B00 * D_800F1618);
        }
    }
}
