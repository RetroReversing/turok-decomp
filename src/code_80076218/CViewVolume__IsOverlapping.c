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
extern int CPlane__Inside(CPlane *pThis, CVector3 *pvPoint);
typedef struct CViewVolume_t
{
 CPlane m_Planes[6];
} CViewVolume;
extern int CViewVolume__IsOverlapping(CViewVolume *pThis, int nPts, CVector3 V[]);
int CPlane__Inside(CPlane *pThis, CVector3 *pvPoint);
int CViewVolume__IsOverlapping(CViewVolume *pThis, int nPts, CVector3 V[]);
int CViewVolume__IsOverlapping(CViewVolume *pThis, int nPts, CVector3 V[]){
 int cPlane, cPoint;
 CPlane *pPlane;
 int anyInside;
 for (cPlane=0; cPlane<6; cPlane++)
 {
  pPlane = &pThis->m_Planes[cPlane];
  anyInside = 0;
  for (cPoint=0; cPoint<nPts; cPoint++)
  {
   if (CPlane__Inside(pPlane, &V[cPoint]))
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
