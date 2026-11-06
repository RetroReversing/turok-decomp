#include "common.h"

typedef s32 M2C_UNK;
M2C_UNK _Printf(M2C_UNK *, M2C_UNK, s32, M2C_UNK *);
extern M2C_UNK func_800A4060;
void osSyncPrintf(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    volatile s32 pad[2];
    _Printf(&func_800A4060, 0, arg0, &arg1);
}
