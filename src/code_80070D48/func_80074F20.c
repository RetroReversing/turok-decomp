#include "decompdecomp_sync_a4202dcd1662b57b4a85.h"
#line 1 "func.c"
#line 1759 "reference.c"
void func_80074F20(CGameObjectInstance *pThis)
{
	CGameObjectInstance	*pPlayer;
	CVector3					vDestPos;


	if ( (AI_GetDyn(pThis)->m_dwStatusFlags & AI_ALREADY_DEAD) &&
		  (AI_GetDyn(pThis)->m_dwStatusFlags & AI_RESURRECTION)        )
	{
		pPlayer  = D_8010201C;
		vDestPos = AI_GetPos(pPlayer);

		// IMPORTANT !!!!!! - this distance must be within the animation rectangle
		if ( (AI_DistanceSquared(pThis, vDestPos) >= (D_801197E8*(0.95*SCALING_FACTOR)) * (D_801197E8*(0.95*SCALING_FACTOR))) &&
			  (!CGameObjectInstance__IsVisible(pThis))         )
		{
			// resurrect this ai
			CAIDynamic__SetHealth(AI_GetDyn(pThis),
										 AI_GetEA(pThis),
										 CGameObjectInstance__TypeFlag(pThis));

			pThis->m_cMelt = 0;

			AI_GetDyn(pThis)->m_Health				= AI_GetDyn(pThis)->m_Health * 85 / 100;
			if (AI_GetDyn(pThis)->m_Health<1) AI_GetDyn(pThis)->m_Health = 1;
			AI_GetDyn(pThis)->m_dwStatusFlags	&= ~AI_ALREADY_DEAD;
			AI_GetDyn(pThis)->m_dwStatusFlags	&= ~AI_WAITFOR_CYCLE;
			AI_GetDyn(pThis)->m_Agitation			= 0;
			AI_GetDyn(pThis)->m_PrevAgitation	= 0;
			AI_GetDyn(pThis)->m_dwStatusFlags	&= ~AI_WOUNDEDMORTALLY;
			AI_GetDyn(pThis)->m_dwStatusFlags2	&= ~AI_GENERATED_PICKUPS;

			// when ai dies again it can never come back
			AI_GetDyn(pThis)->m_dwStatusFlags	&= (~AI_RESURRECTION);
		}
	}
}

