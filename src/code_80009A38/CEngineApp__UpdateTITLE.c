#include "decompdecomp_sync_2bc957b0a68759be96b6.h"
#line 1 "reference.c"
/*****************************************************************************
*
*	Function:		CEngineApp__UpdateTITLE()
*
******************************************************************************
*
*	Description:	Update TITLE mode stuff
*
*	Inputs:			*pThis	-	Ptr to engine
*	Outputs:			None
*
*****************************************************************************/
void CEngineApp__UpdateTITLE(CEngineApp *pThis)
{
	// Needs this for correct record/playback of attract demo!!
	BOOL	Sync ;
	BOOL	StartPressed = FALSE ;

	INT32	Warp ;

	// Check for grabbing a new demo from rom
	CAttractDemo__CheckForNewDemoRequest() ;

	// 60 fps
	CEngineApp__PrepareFrame(pThis, 1) ;
	CEngineApp__UpdateCameraAttributes(pThis);

	// Setup sync var
	Sync = (pThis->m_FadeStatus == FADE_NULL) && ((D_800B6AF0 % 3) == 0) && (D_800B6AF4 == 0) ;

	// Request latest controller information
	if ((D_800B86D0) && (!D_80119908))
	{
		D_80119908 = TRUE;
		osContStartReadData(&D_800F9C20) ;
	}

	// Controller ready?
	if (D_8011990C)
	{
		ReadControllerAdvanced() ;
		//StartPressed = CTControl__IsStart(pCTControl) ;

		if (func_80084E9C(&pThis->m_Pause) != -1)
			StartPressed = TRUE ;
		else
			StartPressed = FALSE ;
	}

	// Play/Record a demo?
	if ((Sync) &&
		 (((pThis->m_ModeTime >= SECONDS_TO_FRAMES(20)) && (CAttractDemo__Play())) ||
		  ((StartPressed) && (CAttractDemo__CheckForRecord()))))
	{
		Warp = pThis->m_WarpID ;

		InitializeRandomSeed() ;
		D_800B6AF0 = 0 ;
		D_800B6AF8 = 0 ;


		D_800B6B00 = 1.0;
		D_800B6B04 = 1.0;
		D_800B6B08 = 1.0;
		D_800B6B0C = 1.0;


		// Clear and re-initialise movement vars!!
		memset(&D_80128C20, 0, sizeof(CTMove)) ;
		memset(&D_80128A00, 0, sizeof(D_80128A00)) ;

		memset(D_80119990, 0, sizeof(OSContPad) * MAXCONTROLLERS) ;
		memset(&D_801199C8, 0, sizeof(OSContPad)) ;
		memset(&D_801199D0, 0, sizeof(CControlState)) ;
		InitControllersAdvanced() ;


		D_800F9E44 = CTControl__CTControl(pThis->m_Options.m_RHControl) ;
		func_80052484() ;

		// Start game
		CEngineApp__NewLife(pThis) ;

		CEngineApp__InitializeGameVars(pThis) ;

		// Put warp back to what it was for attract code sets it up
		// and "CEngineApp__NewLife" changes it !
		pThis->m_WarpID = Warp ;
	}
	else
	if ((Sync) && (pThis->m_ModeTime >= SECONDS_TO_FRAMES(30)))
	{
		func_8000B070() ;
		CEngineApp__SetupFadeTo(pThis, MODE_RESETLEVEL) ;
	}
	else
	// Start a normal game
	if ((pThis->m_Mode == MODE_TITLE) && (StartPressed) && (!CAttractDemo__CheckForRecord()))
	{
		// in training mode, bypass the 'instructions'
 		if (pThis->m_bTrainingMode)
 		{
 			CEngineApp__NewLife(GetApp()) ;
			pThis->m_WarpID = 10000 ;
		}
		else
			pThis->m_WarpID = GAME_INTRO_WARP_ID ;

		CEngineApp__SetupFadeTo(pThis, MODE_RESETLEVEL) ;
	}
}
