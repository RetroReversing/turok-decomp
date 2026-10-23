#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef struct CPlane_t
{
 CVector3 m_vPoint,
     m_vNormal;
} CPlane;
extern int func_800846A4(CPlane *pThis, CVector3 *pvPoint);
typedef struct CViewVolume_t
{
 CPlane m_Planes[6];
} CViewVolume;
extern int func_800848C0(CViewVolume *pThis, CVector3 *pvPoint);
int func_800846A4(CPlane *pThis, CVector3 *pvPoint);
int func_800848C0(CViewVolume *pThis, CVector3 *pvPoint);
int func_800848C0(CViewVolume *pThis, CVector3 *pvPoint){
 int p;
                ;
 for (p=0; p<6; p++)
  if (!func_800846A4(&pThis->m_Planes[p], pvPoint))
   return 0;
 return 1;
}
