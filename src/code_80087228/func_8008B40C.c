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

extern f32 D_800ECF4C;
extern s16 D_800ECF50;
extern M2C_UNK D_80129520;

void func_8008B40C(f32 arg0) {
    M2C_FIELD(&D_80129520, f32 *, 0x19D4) = arg0;
    M2C_FIELD(&D_80129520, f32 *, 0x19C4) = 0.0f;
    M2C_FIELD(&D_80129520, f32 *, 0x19C8) = 0.0f;
    M2C_FIELD(&D_80129520, f32 *, 0x19CC) = 0.0f;
    M2C_FIELD(&D_80129520, f32 *, 0x19D0) = 0.0f;
    M2C_FIELD(&D_80129520, f32 *, 0x19D8) = (f32) (32000.0f / arg0);
    D_800ECF4C = 1.0f;
    D_800ECF50 = 0x7D00;
}
