#include "common.h"

typedef struct { s32 x,y,z; } V3;
typedef struct { f32 a,b,c,d; } Rot;
extern void *D_800B9728;
extern f32 D_80119D80,D_80119D84,D_80119D88;
extern void func_800144C8(V3 *, f32, f32);
extern void func_80013BBC(V3 *, V3 *, V3 *);
V3 *func_80019C78(V3 *out, Rot *r) {
 V3 x,y;
 if (!r) {
  D_80119D80=0; D_80119D84=1; D_80119D88=0;
 } else if (r != D_800B9728) {
  func_800144C8(&x,r->c,r->b);
  func_800144C8(&y,r->d,r->c);
  func_80013BBC((V3 *)&D_80119D80,&x,&y);
 }
 D_800B9728=r;
 *out=*(V3 *)&D_80119D80;
 return out;
}
