#include "common_local_source_4325.h"

#line 1 "reference.c"
void func_8003DFCC(CCamera *pThis)
{
	CEngineApp *pEngine = GetApp() ;
	CGameObjectInstance *pTurok = CEngineApp__GetPlayer(GetApp()) ;
	CVector3			vPos ;
	
	// Load model
	if ((!(pThis->m_Flags & CF_TUROK_LOADED)) && (pTurok))
	{
		// start from explosion
		func_800329E0(&GetApp()->m_Scene, pTurok,
										    AI_OBJECT_CHARACTER_PLAYER, AI_ANIM_EXTRA17) ;
		pThis->m_Flags |= CF_TUROK_LOADED ;
	}

	// Update times
	pThis->m_StageTime += D_800B6B00 ;
	pThis->m_Time += D_800B6B00 ;

	// point camera at Turok
	pThis->m_pObject = pTurok ;


	// Play explosion sound behind turok
	if ((pThis->m_Stage <= 6) &&  (D_800B6AF8 & 7) == 0)
	{
		vPos = pTurok->ah.ih.m_vPos ;
		vPos.x += func_80040D10(-14*SCALING_FACTOR, 14*SCALING_FACTOR) ;
		vPos.z += func_80040D10(20*SCALING_FACTOR, 35*SCALING_FACTOR) ;

		if (RANDOM(2))
			func_80063AE8(&pTurok->ah.ih, vPos, SOUND_GENERIC_218) ;
		else
			func_80063AE8(&pTurok->ah.ih, vPos, SOUND_EXPLOSION_2) ;
	}

	// move TUROK into position on the water surface
	if (pThis->m_Stage >= 10)
	{
		vPos.x = -580 * SCALING_FACTOR ;
		vPos.y = 0 ;
		vPos.z = -22 * SCALING_FACTOR ;
		pTurok->ah.ih.m_pCurrentRegion = func_8002E280(&GetApp()->m_Scene, &vPos) ;
		vPos.y = func_80019D3C(pTurok->ah.ih.m_pCurrentRegion, vPos.x, vPos.z) ;
		pTurok->ah.ih.m_vPos = vPos ;
	}

	// Update stage
	switch (pThis->m_Stage)
	{
		// explosion going off all around (again)
//		case 0:
//			if (pTurok)
//			{
//				AI_SetDesiredAnim(pTurok, AI_ANIM_EXTRA17, TRUE) ;
//				CCameraView__TweenTrackAroundObject(&pThis->m_View, &EndSeq2Track1,
//															  COSINE_TWEEN(pThis->m_StageTime / ENDSEQ2_STAGE1_TIME),
//															  pThis->m_pObject) ;
//			}
//
//			if (pThis->m_StageTime > ENDSEQ2_STAGE1_TIME)
//			{
//				pThis->m_Stage++ ;
//				pThis->m_StageTime = 0 ;
//				AI_SetDesiredAnim(pTurok, AI_ANIM_EXTRA19, TRUE) ;
//			}
//			break ;

		// running away down a hall (cut1) eye at track position, focus on turok
		case 1:
			func_8005FCF4(pTurok, AI_ANIM_EXTRA19, TRUE) ;
			pThis->m_View.m_vFocus.x = pTurok->ah.ih.m_vPos.x ;
			pThis->m_View.m_vFocus.y = pTurok->ah.ih.m_vPos.y +(5*SCALING_FACTOR);
			pThis->m_View.m_vFocus.z = pTurok->ah.ih.m_vPos.z ;

			if (pThis->m_StageTime > ENDSEQ2_STAGE2_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;

				pThis->m_View.m_vEye.x = pTurok->ah.ih.m_vPos.x - (8*SCALING_FACTOR);
				pThis->m_View.m_vEye.y = pTurok->ah.ih.m_vPos.y + (10*SCALING_FACTOR) ;
				pThis->m_View.m_vEye.z = pTurok->ah.ih.m_vPos.z - (40 * SCALING_FACTOR) ;
			}
			break ;

		// running away down a hall (cut2) top view down
		case 2:
			pThis->m_View.m_vFocus.x = pTurok->ah.ih.m_vPos.x ;
			pThis->m_View.m_vFocus.y = pTurok->ah.ih.m_vPos.y + (5*SCALING_FACTOR);
			pThis->m_View.m_vFocus.z = pTurok->ah.ih.m_vPos.z ;

			if (pThis->m_StageTime > ENDSEQ2_STAGE3_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;

			pThis->m_View.m_vEye.x = pTurok->ah.ih.m_vPos.x ;
			pThis->m_View.m_vEye.y = pTurok->ah.ih.m_vPos.y + (8*SCALING_FACTOR) ;
			pThis->m_View.m_vEye.z = pTurok->ah.ih.m_vPos.z - (10 * SCALING_FACTOR) ;

			pThis->m_View.m_vFocus.x = pTurok->ah.ih.m_vPos.x ;
			pThis->m_View.m_vFocus.y = pTurok->ah.ih.m_vPos.y +(6*SCALING_FACTOR);
			pThis->m_View.m_vFocus.z = pTurok->ah.ih.m_vPos.z ;
			}
			break ;

		// running away down a hall (cut3) view from behind
		case 3:
			pThis->m_View.m_vEye.z -= (2.4 * SCALING_FACTOR) * D_800B6B00 ;
			pThis->m_View.m_vFocus.z -= (2.4 * SCALING_FACTOR) * D_800B6B00 ;

			if (pThis->m_StageTime > ENDSEQ2_STAGE4_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;

			pThis->m_View.m_vEye.x = pTurok->ah.ih.m_vPos.x ;
			pThis->m_View.m_vEye.y = pTurok->ah.ih.m_vPos.y + (6*SCALING_FACTOR) ;
			pThis->m_View.m_vEye.z = pTurok->ah.ih.m_vPos.z - (10 * SCALING_FACTOR);

			pThis->m_View.m_vFocus.x = pTurok->ah.ih.m_vPos.x ;
			pThis->m_View.m_vFocus.y = pTurok->ah.ih.m_vPos.y +(6*SCALING_FACTOR);
			pThis->m_View.m_vFocus.z = pTurok->ah.ih.m_vPos.z ;

			}
			break ;

		// running away down a hall (cut4) toward camera
		case 4:
			pThis->m_View.m_vEye.z -= (2.4 * SCALING_FACTOR) * D_800B6B00 ;

			if (pThis->m_StageTime > ENDSEQ2_STAGE5_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;

				pThis->m_View.m_vEye.x = pTurok->ah.ih.m_vPos.x - (8*SCALING_FACTOR) ;
				pThis->m_View.m_vEye.y = pTurok->ah.ih.m_vPos.y + (8*SCALING_FACTOR) ;
				pThis->m_View.m_vEye.z = pTurok->ah.ih.m_vPos.z  ;

				pThis->m_View.m_vFocus.x = pTurok->ah.ih.m_vPos.x ;
				pThis->m_View.m_vFocus.y = pTurok->ah.ih.m_vPos.y +(6*SCALING_FACTOR);
				pThis->m_View.m_vFocus.z = pTurok->ah.ih.m_vPos.z ;
			}
			break ;

		// running away down a hall (cut5) side view
		case 5:
			pThis->m_View.m_vEye.z -= (2.4 * SCALING_FACTOR) * D_800B6B00 ;
			pThis->m_View.m_vFocus.z -= (2.4 * SCALING_FACTOR) * D_800B6B00 ;

			if (pThis->m_StageTime > ENDSEQ2_STAGE6_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;

			pThis->m_View.m_vEye.x = pTurok->ah.ih.m_vPos.x ;
			pThis->m_View.m_vEye.y = pTurok->ah.ih.m_vPos.y + (6 * SCALING_FACTOR) ;
			pThis->m_View.m_vEye.z = pTurok->ah.ih.m_vPos.z - (20 * SCALING_FACTOR) ;

			pThis->m_View.m_vFocus.x = pTurok->ah.ih.m_vPos.x ;
			pThis->m_View.m_vFocus.y = pTurok->ah.ih.m_vPos.y +(6*SCALING_FACTOR);
			pThis->m_View.m_vFocus.z = pTurok->ah.ih.m_vPos.z ;
			}
			break ;

		// running away down a hall (cut6) front view
		case 6:
			pThis->m_View.m_vEye.z -= (2.4 * SCALING_FACTOR) * D_800B6B00 ;

			if (pThis->m_StageTime > ENDSEQ2_STAGE7_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;
				func_8005FCF4(pTurok, AI_ANIM_EXTRA18, TRUE) ;
			}
			break ;

		// starting to leap
		case 7:
			pThis->m_View.m_vFocus.x = pTurok->ah.ih.m_vPos.x ;
			pThis->m_View.m_vFocus.y = pTurok->ah.ih.m_vPos.y +(6*SCALING_FACTOR);
			pThis->m_View.m_vFocus.z = pTurok->ah.ih.m_vPos.z ;

			if (pThis->m_StageTime > ENDSEQ2_STAGE8_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;
				func_8003DEC0() ;

				// move TUROK into position over edge of hole
				vPos.x = -582 * SCALING_FACTOR ;
				vPos.y = 0 ;
				vPos.z = 110 * SCALING_FACTOR ;
				pTurok->ah.ih.m_pCurrentRegion = func_8002E280(&GetApp()->m_Scene, &vPos) ;
				vPos.y = func_80019D3C(pTurok->ah.ih.m_pCurrentRegion, vPos.x, vPos.z) ;
				pTurok->ah.ih.m_vPos = vPos ;

				pThis->m_View.m_vEye.x = -575 * SCALING_FACTOR ;
				pThis->m_View.m_vEye.y = 15 * SCALING_FACTOR ;
				pThis->m_View.m_vEye.z = 80 * SCALING_FACTOR ;

				pThis->m_View.m_vFocus.x = -580 * SCALING_FACTOR ;
				pThis->m_View.m_vFocus.y = 18*SCALING_FACTOR ;
				pThis->m_View.m_vFocus.z = 100 * SCALING_FACTOR ;
			}
			break ;

		// leaping out of exit (cut1) see those flames
		case 8:
			if (pThis->m_StageTime > ENDSEQ2_LEAP1_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;

				func_8005FCF4(pTurok, AI_ANIM_EXTRA15, TRUE) ;

				// position the camera on the ground
				vPos.x = -580 * SCALING_FACTOR ;
				vPos.y = 0 ;
				vPos.z = -40 * SCALING_FACTOR ;
				pTurok->ah.ih.m_pCurrentRegion = func_8002E280(&GetApp()->m_Scene, &vPos) ;
				vPos.y = func_80019D3C(pTurok->ah.ih.m_pCurrentRegion, vPos.x, vPos.z) ;
				vPos.y += 20 * SCALING_FACTOR ;

				pThis->m_View.m_vEye.x = vPos.x  ;
				pThis->m_View.m_vEye.y = vPos.y  ;
				pThis->m_View.m_vEye.z = vPos.z  ;


				// move TUROK into position to fall into water
				vPos.x = -580 * SCALING_FACTOR ;
				vPos.y = 0 ;
				vPos.z = 0 * SCALING_FACTOR ;
				pTurok->ah.ih.m_pCurrentRegion = func_8002E280(&GetApp()->m_Scene, &vPos) ;
				vPos.y = func_80019D3C(pTurok->ah.ih.m_pCurrentRegion, vPos.x, vPos.z) ;
				// move height up to make turok fall
				vPos.y += 40 * SCALING_FACTOR ;
				pTurok->ah.ih.m_vPos = vPos ;
			}
			break ;

		// see turok fall - eye on water, focus on turok
		case 9:
			pThis->m_View.m_vFocus.x = pTurok->ah.ih.m_vPos.x ;
			pThis->m_View.m_vFocus.y = pTurok->ah.ih.m_vPos.y +(6*SCALING_FACTOR) ;
			pThis->m_View.m_vFocus.z = pTurok->ah.ih.m_vPos.z ;

			if (pThis->m_StageTime > ENDSEQ2_FALL1_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;

				func_8005FCF4(pTurok, AI_ANIM_EXTRA20, TRUE) ;
			}

			// Start splash effect
			if ((pTurok->ah.ih.m_vPos.y < ((-120+30)*SCALING_FACTOR)) &&
				 (!(pThis->m_Flags & CF_TUROK_IN_WATER)))
			{
				pThis->m_Flags |= CF_TUROK_IN_WATER ;
				vPos = pTurok->ah.ih.m_vPos ;
				vPos.y = -120*SCALING_FACTOR ; 
				func_8005F840(&pTurok->ah.ih, PARTICLE_TYPE_GENERIC96, vPos) ;
			}

			break;

		// swimming
		case 10:

			func_800395D4(&pThis->m_View, &D_800BAF5C,
															  COSINE_TWEEN(pThis->m_StageTime / ENDSEQ2_SWIM1_TIME),
															  pTurok) ;

//			pThis->m_View.m_vEye.x = pTurok->ah.ih.m_vPos.x ;
//			pThis->m_View.m_vEye.y = pTurok->ah.ih.m_vPos.y + (7.5 * SCALING_FACTOR) ;
//			pThis->m_View.m_vEye.z = pTurok->ah.ih.m_vPos.z - (6 * SCALING_FACTOR) ;

//			pThis->m_View.m_vFocus.x = pTurok->ah.ih.m_vPos.x ;
//			pThis->m_View.m_vFocus.y = pTurok->ah.ih.m_vPos.y +(11*SCALING_FACTOR);
//			pThis->m_View.m_vFocus.z = pTurok->ah.ih.m_vPos.z ;

			if (pThis->m_StageTime > ENDSEQ2_SWIM1_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;
			}
			break ;

		// looking at exploding lair
		case 11:

			// Fade in game over
			if ((pThis->m_StageTime > SECONDS_TO_FRAMES(3)) && (!pEngine->m_bGameOver))
			{
				pEngine->m_bGameOver = TRUE ;
				pEngine->m_GameOverAlpha = 0 ;
				pEngine->m_GameOverMode = 0 ;
				pEngine->m_GameOverTime = SECONDS_TO_FRAMES(100) ;
			}

			// The very, very, very, very, very... end?
			if (pThis->m_StageTime > ENDSEQ2_SWIM2_TIME)
			{
				pThis->m_Stage++ ;
				pThis->m_StageTime = 0 ;

				GetApp()->retail_unknown_before_map_mode = TRUE;
				GetApp()->m_WarpID = CREDITS_WARP_ID ;
				func_80004504(GetApp(), MODE_RESETLEVEL) ;
			}
			break ;
	}
}
