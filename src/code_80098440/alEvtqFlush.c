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

s32 func_8009D220(s32);                             /* extern */
M2C_UNK alUnlink(M2C_UNK *);                   /* extern */
M2C_UNK alLink(M2C_UNK *, void *);           /* extern */

void alEvtqFlush(void *arg0) {
    M2C_UNK *var_s0;
    M2C_UNK *temp_s1;
    unsigned long sp2C;

    sp2C = func_8009D220(1);
    var_s0 = M2C_FIELD(arg0, M2C_UNK **, 8);
    if (var_s0 != NULL) {
        do {
            temp_s1 = *var_s0;
            alUnlink(var_s0);
            alLink(var_s0, arg0);
            var_s0 = temp_s1;
        } while (temp_s1 != NULL);
    }
    func_8009D220(sp2C);
}
