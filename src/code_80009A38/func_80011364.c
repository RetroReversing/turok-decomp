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

M2C_UNK func_80011194();                            /* extern */
M2C_UNK func_800111F4();                            /* extern */
s32 func_8009F760(M2C_UNK *, s32, M2C_UNK *);       /* extern */
extern M2C_UNK D_80119A08;
extern M2C_UNK D_80119A90;

s32 func_80011364(s32 arg0) {
    s32 temp_v0;
    s32 sp1C;

    func_80011194();
    temp_v0 = func_8009F760(&D_80119A08, arg0, &D_80119A90);
    sp1C = temp_v0;
    func_800111F4();
    return temp_v0;
}
