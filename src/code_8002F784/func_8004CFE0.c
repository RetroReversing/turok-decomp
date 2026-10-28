#include "common.h"

extern void func_8008A5C4(s32, void*);

void func_8004CFE0(void *arg0, void *arg1) {
    *(s32*)((u8*)arg1 + 0x20) = 10;
    if (-1 != *(s32*)((u8*)arg1 + 0x1A4)) {
        *(s32*)((u8*)arg1 + 0x1A4) = -1;
        func_8008A5C4(*(s32*)((u8*)arg1 + 0x1A8), arg1);
    }
    *(s32*)((u8*)arg1 + 0x168) = 0;
    *(s32*)((u8*)arg0 + 0x1D0) |= 0x1000;
}
