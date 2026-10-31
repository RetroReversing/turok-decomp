#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct { f32 x,y,z; } V3;
typedef struct { s32 x,y,z; } I3;
extern void func_80013B2C(V3*);
extern void func_80013BBC(V3*,s32,s32);
extern void func_80013C2C(I3*,V3*,f32);
void func_80013FD8(I3 *out,V3 *v,s32 x,s32 y) {
    V3 tmp;
    I3 q;
    f32 dot;
    func_80013BBC(&tmp,x,y);
    func_80013B2C(&tmp);
    dot = v->x*tmp.x + v->y*tmp.y + v->z*tmp.z;
    func_80013C2C(&q,&tmp,dot);
    *out=q;
}
