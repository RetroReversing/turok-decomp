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

M2C_UNK func_8007F994(M2C_UNK);                     /* extern */
M2C_UNK func_8007F9F8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, u32); /* extern */
M2C_UNK func_8007FD68(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, u32); /* extern */
M2C_UNK func_800806B4(M2C_UNK);                     /* extern */
M2C_UNK func_800814AC(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_800858A4(M2C_UNK);                     /* extern */
M2C_UNK func_800859F8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32); /* extern */
extern f32 D_800B6B00;
extern s32 D_800B818C;
extern f64 D_800F0C48;
extern f64 D_800F0C50;
extern s32 D_801197B0;

void func_8000E52C(void *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 4);
    switch (temp_v0) {                              /* irregular */
    case 1:
        M2C_FIELD(arg0, f32 *, 0) = (f32) ((f64) M2C_FIELD(arg0, f32 *, 0) + (D_800F0C48 * (f64) D_800B6B00));
        if ((f64) M2C_FIELD(arg0, f32 *, 0) >= 1.0) {
            M2C_FIELD(arg0, s16 *, 4) = 2;
            M2C_FIELD(arg0, f32 *, 0) = 1.0f;
        }
        break;
    case 3:
        M2C_FIELD(arg0, f32 *, 0) = (f32) ((f64) M2C_FIELD(arg0, f32 *, 0) - (D_800F0C50 * (f64) D_800B6B00));
        if ((f64) M2C_FIELD(arg0, f32 *, 0) <= 0.0) {
            M2C_FIELD(arg0, s16 *, 4) = 0;
            M2C_FIELD(arg0, f32 *, 0) = 0.0f;
            if (M2C_FIELD(arg0, s32 *, 8) == 0) {
                D_801197B0 = 0;
            }
        }
        break;
    }
    func_8007F994(arg1);
    func_8007F9F8(arg1, 0, 0, 0x140, 0xF0, 0, 0, 0, (u32) (M2C_FIELD(arg0, f32 *, 0) * 120.0f));
    func_8007FD68(arg1, 0x3C, 0x46, 0x104, 0x7A, 2, 1, 0x1E, 0x1E, 0x1E, (u32) (M2C_FIELD(arg0, f32 *, 0) * 220.0f));
    func_8007FD68(arg1, 0x3C, 0x7B, 0x104, 0xAA, 2, 1, 0x1E, 0x1E, 0x1E, (u32) (M2C_FIELD(arg0, f32 *, 0) * 220.0f));
    func_800858A4(arg1);
    func_800859F8(arg1, 0x42B80000, 0x430A0000, 0x43080000, 18.0f, M2C_FIELD(arg0, f32 *, 0));
    func_800806B4(arg1);
    func_800814AC(arg1, M2C_FIELD(arg0, s32 *, 0x10), 0xA0, 0x4E, (s32) (M2C_FIELD(arg0, f32 *, 0) * 255.0f), 1, 1);
    func_800814AC(arg1, M2C_FIELD(arg0, s32 *, 0x14), 0xA0, 0x5E, (s32) (M2C_FIELD(arg0, f32 *, 0) * 255.0f), 1, 1);
    func_800814AC(arg1, D_800B818C, 0xA0, 0x8A, (s32) (M2C_FIELD(arg0, f32 *, 0) * 255.0f), 1, 1);
}
