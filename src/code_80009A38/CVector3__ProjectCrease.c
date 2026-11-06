#include "common.h"
#line 1 "func.c"
typedef struct { f32 x,y,z; } LiveV3;
extern void CVector3__Normalize(LiveV3*);
extern void CVector3__Cross(LiveV3*,LiveV3*,LiveV3*);
extern void CVector3__MultScaler(LiveV3*,LiveV3*,f32);
LiveV3 CVector3__ProjectCrease(LiveV3 *v,LiveV3 *a,LiveV3 *b)
{
 LiveV3 cross,project;
 f32 dot;
 CVector3__Cross(&cross,a,b);
 CVector3__Normalize(&cross);
 dot=v->x*cross.x+v->y*cross.y+v->z*cross.z;
 CVector3__MultScaler(&project,&cross,dot);
 return project;
}

