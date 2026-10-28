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

M2C_UNK func_80004504(u8 *, M2C_UNK);             /* extern */
M2C_UNK CEngineApp__PrepareFrame(u8 *, M2C_UNK);             /* extern */
s32 func_80010310(u8 *);                          /* extern */
M2C_UNK func_8001116C();                            /* extern */
M2C_UNK func_8009E970(M2C_UNK *);                   /* extern */
extern u8 D_800B86D0;
extern M2C_UNK D_800F9C20;
extern s32 D_80119908;
extern s32 D_8011990C;

void func_80009A80(u8 *arg0) {
    if ((D_800B86D0 != 0) && (D_80119908 == 0)) {
        D_80119908 = 1;
        func_8009E970(&D_800F9C20);
    }
    if (D_8011990C != 0) {
        func_8001116C();
    }
    CEngineApp__PrepareFrame(arg0, 1);
    if (func_80010310(arg0 + 0x1F6C0) != -1) {
        M2C_FIELD(arg0, s32 *, 0x1F8B4) = 0;
        func_80004504(arg0, 0);
    }
}
