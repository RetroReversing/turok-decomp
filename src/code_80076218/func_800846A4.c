#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void func_800144C8(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
typedef struct CPlane_t
{
 CVector3 m_vPoint,
     m_vNormal;
} CPlane;
extern int func_800846A4(CPlane *pThis, CVector3 *pvPoint);
int func_800846A4(CPlane *pThis, CVector3 *pvPoint);
int func_800846A4(CPlane *pThis, CVector3 *pvPoint){
 CVector3 vDelta;
 func_800144C8(&vDelta, pvPoint, &pThis->m_vPoint);
 return (((&pThis->m_vNormal)->x*(&vDelta)->x + (&pThis->m_vNormal)->y*(&vDelta)->y + (&pThis->m_vNormal)->z*(&vDelta)->z) >= 0);
}
