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

M2C_UNK CEngineApp__SetupDraw();                            /* extern */
M2C_UNK CEngineApp__DrawFade(u8 *);                      /* extern */
M2C_UNK CCredits__Draw(s32);                         /* extern */
M2C_UNK CScene__Draw(s32, s32);                    /* extern */
M2C_UNK COnScreen__DrawSunLensFlare(s32, s32);                    /* extern */
M2C_UNK COnScreen__Init16BitDraw(s32, M2C_UNK);                /* extern */
M2C_UNK CPause__Draw(u8 *, s32);                 /* extern */

void func_80003D78(u8 *arg0) {
    s32 temp_s1;

    CEngineApp__SetupDraw();
    temp_s1 = arg0 + 0x1F810;
    CScene__Draw(arg0 + 0x4B8, temp_s1);
    CCredits__Draw(temp_s1);
    COnScreen__Init16BitDraw(temp_s1, 0x64);
    COnScreen__DrawSunLensFlare(arg0 + 0x17C60, temp_s1);
    if (M2C_FIELD(arg0, s32 *, 0x1F578) != 0) {
        CPause__Draw(arg0 + 0x1F578, temp_s1);
    }
    CEngineApp__DrawFade(arg0);
}
