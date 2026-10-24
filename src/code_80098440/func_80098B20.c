#include "common.h"

extern float func_8009E7A0(float value);
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
extern void func_80098B20(CLine *pThis) ;
void func_80098B20(CLine *pThis);
void func_80098B20(CLine *pThis){
 float Mag ;
 Mag = (pThis->m_vDelta.x * pThis->m_vDelta.x) + (pThis->m_vDelta.z * pThis->m_vDelta.z) ;
 if (Mag != 0)
 {
  Mag = 1 / func_8009E7A0(Mag) ;
  pThis->m_vDir.x = pThis->m_vDelta.x * Mag ;
  pThis->m_vDir.y = pThis->m_vDelta.y * Mag ;
  pThis->m_vDir.z = pThis->m_vDelta.z * Mag ;
 }
 else
 {
  pThis->m_vDir.x = 0 ;
  pThis->m_vDir.y = 0 ;
  pThis->m_vDir.z = 0 ;
 }
}
