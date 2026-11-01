#include "decompdecomp_sync_684a7490616cc48fbe28.h"
#line 1 "func.c"
#line 13 "reference.c"
void AI_SEvent_DamageNudge_Target(CInstanceHdr *pThis, CInstanceHdr *pOrigin, CVector3 vPos, float damage)
{
	CGameObjectInstance	*pAnim,
								*pAttacker;
	CInstanceHdr			*pSource;
	CParticle				*pParticle ;

	switch (pOrigin->m_Type)
	{
		case I_PARTICLE:
			pParticle = (CParticle *)pOrigin ;
			pSource = pParticle->m_pSource;
			if (pSource->m_Type == I_ANIMATED)
				pAttacker = (CGameObjectInstance*) pSource;
			else
				pAttacker = NULL;
			break;

		case I_ANIMATED:
			pAttacker = (CGameObjectInstance*) pOrigin;
			break;

		default:
			pAttacker = NULL;
			break;
	}

	switch (pThis->m_Type)
	{
		case I_ANIMATED:
			TRACE0("S Event Damage & Nudge Target\r\n");
			pAnim = (CGameObjectInstance*) pThis;

			if (		(pAttacker == NULL)
					||	(		(pAnim->ah.ih.m_Type == I_ANIMATED)
							&&	(pAttacker->ah.ih.m_nObjType != pAnim->ah.ih.m_nObjType) ) )
			{
				AI_DoHit(pAnim, (int) damage);
			}
			AI_SetAttacker(pAnim, pOrigin);
			AI_MEvent_WeaponImpact(pAnim, pOrigin, vPos, 15);
			break;
	}
}

