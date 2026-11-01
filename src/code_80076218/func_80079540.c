#include "decompdecomp_sync_6a814f64cb690972c9b5.h"
#line 1 "func.c"
#line 28 "reference.c"
void func_80079540(CGameObjectInstance *pMe)
{
	// declare variables
	int		picked,
				pickedType;

	AnimArray types1 = D_800BE5EC;

	AnimArray types2 = D_800BE608;

	AnimArray weights = D_800BE624;

                  
                                         
      

	if (AI_GetEA(pMe)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
		picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 7, types2.values, weights.values, &pickedType);
	else
		picked = CGameObjectInstance__GetRandomAnimIndex(pMe, 7, types1.values, weights.values, &pickedType);

	AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
	AI_SetDesiredAnimByIndex(pMe, picked, FALSE);
}

