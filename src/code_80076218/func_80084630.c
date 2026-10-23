#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void func_800144C8(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
extern void func_80013BBC(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
typedef struct CPlane_t
{
 CVector3 m_vPoint,
     m_vNormal;
} CPlane;
extern void func_80084630(CPlane *pThis, CVector3 *pvA, CVector3 *pvB, CVector3 *pvC);
void func_80084630(CPlane *pThis, CVector3 *pvA, CVector3 *pvB, CVector3 *pvC);
void func_80084630(CPlane *pThis, CVector3 *pvA, CVector3 *pvB, CVector3 *pvC){
 CVector3 vAB, vBC;
                          ;
 pThis->m_vPoint = *pvA;
 func_800144C8(&vAB, pvB, pvA);
 func_800144C8(&vBC, pvC, pvB);
 func_80013BBC(&pThis->m_vNormal, &vAB, &vBC);
}
