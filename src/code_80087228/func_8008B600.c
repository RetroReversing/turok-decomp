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

s32 func_8002D690(void *);                          /* extern */
M2C_UNK func_8009FA50(M2C_UNK *, s32, s32);         /* extern */
extern s32 D_800ECF60;
extern M2C_UNK D_8012AF28;

void func_8008B600(s32 arg0, void **arg1) {
    func_8009FA50(&D_8012AF28, func_8002D690(*arg1), M2C_FIELD(*arg1, s32 *, 4));
    D_800ECF60 |= 8;
}
