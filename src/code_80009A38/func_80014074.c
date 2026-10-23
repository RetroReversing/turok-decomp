#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern CVector3 func_80014074(CVector3 *pThis, CVector3 *pvSurfaceUnitNormal, float EnergyFactor);
CVector3 func_80014074(CVector3 *pThis, CVector3 *pvSurfaceUnitNormal, float EnergyFactor);
CVector3 func_80014074(CVector3 *pThis, CVector3 *pvSurfaceUnitNormal, float EnergyFactor){
 CVector3 vReflect;
 float dot;
 dot = ((pThis)->x*(pvSurfaceUnitNormal)->x + (pThis)->y*(pvSurfaceUnitNormal)->y + (pThis)->z*(pvSurfaceUnitNormal)->z);
 vReflect.x = pThis->x - (1 + EnergyFactor)*pvSurfaceUnitNormal->x*dot;
 vReflect.y = pThis->y - (1 + EnergyFactor)*pvSurfaceUnitNormal->y*dot;
 vReflect.z = pThis->z - (1 + EnergyFactor)*pvSurfaceUnitNormal->z*dot;
 return vReflect;
}
