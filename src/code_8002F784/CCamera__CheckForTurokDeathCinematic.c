#include "decompdecomp_sync_a0bfdaeea8ecf623d666.h"
#line 1 "func.c"
#line 1629 "reference.c"
BOOL CCamera__CheckForTurokDeathCinematic(CCamera *pThis)
{
                 

	CEngineApp				*pEngine = GetApp() ;
	CGameObjectInstance	*pTurok ;
	CROMRegionSet			*pRegionSet ;
	BOOL						climbFlag;


	// If in cinema mode - return TRUE!
	if (pThis->m_CinemaMode)
		return TRUE ;

	// Waiting to do a cinematic?
	if (pEngine->m_CinemaFlags)
		return TRUE ;

	if (D_80112BD4 & 0x20000) return TRUE;
	// Get turok ptr
	pTurok = CEngineApp__GetPlayer(GetApp()) ;
	if (!pTurok)
		return FALSE ;

	// if in keel over don't do a cinema
	if (CTurokMovement.DeathStage != TMOVE_HEALTH_ALIVE)
		return FALSE;

	// if turok is on a cliff - just return
	climbFlag = CEngineApp__GetPlayerClimbStatus(GetApp());
	if (climbFlag == PLAYER_AT_CLIMBING_SURFACE)
		return FALSE;

	// Get region ptr
	pRegionSet = CScene__GetRegionAttributes(&GetApp()->m_Scene, pTurok->ah.ih.m_pCurrentRegion) ;
	if (!pRegionSet)
		return FALSE ;

	// Do fall death?
	if (		(pRegionSet->m_dwFlags & REGFLAG_FALLDEATH)
			&&	(pTurok->ah.ih.m_vPos.y < CInstanceHdr__GetGroundHeight(&pTurok->ah.ih)) )
	{
		pEngine->m_CinemaFlags |= CINEMA_FLAG_PLAY_FALL_DEATH;
	}

	// Do water death?
	else if (		(pTurok->m_AI.m_Health <= 0)
					&&	(!CTurokMovement.InAntiGrav)
					&& (CCamera__CeilingHighEnoughAboveTurok(pThis))
					&& (		(CTurokMovement.WaterFlag == PLAYER_BELOW_WATERSURFACE)
							||	(		(CTurokMovement.WaterFlag == PLAYER_ON_WATERSURFACE)
									&&	(!CInstanceHdr__IsOnGround(&pTurok->ah.ih)) ) ) )
	{
		pEngine->m_CinemaFlags |= CINEMA_FLAG_PLAY_WATER_DEATH;
	}

	// Do normal death?
	else if (		(CInstanceHdr__IsOnGround(&pTurok->ah.ih))
					&&	(pTurok->m_AI.m_Health <= 0)
					&&	(CCamera__CeilingHighEnoughAboveTurok(pThis)) )
	{
		// if a boss is active, set up special death cinema...
		if ((GetApp()->m_pBossActive) && (BOSS_Health(GetApp()->m_pBossActive) > 0))
		{
			switch (CGameObjectInstance__TypeFlag(GetApp()->m_pBossActive))
			{
				case AI_OBJECT_CHARACTER_MANTIS_BOSS:
					pEngine->m_CinemaFlags |= CINEMA_FLAG_MANTIS_KILL_TUROK;
					break;
				case AI_OBJECT_CHARACTER_TREX_BOSS:
					pEngine->m_CinemaFlags |= CINEMA_FLAG_TREX_KILL_TUROK;
					break;
				case AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS:
					pEngine->m_CinemaFlags |= CINEMA_FLAG_CAMPAIGNER_KILL_TUROK;
					break;
				default:
					pEngine->m_CinemaFlags |= CINEMA_FLAG_PLAY_DEATH;
					break;
			}
		}
		else
		{
			pEngine->m_CinemaFlags |= CINEMA_FLAG_PLAY_DEATH;
		}
	}

	// Perform a cinema?
	if (pEngine->m_CinemaFlags)
	{
		CCamera__FadeToCinema(pThis, pEngine->m_CinemaFlags) ;
		return TRUE ;
	}
	else
		return FALSE ;

     

                               

      
}

