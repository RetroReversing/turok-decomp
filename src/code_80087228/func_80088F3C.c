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

M2C_UNK func_80004504(M2C_UNK *, M2C_UNK);          /* extern */
f32 func_80051EA4(s32);                             /* extern */
extern s32 D_800F9E44;
extern M2C_UNK D_800F9F10;
extern s32 D_80119814;

s32 func_80088F3C(s32 arg0) {
    if (func_80051EA4(D_800F9E44) != 0.0f) {
        D_80119814 = 0x7DC8;
        func_80004504(&D_800F9F10, 6);
    }
    return -1;
}
