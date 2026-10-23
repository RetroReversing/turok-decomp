#include "common.h"

extern float func_8009E7A0(float value);
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern CVector3 func_80013E64(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
extern CVector3 func_80013EF0(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
CVector3 func_80013E64(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
CVector3 func_80013EF0(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
CVector3 func_80013EF0(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal){
 CVector3 vProjected;
 float magProj, magRatio;
 vProjected = func_80013E64(pvThis, pvSurfaceUnitNormal);
 magProj = func_8009E7A0(((&vProjected)->x*(&vProjected)->x + (&vProjected)->y*(&vProjected)->y + (&vProjected)->z*(&vProjected)->z));
 if (magProj != 0)
 {
  magRatio = func_8009E7A0(((pvThis)->x*(pvThis)->x + (pvThis)->y*(pvThis)->y + (pvThis)->z*(pvThis)->z))/magProj;
  vProjected.x *= magRatio;
  vProjected.y *= magRatio;
  vProjected.z *= magRatio;
 }
 return vProjected;
}
