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

M2C_UNK func_8002D1F8(M2C_UNK *, u8 *, M2C_UNK, M2C_UNK *, u8 *, s32, s32, M2C_UNK *); /* extern */
s32 func_8002D690(s32);                             /* extern */
s32 func_8002DBF8(M2C_UNK *, s32, M2C_UNK, s32 *);  /* extern */
s32 func_8002DC24(M2C_UNK *, s32, M2C_UNK);         /* extern */
M2C_UNK func_8002DD28(M2C_UNK *, s32, M2C_UNK);     /* extern */
extern M2C_UNK D_800F0E04;
extern M2C_UNK D_800F0E10;
extern M2C_UNK D_800FA3C8;
extern M2C_UNK func_80018830;
extern M2C_UNK func_80019120;

void func_8001914C(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0_2;
    u32 temp_v0;
    s32 stack[1];

    func_8002DD28(&stack[1], func_8002D690(M2C_FIELD(arg0, s32 *, 0x108)), 0);
    temp_v0 = func_8002DBF8(&stack[1], M2C_FIELD(arg0, s32 *, 0xFC), 0, &stack[0]);
    M2C_FIELD(arg0, s32 *, 0x100) = temp_v0;
    M2C_FIELD(arg0, u16 *, 0x118) = (u16) stack[0];
    func_8002D1F8(&D_800FA3C8, arg0, 0, &func_80019120, arg0 + 0x10C, temp_v0, M2C_FIELD(arg0, u16 *, 0x118), &D_800F0E04);
    temp_v0_2 = func_8002DC24(&stack[1], M2C_FIELD(arg0, s32 *, 0xFC), 2);
    M2C_FIELD(arg0, s32 *, 0x104) = temp_v0_2;
    func_8002D1F8(&D_800FA3C8, arg0, 0, &func_80018830, arg0 + 0x110, temp_v0_2, 4, &D_800F0E10);
}
