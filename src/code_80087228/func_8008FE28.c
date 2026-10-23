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

M2C_UNK func_8005FCF4();            /* extern */

void func_8008FE28(void *arg0) {
    f32 temp_fv0;
    void *temp_v0;

    if (!(M2C_FIELD(arg0, s32 *, 0x1D0) & 0x80000)) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x18);
        temp_fv0 = (f32) (M2C_FIELD(temp_v0, s8 *, 0x4E) != 0);
        M2C_FIELD(arg0, f32 *, 0x1A8) = temp_fv0;
        if (temp_fv0 != 0.0f) {
            M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) | 0x80000);
            M2C_FIELD(arg0, f32 *, 0x1A8) = (f32) (M2C_FIELD(temp_v0, s8 *, 0x4E) * 0xF);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) | 0x100000);
        M2C_FIELD(arg0, f32 *, 0x1A8) = (f32) (M2C_FIELD(temp_v0, u8 *, 0x4A) * 0xF);
        func_8005FCF4(arg0, 0xA40, 1);
    }
}
