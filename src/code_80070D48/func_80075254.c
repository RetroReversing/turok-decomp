#include "decompdecomp_sync_a87668ce63b1b7a5d010.h"
#line 1 "func.c"

short func_80074DCC ( CGameObjectInstance *pAI )
{
	return (short) ( AI_GetDyn(pAI)->m_Agitation / AI_AGITATION_STEP );
}
#line 1843 "reference.c"
void func_80075254(CGameObjectInstance *pMe)
{
	// declare variables
	short						alevel;
	float						Dist,
								DistTurok;
	CGameObjectInstance	*pLeader,
								*pPlayer;
	int						waterFlag,
								nAnim;
	BOOL						Regen;


	if (AI_GetEA(pMe)->m_wTypeFlags3 & AI_TYPE3_DUMB)
	{
		AI_GetDyn(pMe)->m_dwStatusFlags2 |= AI_VISIBLE;
		func_8005FCF4(pMe, AI_ANIM_EXTRA1, TRUE);
		return ;
	}


	// get pointer to player
	pPlayer = CEngineApp__GetPlayer(GetApp());


	// first time running ai ?
	if (AI_GetDyn(pMe)->m_FirstRun)
	{
		if (pMe == pPlayer)
		{
			AI_GetDyn(pMe)->m_FirstRun = FALSE;
		}
		else
		{
			if (		(AI_GetDyn(pMe)->m_dwStatusFlags & AI_INTERACTIVEANIMATION)
					&&	(AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_HOLDINTANIMON1STFRAME) )
			{
				AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
				nAnim = AI_GetEA(pMe)->m_InteractiveAnim - 1 + AI_ANIM_INTERACTIVE_ANIMATION1;
				func_8005FCF4(pMe, nAnim, TRUE);
				func_8001E93C(pMe);
				//AI_GetDyn(pMe)->m_Invincible = TRUE;
			}

			// show interactive anim once ?
			if (AI_GetEA(pMe)->m_wTypeFlags3 & AI_TYPE3_SHOWINTANIMONCE)
				D_80034900(&GetApp()->m_Scene, pMe, TRUE);

			if (AI_GetDyn(pMe)->m_dwStatusFlags & AI_REGENERATE)
				CGameObjectInstance__SetGone(pMe);

			AI_GetDyn(pMe)->m_FirstRun = FALSE;
		}
		return;
	}

	// Clear collision structure
	D_80128F80 = FALSE ;

	// get water status
	waterFlag = func_800719B4(pMe);

	// update turok specific stuff
	if (pMe == pPlayer)
	{
		// if in end sequence mode, spped up turoks animation speed
		if (GetApp()->m_Camera.m_Mode == CAMERA_CINEMA_END_SEQUENCE2_MODE)
			D_800B6B00 *= 1.5 ;
		// update turok on screen weapon animations (only for u64 engine)
		//if (!AI_Cycle_Completed(pMe)) return;									// wait for animation cycle to be completed
		if (D_80079BA0(pMe)) return;
		return;
	}

	// check for water gaff's
	if (		(AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_AVOIDWATER)
			&&	((waterFlag == AI_ON_WATERSURFACE) || (waterFlag == AI_BELOW_WATERSURFACE))
			&& (AI_GetDyn(pMe)->m_Health) )
	{
		// kill this ai
		func_8006364C(&pMe->ah.ih);
//		AI_CompletelyKillOff(pMe);
		return;
	}

	// is this character frozen ?
	if (AI_GetDyn(pMe)->m_FreezeTimer != 0.0)
	{
		// ready for this ai to explode ?
		if (AI_GetDyn(pMe)->m_FreezeTimer == AI_FREEZE_END)
		{
			// set random timer for frozen explosion
			AI_GetDyn(pMe)->m_Time1 = RANDOM(25);
			AI_GetDyn(pMe)->m_FreezeTimer = AI_FREEZE_GOINGTOEXPLODE;
		}

		if (AI_GetDyn(pMe)->m_FreezeTimer == AI_FREEZE_GOINGTOEXPLODE)
		{
			AI_GetDyn(pMe)->m_Time1--;
			if (AI_GetDyn(pMe)->m_Time1 <= 0.0)
			{
				// generate particle effect of ai exploding
				func_8005F840(&pMe->ah.ih, PARTICLE_TYPE_FREEZE_EXPLOSION, AI_GetPos(pMe));

				// get rid of ai
				AI_GetDyn(pMe)->m_dwStatusFlags	|= AI_ALREADY_DEAD;
				AI_GetDyn(pMe)->m_MeltTimer		= 0.0;
				AI_GetDyn(pMe)->m_FreezeTimer		= 0.0;
				pMe->m_cMelt							= MELT_LENGTH;
				CGameObjectInstance__SetGone(pMe);
			}
		}

		return;
	}

	// does this ai have to hold on 1st frame ?
	if (AI_GetDyn(pMe)->m_dwStatusFlags2 & AI_HOLDINTANIMON1STFRAME)
		D_800B6B00 = 0.0;

	// if this ai has interactive flag, it is waiting, return
	if (AI_GetDyn(pMe)->m_dwStatusFlags & AI_INTERACTIVEANIMATION)
		return;

	// does the interactive animation have a delay ?
	if (AI_GetDyn(pMe)->m_dwStatusFlags & AI_INTERANIMDELAY)
	{
		AI_GetDyn(pMe)->m_InteractiveTimer -= (1.0 / 20.0);
		if (AI_GetDyn(pMe)->m_InteractiveTimer > 0.0)
			return;

		// stop holding on 1st frame
		AI_GetDyn(pMe)->m_dwStatusFlags2 &= ~AI_HOLDINTANIMON1STFRAME;

		// make ai visible
		AI_GetDyn(pMe)->m_dwStatusFlags2 |= AI_VISIBLE;

		// is ai gone ?
		if (		(CGameObjectInstance__IsGone(pMe))
				&&	(AI_GetDyn(pMe)->m_dwStatusFlags & AI_REGENERATE) )
		{
			CGameObjectInstance__SetNotGone(pMe);
		}

		// delay has ran out - let ai run
		AI_GetDyn(pMe)->m_InteractiveTimer = 0.0;
		AI_GetDyn(pMe)->m_dwStatusFlags &= ~AI_INTERANIMDELAY;

		// start the delayed interactive animation
		nAnim = AI_GetEA(pMe)->m_InteractiveAnim - 1 + AI_ANIM_INTERACTIVE_ANIMATION1;

		// play interactive anim again while regenerating ?
		if (AI_GetDyn(pMe)->m_dwStatusFlags & AI_REGENERATEINTERANIM)
			AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;

		func_8005FCF4(pMe, nAnim, TRUE);
		func_8001E93C(pMe);
		//AI_GetDyn(pMe)->m_Invincible = TRUE;
		return;
	}

	// new regeneration that was gone ? (if interactive anims are not used)
	if (		CGameObjectInstance__IsGone(pMe)
			&& (!D_80071020(pMe))
			&&	(AI_GetDyn(pMe)->m_dwStatusFlags & AI_REGENERATE) )
	{
		CGameObjectInstance__SetNotGone(pMe);
	}

	// if ai is appearing fade it in
	if (		(AI_GetDyn(pMe)->m_cRegenerateAppearance == APPEARANCE_LENGTH*7/8)
			&&	(!(AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_REPLAYINTANIMONREG))
			&& (!(AI_GetDyn(pMe)->m_dwStatusFlags2 & AI_REGENERATEAPPEARANCEDELAY)) )
	{
		func_8005F840(&pMe->ah.ih, PARTICLE_TYPE_REGENERATION_START, AI_GetPos(pMe));
		AI_GetDyn(pMe)->m_dwStatusFlags2 |= AI_REGENERATEAPPEARANCEDELAY;
		AI_GetDyn(pMe)->m_Time1 = 1.5;		// seconds before regenerated ai appears
		D_8005EED0(&pMe->ah.ih, SOUND_GENERIC_66, 1, 0);
	}

	// waiting for regeneration to appear ?
	if (AI_GetDyn(pMe)->m_dwStatusFlags2 & AI_REGENERATEAPPEARANCEDELAY)
	{
		if (AI_GetDyn(pMe)->m_Time1 > 0.0)
		{
			AI_GetDyn(pMe)->m_Time1 -= D_800B6B00*(1.0/FRAME_FPS);
			if (AI_GetDyn(pMe)->m_Time1 < 0.0)
				AI_GetDyn(pMe)->m_Time1 = 0.0;

			return;
		}
		else
		{
			AI_GetDyn(pMe)->m_dwStatusFlags2 &= ~AI_REGENERATEAPPEARANCEDELAY;
			func_8005F840(&pMe->ah.ih, PARTICLE_TYPE_REGENERATION_APPEARANCE, AI_GetPos(pMe));
			D_8005EED0(&pMe->ah.ih, SOUND_HIGH_PRIEST_TELEPORT, 1, 0);
		}
	}


	// regenerations is now appearing
	if (		(AI_GetDyn(pMe)->m_cRegenerateAppearance)
			&&	(!(AI_GetDyn(pMe)->m_dwStatusFlags2 & AI_REGENERATEAPPEARANCEDELAY)) )
	{
		AI_GetDyn(pMe)->m_cRegenerateAppearance -= D_800B6B00;
		if (AI_GetDyn(pMe)->m_cRegenerateAppearance <= 0.0)
		{
			// completely faded in
			AI_GetDyn(pMe)->m_cRegenerateAppearance = 0.0;
			AI_GetDyn(pMe)->m_cRegenerateAppearanceWhite = APPEARANCEWHITE_LENGTH;
		}
	}

	// whiteness after regeneration
	if (		(AI_GetDyn(pMe)->m_cRegenerateAppearanceWhite)
			&&	(!(AI_GetDyn(pMe)->m_dwStatusFlags2 & AI_REGENERATEAPPEARANCEDELAY)) )
	{
		AI_GetDyn(pMe)->m_cRegenerateAppearanceWhite -= D_800B6B00;
		if (AI_GetDyn(pMe)->m_cRegenerateAppearanceWhite <= 0.0)
		{
			// not white anymore
			AI_GetDyn(pMe)->m_cRegenerateAppearanceWhite = 0.0;
		}
	}

	// allow ai to be killed outside of view when it becomes active
	if (			(AI_GetEA(pMe)->m_wTypeFlags3 & AI_TYPE3_KILLOUTSIDEOFVIEW)
			&&		(CGameObjectInstance__IsVisible(pMe))
			&&		(!(AI_GetDyn(pMe)->m_dwStatusFlags2 & AI_KILLOUTSIDEOFVIEW)) )
	{
		AI_GetDyn(pMe)->m_dwStatusFlags2 |= AI_KILLOUTSIDEOFVIEW;
	}


	// update melting timer when they are ready to melt
	D_80071854(pMe);

	// what should this ai attack ?
	D_800751CC(pMe);

	// Assist in getting to target!
	if (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_SNIPER)
		D_800727E0(pMe);
	else
		func_8007666C(pMe);

	// keep ai flying if it does
	func_80076FB4(pMe, pMe->m_pAttackerCGameObjectInstance);

	// keep ai swimming if it does
	func_80072E18(pMe);

	// is this enemy going to feign death ?
	D_80075090(pMe);

	// is this enemy going to resurrect itself ?
	D_80074F20(pMe);

	// ai landing on ground after an explosion ?
	func_80077B34(pMe, waterFlag);

	// has this ai been hit by an explosion ? (flying ai)
	if (		(AI_GetDyn(pMe)->m_dwStatusFlags & AI_EV_EXPLOSION)
			&&	(AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_FLYING) )
	{
		// convert explosion into normal hit
		AI_GetDyn(pMe)->m_dwStatusFlags &= ~AI_EV_EXPLOSION;
		AI_GetDyn(pMe)->m_dwStatusFlags |= AI_EV_HIT;
	}

	// has this ai been hit by an explosion ? (not a flying ai)
	if (		(AI_GetDyn(pMe)->m_dwStatusFlags & AI_EV_EXPLOSION)
			&&	(!(AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_FLYING)) )
	{
//#ifdef GERMAN
//		// convert explosion into normal hit
//		AI_GetDyn(pMe)->m_dwStatusFlags &= ~AI_EV_EXPLOSION;
//		AI_GetDyn(pMe)->m_dwStatusFlags |= AI_EV_HIT;
//#else
		// ai has an explosion death anim - it is ok to explode it when it is dead
		D_80078040(pMe);
//#endif
	}

	// has this ai been hit ?
	else if (AI_GetDyn(pMe)->m_dwStatusFlags & AI_EV_HIT)
	{
		if (AI_GetDyn(pMe)->m_Health > 0)
		{
			D_80078378(pMe);
		}
		else
		{
			// do dead body riddle with bullets animation
			if (waterFlag == AI_NOT_NEAR_WATER)
			{
				AI_GetDyn(pMe)->m_dwStatusFlags &= ~AI_EV_HIT;
				if ( (AI_GetDyn(pMe)->m_dwStatusFlags & AI_ALREADY_DEAD) && D_800720C8(pMe) )
					D_80077368(pMe);
			}
		}
	}

	// do general updates
	if (AI_GetDyn(pMe)->m_Health > 0)
	{
		// reset ai running flag
		AI_GetDyn(pMe)->m_dwStatusFlags &= (~AI_RUNNING);

		// ai does its normal stuff
		if ( (! D_80071F08(pMe, pMe->m_pAttackerCGameObjectInstance)) || func_80074DCC(pMe) == AI_AGITATED_ATTACK )	// can ai see target ?
		{
			if ( ! D_800720C8 ( pMe ) ) return;			// wait for animation cycle to be completed (overided by turok being seen)

			if (    (waterFlag != AI_ON_WATERSURFACE)
				  && (waterFlag != AI_BELOW_WATERSURFACE)
				  && (!(AI_GetDyn(pMe)->m_dwStatusFlags & AI_TELEPORTING)) )
			{
				if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
					func_8005FCF4(pMe, AI_ANIM_IDLE2, FALSE);
				else
					func_8005FCF4(pMe, AI_ANIM_IDLE, FALSE);
			}
		}
		func_80074DE8 ( pMe, AI_AGITATION_CALM );		// decrease agitation

		// is turok dead ?
		if (AI_GetDyn(pPlayer)->m_Health == 0)
			func_80074DE8(pMe, AI_AGITATION_CALMAFTERFIGHT);		// decrease agitation even more because turok is dead

		// make ai teleport if it has to
		func_80074C34(pMe);

		// get agitation level
		alevel = func_80074DCC(pMe);

		// does ai have a leash ?
		if (AI_GetEA(pMe)->m_LeashRadius>0)
		{
			Dist      = func_8005F34C(pMe, AI_GetDyn(pMe)->m_vLeashCoor);
			DistTurok = func_8005F34C(pPlayer, AI_GetDyn(pMe)->m_vLeashCoor);
			if (Dist     >=AI_GetEA(pMe)->m_LeashRadius ||
				 DistTurok>=AI_GetEA(pMe)->m_LeashRadius      )
			{
				// set agitation back to zero - ai will return to start position (vLeashCoor)
				alevel=0;
			}
		}

		// set first attack flag if this is the first time the ai is in attack mode
		if ( (AI_GetDyn(pMe)->m_PrevAgitation != alevel) && (alevel == AI_AGITATED_ATTACK) )
		{
			AI_GetDyn(pMe)->m_dwStatusFlags |= AI_FIRST_ATTACK;
		}

		// is ai to avoid the player ?
		if (    (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_AVOIDPLAYER)
			  && (D_80071F08(pMe, pMe->m_pAttackerCGameObjectInstance)) )
		{
			// ai avoids player - add on a random <2 seconds>
			AI_GetDyn(pMe)->m_RetreatTimer = AI_RETREAT_TIME + (((float)RANDOM(100))/50.0);
		}
		else if (AI_GetDyn(pMe)->m_RetreatTimer > 0.0)
		{
			AI_GetDyn(pMe)->m_RetreatTimer -= D_800B6B00*(1.0/FRAME_FPS);

			if (AI_GetDyn(pMe)->m_RetreatTimer < 0)
				AI_GetDyn(pMe)->m_RetreatTimer = 0;
		}

		// is ai a flocker ?
		pLeader = pMe->m_pEventCGameObjectInstance;
		if (    (AI_GetDyn(pMe)->m_dwStatusFlags & AI_FLOCKING)
			  && (pLeader != NULL) )
		{
			if (AI_GetDyn(pLeader)->m_Health <= 0)
			{
				AI_GetDyn(pMe)->m_dwStatusFlags &= AI_FLOCKING;
				func_8005F2B8(pMe, AI_AGITATION_FIGHTING, 300);
				pMe->m_pEventCGameObjectInstance = NULL;
			}
			D_8007791C(pMe, pLeader);
		}
		else if (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_SNIPER)
		{
			// sniping
			func_8005F2B8(pMe, AI_AGITATION_FIGHTING, 300);
			D_8007719C(pMe, pMe->m_pAttackerCGameObjectInstance);
		}
		else if (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_FLYING)
		{
			// flying
			func_8005F2B8(pMe, AI_AGITATION_FIGHTING, 300);
			func_80076B3C(pMe, pMe->m_pAttackerCGameObjectInstance);
		}
		else if (AI_GetDyn(pMe)->m_RetreatTimer)
		{
			func_8007924C(pMe, pMe->m_pAttackerCGameObjectInstance);
		}
		else if (AI_GetEA(pMe)->m_wTypeFlags3 & AI_TYPE3_WALKINSTRAIGHTLINE)
		{
			func_8005FCF4(pMe, AI_ANIM_WALK, TRUE);
		}
		else
		{
			// do ai based on agitation state
			switch(alevel)
			{
				case AI_AGITATED_IDLE:
					AI_Standard_Idle(pMe);
					break;

				case AI_AGITATED_AGITATED:

					// Signal not going back to leash now
					AI_GetDyn(pMe)->m_dwStatusFlags &= ~AI_GOBACKTOLEASH ;

					switch(waterFlag)
					{
						case AI_ON_WATERSURFACE:
						case AI_BELOW_WATERSURFACE:
							AI_Standard_Idle(pMe);
							break;

						default:
							D_80079540(pMe);
							break;
					}
					break;

				case AI_AGITATED_ATTACK:

					// Signal not going back to leash now
					AI_GetDyn(pMe)->m_dwStatusFlags &= ~AI_GOBACKTOLEASH ;

					D_8005AFA8(&D_80128C20, TMOVE_INCOMBAT_TIMER);

					if (AI_GetDyn(pMe)->m_dwStatusFlags & AI_TELEPORTMOVESLOW)
					{
						D_80079090(pMe);
						break;
					}

					if (D_800791F0(pMe))
						break;

					D_80078648(pMe, pMe->m_pAttackerCGameObjectInstance);
					break;
			}
		}

		// set previous agitation level
		AI_GetDyn(pMe)->m_PrevAgitation = alevel;
	}
	else
	{
		// ai is dead - no health, is ai already done death animation ?
		if (!(AI_GetDyn(pMe)->m_dwStatusFlags & AI_ALREADY_DEAD))
		{
			// ai still to do death animation
			switch (D_800720C8(pMe))
			{
				case 0:
					break;				// wait for animation cycle to be completed


				case 2:
					// ai has played out its death anim there is no more except that lovely place where all creatures go
					AI_GetDyn(pMe)->m_dwStatusFlags |= AI_ALREADY_DEAD;
					if (waterFlag != AI_NOT_NEAR_WATER)
					{
						if (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_FLOATINWATERONDEATH)
							D_800783AC(pMe);
						else
							func_800784B0(pMe);
					}

					// ai should now be terminated
					break;

				default:
					if (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_FLYING)
						func_800785C0(pMe);
					else
						D_80077BFC(pMe);
					break;

			}
		}
		else
		{
			if (waterFlag != AI_NOT_NEAR_WATER)
			{
				if (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_FLOATINWATERONDEATH)
					D_800783AC(pMe);
				else
					func_800784B0(pMe);
			}

			// does this ai - die instantly
			if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_INSTANTDEATH)
			{
				AI_GetDyn(pMe)->m_MeltTimer		= 0.0;
				AI_GetDyn(pMe)->m_FreezeTimer		= 0.0;
				pMe->m_cMelt							= MELT_LENGTH;
				CGameObjectInstance__SetGone(pMe);
			}
		}
	}


	// make teleporting ai appear
	func_80074720(pMe);

	// invincibility only lasts until cycle is completed or advance runs at least once
	AI_GetDyn(pMe)->m_Invincible = FALSE;

	// leash test
	func_800763C0(pMe);

	// check for water gaff's
	if (		(AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_AVOIDWATER)
			&&	((waterFlag == AI_ON_WATERSURFACE) || (waterFlag == AI_BELOW_WATERSURFACE))
			&& (AI_GetDyn(pMe)->m_Health) )
	{
		// kill this ai
//		AI_CompletelyKillOff(pMe);
		func_8006364C(&pMe->ah.ih);
		return;
	}

	// does this ai regenerate ?
	if (		(D_8005FA10(pMe))
			&&	(pMe->m_cMelt >= MELT_LENGTH)
			&&	(AI_GetDyn(pMe)->m_Regenerate) )
	{
		// initialize ai do redo its interactive animation & fade in
		AI_GetDyn(pMe)->m_Regenerate--;											// one less regeneration
		AI_GetDyn(pMe)->m_cRegenerateAppearance = APPEARANCE_LENGTH*7/8;	// start completely faded out
		AI_GetDyn(pMe)->m_dwStatusFlags |= AI_REGENERATE;
		pMe->m_cMelt = 0;
		AI_GetDyn(pMe)->m_dwStatusFlags2 &= ~AI_REGENERATEAPPEARANCEDELAY;

		// regenerate from original start position
		if (AI_GetEA(pMe)->m_wTypeFlags3 & AI_TYPE3_REGENERATEFROMSTART)
		{
			AI_GetPos(pMe) = AI_GetDyn(pMe)->m_vStartPos;
			pMe->ah.ih.m_pCurrentRegion = AI_GetDyn(pMe)->m_pStartRegion;
			Regen = TRUE;
		}
		// make ai appear in a different place from where his leash center is
		else if (D_80074A74(pMe, AI_GetDyn(pMe)->m_vLeashCoor))
			Regen = TRUE;
		else
			Regen = FALSE;


		// did regeneration end up in valid position ?
		if (Regen)
		{
			// resurrect this ai
			func_8008453C(AI_GetDyn(pMe),
										 AI_GetEA(pMe),
										 CGameObjectInstance__TypeFlag(pMe));

			// setup random head, weapons, body parts etc...
			func_800840C4(AI_GetDyn(pMe), AI_GetEA(pMe), pMe) ;


			AI_GetDyn(pMe)->m_dwStatusFlags &= ~AI_INTERACTIVEANIMATION;
			AI_GetDyn(pMe)->m_InteractiveTimer = 2.0 + D_80013840(3.0);
			AI_GetDyn(pMe)->m_dwStatusFlags |= AI_INTERANIMDELAY;

			AI_GetDyn(pMe)->m_dwStatusFlags		&= ~AI_ALREADY_DEAD;
			AI_GetDyn(pMe)->m_dwStatusFlags		&= ~AI_WAITFOR_CYCLE;
			AI_GetDyn(pMe)->m_Agitation			= 0;
			AI_GetDyn(pMe)->m_PrevAgitation		= 0;
			AI_GetDyn(pMe)->m_dwStatusFlags		&= ~AI_WOUNDEDMORTALLY;
			AI_GetDyn(pMe)->m_dwStatusFlags2		&= ~AI_GENERATED_PICKUPS;

			func_8005FCF4(pMe, AI_ANIM_IDLE, TRUE);
			pMe->m_pAttackerCGameObjectInstance = NULL;

			func_800842CC(AI_GetDyn(pMe), AI_GetEA(pMe), CGameObjectInstance__TypeFlag(pMe));

			if (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_REPLAYINTANIMONREG)
			{
				AI_GetDyn(pMe)->m_dwStatusFlags |= AI_REGENERATEINTERANIM;

				// should this interactive anim hold on 1st frame ?
				if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_HOLDINTANIMON1STFRAME)
					AI_GetDyn(pMe)->m_dwStatusFlags2 |= AI_HOLDINTANIMON1STFRAME;
				else
					AI_GetDyn(pMe)->m_dwStatusFlags2 &= ~AI_HOLDINTANIMON1STFRAME;
			}
		}
	}

}

