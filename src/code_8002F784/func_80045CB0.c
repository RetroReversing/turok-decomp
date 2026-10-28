#include "common.h"

typedef struct MantisStageInfo_t
{
    s32 HealthLimit;
    f32 AnimSpeed;
    f32 FlySpeed;
    f32 MaxWalkTime;
    s32 FlySpitSkips;
    s32 HitsBeforeExplosion;
} CMantisStageInfo;

typedef struct CMantis_t
{
    u8 pad0[0x20];
    s32 m_Mode;
    u8 pad1[0x188 - 0x24];
    CMantisStageInfo *m_pStageInfo;
    u8 pad2[0x2CC - 0x18C];
    s32 m_ExplosionHits;
} CMantis;

typedef struct CGameObjectInstance_t
{
    u8 pad0[0x1D0];
    u32 m_dwFlags;
    u8 pad1[0x208 - 0x1D4];
    s32 m_Invincible;
} CGameObjectInstance;

extern s32 func_8004463C(CGameObjectInstance *pThis, s32 nNewMode);

void func_80045CB0(CGameObjectInstance *pThis, CMantis *pMantis)
{
    if (pThis->m_Invincible)
        return;

    if (pThis->m_dwFlags & 0x800)
    {
        pThis->m_dwFlags &= ~0x800;

        if (++pMantis->m_ExplosionHits < pMantis->m_pStageInfo->HitsBeforeExplosion)
            return;

        pMantis->m_ExplosionHits = 0;

        switch (pMantis->m_Mode)
        {
            case 2:
                func_8004463C(pThis, 0x2F);
                break;
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
                break;
            case 18:
                func_8004463C(pThis, 0x33);
                break;
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
                break;
            case 31:
                func_8004463C(pThis, 0x34);
                break;
            case 32:
            case 33:
            case 34:
            case 35:
            case 36:
            case 37:
            case 38:
            case 39:
            case 40:
            case 41:
                break;
            case 42:
                func_8004463C(pThis, 0x35);
                break;
            case 46:
                break;
        }
    }
}
