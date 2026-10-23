#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef struct CROMBounds_t
{
 CVector3 m_vMin, m_vMax;
} CROMBounds;
typedef struct CPlane_t
{
 CVector3 m_vPoint,
     m_vNormal;
} CPlane;
typedef struct CViewVolume_t
{
 CPlane m_Planes[6];
} CViewVolume;
extern int func_8008492C(CViewVolume *pThis, int nPts, CVector3 V[]);
extern int func_80084ACC(CViewVolume *pThis, CROMBounds *pBounds);
int func_8008492C(CViewVolume *pThis, int nPts, CVector3 V[]);
int func_80084ACC(CViewVolume *pThis, CROMBounds *pBounds);
int func_80084ACC(CViewVolume *pThis, CROMBounds *pBounds){
 CVector3 vCorners[8];
   vCorners[0].x = pBounds->m_vMin.x;
 vCorners[0].y = pBounds->m_vMin.y;
 vCorners[0].z = pBounds->m_vMin.z;
   vCorners[1].x = pBounds->m_vMax.x;
 vCorners[1].y = pBounds->m_vMin.y;
 vCorners[1].z = pBounds->m_vMin.z;
 vCorners[2].x = pBounds->m_vMax.x;
 vCorners[2].y = pBounds->m_vMin.y;
 vCorners[2].z = pBounds->m_vMax.z;
   vCorners[3].x = pBounds->m_vMin.x;
 vCorners[3].y = pBounds->m_vMin.y;
 vCorners[3].z = pBounds->m_vMax.z;
   vCorners[4].x = pBounds->m_vMin.x;
 vCorners[4].y = pBounds->m_vMax.y;
 vCorners[4].z = pBounds->m_vMin.z;
 vCorners[5].x = pBounds->m_vMax.x;
 vCorners[5].y = pBounds->m_vMax.y;
 vCorners[5].z = pBounds->m_vMin.z;
   vCorners[6].x = pBounds->m_vMax.x;
 vCorners[6].y = pBounds->m_vMax.y;
 vCorners[6].z = pBounds->m_vMax.z;
 vCorners[7].x = pBounds->m_vMin.x;
 vCorners[7].y = pBounds->m_vMax.y;
 vCorners[7].z = pBounds->m_vMax.z;
 return func_8008492C(pThis, 8, vCorners);
}
