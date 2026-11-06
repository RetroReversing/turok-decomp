#include "common.h"

typedef struct {s32 x,y,z;} SolVec3;
void AI_SEvent_Grunt(s32,SolVec3,f32);
void AI_SEvent_Growl(s32 a,SolVec3 b,f32 c){AI_SEvent_Grunt(a,b,c);}
