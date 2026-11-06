#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct OSThread {struct OSThread *next;s32 priority;struct OSThread **queue;struct OSThread *tlnext;u16 state;} OSThread;
typedef void *OSMesg;
typedef struct {OSThread *mtqueue,*fullqueue;s32 validCount,first,msgCount;OSMesg *msg;} OSMesgQueue;
extern OSThread *D_800EF290,*D_800EF288;
u32 __osDisableInt(void);void __osRestoreInt(u32);void __osEnqueueAndYield(OSThread**);OSThread *__osPopThread(OSThread**);void __osDispatchThread(void);
void osStartThread(OSThread*);void __osEnqueueThread(OSThread**,OSThread*);
#define __osDisableInt __osDisableInt
#define __osRestoreInt __osRestoreInt
#define __osEnqueueAndYield __osEnqueueAndYield
#define __osPopThread __osPopThread
#define __osDispatchThread __osDispatchThread
#define __osRunningThread D_800EF290
#define __osRunQueue D_800EF288
#define OS_STATE_WAITING 8
#define OS_STATE_RUNNABLE 2
#define OS_STATE_STOPPED 1
#define OS_MESG_BLOCK 1
#define OS_MESG_NOBLOCK 0
#define MQ_IS_FULL(mq) ((mq)->validCount >= (mq)->msgCount)
#line 22 "STARTTHREAD.C"
void
osStartThread(OSThread *t)
{
	register u32 saveMask;

	/* Disable interrupts */
	saveMask = __osDisableInt();

	switch (t->state) {
	case OS_STATE_WAITING:
		/* thread t is waiting for a message */
		/* this path is reached by messaging routines */
		t->state = OS_STATE_RUNNABLE;
	       	__osEnqueueThread(&__osRunQueue, t);
		break;
	case OS_STATE_STOPPED:
		/* thread t was stopped by osStopThread */
		if ((t->queue == NULL) || (t->queue == &__osRunQueue)) {
			/* if thread t was just started or pulled out of RunQueue */
			t->state = OS_STATE_RUNNABLE;
			__osEnqueueThread(&__osRunQueue, t);
		} else {
			/* thread t was pulled out of a message queue */
			t->state = OS_STATE_WAITING;
			__osEnqueueThread(t->queue, t);
			/* kick the first thread in the message queue */
			__osEnqueueThread(&__osRunQueue, __osPopThread(t->queue));
		}
		break;
#ifdef _DEBUG
	default:
		__osError(ERR_OSSTARTTHREAD, 0);
		__osRestoreInt(saveMask);
		return;
#endif
	}

	/* determine who gets to execute */
	if (__osRunningThread == NULL)
		__osDispatchThread();
	/*
	 * If the new thread is the highest priority runnable
	 * thread, yield the processor and invoke the dispatcher.
	 */
	else if (__osRunningThread->priority < __osRunQueue->priority) {
		__osRunningThread->state = OS_STATE_RUNNABLE;
		__osEnqueueAndYield(&__osRunQueue);
	}


	/* Restore interrupts */
	__osRestoreInt(saveMask);
}

