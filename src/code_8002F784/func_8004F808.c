#include "common.h"

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

s32 func_8004F808(void *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x17C), void **, 0x250), s32 *, 4);
    switch (arg1) {
    case 12:
    case 16:
        return (temp_v1 & 1) != 0;
    case 13:
    case 17:
        return (temp_v1 & 2) != 0;
    case 1:
    case 5:
        return (temp_v1 & 4) != 0;
    case 11:
        return (temp_v1 & 8) != 0;
    default:
        return 0;
    }
}
