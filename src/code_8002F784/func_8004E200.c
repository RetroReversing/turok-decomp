#include "common.h"

typedef struct {s32 x,y,z;} SolVec3;
typedef struct {s32 x;SolVec3 vec;} SolObj;
extern SolObj *D_8010201C;
void func_8001DF50(s32,SolVec3,s32);
void func_8004E200(s32 a,s32 b){SolObj *o=D_8010201C;func_8001DF50(a,o->vec,0);}
