#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef struct CLine_t
{
 CVector3 m_vPt[2] ;
 CVector3 m_vDelta ;
 CVector3 m_vDir ;
 CVector3 m_vNormal ;
} CLine ;
extern int func_80098BB8(CLine *pThis, CLine *pLine, float *pt) ;
int func_80098BB8(CLine *pThis, CLine *pLine, float *pt);
int func_80098BB8(CLine *pThis, CLine *pLine, float *pt){
 CVector3 vAS ;
 float ASDotN, MDotN ;
 vAS.x = pLine->m_vPt[0].x - pThis->m_vPt[0].x ;
 vAS.z = pLine->m_vPt[0].z - pThis->m_vPt[0].z ;
 MDotN = (pLine->m_vDelta.x * pThis->m_vNormal.x) + (pLine->m_vDelta.z * pThis->m_vNormal.z) ;
 if (MDotN == 0)
  return 0 ;
 ASDotN = (vAS.x * pThis->m_vNormal.x) + (vAS.z * pThis->m_vNormal.z) ;
 *pt = ASDotN / -MDotN ;
 return 1 ;
}
