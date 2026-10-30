#include "common.h"

extern float __sinf(float angle);
typedef struct CQuatern_t { float x,y,z,t; } CQuatern;
extern float func_8001349C(float x);
extern void func_80014538(CQuatern *q);
extern double D_800F0D30;
void func_800145DC(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB){
 CQuatern qBN;
 float dot, dotN,
     theta, sinTheta, invSinTheta,
     vA, vB;
 qBN = *pqB;
 (&qBN)->x = -((&qBN)->x); (&qBN)->y = -((&qBN)->y); (&qBN)->z = -((&qBN)->z); (&qBN)->t = -((&qBN)->t);;
 dot = ((pqA)->x*(pqB)->x + (pqA)->y*(pqB)->y + (pqA)->z*(pqB)->z + (pqA)->t*(pqB)->t);
 dotN = ((pqA)->x*(&qBN)->x + (pqA)->y*(&qBN)->y + (pqA)->z*(&qBN)->z + (pqA)->t*(&qBN)->t);
 if (dot < dotN)
 {
  dot = dotN;
  pqB = &qBN;
 }
 if (D_800F0D30 < (double)dot) {
  pqThis->x = pqA->x + u * (pqB->x - pqA->x);
  pqThis->y = pqA->y + u * (pqB->y - pqA->y);
  pqThis->z = pqA->z + u * (pqB->z - pqA->z);
  pqThis->t = pqA->t + u * (pqB->t - pqA->t);
  func_80014538(pqThis);
  return;
 }
 theta = func_8001349C(dot);
 sinTheta = __sinf(theta);
   if (sinTheta == 0)
   {
  *pqThis = *pqA;
   }
   else
   {
      invSinTheta = 1/sinTheta;
  vA = __sinf((1-u)*theta) * invSinTheta;
  vB = __sinf(u*theta) * invSinTheta;
  if (dot < dotN)
   pqB = &qBN;
  pqThis->x = vA*pqA->x + vB*pqB->x;
  pqThis->y = vA*pqA->y + vB*pqB->y;
  pqThis->z = vA*pqA->z + vB*pqB->z;
  pqThis->t = vA*pqA->t + vB*pqB->t;
   }
}
