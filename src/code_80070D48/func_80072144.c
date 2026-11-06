#include "decompdecomp_sync_f6d27b51dd286bcc4c62.h"
#line 1 "func.c"
typedef struct {int values[1];} OneWord;
extern const int D_800BE548,D_800BE54C;
#line 9406 "reference.c"
void func_80072144(CGameObjectInstance *pAI, float ang)
{
	int						picked;
	OneWord movetype = *(const OneWord *)&D_800BE548;
	OneWord moveweight = *(const OneWord *)&D_800BE54C;


	AI_GetDyn(pAI)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
	picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 1, movetype.values, moveweight.values, NULL);
	AI_SetDesiredAnimByIndex(pAI, picked, FALSE);

	// make ai turn
	if (ang<=ANGLE_DTOR(-AI_MAX_TELEPORTTURN)) ang=ANGLE_DTOR(-AI_MAX_TELEPORTTURN);
	if (ang>=ANGLE_DTOR(+AI_MAX_TELEPORTTURN)) ang=ANGLE_DTOR(+AI_MAX_TELEPORTTURN);
	AI_NudgeRotY(pAI, D_800B6B00*ang/AI_TURN_SMOOTHNESS);
}

