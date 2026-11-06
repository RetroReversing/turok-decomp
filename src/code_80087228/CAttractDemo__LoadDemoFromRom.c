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

s32 CScene__RequestBinaryBlock(M2C_UNK *, s32, M2C_UNK *, M2C_UNK, M2C_UNK *); /* extern */
extern s32 D_800B6B38;
extern M2C_UNK D_800FA3C8;
extern M2C_UNK D_8012EF48;
extern M2C_UNK SeqReceived;

s32 CAttractDemo__LoadDemoFromRom(s32 arg0) {
    if (D_800B6B38 == 0) {
        return 0;
    }
    return CScene__RequestBinaryBlock(&D_800FA3C8, arg0, &D_8012EF48, 0, &SeqReceived);
}
