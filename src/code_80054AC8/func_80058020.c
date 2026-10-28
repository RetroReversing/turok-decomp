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

/* Returns the remaining ammo as a percentage of this weapon's capacity. Source: tmove.c CTMove__WeaponAmmoPercentage. */
s32 func_80058020(void *pMove, s32 weapon, s32 explosive) {
    switch (weapon) {
    case 0x64:
    case 0x65:
        return 0x64;
    case 0x66:
        if (explosive != 0) {
            return (s32) (M2C_FIELD(pMove, s32 *, 0x14C) * 0x64) / 15;
        }
        return (s32) (M2C_FIELD(pMove, s32 *, 0x15C) * 0x64) / 30;
    case 0x67:
    case 0x68:
        if (M2C_FIELD(pMove, s32 *, 0x1B8) != 0) {
            return (s32) (M2C_FIELD(pMove, s32 *, 0x140) * 0x64) / 200;
        }
        return (s32) (M2C_FIELD(pMove, s32 *, 0x140) * 0x64) / 100;
    case 0x69:
    case 0x6E:
        return (s32) (M2C_FIELD(pMove, s32 *, 0x148) * 0x64) / 100;
    case 0x6A:
    case 0x6B:
        if (M2C_FIELD(pMove, s32 *, 0x1B8) != 0) {
            if (explosive != 0) {
                return (s32) (M2C_FIELD(pMove, s32 *, 0x150) * 0x64) / 20;
            }
            return (s32) (M2C_FIELD(pMove, s32 *, 0x144) * 0x64) / 40;
        }
        if (explosive != 0) {
            return (s32) (M2C_FIELD(pMove, s32 *, 0x150) * 0x64) / 10;
        }
        return (s32) (M2C_FIELD(pMove, s32 *, 0x144) * 0x64) / 20;
    case 0x6C:
        return (s32) (M2C_FIELD(pMove, s32 *, 0x160) * 0x64) / 125;
    case 0x72:
        return (s32) (M2C_FIELD(pMove, s32 *, 0x170) * 0x64) / 3;
    case 0x6D:
        if (M2C_FIELD(pMove, s32 *, 0x1B8) != 0) {
            return (s32) (M2C_FIELD(pMove, s32 *, 0x164) * 0x64) / 30;
        }
        return (s32) (M2C_FIELD(pMove, s32 *, 0x164) * 0x64) / 20;
    case 0x70:
        if (M2C_FIELD(pMove, s32 *, 0x1B8) != 0) {
            return (s32) (M2C_FIELD(pMove, s32 *, 0x168) * 0x64) / 12;
        }
        return (s32) (M2C_FIELD(pMove, s32 *, 0x168) * 0x64) / 6;
    case 0x6F:
        if (M2C_FIELD(pMove, s32 *, 0x1B8) != 0) {
            return (s32) (M2C_FIELD(pMove, s32 *, 0x16C) * 0x64) / 3;
        }
        return (s32) (M2C_FIELD(pMove, s32 *, 0x16C) * 0x64) / 2;
    default:
        return 0;
    }
}
