#include "decompdecomp_sync_4b6b6ac4808805711b3e.h"
#line 1 "func.c"
#line 1436 "reference.c"
void CScene__DecompressInstances(CScene *pThis, CCacheEntry **ppceTarget)
{
	CUnindexedSet			usInstances,
								usGameInstances,
								usRegions,
								usObjectAttributes;
	CIndexedSet				isObjectsIndex,
								isCollision;
	int						newSize,
								cInstance, nInstances,
								nTypeFlag,
								startupAnim, StartupAnimFrame ;
	BOOL						instanceFlag;
	BOOL						access ;
	void						*pNewData,
								*pbRegions;
   CROMObjectInstance   *pROMInstances, *pROMInstance;
   CGameObjectInstance  *pGameInstances, *pGameInstance;
	CGameRegion				*regions;
	CEnemyAttributes		*variations;
	INT32						BossFlags ;


               
                                         
      

	ASSERT(ppceTarget == &pThis->m_pceInstances);
	ASSERT(pThis->m_pceCollision);
	ASSERT(pThis->m_pceObjectsIndex);
	ASSERT(pThis->m_pceInstances);

	// must already have been received in order to decompress instances
	ASSERT(pThis->m_pceObjectsIndex);

	if (!CCacheEntry__DecompressTemp(*ppceTarget))
		return;

	TRACE0("CScene: Decompressing instance data.\r\n");
               
                           
      

	// get base ptr to regions
	CIndexedSet__ConstructFromRawData(&isCollision,
												 CCacheEntry__GetData(pThis->m_pceCollision),
												 FALSE);

	pbRegions = CIndexedSet__GetAddress(&isCollision, CART_COLLISION_usRegions);

	CUnindexedSet__ConstructFromRawData(&usRegions, pbRegions, FALSE);
	regions = (CGameRegion*) CUnindexedSet__GetBasePtr(&usRegions);

	// attatch collection for CGameObjectInstance__Reset()
	CIndexedSet__ConstructFromRawData(&isObjectsIndex,
												 CCacheEntry__GetData(pThis->m_pceObjectsIndex),
												 FALSE);

	// attatch collection to old data
   CUnindexedSet__ConstructFromRawData(&usInstances,
													CCacheEntry__GetData(pThis->m_pceInstances),
													FALSE);

	nInstances = CUnindexedSet__GetBlockCount(&usInstances);
	ASSERT(nInstances >= 1);	// first one is viewer
	TRACE("There are %d animated instances.\r\n", nInstances);

	// allocate block for new data collection
   newSize = US_TOTAL_SIZE(sizeof(CGameObjectInstance), nInstances);

	pNewData = CCacheEntry__AllocDataForReplacement(pThis->m_pceInstances, newSize);
   if (pNewData)
   {
      ASSERT(sizeof(CGameObjectInstance) >= sizeof(CROMObjectInstance));
		CUnindexedSet__DeinterleaveCopy(&usInstances, pNewData, TRUE);

		// set up new collection
      func_8002DA18(&usGameInstances,
                                                 pNewData,                    // data ptr
                                                 sizeof(CGameObjectInstance), // block size
                                                 nInstances,						// block count
                                                 FALSE);                      // don't auto delete data

      // do decompression

      pROMInstances = (CROMObjectInstance*) CUnindexedSet__GetBasePtr(&usInstances);
      pGameInstances = (CGameObjectInstance*) CUnindexedSet__GetBasePtr(&usGameInstances);

		ASSERT(pThis->m_pceObjectAttributes);
		CUnindexedSet__ConstructFromRawData(&usObjectAttributes,
														CCacheEntry__GetData(pThis->m_pceObjectAttributes),
														FALSE);

		variations = (CEnemyAttributes*) CUnindexedSet__GetBasePtr(&usObjectAttributes);

		ASSERT(nInstances);

		if (pThis->m_WarpFound)
		{
			// use m_WarpPoint to position player

         pROMInstance = &pROMInstances[0];

			pROMInstance->m_nCurrentRegion = pThis->m_WarpPoint.m_nRegion;

			NormalizeRotation(&pThis->m_WarpPoint.m_RotY);
			pROMInstance->m_RotY = FLOAT2INT16(max(-ANGLE_PI, min(ANGLE_PI, pThis->m_WarpPoint.m_RotY)), ANGLE_PI);

			pROMInstance->m_vPos = pThis->m_WarpPoint.m_vPos;
		}

		for (cInstance=0; cInstance<nInstances; cInstance++)
		{
         pROMInstance = &pROMInstances[cInstance];
			pGameInstance = &pGameInstances[cInstance];

			CGameObjectInstance__TakeFromROMObjectInstance(pGameInstance, pROMInstance,
																		  regions, variations);

			nTypeFlag = CGameObjectInstance__TypeFlag(pGameInstance);

			CAIDynamic__SetHealth(&pGameInstance->m_AI,
										 pGameInstance->ah.ih.m_pEA,
										 nTypeFlag);

			// Boss reset?
			BossFlags = GetApp()->m_BossFlags ;
			if ((BossFlags & BOSS_FLAG_RESET_LEVEL) && (GetApp()->m_BossLevel))
				CScene__SetInstanceFlagByIndex(pThis, cInstance, FALSE) ;

			instanceFlag = CScene__GetInstanceFlagByIndex(pThis, cInstance);

			startupAnim = -1;	// use first anim in list by default
			StartupAnimFrame = 0 ;

			switch (nTypeFlag)
			{
				// types that need setting properly
				case AI_OBJECT_DEVICE_DOOR:
					if (instanceFlag)
					{
						startupAnim = AI_ANIM_DOOR_OPEN ;
						pGameInstance->m_AI.m_dwStatusFlags |= (AI_STARTED|AI_DOOROPEN) ;
						pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;
						pGameInstance->m_AI.m_RetreatTimer = 0 ;
					}
					break ;

				case AI_OBJECT_DEVICE_ACTION:
				case AI_OBJECT_DEVICE_ANIMOFFSCREENACTION:

					// Setup start
					if (instanceFlag)
					{
						// Special cases
						if ((GetApp()->m_BossLevel == MANTIS_BOSS_LEVEL) &&
							 (AI_GetEA(pGameInstance)->m_Id == MANTIS_LEVEL_UP_WALLS_ID))
							CGameObjectInstance__SetGone(pGameInstance) ;
						else				
						{
							startupAnim = AI_ANIM_ACTION_GO ;
							pGameInstance->m_AI.m_dwStatusFlags |= AI_STARTED ;
							pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;
						}
					}
					break ;

				case AI_OBJECT_DEVICE_EXPTARGET:
					if (instanceFlag)
					{
						startupAnim = AI_ANIM_EXPTARGET_GO ;
						pGameInstance->m_AI.m_dwStatusFlags |= AI_STARTED ;
						pGameInstance->m_AI.m_dwStatusFlags |= AI_ALREADY_DEAD ;
						pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;
					}
					break ;

				// if elevator is set, must be at its extreme
				case AI_OBJECT_DEVICE_ELEVATOR:
				case AI_OBJECT_DEVICE_SPINELEVATOR:
				case AI_OBJECT_DEVICE_FOOTELEVATOR:

					// Set startup
					if (instanceFlag)
					{
						pGameInstance->m_AI.m_dwStatusFlags |= (AI_STARTED | AI_DOOROPEN) ;

						// store original positions
						pGameInstance->m_AI.m_Time2 = pGameInstance->ah.ih.m_vPos.y ;
						pGameInstance->m_AI.m_TeleportTime = CGameRegion__GetGroundHeight(pGameInstance->ah.ih.m_pCurrentRegion, pGameInstance->ah.ih.m_vPos.x, pGameInstance->ah.ih.m_vPos.z) ;

						pGameInstance->m_AI.m_Time1 = 1 ;		// extreme time
					}
					break ;

				case AI_OBJECT_DEVICE_PLATFORM:
					if (instanceFlag)
					{
						pGameInstance->m_AI.m_Time1 = 0 ;
						pGameInstance->m_AI.m_dwStatusFlags |= (AI_STARTED | AI_DOOROPEN) ;
						pGameInstance->m_AI.m_dwStatusFlags &= ~AI_DOORPREOPEN;
						pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;

						// store original positions
						pGameInstance->m_AI.m_Time2 = pGameInstance->ah.ih.m_vPos.y ;
						pGameInstance->m_AI.m_TeleportTime = CGameRegion__GetGroundHeight(pGameInstance->ah.ih.m_pCurrentRegion, pGameInstance->ah.ih.m_vPos.x, pGameInstance->ah.ih.m_vPos.z) ;
					}
					break ;



				case AI_OBJECT_DEVICE_PORTAL:
					access = FALSE ;
					switch (AI_GetEA(pGameInstance)->m_Id)
					{
						case 2:
							if (D_80128C20.Level2Access >= MAX_KEY2)
								access = TRUE ;
							break ;
						case 3:
							if (D_80128C20.Level3Access >= MAX_KEY3)
								access = TRUE ;
							break ;
						case 4:
							if (D_80128C20.Level4Access >= MAX_KEY4)
								access = TRUE ;
							break ;
						case 5:
							if (D_80128C20.Level5Access >= MAX_KEY5)
								access = TRUE ;
							break ;
						case 6:
							if (D_80128C20.Level6Access >= MAX_KEY6)
								access = TRUE ;
							break ;
						case 7:
							if (D_80128C20.Level7Access >= MAX_KEY7)
								access = TRUE ;
							break ;
						case 8:
							if (D_80128C20.Level8Access >= MAX_KEY8)
								access = TRUE ;
							break ;
					}

					if ((access) || (instanceFlag))
					{
						pGameInstance->m_AI.m_Time1 = 1 ;
						pGameInstance->m_AI.m_dwStatusFlags |= AI_STARTED ;
						pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;
					}
					break ;

				case AI_OBJECT_DEVICE_DRAIN:
					if (instanceFlag)
					{
						pGameInstance->m_AI.m_dwStatusFlags |= (AI_STARTED | AI_DOOROPEN | AI_DOORPREOPEN) ;
						pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;
					}
					break ;

				case AI_OBJECT_DEVICE_FLOOD:
					if (instanceFlag)
					{
						pGameInstance->m_AI.m_dwStatusFlags |= AI_STARTED ;
						pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;

						CGameRegion__UnMakeInstantDeath(pGameInstance->ah.ih.m_pCurrentRegion) ;
						CGameRegion__ToWater(pGameInstance->ah.ih.m_pCurrentRegion) ;
					}
					break ;

				case AI_OBJECT_DEVICE_LOCK:
					if (instanceFlag)
					{
						pGameInstance->m_AI.m_dwStatusFlags |= (AI_STARTED | AI_DOOROPEN) ;
						pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;

						// store original positions
						pGameInstance->m_AI.m_Time2 = pGameInstance->ah.ih.m_vPos.y ;
						pGameInstance->m_AI.m_TeleportTime = CGameRegion__GetGroundHeight(pGameInstance->ah.ih.m_pCurrentRegion, pGameInstance->ah.ih.m_vPos.x, pGameInstance->ah.ih.m_vPos.z) ;

						pGameInstance->m_AI.m_Time1 = 1 ;		// extreme time
					}
					break ;

				// randomize the humans features
				case AI_OBJECT_CHARACTER_HUMAN1:
					if (instanceFlag)
						CGameObjectInstance__SetGone(pGameInstance);

					CAIDynamic__RandomizeHuman(AI_GetDyn(pGameInstance), AI_GetEA(pGameInstance), pGameInstance) ;
					break ;

				// reset to initial state
				case AI_OBJECT_DEVICE_ARROWTARGET:
				case AI_OBJECT_DEVICE_TIMERACTION:
				case AI_OBJECT_DEVICE_CONSTANTACTION:
				case AI_OBJECT_DEVICE_SPINDOOR:
				case AI_OBJECT_DEVICE_LASER:
				case AI_OBJECT_DEVICE_SPINPLATFORM:
				case AI_OBJECT_DEVICE_DEATHELEVATOR:
				case AI_OBJECT_DEVICE_TREXPLATFORM:
				case AI_OBJECT_DEVICE_COLLAPSINGPLATFORM:
				case AI_OBJECT_DEVICE_GATE:
				case AI_OBJECT_DEVICE_KEYFLOOR:
					break ;

// TREX ELEVATOR AND PLATFORMS NOW GONE!!
     
                                       
                      
      
                                                                      
                                                   
      
            
      

				case AI_OBJECT_DEVICE_CRYSTAL:
					if (BossFlags & BOSS_FLAG_MANTIS_CRYSTAL_STARTED)
					{
						pGameInstance->m_AI.m_dwStatusFlags |= AI_STARTED ;
						pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;
						pGameInstance->m_AI.m_TeleportTime = 0 ;
						pGameInstance->m_AI.m_Time1 = 0 ;
						pGameInstance->m_AI.m_Time2 = 0 ;

						if (BossFlags & BOSS_FLAG_MANTIS_CRYSTAL_DOWN)
						{
							startupAnim = AI_ANIM_CRYSTAL_SINK ;
							pGameInstance->m_AI.m_dwStatusFlags |= AI_DOOROPEN;
							pGameInstance->m_AI.m_TeleportTime = 0 ;

						}
						else
						{
							startupAnim = AI_ANIM_CRYSTAL_RISE ;
							pGameInstance->m_AI.m_dwStatusFlags |= AI_DOOROPEN;
							pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;
							pGameInstance->m_AI.m_TeleportTime = 0 ;

						}
					}
					break ;

				case AI_OBJECT_DEVICE_WALL:

					// There?
					if (instanceFlag)
						CGameObjectInstance__SetGone(pGameInstance) ;
					break ;

				case AI_OBJECT_DEVICE_STATUE:

					if (BossFlags & BOSS_FLAG_MANTIS_CACOON_OPEN)
						CGameObjectInstance__SetGone(pGameInstance) ;
					break ;

				// Boss status may need to be restored
				case AI_OBJECT_CHARACTER_MANTIS_BOSS:
				case AI_OBJECT_CHARACTER_TREX_BOSS:
				case AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS:
				case AI_OBJECT_CHARACTER_LONGHUNTER_BOSS:
				case AI_OBJECT_CHARACTER_HUMVEE_BOSS:

					// Start bosses on saved frames
					if (CBossesStatus__BossWasSaved(&GetApp()->m_BossesStatus, pGameInstance))
					{
						startupAnim = CBossesStatus__BossWasSaved(&GetApp()->m_BossesStatus, pGameInstance)->m_Anim ;
						StartupAnimFrame = CBossesStatus__BossWasSaved(&GetApp()->m_BossesStatus, pGameInstance)->m_CurrentAnimFrame ;
						CBossesStatus__RestoreBossStatus(&GetApp()->m_BossesStatus, pGameInstance) ;
					}	
					break ;

				case AI_OBJECT_DEVICE_FADEINFADEOUT:

					switch(AI_GetEA(pGameInstance)->m_Id)
					{
						case LONGHUNT_LEVEL_FORCEFIELD_ID:
							if (!(GetApp()->m_BossFlags & BOSS_FLAG_LONGHUNTER_FORCEFIELD_GONE))
							{	
								pGameInstance->m_AI.m_dwStatusFlags |= AI_STARTED | AI_DOOROPEN ;
								pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;
								CGameObjectInstance__SetNotGone(pGameInstance) ;
							}
							break ;

						case LONGHUNT_LEVEL_WATER1_ID:
						case LONGHUNT_LEVEL_WATER2_ID:
						case LONGHUNT_LEVEL_WATER3_ID:
						case LONGHUNT_LEVEL_WATER4_ID:
//							if (GetApp()->m_BossFlags & BOSS_FLAG_LONGHUNTER_SWITCH_PRESSED)
							if (GetApp()->m_BossFlags & BOSS_FLAG_LONGHUNTER_DEAD)
							{
								pGameInstance->m_AI.m_dwStatusFlags |= AI_STARTED | AI_DOOROPEN ;
								pGameInstance->m_AI.m_dwStatusFlags2 |= AI_IGNORESOUNDEVENTS ;
								CGameObjectInstance__SetNotGone(pGameInstance) ;
							}
							break ;
					}

					break ;
     
             
                                            
                                                         
      
                                                                       
                                                                    
                                                  
      
            
      

				case AI_OBJECT_CINEMA_TUROK_ARROW:
					switch(GetApp()->m_WarpID)
					{
						case INTRO_ZOOM_TO_LOGO_WARP_ID:
							startupAnim = AI_ANIM_WEAPON_FIRE1 ;
							break ;

						default:
							startupAnim = AI_ANIM_WEAPON_IDLE ;
							break ;
					}
					break ;

				case AI_OBJECT_CHARACTER_PLAYER:
					switch(GetApp()->m_WarpID)
					{
						case INTRO_TUROK_DRAWING_BOW_WARP_ID:
							startupAnim = AI_ANIM_EXTRA1 ;
							break ;
					}
					break ;

				// non device animated instances
				default:
					if (instanceFlag)
						CGameObjectInstance__SetGone(pGameInstance);
					break;
			}

			func_8001E890(pGameInstance,
												&isObjectsIndex, pThis->m_rpObjectsAddress,
												startupAnim);

			// Anim not starting on frame 0?
			if (StartupAnimFrame)
			{
				pGameInstance->m_asCurrent.m_cFrame = StartupAnimFrame ;
				CGameObjectInstance__SetAnimNotChanged(pGameInstance) ;
				CGameObjectInstance__SetNotBlending(pGameInstance) ;
				pGameInstance->m_asCurrent.m_cFrame = StartupAnimFrame ;
			}
		}

      CUnindexedSet__Destruct(&usGameInstances);
		CUnindexedSet__Destruct(&usObjectAttributes);
   }

	CCacheEntry__DeallocAndReplaceData(pThis->m_pceInstances, pNewData, newSize);

               
                         
                                
      

	TRACE("CScene: ...Finished instance decompression in %8.2f msec.\r\n",
			((float)(CYCLES_TO_NSEC(diffTime)))/1000000);

	CIndexedSet__Destruct(&isCollision);
	CUnindexedSet__Destruct(&usRegions);
	CIndexedSet__Destruct(&isObjectsIndex);
	CUnindexedSet__Destruct(&usInstances);


	GetApp()->m_BossFlags &= ~BOSS_FLAG_RESET_LEVEL ;
}

