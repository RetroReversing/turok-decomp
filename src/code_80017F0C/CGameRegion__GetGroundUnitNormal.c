#include "common.h"

typedef struct { f32 x,y,z; } Vec3; extern s32 D_800B972C; extern f32 D_80119D90,D_80119D94,D_80119D98; extern void CGameRegion__GetGroundNormal(Vec3 *); extern void CVector3__Normalize(Vec3 *); Vec3 *CGameRegion__GetGroundUnitNormal(Vec3 * volatile out,s32 mode) { if(mode==0) { D_80119D90=0.0f; D_80119D94=1.0f; D_80119D98=0.0f; } else if(mode!=D_800B972C) { CGameRegion__GetGroundNormal((Vec3 *)&D_80119D90); CVector3__Normalize((Vec3 *)&D_80119D90); }
D_800B972C=mode;
*out=*(Vec3 *)&D_80119D90;
return out; }
