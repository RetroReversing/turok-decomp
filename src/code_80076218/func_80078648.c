#include "common_local_source_5350.h"

static __inline BOOL IsPlayerAlive(void) { return (CEngineApp__GetPlayer(GetApp())->m_AI.m_Health > 0); }
void func_80078648(CGameObjectInstance *pMe, CGameObjectInstance *pDest)
{
	// declare variables
	CVector3	vDestPos;
	float		dist,
				turnang,
				projectileang,
				avoidrad;

	int		random;
	int		curAnim,
				curAnimTest,
				waterFlag,
				waterEnemyFlag,
				aiType;

	int		picked,
				pickedType,
				nType;

	BOOL		leaper;

	int	swimattacktypes[]   = {AI_ANIM_ATTACK_SWIM1, AI_ANIM_ATTACK_SWIM2, AI_ANIM_ATTACK_SWIM3, AI_ANIM_IDLE_SWIM};
	int	swimattackweights[] = {40, 40, 40,15};

	int strongtypes[]={AI_ANIM_ATTACK_STRONG1,
							 AI_ANIM_ATTACK_STRONG2,
							 AI_ANIM_ATTACK_STRONG3,
							 AI_ANIM_ATTACK_STRONG4,
							 AI_ANIM_ATTACK_STRONG5,
							 AI_ANIM_ATTACK_STRONG6,
							 AI_ANIM_ATTACK_STRONG7,
							 AI_ANIM_ATTACK_STRONG8,
							 AI_ANIM_ATTACK_STRONG9,
							 AI_ANIM_ATTACK_STRONG10,
							 AI_ANIM_ATTACK_STRONG11,
							 AI_ANIM_ATTACK_STRONG12,
							 AI_ANIM_ATTACK_STRONG13,
							 AI_ANIM_ATTACK_STRONG14};

	int strongweights[]={10,10,10,8,8,8,6,6,6,4,4,4,2,2};

	int weaktypes[]=  {AI_ANIM_ATTACK_WEAK1,
							 AI_ANIM_ATTACK_WEAK2,
							 AI_ANIM_ATTACK_WEAK3,
							 AI_ANIM_ATTACK_WEAK4,
							 AI_ANIM_ATTACK_WEAK5,
							 AI_ANIM_ATTACK_WEAK6,
							 AI_ANIM_ATTACK_WEAK7,
							 AI_ANIM_ATTACK_WEAK8,
							 AI_ANIM_ATTACK_WEAK9,
							 AI_ANIM_ATTACK_WEAK10,
							 AI_ANIM_ATTACK_WEAK11,
							 AI_ANIM_ATTACK_WEAK12,
							 AI_ANIM_ATTACK_WEAK13,
							 AI_ANIM_ATTACK_WEAK14};

	int weakweights[]={10,10,10,8,8,8,6,6,6,4,4,4,2,2};

	int swtypes[]={AI_ANIM_ATTACK_STRONG1,
						AI_ANIM_ATTACK_WEAK1,
						AI_ANIM_ATTACK_STRONG2,
						AI_ANIM_ATTACK_WEAK2,
						AI_ANIM_ATTACK_STRONG3,
						AI_ANIM_ATTACK_WEAK3,
						AI_ANIM_ATTACK_STRONG4,
						AI_ANIM_ATTACK_WEAK4,
						AI_ANIM_ATTACK_STRONG5,
						AI_ANIM_ATTACK_WEAK5,
						AI_ANIM_ATTACK_STRONG6,
						AI_ANIM_ATTACK_WEAK6,
						AI_ANIM_ATTACK_STRONG7,
						AI_ANIM_ATTACK_WEAK7,
						AI_ANIM_ATTACK_STRONG8,
						AI_ANIM_ATTACK_WEAK8,
						AI_ANIM_ATTACK_STRONG9,
						AI_ANIM_ATTACK_WEAK9,
						AI_ANIM_ATTACK_STRONG10,
						AI_ANIM_ATTACK_WEAK10,
						AI_ANIM_ATTACK_STRONG11,
						AI_ANIM_ATTACK_WEAK11,
						AI_ANIM_ATTACK_STRONG12,
						AI_ANIM_ATTACK_WEAK12,
						AI_ANIM_ATTACK_STRONG13,
						AI_ANIM_ATTACK_WEAK13,
						AI_ANIM_ATTACK_STRONG14,
						AI_ANIM_ATTACK_WEAK14};

	int swweights[]={5,5,5,5,5,5,5,5,5,5,5,5,5,5,
						  5,5,5,5,5,5,5,5,5,5,5,5,5,5};

	int	evadetypes[] = {AI_ANIM_EVADE_CROUCH,
								 AI_ANIM_EVADE_LEFT,
								 AI_ANIM_EVADE_RIGHT};
	int	evadeweights[]={8, 10, 10};

#if DEBUG_STAND_AI
	rmonPrintf("AI_Standard_Attack\r\n") ;
#endif


	// get ai water status
	waterFlag = func_800719B4(pMe);
	waterEnemyFlag = func_800719B4(pDest);

	// is this ai a leaper ?
	// special stuff so leapers can chase player into water aslong as they are not avoiding the water
	aiType = func_8001D398(&pMe->ah.ih);
	leaper = (		(aiType == AI_OBJECT_CHARACTER_LEAPER)
					&& (!(AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_AVOIDWATER)) );

	// get avoidance radius
	avoidrad = func_8005EDD8(pMe);

/*
	// DEBUG stuff
	switch(waterFlag)
	{
		case	AI_NOT_NEAR_WATER:
			if (waterEnemyFlag == AI_NOT_NEAR_WATER)     osSyncPrintf("leaper not near water, player not near water\n");
			if (waterEnemyFlag == AI_BELOW_WATERSURFACE) osSyncPrintf("leaper not near water, player below water surface\n");
			if (waterEnemyFlag == AI_ABOVE_WATERSURFACE) osSyncPrintf("leaper not near water, player above water surface\n");
			if (waterEnemyFlag == AI_ON_WATERSURFACE)    osSyncPrintf("leaper not near water, player on water surface\n");
			break;

		case	AI_BELOW_WATERSURFACE:
			if (waterEnemyFlag == AI_NOT_NEAR_WATER)     osSyncPrintf("leaper below water, player not near water\n");
			if (waterEnemyFlag == AI_BELOW_WATERSURFACE) osSyncPrintf("leaper below water, player below water surface\n");
			if (waterEnemyFlag == AI_ABOVE_WATERSURFACE) osSyncPrintf("leaper below water, player above water surface\n");
			if (waterEnemyFlag == AI_ON_WATERSURFACE)    osSyncPrintf("leaper below water, player on water surface\n");
			break;

		case	AI_ABOVE_WATERSURFACE:
			if (waterEnemyFlag == AI_NOT_NEAR_WATER)     osSyncPrintf("leaper above water, player not near water\n");
			if (waterEnemyFlag == AI_BELOW_WATERSURFACE) osSyncPrintf("leaper above water, player below water surface\n");
			if (waterEnemyFlag == AI_ABOVE_WATERSURFACE) osSyncPrintf("leaper above water, player above water surface\n");
			if (waterEnemyFlag == AI_ON_WATERSURFACE)    osSyncPrintf("leaper above water, player on water surface\n");
			break;

		case	AI_ON_WATERSURFACE:
			if (waterEnemyFlag == AI_NOT_NEAR_WATER)     osSyncPrintf("leaper on water, player not near water\n");
			if (waterEnemyFlag == AI_BELOW_WATERSURFACE) osSyncPrintf("leaper on water, player below water surface\n");
			if (waterEnemyFlag == AI_ABOVE_WATERSURFACE) osSyncPrintf("leaper on water, player above water surface\n");
			if (waterEnemyFlag == AI_ON_WATERSURFACE)    osSyncPrintf("leaper on water, player on water surface\n");
			break;
	}
*/

	// calculate angle to face to point at destination
	nType = func_8001D398(&pMe->ah.ih);
	if ((nType >= AI_OBJECT_WEAPON_START) && (nType <= AI_OBJECT_WEAPON_END))
		nType = AI_OBJECT_CHARACTER_PLAYER;

	switch (nType)
	{
		case AI_OBJECT_CHARACTER_HUMAN1:
		case AI_OBJECT_CHARACTER_RAPTOR:
			vDestPos = func_8005ED90(pMe, pDest);
//			vDestPos = AI_GetPos(pDest);
			break;

		default:
		case AI_OBJECT_CHARACTER_PLAYER:
			vDestPos = AI_GetPos(pDest);
			break;
	}

	// ai should not attack a dead turok - they should return to there leash coor
	if (		(pDest == CEngineApp__GetPlayer(GetApp()))
			&&	((pDest->m_AI.m_Health == 0) || (func_80039B98(&GetApp()->m_Camera))) )
	{
		AI_GetDyn(pMe)->m_AvoidanceAngle =
		turnang = func_800747C0(pMe, AI_GetDyn(pMe)->m_vLeashCoor, pDest, avoidrad);

		if (		(waterFlag == AI_ON_WATERSURFACE)
				||	(waterFlag == AI_BELOW_WATERSURFACE) )
		{
			func_80072D08(pMe, turnang);
		}
		else
		{
			func_80073FD8(pMe, turnang);
		}
		return;
	}
	else
	{
		AI_GetDyn(pMe)->m_AvoidanceAngle =
		turnang = func_800747C0(pMe, vDestPos, pDest, avoidrad);
	}

	// don't attack if the ai cannot see his target
	if (!func_8001DE20(&pMe->ah, &pMe->m_pAttackerCGameObjectInstance->ah.ih))
	{
		if (		(waterFlag == AI_ON_WATERSURFACE)
				||	(waterFlag == AI_BELOW_WATERSURFACE) )
		{
			func_80072D08(pMe, turnang);
		}
		else
		{
			func_80073FD8(pMe, turnang);
		}
		return;
	}

	// how close is this ai to destination ?
	dist = func_8005F34C(pMe, vDestPos);

	// first time entering attack mode ? (gets attention if it is a leader)
	if (    (AI_GetDyn(pMe)->m_dwStatusFlags & AI_FIRST_ATTACK)
		  && (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_LEADER)
		  && (waterFlag != AI_BELOW_WATERSURFACE)
		  && (waterFlag != AI_ON_WATERSURFACE) )
	{
		// first attack
		func_80071CF0(pMe);
	}
	// (not first attack) should ai run to meet turok or stand & fight
	else if (dist <= AI_GetEA(pMe)->m_AttackRadius)
	{
		if (func_8007223C(pMe, turnang))
		{
			// should ai fight or evade ?
			if (    (waterFlag == AI_BELOW_WATERSURFACE)
				  || (waterFlag == AI_ON_WATERSURFACE) )
			{
				picked = func_8001C348(pMe, 4, swimattacktypes, swimattackweights, &pickedType);
				AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
				func_8005FCA0(pMe, picked, (AI_GetDyn(pMe)->m_dwStatusFlags & AI_FIRST_ATTACK));
			}
			else
			{
				random = RANDOM(99);

				if ((random < AI_GetEA(pMe)->m_Aggression) || (!func_80076488(pMe, ANGLE_DTOR(20))))
				{
					if (    (  AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_USEWEAKATTACKS)
						  && (!(AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_USESTRONGATTACKS)) )
					{
						// weak attacks
						picked = func_8001C348(pMe, 14, weaktypes, weakweights, &pickedType);
					}
					else if (    (  AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_USESTRONGATTACKS)
						       && (!(AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_USEWEAKATTACKS)) )
					{
						// strong attacks
						picked = func_8001C348(pMe, 14, strongtypes, strongweights, &pickedType);
					}
					else if (    (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_USESTRONGATTACKS)
						       && (AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_USEWEAKATTACKS) )
					{
						// both weak & strong attacks
						picked = func_8001C348(pMe, 28, swtypes, swweights, &pickedType);
					}
					else if (    (!(AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_USESTRONGATTACKS))
						       && (!(AI_GetEA(pMe)->m_dwTypeFlags & AI_TYPE_USEWEAKATTACKS)) )
					{
						// neither weak or strong attacks
						func_80073FD8(pMe, turnang);
					}

					AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
					func_8005FCA0(pMe, picked, (AI_GetDyn(pMe)->m_dwStatusFlags & AI_FIRST_ATTACK));
				}
				else
				{
					picked = func_8001C348(pMe, 3, evadetypes, evadeweights, &pickedType);

					AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
					func_8005FCA0(pMe, picked, FALSE);
				}
			}
		}
	}
	else
	{
		// get projectile angle - is it worth firing ?
		projectileang = func_80071DA4(pMe, AI_GetPos(pDest));

		// ai is not within close attack range - does ai fire projectiles ?
		if (		(func_80071770(pMe))
				&&	(		(dist >= (AI_GetEA(pMe)->m_ProjectileRadius/2))
						|| (waterEnemyFlag != AI_NOT_NEAR_WATER) )
				&&	(fabs(projectileang) <= ANGLE_DTOR(5))
				&&	(waterFlag != AI_BELOW_WATERSURFACE)
				&& (waterFlag != AI_ON_WATERSURFACE) )

		{
			// is ai within projectile firing radius ?
			if ( dist <= AI_GetEA(pMe)->m_ProjectileRadius )
			{
				func_80076824(pMe, projectileang, TRUE);
			}
			else
			{
				if (RANDOM(100)<4)
					func_80076824(pMe, projectileang, TRUE);
				else
				{
					func_80073FD8(pMe, turnang);
				}
			}
		}
		else
		{
			// ai does not fire projectile weapon - make it move towards turok for attacking
			if (		(func_80071770(pMe))
					&&	(		(fabs(projectileang) <= ANGLE_DTOR(10))
							||	(waterEnemyFlag != AI_NOT_NEAR_WATER) )
					&&	(		(RANDOM(100)<20)
							||	(waterEnemyFlag != AI_NOT_NEAR_WATER) )
					&&	(waterFlag != AI_BELOW_WATERSURFACE)
					&&	(waterFlag != AI_ON_WATERSURFACE) )
			{
				func_80076824(pMe, projectileang, TRUE);
			}
			else
			{
				if (    (waterFlag == AI_BELOW_WATERSURFACE)
					  || (waterFlag == AI_ON_WATERSURFACE) )
				{
					if (		(func_8001BA24(&pMe->ah.ih))
							&&	(waterFlag != AI_BELOW_WATERSURFACE) )
					{
						func_80073FD8(pMe, turnang);
					}
					else
					{
						func_80072D08(pMe, turnang);
					}
				}
				else
				{
					if (		(dist <= AI_RUN2WALK_DISTANCE)
							&&	(		(waterEnemyFlag == AI_NOT_NEAR_WATER)
									||	(leaper) ) )
					{
						// ai is within walking distance is its prey moving ?
						curAnim = func_80071C8C(pMe);

						if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
							curAnimTest = func_800186FC(pMe, AI_ANIM_RUN2);
						else
							curAnimTest = func_800186FC(pMe, AI_ANIM_RUN);

						if (curAnim == curAnimTest)
						{
							func_80073FD8(pMe, turnang);
						}
						else
						{
							func_800731F8(pMe, turnang);
						}
					}
					else if (		(dist > AI_RUN2WALK_DISTANCE)
									&&	(		(waterEnemyFlag == AI_NOT_NEAR_WATER)
											||	(leaper) ) )
					{
						func_80073FD8(pMe, turnang);
					}
					else if (		(waterEnemyFlag != AI_NOT_NEAR_WATER)
									&&	(waterFlag == AI_NOT_NEAR_WATER) )
					{
						// enemy is in water & this ai does not have any projectile firing means
						// what shall we do - make it run back to its leash coordinate

						// get avoidance radius
						avoidrad = func_8005EDD8(pMe);

						// calculate angle to face to point at the leash start position
						AI_GetDyn(pMe)->m_AvoidanceAngle =
						turnang = func_800747C0(pMe, AI_GetDyn(pMe)->m_vLeashCoor, CEngineApp__GetPlayer(GetApp()), avoidrad);
						func_80073FD8(pMe, turnang);
//						AI_Make_Get_Attention(pMe);
					}
				}
			}
		}
	}

	// keep agitation up, now that we are fighting (only if ai we are attacking is alive)
	if (IsPlayerAlive())
		func_8005F2B8(pMe, AI_AGITATION_FIGHTING, 300);

	// ai is no longer in first attack
	AI_GetDyn(pMe)->m_dwStatusFlags &= ~AI_FIRST_ATTACK;
}

/* Adjacent retail data words following the three-weight initializer, verified in the ROM. */
int adjacent_retail_ai_words[2] = {24,95};
