#include "decompdecomp_sync_d6095e54d0fdaf22d092.h"
#line 1 "func.c"
#line 2733 "reference.c"
void AI_MEvent_PressurePlate(CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value)
{
//	float		radiusSquared;
//	CVector3	vDelta;
//	float		radius ;
	int		nAnim;
	FLOAT		Id ;
	BOOL		Activated = FALSE ;
	BOOL		floorcheck ;

//	radius = 90 * SCALING_FACTOR;
//	radiusSquared = radius*radius ;

//	CVector3__Subtract(&vDelta, &pAI->ah.ih.m_vPos, &vPos);

	// Special case id checking types
	switch (CGameObjectInstance__TypeFlag(pAI))
	{
		// Special walls in MANTIS BOSS stage
		case AI_OBJECT_DEVICE_WALL:
			// Only mantis can trigger breakable walls, if on wall or flying
			//if ((nType == AI_OBJECT_CHARACTER_MANTIS_BOSS) &&
			if ((CInstanceHdr__TypeFlag(pOrigin) == AI_OBJECT_CHARACTER_MANTIS_BOSS) &&
				 (((CGameObjectInstance *)pOrigin)->m_pBoss->m_ModeFlags & (BF_LEFT_WALL_MODE | BF_RIGHT_WALL_MODE | BF_FLYING_MODE)))
			{
				// if already activated, then don't bother
				if ((pAI->m_AI.m_dwStatusFlags & AI_DOOROPEN) == 0)
				{
					// Wall ids are 1,2,3,4. Pressure id's are 10,11, 20,21, 30,31, 40,41.
					Id = AI_GetEA(pAI)->m_Id * 10 ;

					// Check for matching left right actions
					if (Id == Value)
					{
						WallAI_MEvent_Left(pAI);
						Activated = TRUE ;
					}
					else
					if ((Id+1) == Value)
					{
					 	WallAI_MEvent_Right(pAI);
						Activated = TRUE ;
					}

					// Update vars
					if (Activated)
					{
						// Update broken wall flags
						((CMantis *)((CGameObjectInstance *)pOrigin)->m_pBoss)->m_WallBroken[AI_GetEA(pAI)->m_Id - 1] = TRUE ;
						((CMantis *)((CGameObjectInstance *)pOrigin)->m_pBoss)->m_WallsToBreak-- ;
					}
				}
			}
			return ;
	}


	// SPECIAL CASE,
	// if ID = id of a door +100, close it (and player on ground)
	if ((AI_GetEA(pAI)->m_Id+100) == (short)Value)
	{
		switch (CGameObjectInstance__TypeFlag(pAI))
		{
			case AI_OBJECT_DEVICE_DOOR:
//				if ((CEngineApp__GetPlayer(GetApp()) == (CGameObjectInstance *)pOrigin) &&
//					(CInstanceHdr__IsOnGround(&CEngineApp__GetPlayer(GetApp())->ah.ih)))

				DoorAI_MEvent_OpenClose(pAI, FALSE);
				break ;

			// make crystal sink
			case AI_OBJECT_DEVICE_CRYSTAL:
				CrystalAI_MEvent_Start(pAI, FALSE);
				break ;
		}
	}


	// Id checking types
	if (AI_GetEA(pAI)->m_Id != (short)Value)
		return ;


	switch (CGameObjectInstance__TypeFlag(pAI))
	{
		case AI_OBJECT_DEVICE_DOOR:
			// only player can trigger doors (so MANTIS doesnt trigger crystal)
//			if (CEngineApp__GetPlayer(GetApp()) == (CGameObjectInstance *)pOrigin)

			DoorAI_MEvent_OpenClose(pAI, TRUE);
			break;

		case AI_OBJECT_DEVICE_ACTION:
		case AI_OBJECT_DEVICE_ANIMOFFSCREENACTION:
			// only player can trigger actions (so MANTIS doesnt trigger rising walls)
			//if (CEngineApp__GetPlayer(GetApp()) == (CGameObjectInstance *)pOrigin)
				ActionAI_MEvent_Go(pAI);
			break;

		case AI_OBJECT_DEVICE_TIMERACTION:
			TimerActionAI_MEvent_Go(pAI);
			break;

		case AI_OBJECT_DEVICE_PRESSUREACTION:
			PressureActionAI_MEvent_Go(pAI);
			break;
     
           
                                          
                                            
         
      

		case AI_OBJECT_DEVICE_PORTAL:
			PortalAI_MEvent_Start(pAI);
			break;

		case AI_OBJECT_DEVICE_LOCK:
			LockAI_MEvent_Start(pAI);
			break;


		case AI_OBJECT_CHARACTER_RAPTOR:
		case AI_OBJECT_CHARACTER_HUMAN1:
		case AI_OBJECT_CHARACTER_SABERTIGER:
		case AI_OBJECT_CHARACTER_DIMETRODON:
		case AI_OBJECT_CHARACTER_TRICERATOPS:
		case AI_OBJECT_CHARACTER_MOSCHOPS:
		case AI_OBJECT_CHARACTER_PTERANODON:
		case AI_OBJECT_CHARACTER_SUBTERRANEAN:
		case AI_OBJECT_CHARACTER_LEAPER:
		case AI_OBJECT_CHARACTER_ALIEN:
		case AI_OBJECT_CHARACTER_HULK:
		case AI_OBJECT_CHARACTER_ROBOT:
		case AI_OBJECT_CHARACTER_BADFISH:
		case AI_OBJECT_CHARACTER_GOODFISH:
		case AI_OBJECT_CHARACTER_SLUDGEBOY:
		case AI_OBJECT_CHARACTER_PLANT:
		case AI_OBJECT_CHARACTER_ANCIENTWARRIOR:
		case AI_OBJECT_CHARACTER_HIGHPRIEST:
		case AI_OBJECT_CEILING_TURRET:
		case AI_OBJECT_BUNKER_TURRET:
		case AI_OBJECT_CHARACTER_GENERICRED:
		case AI_OBJECT_CHARACTER_GENERICGREEN:
		case AI_OBJECT_CHARACTER_GENERICMETAL:

			// pickups do not need to be on floor...
			floorcheck = TRUE ;
			if (pOrigin->m_Type == I_SIMPLE)
				floorcheck = FALSE ;
			if (AI_GetDyn(pAI)->m_dwStatusFlags & AI_INTERACTIVEANIMATION)
			{
				if ((floorcheck) && (CInstanceHdr__IsOnGround(&CEngineApp__GetPlayer(GetApp())->ah.ih)==FALSE))
					break ;

				AI_GetDyn(pAI)->m_dwStatusFlags &= ~AI_INTERACTIVEANIMATION;
				AI_GetDyn(pAI)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;

				if (!(AI_GetDyn(pAI)->m_dwStatusFlags & AI_INTERANIMDELAY))
				{
					nAnim = AI_GetEA(pAI)->m_InteractiveAnim - 1 + AI_ANIM_INTERACTIVE_ANIMATION1;
					AI_GetDyn(pAI)->m_dwStatusFlags2 &= ~AI_HOLDINTANIMON1STFRAME;
					AI_SetDesiredAnim(pAI, nAnim, TRUE);
					CGameObjectInstance__RestartAnim(pAI);
					//AI_GetDyn(pAI)->m_Invincible = TRUE;
					AI_GetDyn(pAI)->m_dwStatusFlags2 |= AI_VISIBLE;
				}
			}
			break ;


		// rotating doors
		//case AI_OBJECT_DEVICE_SPINDOOR:
		//	SpinDoorAI_MEvent_Spin(pAI);
		//	break;


		// laser
		case AI_OBJECT_DEVICE_LASER:
			// only player can trigger lasers
			if (CEngineApp__GetPlayer(GetApp()) == (CGameObjectInstance *)pOrigin)
				LaserAI_MEvent_Start(pAI);
			break;

		// elevators
		case AI_OBJECT_DEVICE_ELEVATOR:
		case AI_OBJECT_DEVICE_FOOTELEVATOR:
			ElevatorAI_MEvent_Start(pAI);
			break;
		// platforms
		case AI_OBJECT_DEVICE_PLATFORM:
			PlatformAI_MEvent_Start(pAI);
			break;
		// deathelevators
		case AI_OBJECT_DEVICE_DEATHELEVATOR:
			DeathElevatorAI_MEvent_Start(pAI);
			break;
		// collapsing platform
		case AI_OBJECT_DEVICE_COLLAPSINGPLATFORM:
			CollapsingPlatformAI_MEvent_Start(pAI);
			break;

// TREX ELEVATOR AND PLATFORMS NOW GONE!!
     

                  
                                     
                                    
         

                  
                                     
                                    
         
      


		// drain
		case AI_OBJECT_DEVICE_DRAIN:
			DrainAI_MEvent_Start(pAI);
			break;
		// flood
		case AI_OBJECT_DEVICE_FLOOD:
			FloodAI_MEvent_Start(pAI);
			break;

		// crystal
		case AI_OBJECT_DEVICE_CRYSTAL:
			// only player can trigger crystal on mantis level
			if (CEngineApp__GetPlayer(GetApp()) == (CGameObjectInstance *)pOrigin)
				CrystalAI_MEvent_Start(pAI, TRUE);
			break;
		// spin elevator
		case AI_OBJECT_DEVICE_SPINELEVATOR:
			SpinElevatorAI_MEvent_Start(pAI);
			break;
		// spin platform
		case AI_OBJECT_DEVICE_SPINPLATFORM:
			SpinPlatformAI_MEvent_Start(pAI);
			break;


		// FadeInFadeOut device
		case AI_OBJECT_DEVICE_FADEINFADEOUT:
			FadeInFadeOutAI_MEvent_ToggleState(pAI) ;
			break ;
	}
}

