#include "decompdecomp_sync_9a35ce0b1d79af06cca5.h"
#line 1 "func.c"
#line 1 "reference.c"
void func_8001C9D8(CGameObjectInstance *pThis, Gfx **ppDLP,
										 CCacheEntry *pceTextureSetsIndex)
{
	CIndexedSet				isObjectIndex,
								isGeometry,
								isCurrentAnim,
								isBlendAnim,
								isNodes;
	ROMAddress				*rpGeometryAddress;
	DWORD						geometrySize;
	void						*pbNodes;
	CCacheEntry				*pceGeometry;
	BOOL						isPlayer, isDevice, isAbsoluteAnim, isAlive, better, sendEvents;
	CVector3					vTCorners[8],
								vDelta,
								vShadowOffset;
	float						prevFrameIncrement,
								distFromPlayerSquared;
	CGameObjectInstance	*pPlayer;
	CMtxF						mfOrient;
//#define DRAW_BOUNDS
                  
                  
             
                    
      
	
	int						nNodes;
	CAnimDraw				AnimDraw;
 Mtx *oldDrawMtxs;

	isPlayer = (pThis == CEngineApp__GetPlayer(GetApp())) ;

	// Clear incase anything uses it (TRex!!)
	oldDrawMtxs = pThis->pmtDrawMtxs;
	pThis->pmtDrawMtxs = NULL ;

	//rmonPrintf("%x: Draw\n", pThis);

	// this routine will get called every frame for every
	// animated instance
///////////// NOT ANYMORE! ////////////////////////

	// don't draw enemies during ressurect - but update
	if ((GetApp()->m_Camera.m_Mode == CAMERA_CINEMA_TUROK_RESURRECT_MODE) &&
		 (pThis != CEngineApp__GetPlayer(GetApp())) &&
		 (!CGameObjectInstance__IsDevice(pThis)))
		return ;

	// Draw in "pickup key" cinema?
	if (    (pThis->ah.ih.m_pEA->m_wTypeFlags3 & AI_TYPE3_DONTDRAWONCINEMA)
		  && (GetApp()->m_Camera.m_Mode == CAMERA_CINEMA_TUROK_PICKUP_KEY_MODE) )
		return ;

	// not ready to draw first time yet
	//if (!pThis->m_nAnims || !pThis->m_pceObjectInfo)
	if (!pThis->m_nAnims)
		return;

	
	// scene.cpp checks for this
	ASSERT(pThis->m_pceObjectInfo);

	// make sure the anims index, object index, and object info are handy

	pThis->m_pceAnimsIndex = NULL;
   CCartCache__RequestBlock(GetCache(),
									 NULL, NULL, NULL,
                            &pThis->m_pceAnimsIndex,
                            pThis->m_rpAnims, IS_INDEX_SIZE(pThis->m_nAnims),
                            "Animations Index (draw)");

	pThis->m_pceObjectIndex = NULL;
   CCartCache__RequestBlock(GetCache(),
									 NULL, NULL, NULL,
									 &pThis->m_pceObjectIndex,
                            pThis->m_rpObject, IS_INDEX_SIZE(CART_GRAPHOBJ_nItems),
                            "Object Index (draw)");

	pThis->m_pceObjectInfo = NULL;
	CCartCache__RequestBlock(GetCache(),
									 NULL, NULL, NULL,
									 &pThis->m_pceObjectInfo,
									 pThis->m_rpObjectInfo, pThis->m_ObjectInfoSize,
									 "Object Info (draw)");

	if (!pThis->m_pceAnimsIndex || !pThis->m_pceObjectIndex || !pThis->m_pceObjectInfo)
		return;

	// make sure geometry and animation requests don't push these out of the cache
	CCacheEntry__ResetAge(pThis->m_pceAnimsIndex);
	CCacheEntry__ResetAge(pThis->m_pceObjectIndex);
	CCacheEntry__ResetAge(pThis->m_pceObjectInfo);

	// make sure anims index stays around
	//if (pThis->m_pceAnimsIndex)
	//	CCacheEntry__ResetAge(pThis->m_pceAnimsIndex);

	// make sure object index stays around
	//if (pThis->m_pceObjectIndex)
	//	CCacheEntry__ResetAge(pThis->m_pceObjectIndex);

	// need object info to figure out bounds and anims index to advance
	//if (pThis->m_pceObjectInfo && pThis->m_pceAnimsIndex)
	//{
	// make sure object info stays around
	//CCacheEntry__ResetAge(pThis->m_pceObjectInfo);

	// bounds check against anim rect
	//if (isPlayer || (isAlive || && (pThis->m_pBoss || CBoundsRect__IsOverlapping(&pThis->m_BoundsRect, &anim_bounds_rect))))

	if (CGameObjectInstance__IsGone(pThis))
	{
		ASSERT(pThis != CEngineApp__GetPlayer(GetApp()));
		prevFrameIncrement = D_800B6B00;
		CGameObjectInstance__DoAI(pThis);
		D_800B6B00 = prevFrameIncrement;

		CGameObjectInstance__SetNotVisible(pThis);

		// make sure old animation doesn't get used
		pThis->m_asCurrent.m_pceAnim = NULL;
	}
	//else if (isPlayer || pThis->m_pBoss || CBoundsRect__IsOverlapping(&pThis->m_BoundsRect, &anim_bounds_rect))
	else
	{
		pPlayer = CEngineApp__GetPlayer(GetApp());
		isPlayer = (pThis == pPlayer);
		isDevice = CGameObjectInstance__IsDevice(pThis);

		isAlive = !(pThis->m_AI.m_dwStatusFlags & AI_ALREADY_DEAD);

		if (!pThis->m_asCurrent.m_pceAnim)
			CGameObjectInstance__RequestInitialAnimation(pThis);

		if (pThis->m_asCurrent.m_pceAnim)
		{
			CCacheEntry__ResetAge(pThis->m_asCurrent.m_pceAnim);

			// allow AI to speed up/slow down animations
			prevFrameIncrement = D_800B6B00;

			CGameObjectInstance__PreDraw(pThis, ppDLP);

			CVector3__Subtract(&vDelta, &pThis->ah.ih.m_vPos, &pPlayer->ah.ih.m_vPos);
			distFromPlayerSquared = CVector3__MagnitudeSquared(&vDelta);

			sendEvents = FALSE;
			if (!isPlayer)
			{
#define AI_DISTANCE	50*SCALING_FACTOR
				if (		CGameObjectInstance__IsVisible(pThis)
						|| CGameObjectInstance__IsDevice(pThis)
						|| pThis->m_pBoss
						|| pThis->ah.ih.m_pEA->m_InteractiveAnim
						|| !pThis->m_AI.m_Health
						|| (distFromPlayerSquared < SQR(AI_DISTANCE)) )
				{
					sendEvents = TRUE;

					pThis->pmtDrawMtxs = oldDrawMtxs;
CGameObjectInstance__DoAI(pThis);
 pThis->pmtDrawMtxs = NULL;

					if (pThis->ah.ih.m_pEA->m_dwTypeFlags & AI_TYPE_SLOWENEMY)
						D_800B6B00 *= 0.5;

					// This function in "cinecam.cpp"
					D_800B6B00 *= CGameObjectInstance__AnimSpeedScaler(pThis) ;

					if (pThis->m_asCurrent.m_pceAnim)
						func_8001BAAC(pThis);
				}
			}

			if (pThis->m_asCurrent.m_pceAnim)
			{
				CIndexedSet__ConstructFromRawData(&isCurrentAnim,
														 	CCacheEntry__GetData(pThis->m_asCurrent.m_pceAnim),
														 	FALSE);

				if (CGameObjectInstance__IsBlending(pThis))
				{
					ASSERT(pThis->m_asBlend.m_pceAnim);
					CIndexedSet__ConstructFromRawData(&isBlendAnim,
															 	CCacheEntry__GetData(pThis->m_asBlend.m_pceAnim),
															 	FALSE);
				}

				if (!isPlayer)
				{
					//CGameObjectInstance__CalculateOrientationMatrix(pThis, isPlayer, vTCorners);
					CGameObjectInstance__CalculateOrientationMatrix(pThis, FALSE, vTCorners, mfOrient);

					if (sendEvents)
						CGameObjectInstance__SendAnimEvents(pThis, &isCurrentAnim, mfOrient);
				}

				// bounds check against view rect
				if (		isPlayer
						|| (		CBoundsRect__IsOverlapping(&pThis->m_BoundsRect, &D_800F9E20)
								&& (isDevice || (pThis->m_AI.m_dwStatusFlags2 & AI_VISIBLE)) ) )
				{
					// bounds check against view volume
					if (isPlayer || CViewVolume__IsOverlapping(&D_800F9D90, 8, isPlayer ? D_80119CC0 : vTCorners))
					{
						CGameObjectInstance__SetVisible(pThis);

						//ASSERT(pThis->m_pceObjectIndex);
						CIndexedSet__ConstructFromRawData(&isObjectIndex,
													 				CCacheEntry__GetData(pThis->m_pceObjectIndex),
													 				FALSE);

						// calculate address of geometry

   					rpGeometryAddress = func_8002DBF8(&isObjectIndex,
																	  							pThis->m_rpObject,
																	  							CART_GRAPHOBJ_isGeometry, &geometrySize);

						// request geometry data (will be decompressed)
						D_800237C0(&pThis->m_Geometry, GetCache(),
	  						 							rpGeometryAddress, geometrySize,
														pceTextureSetsIndex);

						pceGeometry = CGeometry__GetCacheEntry(&pThis->m_Geometry);
						if (pceGeometry)
						{
							// Get total nodes in object
							CIndexedSet__ConstructFromRawData(&isGeometry,
														 			 	CCacheEntry__GetData(pceGeometry),
														 			 	FALSE);

							pbNodes = CIndexedSet__GetAddress(&isGeometry, CART_GEOMETRY_isNodes);
							CIndexedSet__ConstructFromRawData(&isNodes, pbNodes, FALSE);
							nNodes = CIndexedSet__GetBlockCount(&isNodes);

							// get matrix table for drawing animated instances
							pThis->pmtDrawMtxs = CAnimationMtxs__RequestMtxTable(nNodes);
							if (pThis->pmtDrawMtxs)
							{
								// Update head tracking
								AI_PerformHeadTracking(pThis);

								isAbsoluteAnim = CGameObjectInstance__IsAbsoluteAnim(pThis, pThis->m_asCurrent.m_nAnim);

								if (isAbsoluteAnim)
								{
									vShadowOffset = CGameObjectInstance__GetNodeBlendPos(pThis, &pThis->m_asCurrent, 0);
									vShadowOffset.y = 0;
								}
								else
								{
									vShadowOffset.x = vShadowOffset.y = vShadowOffset.z = 0;
								}

								// draw shadow before model so model will be in front of shadow
								// never draw shadow for devices?
								if (!isDevice && !isPlayer)
									CGameObjectInstance__DrawShadow(pThis, ppDLP, &vShadowOffset);

								// instance orientation
  								gSPMatrix((*ppDLP)++,
						 					RSP_ADDRESS(&CGameObjectInstance__GetOrientationMatrix(pThis)),
	   				 					G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

								// draw some stuff with better quality anti-aliasing
								// || pThis->m_pBoss ?
								if (		(GetApp()->m_Mode == MODE_INTRO)
										|| (GetApp()->m_Mode == MODE_LEGALSCREEN)
										|| (GetApp()->m_Mode == MODE_TITLE)
										|| (isPlayer)
										|| (GetApp()->m_bPause))// || (pThis->ah.ih.m_pEA->m_dwTypeFlags & AI_TYPE_SNIPER))
								{
									better = TRUE;
								}
								else
								{
									// draw dead enemies with better quality
									if (isAlive)
									{
										// draw far enemies with better quality
										// (far enemies look much better with full anti-aliasing
										//  and don't take much screen area so they won't slow
										//  the game down much)
		#define BETTER_AA_DISTANCE	50*SCALING_FACTOR
										better = distFromPlayerSquared > SQR(BETTER_AA_DISTANCE);
									}
									else
									{
										better = TRUE;
									}
								}

								// draw instance
								AnimDraw.ppDLP = ppDLP;
								AnimDraw.pisNodes = &isNodes;
								AnimDraw.pisCurrentAnim = &isCurrentAnim;
								AnimDraw.pisBlendAnim = &isBlendAnim;
								AnimDraw.RemoveRootXZ = !((isPlayer && !GetApp()->m_Camera.m_CinemaMode) || isDevice || isAbsoluteAnim);
								AnimDraw.Better = better;
								//AnimDraw.Inter = isPlayer;
								AnimDraw.Inter = FALSE;



								// Update special general purpose mode ai
								switch(pThis->m_Mode)
								{
									case IDLE_MODE:
										break ;

									case TRANS_FADE_OUT_MODE:

										// Draw with trans mode!
										D_800B9878 = FXMODE_TOTRANSPARENT ;
										D_800B9888[0] = pThis->m_ModeTime ;	// Set trans

										// Only fade if not pausing
										if (!GetApp()->m_bPause)
											pThis->m_ModeTime += pThis->m_ModeMisc1 ;	// Misc1 = fade speed

										// Totally transparent?
										if (pThis->m_ModeTime <= MAX_TRANS)
										{
											CGameObjectInstance__SetGone(pThis) ;
											pThis->m_Mode = IDLE_MODE ;
										}
										break ;
								}


								if ((D_800B9878 != FXMODE_TOTRANSPARENT) || D_800B9888[0])
								{
									CGameObjectInstance__DoDraw(pThis, &AnimDraw, 0,
																	 	isPlayer ? D_80119D20 : mfOrient,
																	 	TRUE);

									D_800B9878 = FXMODE_NONE ;

									// add swoosh edge if a swoosh is active
									if (pThis->m_ActiveSwooshes)
										CFxSystem__CheckForAddingObjectSwooshEdge(&GetApp()->m_FxSystem, pThis, pThis->pmtDrawMtxs) ;
								}

                    
                                 
                                        
                              
         
                                                                                                                      
                                
                                                             
                                            
         
        

								CIndexedSet__Destruct(&isGeometry);
								CIndexedSet__Destruct(&isNodes);
							}
						}

						CIndexedSet__Destruct(&isObjectIndex);
					}
					else
					{
						CGameObjectInstance__SetNotVisible(pThis);
					}
				}
				else
				{
					CGameObjectInstance__SetNotVisible(pThis);
				}
			}

			CGameObjectInstance__PostDraw(pThis, ppDLP);
			D_800B6B00 = prevFrameIncrement;

			CIndexedSet__Destruct(&isCurrentAnim);
			if (CGameObjectInstance__IsBlending(pThis))
				CIndexedSet__Destruct(&isBlendAnim);
		}
	}
/*
	else
	{
		CGameObjectInstance__SetNotVisible(pThis);

		// make sure old animation doesn't get used
		pThis->m_asCurrent.m_pceAnim = NULL;
	}
*/
	//}
}

