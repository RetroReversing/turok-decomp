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

s32 func_80011224();                                /* extern */
M2C_UNK func_800113A8(M2C_UNK);                     /* extern */
extern u8 D_800B86D4;
extern s32 D_80119814;
extern s32 D_80119940;
extern f32 D_80119944;
extern M2C_UNK D_80119948;
extern s32 D_80119AB8;
extern s32 D_80119AC4;

void func_8000B070(void) {
    s32 temp_v0;

    M2C_FIELD(&D_80119948, s32 *, 0) = 0;
    M2C_FIELD(&D_80119948, f32 *, 4) = 45.0f;
    D_80119814 = 0x7D04;
    D_80119940 = 0;
    func_80011224();
    temp_v0 = func_80011224();
    if ((temp_v0 == 4) || (temp_v0 == 0xB) || (temp_v0 == 0xA)) {
        D_80119940 = 3;
    } else {
        func_800113A8(0);
        if ((D_80119AB8 == 0) && (D_80119AC4 < 0x10)) {
            D_80119940 = 1;
        } else if (D_800B86D4 == 0) {
            D_80119940 = 2;
        }
    }
    D_80119944 = 255.0f;
}
