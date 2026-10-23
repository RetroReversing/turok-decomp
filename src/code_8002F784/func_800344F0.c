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

M2C_UNK func_8002D1F8(); /* extern */
extern M2C_UNK D_800F1A9C;
extern M2C_UNK func_80034BA0;

void func_800344F0(u8 *arg0) {
    func_8002D1F8(arg0, arg0, 0, &func_80034BA0, arg0 + 0x6B24, M2C_FIELD(arg0, s32 *, 0x6AE0), M2C_FIELD(arg0, s32 *, 0x6B48), &D_800F1A9C);
}
