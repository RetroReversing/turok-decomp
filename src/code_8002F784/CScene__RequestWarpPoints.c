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

M2C_UNK CCartCache__RequestBlock(); /* extern */
extern M2C_UNK D_800F1A9C;
extern M2C_UNK CScene__WarpPointsReceived;

void CScene__RequestWarpPoints(u8 *arg0) {
    CCartCache__RequestBlock(arg0, arg0, 0, &CScene__WarpPointsReceived, arg0 + 0x6B24, M2C_FIELD(arg0, s32 *, 0x6AE0), M2C_FIELD(arg0, s32 *, 0x6B48), &D_800F1A9C);
}
