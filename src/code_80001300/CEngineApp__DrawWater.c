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

M2C_UNK CEngineApp__RenderTint();                      /* extern */

void CEngineApp__DrawWater(u8 *pThis) {
    if (M2C_FIELD(pThis, s32 *, 0x1F8BC) != 0) {
        CEngineApp__RenderTint(pThis, pThis + 0x1F8CC);
    }
}
