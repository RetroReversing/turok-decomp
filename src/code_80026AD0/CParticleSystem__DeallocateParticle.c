#include "decompdecomp_sync_602eae6ba6ad646fbf78.h"
#line 1 "func.c"
#line 1180 "reference.c"
void CParticleSystem__DeallocateParticle(CParticleSystem *pThis, CParticle *pParticle)
{
	ASSERT(pParticle);

	ASSERT(pParticle->m_dwFlags & PARTICLE_ALLOCATED);
	if (!(pParticle->m_dwFlags & PARTICLE_ALLOCATED))
		return;

	// Leave permanent particles there
	if (pParticle->m_dwFlags & PARTICLE_PERMANENT)
		return ;

	// Stop creating swooshes on particle if there are any
	if (pParticle->m_ActiveSwooshes)
	{
		// Add the last one (works with impacts)
		CParticle__CalculateOrientationMatrix(pParticle, NULL, NULL);
		CFxSystem__CheckForAddingParticleSwooshEdge(((void*)D_80112E10), pParticle, &CParticle__GetOrientationMatrix(pParticle));

		// And now stop all future impacts
		CFxSystem__StopSwooshesOnParticle(((void*)D_80112E10), pParticle);
	}

	// was this particle glaring ?
	if (pParticle == D_8011A0D0)
		D_8011A0D0 = NULL;

	pParticle->m_dwFlags &= ~PARTICLE_ALLOCATED;

	// remove from active list
	if (pParticle->m_pLast)
		pParticle->m_pLast->m_pNext = pParticle->m_pNext;
	if (pParticle->m_pNext)
		pParticle->m_pNext->m_pLast = pParticle->m_pLast;

	// update head of active list
	if (pThis->m_pActiveHead == pParticle)
		pThis->m_pActiveHead = pParticle->m_pNext;

	// update tail of active list
	if (pThis->m_pActiveTail == pParticle)
		pThis->m_pActiveTail = pParticle->m_pLast;

	// add to free list
	pParticle->m_pNext = pThis->m_pFreeHead;
	pThis->m_pFreeHead = pParticle;

	// remove from draw list
	if (pParticle->m_pDrawLast)
		pParticle->m_pDrawLast->m_pDrawNext = pParticle->m_pDrawNext;
	if (pParticle->m_pDrawNext)
		pParticle->m_pDrawNext->m_pDrawLast = pParticle->m_pDrawLast;

	// update head of draw list
	if (pThis->m_pDrawHead == pParticle)
		pThis->m_pDrawHead = pParticle->m_pDrawNext;

	// update tail of draw list
	if (pThis->m_pDrawTail == pParticle)
		pThis->m_pDrawTail = pParticle->m_pDrawLast;

                
                                                                    
      
}

