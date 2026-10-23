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

M2C_UNK func_80004504(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_8004BA18(u8 *);                      /* extern */
M2C_UNK func_8004C000(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8004D03C(u8 *, u8 *);              /* extern */
M2C_UNK func_8007F404(M2C_UNK *, u8 *);           /* extern */
extern M2C_UNK D_800F9F10;
extern M2C_UNK D_80111B70;
extern s16 D_80112C20;
extern s32 D_8011986C;

void func_8004CC8C(u8 *arg0, u8 *arg1) {
    if ((D_80112C20 == 0xE) || (D_80112C20 == 0xF)) {
        M2C_FIELD(arg1, f32 *, 0xCC) = 1.0f;
    }
    if (M2C_FIELD(arg1, s32 *, 0x3C) != 0) {
        func_8004BA18(arg1 + 0x50);
        M2C_FIELD(arg0, s32 *, 0x208) = 0;
        func_8007F404(&D_80111B70, arg1);
        func_8004C000(arg0, 6);
        func_8004D03C(arg0, arg1);
        func_80004504(&D_800F9F10, 6);
        D_8011986C = 1;
    }
}
