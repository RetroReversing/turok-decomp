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

M2C_UNK func_8007F5C4(u8 *, M2C_UNK *, u8 *, s32); /* extern */
extern M2C_UNK D_800BF3A0;

void func_8007F2D4(u8 *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x68)) {
        func_8007F5C4(arg0 + 0x114, &D_800BF3A0, arg0, arg1);
        M2C_FIELD(arg0, s32 *, 0x68) = arg1;
    }
}
