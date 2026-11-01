#include "decompdecomp_sync_602eae6ba6ad646fbf78.h"
#line 1 "func.c"
#line 1033 "reference.c"
void func_800281F0(CParticleSystem *pThis, CParticle *pParticle)
{
/*
	CAnimInstanceHdr	*pPlayer;
	CVector3					vDelta;
	CParticle				*pCurrent, *pNext;

	ASSERT(pParticle);

	pPlayer = D_8010201C;
	CVector3__Subtract(&vDelta, &pParticle->ah.ih.m_vPos, &pPlayer->ih.m_vPos);
	pParticle->m_DistanceSquared = CVector3__MagnitudeSquared(&vDelta);

	pCurrent = NULL;
	pNext = pThis->m_pDrawHead;
	while (pNext)
	{
		if (pNext->m_DistanceSquared < pParticle->m_DistanceSquared)
			break;

		pCurrent = pNext;
		pNext = pNext->m_pDrawNext;
	}

	if (pCurrent)
	{
		// add after pCurrent
		pParticle->m_pDrawNext = pCurrent->m_pDrawNext;
		if (pCurrent->m_pDrawNext)
			pCurrent->m_pDrawNext->m_pDrawLast = pParticle;
		pParticle->m_pDrawLast = pCurrent;
		pCurrent->m_pDrawNext = pParticle;
	}
	else
	{
		// add to head of list
		if (pThis->m_pDrawHead)
			pThis->m_pDrawHead->m_pDrawLast = pParticle;
		pParticle->m_pDrawNext = pThis->m_pDrawHead;
		pThis->m_pDrawHead = pParticle;
		pParticle->m_pDrawLast = NULL;
	}
*/

	CAnimInstanceHdr	*pPlayer;
	CVector3					vDelta;
	CParticle				*pMatch,
								*pCurrent, *pNext;

	ASSERT(pParticle);

	pPlayer = D_8010201C;
	if (pPlayer)
		CVector3__Subtract(&vDelta, &pParticle->ah.ih.m_vPos, &pPlayer->ih.m_vPos);
	else
		vDelta.x = vDelta.y = vDelta.z = 0;

	pParticle->m_DistanceSquared = CVector3__MagnitudeSquared(&vDelta);

	// find matching particle type in draw list
	pMatch = pThis->m_pDrawHead;
	while (pMatch)
	{
//		if (pMatch->ah.ih.m_nObjType == pParticle->ah.ih.m_nObjType)
		if (pMatch->m_pEffect == pParticle->m_pEffect)
			break;

		pMatch = pMatch->m_pDrawNext;
	}

	if (pMatch)
	{
		// add within matching particles in sorted order

		pCurrent = NULL;
		pNext = pMatch;
		while (pNext)
		{
			//if (		(pNext->ah.ih.m_nObjType != pParticle->ah.ih.m_nObjType)
			if (		(pNext->m_pEffect != pParticle->m_pEffect)
					|| (pNext->m_DistanceSquared < pParticle->m_DistanceSquared) )
			{
				break;
			}

			pCurrent = pNext;
			pNext = pNext->m_pDrawNext;
		}

		if (pCurrent)
		{
			// add after pCurrent
			pParticle->m_pDrawNext = pCurrent->m_pDrawNext;
			if (pCurrent->m_pDrawNext)
				pCurrent->m_pDrawNext->m_pDrawLast = pParticle;
			pParticle->m_pDrawLast = pCurrent;
			pCurrent->m_pDrawNext = pParticle;

			// update tail of list
			if (pThis->m_pDrawTail == pCurrent)
				pThis->m_pDrawTail = pParticle;
		}
		else
		{
			// add before pMatch
			pParticle->m_pDrawNext = pMatch;
			pParticle->m_pDrawLast = pMatch->m_pDrawLast;
			if (pMatch->m_pDrawLast)
				pMatch->m_pDrawLast->m_pDrawNext = pParticle;
			pMatch->m_pDrawLast = pParticle;

			// update head of list
			if (pThis->m_pDrawHead == pMatch)
				pThis->m_pDrawHead = pParticle;
		}
	}
	else
	{
		if (pParticle->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_DRAWONBOTTOM)
		{
			// add to head of list
			if (pThis->m_pDrawHead)
				pThis->m_pDrawHead->m_pDrawLast = pParticle;
			pParticle->m_pDrawNext = pThis->m_pDrawHead;
			pThis->m_pDrawHead = pParticle;
			pParticle->m_pDrawLast = NULL;

			// update tail of list
			if (!pThis->m_pDrawTail)
				pThis->m_pDrawTail = pParticle;
		}
		else
		{
			// add to tail of list
			if (pThis->m_pDrawTail)
				pThis->m_pDrawTail->m_pDrawNext = pParticle;
			pParticle->m_pDrawLast = pThis->m_pDrawTail;
			pThis->m_pDrawTail = pParticle;
			pParticle->m_pDrawNext = NULL;

			// update head of list
			if (!pThis->m_pDrawHead)
				pThis->m_pDrawHead = pParticle;
		}
	}
}

