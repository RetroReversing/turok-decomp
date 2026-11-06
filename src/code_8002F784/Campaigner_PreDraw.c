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

M2C_UNK CSpecialFx__Update(s32);                         /* extern */
M2C_UNK CSpecialFx__SetDrawFxVars(s32);                         /* extern */
M2C_UNK PrepareDrawFxVars();                            /* extern */

void Campaigner_PreDraw(s32 arg0, s32 arg1, M2C_UNK arg2) {
    u32 temp_a0;
    s32 sp1C;

    temp_a0 = arg1 + 0x188;
    sp1C = temp_a0;
    CSpecialFx__Update(temp_a0);
    CSpecialFx__SetDrawFxVars(temp_a0);
    PrepareDrawFxVars();
}
