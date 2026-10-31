#include "source_func_80061CC4.h"
#line 1 "func.c"
#line 1 "reference.c"
void func_80061CC4 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, int hits, float rad, int nType)
{
	INT32	Impact = FALSE ;
	CGameObjectInstance	*pAttacker ;
	CMantis					*pMantis = NULL ;

	// Setup attacker
	switch (pOrigin->m_Type)
	{
		case I_PARTICLE:
			break;

		case I_ANIMATED:
			pAttacker = (CGameObjectInstance*) pOrigin ;
			break;

		default:
			pAttacker = NULL ;
	}

	// Can't hurt self - added by S.B. 11/30/96
	if (&pAI->ah.ih == pOrigin)
		return ;

	// Is this the mantis?
	if ((nType == DAMAGE_PARTICLE) && (CGameObjectInstance__TypeFlag(pAttacker) == AI_OBJECT_CHARACTER_MANTIS_BOSS))
		pMantis = (CMantis *)pAttacker->m_pBoss ;

	// Only hurt player once a frame if this is a mantis steamy slime
	if ((pMantis) && ((pMantis->m_AcidHurtTurok) || (D_800B6AF8 & 3)))
		return ;

	TRACE2("M Event Damage %d - AI (Any) Radius = %f\r\n", hits, rad);

	// did ai get hit
	rad *= SCALING_FACTOR;

	// did player get hit or was it another ai ?
	if ( pAI == CEngineApp__GetPlayer(GetApp()) )
	{
		// hit player (do fudge on distance /2 - to get ai hitting turok without getting too close)
		if ( (sqrt(func_8005F34C(pAI, vPos))/2) <= ( rad + AI_GetEA(pAI)->m_CollisionRadius) )
		{
			func_80060A54(pAI, hits);
			func_8005F228(pAI, pOrigin);
			Impact = TRUE ;
		}
	}
	else
	{
		// hit another ai (do normal proper test between two ai's)
		if ( (sqrt(func_8005F34C(pAI, vPos))/2) <= ( rad + AI_GetEA(pAI)->m_CollisionRadius) )
		{
			if (		(pAI->ah.ih.m_Type == I_ANIMATED)
					&&	(pOrigin->m_nObjType != pAI->ah.ih.m_nObjType) )
			{
				func_80060A54(pAI, hits);
				func_8005F228(pAI, pOrigin);
				Impact = TRUE ;
			}
		}
	}

	// any sfx on this impact ?
	if (Impact)
	{
		switch(nType)
		{
			case DAMAGE_NORMAL:
				// Boss impact effect?
				if ((pOrigin->m_Type == I_ANIMATED) && (((CGameObjectInstance *)pOrigin)->m_pBoss))
				{
					Impact = ((CGameObjectInstance *)pOrigin)->m_pBoss->m_ModeFlags ;
					if (Impact & (BF_KICK_IMPACT_MODE | BF_PUNCH_IMPACT_MODE))
						func_8005EED0(&pAI->ah.ih, 466, 1, RANDOMIZE_PITCH);
				}
				break;

			case DAMAGE_BLADE:
				func_8005EED0(&pAI->ah.ih, SOUND_TOMAHAWK_IMPACT_FLESH, 1, RANDOMIZE_PITCH);
				break;

			case DAMAGE_KICK:
				func_8005EED0(&pAI->ah.ih, SOUND_GENERIC_81, 1, RANDOMIZE_PITCH);
				break;

			case DAMAGE_PARTICLE:
				if (pMantis)
				{
					pMantis->m_AcidHurtTurok = TRUE ;
					if (!(D_800B6AF8 & 3))
						func_8005EED0(&pAI->ah.ih, SOUND_GENERIC_95, 1, RANDOMIZE_PITCH);
				}
				break;
		}
	}
}

