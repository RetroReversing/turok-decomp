#include "common.h"

s32 osWritebackDCache(s32, s32);
s32 osInvalDCache(s32, s32);
s32 osVirtualToPhysical(s32);
s32 func_800AFDD0();
extern volatile s32 D_A4800000;
extern volatile s32 D_A4800004;
extern volatile s32 D_A4800010;

s32 __osSiRawStartDma(volatile s32 arg0, s32 arg1) {
    if (func_800AFDD0() != 0) {
        return -1;
    }
    if (arg0 == 1) {
        osWritebackDCache(arg1, 0x40);
    }
    *(volatile s32 *)0xA4800000 = osVirtualToPhysical(arg1);
    if (arg0 == 0) {
        *(volatile s32 *)0xA4800004 = 0x1FC007C0;
    } else {
        *(volatile s32 *)0xA4800010 = 0x1FC007C0;
    }
    if (arg0 == 0) {
        osInvalDCache(arg1, 0x40);
    }
    return 0;
}
