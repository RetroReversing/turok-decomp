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

s32 CCamera__InCinemaMode(M2C_UNK *);                       /* extern */
M2C_UNK COverlay__RunScript(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_800BF36C;
extern M2C_UNK D_80112C18;

void COnScreen__SetLives(u8 *arg0, s32 arg1) {
    if ((CCamera__InCinemaMode(&D_80112C18) == 0) && (arg1 != M2C_FIELD(arg0, s32 *, 0x64))) {
        COverlay__RunScript(arg0 + 0xE0, &D_800BF36C);
        M2C_FIELD(arg0, s32 *, 0x64) = arg1;
    }
}
