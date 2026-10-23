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

s32 func_800583D4(void *);                          /* extern */
s32 func_80058644(void *);                          /* extern */
M2C_UNK func_8007F320(M2C_UNK *, s32, s32);         /* extern */
M2C_UNK func_8007F4A4(M2C_UNK *, u8, M2C_UNK);      /* extern */
extern M2C_UNK D_80111B70;

void func_8005AFE8(void *arg0, M2C_UNK arg1) {
    s32 pad; s32 sp18;

    func_8007F4A4(&D_80111B70, M2C_FIELD(arg0, u8 *, 0x2BF), arg1);
    sp18 = func_80058644(arg0);
    func_8007F320(&D_80111B70, sp18, func_800583D4(arg0));
}
