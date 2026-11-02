#include "decompdecomp_sync_0b4d8928c78c9ffcb7cd.h"
#line 1 "func.c"
#line 491 "reference.c"
void func_8002C280(OSSched *sc)
{
    OSScTask *t, *sp = 0, *dp = 0;
    s32 state;
	 CFrameData	*pFrameData;
	 FrameDataView	*pApp;

    ASSERT(sc->curRDPTask);
    ASSERT(sc->curRDPTask->list.t.type == M_GFXTASK);

    t = sc->curRDPTask;

                 
                                                 
      

    t->state &= ~OS_SC_NEEDS_RDP;

	ASSERT(t->list.t.type == M_GFXTASK);
	if (t->list.t.type == M_GFXTASK)
	{
		if (t->flags & OS_SC_LAST_TASK)
			rdp_time = (__ull_to_f(CYCLES_TO_NSEC(osGetTime() - rdp_start_time)))/1000000;

		sc->curRDPTask = 0;

		if (t->flags & OS_SC_LAST_TASK)
		{
			pApp = GetApp();

			if (t->framebuffer == (void*) pApp->m_FrameData[0].m_pFrameBuffer)
				pFrameData = &pApp->m_FrameData[0];
			else if (t->framebuffer == (void*) pApp->m_FrameData[1].m_pFrameBuffer)
				pFrameData = &pApp->m_FrameData[1];
			else if (t->framebuffer == (void*) pApp->m_FrameData[2].m_pFrameBuffer)
				pFrameData = &pApp->m_FrameData[2];
			else
				ASSERT(FALSE);

			n_lll_fields = n_ll_fields;
			n_ll_fields = n_l_fields;
			n_l_fields = n_fields;
			n_fields = c_field + 1;
			if (((c_field + 1) >= pFrameData->m_nPredictFields) && !n_waiting && !n_pending)
			{
             
                                                                                             
      

				p_pending_fb = pFrameData->m_pFrameBuffer;
				osViSwapBuffer(pFrameData->m_pFrameBuffer);
				n_pending++;
			}
			else
			{
             
                                   
      

				n_waiting++;

				p_waiting_frames[c_waiting] = pFrameData;
				if (++c_waiting == 3)
					c_waiting = 0;
			}

			CSunFrameData__RDPComplete(&pFrameData->m_SunFrame);
		}
	}

	__scTaskComplete(sc, t);


	state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);
	if ( (__scSchedule (sc, &sp, &dp, state)) != state)
		__scExec(sc, sp, dp);
}

