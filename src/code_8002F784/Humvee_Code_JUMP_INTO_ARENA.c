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

M2C_UNK CEngineApp__SetupFadeTo(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK CCollisionInfo__SetHumveeRunCollisionDefaults(u8 *);                      /* extern */
M2C_UNK Humvee_SetupMode(u8 *, M2C_UNK);             /* extern */
M2C_UNK Humvee_StopSound(u8 *, u8 *);              /* extern */
M2C_UNK COnScreen__AddBossBar(M2C_UNK *, u8 *);           /* extern */
extern M2C_UNK D_800F9F10;
extern M2C_UNK D_80111B70;
extern s16 D_80112C20;
extern s32 D_8011986C;

void Humvee_Code_JUMP_INTO_ARENA(u8 *arg0, u8 *arg1) {
    if ((D_80112C20 == 0xE) || (D_80112C20 == 0xF)) {
        M2C_FIELD(arg1, f32 *, 0xCC) = 1.0f;
    }
    if (M2C_FIELD(arg1, s32 *, 0x3C) != 0) {
        CCollisionInfo__SetHumveeRunCollisionDefaults(arg1 + 0x50);
        M2C_FIELD(arg0, s32 *, 0x208) = 0;
        COnScreen__AddBossBar(&D_80111B70, arg1);
        Humvee_SetupMode(arg0, 6);
        Humvee_StopSound(arg0, arg1);
        CEngineApp__SetupFadeTo(&D_800F9F10, 6);
        D_8011986C = 1;
    }
}
