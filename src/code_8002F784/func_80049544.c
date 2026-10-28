#include "common.h"

extern void func_80040228(s32, void *, s32);
extern void func_8004826C(s32, s32);
void func_80049544(s32 arg0, void *arg1) {
    s32 val = *(s32 *)((u8 *)arg1 + 0x20);
    if (val == 0x13) {
        func_80040228(arg0, arg1, 0x3E0EFA35);
        val = *(s32 *)((u8 *)arg1 + 0x20);
    }
    if (val == 0x16) {
        func_80040228(arg0, arg1, 0x3D567750);
    }
    if (*(s32 *)((u8 *)arg1 + 0x3C) >= *(s32 *)((u8 *)arg1 + 0x48)) {
        func_8004826C(arg0, *(s32 *)((u8 *)arg1 + 0x20) + 2);
    }
}
