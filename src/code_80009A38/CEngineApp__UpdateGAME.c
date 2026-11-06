#include "common_local_source_3731.h"

#line 1 "reference.c"
void CEngineApp__UpdateGAME(CEngineApp *pThis)
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
		ReadPlayerController() ;

		// Start pressed? - if so signal it to camera
		if ((CTControl__IsStart(D_800F9E44)) && (pThis->m_FadeStatus == FADE_NULL))
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
	CAttractDemo__Update() ;
	CAttractDemo__CheckForUpdatingGameVars() ;

	// Demo's were recorded at 60 frames per sec!!
	if (CAttractDemo__Active())
		D_800B6B00 = REFRESHES_TO_FRAME_INC(D_8011992C, 60.0) ;
	else
		D_800B6B00 = REFRESHES_TO_FRAME_INC(D_8011992C, D_800F9E4C) ;

	// Process player controller values
	ProcessPlayerController() ;

	// Start pressed? - if so signal it to camera
	if ((CTControl__IsStart(D_800F9E44)) && (pThis->m_FadeStatus == FADE_NULL))
		pThis->m_Camera.m_StartPressed = TRUE ;

	// Update turok
	if ((pThis->m_bPause==FALSE) && (pThis->m_Warp == WARP_NOT_WARPING) && (pThis->m_Death == DEATH_NOT_DIEING) &&(pThis->m_bTraining ==FALSE))
		CTMove__UpdateTurokInstance(D_800F9E48, pThis, D_800F9E44);

	CEngineApp__SetCameraToTurok(pThis);
	CCamera__Update(&pThis->m_Camera) ;
	CEngineApp__UpdateCameraAttributes(pThis);


	// Start tasks
	D_80119924 = CEngineApp__CreateGraphicsTask(pThis);
	D_80119924->m_nPredictFields = D_8011992C;
	CEngineApp__SendGraphicsTask(pThis, D_80119924);

	// Update Region Music
	UpdateSeq();

	// Play sounds in audio list
	if (D_800B6AF8 == 3)
		CAudioList__Flush() ;
}
