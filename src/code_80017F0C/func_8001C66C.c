#include "common_local_source_3936.h"

#line 1 "reference.c"
void func_8001C66C(CGameObjectInstance *pThis)
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
				func_8001C5E8(pThis);
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
			func_8008DDA4(pThis);
			break;
		case AI_OBJECT_DEVICE_ACTION:
		case AI_OBJECT_DEVICE_ANIMOFFSCREENACTION:
			func_8008DF0C(pThis);
			break;
		case AI_OBJECT_DEVICE_TIMERACTION:
			func_8008DF58(pThis);
			break;
		case AI_OBJECT_DEVICE_PRESSUREACTION:
			func_8008E1D4(pThis);
			break;
		case AI_OBJECT_DEVICE_CONSTANTACTION:
			func_8008E314(pThis);
			break;
		case AI_OBJECT_DEVICE_STATUE:
			func_8008E488(pThis);
			break;
		case AI_OBJECT_DEVICE_WALL:
			func_8008E4D4(pThis);
			break;
//		case AI_OBJECT_DEVICE_SPINDOOR:
//			SpinDoorAI_Advance(pThis);
//			break;
		case AI_OBJECT_DEVICE_LASER:
			func_8008E520(pThis);
			break;
		case AI_OBJECT_DEVICE_EXPTARGET:
			func_8008E660(pThis);
			break;
		case AI_OBJECT_DEVICE_ELEVATOR:
		case AI_OBJECT_DEVICE_FOOTELEVATOR:
			func_8008E6BC(pThis);
			break;
		case AI_OBJECT_DEVICE_PLATFORM:
			func_8008E800(pThis);
			break;
		case AI_OBJECT_DEVICE_DEATHELEVATOR:
			func_8008E880(pThis);
			break;
		case AI_OBJECT_DEVICE_COLLAPSINGPLATFORM:
			func_8008E9D8(pThis);
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
			func_8008EB08(pThis);
			break;
		case AI_OBJECT_DEVICE_GATE:
			func_8008EC04(pThis);
			break;
		case AI_OBJECT_DEVICE_LOCK:
			func_8008EC0C(pThis);
			break;
		case AI_OBJECT_DEVICE_DRAIN:
			func_8008EC80(pThis);
			break;
		case AI_OBJECT_DEVICE_FLOOD:
			func_8008ED7C(pThis);
			break;
		case AI_OBJECT_DEVICE_CRYSTAL:
			func_8008EE08(pThis);
			break;
		case AI_OBJECT_DEVICE_SPINELEVATOR:
			func_8008F090(pThis);
			break;
		case AI_OBJECT_DEVICE_SPINPLATFORM:
			func_8008F1E4(pThis);
			break;
		case AI_OBJECT_DEVICE_KEYFLOOR:
			func_8008F278(pThis);
			break;

		case AI_OBJECT_DEVICE_FADEINFADEOUT:
			func_8008F280(pThis) ;
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
				func_8005FCA0(pThis, RANDOM(pThis->m_nAnims), FALSE);
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
				func_8001C4E8(pThis);
			}
			else
			{
				if (pThis->m_pBoss)
					func_8003FC00(pThis);
				else if (GetApp()->m_Mode == MODE_GALLERY)
					func_80076218(pThis);
				else
					func_80075254(pThis);
			}
#endif
			break;
	}

	// Update head tracking
	//AI_PerformHeadTracking(pThis) ;
}
