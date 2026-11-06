#include "common.h"

extern float sqrtf(float value);
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern CVector3 CVector3__Project(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
extern CVector3 CVector3__Redirect(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
CVector3 CVector3__Project(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
CVector3 CVector3__Redirect(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
CVector3 CVector3__Redirect(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal){
 CVector3 vProjected;
 float magProj, magRatio;
 vProjected = CVector3__Project(pvThis, pvSurfaceUnitNormal);
 magProj = sqrtf(((&vProjected)->x*(&vProjected)->x + (&vProjected)->y*(&vProjected)->y + (&vProjected)->z*(&vProjected)->z));
 if (magProj != 0)
 {
  magRatio = sqrtf(((pvThis)->x*(pvThis)->x + (pvThis)->y*(pvThis)->y + (pvThis)->z*(pvThis)->z))/magProj;
  vProjected.x *= magRatio;
  vProjected.y *= magRatio;
  vProjected.z *= magRatio;
 }
 return vProjected;
}
