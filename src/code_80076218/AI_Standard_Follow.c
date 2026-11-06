#include "source_AI_Standard_Follow.h"

static __inline BOOL IsPlayerAlive()
{
	return (CEngineApp__GetPlayer(GetApp())->m_AI.m_Health > 0);
}
void AI_Standard_Follow(CGameObjectInstance *pMe, CGameObjectInstance *pLeader)
{
	// declare variables
	CVector3	vLeaderPos;
	float		dist,
				turnang,
				avoidrad;
	int		curAnim,
				curAnimTest;


#if DEBUG_STAND_AI
	rmonPrintf("AI_Standard_Follow\r\n") ;
#endif

	// get avoidance radius
	avoidrad = AI_GetAvoidanceRadiusFactor(pMe);

	// calculate angle to face to point at the leader
	vLeaderPos = AI_GetPos(pLeader);

	AI_GetDyn(pMe)->m_AvoidanceAngle =
	turnang = AI_GetAvoidanceAngle(pMe, vLeaderPos, pLeader, avoidrad);

	// how close is this ai to the leader ?
	dist = AI_DistanceSquared(pMe, vLeaderPos);

	// ai should follow the leader
	if (dist <= AI_GetEA(pMe)->m_AttackRadius)
	{
		if (AI_Make_Turn(pMe, turnang))
		{
			// ai has reached & is facing the leader
			if (RANDOM(100)<5)
			{
				AI_Make_Get_Attention(pMe);
			}
			else
			{
				if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
					AI_SetDesiredAnim(pMe, AI_ANIM_IDLE2, FALSE);
				else
					AI_SetDesiredAnim(pMe, AI_ANIM_IDLE, FALSE);

				AI_GetDyn(pMe)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
			}
		}
	}
	else
	{
		if (dist <= AI_RUN2WALK_DISTANCE)
		{
			// ai is within walking distance of leader ?
			curAnim = AI_GetCurrentAnim(pMe);

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
		else
		{
			// make ai run towards leader
			func_80073FD8(pMe, turnang);
		}
	}

	// keep agitation up, now that we are fighting (only if ai we are attacking is alive)
	if (IsPlayerAlive())
		AI_Increase_Agitation(pMe, AI_AGITATION_FIGHTING, 300);
}
