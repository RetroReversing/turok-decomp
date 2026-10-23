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

M2C_UNK func_8008EED8(void *);                      /* extern */
M2C_UNK func_8008F5D0();                            /* extern */
M2C_UNK func_8008F77C();                            /* extern */
M2C_UNK func_8008F7D8();                            /* extern */
extern f32 D_800B6B00;
extern void *D_8010201C;

void func_8008F090(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    u16 *temp_a1;
    u16 *temp_v1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1D0);
    if (temp_v0 & 0x40000) {
        if ((temp_v0 & 0x180000) == 0x180000) {
            temp_v1 = M2C_FIELD(D_8010201C, u16 **, 0x14);
            if ((temp_v1 != NULL) && (temp_a1 = M2C_FIELD(arg0, u16 **, 0x14), (temp_a1 != NULL))) {
                if (*temp_a1 == *temp_v1) {
                    M2C_FIELD(arg0, f32 *, 0x1A8) = (f32) (M2C_FIELD(arg0, f32 *, 0x1A8) - D_800B6B00);
                    if (M2C_FIELD(arg0, f32 *, 0x1A8) < 0.0f) {
                        M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) & 0xFFFBFFFF);
                    }
                } else {
                    M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (temp_v0 & 0xFFFBFFFF);
                }
            } else {
                M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (temp_v0 & 0xFFFBFFFF);
            }
        } else {
            if (temp_v0 & 0x100000) {
                func_8008F5D0();
                func_8008EED8(arg0);
                return;
            }
            if (temp_v0 & 0x80000) {
                func_8008F77C();
                return;
            }
            func_8008F7D8();
            func_8008EED8(arg0);
            temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1D0);
            if (!(temp_v0_2 & 0x40000)) {
                M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (temp_v0_2 | 0x1C0000);
                M2C_FIELD(arg0, f32 *, 0x1A8) = (f32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), s16 *, 0x42) * 0xF);
            }
        }
    }
}
