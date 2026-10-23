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

M2C_UNK func_800AB150(u8 *, s32, s32);            /* extern */
M2C_UNK func_800AB1A4(u8 *, s32);                 /* extern */

void func_800AB224(u8 *arg0, u8 *arg1) {
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
            func_800AB1A4(arg0, var_s0);
            func_800AB150(arg0, temp_s1, var_s0);
            var_s0 += 1;
        } while (var_s0 < (s32) M2C_FIELD(arg0, u8 *, 0x34));
    }
    if (M2C_FIELD(arg1, s32 *, 8) != 0) {
        func_800AB1A4(arg0, var_s0);
        func_800AB150(arg0, M2C_FIELD(arg1, s32 *, 8), 9);
    }
}
