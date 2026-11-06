#include "common_local_source_4552.h"

#line 1 "reference.c"
void Longhunt_Update(CGameObjectInstance *pThis, CLonghunt *pLonghunt)
{
	CVector3			vPos ;
	CGameRegion		*pRegion ;
	int				i ;

	// Play hurt sound every 10% damage
	for (i = 10 ; i <= 100 ; i += 10)
	{
		if ((pLonghunt->m_Boss.m_LastPercentageHealth >= i) &&
			 (pLonghunt->m_Boss.m_PercentageHealth < i))
		{
			AI_SEvent_GeneralSound(&pThis->ah.ih, pThis->ah.ih.m_vPos, SOUND_LONGHUNTER_TAUNT_3) ;
			break ;
		}
	}

	// Update sound taunt timer
	pLonghunt->m_SoundTimer -= D_800B6B00 ;
	if (pLonghunt->m_SoundTimer < 0)
		pLonghunt->m_SoundTimer = 0 ;

	// Generate key
	if ((D_800B6AF8 > 10) && (!(GetApp()->m_BossFlags & BOSS_FLAG_LONGHUNTER_GENERATED_KEY)))
	{
		GetApp()->m_BossFlags |= BOSS_FLAG_LONGHUNTER_GENERATED_KEY ;
		CVector3__Set(&vPos,0,0,0) ;
		pRegion = CScene__NearestRegion(&GetApp()->m_Scene, &vPos) ;
		CSimplePool__CreateSimpleInstance(&GetApp()->m_Scene.m_SimplePool,
												    AI_OBJECT_PICKUP_KEY5, vPos,vPos,pRegion,0) ;
	}

//	enemy_speed_scaler = 0.25 ;
	// Update action AI
	Longhunt_UpdateAction(pThis, pLonghunt) ;

	// Get target and angle to aim for
	Longhunt_GetTarget(pThis, pLonghunt) ;

	// Check for death
	if (BOSS_Health(pThis) <= 0)
	{
		switch(pLonghunt->m_Boss.m_Mode)
		{
			// On floor modes - goto death
			case LONGHUNT_DEATH_MODE:
				break ;

			default:
				Longhunt_SetupMode(pThis, LONGHUNT_DEATH_MODE) ;
				break ;
		}
	}


	// Update run time
	if (!(pLonghunt->m_Boss.m_ModeFlags & BF_RUNNING_MODE))
		pLonghunt->m_RunTime = 0 ;
	else
		pLonghunt->m_RunTime += D_800B6B00 ;


	// No interruptions on blends!
//	if (CGameObjectInstance__IsBlending(pThis))
//		return ;


	// Call update function if there is one
	if ((pLonghunt->m_Boss.m_Mode >= 0 ) &&
		 (pLonghunt->m_Boss.m_pModeTable[pLonghunt->m_Boss.m_Mode].m_pUpdateFunction))
		 (pLonghunt->m_Boss.m_pModeTable[pLonghunt->m_Boss.m_Mode].m_pUpdateFunction)(pThis, (CBoss *)pLonghunt) ;


	// Check for evading projectiles
	Longhunt_CheckForEvade(pThis, pLonghunt) ;


	// Check for updating stage
	if (pLonghunt->m_Boss.m_PercentageHealth < pLonghunt->m_pStageInfo->HealthLimit)
	{
		pLonghunt->m_Boss.m_Stage++ ;
		Longhunt_SetupStageInfo(pThis, pLonghunt, ++pLonghunt->m_pStageInfo) ;
#if DEBUG_LONGHUNT
			rmonPrintf("\r\n....NEXT ATTACK STAGE....\r\n") ;
#endif
	}


	// Update anim speed
	switch(pLonghunt->m_Boss.m_Mode)
	{
		default:
			pLonghunt->m_Boss.m_AnimSpeed = pLonghunt->m_pStageInfo->AnimSpeed ;
	}
}
