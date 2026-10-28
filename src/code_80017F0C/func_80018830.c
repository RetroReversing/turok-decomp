#include "common.h"

extern void func_800188C8(s32,void*); extern s32 CCacheEntry__GetData(s32); extern void CIndexedSet__ConstructFromRawData(void*,s32,s32); extern void func_8002D1F8(void*,void*,s32,void*,void*,s32,s32,void*); extern s32 func_8002DC24(s32,s32,u16); extern void func_80019C78(void*); extern void func_80013B2C(void*); extern void func_800187D0(); extern void func_8001914C();
extern s32 D_800B972C; extern f32 D_80119D90[3]; extern f32 D_80119D94,D_80119D98; extern s32 D_800F0E24,D_800FA3C8,D_800F0DF4;
void func_80018830(void *a,s32 unused){struct {s32 *data; s32 flags;} p; s32 raw=CCacheEntry__GetData(*(s32*)((char*)a+0x110)); CIndexedSet__ConstructFromRawData(&p,raw,0); *(s16*)((char*)a+0x11c)=*p.data; func_8002D1F8(&D_800FA3C8,a,0,func_800187D0,(char*)a+0x114,*(s32*)((char*)a+0x104),((*(s16*)((char*)a+0x11c)*4+15)&-8),&D_800F0E24);}
