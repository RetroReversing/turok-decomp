#include "common.h"

typedef struct { f32 x,y,z; } Vec3; extern s32 D_800B9724; extern f32 D_80119D70,D_80119D74,D_80119D78; extern void CGameRegion__GetCeilingNormal(Vec3 *); extern void CVector3__Normalize(Vec3 *); Vec3 *CGameRegion__GetCeilingUnitNormal(Vec3 * volatile out,s32 mode) { if(mode==0) { D_80119D70=0.0f; D_80119D74=-1.0f; D_80119D78=0.0f; } else if(mode!=D_800B9724) { CGameRegion__GetCeilingNormal((Vec3 *)&D_80119D70); CVector3__Normalize((Vec3 *)&D_80119D70); }
D_800B9724=mode;
*out=*(Vec3 *)&D_80119D70;
return out; }
