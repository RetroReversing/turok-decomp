#include "common.h"

typedef struct {s32 x,y,z;} SolVec3;
extern f32 D_800F4438;
void func_80060464(s32,s32,SolVec3,f32);
void func_80065FEC(s32 a,SolVec3 b){func_80060464(a,0x108,b,D_800F4438);}
