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

M2C_UNK StartSerialQ();                            /* extern */
M2C_UNK EndSerialQ();                            /* extern */
s32 osPfsFileState(M2C_UNK *, s32, M2C_UNK *);       /* extern */
extern M2C_UNK D_80119A08;
extern M2C_UNK D_80119A90;

/***************************************************************************** * * Function: GetFileState() * ****************************************************************************** * * Description: Setup the global FileState struc * * Note: Temporarily re-routes the SI message to a new Q * * Inputs: file number * Outputs: error_numb (0 if ok) * *****************************************************************************/ s32 GetFileState(s32 file) {
    s32 temp_v0;
    s32 sp1C;

    StartSerialQ();
    temp_v0 = osPfsFileState(&D_80119A08, file, &D_80119A90);
    sp1C = temp_v0;
    EndSerialQ();
    return temp_v0;
}
