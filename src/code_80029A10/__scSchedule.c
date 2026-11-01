#include "decompdecomp_sync_9d9b901578a01a880ff8.h"
#line 1 "func.c"
#line 744 "reference.c"
s32 __scSchedule(OSSched *sc, OSScTask **sp, OSScTask **dp, s32 availRCP)
{
	s32 avail = availRCP;
	OSScTask *gfx = sc->gfxListHead;
	OSScTask *audio = sc->audioListHead;





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



		if (__scTaskReady(gfx))
		{



			switch (gfx->flags & OS_SC_TYPE_MASK)
			{
				case (OS_SC_XBUS):
					if (gfx->state & OS_SC_YIELDED)
					{



						// can hit this if RDP finishes at yield req
						// ASSERT(gfx->state & OS_SC_DP);

						if (avail & OS_SC_SP)
						{
							// if SP is available



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

