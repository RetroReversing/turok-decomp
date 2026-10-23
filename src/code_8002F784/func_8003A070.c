#include "common.h"

extern float func_8009E7A0(float value);
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
float func_8003A070(CVector3 *pThis, CVector3 *pvPt);
float func_8003A070(CVector3 *pThis, CVector3 *pvPt){
 float dx,dy,dz, d ;
 dx = pThis->x - pvPt->x ;
 dy = pThis->y - pvPt->y ;
 dz = pThis->z - pvPt->z ;
 d = (dx * dx) + (dy * dy) + (dz * dz) ;
 if (d != 0.0)
  return func_8009E7A0(d) ;
 else
  return d ;
}
