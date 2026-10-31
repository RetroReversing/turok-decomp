#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef u64 OSTime;
typedef struct OSTimer {struct OSTimer *next,*prev;OSTime interval,value;void *mq,*msg;} OSTimer;
extern OSTimer *D_800EF2C0;extern u32 D_80138F60;
u32 func_800A5750(void);void func_800A5770(u32);u32 func_800A60D0(void);void func_800AFDC0(u32);void __osSetTimerIntr(OSTime);OSTime __osInsertTimer(OSTimer*);s32 osSendMesg(void*,void*,s32);
#define __osDisableInt func_800A5750
#define __osRestoreInt func_800A5770
#define osGetCount func_800A60D0
#define __osSetCompare func_800AFDC0
#define __osTimerList D_800EF2C0
#define __osTimerCounter D_80138F60
#define _FINALROM 1
#define OS_MESG_NOBLOCK 0
#line 188 "TIMERINTR.C"
OSTime
__osInsertTimer(OSTimer *t)
{
    OSTimer *timep;
    OSTime  tim;
    u32 savedMask;

    /* disable interrupts */

    savedMask = __osDisableInt();

    /* Insert the new timer into the sorted list */

    timep = __osTimerList->next;
    tim = t->value;

    for ( ; (timep != __osTimerList) && (tim > timep->value);
		timep = timep->next)
	tim -= timep->value;
    t->value = tim;
    if (timep != __osTimerList)
	timep->value -= tim;	/* Subtract off tim from the  */
    /* timer next to the new insted timer */
    t->next = timep;
    t->prev = timep->prev;
    timep->prev->next = t;
    timep->prev = t;

    __osRestoreInt(savedMask);

    return(tim);
}

