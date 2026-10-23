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

M2C_UNK func_8007E38C(s32, s32, s32, s32, f32, s32, s32); /* extern */
M2C_UNK func_80098670(M2C_UNK *, s32 *, s32 *, s32 *, f32 *); /* extern */
extern M2C_UNK D_80135BE0;

void func_8007DF74(s32 arg0, s32 arg1) {
    s32 sp34;
    s32 sp30;
    f32 sp2C;
    s32 sp28;

    func_80098670(&D_80135BE0, &sp28, &sp34, &sp30, &sp2C);
    if (sp28 != 0) {
        func_8007E38C(arg0, arg1, sp34, sp30, sp2C, 1, 0);
    }
}
