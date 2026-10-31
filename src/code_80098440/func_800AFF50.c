#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct {u8 pad[12];u32 addr;} Device;
s32 func_800AFF50(Device *p,u32 addr,u32 value)
{
 register u32 status;
 status=*(volatile u32*)0xA4600010;
 while(status&3) {status=*(volatile u32*)0xA4600010;}
 *(volatile u32*)((p->addr|addr)|0xA0000000)=value;
 return 0;
}

