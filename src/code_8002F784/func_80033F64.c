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

M2C_UNK func_80026DA4(u8 *, s32, s32);            /* extern */
M2C_UNK func_8002D1F8(u8 *, u8 *, M2C_UNK *, M2C_UNK *, u8 *, s32, s32, M2C_UNK *); /* extern */
s32 CCacheEntry__GetData(s32);                             /* extern */
s32 func_8002DBF8(M2C_UNK *, s32, M2C_UNK, s32 *);  /* extern */
s32 func_8002DC24(M2C_UNK *, s32, M2C_UNK);         /* extern */
M2C_UNK CIndexedSet__ConstructFromRawData(M2C_UNK *, s32, M2C_UNK);     /* extern */
extern M2C_UNK D_800F1B40;
extern M2C_UNK D_800F1B4C;
extern M2C_UNK func_800336C0;
extern M2C_UNK CScene__DecompressCollision;
extern M2C_UNK func_80033CDC;

void func_80033F64(u8 *arg0, M2C_UNK arg1) {
    M2C_UNK sp50[5];
    s32 sp40;
    s32 sp3C;
    s32 sp38;

    CIndexedSet__ConstructFromRawData(sp50 + 3, CCacheEntry__GetData(M2C_FIELD(arg0, s32 *, 0x6B10)), 0);
    func_8002D1F8(arg0, arg0, &CScene__DecompressCollision, &func_800336C0, arg0 + 0x6AF8, func_8002DBF8(sp50 + 3, M2C_FIELD(arg0, s32 *, 0x6AC8), 1, &sp3C), sp3C, &D_800F1B40);
    M2C_FIELD(arg0, s32 *, 0x6ADC) = func_8002DBF8(sp50 + 3, M2C_FIELD(arg0, s32 *, 0x6AC8), 3, arg0 + 0x6B44);
    M2C_FIELD(arg0, s32 *, 0x6ACC) = func_8002DC24(sp50 + 3, M2C_FIELD(arg0, s32 *, 0x6AC8), 4);
    func_8002D1F8(arg0, arg0, NULL, &func_80033CDC, arg0 + 0x6B2C, func_8002DBF8(sp50 + 3, M2C_FIELD(arg0, s32 *, 0x6AC8), 0, &sp40), sp40, &D_800F1B4C);
    func_80026DA4(arg0 + 0x175BC, func_8002DBF8(sp50 + 3, M2C_FIELD(arg0, s32 *, 0x6AC8), 5, &sp38), sp38);
    M2C_FIELD(arg0, s32 *, 0x175C8) = 1;
}
