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

M2C_UNK func_80013B2C(u8 *, u8 *);              /* extern */
extern f32 D_800F6B98;
extern f32 D_800F6B9C;
extern f32 D_800F6BA0;

void func_800985E4(u8 *arg0) {
    u8 *temp_a0;

    M2C_FIELD(arg0, f32 *, 0x14) = (f32) D_800F6B98;
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) D_800F6B9C;
    temp_a0 = arg0 + 0x14;
    M2C_FIELD(temp_a0, f32 *, 8) = (f32) D_800F6BA0;
    func_80013B2C(temp_a0, arg0);
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
}
