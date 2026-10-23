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

M2C_UNK func_80034900(M2C_UNK *, void *, M2C_UNK);  /* extern */
M2C_UNK func_8008FEE4();                            /* extern */
extern M2C_UNK D_800FA3C8;

void func_8008DD60(void *arg0) {
    func_8008FEE4();
    M2C_FIELD(arg0, s16 *, 0x1DC) = 0;
    M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) | 0x1000);
    func_80034900(&D_800FA3C8, arg0, 1);
}
