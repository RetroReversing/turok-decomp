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
extern int func_8008492C(CViewVolume *pThis, int nPts, CVector3 V[]);
int func_800846A4(CPlane *pThis, CVector3 *pvPoint);
int func_8008492C(CViewVolume *pThis, int nPts, CVector3 V[]);
int func_8008492C(CViewVolume *pThis, int nPts, CVector3 V[]){
 int cPlane, cPoint;
 CPlane *pPlane;
 int anyInside;
 for (cPlane=0; cPlane<6; cPlane++)
 {
  pPlane = &pThis->m_Planes[cPlane];
  anyInside = 0;
  for (cPoint=0; cPoint<nPts; cPoint++)
  {
   if (func_800846A4(pPlane, &V[cPoint]))
   {
    anyInside = 1;
    break;
   }
  }
  if (!anyInside)
   return 0;
 }
 return 1;
}
