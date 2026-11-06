#include "common.h"

/* machine draft (m2c) for ido-5.3 -O2 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul, tried by autopilot */
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
M2C_UNK CEngineApp__DrawFade(s32);                         /* extern */
M2C_UNK func_8000B28C(s32);                         /* extern */
M2C_UNK CScene__Draw(s32, s32);                    /* extern */

void CEngineApp__DrawLEGALSCREEN(s32 arg0) {
    s32 sp1C;
    s32 temp_a1;

    CEngineApp__SetupDraw();
    temp_a1 = arg0 + 0x1F810;
    sp1C = temp_a1;
    CScene__Draw(arg0 + 0x4B8, temp_a1);
    func_8000B28C(sp1C);
    CEngineApp__DrawFade(arg0);
}
