#include "common.h"
#line 1 "func.c"
typedef struct { f32 x,y,z; } LiveV3;
extern void func_80013B2C(LiveV3*);
extern void func_80013BBC(LiveV3*,LiveV3*,LiveV3*);
extern void func_80013C2C(LiveV3*,LiveV3*,f32);
LiveV3 CVector3__ProjectCrease(LiveV3 *v,LiveV3 *a,LiveV3 *b)
{
 LiveV3 cross,project;
 f32 dot;
 func_80013BBC(&cross,a,b);
 func_80013B2C(&cross);
 dot=v->x*cross.x+v->y*cross.y+v->z*cross.z;
 func_80013C2C(&project,&cross,dot);
 return project;
}

