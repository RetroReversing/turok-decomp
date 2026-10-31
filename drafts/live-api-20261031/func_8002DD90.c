#include "../../include/common.h"
#line 1 "func.c"
/* machine draft (m2c) for ido-5.3 -O3 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul, tried by autopilot */
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

void func_8002DD90(void *arg0, void **arg1, s32 *arg2, s32 *arg3) {
    u32 temp_a2;
    u32 temp_a2_2;
    u32 var_v1;
    u32 var_v1_2;
    void **var_a3;
    void **var_a3_2;
    void *var_t0;
    void *var_v0;

    var_v0 = *arg1;
    if (var_v0 == (void *)-1) {
        temp_a2 = M2C_FIELD(arg0, u32 *, 4);
        var_v1 = 0;
        if (temp_a2 != 0) {
            var_a3 = M2C_FIELD(arg0, void ***, 0);
loop_3:
            var_v0 = *var_a3;
            var_v1 += 1;
            if (var_v0 == NULL) {
                var_a3 += 1;
                if (var_v1 < temp_a2) {
                    goto loop_3;
                }
            }
        }
    }
    var_t0 = M2C_FIELD(var_v0, void **, 0);
    if (var_t0 == NULL) {
        temp_a2_2 = M2C_FIELD(arg0, u32 *, 4);
        var_v1_2 = M2C_FIELD(var_v0, s32 *, 4) + 1;
        if (var_v1_2 < temp_a2_2) {
            var_a3_2 = M2C_FIELD(arg0, void ***, 0) + var_v1_2;
loop_8:
            var_t0 = *var_a3_2;
            var_v1_2 += 1;
            if (var_t0 == NULL) {
                var_a3_2 += 1;
                if (var_v1_2 < temp_a2_2) {
                    goto loop_8;
                }
            }
        }
    }
    *arg1 = var_t0;
    *arg2 = M2C_FIELD(var_v0, s32 *, 8);
    *arg3 = M2C_FIELD(var_v0, s32 *, 0xC);
}

