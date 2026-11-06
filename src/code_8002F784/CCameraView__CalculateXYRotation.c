#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern float CVector3__XZAngle(CVector3 *pThis) ;
extern float CVector3__XYAngle(CVector3 *pThis) ;
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
extern void CCameraView__CalculateXYRotation(CCameraView *pThis) ;
void CCameraView__CalculateXYRotation(CCameraView *pThis);
void CCameraView__CalculateXYRotation(CCameraView *pThis){
 CVector3 vLookDir ;
 vLookDir.x = pThis->m_vFocus.x - pThis->m_vEye.x ;
 vLookDir.y = pThis->m_vFocus.y - pThis->m_vEye.y ;
 vLookDir.z = pThis->m_vFocus.z - pThis->m_vEye.z ;
 pThis->m_vRotation.x = -CVector3__XYAngle(&vLookDir) ;
 pThis->m_vRotation.y = CVector3__XZAngle(&vLookDir) ;
}
