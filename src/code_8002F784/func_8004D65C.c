#include "common.h"

extern f32 D_800F2D44;
extern void func_8004D51C(void *, void *);
typedef struct { f32 x,y,z; } Vec3;
extern void func_80063AE8(void *, Vec3, f32);
typedef struct { void *pad0; Vec3 v; } ObjA;
typedef struct { char pad[0x258]; f32 f258; s32 f25C; } ObjB;
void func_8004D65C(ObjA *arg0, ObjB *arg1) {
 ObjB *s0=arg1;
 if(s0->f25C==0x169){func_8004D51C(arg0,arg1);return;}
 if(s0->f258==0.0f){func_80063AE8(arg0,arg0->v,D_800F2D44);s0->f25C=0x169;s0->f258=30.0f;}
}
