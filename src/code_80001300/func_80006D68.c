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

M2C_UNK func_80006E0C(u8 *);                      /* extern */
M2C_UNK func_800984B0(s32);                         /* extern */
extern M2C_UNK D_80200000;
extern M2C_UNK D_80225800;
extern M2C_UNK D_8024B000;

void func_80006D68(u8 *arg0) {
    s32 var_s1;
    s32 var_s2;
    u8 *var_s0;

    var_s0 = arg0;
    var_s1 = 0;
    var_s2 = arg0 + 0x60;
    do {
        M2C_FIELD(var_s0, s16 *, 0x150) = 2;
        func_800984B0(var_s2);
        var_s1 += 0x190;
        var_s0 += 0x190;
        var_s2 += 0x190;
    } while (var_s1 != 0x4B0);
    M2C_FIELD(arg0, M2C_UNK **, 0x170) = &D_80200000;
    M2C_FIELD(arg0, M2C_UNK **, 0x300) = &D_80225800;
    M2C_FIELD(arg0, M2C_UNK **, 0x490) = &D_8024B000;
    func_80006E0C(arg0);
}
