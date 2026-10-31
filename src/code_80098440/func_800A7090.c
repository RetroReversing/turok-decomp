#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
/* machine draft (m2c) for ido-5.3 -O1 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul, tried by autopilot */
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

M2C_UNK _bzero(M2C_UNK *, M2C_UNK);                 /* extern */
M2C_UNK func_800AA810();                            /* extern */
extern s32 D_80000300;
extern M2C_UNK D_800EF2D0;
extern M2C_UNK *D_800EF330;
extern void *D_800EF334;
extern s32 D_800EF338;
extern M2C_UNK D_800EF680;
extern M2C_UNK D_800EF6D0;
extern M2C_UNK D_800EF720;



void func_800A7090(void) {
    _bzero(&D_800EF2D0, 0x60);
    D_800EF330 = &D_800EF2D0;
    D_800EF334 = (u8*)&D_800EF2D0 + 0x30;
    M2C_FIELD(&D_800EF2D0, s16 *, 0x32) = 1;
    M2C_FIELD(D_800EF330, s16 *, 2) = 1;
    if (D_80000300 == 0) {
        M2C_FIELD(D_800EF334, M2C_UNK **, 8) = &D_800EF680;
        D_800EF338 = 0x02F5B2D2;
    } else if (D_80000300 == 2) {
        M2C_FIELD(D_800EF334, M2C_UNK **, 8) = &D_800EF6D0;
        D_800EF338 = 0x02E6025C;
    } else {
        M2C_FIELD(D_800EF334, M2C_UNK **, 8) = &D_800EF720;
        D_800EF338 = 0x02E6D354;
    }
    M2C_FIELD(D_800EF334, s16 *, 0) = 0x20;
    M2C_FIELD(D_800EF334, s32 *, 0xC) = (s32) M2C_FIELD(M2C_FIELD(D_800EF334, M2C_UNK **, 8), s32 *, 4);
    if ((u32) (*(volatile u32 *)0xA4400010) >= 0xBU) {
        do {

        } while ((u32) (*(volatile u32 *)0xA4400010) >= 0xBU);
    }
    (*(volatile u32 *)0xA4400000) = 0;
    func_800AA810();
}

