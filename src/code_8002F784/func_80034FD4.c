#include "common.h"

extern s32 CCacheEntry__GetData(s32); extern void func_8002DA8C(void*,s32,s32); extern void func_8002D1F8(void*,s32,s32,s32,void*,s32,s32,void*); extern u8 D_800F1A78[];
void func_80034FD4(void *a,s32 b){u8 temp[12];s32 x; s32 n; void *p=a; x=CCacheEntry__GetData(*(s32*)((u8*)a+0x6B34));func_8002DA8C(temp,x,0);n=*(s32*)(*(u32*)temp+4);func_8002D1F8(p,0,0,0,(u8*)p+0x6B30,*(s32*)((u8*)p+0x6AE4),((n*4+15)&~7),D_800F1A78);}
