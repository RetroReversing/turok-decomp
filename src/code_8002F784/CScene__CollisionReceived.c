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

M2C_UNK CCartCache__RequestBlock(u8 *, u8 *, M2C_UNK *, M2C_UNK *, u8 *, s32, s32, M2C_UNK *); /* extern */
s32 CCacheEntry__GetData(s32);                             /* extern */
s32 func_8002DBF8(M2C_UNK *, s32, M2C_UNK, s32 *);  /* extern */
M2C_UNK CIndexedSet__ConstructFromRawData(M2C_UNK *, s32, M2C_UNK);     /* extern */
extern M2C_UNK D_800F1B64;
extern M2C_UNK CScene__InstancesReceived;
extern M2C_UNK CScene__DecompressInstances;

void CScene__CollisionReceived(u8 *pThis, M2C_UNK ppceTarget) {
    M2C_UNK sp40[3];
    s32 sp38;

    CIndexedSet__ConstructFromRawData(sp40 + 1, CCacheEntry__GetData(M2C_FIELD(pThis, s32 *, 0x6B10)), 0);
    CCartCache__RequestBlock(pThis, pThis, &CScene__DecompressInstances, &CScene__InstancesReceived, pThis + 0x6AFC, func_8002DBF8(sp40 + 1, M2C_FIELD(pThis, s32 *, 0x6AC8), 2, &sp38), sp38, &D_800F1B64);
}
