#include "decompdecomp_sync_fe8b057ea0aabab05228.h"
#line 1 "func.c"
#line 1478 "reference.c"
void AI_Standard_DeadBodyRiddle(CGameObjectInstance *pMe)
{
	int	picked=-1;
	int	pickedType=-1;

	int	normaltypes[]={AI_ANIM_TWITCH_NORMAL1,
								AI_ANIM_TWITCH_NORMAL2,
								AI_ANIM_DEATH_NORMAL};
	int	normalweights[]={100000,100000,1};

	int	violenttypes[]={AI_ANIM_TWITCH_VIOLENT1,
								AI_ANIM_TWITCH_VIOLENT2,
								AI_ANIM_DEATH_VIOLENT};
	int	violentweights[]={100000,100000,1};

	int	highfalltypes[]={AI_ANIM_TWITCH_HIGHFALL1,
								AI_ANIM_TWITCH_HIGHFALL2,
								AI_ANIM_DEATH_HIGH_FALL};
	int	highfallweights[]={100000,100000,1};

	int	wipeouttypes[]={AI_ANIM_TWITCH_WIPEOUT1,
								AI_ANIM_TWITCH_WIPEOUT2,
								AI_ANIM_DEATH_WIPEOUT};
	int	wipeoutweights[]={100000,100000,1};

	int	expdead1types[]={AI_ANIM_TWITCH_EXPDEAD1_1,
								AI_ANIM_TWITCH_EXPDEAD1_2,
								AI_ANIM_IMPACT_EXPLODE_DEAD1};
	int	expdead1weights[]={100000,100000,1};

	int	expdead2types[]={AI_ANIM_TWITCH_EXPDEAD2_1,
								AI_ANIM_TWITCH_EXPDEAD2_2,
								AI_ANIM_IMPACT_EXPLODE_DEAD2};
	int	expdead2weights[]={100000,100000,1};

	int	explefttypes[]={AI_ANIM_TWITCH_EXPLEFT1,
								AI_ANIM_TWITCH_EXPLEFT2,
								AI_ANIM_IMPACT_EXPLODE_LEFT};
	int	expleftweights[]={100000,100000,1};

	int	exprighttypes[]={AI_ANIM_TWITCH_EXPRIGHT1,
								AI_ANIM_TWITCH_EXPRIGHT2,
								AI_ANIM_IMPACT_EXPLODE_RIGHT};
	int	exprightweights[]={100000,100000,1};

	int	expbacktypes[]={AI_ANIM_TWITCH_EXPBACK1,
								AI_ANIM_TWITCH_EXPBACK2,
								AI_ANIM_IMPACT_EXPLODE_BACKWARD};
	int	expbackweights[]={100000,100000,1};

	int	expfortypes[]={AI_ANIM_TWITCH_EXPFOR1,
								AI_ANIM_TWITCH_EXPFOR2,
								AI_ANIM_IMPACT_EXPLODE_FORWARD};
	int	expforweights[]={100000,100000,1};


                  
                                               
      

	// what is the last death animation ?
	switch(AI_GetDyn(pMe)->m_DeathAnimType)
	{
		case AI_ANIM_DEATH_NORMAL:
		case AI_ANIM_DEATH_NORMAL2:
		case AI_ANIM_TWITCH_NORMAL1:
		case AI_ANIM_TWITCH_NORMAL2:
			picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 3, normaltypes, normalweights, &pickedType);
			break;

		case AI_ANIM_DEATH_VIOLENT:
		case AI_ANIM_DEATH_VIOLENT2:
		case AI_ANIM_DEATH_VIOLENTLESSCHANCE:
		case AI_ANIM_DEATH_VIOLENT2LESSCHANCE:
		case AI_ANIM_TWITCH_VIOLENT1:
		case AI_ANIM_TWITCH_VIOLENT2:
			picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 3, violenttypes, violentweights, &pickedType);
			break;

		case AI_ANIM_DEATH_WIPEOUT:
		case AI_ANIM_DEATH_WIPEOUT2:
		case AI_ANIM_TWITCH_WIPEOUT1:
		case AI_ANIM_TWITCH_WIPEOUT2:
			picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 3, wipeouttypes, wipeoutweights, &pickedType);
			break;

		case AI_ANIM_DEATH_HIGH_FALL:
		case AI_ANIM_TWITCH_HIGHFALL1:
		case AI_ANIM_TWITCH_HIGHFALL2:
			picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 3, highfalltypes, highfallweights, &pickedType);
			break;

		case AI_ANIM_IMPACT_EXPLODE_DEAD1:
		case AI_ANIM_TWITCH_EXPDEAD1_1:
		case AI_ANIM_TWITCH_EXPDEAD1_2:
			picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 3, expdead1types, expdead1weights, &pickedType);
			break;

		case AI_ANIM_IMPACT_EXPLODE_DEAD2:
		case AI_ANIM_TWITCH_EXPDEAD2_1:
		case AI_ANIM_TWITCH_EXPDEAD2_2:
			picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 3, expdead2types, expdead2weights, &pickedType);
			break;

		case AI_ANIM_IMPACT_EXPLODE_LEFT_LAND:
		case AI_ANIM_TWITCH_EXPLEFT1:
		case AI_ANIM_TWITCH_EXPLEFT2:
			picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 3, explefttypes, expleftweights, &pickedType);
			break;

		case AI_ANIM_IMPACT_EXPLODE_RIGHT_LAND:
		case AI_ANIM_TWITCH_EXPRIGHT1:
		case AI_ANIM_TWITCH_EXPRIGHT2:
			picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 3, exprighttypes, exprightweights, &pickedType);
			break;

		case AI_ANIM_IMPACT_EXPLODE_BACKWARD_LAND:
		case AI_ANIM_TWITCH_EXPBACK1:
		case AI_ANIM_TWITCH_EXPBACK2:
			picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 3, expbacktypes, expbackweights, &pickedType);
			break;

		case AI_ANIM_IMPACT_EXPLODE_FORWARD_LAND:
		case AI_ANIM_TWITCH_EXPFOR1:
		case AI_ANIM_TWITCH_EXPFOR2:
			picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 3, expfortypes, expforweights, &pickedType);
			break;

		default:
		case -1:
			break;
	}

	// was valid anim picked ?
	if (picked != -1)
	{
		// was the picked animation a repeatable twitch ?
		switch(pickedType)
		{
			// play chosen twitch animation
			default:
				AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
				AI_SetDesiredAnimByIndex(pMe, picked, TRUE);
				CGameObjectInstance__RestartAnim(pMe);
				break;

			// should not do any animation for these anims - not proper twitch animations
			case -1:
			case AI_ANIM_IMPACT_EXPLODE_BACKWARD:
			case AI_ANIM_IMPACT_EXPLODE_FORWARD:
			case AI_ANIM_IMPACT_EXPLODE_LEFT:
			case AI_ANIM_IMPACT_EXPLODE_RIGHT:
			case AI_ANIM_IMPACT_EXPLODE_DEAD1:
			case AI_ANIM_IMPACT_EXPLODE_DEAD2:
			case AI_ANIM_DEATH_NORMAL:
			case AI_ANIM_DEATH_NORMAL2:
			case AI_ANIM_DEATH_HIGH_FALL:
			case AI_ANIM_DEATH_VIOLENT:
			case AI_ANIM_DEATH_VIOLENT2:
			case AI_ANIM_DEATH_WIPEOUT:
			case AI_ANIM_DEATH_WIPEOUT2:
				break;
		}
	}

	// set last death animation
	AI_GetDyn(pMe)->m_DeathAnimType = pickedType;
}

