#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct Timer {struct Timer *next,*prev;u64 interval,value;void *mq,*msg;} Timer;
extern Timer *D_800EF2C0;u64 D_80138F50;extern u32 D_80138F58,D_80138F5C;
void __osTimerServicesInit(void)
{
 D_80138F50=0;
 D_80138F58=0;
 D_80138F5C=0;
 D_800EF2C0->next=D_800EF2C0->prev=D_800EF2C0;
 D_800EF2C0->interval=D_800EF2C0->value=(u64)0;
 D_800EF2C0->mq=0;
 D_800EF2C0->msg=0;
}

