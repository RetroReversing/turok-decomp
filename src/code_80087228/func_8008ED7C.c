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

M2C_UNK func_8002169C(s32);                         /* extern */
M2C_UNK func_800218A4(s32);                         /* extern */
void *func_8002E438(M2C_UNK *, s32, void *);        /* extern */
extern M2C_UNK D_800FA3C8;

void func_8008ED7C(void *arg0) {
    s32 temp_v0;
    void *temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1D0);
    if ((temp_v0 & 0x40000) && !(temp_v0 & 0x100000)) {
        M2C_FIELD(arg0, f32 *, 8) = (f32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), f32 *, 0x24);
        temp_v0_2 = func_8002E438(&D_800FA3C8, M2C_FIELD(arg0, s32 *, 0x14), arg0);
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, f32 *, 0x20) = (f32) M2C_FIELD(arg0, f32 *, 8);
        }
        M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) | 0x100000);
        func_8002169C(M2C_FIELD(arg0, s32 *, 0x14));
        func_800218A4(M2C_FIELD(arg0, s32 *, 0x14));
    }
}
