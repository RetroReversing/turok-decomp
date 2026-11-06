#include "decompdecomp_sync_ca98358e229ecb49eeba.h"
#line 657 "reference.c"
void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp)
{
	int rv;

#ifdef SC_LOGGING
	osLogEvent(l, 511, 2, sp, dp);
#endif

	ASSERT(sc->curRSPTask == 0);

	if (dp)
		if (dp->flags & OS_SC_LAST_TASK)
			if (!(dp->state & OS_SC_YIELD))
				rdp_start_time = osGetTime();

	if (sp)
	{
		if (sp->list.t.type == M_AUDTASK)
		{
			osWritebackDCacheAll();  // flush the cache

			rsp_audio_start_time = osGetTime();
		}
		else
		{
			if (sp->flags & OS_SC_LAST_TASK)
			{
				rsp_graphics_start_time = osGetTime();

				if (!(sp->state & OS_SC_YIELD))
				{
					rsp_start_time = rsp_graphics_start_time;
					this_rsp_graphics_time = 0;
				}
			}
		}

		sp->state &= ~(OS_SC_YIELD | OS_SC_YIELDED);
		osSpTaskLoad(&sp->list);
		osSpTaskStartGo(&sp->list);
		sc->curRSPTask = sp;

		if (sp == dp)
			sc->curRDPTask = dp;
	}

	if (dp && (dp != sp))
	{
		ASSERT(dp->list.t.output_buff);

#ifdef SC_LOGGING
		osLogEvent(l, 523, 3, dp, dp->list.t.output_buff,
					  (u32)*dp->list.t.output_buff_size);
#endif
		rv = osDpSetNextBuffer(dp->list.t.output_buff,
									  *dp->list.t.output_buff_size);

		dp_busy = 1;
		dpCount = 0;

		ASSERT(rv == 0);

		sc->curRDPTask = dp;
	}
}
