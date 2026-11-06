#include "common.h"

typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} V3;
typedef struct 
{
  s32 pad;
  f32 x;
  f32 y;
  f32 z;
} V4;
extern f64 D_800F1E38;
extern f32 __sinf(f32);
extern f32 __cosf(f32);
extern s32 CAnimInstanceHdr__IsObstructed(void *, V3, s32);
s32 CGameObjectInstance__CylinderCollisionFree(V4 *p, f32 r)
{
  f32 a;
  V3 v;
  s32 i;
  v.y = p->y;
 a = 0; i = 10; do { v.x = (__sinf(a) * r) + p->x; v.z = (__cosf(a) * r) + p->z; if (CAnimInstanceHdr__IsObstructed(p, v, 0) != 0) { return 0; }
    a += 0.19198621771937624;
  }
  while (i--);
  return 1;
}
