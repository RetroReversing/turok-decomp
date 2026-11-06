#include "common.h"

typedef struct { s32 x, y, z; } SolVec3;
void AI_DoParticle(s32, s32, SolVec3);
void AI_SEvent_Generic213(s32 arg0, SolVec3 arg1) { AI_DoParticle(arg0, 0x147, arg1); }
