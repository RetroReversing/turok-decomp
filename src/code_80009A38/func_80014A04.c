#include "common.h"

extern float func_8009E7B0(float angle);
struct CQuatern_t;
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
extern void func_80014A04(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
extern float func_8001349C(float x);
void func_80014A04(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
float func_8001349C(float x);
void func_80014A04(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB){
 CQuatern qBN;
 float dot, dotN,
     theta, sinTheta, invSinTheta,
     vA, vB;
 /* Blend between quaternions along the shorter spherical arc (graphu64.c). */
 qBN = *pqB;
 (&qBN)->x = -((&qBN)->x); (&qBN)->y = -((&qBN)->y); (&qBN)->z = -((&qBN)->z); (&qBN)->t = -((&qBN)->t);;
 dot = ((pqA)->x*(pqB)->x + (pqA)->y*(pqB)->y + (pqA)->z*(pqB)->z + (pqA)->t*(pqB)->t);
 dotN = ((pqA)->x*(&qBN)->x + (pqA)->y*(&qBN)->y + (pqA)->z*(&qBN)->z + (pqA)->t*(&qBN)->t);
 if (dot < dotN)
 {
  dot = dotN;
  pqB = &qBN;
 }
 theta = func_8001349C(dot);
 sinTheta = func_8009E7B0(theta);
   if (sinTheta == 0)
   {
  *pqThis = *pqA;
   }
   else
   {
      invSinTheta = 1/sinTheta;
  vA = func_8009E7B0((1-u)*theta) * invSinTheta;
  vB = func_8009E7B0(u*theta) * invSinTheta;
  if (dot < dotN)
   pqB = &qBN;
  pqThis->x = vA*pqA->x + vB*pqB->x;
  pqThis->y = vA*pqA->y + vB*pqB->y;
  pqThis->z = vA*pqA->z + vB*pqB->z;
  pqThis->t = vA*pqA->t + vB*pqB->t;
   }
}
