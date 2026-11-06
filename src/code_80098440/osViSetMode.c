#include "common.h"

s32 __osDisableInt(void); s32 __osRestoreInt(s32);
extern void *D_800EF334;
void osViSetMode(void *arg0) {
 register s32 temp_v0;
 temp_v0=__osDisableInt();
 *(void **)((s8*)D_800EF334+8)=arg0;
 *(s16*)D_800EF334=1;
 *(s32*)((s8*)D_800EF334+12)=*(s32*)((s8*)*(void**)((s8*)D_800EF334+8)+4);
 __osRestoreInt(temp_v0);
}
