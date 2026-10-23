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

void func_800AB1A4(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg1 * 0x10;
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x60) + temp_v0), s8 *, 6) = 0;
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x60) + temp_v0), s8 *, 0xA) = 0;
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x60) + temp_v0), s8 *, 7) = 0x40;
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x60) + temp_v0), s8 *, 9) = 0x7F;
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x60) + temp_v0), s8 *, 8) = 5;
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x60) + temp_v0), s8 *, 0xB) = 0;
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x60) + temp_v0), s16 *, 4) = 0xC8;
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x60) + temp_v0), f32 *, 0xC) = 1.0f;
}
