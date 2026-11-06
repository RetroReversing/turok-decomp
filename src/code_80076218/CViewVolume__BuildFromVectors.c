#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef struct CPlane_t
{
 CVector3 m_vPoint,
     m_vNormal;
} CPlane;
extern void CPlane__BuildFromVectors(CPlane *pThis, CVector3 *pvA, CVector3 *pvB, CVector3 *pvC);
typedef struct CViewVolume_t
{
 CPlane m_Planes[6];
} CViewVolume;
extern void CViewVolume__BuildFromVectors(CViewVolume *pThis,
               CVector3 *pvEye,
               CVector3 *pvUpLeft,
               CVector3 *pvUpRight,
               CVector3 *pvLowLeft,
               CVector3 *pvLowRight);
void CPlane__BuildFromVectors(CPlane *pThis, CVector3 *pvA, CVector3 *pvB, CVector3 *pvC);
void CViewVolume__BuildFromVectors(CViewVolume *pThis,
             CVector3 *pvEye,
             CVector3 *pvUpLeft,
             CVector3 *pvUpRight,
             CVector3 *pvLowLeft,
             CVector3 *pvLowRight);
void CViewVolume__BuildFromVectors(CViewVolume *pThis,
             CVector3 *pvEye,
             CVector3 *pvUpLeft,
             CVector3 *pvUpRight,
             CVector3 *pvLowLeft,
             CVector3 *pvLowRight){
 CPlane__BuildFromVectors(&pThis->m_Planes[0], pvUpLeft, pvUpRight, pvLowRight);
 pThis->m_Planes[1].m_vNormal.x = -pThis->m_Planes[0].m_vNormal.x;
 pThis->m_Planes[1].m_vNormal.y = -pThis->m_Planes[0].m_vNormal.y;
 pThis->m_Planes[1].m_vNormal.z = -pThis->m_Planes[0].m_vNormal.z;
 pThis->m_Planes[1].m_vPoint = *pvEye;
 CPlane__BuildFromVectors(&pThis->m_Planes[2], pvEye, pvUpLeft, pvLowLeft);
 CPlane__BuildFromVectors(&pThis->m_Planes[3], pvEye, pvLowRight, pvUpRight);
 CPlane__BuildFromVectors(&pThis->m_Planes[4], pvEye, pvUpRight, pvUpLeft);
 CPlane__BuildFromVectors(&pThis->m_Planes[5], pvEye, pvLowLeft, pvLowRight);
}
