#include "decompdecomp_sync_51fb4305e26611586ff5.h"
#line 34 "reference.c"
// called when an RSP task signals that it has
// finished or yielded (at the hosts request)
void __scHandleRSP(OSSched *sc)
{
	OSScTask *t, *sp = 0, *dp = 0;
	s32 state, ret;

	ASSERT(sc->curRSPTask);

	t = sc->curRSPTask;
	sc->curRSPTask = 0;

#ifdef SC_LOGGING
	osLogEvent(l, 510, 3, t, t->state, t->flags);
#endif

	if ((t->state & OS_SC_YIELD) && osSpTaskYielded(&t->list))
	{
		t->state |= OS_SC_YIELDED;

		if ((t->flags & OS_SC_TYPE_MASK) == OS_SC_XBUS)
		{
			// push the task back on the list
			t->next = sc->gfxListHead;
			sc->gfxListHead = t;
			if (sc->gfxListTail == 0)
				sc->gfxListTail = t;
		}

#ifdef SC_LOGGING
		osLogEvent(l, 521, 1, t);
#endif

		ASSERT(t->list.t.type == M_GFXTASK);

		if (t->flags & OS_SC_LAST_TASK)
			this_rsp_graphics_time += ((float)(CYCLES_TO_NSEC(osGetTime() - rsp_graphics_start_time)))/1000000;

	}
	else
	{
		t->state &= ~OS_SC_NEEDS_RSP;

		if (t->list.t.type == M_GFXTASK)
		{
			c_retrace = 0;

			// RSP complete for graphics task
			if (t->flags & OS_SC_LAST_TASK)
			{
				this_rsp_graphics_time += ((float)(CYCLES_TO_NSEC(osGetTime() - rsp_graphics_start_time)))/1000000;
				rsp_graphics_time = this_rsp_graphics_time;
				rsp_total_time = ((float)(CYCLES_TO_NSEC(osGetTime() - rsp_start_time)))/1000000;

				ret = osSendMesg(t->msgQ, t->msg, OS_MESG_NOBLOCK);
				if (ret == -1)
				{
#ifndef SHIP_IT
					trap_thread = THREAD_MAIN;
					igAssert(__FILE__, __LINE__, "-- MQ FULL --");
#endif

					// reboot
					*((char*)(NULL)) = 0;
				}
			}
		}
		else
		{
			rsp_audio_time = ((float)(CYCLES_TO_NSEC(osGetTime() - rsp_audio_start_time)))/1000000;

			ret = osSendMesg(t->msgQ, t->msg, OS_MESG_NOBLOCK);
			if (ret == -1)
			{
#ifndef SHIP_IT
				trap_thread = THREAD_MAIN;
				igAssert(__FILE__, __LINE__, "-- MQ FULL --");
#endif

				// reboot
				*((char*)(NULL)) = 0;
			}
		}

		__scTaskComplete(sc, t);
	}

	state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);
	if ( (__scSchedule (sc, &sp, &dp, state)) != state)
		__scExec(sc, sp, dp);
}
