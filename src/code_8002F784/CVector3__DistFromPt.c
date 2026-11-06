#include "common.h"

extern float sqrtf(float value);
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
float CVector3__DistFromPt(CVector3 *pThis, CVector3 *pvPt);
float CVector3__DistFromPt(CVector3 *pThis, CVector3 *pvPt){
 float dx,dy,dz, d ;
 dx = pThis->x - pvPt->x ;
 dy = pThis->y - pvPt->y ;
 dz = pThis->z - pvPt->z ;
 d = (dx * dx) + (dy * dy) + (dz * dz) ;
 if (d != 0.0)
  return sqrtf(d) ;
 else
  return d ;
}
