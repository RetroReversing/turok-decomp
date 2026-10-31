#include "decompdecomp_sync_5ee3df47777452ad3ff2.h"
#line 1 "func.c"
#line 1 "reference.c"
       void
__osLeoResume(void)
{
	__OSEventState *es;
	OSMesgQueue *mq;
	s32 last;

	/* send message to PI */
	
	es = &D_801369A0[8];
	mq = es->messageQueue;
	if ((mq == NULL) || (MQ_IS_FULL(mq)))
		return;
	
	/* Increment the last ptr for next available slot */
        last = (mq->first + mq->validCount) % mq->msgCount;

	/* Copy message into the queue buffer */
	mq->msg[last] = es->message;

	/* Increment valid message counter */
	mq->validCount++;

	if (mq->mtqueue->next != NULL) {
		__osEnqueueThread(&__osRunQueue, __osPopThread(&mq->mtqueue));
	}
}

