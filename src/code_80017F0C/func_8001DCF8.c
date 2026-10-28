#include "common.h"

typedef struct {f32 x,y,z;} Vec3;
extern void func_800144FC(void*,void*,void*); extern void func_80014DC4(void*,void*); extern void func_80015754(void*,void*,void*); extern void func_80017F0C(s32,Vec3,s32,s32,s32,s32); extern void func_8001D464(void*,s32);
extern s32 D_8010201C; extern u8 D_80119664[];
void func_8001DCF8(s32 obj,Vec3 direction,s32 arg4,s32 arg5) {
 struct { Vec3 transformed; u8 inverse[0x40]; u8 rotation[0x18]; Vec3 temp; u8 pad[4]; Vec3 result; Vec3 translated; } loc;
 if(obj==D_8010201C) {
    direction.x=-direction.x; direction.z=-direction.z;
    func_80015754(D_80119664,&direction,&loc.result);
 } else {
    loc.temp = direction;
    func_8001D464(&loc.rotation,obj);
    func_80014DC4(&loc.rotation,&loc.inverse);
    func_80015754(&loc.inverse,&loc.temp,&loc.transformed);
    loc.translated=loc.transformed;
    func_800144FC(&loc.result,(void *)(obj+4),&loc.translated);
 }
 func_80017F0C(obj,loc.result,arg4,arg5,1,1);
}
