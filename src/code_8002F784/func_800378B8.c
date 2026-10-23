#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern float func_80013A24(CVector3 *pThis) ;
extern float func_800139A8(CVector3 *pThis) ;
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
extern void func_800378B8(CCameraView *pThis) ;
void func_800378B8(CCameraView *pThis);
void func_800378B8(CCameraView *pThis){
 CVector3 vLookDir ;
 vLookDir.x = pThis->m_vFocus.x - pThis->m_vEye.x ;
 vLookDir.y = pThis->m_vFocus.y - pThis->m_vEye.y ;
 vLookDir.z = pThis->m_vFocus.z - pThis->m_vEye.z ;
 pThis->m_vRotation.x = -func_800139A8(&vLookDir) ;
 pThis->m_vRotation.y = func_80013A24(&vLookDir) ;
}
