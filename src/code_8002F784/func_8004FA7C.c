#include "common.h"

s32 func_8004FA14(u8*,s32);
void func_8004FA7C(u8*a){s32 v;v=func_8004FA14(a,3);if(v){*(s32*)(a+12)=func_8004FA14(a,v)+1;}else{*(s32*)(a+12)=1;}}
