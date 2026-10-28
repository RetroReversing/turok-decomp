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

M2C_UNK *func_8002DC68(s32 *, s32, s32);            /* extern */
M2C_UNK CIndexedSet__ConstructFromRawData(s32 *, M2C_UNK *, M2C_UNK);   /* extern */
extern M2C_UNK D_8014F688;

void func_8003205C(s32 arg0, s32 arg1, s32 arg2) {
    s32 padding[2];
    s32 sp38[2];
    s32 sp30[2];
    s32 sp28[2];

    CIndexedSet__ConstructFromRawData(&sp38[2], &D_8014F688, 0);
    CIndexedSet__ConstructFromRawData(&sp30[2], func_8002DC68(&sp38[2], sp38[2], 1), 0);
    CIndexedSet__ConstructFromRawData(&sp28[2], func_8002DC68(&sp30[2], sp30[2], arg1), 0);
    func_8002DC68(&sp28[2], sp28[2], arg2);
}
