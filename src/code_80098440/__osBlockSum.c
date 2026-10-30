#include "common.h"

typedef struct { s32 unk0; s32 unk4; s32 unk8; u8 pad[0x65-12]; volatile u8 unk65; } S_func_800A0008;
extern s32 __osPfsSelectBank(S_func_800A0008 *);
extern s32 __osContRamRead(s32,s32,s32,void *);
extern s32 __osSumcalc(void *,s32);

s32 __osBlockSum(S_func_800A0008 *arg0, u8 arg1, u16 *arg2, u8 arg3){
    s32 sp3C;
    s32 sp38 = 0;
    u8 sp18[0x20];

    arg0->unk65 = arg3;
    sp38 = __osPfsSelectBank(arg0);
    if (sp38 != 0)
        return sp38;

    sp3C = 0;
    do {
        sp38 = __osContRamRead(arg0->unk4, arg0->unk8, (arg1 * 8) + sp3C, sp18);
        if (sp38 != 0) {
            arg0->unk65 = 0;
            __osPfsSelectBank(arg0);
            return sp38;
        }
        *arg2 = *arg2 + __osSumcalc(sp18, 0x20);
    } while (++sp3C < 8);

    arg0->unk65 = 0;
    sp38 = __osPfsSelectBank(arg0);
    return sp38;
}
