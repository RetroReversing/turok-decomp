#include "common.h"

extern float func_8009E7A0(float value);
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern float func_80013A24(CVector3 *pThis) ;
extern float func_8001349C(float x);
float func_80013A24(CVector3 *pThis);
float func_8001349C(float x);
float func_80013A24(CVector3 *pThis){
 float dx, dz,
    magDelta,
    dot, theta;
 dx = pThis->x ;
 dz = pThis->z ;
 magDelta = (dx*dx) + (dz*dz) ;
 if (magDelta == 0)
  return 0 ;
 magDelta = func_8009E7A0(magDelta) ;
 dot = ((-1) > (((1) < (-dz/magDelta) ? (1) : (-dz/magDelta))) ? (-1) : (((1) < (-dz/magDelta) ? (1) : (-dz/magDelta)))) ;
 theta = func_8001349C(dot) ;
 return (-dx > 0) ? theta : -theta ;
}
