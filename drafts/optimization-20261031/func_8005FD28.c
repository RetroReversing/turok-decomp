#include "context_c261466cf085.h"
#line 1 "func.c"
#line 1 "reference.c"
void func_8005FD28(CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value)
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
			if ((func_8001D398(pOrigin) == AI_OBJECT_CHARACTER_MANTIS_BOSS) &&
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
						func_8008FD20(pAI);
						Activated = TRUE ;
					}
					else
					if ((Id+1) == Value)
					{
					 	func_8008FDA4(pAI);
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

				func_8008F948(pAI, FALSE);
				break ;

			// make crystal sink
			case AI_OBJECT_DEVICE_CRYSTAL:
				func_80090830(pAI, FALSE);
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

			func_8008F948(pAI, TRUE);
			break;

		case AI_OBJECT_DEVICE_ACTION:
		case AI_OBJECT_DEVICE_ANIMOFFSCREENACTION:
			// only player can trigger actions (so MANTIS doesnt trigger rising walls)
			//if (CEngineApp__GetPlayer(GetApp()) == (CGameObjectInstance *)pOrigin)
				func_8008FB0C(pAI);
			break;

		case AI_OBJECT_DEVICE_TIMERACTION:
			func_8008FB9C(pAI);
			break;

		case AI_OBJECT_DEVICE_PRESSUREACTION:
			func_8008FC3C(pAI);
			break;
#if 0
// Gone now
		case AI_OBJECT_DEVICE_LONGHUNTER_SWITCH:
			LonghunterSwitchAI_MEvent_Go(pAI, Value);
			break;
#endif

		case AI_OBJECT_DEVICE_PORTAL:
			func_800901E0(pAI);
			break;

		case AI_OBJECT_DEVICE_LOCK:
			func_80090330(pAI);
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
				if ((floorcheck) && (func_8001BA24(&CEngineApp__GetPlayer(GetApp())->ah.ih)==FALSE))
					break ;

				AI_GetDyn(pAI)->m_dwStatusFlags &= ~AI_INTERACTIVEANIMATION;
				AI_GetDyn(pAI)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;

				if (!(AI_GetDyn(pAI)->m_dwStatusFlags & AI_INTERANIMDELAY))
				{
					nAnim = AI_GetEA(pAI)->m_InteractiveAnim - 1 + AI_ANIM_INTERACTIVE_ANIMATION1;
					AI_GetDyn(pAI)->m_dwStatusFlags2 &= ~AI_HOLDINTANIMON1STFRAME;
					func_8005FCF4(pAI, nAnim, TRUE);
					func_8001E93C(pAI);
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
				func_8008FE28(pAI);
			break;

		// elevators
		case AI_OBJECT_DEVICE_ELEVATOR:
		case AI_OBJECT_DEVICE_FOOTELEVATOR:
			func_8008FF34(pAI);
			break;
		// platforms
		case AI_OBJECT_DEVICE_PLATFORM:
			func_80090064(pAI);
			break;
		// deathelevators
		case AI_OBJECT_DEVICE_DEATHELEVATOR:
			func_800900E4(pAI);
			break;
		// collapsing platform
		case AI_OBJECT_DEVICE_COLLAPSINGPLATFORM:
			func_80090154(pAI);
			break;

// TREX ELEVATOR AND PLATFORMS NOW GONE!!
#if 0

		// trex elevator
		case AI_OBJECT_DEVICE_TREXELEVATOR:
			TrexElevatorAI_MEvent_Start(pAI);
			break;

		// trex platform
		case AI_OBJECT_DEVICE_TREXPLATFORM:
			TrexPlatformAI_MEvent_Start(pAI);
			break;
#endif


		// drain
		case AI_OBJECT_DEVICE_DRAIN:
			func_80090738(pAI);
			break;
		// flood
		case AI_OBJECT_DEVICE_FLOOD:
			func_800907CC(pAI);
			break;

		// crystal
		case AI_OBJECT_DEVICE_CRYSTAL:
			// only player can trigger crystal on mantis level
			if (CEngineApp__GetPlayer(GetApp()) == (CGameObjectInstance *)pOrigin)
				func_80090830(pAI, TRUE);
			break;
		// spin elevator
		case AI_OBJECT_DEVICE_SPINELEVATOR:
			func_80090988(pAI);
			break;
		// spin platform
		case AI_OBJECT_DEVICE_SPINPLATFORM:
			func_80090A1C(pAI);
			break;


		// FadeInFadeOut device
		case AI_OBJECT_DEVICE_FADEINFADEOUT:
			func_80090A8C(pAI) ;
			break ;
	}
}

