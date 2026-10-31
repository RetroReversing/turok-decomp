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
M2C_UNK alUnlink(void *);                      /* extern */
M2C_UNK alLink(void *, void *);              /* extern */

void alEvtqFlushType(void *arg0, s16 arg1) {
    s32 padding[4];
    s32 sp2C;
    void *temp_s1;
    void *var_s0;

    sp2C = func_8009D220(1);
    var_s0 = M2C_FIELD(arg0, void **, 8);
    if (var_s0 != NULL) {
        do {
            temp_s1 = M2C_FIELD(var_s0, void **, 0);
            if (arg1 == M2C_FIELD(var_s0, s16 *, 0xC)) {
                if (temp_s1 != NULL) {
                    M2C_FIELD(temp_s1, s32 *, 8) = (s32) (M2C_FIELD(var_s0, s32 *, 8) + M2C_FIELD(temp_s1, s32 *, 8));
                }
                alUnlink(var_s0);
                alLink(var_s0, arg0);
            }
            var_s0 = temp_s1;
        } while (temp_s1 != NULL);
    }
    func_8009D220(sp2C);
}
