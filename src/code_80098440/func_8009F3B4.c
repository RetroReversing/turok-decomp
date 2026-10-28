#include "common.h"

s32 func_8009F3B4(s32 arg0,s32 arg1) {
 extern u8 D_80137C90; extern void func_8009F130(s32); extern s32 func_800A8590(s32,void*);
 extern void func_8009D0B0(s32,s32*,s32); extern void func_8009F22C(u8*,u8*);
 s32 sp34=0,sp30; u8 sp2F; u8 sp1C[16];
 func_8009F130(0); sp34=func_800A8590(1,&D_80137C90); func_8009D0B0(arg0,&sp30,1);
 sp34=func_800A8590(0,&D_80137C90); func_8009D0B0(arg0,&sp30,1); func_8009F22C(&sp2F,sp1C);
 if ((sp1C[arg1*4+2]&1) && (sp1C[arg1*4+2]&2)) return 2;
 if (((volatile u8*)sp1C)[arg1*4+3] || !(((volatile u8*)sp1C)[arg1*4+2]&1)) return 1;
 if (((volatile u8*)sp1C)[arg1*4+2]&4) return 4;
 return sp34;
}
