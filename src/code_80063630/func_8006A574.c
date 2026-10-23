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
M2C_UNK func_8005EED0(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_8006A574(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    if (func_8001D398() == 0x3EA) {
        func_8005EED0(arg0, 0x166, 0x3F800000, 0);
    }
}
