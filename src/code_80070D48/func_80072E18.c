#include "common_local_source_5312.h"

#line 8983 "reference.c"
void func_80072E18(CGameObjectInstance *pAI)
{
	CGameObjectInstance	*pTarget;
	float						dm, tcy, acy, num, ghgt;
	int						waterFlag;
	BOOL						DontSetHeight = FALSE;


	// is ai near water
	waterFlag = func_800719B4(pAI);
	if (waterFlag == AI_NOT_NEAR_WATER)
		return;


	// if it floats remove any velocity
	if (		(AI_GetEA(pAI)->m_dwTypeFlags & AI_TYPE_FLOATINWATERONDEATH)
			&&	((waterFlag == AI_ON_WATERSURFACE) || (waterFlag == AI_BELOW_WATERSURFACE)) )
	{
		AI_GetVelocity(pAI)->x = 0;
		AI_GetVelocity(pAI)->y = 0;
		AI_GetVelocity(pAI)->z = 0;
	}

	// make ai match its targets height
	pTarget = pAI->m_pAttackerCGameObjectInstance;
	if (pTarget)
	{
		// what is water status of target ?
		waterFlag = func_800719B4(pTarget);
		switch (waterFlag)
		{
			case AI_BELOW_WATERSURFACE:
				if (!AI_GetDyn(pAI)->m_Health)
				{
					if (AI_GetEA(pAI)->m_dwTypeFlags & AI_TYPE_FLOATINWATERONDEATH)
						tcy = AI_GetWaterHeight(pAI) + (AI_GetEA(pAI)->m_DeadHeight/2);
					else
						DontSetHeight = TRUE;
				}
				else
				{
					// set target center y position
					tcy  = AI_GetPos(pTarget).y + (AI_GetEA(pTarget)->m_CollisionHeight/2);
					tcy -= (0.2*SCALING_FACTOR);
				}
				break;

			case AI_ON_WATERSURFACE:
			default:
				if (!AI_GetDyn(pAI)->m_Health)
				{
					if (AI_GetEA(pAI)->m_dwTypeFlags & AI_TYPE_FLOATINWATERONDEATH)
						tcy = AI_GetWaterHeight(pAI) + (AI_GetEA(pAI)->m_DeadHeight/2);
					else
						DontSetHeight = TRUE;
				}
				else
				{
					// make ai swim underwater
					tcy = AI_GetWaterHeight(pAI);
					tcy -= (0.2*SCALING_FACTOR);
				}
				break;
		}

		// should height be set ?
		if (DontSetHeight)
			return;

		// anything that avoids the player should appear at a slightly different height while swimming
		if (		(AI_GetEA(pAI)->m_dwTypeFlags & AI_TYPE_AVOIDPLAYER)
				&&	(AI_GetDyn(pAI)->m_Health) )
		{
			num = (((float) (((DWORD)pAI) & 0x1f)) / 9.0) * SCALING_FACTOR;
			tcy -= num;
		}

		// get ai center y position
		acy = AI_GetPos(pAI).y + (AI_GetEA(pAI)->m_CollisionHeight/2);

		if (		(AI_GetEA(pAI)->m_dwTypeFlags & AI_TYPE_AVOIDPLAYER)
				&&	(AI_GetDyn(pAI)->m_Health) )
		{
			if (tcy > AI_GetWaterHeight(pAI) - (5*SCALING_FACTOR))
				tcy -= (5*SCALING_FACTOR);

			ghgt = func_80019D3C(pAI->ah.ih.m_pCurrentRegion, AI_GetPos(pAI).x, AI_GetPos(pAI).z);

			if (tcy < ghgt + (5*SCALING_FACTOR) )
				tcy += 5*SCALING_FACTOR;

			dm = (tcy - acy) / 35;
			if (dm >  0.08*SCALING_FACTOR) dm =  0.08 * SCALING_FACTOR;
			else
				if (dm < -0.08*SCALING_FACTOR) dm = -0.08 *SCALING_FACTOR;
		}
		else
		{
			dm = (tcy - acy) / 15;
			if (dm >  0.3*SCALING_FACTOR) dm =  0.3 * SCALING_FACTOR;
			else
				if (dm < -0.3*SCALING_FACTOR) dm = -0.3 *SCALING_FACTOR;
		}

		// set new height ?
		if (!AI_GetDyn(pAI)->m_RetreatTimer)
			AI_GetPos(pAI).y += dm * frame_increment * 2;
	}
}
