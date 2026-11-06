#include "decompdecomp_sync_616a1dc3e52f8c6e69f5.h"
#line 1 "func.c"
typedef struct {int values[2];} Retail_walkweight;
extern const int D_800BE400[2];
#line 8816 "reference.c"
void func_800731F8 ( CGameObjectInstance *pAI, float ang )
{
	int		picked;

	int		turn180type1[]={AI_ANIM_RTURN180, AI_ANIM_RTURNR90,
									 AI_ANIM_WTURN180, AI_ANIM_WTURNR90,
									 AI_ANIM_TURN180,  AI_ANIM_TURNR90 };

	int		turn180type2[]={AI_ANIM_RTURN1802, AI_ANIM_RTURNR902,
									 AI_ANIM_WTURN1802, AI_ANIM_WTURNR902,
									 AI_ANIM_TURN1802,  AI_ANIM_TURNR902 };

	int		turn180weight[]={100,     1,
									  1000000, 10000,
									  10,      1    };

	int		turnl90type1[]={AI_ANIM_RTURNL90,
									 AI_ANIM_WTURNL90,
									 AI_ANIM_TURNL90   };

	int		turnl90type2[]={AI_ANIM_RTURNL902,
									 AI_ANIM_WTURNL902,
									 AI_ANIM_TURNL902   };

	int		turnl90weight[]={10000, 1000000, 1};

	int		turnr90type1[]={AI_ANIM_RTURNR90,
									 AI_ANIM_WTURNR90,
									 AI_ANIM_TURNR90   };

	int		turnr90type2[]={AI_ANIM_RTURNR902,
									 AI_ANIM_WTURNR902,
									 AI_ANIM_TURNR902   };

	int		turnr90weight[]={10000, 1000000, 1};

	int		walktype1[]={AI_ANIM_RUN, AI_ANIM_WALK};

	int		walktype2[]={AI_ANIM_RUN2, AI_ANIM_WALK2};

	Retail_walkweight walkweight = *(const Retail_walkweight *)D_800BE400;


	// which way should we turn ?
	if ( ang < ANGLE_DTOR(-170) )
	{
		// turn around 180 degrees
		if (AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
			picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 6, turn180type2, turn180weight, NULL);
		else
			picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 6, turn180type1, turn180weight, NULL);

		if (picked==-1)
		{
			AI_NudgeRotY(pAI, D_800B6B00*ang/AI_RUNTURN_SMOOTHNESS);
			AI_GetDyn(pAI)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
		}
		else
		{
			AI_SetDesiredAnimByIndex(pAI, picked, FALSE);
			AI_GetDyn(pAI)->m_dwStatusFlags       |= AI_WAITFOR_CYCLE;
		}
	}
	else if ( ang < ANGLE_DTOR(-80) )
	{
		// turn left 90 degrees
		if (AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
			picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 3, turnl90type2, turnl90weight, NULL);
		else
			picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 3, turnl90type1, turnl90weight, NULL);

		if (picked==-1)
		{
			AI_NudgeRotY(pAI, D_800B6B00*ang/AI_RUNTURN_SMOOTHNESS);
			AI_GetDyn(pAI)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
		}
		else
		{
			AI_SetDesiredAnimByIndex(pAI, picked, FALSE);
			AI_GetDyn(pAI)->m_dwStatusFlags       |= AI_WAITFOR_CYCLE;
		}
	}
	else if ( ang < ANGLE_DTOR(80) )
	{
		// walking
		if (AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
			picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 2, walktype2, walkweight.values, NULL);
		else
			picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 2, walktype1, walkweight.values, NULL);

		if (picked==-1)
		{
			AI_NudgeRotY(pAI, D_800B6B00*ang/AI_RUNTURN_SMOOTHNESS);
			AI_GetDyn(pAI)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
		}
		else
		{
			AI_SetDesiredAnimByIndex(pAI, picked, FALSE);
			AI_GetDyn(pAI)->m_dwStatusFlags       &= (~AI_WAITFOR_CYCLE);
		}

		// do random turn ?
		if (RANDOM(300)<2)
		{
			if (AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
				picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 6, turn180type2, turn180weight, NULL);
			else
				picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 6, turn180type1, turn180weight, NULL);

			if (picked==-1)
			{
				AI_NudgeRotY(pAI, D_800B6B00*ang/AI_RUNTURN_SMOOTHNESS);
				AI_GetDyn(pAI)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
			}
			else
			{
				AI_SetDesiredAnimByIndex(pAI, picked, FALSE);
				AI_GetDyn(pAI)->m_dwStatusFlags       |= AI_WAITFOR_CYCLE;
			}
		}

		// make ai turn a direction
		AI_NudgeRotY(pAI, D_800B6B00*ang/AI_WALKTURN_SMOOTHNESS);
	}
	else if ( ang < ANGLE_DTOR(170) )
	{
		// turn right 90 degrees
		if (AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
			picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 3, turnr90type2, turnr90weight, NULL);
		else
			picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 3, turnr90type1, turnr90weight, NULL);

		if (picked==-1)
		{
			AI_NudgeRotY(pAI, D_800B6B00*ang/AI_RUNTURN_SMOOTHNESS);
			AI_GetDyn(pAI)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
		}
		else
		{
			AI_SetDesiredAnimByIndex(pAI, picked, FALSE);
			AI_GetDyn(pAI)->m_dwStatusFlags       |= AI_WAITFOR_CYCLE;
		}
	}
	else if ( ang <= ANGLE_DTOR(180) )
	{
		// turn around 180 degrees
		if (AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
			picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 6, turn180type2, turn180weight, NULL);
		else
			picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 6, turn180type1, turn180weight, NULL);

		if (picked==-1)
		{
			AI_NudgeRotY(pAI, D_800B6B00*ang/AI_RUNTURN_SMOOTHNESS);
			AI_GetDyn(pAI)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
		}
		else
		{
			AI_SetDesiredAnimByIndex(pAI, picked, FALSE);
			AI_GetDyn(pAI)->m_dwStatusFlags       |= AI_WAITFOR_CYCLE;
		}
	}
}

