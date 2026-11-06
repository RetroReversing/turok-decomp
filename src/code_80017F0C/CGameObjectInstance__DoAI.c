#include "common_local_source_3936.h"

#line 1 "reference.c"
void CGameObjectInstance__DoAI(CGameObjectInstance *pThis)
{
	// don't update devices in pause mode...
	if (GetApp()->m_bPause)
	{
		// Bosses may have a pause function (to cut off looping sounds etc)
		if ((pThis->m_pBoss) && (pThis->m_pBoss->m_pPauseFunction))
			pThis->m_pBoss->m_pPauseFunction(pThis, pThis->m_pBoss) ;

		return ;
	}

#ifndef KANJI
	if ( 		(GetApp()->m_Mode == MODE_GAME)
			&&	(GetApp()->m_dwCheatFlags & CHEATFLAG_DISCO)
			&& (pThis->m_AI.m_Health) )
	{
		switch (CGameObjectInstance__TypeFlag(pThis))
		{
			case AI_OBJECT_CHARACTER_RAPTOR:
			case AI_OBJECT_CHARACTER_HUMAN1:
			case AI_OBJECT_CHARACTER_DIMETRODON:
			case AI_OBJECT_CHARACTER_TRICERATOPS:
			case AI_OBJECT_CHARACTER_MOSCHOPS:
			case AI_OBJECT_CHARACTER_LEAPER:
			case AI_OBJECT_CHARACTER_ALIEN:
			case AI_OBJECT_CHARACTER_HULK:
			case AI_OBJECT_CHARACTER_ROBOT:
			case AI_OBJECT_CHARACTER_ANCIENTWARRIOR:
			case AI_OBJECT_CHARACTER_HIGHPRIEST:
				CGameObjectInstance__DiscoAI(pThis);
				return;
		}
	}
#endif

	switch (CGameObjectInstance__TypeFlag(pThis))
	{
		case AI_OBJECT_DEVICE_DOOR:
			// no AI -- all handled by events
			// for now, use random for testing
			//if (CGameObjectInstance__IsCycleCompleted(pThis))
			//	CGameObjectInstance__SetDesiredAnim(pThis, RANDOM(pThis->m_nAnims));
			DoorAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_ACTION:
		case AI_OBJECT_DEVICE_ANIMOFFSCREENACTION:
			ActionAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_TIMERACTION:
			TimerActionAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_PRESSUREACTION:
			PressureActionAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_CONSTANTACTION:
			ConstantActionAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_STATUE:
			StatueAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_WALL:
			WallAI_Advance(pThis);
			break;
//		case AI_OBJECT_DEVICE_SPINDOOR:
//			SpinDoorAI_Advance(pThis);
//			break;
		case AI_OBJECT_DEVICE_LASER:
			LaserAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_EXPTARGET:
			ExplosiveTargetAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_ELEVATOR:
		case AI_OBJECT_DEVICE_FOOTELEVATOR:
			ElevatorAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_PLATFORM:
			PlatformAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_DEATHELEVATOR:
			DeathElevatorAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_COLLAPSINGPLATFORM:
			CollapsingPlatformAI_Advance(pThis);
			break;


// TREX ELEVATOR AND PLATFORMS NOW GONE!!
#if 0

		case AI_OBJECT_DEVICE_TREXELEVATOR:
			TrexElevatorAI_Advance(pThis);
			break;

		case AI_OBJECT_DEVICE_TREXPLATFORM:
			TrexPlatformAI_Advance(pThis);
			break;
#endif

#if 0
// gone now!!
		case AI_OBJECT_DEVICE_LONGHUNTER_SWITCH:
			LonghunterSwitchAI_Advance(pThis);
			break;
#endif

		case AI_OBJECT_DEVICE_PORTAL:
			PortalAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_GATE:
			GateAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_LOCK:
			LockAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_DRAIN:
			DrainAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_FLOOD:
			FloodAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_CRYSTAL:
			CrystalAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_SPINELEVATOR:
			SpinElevatorAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_SPINPLATFORM:
			SpinPlatformAI_Advance(pThis);
			break;
		case AI_OBJECT_DEVICE_KEYFLOOR:
			KeyFloorAI_Advance(pThis);
			break;

		case AI_OBJECT_DEVICE_FADEINFADEOUT:
			FadeInFadeOutAI_Advance(pThis) ;
			break ;

		case AI_OBJECT_CEILING_TURRET:
			func_80090F68(pThis);
			break;
		case AI_OBJECT_BUNKER_TURRET:
			func_80090FC8(pThis);
			break;

		// the AI for the following is so simple that there isn't any!
		case AI_OBJECT_CINEMA_TUROK_ARROW:
		case AI_OBJECT_DEVICE_PICKUP_GERATOR:
			break ;

		default:

			// leave animating objects alone during intro and title!!
			if (		(GetApp()->m_Mode == MODE_INTRO)
					|| (GetApp()->m_Mode == MODE_TITLE)
					|| (GetApp()->m_Mode == MODE_LEGALSCREEN) )
			{
				return;
			}

#ifdef RANDOM_AI
			if (CGameObjectInstance__IsCycleCompleted(pThis))
				AI_SetDesiredAnimByIndex(pThis, RANDOM(pThis->m_nAnims), FALSE);
#else
			// set cycle completed flag for AI
			if (CGameObjectInstance__IsCycleCompleted(pThis))
				pThis->m_AI.m_dwStatusFlags |= AI_CYCLECOMPLETED;
			else
				pThis->m_AI.m_dwStatusFlags &= (~AI_CYCLECOMPLETED);

// TEMP S.B.
			if ((GetApp()->m_bPause) && (!pThis->m_pBoss))
//			if (1)
			{
				CGameObjectInstance__PauseAI(pThis);
			}
			else
			{
				if (pThis->m_pBoss)
					func_8003FC00(pThis);
				else if (GetApp()->m_Mode == MODE_GALLERY)
					AI_Advance_Gallery(pThis);
				else
					AI_Advance(pThis);
			}
#endif
			break;
	}

	// Update head tracking
	//AI_PerformHeadTracking(pThis) ;
}
