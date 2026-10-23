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

f32 func_80021348(s32, s32, s32);                   /* extern */
void *func_8002E438(M2C_UNK *, s32);                /* extern */
extern f64 D_800F1E60;
extern M2C_UNK D_800FA3C8;
extern void *D_8010201C;

s32 func_800397A4(s32 arg0) {
    register void *temp_v1;
    void *temp_v0;
    void *sp1C;

    temp_v1 = D_8010201C;
    sp1C = temp_v1;
    temp_v0 = func_8002E438(&D_800FA3C8, M2C_FIELD(temp_v1, s32 *, 0x14));
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x34) & 0x40)) {
        sp1C = temp_v1;
        if ((f64) (func_80021348(M2C_FIELD(temp_v1, s32 *, 0x14), M2C_FIELD(temp_v1, s32 *, 4), M2C_FIELD(temp_v1, s32 *, 0xC)) - M2C_FIELD(temp_v1, f32 *, 8)) < D_800F1E60) {
            return 0;
        }
    }
    return 1;
}
