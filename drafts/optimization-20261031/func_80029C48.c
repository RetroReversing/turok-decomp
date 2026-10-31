#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct { u8 pad[0xA8]; void *tablePtr; } Obj;
typedef struct { u8 pad0[0x38]; u16 first; u8 pad3A[0x1A]; u16 second; u8 pad56[0x1A]; u16 third; } Entry;
typedef struct { u8 pad[0xB8]; void *model; } Obj2;
typedef struct { u8 pad0[0x34]; s32 field34; } Model;
extern s32 func_8002814C(void); extern void CParticle__Spawn(void *,s32,s32);
typedef struct { f32 x,y,z; } Vec3; extern void func_80070DA8(void *,void *,s32,s32,Vec3,f32);
extern void func_80031974(void *,s32,s32,void *,void *,s32);
extern u8 D_800FA3C8[];
void func_80029C48(Obj *arg0) {
 void *data=arg0->tablePtr; s32 i; u32 *base; Entry *entry; s32 a,b,c; f32 f;
 i=func_8002814C()?12:10; base=*(u32 **)data; entry=(Entry *)((u8 *)base+i*2);
 a=entry->first; b=entry->second; c=entry->third; f=*(f32 *)((u8 *)base+i*4);
 if(a!=0xFFFF) { CParticle__Spawn(arg0,a,1); c=entry->third; f=*(f32 *)((u8 *)base+i*4); }
 if(b!=0xFFFF) { func_80070DA8(arg0,((Obj2 *)arg0)->model,b,-1,*(Vec3 *)((u8 *)arg0+4),f); c=entry->third; }
 if(c!=0xFFFF) func_80031974(D_800FA3C8,c,0,arg0,(u8 *)arg0+4,0);
}
