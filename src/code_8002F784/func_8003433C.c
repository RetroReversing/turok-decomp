#include "common.h"

extern void func_80035F84(void *,void *,s32,s32); extern void func_8002D1F8(); extern void func_800342B0(); extern unsigned char D_800F1AEC[]; void func_8003433C(void *arg0,s32 arg1){  func_80035F84((u8*)arg0+0x14280,arg0,*(s32*)((u8*)arg0+0x6AF4),*(s32*)((u8*)arg0+0x6ABC));  func_8002D1F8(arg0,arg0,0,func_800342B0,(u8*)arg0+0x6B00,*(s32*)((u8*)arg0+0x6AC0),4,D_800F1AEC);}
