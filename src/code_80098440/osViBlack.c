#include "common.h"

s32 func_800A5750(); void func_800A5770(s32);
extern u16 *D_800EF334;
void osViBlack(volatile u8 arg0) {
 register s32 result;
 result=func_800A5750();
 if(arg0) *D_800EF334 |= 0x20;
 else *D_800EF334 &= ~0x20;
 func_800A5770(result);
}
