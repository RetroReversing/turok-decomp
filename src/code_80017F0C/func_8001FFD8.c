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

s32 CInstanceHdr__TypeFlag();                                /* extern */
M2C_UNK CGameSimpleInstance__AdvanceWarp(void *);                      /* extern */
M2C_UNK CGameSimpleInstance__AdvancePickup(void *);                      /* extern */
s32 AI_IsMorph(s32);                             /* extern */
s32 AI_IsWarp(s32);                             /* extern */
s32 AI_IsPickup(s32);                             /* extern */
extern f32 D_800B6B00;
extern f64 D_800F1618;
extern s32 D_80119798;

void func_8001FFD8(void *arg0) {
    s32 sp1C;
    s32 temp_v0;

    if (D_80119798 == 0) {
        temp_v0 = CInstanceHdr__TypeFlag();
        sp1C = temp_v0;
        if (AI_IsPickup(temp_v0) != 0) {
            CGameSimpleInstance__AdvancePickup(arg0);
            return;
        }
        if (AI_IsWarp(sp1C) != 0) {
            CGameSimpleInstance__AdvanceWarp(arg0);
            return;
        }
        if (AI_IsMorph(sp1C) != 0) {
            M2C_FIELD(arg0, f32 *, 0x17C) = (f32) ((f64) D_800B6B00 * D_800F1618);
        }
    }
}
