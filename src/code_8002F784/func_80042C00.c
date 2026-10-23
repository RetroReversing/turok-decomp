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

M2C_UNK func_80042794(M2C_UNK *, void *, M2C_UNK *); /* extern */
M2C_UNK func_800436A4(void *);                      /* extern */
extern M2C_UNK D_800BB128;
extern M2C_UNK D_800BB144;
extern M2C_UNK D_800BB160;
extern M2C_UNK D_800BB17C;
extern M2C_UNK D_800BB2B4;
extern M2C_UNK D_800BB2D0;
extern M2C_UNK D_800BB4A4;
extern M2C_UNK D_800BB4C0;
extern M2C_UNK D_800BB4DC;
extern M2C_UNK D_800BB4F8;
extern M2C_UNK D_80112E10;

void func_80042C00(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0) == 1) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x11A);
        switch (temp_v0) {                          /* irregular */
        case 0x3E8:
            func_80042794(&D_80112E10, arg0, &D_800BB128);
            func_80042794(&D_80112E10, arg0, &D_800BB144);
            func_80042794(&D_80112E10, arg0, &D_800BB160);
            func_80042794(&D_80112E10, arg0, &D_800BB17C);
            return;
        case 0x3EA:
            func_80042794(&D_80112E10, arg0, &D_800BB2B4);
            func_80042794(&D_80112E10, arg0, &D_800BB2D0);
            return;
        case 0x3EB:
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x17C), s32 *, 0x34) & 0x1000) {
                func_80042794(&D_80112E10, arg0, &D_800BB4DC);
                func_80042794(&D_80112E10, arg0, &D_800BB4F8);
                return;
            }
            func_80042794(&D_80112E10, arg0, &D_800BB4A4);
            func_80042794(&D_80112E10, arg0, &D_800BB4C0);
            return;
        case 0x2:
            func_800436A4(arg0);
            break;
        }
    }
}
