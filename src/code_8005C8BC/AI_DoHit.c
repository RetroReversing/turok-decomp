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

s32 CInstanceHdr__IsDevice();                                /* extern */
M2C_UNK AI_Increase_Agitation(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK AI_Decrease_Health(void *, s32, M2C_UNK, M2C_UNK); /* extern */

void AI_DoHit(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1D0);
    if (!(temp_v0 & 0x01000000) && !(temp_v0 & 0x04000000) && !(M2C_FIELD(arg0, s32 *, 0x1D4) & 1) && (CInstanceHdr__IsDevice() == 0)) {
        if (M2C_FIELD(arg0, s32 *, 0x208) == 0) {
            M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) | 0x400);
        }
        AI_Increase_Agitation(arg0, 0x12C, 0x12C);
        AI_Decrease_Health(arg0, arg1, 1, 1);
    }
}
