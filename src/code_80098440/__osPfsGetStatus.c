#include "common.h"

s32 __osPfsGetStatus(s32 arg0,s32 arg1) {
 extern u8 D_80137C90; extern void __osPfsRequestData(s32); extern s32 __osSiRawStartDma(s32,void*);
 extern void osRecvMesg(s32,s32*,s32); extern void __osContGetInitData(u8*,u8*);
 s32 sp34=0,sp30; u8 sp2F; u8 sp1C[16];
 __osPfsRequestData(0); sp34=__osSiRawStartDma(1,&D_80137C90); osRecvMesg(arg0,&sp30,1);
 sp34=__osSiRawStartDma(0,&D_80137C90); osRecvMesg(arg0,&sp30,1); __osContGetInitData(&sp2F,sp1C);
 if ((sp1C[arg1*4+2]&1) && (sp1C[arg1*4+2]&2)) return 2;
 if (((volatile u8*)sp1C)[arg1*4+3] || !(((volatile u8*)sp1C)[arg1*4+2]&1)) return 1;
 if (((volatile u8*)sp1C)[arg1*4+2]&4) return 4;
 return sp34;
}
