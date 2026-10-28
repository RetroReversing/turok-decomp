#include "common.h"

extern f32 D_800F2C38; extern f32 func_80040D10(f32,f32); extern s32 func_800137A0(void); typedef struct { f32 x,y,z; } Vec3; extern void func_80063AE8(void*,Vec3,f32);
void func_8004AF44(void*a,void*b){s32 x;if(*(f32*)((char*)b+0x1A4)<=0.0f){*(f32*)((char*)b+0x1A4)=func_80040D10(120.0f,180.0f);x=func_800137A0();if(x%2)func_80063AE8(a,*(Vec3*)((char*)a+4),D_800F2C38);else func_80063AE8(a,*(Vec3*)((char*)a+4),354.0f);}}
