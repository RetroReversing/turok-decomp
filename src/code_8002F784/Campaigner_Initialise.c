#include "decompdecomp_sync_feb26eeae9ea0c68c17a.h"
#line 1 "func.c"
#line 862 "reference.c"
CBoss *Campaigner_Initialise(CGameObjectInstance *pThis)
{
	CCampaigner *pCampaigner = &D_80127ED0 ;

	// Setup defaults
	func_8003F7E0(&pCampaigner->m_Boss) ;

	// Setup regions for in hole modes!
	pCampaigner->m_HoleNumber = 0 ;
	GetApp()->m_BossVars.m_pRegionList[0] = func_8002E280(&GetApp()->m_Scene, &D_800BDE58[0]) ;
	GetApp()->m_BossVars.m_pRegionList[1] = func_8002E280(&GetApp()->m_Scene, &D_800BDE58[1]) ;

	// Setup boss vars
	pCampaigner->m_Boss.m_pInitializeFunction = (void *)func_8004D1EC ;
	pCampaigner->m_Boss.m_pUpdateFunction = (void *)func_8004D6FC ;
	pCampaigner->m_Boss.m_pHitByParticleFunction = (void *)func_8004DFE8 ;
	pCampaigner->m_Boss.m_pModeTable = D_800BD390 ;
	pCampaigner->m_Boss.m_Rot1 = 0 ;
	pCampaigner->m_Boss.m_Rot2 = 0 ;

	// Setup campaigner vars
	pCampaigner->m_pStageInfo = D_800BD818 ;
	func_8004D444(pThis, pCampaigner, D_800BD818) ;

	// Put into start mode
	pCampaigner->m_Boss.m_Mode = CAMPAIGNER_TALK_MODE ;

	pCampaigner->m_Boss.m_ModeAnimSpeed = 0 ;
	pCampaigner->m_Boss.m_AnimRepeats = 1 ;
	pCampaigner->m_Boss.m_AnimSpeed = 1.0 ;

	pCampaigner->m_Boss.m_pPreDrawFunction = (void *)func_8004DAF4 ;
	pCampaigner->m_Boss.m_pPostDrawFunction = (void *)func_8004DB30 ;

                 
                                                                              
      

                    
                                                                                    
      

	// Setup misc
	func_8004D404(&pCampaigner->m_Boss.m_CollisionInfo) ;
	BOSS_Health(pThis) = CAMPAIGNER_HEALTH ;

	// Make him limp!
	pCampaigner->m_Limp = FALSE ;

	// Reset run timers
	pCampaigner->m_RunTime = 0 ;
	pCampaigner->m_RunAttackTime = 0 ;

	// Reset all timers
	pCampaigner->m_EvadeTime = 0 ;
	pCampaigner->m_FlinchTime = 0 ;
	pCampaigner->m_ExplodeFlinchTime = 0 ;
	pCampaigner->m_ShortOutTime = 0 ;

	// Init shield
	pCampaigner->m_Boss.m_pShield = &pCampaigner->m_Shield ;
	func_80040E48(&pCampaigner->m_Shield,
							 pThis,
							 CAMPAIGNER_HEALTH/2,
							 D_800BD280,
							 sizeof(D_800BD280) / sizeof(CPsuedoColor)) ;

	// Take off weapon vars
	pCampaigner->m_WeaponToTakeOff = 0 ;
	pCampaigner->m_pDamage = D_800BD240 ;

	// Init sound
	pCampaigner->m_TauntTimer = SECONDS_TO_FRAMES(8) ;
	pCampaigner->m_PlayingSoundTimer = 0 ;
	pCampaigner->m_LastSound = 0 ;

	// Init run attack script
	pCampaigner->m_RunAttackScript.m_pStart =
	pCampaigner->m_RunAttackScript.m_pCurrent = D_800BD938 ;

	// Return pointer to campaigner boss
	return (CBoss *)pCampaigner ;
}

