#include "common.h"

extern f32 D_800F2C3C;
extern s32 func_80039B98(void*);
extern s32 func_800137A0(void);
typedef struct { f32 x,y,z; } Vec3;
extern void func_80063AE8(void*,Vec3,f32);
extern u8 D_80112C18[];
void func_8004B334(void *a,void *b)
{
    *(s32*)((char*)b+0x20)=8;
    if (func_80039B98(D_80112C18))
        func_80063AE8(a,*(Vec3*)((char*)a+4),354.0f);
    else if (func_800137A0()%2)
        func_80063AE8(a,*(Vec3*)((char*)a+4),D_800F2C3C);
    else
        func_80063AE8(a,*(Vec3*)((char*)a+4),354.0f);
}
