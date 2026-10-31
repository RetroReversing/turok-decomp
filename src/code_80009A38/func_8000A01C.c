#include "common_local_source_3731.h"

#line 1 "reference.c"
void func_8000A01C(CEngineApp *pThis)
{
	// Request latest controller information
	if (D_800B86D0 && !D_80119908)
	{
		D_80119908 = TRUE;
		osContStartReadData(&D_800F9C20);
	}

	// Read controller
	if (D_8011990C)
	{
		func_80010DF0() ;

		// Start pressed? - if so signal it to camera
		if ((func_800513F4(D_800F9E44)) && (pThis->m_FadeStatus == FADE_NULL))
			pThis->m_Camera.m_StartPressed = TRUE ;
	}

//	sprintf(buff, "crash %d", CrashId) ;
//	COnScreen__AddGameTextWithId(buff, 39) ;

	// Calculate frame rate
	switch(pThis->m_CurrentWarpID)
	{
		case INTRO_TUROK_DRAWING_BOW_WARP_ID:
		case INTRO_ZOOM_TO_LOGO_WARP_ID:
			D_8011992C = CALC_FRAMERATE(3) ;
			break ;

		case GAME_INTRO_WARP_ID:
		case GAME_INTRO_KEY_WARP_ID:
			D_8011992C = CALC_FRAMERATE(4) ;
			break ;

		case CHEAT_GALLERY_WARP_ID:
			D_8011992C = CALC_FRAMERATE(1) ;
			break ;


		default:
			D_8011992C = CALC_FRAMERATE(2) ;
	}

	// Other special case frame rates more more smoothness
	switch(pThis->m_Camera.m_Mode)
	{
		case CAMERA_CINEMA_TUROK_RESURRECT_MODE:

		case CAMERA_CINEMA_END_SEQUENCE_MODE: 			// Turok escaping from campainer
		case CAMERA_CINEMA_END_SEQUENCE2_MODE:   		// Turok in extra bit, running away

			D_8011992C = CALC_FRAMERATE(3) ;
			break ;
	}


	// Attract code may modify controller values/nNextFields
	func_80050120() ;
	func_800501E0() ;

	// Demo's were recorded at 60 frames per sec!!
	if (func_80050280())
		D_800B6B00 = REFRESHES_TO_FRAME_INC(D_8011992C, 60.0) ;
	else
		D_800B6B00 = REFRESHES_TO_FRAME_INC(D_8011992C, D_800F9E4C) ;

	// Process player controller values
	func_80010E7C() ;

	// Start pressed? - if so signal it to camera
	if ((func_800513F4(D_800F9E44)) && (pThis->m_FadeStatus == FADE_NULL))
		pThis->m_Camera.m_StartPressed = TRUE ;

	// Update turok
	if ((pThis->m_bPause==FALSE) && (pThis->m_Warp == WARP_NOT_WARPING) && (pThis->m_Death == DEATH_NOT_DIEING) &&(pThis->m_bTraining ==FALSE))
		func_80052BCC(D_800F9E48, pThis, D_800F9E44);

	func_8000695C(pThis);
	func_80037EEC(&pThis->m_Camera) ;
	func_80007654(pThis);


	// Start tasks
	D_80119924 = func_80007E44(pThis);
	D_80119924->m_nPredictFields = D_8011992C;
	func_80008060(pThis, D_80119924);

	// Update Region Music
	func_8008B654();

	// Play sounds in audio list
	if (D_800B6AF8 == 3)
		func_8008B92C() ;
}
