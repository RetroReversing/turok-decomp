#include "decompdecomp_sync_a4202dcd1662b57b4a85.h"
#line 1 "func.c"
#line 1718 "reference.c"
void AI_FeignDeath(CGameObjectInstance *pThis)
{
	CGameObjectInstance	*pPlayer;
	CVector3					vDestPos;


	if ( (AI_GetDyn(pThis)->m_dwStatusFlags & AI_ALREADY_DEAD) &&
		  (AI_GetDyn(pThis)->m_dwStatusFlags & AI_FEIGNDEATH)        )
	{
		pPlayer  = D_8010201C;
		vDestPos = AI_GetPos(pPlayer);

		if (AI_DistanceSquared(pThis, vDestPos) <= AI_GetEA(pThis)->m_AttackRadius)
		{
			// resurrect this ai
			CAIDynamic__SetHealth(AI_GetDyn(pThis),
										 AI_GetEA(pThis),
										 CGameObjectInstance__TypeFlag(pThis));

			AI_GetDyn(pThis)->m_Health				= AI_GetDyn(pThis)->m_Health * 35 / 100;
			if (AI_GetDyn(pThis)->m_Health<1) AI_GetDyn(pThis)->m_Health = 1;
			AI_GetDyn(pThis)->m_dwStatusFlags	&= ~AI_ALREADY_DEAD;
			AI_GetDyn(pThis)->m_dwStatusFlags	&= ~AI_WAITFOR_CYCLE;
			AI_GetDyn(pThis)->m_Agitation			= 0;
			AI_GetDyn(pThis)->m_PrevAgitation	= 0;
			AI_GetDyn(pThis)->m_dwStatusFlags	&= ~AI_WOUNDEDMORTALLY;
			AI_GetDyn(pThis)->m_dwStatusFlags2	&= ~AI_GENERATED_PICKUPS;

			pThis->m_cMelt = 0;

			// ai can only feign death once
			AI_GetDyn(pThis)->m_dwStatusFlags	&= (~AI_FEIGNDEATH);
		}
	}
}

