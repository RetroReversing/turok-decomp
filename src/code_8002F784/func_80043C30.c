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

s32 func_800186FC();                             /* extern */

s32 func_80043C30(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = func_800186FC(arg0, M2C_FIELD(arg0, s32 *, 0x138));
    switch (temp_v0) {                              /* irregular */
    case 0x3:
    case 0x4:
    case 0x6:
    case 0x7:
    case 0x8:
    case 0x9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0xB55:
    case 0xB56:
    case 0xB57:
        return 1;
    default:
        return 0;
    }
}
