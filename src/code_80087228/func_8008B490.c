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

M2C_UNK alCSeqNew(s32, M2C_UNK *);              /* extern */
M2C_UNK func_800A4B80(s32, s32);                    /* extern */
M2C_UNK func_800A4BC0(s32, s32);                    /* extern */
M2C_UNK func_800A4C00(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_800A4C60(s32, s16);                    /* extern */
extern s16 D_800ECF50;
extern void *D_8012AF0C;
extern M2C_UNK D_8012AF28;
extern s32 D_8012EF28;
extern s32 D_8012EF2C;

void func_8008B490(void) {
    s32 var_s0;

    alCSeqNew(D_8012EF28, &D_8012AF28);
    func_800A4B80(D_8012EF2C, D_8012EF28);
    func_800A4BC0(D_8012EF2C, M2C_FIELD(D_8012AF0C, s32 *, 4));
    var_s0 = 0;
    do {
        func_800A4C00(D_8012EF2C, var_s0 & 0xFF, 0);
        var_s0 += 1;
    } while (var_s0 != 0x10);
    func_800A4C60(D_8012EF2C, D_800ECF50);
}
