#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"
typedef struct { f32 x,y,z; } LiveV3;
extern void CVector3__Normalize(LiveV3*);
extern void CVector3__Cross(LiveV3*,LiveV3*,LiveV3*);
extern void CVector3__MultScaler(LiveV3*,LiveV3*,f32);
LiveV3 CVector3__ProjectCrease(LiveV3 *pvThis,LiveV3 *pvNormalA,LiveV3 *pvNormalB)
{
 LiveV3 cross,project;
 f32 dot;
 CVector3__Cross(&cross,pvNormalA,pvNormalB);
 CVector3__Normalize(&cross);
 dot=pvThis->x*cross.x+pvThis->y*cross.y+pvThis->z*cross.z;
 CVector3__MultScaler(&project,&cross,dot);
 return project;
}
