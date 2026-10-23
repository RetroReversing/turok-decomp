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

M2C_UNK func_80002B40();                            /* extern */
M2C_UNK func_800042D4(u8 *);                      /* extern */
M2C_UNK func_8000BB88(s32);                         /* extern */
M2C_UNK func_80031B6C(s32, s32);                    /* extern */
M2C_UNK func_8007DF74(s32, s32);                    /* extern */
M2C_UNK func_80081A10(s32, M2C_UNK);                /* extern */
M2C_UNK func_80087228(u8 *, s32);                 /* extern */

void func_80003D78(u8 *arg0) {
    s32 temp_s1;

    func_80002B40();
    temp_s1 = arg0 + 0x1F810;
    func_80031B6C(arg0 + 0x4B8, temp_s1);
    func_8000BB88(temp_s1);
    func_80081A10(temp_s1, 0x64);
    func_8007DF74(arg0 + 0x17C60, temp_s1);
    if (M2C_FIELD(arg0, s32 *, 0x1F578) != 0) {
        func_80087228(arg0 + 0x1F578, temp_s1);
    }
    func_800042D4(arg0);
}
