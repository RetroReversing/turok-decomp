#include "common.h"

extern s32 func_800ACBAC(s32,void*,s32);
void func_800A4B80(s32 a0,s32 a1){
 struct {s16 type,pad; s32 value; s32 rest[2];} x;
 x.type=13;
 x.value=a1;
 func_800ACBAC(a0+0x48,&x,0);
}
