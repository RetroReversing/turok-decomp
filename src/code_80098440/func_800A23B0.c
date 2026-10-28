#include "common.h"

extern s32 func_800A4A0C(s32, s32 *); extern void func_800ACBAC(void *, s16 *, s32); void func_800A23B0(void *p){struct {s32 n;s16 z;u8 pad[12];} local; if (*(s32*)((u8*)p+0x2c)==1){s32 v=*(s32*)((u8*)p+0x18); if(v && func_800A4A0C(v,&local.n)){local.z=0;func_800ACBAC((u8*)p+0x48,&local.z,*(s32*)((u8*)p+0x24)*local.n);}}}
