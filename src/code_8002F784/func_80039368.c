#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void func_800141A8(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
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
extern void func_80039368(CCameraView *pThis, float Time, CCameraView *pViewA, CCameraView *pViewB) ;
void func_80039368(CCameraView *pThis, float Time, CCameraView *pViewA, CCameraView *pViewB);
void func_80039368(CCameraView *pThis, float Time, CCameraView *pViewA, CCameraView *pViewB){
 func_800141A8(&pThis->m_vEye, Time, &pViewA->m_vEye, &pViewB->m_vEye) ;
 func_800141A8(&pThis->m_vFocus, Time, &pViewA->m_vFocus, &pViewB->m_vFocus) ;
 func_800141A8(&pThis->m_vRotation, Time, &pViewA->m_vRotation, &pViewB->m_vRotation) ;
}
