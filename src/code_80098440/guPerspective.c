#include "common.h"

void guPerspectiveF(void *, s32, f32, f32, f32, f32, f32); s32 guMtxF2L(void *, s32); void guPerspective(s32 a,s32 b,f32 c,f32 d,f32 e,f32 f,f32 g){u8 tmp[0x40];guPerspectiveF(tmp,b,c,d,e,f,g);guMtxF2L(tmp,a);}
