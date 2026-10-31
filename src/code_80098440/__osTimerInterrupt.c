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
#line 72 "TIMERINTR.C"
void
__osTimerInterrupt(void)
{
    OSTimer *t;
    u32	count, elapsed_cycles;

#ifndef _FINALROM
    /* profiler stuff */
    u32 pc;
    s32 offset;
    OSProf *prof = __osProfileList;
#endif 


    if (__osTimerList->next == __osTimerList)
	/* there is no active timer */
	return;

    for (;;) {
	t = __osTimerList->next;
	if (t == __osTimerList) {
	    /* timer list has been emptied */
	    __osSetCompare(0);
	    __osTimerCounter = 0;
	    break;
	}

	/* Compute time since timer was set */

	count = osGetCount();
	elapsed_cycles = count - __osTimerCounter;
	/* Have enough ticks gone by since timer was set? */
	__osTimerCounter = count;

	if ((OSTime)elapsed_cycles < t->value) {

	    /* not yet ready for next item on list */

	    t->value -= (OSTime)elapsed_cycles;
	    __osSetTimerIntr(t->value);
	    break;
	}

	/* Remove head of the list and process it */

	t->prev->next = t->next;
	t->next->prev = t->prev;
	t->next = NULL;
	t->prev = NULL;

	/* Send signal to wake up waiting threads */

	if (t->mq != NULL) {
#ifdef _FINALROM
	    (void)osSendMesg(t->mq, t->msg, OS_MESG_NOBLOCK);
	}
#else
	    if (t->mq != &__osProfTimerQ) {
		(void)osSendMesg(t->mq, t->msg, OS_MESG_NOBLOCK);
	    }
	    else {

		/*
		 *  Determine which bin to put pc in.
		 */

		pc = __osRunQueue->context.pc;

		for (prof = __osProfileList;
			prof < __osProfileListEnd; prof++) {
		    offset = (s32) (pc - (u32)prof->text_start);
		    if ((offset >= 0) && 
		        	((s32)((u32)(prof->text_end) - pc) > 0)) {
			++*((u16 *) ((offset >> 2) + prof->histo_base));
			goto __ProfDone;
		    }
		}
		++__osProfileOverflowBin;
	    }
	}

__ProfDone:

#endif /* _FINALROM */


	/* 
	 * if timer is set up to reload, compute next time timer
	 * should go off and inster it to the list 
	 */
	if (t->interval) {
	    t->value = t->interval;
	    __osInsertTimer(t);
	}
    }

}

