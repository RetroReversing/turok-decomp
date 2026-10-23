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
extern M2C_UNK D_800F1AB8;
extern M2C_UNK func_8002D784;
extern M2C_UNK func_80034444;

void func_80034498(u8 *arg0, M2C_UNK arg1) {
    func_8002D1F8(arg0, arg0, &func_8002D784, &func_80034444, arg0 + 0x6AE8, M2C_FIELD(arg0, s32 *, 0x6AD4), M2C_FIELD(arg0, s32 *, 0x6B3C), &D_800F1AB8);
}
