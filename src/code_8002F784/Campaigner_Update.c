#include "decompdecomp_sync_90656d858d8223124649.h"
#line 1 "func.c"
/* Declare the callback before the constructor that stores its address. */
void Campaigner_Update(CGameObjectInstance *, CCampaigner *);
#line 862 "reference.c"
CBoss *func_8004D218(CGameObjectInstance *pThis)
{
	CCampaigner *pCampaigner = &D_80127ED0 ;

	// Setup defaults
	CBoss__Construct(&pCampaigner->m_Boss) ;

	// Setup regions for in hole modes!
	pCampaigner->m_HoleNumber = 0 ;
	GetApp()->m_BossVars.m_pRegionList[0] = CScene__NearestRegion(&GetApp()->m_Scene, &D_800BDE58[0]) ;
	GetApp()->m_BossVars.m_pRegionList[1] = CScene__NearestRegion(&GetApp()->m_Scene, &D_800BDE58[1]) ;

	// Setup boss vars
	pCampaigner->m_Boss.m_pInitializeFunction = (void *)InitializeCampaigner ;
	pCampaigner->m_Boss.m_pUpdateFunction = (void *)Campaigner_Update ;
	pCampaigner->m_Boss.m_pHitByParticleFunction = (void *)Campaigner_HitByParticle ;
	pCampaigner->m_Boss.m_pModeTable = D_800BD390 ;
	pCampaigner->m_Boss.m_Rot1 = 0 ;
	pCampaigner->m_Boss.m_Rot2 = 0 ;

	// Setup campaigner vars
	pCampaigner->m_pStageInfo = D_800BD818 ;
	Campaigner_SetupStageInfo(pThis, pCampaigner, D_800BD818) ;

	// Put into start mode
	pCampaigner->m_Boss.m_Mode = CAMPAIGNER_TALK_MODE ;

	pCampaigner->m_Boss.m_ModeAnimSpeed = 0 ;
	pCampaigner->m_Boss.m_AnimRepeats = 1 ;
	pCampaigner->m_Boss.m_AnimSpeed = 1.0 ;

	pCampaigner->m_Boss.m_pPreDrawFunction = (void *)Campaigner_PreDraw ;
	pCampaigner->m_Boss.m_pPostDrawFunction = (void *)Campaigner_PostDraw ;

                 
                                                                              
      

                    
                                                                                    
      

	// Setup misc
	CCollisionInfo__SetCampaignerCollisionDefaults(&pCampaigner->m_Boss.m_CollisionInfo) ;
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
	CShield__Construct(&pCampaigner->m_Shield,
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

#line 1 "reference.c"
void Campaigner_Update(CGameObjectInstance *pThis, CCampaigner *pCampaigner)
{
	// Keep the sound up-to date
	Campaigner_UpdateSound(pThis, pCampaigner) ;

	// Has a weapon been fired at Mr. Campaigner?
	if ((pCampaigner->m_Boss.m_Mode != CAMPAIGNER_TELEPORT_MODE) &&
		 (!pCampaigner->m_WeaponToTakeOff) && (D_80128C20.WeaponCurrent) &&
		 (D_80128C20.WeaponMode == TWEAPONMODE_ON) && (D_80128C20.WeaponFired))
	{
		switch(D_80128C20.WeaponCurrent)
		{
			// Take away weapons
			case AI_OBJECT_WEAPON_TECHWEAPON2:
			case AI_OBJECT_WEAPON_SHOCKWAVE:
				Campaigner_SetupMode(pThis, CAMPAIGNER_WEAPON_IDLE_MODE) ;
				break ;

			// Block weaponss
			case AI_OBJECT_WEAPON_MACHINEGUN:
			case AI_OBJECT_WEAPON_GRENADE_LAUNCHER:
			case AI_OBJECT_WEAPON_TECHWEAPON1:
			case AI_OBJECT_WEAPON_ROCKET:

				// Start shield
				if (pCampaigner->m_pStageInfo->BlockWeaponsPercentage >= RANDOM(101))
					Campaigner_ActivateShield(pThis, pCampaigner, SECONDS_TO_FRAMES(4)) ;
				break ;
		}
	}

	// Get target and angle to aim for
	Campaigner_GetTarget(pThis, pCampaigner) ;

	// Goto teleport/jump?
	if ((!Campaigner_TurokObstructed(pThis, pCampaigner)) &&
		 (pCampaigner->m_Boss.m_ModeFlags & BF_CAN_TELEPORT) &&
		 (pCampaigner->m_Boss.m_DistFromTarget >= CAMPAIGNER_DO_TELEPORT_DIST))
	{
		if ((RANDOM(2)) || (pCampaigner->m_Limp))
			Campaigner_SetupMode(pThis, CAMPAIGNER_TELEPORT_MODE) ;
		else
			Campaigner_SetupMode(pThis, CAMPAIGNER_EVADE_MEGA_JUMP_MODE) ;
	}

	// Check for death
	if ((BOSS_Health(pThis) <= 0) && (!Campaigner_InHole(pThis, pCampaigner)))
	{
		switch(pCampaigner->m_Boss.m_Mode)
		{
			// On floor modes - goto death
			case CAMPAIGNER_DEATH_MODE:
				break ;

			default:
				Campaigner_SetupMode(pThis, CAMPAIGNER_DEATH_MODE) ;
				CSpecialFx__StartScript(&pCampaigner->m_SpecialFx, D_800BDBCC) ;
				break ;
		}
	}
	
	// Update invincible flag
	if ((pCampaigner->m_Boss.m_ModeFlags & BF_INVINCIBLE) ||
		 (CShield__IsOn(&pCampaigner->m_Shield)))
		AI_GetDyn(pThis)->m_Invincible = TRUE ;
	else
		AI_GetDyn(pThis)->m_Invincible = FALSE ;

	// Hit by explosion?
	if ((BOSS_Health(pThis) > 0) && (!AI_GetDyn(pThis)->m_Invincible))
	{
		Campaigner_CheckHitByExplosion(pThis, pCampaigner) ;

		// Increase damage
		if (pCampaigner->m_Boss.m_PercentageHealth < pCampaigner->m_pDamage->m_Health)
		{
			pCampaigner->m_pDamage++ ;
			Campaigner_SetupMode(pThis, CAMPAIGNER_DAMAGE_SHORTING_OUT_MODE) ;
			AI_SEvent_GeneralSound(&pThis->ah.ih, pThis->ah.ih.m_vPos, SOUND_CAMPAIGNERS_DEATH) ;
		}
	}

	// Update run time
	if (!(pCampaigner->m_Boss.m_ModeFlags & BF_RUNNING_MODE))
		pCampaigner->m_RunTime = 0 ;
	else
		pCampaigner->m_RunTime += D_800B6B00 ;

	// Update the shield
	CShield__Update(&pCampaigner->m_Shield) ;

	// No interruptions on blends!
	if (CGameObjectInstance__IsBlending(pThis))
		return ;

//	osSyncPrintf("Mode:%d\r\n", pCampaigner->m_Boss.m_Mode) ;

	// Call update function if there is one
	if ((pCampaigner->m_Boss.m_Mode >= 0 ) &&
		 (pCampaigner->m_Boss.m_pModeTable[pCampaigner->m_Boss.m_Mode].m_pUpdateFunction))
		 (pCampaigner->m_Boss.m_pModeTable[pCampaigner->m_Boss.m_Mode].m_pUpdateFunction)(pThis, (CBoss *)pCampaigner) ;

#if CAMPAIGNER_CHECK_FOR_EVADE
	// Check for evading projectiles
	Campaigner_CheckForEvade(pThis, pCampaigner) ;
#endif

	// Put into limp?
	if (pCampaigner->m_pDamage->m_Flags & CAMP_RIGHT_UPPER_LEG_GEOM_DAMAGE_FLAG)
		pCampaigner->m_Limp = TRUE ;

	// Use limping?
	if (pCampaigner->m_Limp)
	{
		switch(pCampaigner->m_Boss.m_Mode)
		{
			case CAMPAIGNER_WALK_MODE:
			case CAMPAIGNER_RUN_MODE:
				pCampaigner->m_Boss.m_Mode = CAMPAIGNER_LIMP_MODE ;
				break ;
			case CAMPAIGNER_WALK_TURN180_MODE:
			case CAMPAIGNER_RUN_TURN180_MODE:
				pCampaigner->m_Boss.m_Mode = CAMPAIGNER_LIMP_TURN180_MODE ;
				break ;
			case CAMPAIGNER_WALK_TURN_LEFT90_MODE:
			case CAMPAIGNER_RUN_TURN_LEFT90_MODE:
				pCampaigner->m_Boss.m_Mode = CAMPAIGNER_LIMP_TURN_LEFT90_MODE ;
				break ;
			case CAMPAIGNER_WALK_TURN_RIGHT90_MODE:
			case CAMPAIGNER_RUN_TURN_RIGHT90_MODE:
				pCampaigner->m_Boss.m_Mode = CAMPAIGNER_LIMP_TURN_RIGHT90_MODE ;
				break ;
		}
	}


	// Check for updating stage
	if (pCampaigner->m_Boss.m_PercentageHealth < pCampaigner->m_pStageInfo->HealthLimit)
	{
		pCampaigner->m_Boss.m_Stage++ ;
		Campaigner_SetupStageInfo(pThis, pCampaigner, ++pCampaigner->m_pStageInfo) ;
#if DEBUG_CAMPAIGNER
			rmonPrintf("\r\n....NEXT ATTACK STAGE....\r\n") ;
#endif
	}

	// Update anim speed
	switch(pCampaigner->m_Boss.m_Mode)
	{
		default:
			pCampaigner->m_Boss.m_AnimSpeed = pCampaigner->m_pStageInfo->AnimSpeed ;
	}
}

