#include "common.h"

extern float sqrtf(float value);
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern float CVector3__XZAngle(CVector3 *pThis) ;
extern float acos(float x);
float CVector3__XZAngle(CVector3 *pThis);
float acos(float x);
float CVector3__XZAngle(CVector3 *pThis){
 float dx, dz,
    magDelta,
    dot, theta;
 dx = pThis->x ;
 dz = pThis->z ;
 magDelta = (dx*dx) + (dz*dz) ;
 if (magDelta == 0)
  return 0 ;
 magDelta = sqrtf(magDelta) ;
 dot = ((-1) > (((1) < (-dz/magDelta) ? (1) : (-dz/magDelta))) ? (-1) : (((1) < (-dz/magDelta) ? (1) : (-dz/magDelta)))) ;
 theta = acos(dot) ;
 return (-dx > 0) ? theta : -theta ;
}
