#include "common.h"

typedef struct {f32 x,y,z;} Vec3;
extern void CVector3__Add(void*,void*,void*); extern void CQuatern__ToMatrix(void*,void*); extern void CMtxF__VectorMult(void*,void*,void*); extern void CInstanceHdr__GetNearPositionAndRegion(s32,Vec3,s32,s32,s32,s32); extern void CGameObjectInstance__GetAimRotation(void*,s32);
extern s32 D_8010201C; extern u8 D_80119664[];
void func_8001DCF8(s32 obj,Vec3 direction,s32 arg4,s32 arg5) {
 struct { Vec3 transformed; u8 inverse[0x40]; u8 rotation[0x18]; Vec3 temp; u8 pad[4]; Vec3 result; Vec3 translated; } loc;
 if(obj==D_8010201C) {
    direction.x=-direction.x; direction.z=-direction.z;
    CMtxF__VectorMult(D_80119664,&direction,&loc.result);
 } else {
    loc.temp = direction;
    CGameObjectInstance__GetAimRotation(&loc.rotation,obj);
    CQuatern__ToMatrix(&loc.rotation,&loc.inverse);
    CMtxF__VectorMult(&loc.inverse,&loc.temp,&loc.transformed);
    loc.translated=loc.transformed;
    CVector3__Add(&loc.result,(void *)(obj+4),&loc.translated);
 }
 CInstanceHdr__GetNearPositionAndRegion(obj,loc.result,arg4,arg5,1,1);
}
