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
	avoidrad = func_8005EDD8(pMe);

	// calculate angle to face to point at the leader
	vLeaderPos = AI_GetPos(pLeader);

	AI_GetDyn(pMe)->m_AvoidanceAngle =
	turnang = func_800747C0(pMe, vLeaderPos, pLeader, avoidrad);

	// how close is this ai to the leader ?
	dist = func_8005F34C(pMe, vLeaderPos);

	// ai should follow the leader
	if (dist <= AI_GetEA(pMe)->m_AttackRadius)
	{
		if (func_8007223C(pMe, turnang))
		{
			// ai has reached & is facing the leader
			if (RANDOM(100)<5)
			{
				func_80071CF0(pMe);
			}
			else
			{
				if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
					func_8005FCF4(pMe, AI_ANIM_IDLE2, FALSE);
				else
					func_8005FCF4(pMe, AI_ANIM_IDLE, FALSE);

				AI_GetDyn(pMe)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
			}
		}
	}
	else
	{
		if (dist <= AI_RUN2WALK_DISTANCE)
		{
			// ai is within walking distance of leader ?
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
		else
		{
			// make ai run towards leader
			func_80073FD8(pMe, turnang);
		}
	}

	// keep agitation up, now that we are fighting (only if ai we are attacking is alive)
	if (IsPlayerAlive())
		func_8005F2B8(pMe, AI_AGITATION_FIGHTING, 300);
}
