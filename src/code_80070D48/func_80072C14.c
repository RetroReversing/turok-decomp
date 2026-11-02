#include "decompdecomp_sync_40370375a016143b10e5.h"
#line 1 "func.c"
#line 9120 "reference.c"
void func_80072C14(CGameObjectInstance *pAI, float ang)
{
	int						picked;
	SwimArray swimtype = D_800BE418;
	SwimArray swimweight = D_800BE41C;


	// swimming
	picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 1, swimtype.values, swimweight.values, NULL);
	AI_SetDesiredAnimByIndex(pAI, picked, FALSE);
	AI_GetDyn(pAI)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);

	// make ai turn
	if (ang<=ANGLE_DTOR(-AI_MAX_SWIMTURN)) ang=ANGLE_DTOR(-AI_MAX_SWIMTURN);
	if (ang>=ANGLE_DTOR(+AI_MAX_SWIMTURN)) ang=ANGLE_DTOR(+AI_MAX_SWIMTURN);
	AI_NudgeRotY(pAI, frame_increment*ang/(AI_SWIMTURN_SMOOTHNESS/2));
}

