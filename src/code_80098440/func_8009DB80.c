#include "common.h"

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

s32 func_800A5750();                                /* extern */
M2C_UNK func_800A5770(s32);                         /* extern */
extern void *D_800EF334;

void func_8009DB80(s32 arg0) {
    register s32 temp_s0;

    temp_s0 = func_800A5750();
    if (arg0 & 1) {
        M2C_FIELD(D_800EF334, s32 *, 0xC) = (s32) (M2C_FIELD(D_800EF334, s32 *, 0xC) | 8);
    }
    if (arg0 & 2) {
        M2C_FIELD(D_800EF334, s32 *, 0xC) = (s32) (M2C_FIELD(D_800EF334, s32 *, 0xC) & ~8);
    }
    if (arg0 & 4) {
        M2C_FIELD(D_800EF334, s32 *, 0xC) = (s32) (M2C_FIELD(D_800EF334, s32 *, 0xC) | 4);
    }
    if (arg0 & 8) {
        M2C_FIELD(D_800EF334, s32 *, 0xC) = (s32) (M2C_FIELD(D_800EF334, s32 *, 0xC) & ~4);
    }
    if (arg0 & 0x10) {
        M2C_FIELD(D_800EF334, s32 *, 0xC) = (s32) (M2C_FIELD(D_800EF334, s32 *, 0xC) | 0x10);
    }
    if (arg0 & 0x20) {
        M2C_FIELD(D_800EF334, s32 *, 0xC) = (s32) (M2C_FIELD(D_800EF334, s32 *, 0xC) & ~0x10);
    }
    if (arg0 & 0x40) {
        M2C_FIELD(D_800EF334, s32 *, 0xC) = (s32) (M2C_FIELD(D_800EF334, s32 *, 0xC) | 0x10000);
        M2C_FIELD(D_800EF334, s32 *, 0xC) = (s32) (M2C_FIELD(D_800EF334, s32 *, 0xC) & ~0x300);
    }
    if (arg0 & 0x80) {
        M2C_FIELD(D_800EF334, s32 *, 0xC) = (s32) (M2C_FIELD(D_800EF334, s32 *, 0xC) & 0xFFFEFFFF);
        M2C_FIELD(D_800EF334, s32 *, 0xC) = (M2C_FIELD(M2C_FIELD(D_800EF334, void **, 8), s32 *, 4) & 0x300) | M2C_FIELD(D_800EF334, s32 *, 0xC);
    }
    M2C_FIELD(D_800EF334, u16 *, 0) = (u16) (M2C_FIELD(D_800EF334, u16 *, 0) | 8);
    func_800A5770(temp_s0);
}
