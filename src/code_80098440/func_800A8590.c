#include "common.h"

s32 func_800A16E0(s32, s32);
s32 func_800A1760(s32, s32);
s32 func_800A4F30(s32);
s32 func_800AFDD0();
extern volatile s32 D_A4800000;
extern volatile s32 D_A4800004;
extern volatile s32 D_A4800010;

s32 func_800A8590(volatile s32 arg0, s32 arg1) {
    if (func_800AFDD0() != 0) {
        return -1;
    }
    if (arg0 == 1) {
        func_800A16E0(arg1, 0x40);
    }
    *(volatile s32 *)0xA4800000 = func_800A4F30(arg1);
    if (arg0 == 0) {
        *(volatile s32 *)0xA4800004 = 0x1FC007C0;
    } else {
        *(volatile s32 *)0xA4800010 = 0x1FC007C0;
    }
    if (arg0 == 0) {
        func_800A1760(arg1, 0x40);
    }
    return 0;
}
