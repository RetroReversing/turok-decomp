#include "decompdecomp_sync_74168ac028e586882f09.h"
#line 1 "func.c"
#line 9538 "reference.c"
void AI_Decrease_Health(CGameObjectInstance *pAI, int hits, BOOL FlashScreen, BOOL DoSounds)
{
	int	flash,
			flashdec,
			waterFlag,
			s,
			n;

	// Invincible cannot be hurt
	if (AI_GetDyn(pAI)->m_Invincible)
	{
		// Boss with shield?
		if ((pAI->m_pBoss) && (pAI->m_pBoss->m_pShield) && (CShield__IsOn(pAI->m_pBoss->m_pShield)))
		{
			pAI->m_pBoss->m_pShield->m_Health -= hits ;
			if (pAI->m_pBoss->m_pShield->m_Health < 0)
				pAI->m_pBoss->m_pShield->m_Health = 0 ;
		}

		// ai is invincible
		return ;
	}

	if (AI_GetDyn(pAI)->m_Health==0) return;			// ai is already dead
	if (AI_GetDyn(pAI)->m_dwStatusFlags2 & AI_HOLDINTANIMON1STFRAME) return;
	if (AI_GetDyn(pAI)->m_dwStatusFlags & AI_INTERACTIVEANIMATION) return;
	if (AI_GetDyn(pAI)->m_dwStatusFlags & AI_INTERANIMDELAY) return;
	if (CGameObjectInstance__IsDevice(pAI)) return;

	// if AI is player, check if any armor, and flash a different color
	if (CEngineApp__GetPlayer(GetApp()) == pAI)
	{
		// Doing a cinematic?
		if (CCamera__InCinemaMode(&GetApp()->m_Camera))
			return ;

		// if pausing, or cheating, don't decrease health!
		if ((GetApp()->m_dwCheatFlags & CHEATFLAG_INVINCIBILITY) || (GetApp()->m_bPause))
			return ;

		// invincible?? then do nothing!
		if (D_80128C20.SpiritualTime)
			return ;

		// which injury sfx shall we play ?
		waterFlag = CEngineApp__GetPlayerWaterStatus(GetApp());
		switch (waterFlag)
		{
			default:
			case PLAYER_NOT_NEAR_WATER:
			case PLAYER_ABOVE_WATERSURFACE:
			case PLAYER_ON_WATERSURFACE:
				n = RANDOM(4);
				switch (n)
				{
					case 0:	s = SOUND_GENERIC_10;		break;
					case 1:	s = SOUND_GENERIC_11;		break;
					case 2:	s = SOUND_GENERIC_12;		break;
					case 3:	s = SOUND_GENERIC_13;		break;
				}
				break;

			case PLAYER_BELOW_WATERSURFACE:
				if (D_80128C20.InAntiGrav)
				{
					n = RANDOM(4);
					switch (n)
					{
						case 0:	s = SOUND_GENERIC_10;		break;
						case 1:	s = SOUND_GENERIC_11;		break;
						case 2:	s = SOUND_GENERIC_12;		break;
						case 3:	s = SOUND_GENERIC_13;		break;
					}
				}
				else
				{
					n = RANDOM(2);
					switch (n)
					{
						case 0:	s = SOUND_GENERIC_14;		break;
						case 1:	s = SOUND_GENERIC_15;		break;
					}
				}
				break;
		}
		if (DoSounds && D_80128C20.ArmorFlag==0)
		{
			if (D_80128C20.HitSoundTimerScream)
			{
				if (D_80128C20.HitSoundTimer >= TMOVE_HITSOUND_TIMER_SCREAM)
				{
					D_80128C20.HitSoundTimer = D_800F5584;
					D_80128C20.HitSoundTimerScream = FALSE;
				}
			}
			else
			{
				if (D_80128C20.HitSoundTimer < D_800F5588)
				{
					D_80128C20.HitSoundTimer = 0.0;
					D_80128C20.HitSoundTimerScream = TRUE;

					// do special scream because turok is being hit alot
					// for the now lets just do the normal grunt sfx
					switch(waterFlag)
					{
						case PLAYER_NOT_NEAR_WATER:
						case PLAYER_ABOVE_WATERSURFACE:
						case PLAYER_ON_WATERSURFACE:
							func_8005EED0(&pAI->ah.ih, s, 1, 0);
							break;

						case PLAYER_BELOW_WATERSURFACE:
							func_8005EED0(&pAI->ah.ih, s, 1, 0);
							break;
					}
				}
				else
				{
					func_8005EED0(&pAI->ah.ih, s, 1, 0);
					D_80128C20.HitSoundTimer = 0.0;
				}
			}
		}


		if (D_80128C20.ArmorFlag)
		{
			//CTurokMovement.ArmorAmount = max(0, CTurokMovement.ArmorAmount - hits);
			D_80128C20.ArmorAmount -= hits ;

			// calc flash size & duration
			if (FlashScreen)
			{
				flash = 255*hits/20;
				flash = max(128, min(255, flash));

				flashdec = 30;

				CEngineApp__DoColorFlash(GetApp(), flash, flashdec, 255, 255, 0);
			}

			// if damage is more than armor can take, spill over to normal damage...
			if (D_80128C20.ArmorAmount <= 3)
			{
				hits = 3-D_80128C20.ArmorAmount ;
				D_80128C20.ArmorFlag = FALSE;
				D_80128C20.ArmorAmount = 0;
			}
			else
				hits = 0 ;
		}

		if (hits)
		{
			// decrease health

			AI_GetDyn(pAI)->m_Health = max(0, AI_GetDyn(pAI)->m_Health - hits);

			// calc flash size & duration
			if (FlashScreen)
			{
				if (AI_GetDyn(pAI)->m_Health)
				{
					flash = 255*hits/20;
					flash = max(128, min(255, flash));

					flashdec = 30;
				}
				else
				{
					flash = 255;

					flashdec = 12;
				}

				// flash screen
				CEngineApp__DoFlash(GetApp(), flash, flashdec);
			}
		}
	}
	// non player ai
	else
	{
		// decrease health
		AI_GetDyn(pAI)->m_Health -= hits;

		// does this character generate pickups when damaged ?
		if (		(AI_GetDyn(pAI)->m_Health)
				&&	(AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_DOPICKUPONDAMAGE) )
		{
			func_80063DE8(pAI, pAI->ah.ih.m_vPos);
		}
	}


	// is ai now dead ?
	if ( AI_GetDyn(pAI)->m_Health <= 0 )
	{
		AI_GetDyn(pAI)->m_Health = 0;			// set health to zero

		// do the following so final death anim will play immediately
		AI_GetDyn(pAI)->m_dwStatusFlags &= ~AI_ALREADY_DEAD;
		AI_GetDyn(pAI)->m_dwStatusFlags &= ~AI_WAITFOR_CYCLE;

		if (		(AI_CanWeRemoveIt(pAI))
				&& (CEngineApp__GetPlayer(GetApp()) != pAI)
				&&	(!AI_DoesItRegenerate(pAI)) )
		{
			func_80034900(&GetApp()->m_Scene, pAI, TRUE);
		}

		if (AI_GetEA(pAI)->m_DeathId)
			AI_Event_Dispatcher (&pAI->ah.ih, &pAI->ah.ih, AI_MEVENT_PRESSUREPLATE, AI_SPECIES_ALL, AI_GetPos(pAI), (float)AI_GetEA(pAI)->m_DeathId);
	}
}

