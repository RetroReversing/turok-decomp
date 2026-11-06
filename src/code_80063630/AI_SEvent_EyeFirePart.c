#include "common.h"

typedef struct {s32 x,y,z;} SolVec3;
extern f32 D_800F4770;
void AI_AimParticleAtPlayer(s32,s32,SolVec3,f32);
void AI_SEvent_EyeFirePart(s32 a,SolVec3 b){AI_AimParticleAtPlayer(a,0x14,b,D_800F4770);}
