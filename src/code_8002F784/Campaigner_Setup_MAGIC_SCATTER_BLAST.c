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

M2C_UNK CSpecialFx__StartScript(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_800BDA70;

void Campaigner_Setup_MAGIC_SCATTER_BLAST(s32 arg0, u8 *arg1) {
    M2C_FIELD(arg1, s32 *, 0x20) = 0x22;
    CSpecialFx__StartScript(arg1 + 0x188, &D_800BDA70);
}
