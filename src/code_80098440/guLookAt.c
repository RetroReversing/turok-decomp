#include "common.h"
#line 1 "func.c"
extern void guLookAtF(void*,f32,f32,f32,f32,f32,f32,f32,f32,f32); extern void guMtxF2L(void*,s32); void guLookAt(s32 arg0,f32 a,f32 b,f32 c,f32 d,f32 e,f32 f,f32 g,f32 h,f32 i){u8 tmp[64];guLookAtF(tmp,a,b,c,d,e,f,g,h,i);guMtxF2L(tmp,arg0);}
