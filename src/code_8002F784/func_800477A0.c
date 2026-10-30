#include "common_local_source_4504.h"

#line 1 "reference.c"
CBoss *func_800477A0(CGameObjectInstance *pThis)
{
	CTRex *pTRex = &D_80127760 ;

	// Setup defaults
	func_8003F7E0(&pTRex->m_Boss) ;

	// Setup boss vars
	pTRex->m_Boss.m_pUpdateFunction = (void *)func_80047F84 ;
	pTRex->m_Boss.m_pModeTable = D_800BC6B0 ;

	// Setup trex vars
	pTRex->m_pStageInfo = D_800BCB14 ;
	func_80047750(pThis, pTRex, D_800BCB14) ;

	// Put into start mode
	pTRex->m_Boss.m_Action = TREX_ON_ELEVATOR_ACTION ;
	pTRex->m_Boss.m_ActionTime = 0 ;
	pTRex->m_Boss.m_Mode = TREX_ON_ELEVATOR_IDLE_MODE ;
	pTRex->m_Boss.m_ModeAnimSpeed = 0 ;
	pTRex->m_Boss.m_AnimRepeats = 1 ;
	pTRex->m_Boss.m_AnimSpeed = 1.0 ;

	pTRex->m_Boss.m_pPreDrawFunction = (void *)func_800478FC ;
	pTRex->m_Boss.m_pPostDrawFunction = (void *)func_8004792C ;
	pTRex->m_Boss.m_pPauseFunction = (void *)D_80047F54 ;


#ifndef MAKE_CART
	pTRex->m_Boss.m_pDisplayModeFunction = (void *)TRex_DisplayMode ;
#endif

#if DEBUG_TREX
	rmonPrintf("\r\n\r\n\r\nTREX HERE WE GO!! Prepare for Attack Action") ;
#endif

	// Setup misc
	func_80047710(&pTRex->m_Boss.m_CollisionInfo) ;
	BOSS_Health(pThis) = TREX_HEALTH ;
	pTRex->m_ExplosionHits = 0 ;

	// Reset caves
	pTRex->m_LookTime = 0 ;
	pTRex->m_pTurokInCave = NULL ;
	pTRex->m_pTargetCave = NULL ;
	pTRex->m_TurokTimeInCave = 0 ;
	pTRex->m_TurokInCaveWaitTime = func_80040D10(SECONDS_TO_FRAMES(2), SECONDS_TO_FRAMES(5)) ;

	// No sound to begin with
	pTRex->m_LaserSoundHandle = -1 ;

	pTRex->m_FireSoundHandle = -1 ;
	pTRex->m_FireSoundVolume = 0 ;

	pTRex->m_pDamage = D_800BCCC4 ;

	// Return pointer to trex boss
	return (CBoss *)pTRex ;
}
