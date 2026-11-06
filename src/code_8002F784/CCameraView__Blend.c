#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void CVector3__Blend(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
typedef struct CCameraView_t
{
 float m_Time ;
 CVector3 m_vEye ;
 CVector3 m_vFocus ;
 CVector3 m_vRotation ;
 float m_YRotOffset,
     m_Radius,
     m_EyeYOffset,
     m_FocusYOffset ;
} CCameraView ;
extern void CCameraView__Blend(CCameraView *pThis, float Time, CCameraView *pViewA, CCameraView *pViewB) ;
void CCameraView__Blend(CCameraView *pThis, float Time, CCameraView *pViewA, CCameraView *pViewB);
void CCameraView__Blend(CCameraView *pThis, float Time, CCameraView *pViewA, CCameraView *pViewB){
 CVector3__Blend(&pThis->m_vEye, Time, &pViewA->m_vEye, &pViewB->m_vEye) ;
 CVector3__Blend(&pThis->m_vFocus, Time, &pViewA->m_vFocus, &pViewB->m_vFocus) ;
 CVector3__Blend(&pThis->m_vRotation, Time, &pViewA->m_vRotation, &pViewB->m_vRotation) ;
}
