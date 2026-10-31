#include "common_local_source_5348.h"

#line 1046 "reference.c"
void func_800784B0(CGameObjectInstance *pMe)
{
	CGameRegion		*pRegion;
	float				ghgt;

	int	picked,
			pickedType=-1;

	int	sinktypes[]={AI_ANIM_DEATH_SWIM_SINK};
	int	sinkweights[]={1};

	int	posetypes[]={AI_ANIM_DEATH_SWIM_SINK_POSE};
	int	poseweights[]={1};

#if DEBUG_STAND_AI
	rmonPrintf("AI_Standard_Sink\r\n") ;
#endif

	pRegion = pMe->ah.ih.m_pCurrentRegion;
	if (!pRegion)
		return;

	ghgt = func_80019D3C(pRegion, AI_GetPos(pMe).x, AI_GetPos(pMe).z);

	if ( (AI_GetPos(pMe).y - ghgt) < (3*SCALING_FACTOR) )
	{
		// ai is on ground - assume ground sink pose anim
		picked = func_8001C348(pMe, 1, posetypes, poseweights, &pickedType);
		AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
		func_8005FCA0(pMe, picked, TRUE);
	}
	else
	{
		// ai is falling - doing falling sink animation
		picked = func_8001C348(pMe, 1, sinktypes, sinkweights, &pickedType);
		AI_GetDyn(pMe)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
		func_8005FCA0(pMe, picked, TRUE);
	}
}
