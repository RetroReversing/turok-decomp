#line 1 "reference.c"
void func_8004D6FC(CGameObjectInstance *pThis, CCampaigner *pCampaigner)
{
	// Keep the sound up-to date
	func_8004D4B4(pThis, pCampaigner) ;

	// Has a weapon been fired at Mr. Campaigner?
	if ((pCampaigner->m_Boss.m_Mode != CAMPAIGNER_TELEPORT_MODE) && (D_80128C20.WeaponFired) && (D_80128C20.WeaponMode == TWEAPONMODE_ON) && (!pCampaigner->m_WeaponToTakeOff) && (D_80128C20.WeaponCurrent))
	{
		switch(D_80128C20.WeaponCurrent)
		{
			// Take away weapons
			case AI_OBJECT_WEAPON_TECHWEAPON2:
			case AI_OBJECT_WEAPON_SHOCKWAVE:
				func_8004DACC(pThis, CAMPAIGNER_WEAPON_IDLE_MODE) ;
				break ;

			// Block weaponss
			case AI_OBJECT_WEAPON_MACHINEGUN:
			case AI_OBJECT_WEAPON_GRENADE_LAUNCHER:
			case AI_OBJECT_WEAPON_TECHWEAPON1:
			case AI_OBJECT_WEAPON_ROCKET:

				// Start shield
				if (pCampaigner->m_pStageInfo->BlockWeaponsPercentage >= RANDOM(101))
					func_8004DB48(pThis, pCampaigner, SECONDS_TO_FRAMES(4)) ;
				break ;
		}
	}

	// Get target and angle to aim for
	func_8004DBDC(pThis, pCampaigner) ;

	// Goto teleport/jump?
	if ((!func_8004E200(pThis, pCampaigner)) &&
		 (pCampaigner->m_Boss.m_ModeFlags & BF_CAN_TELEPORT) &&
		 (pCampaigner->m_Boss.m_DistFromTarget >= CAMPAIGNER_DO_TELEPORT_DIST))
	{
		if ((RANDOM(2)) || (pCampaigner->m_Limp))
			func_8004DACC(pThis, CAMPAIGNER_TELEPORT_MODE) ;
		else
			func_8004DACC(pThis, CAMPAIGNER_EVADE_MEGA_JUMP_MODE) ;
	}

	// Check for death
	if ((BOSS_Health(pThis) <= 0) && (!func_8004D1C0(pThis, pCampaigner)))
	{
		switch(pCampaigner->m_Boss.m_Mode)
		{
			// On floor modes - goto death
			case CAMPAIGNER_DEATH_MODE:
				break ;

			default:
				func_8004DACC(pThis, CAMPAIGNER_DEATH_MODE) ;
				func_8004305C(&pCampaigner->m_SpecialFx, D_800BDBCC) ;
				break ;
		}
	}
	
	// Update invincible flag
	if ((pCampaigner->m_Boss.m_ModeFlags & BF_INVINCIBLE) ||
		 (func_80040E80(&pCampaigner->m_Shield)))
		AI_GetDyn(pThis)->m_Invincible = TRUE ;
	else
		AI_GetDyn(pThis)->m_Invincible = FALSE ;

	// Hit by explosion?
	if ((BOSS_Health(pThis) > 0) && (!AI_GetDyn(pThis)->m_Invincible))
	{
		func_8004E0B4(pThis, pCampaigner) ;

		// Increase damage
		if (pCampaigner->m_Boss.m_PercentageHealth < pCampaigner->m_pDamage->m_Health)
		{
			pCampaigner->m_pDamage++ ;
			func_8004DACC(pThis, CAMPAIGNER_DAMAGE_SHORTING_OUT_MODE) ;
			func_80063AE8(&pThis->ah.ih, pThis->ah.ih.m_vPos, SOUND_CAMPAIGNERS_DEATH) ;
		}
	}

	// Update run time
	if (!(pCampaigner->m_Boss.m_ModeFlags & BF_RUNNING_MODE))
		pCampaigner->m_RunTime = 0 ;
	else
		pCampaigner->m_RunTime += D_800B6B00 ;

	// Update the shield
	func_80040EA4(&pCampaigner->m_Shield) ;

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
	func_8004DEC8(pThis, pCampaigner) ;
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
		func_8004D444(pThis, pCampaigner, ++pCampaigner->m_pStageInfo) ;
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
