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

M2C_UNK CFxSystem__AddTimerFx(M2C_UNK *, M2C_UNK *, s32, M2C_UNK, f32); /* extern */
extern s32 D_8010201C;
extern M2C_UNK D_80112E10;
extern M2C_UNK CampArenaInsideExplosion;

void StartCampArenaInsideExplosions(void) {
    CFxSystem__AddTimerFx(&D_80112E10, &CampArenaInsideExplosion, D_8010201C, 0x2710, 0.0f);
}
