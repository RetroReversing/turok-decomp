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

u16 CScene__GetObjectTypeFlag(M2C_UNK *, u16, void *);          /* extern */
extern M2C_UNK D_800FA3C8;

u16 CInstanceHdr__TypeFlag(void *pThis) {
    if (M2C_FIELD(pThis, u8 *, 0) == 1) {
        return M2C_FIELD(pThis, u16 *, 0x11A);
    }
    return CScene__GetObjectTypeFlag(&D_800FA3C8, M2C_FIELD(pThis, u16 *, 2), pThis);
}
