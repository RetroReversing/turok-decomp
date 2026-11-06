#include "common_local_source_4433.h"

#line 1 "reference.c"
CBoss *Mantis_Initialise(CGameObjectInstance *pThis)
{
	CMantis *pMantis = &D_80127480 ;

	// Setup defaults
	CBoss__Construct(&pMantis->m_Boss) ;

	// Setup boss vars
	pMantis->m_Boss.m_pInitializeFunction = (void *)InitializeMantis ;
	pMantis->m_Boss.m_pUpdateFunction = (void *)Mantis_Update ;
	pMantis->m_Boss.m_pModeTable = D_800BBE60 ;

	// Reset head tracking
	pMantis->m_Boss.m_Rot1 = 0 ;
	pMantis->m_Boss.m_Rot2 = 0 ;

	// Setup mantis vars
	pMantis->m_pStageInfo = D_800BC544 ;
//	pMantis->m_pStageInfo = &MantisStageInfo[3] ;
	pMantis->m_FlySpitTotal = 0 ;
	pMantis->m_Boss.m_Stage = 0 ;
	Mantis_SetupStageInfo(pThis, pMantis, pMantis->m_pStageInfo) ;

	// Put into start mode

#if DEBUG_MANTIS_HEAD_TRACK
	pMantis->m_Boss.m_Mode = MANTIS_IDLE_FLOOR_MODE ;
#else
	pMantis->m_Boss.m_Mode = MANTIS_SLEEPING_FLOOR_MODE ;
#endif

	pMantis->m_Boss.m_ModeAnimSpeed = 0 ;
	pMantis->m_Boss.m_Action = MANTIS_ATTACK_ACTION ;
	pMantis->m_Boss.m_ActionTime = 0 ;

	pMantis->m_WalkTime = 0 ;

	// Setup light stuff
	pMantis->m_FlinchGlow = FALSE ;
	pMantis->m_Boss.m_pPreDrawFunction = (void *)Mantis_PreDraw ;
	pMantis->m_Boss.m_pPostDrawFunction = (void *)Mantis_PostDraw ;

#ifndef MAKE_CART
	pMantis->m_Boss.m_pDisplayModeFunction = (void *)Mantis_DisplayMode ;
#endif

#if DEBUG_MANTIS
	rmonPrintf("\r\n\r\n\r\n\r\nMANTIS HERE WE GO!!\r\n\r\n") ;
#endif

	// Setup misc
	CCollisionInfo__SetMantisCollisionDefaults(&pMantis->m_Boss.m_CollisionInfo) ;
	BOSS_Health(pThis) = MANTIS_HEALTH ;
	pMantis->m_ExplosionHits = 0 ;
	pMantis->m_AcidHurtTurok = FALSE ;

	// Initialise wall vars
	pMantis->m_WallBroken[0] = FALSE ;
	pMantis->m_WallBroken[1] = FALSE ;
	pMantis->m_WallBroken[2] = FALSE ;
	pMantis->m_WallBroken[3] = FALSE ;
	pMantis->m_WallsToBreak = 4 ;

	pMantis->m_WallToAimFor = -1 ;
	pMantis->m_GotoFloor = FALSE ;
	pMantis->m_ChoosePosition = FALSE ;
	pMantis->m_WallCollapseTime = 0 ;

	// Make invisivle to begin with
	CGameObjectInstance__SetGone(pThis) ;

	// Return pointer to mantis boss
	return (CBoss *)pMantis ;
}
