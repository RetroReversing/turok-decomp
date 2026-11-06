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

M2C_UNK CCartCache__RequestBlock(M2C_UNK *, u8 *, M2C_UNK, M2C_UNK *, u8 *, s32, s32, M2C_UNK *); /* extern */
s32 CCacheEntry__GetData(s32);                             /* extern */
s32 func_8002DBF8(M2C_UNK *, s32, M2C_UNK, s32 *);  /* extern */
s32 CIndexedSet__GetROMAddress(M2C_UNK *, s32, M2C_UNK);         /* extern */
M2C_UNK CIndexedSet__ConstructFromRawData(M2C_UNK *, s32, M2C_UNK);     /* extern */
extern M2C_UNK D_800F0E04;
extern M2C_UNK D_800F0E10;
extern M2C_UNK D_800FA3C8;
extern M2C_UNK CGameObjectInstance__AnimsHeaderReceived;
extern M2C_UNK CGameObjectInstance__ObjectInfoReceived;

void CGameObjectInstance__ObjectIndexReceived(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0_2;
    u32 temp_v0;
    s32 stack[1];

    CIndexedSet__ConstructFromRawData(&stack[1], CCacheEntry__GetData(M2C_FIELD(arg0, s32 *, 0x108)), 0);
    temp_v0 = func_8002DBF8(&stack[1], M2C_FIELD(arg0, s32 *, 0xFC), 0, &stack[0]);
    M2C_FIELD(arg0, s32 *, 0x100) = temp_v0;
    M2C_FIELD(arg0, u16 *, 0x118) = (u16) stack[0];
    CCartCache__RequestBlock(&D_800FA3C8, arg0, 0, &CGameObjectInstance__ObjectInfoReceived, arg0 + 0x10C, temp_v0, M2C_FIELD(arg0, u16 *, 0x118), &D_800F0E04);
    temp_v0_2 = CIndexedSet__GetROMAddress(&stack[1], M2C_FIELD(arg0, s32 *, 0xFC), 2);
    M2C_FIELD(arg0, s32 *, 0x104) = temp_v0_2;
    CCartCache__RequestBlock(&D_800FA3C8, arg0, 0, &CGameObjectInstance__AnimsHeaderReceived, arg0 + 0x110, temp_v0_2, 4, &D_800F0E10);
}
