#include "common.h"

s32 osVirtualToPhysical(s32); s32 func_800AAF70();
s32 func_800AAEE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_800AAF70() != 0) return -1;
    *(volatile s32 *)0xA4040000 = arg1;
    *(volatile s32 *)0xA4040004 = osVirtualToPhysical(arg2);
    if (arg0 == 0) *(volatile s32 *)0xA404000C = arg3 - 1;
    else *(volatile s32 *)0xA4040008 = arg3 - 1;
    return 0;
}
