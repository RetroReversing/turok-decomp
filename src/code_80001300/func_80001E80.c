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

void func_80001E80(void *arg0, s8 *arg1, s8 *arg2, s8 *arg3) {
    *arg1 = M2C_FIELD(arg0, u8 *, 0x1F8CC) & 0xF8;
    *arg2 = M2C_FIELD(arg0, u8 *, 0x1F8CD) & 0xF8;
    *arg3 = M2C_FIELD(arg0, u8 *, 0x1F8CE) & 0xF8;
}
