#include "common.h"

typedef struct CVector3_t {
    float x, y, z;
} CVector3;

typedef struct CEnemyAttributes_t {
    float pad0[13];
    u32 m_dwSpecies;
} CEnemyAttributes;

typedef struct CInstanceHdr_t {
    u8 m_Type;
    u8 m_bActiveFlags;
    u16 m_nObjType;
    CVector3 m_vPos;
    float m_CollisionHeightOffset;
    void *m_pCurrentRegion;
    CEnemyAttributes *m_pEA;
} CInstanceHdr;

typedef struct CAnimInstanceHdr_t {
    CInstanceHdr ih;
} CAnimInstanceHdr;

typedef struct CGameObjectInstance_t {
    CAnimInstanceHdr ah;
    u8 pad[0x1D0 - sizeof(CAnimInstanceHdr)];
    u32 flag_1d0;
} CGameObjectInstance;

typedef struct CHumvee_t {
    u8 pad[0x3C];
    s32 m_LastHealth;
    u8 pad2[0x168 - 0x40];
    s32 m_SoundHandle;
} CHumvee;

extern CGameObjectInstance *D_8010201C;
extern void func_80070DA8(CInstanceHdr *pThis, CInstanceHdr *pOrigin, s32 Event, u32 dwSpecies, CVector3 vPos, f32 Value);

void func_800475B0(CGameObjectInstance *pThis, CHumvee *pHumvee) {
    func_80070DA8(&D_8010201C->ah.ih, &D_8010201C->ah.ih,
               0xE7, D_8010201C->ah.ih.m_pEA->m_dwSpecies,
               D_8010201C->ah.ih.m_vPos, 300.0f);

    if (pHumvee->m_LastHealth) {
        pHumvee->m_SoundHandle = 0;
        pThis->flag_1d0 |= 0x1000;
    }
}
