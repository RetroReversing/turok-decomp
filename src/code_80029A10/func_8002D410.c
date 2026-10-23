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

extern s32 D_800B6AF0;

void func_8002D410(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    M2C_FIELD(arg1, s32 *, 0x14) = (s32) D_800B6AF0;
    if (arg1 == M2C_FIELD(arg0, void **, 0x20)) {
        M2C_FIELD(arg0, void **, 0x20) = (void *) M2C_FIELD(arg1, void **, 0x2C);
    }
    if (arg1 == M2C_FIELD(arg0, void **, 0x24)) {
        M2C_FIELD(arg0, void **, 0x24) = (void *) M2C_FIELD(arg1, void **, 0x28);
    }
    temp_v0 = M2C_FIELD(arg1, void **, 0x28);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, void **, 0x2C) = (void *) M2C_FIELD(arg1, void **, 0x2C);
    }
    temp_v0_2 = M2C_FIELD(arg1, void **, 0x2C);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, void **, 0x28) = (void *) M2C_FIELD(arg1, void **, 0x28);
    }
    temp_v0_3 = M2C_FIELD(arg0, void **, 0x20);
    if (temp_v0_3 != NULL) {
        M2C_FIELD(temp_v0_3, void **, 0x28) = arg1;
    }
    if (M2C_FIELD(arg0, void **, 0x24) == NULL) {
        M2C_FIELD(arg0, void **, 0x24) = arg1;
    }
    M2C_FIELD(arg1, void **, 0x28) = NULL;
    M2C_FIELD(arg1, void **, 0x2C) = (void *) M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(arg0, void **, 0x20) = arg1;
}
