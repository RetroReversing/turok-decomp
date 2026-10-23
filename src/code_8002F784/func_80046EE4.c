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

s32 func_80045B3C();                                /* extern */
s32 func_80045B60(s32, void *);                     /* extern */

void func_80046EE4(s32 arg0, void *arg1) {
    if ((M2C_FIELD(arg1, s16 *, 0x108) == 1) || (func_80045B3C() != 0)) {
        M2C_FIELD(arg1, s32 *, 0x20) = 0x19;
        return;
    }
    if (func_80045B60(arg0, arg1) != 0) {
        M2C_FIELD(arg1, s32 *, 0x20) = 0x24;
        return;
    }
    if (M2C_FIELD(arg1, s32 *, 0x19C) != 0) {
        M2C_FIELD(arg1, s32 *, 0x20) = 0x11;
        return;
    }
    M2C_FIELD(arg1, s32 *, 0x20) = 2;
}
