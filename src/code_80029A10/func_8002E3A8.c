#include "common.h"

typedef struct{f32 x,y,z;} V;
extern void func_80035A74(void*,void*,V,V,void*,f32);
void func_8002E3A8(void *a0,void *a1,V a2,void *a3,f32 a4)
{
V zero;
zero.x=0.0f;
zero.y=0.0f;
zero.z=0.0f;
func_80035A74((char*)a0+0x14280,a3,zero,a2,a1,a4);
}
