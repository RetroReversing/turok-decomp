#include "common.h"

u32 func_800A4F30(s32); s32 func_800AAFA0(void);
#define D_A4100000 (*(volatile u32 *)0xA4100000)
#define D_A4100004 (*(volatile u32 *)0xA4100004)
#define D_A410000C (*(volatile u32 *)0xA410000C)
s32 func_800A1610(volatile s32 arg0,u64 arg1) {
register u32 status;
if(func_800AAFA0())return -1;
D_A410000C=1;
do {status=D_A410000C;}while(status&1);
D_A4100000=func_800A4F30(arg0);
D_A4100004=func_800A4F30(arg0)+arg1;
return 0;
}
