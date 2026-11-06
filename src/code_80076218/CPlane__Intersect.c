#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void CVector3__Subtract(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
typedef struct CPlane_t
{
 CVector3 m_vPoint,
     m_vNormal;
} CPlane;
extern float CPlane__Intersect(CPlane *pThis, CVector3 *pvA, CVector3 *pvB);
float CPlane__Intersect(CPlane *pThis, CVector3 *pvA, CVector3 *pvB);
float CPlane__Intersect(CPlane *pThis, CVector3 *pvA, CVector3 *pvB){
 CVector3 vDelta, vPointDelta;
 float normalDotDelta, normalDotPointDelta;
 CVector3__Subtract(&vDelta, pvB, pvA);
 normalDotDelta = ((&pThis->m_vNormal)->x*(&vDelta)->x + (&pThis->m_vNormal)->y*(&vDelta)->y + (&pThis->m_vNormal)->z*(&vDelta)->z);
 if (normalDotDelta == 0)
  return 1;
 CVector3__Subtract(&vPointDelta, &pThis->m_vPoint, pvA);
 normalDotPointDelta = ((&pThis->m_vNormal)->x*(&vPointDelta)->x + (&pThis->m_vNormal)->y*(&vPointDelta)->y + (&pThis->m_vNormal)->z*(&vPointDelta)->z);
 return normalDotPointDelta/normalDotDelta;
}
