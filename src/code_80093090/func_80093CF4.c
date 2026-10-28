#include "common.h"

extern s32 func_800502F0(s32); extern u8 D_80109F10[]; void func_80093CF4(void *p){u8 *new_var;u32 base=(u32)D_80109F10;*((s32*)((u32)D_80109F10+0xf6dc))=0;*((s32*)((u8*)p+0x20))=0xb8;goto dummy;dummy:;*((s32*)((u8*)p+0x24))=0x80;*((s32*)(new_var=(u8*)p+0x28))=0x80;*((s32*)((u8*)p+0xc))=1;*((s32*)((u8*)p+0x10))=1;*((s32*)(base+0xf87c))=1;func_800502F0(*((s32*)((u8*)p+0xc)));}
