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

M2C_UNK CEngineApp__AdvanceFrameData(u8 *);                      /* extern */
M2C_UNK CSunFrameData__Construct(s32);                         /* extern */
extern M2C_UNK D_80200000;
extern M2C_UNK D_80225800;
extern M2C_UNK D_8024B000;

void CEngineApp__InitGraphics(u8 *pThis) {
    s32 var_s1;
    s32 var_s2;
    u8 *var_s0;

    var_s0 = pThis;
    var_s1 = 0;
    var_s2 = pThis + 0x60;
    do {
        M2C_FIELD(var_s0, s16 *, 0x150) = 2;
        CSunFrameData__Construct(var_s2);
        var_s1 += 0x190;
        var_s0 += 0x190;
        var_s2 += 0x190;
    } while (var_s1 != 0x4B0);
    M2C_FIELD(pThis, M2C_UNK **, 0x170) = &D_80200000;
    M2C_FIELD(pThis, M2C_UNK **, 0x300) = &D_80225800;
    M2C_FIELD(pThis, M2C_UNK **, 0x490) = &D_8024B000;
    CEngineApp__AdvanceFrameData(pThis);
}
