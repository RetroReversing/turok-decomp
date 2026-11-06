#include "common.h"

typedef struct { s32 x,y,z; } V3;
typedef struct { f32 a,b,c,d; } Rot;
extern void *D_800B9728;
extern f32 D_80119D80,D_80119D84,D_80119D88;
extern void CVector3__Subtract(V3 *, f32, f32);
extern void CVector3__Cross(V3 *, V3 *, V3 *);
V3 *CGameRegion__GetGroundNormal(V3 *out, Rot *r) {
 V3 x,y;
 if (!r) {
  D_80119D80=0; D_80119D84=1; D_80119D88=0;
 } else if (r != D_800B9728) {
  CVector3__Subtract(&x,r->c,r->b);
  CVector3__Subtract(&y,r->d,r->c);
  CVector3__Cross((V3 *)&D_80119D80,&x,&y);
 }
 D_800B9728=r;
 *out=*(V3 *)&D_80119D80;
 return out;
}
