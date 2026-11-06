#include "common_local_source_4548.h"

#line 1 "reference.c"
CBoss *Longhunt_Initialise(CGameObjectInstance *pThis)
{
	CLonghunt		*pLonghunt = &D_80127960 ;

	// Setup defaults
	CBoss__Construct(&pLonghunt->m_Boss) ;

	// Setup boss vars
	pLonghunt->m_Boss.m_pUpdateFunction = (void *)Longhunt_Update ;
	pLonghunt->m_Boss.m_pModeTable = D_800BCDA0 ;
	pLonghunt->m_Boss.m_Rot1 = 0 ;
	pLonghunt->m_Boss.m_Rot2 = 0 ;

	// Setup longhunt vars
	pLonghunt->m_pStageInfo = D_800BCFBC ;
	Longhunt_SetupStageInfo(pThis, pLonghunt, D_800BCFBC) ;

	// Put into start mode
	pLonghunt->m_Boss.m_Mode = LONGHUNT_WAIT_FOR_START_MODE ;
	pLonghunt->m_Boss.m_ModeAnimSpeed = 0 ;
	pLonghunt->m_Boss.m_AnimRepeats = 1 ;
	pLonghunt->m_Boss.m_AnimSpeed = 1.0 ;

	pLonghunt->m_Boss.m_Action = LONGHUNT_WAIT_FOR_HUMVEES_DEATH_ACTION ;
	pLonghunt->m_Boss.m_ActionStage = 0 ;

	pLonghunt->m_Boss.m_pRestoreFunction = (void *)Longhunt_OpenForceField ;

#ifndef MAKE_CART
	pLonghunt->m_Boss.m_pDisplayModeFunction = (void *)Longhunt_DisplayMode ;
#endif

#if DEBUG_LONGHUNT
	rmonPrintf("\r\n\r\n\r\nLONGHUNTER HERE WE GO!! Prepare for Attack Action\r\n") ;
#endif


	// Make boss invincible for now
	AI_GetDyn(pThis)->m_Invincible = TRUE ;

	// Setup misc
	CCollisionInfo__SetLonghuntCollisionDefaults(&pLonghunt->m_Boss.m_CollisionInfo) ;
	BOSS_Health(pThis) = LONGHUNT_HEALTH ;

	// Evade
	pLonghunt->m_EvadeTime = 0 ;
	pLonghunt->m_EvadeCount = 0 ;
	pLonghunt->m_EvadeActive = FALSE ;

	// Reset run timers
	pLonghunt->m_RunTime = 0 ;
	pLonghunt->m_RunAttackTime = 0 ;
	pLonghunt->m_RunAngle = 0 ;

	pLonghunt->m_SoundTimer = SECONDS_TO_FRAMES(2) ;

	// Return pointer to longhunt boss
	return (CBoss *)pLonghunt ;
}
