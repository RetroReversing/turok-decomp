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

M2C_UNK func_80083248(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK D_800BAAB8;
extern M2C_UNK D_800BAAC8;

void func_8003AC1C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 8) = 6;
    M2C_FIELD(arg0, s16 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
    M2C_FIELD(arg0, f32 *, 0x24) = 0.0f;
    func_80083248(&D_800BAAB8, 0x40E00000);
    func_80083248(&D_800BAAC8, 0x40E00000);
}
