#include "common.h"

s32 func_800A5750(void); s32 func_800A5770(s32);
extern void *D_800EF334;
void func_8009DB10(void *arg0) {
 register s32 temp_v0;
 temp_v0=func_800A5750();
 *(void **)((s8*)D_800EF334+8)=arg0;
 *(s16*)D_800EF334=1;
 *(s32*)((s8*)D_800EF334+12)=*(s32*)((s8*)*(void**)((s8*)D_800EF334+8)+4);
 func_800A5770(temp_v0);
}
