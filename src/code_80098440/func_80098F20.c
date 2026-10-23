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

void *func_8002E438(M2C_UNK *);                     /* extern */
extern M2C_UNK D_800FA3C8;

s32 func_80098F20(void *arg0) {
    void *temp_v0;

    temp_v0 = func_8002E438(&D_800FA3C8);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x34) & 0x4000)) {
        return 0;
    }
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC);
}
