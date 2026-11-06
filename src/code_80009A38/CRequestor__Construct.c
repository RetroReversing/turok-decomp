#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

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

extern M2C_UNK D_800B8184;

void CRequestor__Construct(void *pThis, s32 String1, s32 String2) {
    M2C_FIELD(pThis, s32 *, 0xC) = 0;
    M2C_FIELD(pThis, s32 *, 0x14) = String1;
    M2C_FIELD(pThis, s32 *, 0x18) = String2;
    M2C_FIELD(pThis, s16 *, 4) = 1;
    M2C_FIELD(pThis, s32 *, 8) = 1;
    M2C_FIELD(pThis, M2C_UNK **, 0x10) = &D_800B8184;
    M2C_FIELD(pThis, f32 *, 0) = 0.0f;
}
