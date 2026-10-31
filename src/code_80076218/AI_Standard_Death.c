#include "source_AI_Standard_Death.h"
#line 1 "func.c"
#line 1 "reference.c"
void AI_Standard_Death(CGameObjectInstance *pMe)
{
	int	picked,
			pickedType=-1;

	int	vdeathtypes1[]={AI_ANIM_DEATH_NORMAL,
							   AI_ANIM_DEATH_VIOLENT,
								AI_ANIM_DEATH_VIOLENTLESSCHANCE};

	int	vdeathtypes2[]={AI_ANIM_DEATH_NORMAL2,
							   AI_ANIM_DEATH_VIOLENT2,
								AI_ANIM_DEATH_VIOLENT2LESSCHANCE};

	int	vdeathweights[]={18, 3, 2};		// used to be 16, 5, 2

	int	vwipeouttypes1[]={AI_ANIM_DEATH_WIPEOUT,
								  AI_ANIM_DEATH_NORMAL,
								  AI_ANIM_DEATH_VIOLENT};

	int	vwipeouttypes2[]={AI_ANIM_DEATH_WIPEOUT2,
								  AI_ANIM_DEATH_NORMAL2,
								  AI_ANIM_DEATH_VIOLENT2};

	int	vwipeoutweights[]={8,2,2};		// used to be 8,4,2


	int	deathtypes1[]={AI_ANIM_DEATH_NORMAL};
	int	deathtypes2[]={AI_ANIM_DEATH_NORMAL2};
	int	deathweights[]={2};
	int	wipeouttypes1[]={AI_ANIM_DEATH_WIPEOUT,
								  AI_ANIM_DEATH_NORMAL};
	int	wipeouttypes2[]={AI_ANIM_DEATH_WIPEOUT2,
								  AI_ANIM_DEATH_NORMAL2};
	int	wipeoutweights[]={2};

	int	swimtypes[]={AI_ANIM_DEATH_SWIM};
	int	swimweights[]={1};

#if DEBUG_STAND_AI
	rmonPrintf("AI_Standard_Death\r\n") ;
#endif

	// violent death's ?
	if (AI_GetEA(pMe)->m_wTypeFlags3 & AI_TYPE3_DONTDOVIOLENTDEATH)
	{
		// violent deaths not allowed
		if (func_800719B4(pMe)==AI_BELOW_WATERSURFACE)
		{
			picked = func_8001C348(pMe, 1, swimtypes, swimweights, &pickedType);

			AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
			func_8005FCA0(pMe, picked, TRUE);
		}
		else
		{
			if (AI_GetDyn(pMe)->m_dwStatusFlags & AI_RUNNING)
			{
				if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
					picked = func_8001C348(pMe, 2, wipeouttypes2, wipeoutweights, &pickedType);
				else
					picked = func_8001C348(pMe, 2, wipeouttypes1, wipeoutweights, &pickedType);

				AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
				func_8005FCA0(pMe, picked, TRUE);
			}
			else
			{
				if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
					picked = func_8001C348(pMe, 1, deathtypes2, deathweights, &pickedType);
				else
					picked = func_8001C348(pMe, 1, deathtypes1, deathweights, &pickedType);

				AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
				func_8005FCA0(pMe, picked, TRUE);
			}
		}

		// set last death animation
		AI_GetDyn(pMe)->m_DeathAnimType = pickedType;
	}
	else
	{
		// violent deaths allowed
		if (func_800719B4(pMe)==AI_BELOW_WATERSURFACE)
		{
			picked = func_8001C348(pMe, 1, swimtypes, swimweights, &pickedType);

			AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
			func_8005FCA0(pMe, picked, TRUE);
		}
		else
		{
			if (AI_GetDyn(pMe)->m_dwStatusFlags & AI_RUNNING)
			{
				if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
					picked = func_8001C348(pMe, 3, vwipeouttypes2, vwipeoutweights, &pickedType);
				else
					picked = func_8001C348(pMe, 3, vwipeouttypes1, vwipeoutweights, &pickedType);

				AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
				func_8005FCA0(pMe, picked, TRUE);
			}
			else
			{
				if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
					picked = func_8001C348(pMe, 3, vdeathtypes2, vdeathweights, &pickedType);
				else
					picked = func_8001C348(pMe, 3, vdeathtypes1, vdeathweights, &pickedType);

				AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
				func_8005FCA0(pMe, picked, TRUE);
			}
		}

		// set last death animation
		AI_GetDyn(pMe)->m_DeathAnimType = pickedType;
	}
}

