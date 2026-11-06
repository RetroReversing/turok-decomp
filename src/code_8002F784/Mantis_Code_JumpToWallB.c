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

M2C_UNK Mantis_SetupMode(s32, s32);                    /* extern */
s32 Mantis_NearWall(s32, void *);                     /* extern */
M2C_UNK AI_NudgeRotY();                         /* extern */

void Mantis_Code_JumpToWallB(s32 arg0, void *arg1) {
    if (M2C_FIELD(arg1, s16 *, 0x108) == 1) {
        AI_NudgeRotY(arg0, M2C_FIELD(arg1, s32 *, 0x110));
    }
    if (Mantis_NearWall(arg0, arg1) != 0) {
        Mantis_SetupMode(arg0, M2C_FIELD(arg1, s32 *, 0x20) + 1);
    }
}
