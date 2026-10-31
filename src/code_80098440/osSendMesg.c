#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct OSThread {struct OSThread *next;s32 priority;struct OSThread **queue;struct OSThread *tlnext;u16 state;} OSThread;
typedef void *OSMesg;
typedef struct {OSThread *mtqueue,*fullqueue;s32 validCount,first,msgCount;OSMesg *msg;} OSMesgQueue;
extern OSThread *D_800EF290,*D_800EF288;
u32 func_800A5750(void);void func_800A5770(u32);void func_800A5DEC(OSThread**);OSThread *func_800A5F34(OSThread**);void func_800A5F44(void);
void osStartThread(OSThread*);void __osEnqueueThread(OSThread**,OSThread*);
#define __osDisableInt func_800A5750
#define __osRestoreInt func_800A5770
#define __osEnqueueAndYield func_800A5DEC
#define __osPopThread func_800A5F34
#define __osDispatchThread func_800A5F44
#define __osRunningThread D_800EF290
#define __osRunQueue D_800EF288
#define OS_STATE_WAITING 8
#define OS_STATE_RUNNABLE 2
#define OS_STATE_STOPPED 1
#define OS_MESG_BLOCK 1
#define OS_MESG_NOBLOCK 0
#define MQ_IS_FULL(mq) ((mq)->validCount >= (mq)->msgCount)
#line 34 "SENDMESG.C"
s32
osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flags)
{
	register u32 saveMask;
	register s32 last;

	/* Ensure that message queue is not null */
	/* assert(mq != NULL); */

#ifdef _DEBUG
	/* Ensure that flags contain valid data */
	if ((flags != OS_MESG_NOBLOCK) && (flags != OS_MESG_BLOCK)) {
		__osError(ERR_OSSENDMESG, 1, flags);
		return(-1);
	}
#endif

	/* Disable interrupts */
	saveMask = __osDisableInt();

	/* Check for full queue */
	while (MQ_IS_FULL(mq)) {
		if (flags == OS_MESG_BLOCK) {
			/* Yield processing and enqueue the calling thread */
			__osRunningThread->state = OS_STATE_WAITING;
			__osEnqueueAndYield(&mq->fullqueue);
		} else {
			/* Restore interrupts */
			__osRestoreInt(saveMask);
			return(-1);
		}
	}

	/* Increment the last ptr for next available slot */
	last = (mq->first + mq->validCount) % mq->msgCount;

	/* Copy message into the queue buffer */
	mq->msg[last] = msg;

	/* Increment valid message counter */
	mq->validCount++;

	/* 
	 * Now, check to see if there's any thread blocked because the
	 * queue was empty. If there is, we simply start it again.
	 */
	if (mq->mtqueue->next != NULL) {
		osStartThread(__osPopThread(&mq->mtqueue));
	}

	/* Restore interrupts */
	__osRestoreInt(saveMask);

	return(0);

}
