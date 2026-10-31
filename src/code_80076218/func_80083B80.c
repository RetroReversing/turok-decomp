#include "common.h"

/* machine draft (m2c) for ido-5.3 -O2 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul, tried by autopilot */
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

M2C_UNK osRecvMesg(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800A1760(s32, s32);                    /* extern */
M2C_UNK osPiStartDma(M2C_UNK *, M2C_UNK, M2C_UNK, s32, s32, s32, M2C_UNK *); /* extern */
extern M2C_UNK D_800F9BC8;

void func_80083B80(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK sp30[6];
    M2C_UNK sp2C[2];

    func_800A1760(arg1, arg2);
    osPiStartDma(sp30, 0, 0, arg0, arg1, arg2, &D_800F9BC8);
    osRecvMesg(&D_800F9BC8, sp2C + 1, 1);
}
