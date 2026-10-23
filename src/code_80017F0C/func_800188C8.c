#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef struct CBoundsRect_t
{
 float m_MinX, m_MinZ,
      m_MaxX, m_MaxZ;
} CBoundsRect;
extern void func_800188C8(CBoundsRect *pThis, int nPts, CVector3 V[]);
void func_800188C8(CBoundsRect *pThis, int nPts, CVector3 V[]);
void func_800188C8(CBoundsRect *pThis, int nPts, CVector3 V[]){
 int p;
 for (p=0; p<nPts; p++)
 {
  pThis->m_MinX = ((pThis->m_MinX) < (V[p].x) ? (pThis->m_MinX) : (V[p].x));
  pThis->m_MinZ = ((pThis->m_MinZ) < (V[p].z) ? (pThis->m_MinZ) : (V[p].z));
  pThis->m_MaxX = ((pThis->m_MaxX) > (V[p].x) ? (pThis->m_MaxX) : (V[p].x));
  pThis->m_MaxZ = ((pThis->m_MaxZ) > (V[p].z) ? (pThis->m_MaxZ) : (V[p].z));
 }
}
