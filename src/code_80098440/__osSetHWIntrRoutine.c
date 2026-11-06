#include "common.h"

extern s32 D_800EF2A0[]; s32 __osDisableInt(void); void __osRestoreInt(s32);
void __osSetHWIntrRoutine(s32 arg0,s32 arg1){register s32 tmp;
tmp=__osDisableInt();
D_800EF2A0[arg0]=arg1;__osRestoreInt(tmp);}
