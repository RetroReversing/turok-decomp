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

M2C_UNK func_800121B8(s32, M2C_UNK, s32);           /* extern */
s32 func_8002DC3C(s32 **, s32 *, M2C_UNK, s32 *);   /* extern */
M2C_UNK *func_8002DC68(s32 **, s32 *, s32);         /* extern */
M2C_UNK func_8002DD28(s32 **, M2C_UNK *, M2C_UNK);  /* extern */
extern s32 D_800BA910;
extern M2C_UNK D_8014F688;

void func_80034998(void) {
    s32 padding[4];
    s32 * sp60[2];
    s32 var_s0;
    s32 * sp68[2];
    s32 * sp70[3];
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 temp_s2;

    if (D_800BA910 != 0) {
        func_8002DD28(&sp70[10], &D_8014F688, 0);
        func_800121B8(func_8002DC3C(&sp70[10], sp70[10], 0, &sp44), 0, sp44);
        func_8002DD28(&sp68[5], func_8002DC68(&sp70[10], sp70[10], 1), 0);
        var_s0 = 0;
        temp_s2 = *sp68[5];
        if (temp_s2 > 0) {
            do {
                func_8002DD28(&sp60[0], func_8002DC68(&sp68[5], sp68[5], var_s0), 0);
                func_800121B8(func_8002DC3C(&sp60[0], sp60[0], 0, &sp40), 0, sp40);
                func_800121B8(func_8002DC3C(&sp60[0], sp60[0], 1, &sp3C), 0, sp3C);
                var_s0 += 1;
            } while (var_s0 != temp_s2);
        }
        func_800121B8(func_8002DC3C(&sp70[10], sp70[10], 2, &sp38), 0, sp38);
    }
}
