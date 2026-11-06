#include "common_local_source_4157.h"

static __inline void PreDrawSelf(CScene *pThis, CUnindexedSet *pusInstances, Gfx **ppDLP)
{
	int 						nInstances;
	CGameObjectInstance	*instances;

	// Don't draw player during intro
// CARL
//	if (GetApp()->m_Mode == MODE_INTRO || GetApp()->m_Mode == MODE_GALLERY)
//		return ;

   nInstances = CUnindexedSet__GetBlockCount(pusInstances);
   instances = (CGameObjectInstance*) CUnindexedSet__GetBasePtr(pusInstances);

	if (nInstances)
		CGameObjectInstance__PreDrawPlayer(&instances[0], ppDLP);
}

void CScene__Draw(CScene *pThis, Gfx **ppDLP)
{
   CUnindexedSet usInstances;
	BOOL				DrawSelf ;

	// keep main indexes in cache
	if (pThis->m_pceObjectsIndex)
		CCacheEntry__ResetAge(pThis->m_pceObjectsIndex);
	if (pThis->m_pceTextureSetsIndex)
		CCacheEntry__ResetAge(pThis->m_pceTextureSetsIndex);
	if (pThis->m_pceLevelsIndex)
		CCacheEntry__ResetAge(pThis->m_pceLevelsIndex);
	if (pThis->m_pceLevelIndex)
		CCacheEntry__ResetAge(pThis->m_pceLevelIndex);
	if (pThis->m_pceGridBounds)
		CCacheEntry__ResetAge(pThis->m_pceGridBounds);
	if (pThis->m_pceCollision)
		CCacheEntry__ResetAge(pThis->m_pceCollision);
	if (pThis->m_pceGridSectionsIndex)
		CCacheEntry__ResetAge(pThis->m_pceGridSectionsIndex);
	if (pThis->m_pceObjectAttributes)
		CCacheEntry__ResetAge(pThis->m_pceObjectAttributes);
	if (pThis->m_pceObjectTypes)
		CCacheEntry__ResetAge(pThis->m_pceObjectTypes);
	if (pThis->m_pceSoundEffects)
		CCacheEntry__ResetAge(pThis->m_pceSoundEffects);
	if (pThis->m_pceBinaryTypes)
		CCacheEntry__ResetAge(pThis->m_pceBinaryTypes);
	if (pThis->m_pceBinariesIndex)
		CCacheEntry__ResetAge(pThis->m_pceBinariesIndex);

	if (pThis->m_pceObjectAttributes && pThis->m_pceObjectsIndex && pThis->m_pceCollision && pThis->m_pceInstances && pThis->m_pceTextureSetsIndex
		 && pThis->m_pceGridBounds && pThis->m_pceGridSectionsIndex && pThis->m_pceObjectTypes
		 && pThis->m_pceBinaryTypes && pThis->m_pceBinariesIndex)
	{
		D_800B6B38 = TRUE;

      // attatch to usInstances
		CUnindexedSet__ConstructFromRawData(&usInstances,
														CCacheEntry__GetData(pThis->m_pceInstances),
														FALSE);

		func_800311B4(pThis, &usInstances);
		
		CScene__BuildInstanceCollisionList(pThis, &usInstances);

		// dont spin pickups during pause
		if (GetApp()->m_bPause == FALSE)
			pThis->m_RotYPickup += ANGLE_DTOR(5)*D_800B6B00;
		CQuatern__BuildFromAxisAngle(&pThis->m_qRotYPickup, 0,1,0, pThis->m_RotYPickup);


		// MAKE SURE THIS IS BEFORE DRAW ENVIRONMENT SO THAT IF THE DISPLAY LIST RUNS OUT, TUROK IS STILL DRAWN!!!
		// (fixes the trex level bug!!!)
		// If in cinema mode, draw player like other objects
		if (CCamera__InCinemaMode(&GetApp()->m_Camera))
		{
			DrawSelf = TRUE ;

			// Special warp id's
			// DO NOT CHANGE THIS BACK TO WARP ID (See Carl for more...)
			switch(GetApp()->m_CurrentWarpID)
			{
				case LEGALSCREEN_WARP_ID:
				case INTRO_ACCLAIM_LOGO_WARP_ID:
				case INTRO_IGGY_WARP_ID:
				case INTRO_ZOOM_TO_LOGO_WARP_ID:
				case GAME_INTRO_WARP_ID:
				case CHEAT_GALLERY_WARP_ID:
					DrawSelf = FALSE ;
					break;

				case CREDITS_WARP_ID:
					DrawSelf = FALSE ;
					CSun__ReadZDepth(&D_80135BE0, ppDLP);
					gDPPipeSync((*ppDLP)++);
				#ifdef USE_FOG
					gDPSetCycleType((*ppDLP)++, G_CYC_2CYCLE);
				#else		// !USE_FOG
					gDPSetCycleType((*ppDLP)++, G_CYC_1CYCLE);
				#endif
					break ;
			}

			// Special camera modes
			switch(GetApp()->m_Camera.m_Mode)
			{
				case CAMERA_CINEMA_LONGHUNTER_MODE:
				case CAMERA_CINEMA_FIRST_HUMVEE_MODE:
				case CAMERA_CINEMA_FINAL_HUMVEE_MODE:
				case CAMERA_CINEMA_TUROK_KILL_MANTIS_MODE:
				case CAMERA_CINEMA_TUROK_KILL_TREX_MODE:
				case CAMERA_CINEMA_TUROK_KILL_LONGHUNTER_MODE:
				case CAMERA_CINEMA_TUROK_KILL_CAMPAIGNER_MODE:

					DrawSelf = FALSE ;
					break ;
			}

			// Don't draw after loaded game or selecting 'training'
			if (!((GetApp()->m_JustLoadedGame == FALSE) &&
				  ((GetApp()->m_bTrainingMode == FALSE) || (GetApp()->m_bTrainingMode == -1))))
					DrawSelf = FALSE ;

			// Do draw if needed
			if (DrawSelf)
			{
				PreDrawSelf(pThis, &usInstances, ppDLP);
				CScene__DrawSelf(pThis, ppDLP, &usInstances);
			}
		}


		CScene__DrawEnvironment(pThis, ppDLP);
		func_8003098C(pThis);

		CScene__DrawInstances(pThis, ppDLP, &usInstances);

		CScene__DrawTransparentInstances(pThis, ppDLP);

		CSimplePool__Advance(&pThis->m_SimplePool);
		CSimplePool__Draw(&pThis->m_SimplePool, ppDLP, pThis->m_pceTextureSetsIndex);

		// must do some player stuff before particles to position them correctly
		if (!CCamera__InCinemaMode(&GetApp()->m_Camera))
			PreDrawSelf(pThis, &usInstances, ppDLP);

		CScene__DrawSky(pThis, ppDLP);

		func_800318D0(pThis, ppDLP);

		CFxSystem__Draw(&GetApp()->m_FxSystem, ppDLP) ;

		// must draw self after particles because it
		// clears the Z buffer
		if (!CCamera__InCinemaMode(&GetApp()->m_Camera))
		{
//			if (CTurokMovement.InSun)
//				COnScreen__DrawSun(ppDLP);

			CScene__DrawSelf(pThis, ppDLP, &usInstances);
		}

		func_8002B400(&pThis->m_ParticleSystem);

		CPickupMonitor__Update(&pThis->m_PickupMonitor) ;

		CUnindexedSet__Destruct(&usInstances);
	}
}
