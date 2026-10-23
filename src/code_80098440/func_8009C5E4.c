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

M2C_UNK func_8009C5D0(M2C_UNK *);                   /* extern */
M2C_UNK func_8009C884(M2C_UNK *);                   /* extern */
M2C_UNK func_8009C8D0(M2C_UNK *);                   /* extern */
M2C_UNK func_8009C91C(M2C_UNK *);                   /* extern */
M2C_UNK func_8009C968(M2C_UNK *);                   /* extern */
M2C_UNK func_8009C9AC(M2C_UNK *);                   /* extern */
M2C_UNK func_8009C9E8(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CA34(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CA74(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CACC(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CB24(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CB7C(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CBC8(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CC20(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CC78(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CCC4(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CD10(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CD68(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CDB8(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CE0C(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CE5C(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CEA0(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CED4(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CF08(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CF3C(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CF70(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CFA4(M2C_UNK *);                   /* extern */
M2C_UNK func_8009CFDC(M2C_UNK *);                   /* extern */
extern M2C_UNK D_80135C20;
extern M2C_UNK D_80135CA0;
extern M2C_UNK D_80135D20;
extern M2C_UNK D_80135DA0;
extern M2C_UNK D_80135E20;
extern M2C_UNK D_80135EA0;
extern M2C_UNK D_80135F20;
extern M2C_UNK D_80135FA0;
extern M2C_UNK D_80136020;
extern M2C_UNK D_801360A0;
extern M2C_UNK D_80136120;
extern M2C_UNK D_801361A0;
extern M2C_UNK D_80136220;
extern M2C_UNK D_801362A0;
extern M2C_UNK D_80136320;
extern M2C_UNK D_801363A0;
extern M2C_UNK D_80136420;
extern M2C_UNK D_801364A0;
extern M2C_UNK D_80136520;
extern M2C_UNK D_801365A0;
extern M2C_UNK D_80136620;
extern M2C_UNK D_801366A0;
extern M2C_UNK D_80136720;
extern M2C_UNK D_801367A0;
extern M2C_UNK D_80136820;
extern M2C_UNK D_801368A0;
extern M2C_UNK D_80136920;

void func_8009C5E4(void) {
    func_8009C884(&D_80135C20);
    func_8009C5D0(&D_80135C20);
    func_8009C8D0(&D_80135CA0);
    func_8009C5D0(&D_80135CA0);
    func_8009C91C(&D_80135D20);
    func_8009C5D0(&D_80135D20);
    func_8009C968(&D_80135DA0);
    func_8009C5D0(&D_80135DA0);
    func_8009C9AC(&D_80135E20);
    func_8009C5D0(&D_80135E20);
    func_8009C9E8(&D_80135EA0);
    func_8009C5D0(&D_80135EA0);
    func_8009CA34(&D_80135F20);
    func_8009C5D0(&D_80135F20);
    func_8009CA74(&D_80135FA0);
    func_8009C5D0(&D_80135FA0);
    func_8009CACC(&D_80136020);
    func_8009C5D0(&D_80136020);
    func_8009CB24(&D_801360A0);
    func_8009C5D0(&D_801360A0);
    func_8009CB7C(&D_80136120);
    func_8009C5D0(&D_80136120);
    func_8009CBC8(&D_801361A0);
    func_8009C5D0(&D_801361A0);
    func_8009CC20(&D_80136220);
    func_8009C5D0(&D_80136220);
    func_8009CC78(&D_801362A0);
    func_8009C5D0(&D_801362A0);
    func_8009CCC4(&D_80136320);
    func_8009C5D0(&D_80136320);
    func_8009CD10(&D_801363A0);
    func_8009C5D0(&D_801363A0);
    func_8009CD68(&D_80136420);
    func_8009C5D0(&D_80136420);
    func_8009CEA0(&D_80136620);
    func_8009C5D0(&D_80136620);
    func_8009CED4(&D_801366A0);
    func_8009C5D0(&D_801366A0);
    func_8009CF08(&D_80136720);
    func_8009C5D0(&D_80136720);
    func_8009CF3C(&D_801367A0);
    func_8009C5D0(&D_801367A0);
    func_8009CDB8(&D_801364A0);
    func_8009C5D0(&D_801364A0);
    func_8009CE0C(&D_80136520);
    func_8009C5D0(&D_80136520);
    func_8009CE5C(&D_801365A0);
    func_8009C5D0(&D_801365A0);
    func_8009CF70(&D_80136820);
    func_8009C5D0(&D_80136820);
    func_8009CFA4(&D_801368A0);
    func_8009C5D0(&D_801368A0);
    func_8009CFDC(&D_80136920);
    func_8009C5D0(&D_80136920);
}
