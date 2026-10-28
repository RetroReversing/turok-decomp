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

M2C_UNK CTControl__Action();           /* extern */

void func_80051E44(void *arg0) {
    CTControl__Action(arg0, M2C_FIELD(arg0, u16 *, 0x9E), M2C_FIELD(arg0, u16 *, 0x136), M2C_FIELD(arg0, u8 *, 0x21B), (s32) M2C_FIELD(arg0, u16 *, 0x1CE));
}
