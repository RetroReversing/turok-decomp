#include "common_local_source_4552.h"

#line 1 "reference.c"
void func_80049EB4(CGameObjectInstance *pThis, CLonghunt *pLonghunt)
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
			func_80063AE8(&pThis->ah.ih, pThis->ah.ih.m_vPos, SOUND_LONGHUNTER_TAUNT_3) ;
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
		pRegion = func_8002E280(&GetApp()->m_Scene, &vPos) ;
		func_80035A74(&GetApp()->m_Scene.m_SimplePool,
												    AI_OBJECT_PICKUP_KEY5, vPos,vPos,pRegion,0) ;
	}

//	enemy_speed_scaler = 0.25 ;
	// Update action AI
	func_80049E04(pThis, pLonghunt) ;

	// Get target and angle to aim for
	func_8004A2B0(pThis, pLonghunt) ;

	// Check for death
	if (BOSS_Health(pThis) <= 0)
	{
		switch(pLonghunt->m_Boss.m_Mode)
		{
			// On floor modes - goto death
			case LONGHUNT_DEATH_MODE:
				break ;

			default:
				func_8004A118(pThis, LONGHUNT_DEATH_MODE) ;
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
	func_8004A6EC(pThis, pLonghunt) ;


	// Check for updating stage
	if (pLonghunt->m_Boss.m_PercentageHealth < pLonghunt->m_pStageInfo->HealthLimit)
	{
		pLonghunt->m_Boss.m_Stage++ ;
		func_80049DF4(pThis, pLonghunt, ++pLonghunt->m_pStageInfo) ;
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
