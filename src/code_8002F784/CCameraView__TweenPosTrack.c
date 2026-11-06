#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void CVector3__Blend(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
typedef struct CCameraPosTrackInfo_t
{
 CVector3 m_vStartEye, m_vFinalEye ;
 CVector3 m_vStartFocus, m_vFinalFocus ;
 CVector3 m_vStartRotation, m_vFinalRotation ;
} CCameraPosTrackInfo ;
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
extern void CCameraView__TweenPosTrack(CCameraView *pThis, CCameraPosTrackInfo *pInfo, float Time) ;
void CCameraView__TweenPosTrack(CCameraView *pThis, CCameraPosTrackInfo *pInfo, float Time);
void CCameraView__TweenPosTrack(CCameraView *pThis, CCameraPosTrackInfo *pInfo, float Time){
 if (Time < 0)
  Time = 0 ;
 else
 if (Time > 1)
  Time = 1 ;
 CVector3__Blend(&pThis->m_vEye, Time, &pInfo->m_vStartEye, &pInfo->m_vFinalEye) ;
 CVector3__Blend(&pThis->m_vFocus, Time, &pInfo->m_vStartFocus, &pInfo->m_vFinalFocus) ;
 CVector3__Blend(&pThis->m_vRotation, Time, &pInfo->m_vStartRotation, &pInfo->m_vFinalRotation) ;
}
