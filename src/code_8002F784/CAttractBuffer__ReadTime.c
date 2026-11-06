#include "common.h"

s32 CAttractBuffer__ReadBits(u8*,s32);
void CAttractBuffer__ReadTime(u8*a){s32 v;v=CAttractBuffer__ReadBits(a,3);if(v){*(s32*)(a+12)=CAttractBuffer__ReadBits(a,v)+1;}else{*(s32*)(a+12)=1;}}
