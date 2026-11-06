#include "common.h"

extern f32 D_800F2D44;
extern void Campaigner_PlayTauntSound(void *, void *);
typedef struct { f32 x,y,z; } Vec3;
extern void AI_SEvent_GeneralSound(void *, Vec3, f32);
typedef struct { void *pad0; Vec3 v; } ObjA;
typedef struct { char pad[0x258]; f32 f258; s32 f25C; } ObjB;
void Campaigner_PlayLaughSound(ObjA *arg0, ObjB *arg1) {
 ObjB *s0=arg1;
 if(s0->f25C==0x169){Campaigner_PlayTauntSound(arg0,arg1);return;}
 if(s0->f258==0.0f){AI_SEvent_GeneralSound(arg0,arg0->v,D_800F2D44);s0->f25C=0x169;s0->f258=30.0f;}
}
