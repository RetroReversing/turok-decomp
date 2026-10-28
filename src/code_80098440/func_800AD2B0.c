#include "common.h"

extern f32 D_800F74A0,D_800F74A4;
f32 func_800AD2B0(s32 n) { f32 x=1.0f,y; if(n>=0) { y=D_800F74A0; } else { y=D_800F74A4; n=-n; } if(n) do { if(n&1)x=x*y; n>>=1; y=y*y; } while(n); return x; }
