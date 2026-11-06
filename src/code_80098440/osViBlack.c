#include "common.h"

s32 __osDisableInt(); void __osRestoreInt(s32);
extern u16 *D_800EF334;
void osViBlack(volatile u8 arg0) {
 register s32 result;
 result=__osDisableInt();
 if(arg0) *D_800EF334 |= 0x20;
 else *D_800EF334 &= ~0x20;
 __osRestoreInt(result);
}
