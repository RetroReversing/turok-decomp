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

M2C_UNK CCollisionInfo__ClearCollision(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetPlayerDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetPlayerDeadDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetPlayerUnderwaterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetPlayerAntiGravDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetPlayerOnWaterSurfaceDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetPlayerFallIntoWaterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetPlayerClimbingSideStepCharacterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetCharacterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetCharacterWalkInWaterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetDeadCharacterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetFlyingCharacterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetClimbingCharacterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetClimbingAndSwimmingCharacterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetUnderwaterClimbingCharacterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetUnderwaterCharacterDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetUnderwaterCharacterDeadDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetUnderwaterCharacterFloatDeadDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetParticleDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetPickupDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetNoCollisionAtAllDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetMovementTestDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetSwimmerMovementTestDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetClimberMovementTestDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetClimberAndSwimmerMovementTestDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetRayCastDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetNearRegionTestDefaults(M2C_UNK *);                   /* extern */
M2C_UNK CCollisionInfo__SetCliffTestDefaults(M2C_UNK *);                   /* extern */
extern M2C_UNK D_80135C20;
extern M2C_UNK D_80135CA0;
extern M2C_UNK D_80135D20;
extern M2C_UNK D_80135DA0;
extern M2C_UNK D_80135E20;
extern M2C_UNK D_80135EA0;
extern M2C_UNK D_80135F20;
extern M2C_UNK D_80135FA0;
extern M2C_UNK D_80136020;
extern M2C_UNK D_801360A0;
extern M2C_UNK D_80136120;
extern M2C_UNK D_801361A0;
extern M2C_UNK D_80136220;
extern M2C_UNK D_801362A0;
extern M2C_UNK D_80136320;
extern M2C_UNK D_801363A0;
extern M2C_UNK D_80136420;
extern M2C_UNK D_801364A0;
extern M2C_UNK D_80136520;
extern M2C_UNK D_801365A0;
extern M2C_UNK D_80136620;
extern M2C_UNK D_801366A0;
extern M2C_UNK D_80136720;
extern M2C_UNK D_801367A0;
extern M2C_UNK D_80136820;
extern M2C_UNK D_801368A0;
extern M2C_UNK D_80136920;

void CCollisionInfo__Reset(void) {
    /* Initialize the 26 fixed-size state records, then clear each record's four working fields. */
    CCollisionInfo__SetPlayerDefaults(&D_80135C20);
    CCollisionInfo__ClearCollision(&D_80135C20);
    CCollisionInfo__SetPlayerDeadDefaults(&D_80135CA0);
    CCollisionInfo__ClearCollision(&D_80135CA0);
    CCollisionInfo__SetPlayerUnderwaterDefaults(&D_80135D20);
    CCollisionInfo__ClearCollision(&D_80135D20);
    CCollisionInfo__SetPlayerAntiGravDefaults(&D_80135DA0);
    CCollisionInfo__ClearCollision(&D_80135DA0);
    CCollisionInfo__SetPlayerOnWaterSurfaceDefaults(&D_80135E20);
    CCollisionInfo__ClearCollision(&D_80135E20);
    CCollisionInfo__SetPlayerFallIntoWaterDefaults(&D_80135EA0);
    CCollisionInfo__ClearCollision(&D_80135EA0);
    CCollisionInfo__SetPlayerClimbingSideStepCharacterDefaults(&D_80135F20);
    CCollisionInfo__ClearCollision(&D_80135F20);
    CCollisionInfo__SetCharacterDefaults(&D_80135FA0);
    CCollisionInfo__ClearCollision(&D_80135FA0);
    CCollisionInfo__SetCharacterWalkInWaterDefaults(&D_80136020);
    CCollisionInfo__ClearCollision(&D_80136020);
    CCollisionInfo__SetDeadCharacterDefaults(&D_801360A0);
    CCollisionInfo__ClearCollision(&D_801360A0);
    CCollisionInfo__SetFlyingCharacterDefaults(&D_80136120);
    CCollisionInfo__ClearCollision(&D_80136120);
    CCollisionInfo__SetClimbingCharacterDefaults(&D_801361A0);
    CCollisionInfo__ClearCollision(&D_801361A0);
    CCollisionInfo__SetClimbingAndSwimmingCharacterDefaults(&D_80136220);
    CCollisionInfo__ClearCollision(&D_80136220);
    CCollisionInfo__SetUnderwaterClimbingCharacterDefaults(&D_801362A0);
    CCollisionInfo__ClearCollision(&D_801362A0);
    CCollisionInfo__SetUnderwaterCharacterDefaults(&D_80136320);
    CCollisionInfo__ClearCollision(&D_80136320);
    CCollisionInfo__SetUnderwaterCharacterDeadDefaults(&D_801363A0);
    CCollisionInfo__ClearCollision(&D_801363A0);
    CCollisionInfo__SetUnderwaterCharacterFloatDeadDefaults(&D_80136420);
    CCollisionInfo__ClearCollision(&D_80136420);
    CCollisionInfo__SetMovementTestDefaults(&D_80136620);
    CCollisionInfo__ClearCollision(&D_80136620);
    CCollisionInfo__SetSwimmerMovementTestDefaults(&D_801366A0);
    CCollisionInfo__ClearCollision(&D_801366A0);
    CCollisionInfo__SetClimberMovementTestDefaults(&D_80136720);
    CCollisionInfo__ClearCollision(&D_80136720);
    CCollisionInfo__SetClimberAndSwimmerMovementTestDefaults(&D_801367A0);
    CCollisionInfo__ClearCollision(&D_801367A0);
    CCollisionInfo__SetParticleDefaults(&D_801364A0);
    CCollisionInfo__ClearCollision(&D_801364A0);
    CCollisionInfo__SetPickupDefaults(&D_80136520);
    CCollisionInfo__ClearCollision(&D_80136520);
    CCollisionInfo__SetNoCollisionAtAllDefaults(&D_801365A0);
    CCollisionInfo__ClearCollision(&D_801365A0);
    CCollisionInfo__SetRayCastDefaults(&D_80136820);
    CCollisionInfo__ClearCollision(&D_80136820);
    CCollisionInfo__SetNearRegionTestDefaults(&D_801368A0);
    CCollisionInfo__ClearCollision(&D_801368A0);
    CCollisionInfo__SetCliffTestDefaults(&D_80136920);
    CCollisionInfo__ClearCollision(&D_80136920);
}
