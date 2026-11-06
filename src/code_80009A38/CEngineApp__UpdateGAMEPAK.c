#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"
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

M2C_UNK CEngineApp__SetupFadeTo(u8 *, M2C_UNK);             /* extern */
M2C_UNK CEngineApp__PrepareFrame(u8 *, M2C_UNK);             /* extern */
s32 CGamePak__Update(u8 *);                          /* extern */
M2C_UNK ReadControllerAdvanced();                            /* extern */
M2C_UNK osContStartReadData(M2C_UNK *);                   /* extern */
extern u8 D_800B86D0;
extern M2C_UNK D_800F9C20;
extern s32 D_80119908;
extern s32 D_8011990C;

/***************************************************************************** * * Function: CEngineApp__UpdateGAMEPAK() * ****************************************************************************** * * Description: Update GAMEPAK mode stuff * * Inputs: *pThis - Ptr to engine * Outputs: None * *****************************************************************************/ void CEngineApp__UpdateGAMEPAK(u8 *pThis) {
    if ((D_800B86D0 != 0) && (D_80119908 == 0)) {
        D_80119908 = 1;
        osContStartReadData(&D_800F9C20);
    }
    if (D_8011990C != 0) {
        ReadControllerAdvanced();
    }
    CEngineApp__PrepareFrame(pThis, 1);
    if (CGamePak__Update(pThis + 0x1F6C0) != -1) {
        M2C_FIELD(pThis, s32 *, 0x1F8B4) = 0;
        CEngineApp__SetupFadeTo(pThis, 0);
    }
}
