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

extern void *D_80112BD8;

s32 func_80016584(s32 arg0, M2C_UNK arg1) {
    if (M2C_FIELD(M2C_FIELD(D_80112BD8, void **, 0x17C), s32 *, 0x20) != 0x29) {
        return -1;
    }
    if (M2C_FIELD(D_80112BD8, f32 *, 0x144) < 158.0f) {
        return -1;
    }
    return 0;
}
