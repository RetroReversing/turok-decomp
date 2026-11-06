#include "common.h"

extern f32 D_800F2C38; extern f32 RandomRangeFLOAT(f32,f32); extern s32 RandomSwapWord(void); typedef struct { f32 x,y,z; } Vec3; extern void AI_SEvent_GeneralSound(void*,Vec3,f32);
void Longhunt_PlayAttackTauntSount(void*a,void*b){s32 x;if(*(f32*)((char*)b+0x1A4)<=0.0f){*(f32*)((char*)b+0x1A4)=RandomRangeFLOAT(120.0f,180.0f);x=RandomSwapWord();if(x%2)AI_SEvent_GeneralSound(a,*(Vec3*)((char*)a+4),D_800F2C38);else AI_SEvent_GeneralSound(a,*(Vec3*)((char*)a+4),354.0f);}}
