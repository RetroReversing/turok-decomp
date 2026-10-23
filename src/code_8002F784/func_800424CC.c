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

M2C_UNK func_80042868();                            /* extern */
M2C_UNK func_800437F0(u8 *);                      /* extern */
extern s32 D_800B6AF4;
extern s32 D_80119798;

void func_800424CC(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3200) = 0x190;
    M2C_FIELD(arg0, u8 **, 0x3204) = (u8 *) ((s32)arg0 + (D_800B6AF4 * 0x1900));
    if (!D_80119798) {
        func_80042868();
        func_800437F0(arg0);
    }
}
