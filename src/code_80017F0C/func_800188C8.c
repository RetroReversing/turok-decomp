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
extern void func_800188C8(CBoundsRect *bounds, int pointCount, CVector3 points[]);
void func_800188C8(CBoundsRect *bounds, int pointCount, CVector3 points[]);
 /* Expand an XZ bounds rectangle to contain each point in the array. */
void func_800188C8(CBoundsRect *bounds, int pointCount, CVector3 points[]){
 int point;
 for (point=0; point<pointCount; point++)
 {
  bounds->m_MinX = ((bounds->m_MinX) < (points[point].x) ? (bounds->m_MinX) : (points[point].x));
  bounds->m_MinZ = ((bounds->m_MinZ) < (points[point].z) ? (bounds->m_MinZ) : (points[point].z));
  bounds->m_MaxX = ((bounds->m_MaxX) > (points[point].x) ? (bounds->m_MaxX) : (points[point].x));
  bounds->m_MaxZ = ((bounds->m_MaxZ) > (points[point].z) ? (bounds->m_MaxZ) : (points[point].z));
 }
}
