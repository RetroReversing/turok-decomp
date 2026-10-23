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

extern M2C_UNK D_80109F10;

void func_800808F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    M2C_FIELD(&D_80109F10, s32 *, 0x7C84) = arg1;
    M2C_FIELD(&D_80109F10, s32 *, 0x7C88) = arg2;
    M2C_FIELD(&D_80109F10, s32 *, 0x7C8C) = arg3;
    M2C_FIELD(&D_80109F10, s32 *, 0x7C90) = arg4;
    M2C_FIELD(&D_80109F10, s32 *, 0x7C94) = arg5;
    M2C_FIELD(&D_80109F10, s32 *, 0x7C98) = arg6;
}
