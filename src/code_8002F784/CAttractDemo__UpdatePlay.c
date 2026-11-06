#include "common_local_source_4691.h"

#line 1 "reference.c"
void CAttractDemo__UpdatePlay()
{
	CAttractDemo	*pThis = &D_80128140 ;

	// First time ran - force read
	if (pThis->m_FirstFrame)
	{
		CAttractBuffer__ReadValue(&pThis->m_ButtonBuffer) ;
		CAttractBuffer__ReadValue(&pThis->m_StickXBuffer) ;
		CAttractBuffer__ReadValue(&pThis->m_StickYBuffer) ;
		CAttractBuffer__ReadValue(&pThis->m_NextFieldsBuffer) ;

		pThis->m_FirstFrame = FALSE ;
	}
	else
	{
		// End yet or start pressed?
		pThis->m_TotalTime += D_800B6B00 ;
		if ((--pThis->m_TotalFrames <= 0) || (D_801199C8.button & START_BUTTON))
		{
			// Put original options back
			func_80093C80(&GetApp()->m_Options) ;

			D_801199C8.button = 0 ;
			D_801199C8.stick_x = 0 ;
			D_801199C8.stick_y = 0 ;
			pThis->m_Active = FALSE ;
			pThis->m_Play = FALSE ;

			// Request next demo from rom
			CAttractDemo__RequestNewDemo() ;

			// Stop player from joining in demo!!
			GetApp()->m_CinemaFlags = -1 ;

			// Re-run front end
			CEngineApp__SetupFadeTo(GetApp(), MODE_RESETGAME) ;
		}
		else
		{
			CAttractBuffer__UpdatePlay(&pThis->m_ButtonBuffer) ;
			CAttractBuffer__UpdatePlay(&pThis->m_StickXBuffer) ;
			CAttractBuffer__UpdatePlay(&pThis->m_StickYBuffer) ;
			CAttractBuffer__UpdatePlay(&pThis->m_NextFieldsBuffer) ;
		}
	}

	// All joypad direction buttons (run/walk) count as one button
	if (pThis->m_ButtonBuffer.m_Value & (U_JPAD | D_JPAD | L_JPAD | R_JPAD))
	{
		pThis->m_ButtonBuffer.m_Value &= ~(U_JPAD | D_JPAD | L_JPAD | R_JPAD) ;
		pThis->m_ButtonBuffer.m_Value |= R_JPAD ;
	}


	CAttractDemo__UpdateChecksum() ;

#if 0
	osSyncPrintf("F:%d x:%f z:%f xvl:%f zvl:%f f_inc:%f\r\n",
				  D_800B6AF8,
				  CEngineApp__GetPlayer(GetApp())->ah.ih.m_vPos.x,	
				  CEngineApp__GetPlayer(GetApp())->ah.ih.m_vPos.z,
				  CEngineApp__GetPlayer(GetApp())->ah.m_vVelocity.x,	
				  CEngineApp__GetPlayer(GetApp())->ah.m_vVelocity.z,
				  D_800B6B00) ;
#endif

}
