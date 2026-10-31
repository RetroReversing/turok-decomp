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

M2C_UNK CParticleSystem__DeallocateParticle(void *, void *);              /* extern */

void func_8002B570(void *arg0) {
    void *temp_a1;
    void *var_s0;

    var_s0 = M2C_FIELD(arg0, void **, 0xC404);
    if (var_s0 != NULL) {
        do {
            temp_a1 = var_s0;
            var_s0 = M2C_FIELD(var_s0, void **, 0x178);
            CParticleSystem__DeallocateParticle(arg0, temp_a1);
        } while (var_s0 != NULL);
    }
}
