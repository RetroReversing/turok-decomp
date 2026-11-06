#include "common.h"

typedef struct {s32 x,y,z;} SolVec3;
typedef struct {s32 x;SolVec3 vec;} SolObj;
extern SolObj *D_8010201C;
void CAnimInstanceHdr__IsObstructed(s32,SolVec3,s32);
void Campaigner_TurokObstructed(s32 a,s32 b){SolObj *o=D_8010201C;CAnimInstanceHdr__IsObstructed(a,o->vec,0);}
