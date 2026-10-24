#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void func_800144C8(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
typedef struct CPlane_t
{
 CVector3 m_vPoint,
     m_vNormal;
} CPlane;
extern float func_80084714(CPlane *pThis, CVector3 *pvA, CVector3 *pvB);
float func_80084714(CPlane *pThis, CVector3 *pvA, CVector3 *pvB);
float func_80084714(CPlane *pThis, CVector3 *pvA, CVector3 *pvB){
 CVector3 vDelta, vPointDelta;
 float normalDotDelta, normalDotPointDelta;
 func_800144C8(&vDelta, pvB, pvA);
 normalDotDelta = ((&pThis->m_vNormal)->x*(&vDelta)->x + (&pThis->m_vNormal)->y*(&vDelta)->y + (&pThis->m_vNormal)->z*(&vDelta)->z);
 if (normalDotDelta == 0)
  return 1;
 func_800144C8(&vPointDelta, &pThis->m_vPoint, pvA);
 normalDotPointDelta = ((&pThis->m_vNormal)->x*(&vPointDelta)->x + (&pThis->m_vNormal)->y*(&vPointDelta)->y + (&pThis->m_vNormal)->z*(&vPointDelta)->z);
 return normalDotPointDelta/normalDotDelta;
}
