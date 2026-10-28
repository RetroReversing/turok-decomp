#include "common.h"

s32 func_800A5750(); void func_800A5770(s32);
extern void *D_800EF334;
void func_800A1110(volatile s32 arg0, volatile s32 arg1, volatile s32 arg2) {
 register s32 result;
 result = func_800A5750();
 *(s32 *)((u8 *)D_800EF334+0x10)=arg0;
 *(s32 *)((u8 *)D_800EF334+0x14)=arg1;
 *(s16 *)((u8 *)D_800EF334+2)=arg2;
 func_800A5770(result);
}
