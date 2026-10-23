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

M2C_UNK func_80095124(s32);                         /* extern */

void func_80095548(s32 arg0) {
    s32 temp_t7;
    s32 temp_t8;

    temp_t7 = (arg0 >> 4) & 0xF;
    if (temp_t7 >= 0xA) {
        func_80095124(temp_t7 + 0x57);
    } else {
        func_80095124(temp_t7 + 0x30);
    }
    temp_t8 = arg0 & 0xF;
    if (temp_t8 >= 0xA) {
        func_80095124(temp_t8 + 0x57);
        return;
    }
    func_80095124(temp_t8 + 0x30);
}
