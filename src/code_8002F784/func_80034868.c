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

s32 CCacheEntry__GetData(s32);                             /* extern */
M2C_UNK func_8002DA8C(s32 *, s32, M2C_UNK);         /* extern */

u32 func_80034868(void *arg0, s32 arg1) {
    s32 sp2C[6];

    func_8002DA8C(sp2C + 3, CCacheEntry__GetData(M2C_FIELD(arg0, s32 *, 0x6AFC)), 0);
    return (u32) ((arg1 - sp2C[3]) - 8) / 552U;
}
