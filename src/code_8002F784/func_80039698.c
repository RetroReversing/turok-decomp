#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void func_80040B54(float *pVar, float Target, float Speed) ;
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
extern void func_80039698(CCameraView *pThis, CVector3 *pvPos, float Speed) ;
void func_80039698(CCameraView *pThis, CVector3 *pvPos, float Speed);
void func_80039698(CCameraView *pThis, CVector3 *pvPos, float Speed){
 func_80040B54(&pThis->m_vFocus.x, pvPos->x, Speed) ;
 func_80040B54(&pThis->m_vFocus.y, pvPos->y, Speed) ;
 func_80040B54(&pThis->m_vFocus.z, pvPos->z, Speed) ;
}
