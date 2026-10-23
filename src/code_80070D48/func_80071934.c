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

void *func_8002E438(M2C_UNK *, void *);             /* extern */
extern M2C_UNK D_800FA3C8;

f32 func_80071934(void *arg0) {
    void *temp_a1;
    void *temp_v0;

    if (arg0 == NULL) {
        return 0.0f;
    }
    temp_a1 = M2C_FIELD(arg0, void **, 0x14);
    if (temp_a1 == NULL) {
        return 0.0f;
    }
    if (!(M2C_FIELD(temp_a1, u16 *, 2) & 1)) {
        return 0.0f;
    }
    temp_v0 = func_8002E438(&D_800FA3C8, temp_a1);
    if (temp_v0 == NULL) {
        return 0.0f;
    }
    return M2C_FIELD(temp_v0, f32 *, 0x20);
}
