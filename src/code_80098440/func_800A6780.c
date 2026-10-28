#include "common.h"

extern s32 D_800EF2A0[]; s32 func_800A5750(void); void func_800A5770(s32);
void func_800A6780(s32 arg0,s32 arg1){register s32 tmp;
tmp=func_800A5750();
D_800EF2A0[arg0]=arg1;func_800A5770(tmp);}
