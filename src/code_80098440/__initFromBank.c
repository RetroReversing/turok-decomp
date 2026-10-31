#include "common.h"

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

M2C_UNK __setInstChanState(u8 *, s32, s32);            /* extern */
M2C_UNK __resetPerfChanState(u8 *, s32);                 /* extern */

void __initFromBank(u8 *arg0, u8 *arg1) {
    s32 temp_s1;
    s32 var_s0;
    u8 *var_v0;

    var_v0 = arg1;
    do {
        temp_s1 = M2C_FIELD(var_v0, s32 *, 0xC);
        var_v0 += 4;
    } while (temp_s1 == 0);
    var_s0 = 0;
    if ((s32) M2C_FIELD(arg0, u8 *, 0x34) > 0) {
        do {
            __resetPerfChanState(arg0, var_s0);
            __setInstChanState(arg0, temp_s1, var_s0);
            var_s0 += 1;
        } while (var_s0 < (s32) M2C_FIELD(arg0, u8 *, 0x34));
    }
    if (M2C_FIELD(arg1, s32 *, 8) != 0) {
        __resetPerfChanState(arg0, var_s0);
        __setInstChanState(arg0, M2C_FIELD(arg1, s32 *, 8), 9);
    }
}
