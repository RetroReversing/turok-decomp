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

s32 func_80034EDC(M2C_UNK *, s32, M2C_UNK *, M2C_UNK, M2C_UNK *); /* extern */
extern s32 D_800B6B38;
extern M2C_UNK D_800FA3C8;
extern M2C_UNK D_801289FC;
extern M2C_UNK func_8004FC54;

s32 func_8004FCA0(s32 arg0) {
    if (D_800B6B38 == 0) {
        return 0;
    }
    return func_80034EDC(&D_800FA3C8, arg0, &D_801289FC, 0, &func_8004FC54);
}
