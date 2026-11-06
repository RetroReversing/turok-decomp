#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef struct CBoundsRect_t
{
 float m_MinX, m_MinZ,
      m_MaxX, m_MaxZ;
} CBoundsRect;
extern void CBoundsRect__AddEncloseVectors(CBoundsRect *bounds, int pointCount, CVector3 points[]);
void CBoundsRect__AddEncloseVectors(CBoundsRect *bounds, int pointCount, CVector3 points[]);
 /* Expand an XZ bounds rectangle to contain each point in the array. */
void CBoundsRect__AddEncloseVectors(CBoundsRect *pThis, int nPts, CVector3 V[]){
 int point;
 for (point=0; point<nPts; point++)
 {
  pThis->m_MinX = ((pThis->m_MinX) < (V[point].x) ? (pThis->m_MinX) : (V[point].x));
  pThis->m_MinZ = ((pThis->m_MinZ) < (V[point].z) ? (pThis->m_MinZ) : (V[point].z));
  pThis->m_MaxX = ((pThis->m_MaxX) > (V[point].x) ? (pThis->m_MaxX) : (V[point].x));
  pThis->m_MaxZ = ((pThis->m_MaxZ) > (V[point].z) ? (pThis->m_MaxZ) : (V[point].z));
 }
}
