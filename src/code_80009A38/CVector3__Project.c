#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern CVector3 CVector3__Project(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
CVector3 CVector3__Project(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
CVector3 CVector3__Project(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal){
 CVector3 vProjected;
 float dot;
 dot = ((pvThis)->x*(pvSurfaceUnitNormal)->x + (pvThis)->y*(pvSurfaceUnitNormal)->y + (pvThis)->z*(pvSurfaceUnitNormal)->z);
 vProjected.x = pvThis->x - dot*pvSurfaceUnitNormal->x;
 vProjected.y = pvThis->y - dot*pvSurfaceUnitNormal->y;
 vProjected.z = pvThis->z - dot*pvSurfaceUnitNormal->z;
 return vProjected;
}
