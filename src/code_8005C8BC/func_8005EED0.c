#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
extern u8 *D_8010201C;extern s32 D_801195EC;extern u8 D_800FA3C8[];
int func_80031974(void*,s32,f32,void*,void*,s32);
int func_8005EED0(u8 *obj,s32 sound,f32 radius,s32 flags)
{
 if(*obj==1 && obj!=D_8010201C) {
  if(D_801195EC & 0x100) flags |= 0x40;
  else if(D_801195EC & 0x80) flags |= 0x80;
 }
 return func_80031974(D_800FA3C8,sound,radius,obj,obj+4,flags);
}

