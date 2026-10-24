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
extern void func_80098AA0(CLine *pThis, CVector3 *pvPt1, CVector3 *pvPt2) ;
void func_80098AA0(CLine *pThis, CVector3 *pvPt1, CVector3 *pvPt2);
void func_80098AA0(CLine *pThis, CVector3 *pvPt1, CVector3 *pvPt2){
 pThis->m_vPt[0] = *pvPt1 ;
 pThis->m_vPt[1] = *pvPt2 ;
 pThis->m_vDelta.x = pvPt2->x - pvPt1->x ;
 pThis->m_vDelta.y = pvPt2->y - pvPt1->y ;
 pThis->m_vDelta.z = pvPt2->z - pvPt1->z ;
 pThis->m_vNormal.x = pThis->m_vDelta.z ;
 pThis->m_vNormal.y = 0 ;
 pThis->m_vNormal.z = -pThis->m_vDelta.x ;
}
