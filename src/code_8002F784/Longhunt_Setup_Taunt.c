#include "common.h"

extern f32 D_800F2C3C;
extern s32 CCamera__InCinemaMode(void*);
extern s32 RandomSwapWord(void);
typedef struct { f32 x,y,z; } Vec3;
extern void AI_SEvent_GeneralSound(void*,Vec3,f32);
extern u8 D_80112C18[];
void Longhunt_Setup_Taunt(void *a,void *b)
{
    *(s32*)((char*)b+0x20)=8;
    if (CCamera__InCinemaMode(D_80112C18))
        AI_SEvent_GeneralSound(a,*(Vec3*)((char*)a+4),354.0f);
    else if (RandomSwapWord()%2)
        AI_SEvent_GeneralSound(a,*(Vec3*)((char*)a+4),D_800F2C3C);
    else
        AI_SEvent_GeneralSound(a,*(Vec3*)((char*)a+4),354.0f);
}
