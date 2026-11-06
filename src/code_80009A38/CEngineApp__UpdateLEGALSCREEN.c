#include "decompdecomp_sync_054b35ed234ce903c9f5.h"
#line 1 "func.c"
#line 4384 "reference.c"
void CEngineApp__UpdateLEGALSCREEN(CEngineApp *pThis)
{
	// request latest controller information
	if (validcontrollers && !cntrlReadInProg)
	{
		cntrlReadInProg = TRUE;
		osContStartReadData(&gfxFrameMsgQ);
	}
	if (cntrlReadYet)
	{
		ReadControllerAdvanced();

		// skip a frame, then check if the start button is ever released
		if (	(pThis->m_LegalTimer++ == 4)
			&& (!(PlayerControllerData.button & START_BUTTON)))
		{
//			ASSERT(FALSE) ;
			pThis->m_GamePakCheck = FALSE ;
		}

		if (	(pThis->m_GamePakCheck)
			
			&& (pThis->m_FadeStatus == FADE_NULL))
		{
			CGamePak__Construct(&pThis->m_GamePak) ;
			if (pThis->m_GamePak.b_Active)
				CEngineApp__SetupFadeTo(pThis, MODE_GAMEPAK) ;
		}

//		else if ((pThis->m_LegalBypass) && (CTControl__IsStart(pCTControl)))
		else if ((pThis->m_LegalBypass) && (CTControl__IsStart(pCTControl)))
		{
//			if (!IntroFirstRun)
			if (!IntroFirstRun)
			{
				pThis->m_WarpID = INTRO_ZOOM_TO_LOGO_WARP_ID ;
				SkipIntro = TRUE ;
			}
			else
				pThis->m_WarpID = INTRO_ACCLAIM_LOGO_WARP_ID ;

			CEngineApp__SetupFadeTo(pThis, MODE_RESETLEVEL) ;
		}
	}
	// 60 fps
	CEngineApp__PrepareFrame(pThis, 1);

	CLegalScreen__Update();
}

