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

M2C_UNK func_8009373C(u8 *, u8 *);              /* extern */

void func_80093984(u8 *arg0) {
    s32 var_s0;
    u8 *var_s1;

    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        var_s0 = 0;
        var_s1 = arg0 + 4;
        if (M2C_FIELD(arg0, s32 *, 0x184) > 0) {
            do {
                func_8009373C(arg0, var_s1);
                var_s0 += 1;
                var_s1 += 0x18;
            } while (var_s0 < M2C_FIELD(arg0, s32 *, 0x184));
        }
    }
}
