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

M2C_UNK func_80011194();                            /* extern */
M2C_UNK func_800111F4();                            /* extern */
s32 func_8009EF90(M2C_UNK *, u8 *);                 /* extern */
s32 func_8009F300(M2C_UNK *, M2C_UNK *, s32);       /* extern */
extern u8 D_800B86D4;
extern s32 D_800F9E40;
extern M2C_UNK D_80119A08;
extern M2C_UNK D_80119A70;
extern s32 D_80119AB0;
extern s32 D_80119AC4;

s32 func_80011224(void) {
    s32 var_v1;
    s32 temp_v0;
    s32 sp1C;

    func_80011194();
    func_8009EF90(&D_80119A70, &D_800B86D4);
    temp_v0 = func_8009EF90(&D_80119A70, &D_800B86D4);
    var_v1 = temp_v0;
    if (temp_v0 == 0) {
        if (D_800B86D4 & (1 << D_800F9E40)) {
            var_v1 = func_8009F300(&D_80119A70, &D_80119A08, D_800F9E40);
        } else {
            D_800B86D4 = 0;
        }
    }
    D_80119AC4 = 0x7B;
    D_80119AB0 = 0;
    sp1C = var_v1;
    func_800111F4();
    return sp1C;
}
