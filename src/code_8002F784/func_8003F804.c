#include "decompdecomp_sync_2f731d730c55305315f2.h"
#line 1 "func.c"
#line 517 "reference.c"
void func_8003F804(CGameObjectInstance *pThis, INT32 nObjectType)
{
	CBoss *pBoss ;

	// Already initialized?
	if (CBossesStatus__BossWasSaved(&GetApp()->m_BossesStatus, pThis))
		pBoss = pThis->m_pBoss ;
	else
	{
		// Setup active flag
		GetApp()->m_pBossActive = pThis ;
		GetApp()->m_BossesStatus.m_pBossActive = pThis ;

		switch(nObjectType)
		{
			case AI_OBJECT_CHARACTER_MANTIS_BOSS:
				GetApp()->m_BossVars.m_pMantisInstance = pThis ;
				pBoss = Mantis_Initialise(pThis) ;
				break ;

			case AI_OBJECT_CHARACTER_TREX_BOSS:
				pBoss = TRex_Initialise(pThis) ;
				break ;

			case AI_OBJECT_CHARACTER_HUMVEE_BOSS:
				pBoss = Humvee_Initialise(pThis) ;
				break ;

			case AI_OBJECT_CHARACTER_LONGHUNTER_BOSS:
				pBoss = Longhunt_Initialise(pThis) ;
				break ;

			case AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS:
				pBoss = Campaigner_Initialise(pThis) ;
				break ;


			default:
				pBoss = NULL ;
		}
	}

	// Keep pointer to boss vars in instance
	pThis->m_pBoss = pBoss ;
	if (!pBoss)
		return ;

	// Call initialize function
	if (pBoss->m_pInitializeFunction)
		pBoss->m_pInitializeFunction(pThis, pBoss) ;

	// Apply difficulty
	BOSS_Health(pThis) = ((float)BOSS_Health(pThis) * CEngineApp__GetBossHitPointScaler(GetApp())) ;

	// Keep copy of full health!
	pBoss->m_LastHealth = pBoss->m_StartHealth = BOSS_Health(pThis) ;
	pBoss->m_Alive = TRUE ;

	// Make sure boss only attacks Turok
	pThis->m_pAttackerCGameObjectInstance = CEngineApp__GetPlayer(GetApp());



	// Initialise boss vars
	pBoss->m_Initialized = FALSE ;
	pBoss->m_ObjectType = nObjectType ;
	pBoss->m_AnimPlayed = 0 ;
	pBoss->m_AnimPastEnd = FALSE ;
	pBoss->m_LastPercentageHealth = 100 ;
	pBoss->m_PercentageHealth = 100 ;
	pBoss->m_AnimSpeed = 2.0 ;

	pThis->m_pCalculateOrientation = (void *)BOSS_CalculateOrientation ;
	pBoss->m_RotX = 0 ;
	pBoss->m_RotZ = 0 ;

	pBoss->m_TurokAngle =
	pBoss->m_TurokAngleDiff =
	pBoss->m_TurokAngleDist =
	pBoss->m_LastTurokDeltaAngle =
	pBoss->m_TurokDeltaAngle =
	pBoss->m_AbsTurokDeltaAngle = 0 ;

}

