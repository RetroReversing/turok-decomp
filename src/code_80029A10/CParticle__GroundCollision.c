#include "decompdecomp_sync_2524f0b2abd418a13e2b.h"
#line 11427 "reference.c"
// particle ground collision
//
void CParticle__GroundCollision(CParticle *pThis)
{
	// declare variables
	int						nGrd,
								nParticleType,
								nEventType,
								nSoundType;
	float						EventNumber;
	CROMParticleEffect	*pEffect;

	if (CGameRegion__IsCliff(pThis->ah.ih.m_pCurrentRegion))
		nGrd = CGameRegion__GetWallMaterial(pThis->ah.ih.m_pCurrentRegion);
	else
		nGrd = CGameRegion__GetGroundMaterial(pThis->ah.ih.m_pCurrentRegion);

	pEffect = pThis->m_pEffect;

	nParticleType = pEffect->m_pImpact->m_ImpactParticleType[nGrd];
	nEventType    = pEffect->m_pImpact->m_ImpactEventType   [nGrd];
	EventNumber   = pEffect->m_pImpact->m_ImpactEventNumber [nGrd];
	nSoundType    = pEffect->m_pImpact->m_ImpactSoundType   [nGrd];

	if (nParticleType != (WORD) -1)
		CParticle__SpawnGroundCollision(pThis, nParticleType);

	if (nEventType != (WORD) -1)
		AI_Event_Dispatcher(&pThis->ah.ih, pThis->m_pSource, nEventType, AI_SPECIES_ALL, pThis->m_CI.vGroundCollisionPos, EventNumber);

	if (nSoundType != (WORD) -1)
		CParticle__DoSoundEffect(pThis, nSoundType, FALSE, &pThis->m_CI.vGroundCollisionPos);

	// ?
	if (pThis->m_CI.GroundBehavior == INTERSECT_BEHAVIOR_STICK)
		CParticle__Delete(pThis);
}
