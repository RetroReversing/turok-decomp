#include "common.h"

extern float __sinf(float angle);
extern float __cosf(float angle);
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef struct CCameraTrackInfo_t
{
 float m_StartYRotOffset, m_FinalYRotOffset ;
 float m_StartRadius, m_FinalRadius ;
 float m_StartEyeYOffset, m_FinalEyeYOffset ;
 float m_StartFocusYOffset, m_FinalFocusYOffset ;
} CCameraTrackInfo ;
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
extern void func_80039494(CCameraView *pThis, CCameraTrackInfo *pInfo, float Time, CVector3 *pvPos, float RotYOffset) ;
void func_80039494(CCameraView *pThis, CCameraTrackInfo *pInfo, float Time, CVector3 *pvPos, float RotYOffset);
void func_80039494(CCameraView *pThis, CCameraTrackInfo *pInfo, float Time, CVector3 *pvPos, float RotYOffset){
 float Rot ;
 if (Time < 0)
  Time = 0 ;
 else
 if (Time > 1)
  Time = 1 ;
 pThis->m_YRotOffset = ((pInfo->m_StartYRotOffset) + (Time)*(((float)(pInfo->m_FinalYRotOffset)) - (pInfo->m_StartYRotOffset))) ;
 pThis->m_Radius = ((pInfo->m_StartRadius) + (Time)*(((float)(pInfo->m_FinalRadius)) - (pInfo->m_StartRadius))) ;
 pThis->m_EyeYOffset = ((pInfo->m_StartEyeYOffset) + (Time)*(((float)(pInfo->m_FinalEyeYOffset)) - (pInfo->m_StartEyeYOffset))) ;
 pThis->m_FocusYOffset = ((pInfo->m_StartFocusYOffset) + (Time)*(((float)(pInfo->m_FinalFocusYOffset)) - (pInfo->m_StartFocusYOffset))) ;
 Rot = RotYOffset + pThis->m_YRotOffset ;
 pThis->m_vEye.x = pvPos->x - (pThis->m_Radius * __sinf(Rot)) ;
 pThis->m_vEye.y = pvPos->y + pThis->m_EyeYOffset ;
 pThis->m_vEye.z = pvPos->z - (pThis->m_Radius * __cosf(Rot)) ;
 pThis->m_vFocus.x = pvPos->x ;
 pThis->m_vFocus.y = pvPos->y + pThis->m_FocusYOffset ;
 pThis->m_vFocus.z = pvPos->z ;
}
