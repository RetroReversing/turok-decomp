#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void ProportionalZoomVarFLOAT(float *pVar, float Target, float Speed) ;
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
extern void CCameraView__ZoomFocusToPos(CCameraView *pThis, CVector3 *pvPos, float Speed) ;
void CCameraView__ZoomFocusToPos(CCameraView *pThis, CVector3 *pvPos, float Speed);
void CCameraView__ZoomFocusToPos(CCameraView *pThis, CVector3 *pvPos, float Speed){
 ProportionalZoomVarFLOAT(&pThis->m_vFocus.x, pvPos->x, Speed) ;
 ProportionalZoomVarFLOAT(&pThis->m_vFocus.y, pvPos->y, Speed) ;
 ProportionalZoomVarFLOAT(&pThis->m_vFocus.z, pvPos->z, Speed) ;
}
