#include "decompdecomp_sync_cd8e719cd0b00f3838e3.h"
#line 744 "reference.c"
// schedules the tasks to be run on the RCP
s32 __scSchedule(OSSched *sc, OSScTask **sp, OSScTask **dp, s32 availRCP)
{
	s32 avail = availRCP;
	OSScTask *gfx = sc->gfxListHead;
	OSScTask *audio = sc->audioListHead;

#ifdef SC_LOGGING
	osLogEvent(l, 517, 3, *sp, *dp, availRCP);
#endif

	if (sc->doAudio && (avail & OS_SC_SP))
	{
		if (gfx && (gfx->flags & OS_SC_PARALLEL_TASK))
		{
			*sp = gfx;
			avail &= ~OS_SC_SP;
		}
		else
		{
			*sp = audio;
			avail &= ~OS_SC_SP;
			sc->doAudio = 0;
			sc->audioListHead = sc->audioListHead->next;
			if (sc->audioListHead == NULL)
				sc->audioListTail = NULL;
		}
	}
	else
	{
#ifdef SC_LOGGING
		osLogEvent(l, 520, 1, gfx);
#endif
		if (__scTaskReady(gfx))
		{
#ifdef SC_LOGGING
			osLogEvent(l, 522, 3, gfx, gfx->state, gfx->flags);
#endif
			switch (gfx->flags & OS_SC_TYPE_MASK)
			{
				case (OS_SC_XBUS):
					if (gfx->state & OS_SC_YIELDED)
					{
#ifdef SC_LOGGING
						osLogEvent(l, 518, 0);
#endif
						// can hit this if RDP finishes at yield req
						// ASSERT(gfx->state & OS_SC_DP);

						if (avail & OS_SC_SP)
						{
							// if SP is available
#ifdef SC_LOGGING
							osLogEvent(l, 519, 0);
#endif
							*sp = gfx;
							avail &= ~OS_SC_SP;

							if (gfx->state & OS_SC_DP)
							{
								// if it needs DP */
								*dp = gfx;
								avail &= ~OS_SC_DP;

								if (avail & OS_SC_DP == 0)
									ASSERT(sc->curRDPTask == gfx);
							}

							sc->gfxListHead = sc->gfxListHead->next;
							if (sc->gfxListHead == NULL)
								sc->gfxListTail = NULL;
						}
					}
					else
					{
						if (avail == (OS_SC_SP | OS_SC_DP))
						{
							*sp = *dp = gfx;
							avail &= ~(OS_SC_SP | OS_SC_DP);
							sc->gfxListHead = sc->gfxListHead->next;
							if (sc->gfxListHead == NULL)
								sc->gfxListTail = NULL;
						}
               }
               break;

				case (OS_SC_DRAM):
				case (OS_SC_DP_DRAM):
				case (OS_SC_DP_XBUS):
					if (gfx->state & OS_SC_SP)
					{
						// if needs SP
						if (avail & OS_SC_SP)
						{
							// if SP is available
							*sp = gfx;
							avail &= ~OS_SC_SP;
						}
					}
					else if (gfx->state & OS_SC_DP)
					{
						// if needs DP
						if (avail & OS_SC_DP)
						{
							// if DP available
							*dp = gfx;
							avail &= ~OS_SC_DP;
							sc->gfxListHead = sc->gfxListHead->next;
							if (sc->gfxListHead == NULL)
								sc->gfxListTail = NULL;
						}
					}
					break;

				case (OS_SC_SP_DRAM):
				case (OS_SC_SP_XBUS):
				default:
					break;
			}
		}
	}

	if (avail != availRCP)
		avail = __scSchedule(sc, sp, dp, avail);

	return avail;
}
