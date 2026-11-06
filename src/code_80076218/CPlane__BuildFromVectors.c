#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void CVector3__Subtract(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
extern void CVector3__Cross(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
typedef struct CPlane_t
{
 CVector3 m_vPoint,
     m_vNormal;
} CPlane;
extern void CPlane__BuildFromVectors(CPlane *pThis, CVector3 *pvA, CVector3 *pvB, CVector3 *pvC);
void CPlane__BuildFromVectors(CPlane *pThis, CVector3 *pvA, CVector3 *pvB, CVector3 *pvC);
void CPlane__BuildFromVectors(CPlane *pThis, CVector3 *pvA, CVector3 *pvB, CVector3 *pvC){
 CVector3 vAB, vBC;
                          ;
 pThis->m_vPoint = *pvA;
 CVector3__Subtract(&vAB, pvB, pvA);
 CVector3__Subtract(&vBC, pvC, pvB);
 CVector3__Cross(&pThis->m_vNormal, &vAB, &vBC);
}
