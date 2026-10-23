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

M2C_UNK func_8008A4DC(M2C_UNK, void *);             /* extern */
M2C_UNK func_8008A5C4(s32);                         /* extern */

void func_800479B4(s32 arg0, void *arg1) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg1, s32 *, 0x1F4);
    if (temp_a0 != -1) {
        func_8008A5C4(temp_a0);
        M2C_FIELD(arg1, s32 *, 0x1F4) = -1;
        func_8008A4DC(0x15E, arg1);
    }
}
