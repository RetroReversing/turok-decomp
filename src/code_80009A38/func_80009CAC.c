#include "common_local_source_3729.h"

#line 1 "reference.c"
void func_80009CAC(CEngineApp *pThis)
{
	// Needs this for correct record/playback of attract demo!!
	BOOL	Sync ;
	BOOL	StartPressed = FALSE ;

	INT32	Warp ;

	// Check for grabbing a new demo from rom
	func_8004FD0C() ;

	// 60 fps
	CEngineApp__PrepareFrame(pThis, 1) ;
	func_80007654(pThis);

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
		func_8001116C() ;
		//StartPressed = CTControl__IsStart(pCTControl) ;

		if (func_80084E9C(&pThis->m_Pause) != -1)
			StartPressed = TRUE ;
		else
			StartPressed = FALSE ;
	}

	// Play/Record a demo?
	if ((Sync) &&
		 (((pThis->m_ModeTime >= SECONDS_TO_FRAMES(20)) && (func_8004FF48())) ||
		  ((StartPressed) && (func_8004FE78()))))
	{
		Warp = pThis->m_WarpID ;

		func_80013928() ;
		D_800B6AF0 = 0 ;
		D_800B6AF8 = 0 ;


		D_800B6B00 = 1.0;
		D_800B6B04 = 1.0;
		D_800B6B08 = 1.0;
		D_800B6B0C = 1.0;


		// Clear and re-initialise movement vars!!
		func_800121B8(&D_80128C20, 0, sizeof(CTMove)) ;
		func_800121B8(&D_80128A00, 0, sizeof(D_80128A00)) ;

		func_800121B8(D_80119990, 0, sizeof(OSContPad) * MAXCONTROLLERS) ;
		func_800121B8(&D_801199C8, 0, sizeof(OSContPad)) ;
		func_800121B8(&D_801199D0, 0, sizeof(CControlState)) ;
		func_80010C94() ;


		D_800F9E44 = func_800502F0(pThis->m_Options.m_RHControl) ;
		func_80052484() ;

		// Start game
		func_80009FBC(pThis) ;

		func_80001860(pThis) ;

		// Put warp back to what it was for attract code sets it up
		// and "CEngineApp__NewLife" changes it !
		pThis->m_WarpID = Warp ;
	}
	else
	if ((Sync) && (pThis->m_ModeTime >= SECONDS_TO_FRAMES(30)))
	{
		func_8000B070() ;
		func_80004504(pThis, MODE_RESETLEVEL) ;
	}
	else
	// Start a normal game
	if ((pThis->m_Mode == MODE_TITLE) && (StartPressed) && (!func_8004FE78()))
	{
		// in training mode, bypass the 'instructions'
 		if (pThis->m_bTrainingMode)
 		{
 			func_80009FBC(GetApp()) ;
			pThis->m_WarpID = 10000 ;
		}
		else
			pThis->m_WarpID = GAME_INTRO_WARP_ID ;

		func_80004504(pThis, MODE_RESETLEVEL) ;
	}
}
