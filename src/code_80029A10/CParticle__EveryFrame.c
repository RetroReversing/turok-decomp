#include "decompdecomp_sync_8507a72c31a8c16fd6f7.h"
#line 11535 "reference.c"
// do every frame particle
//
void CParticle__EveryFrame(CParticle *pThis)
{
	// declare variables
	int						nParticleType,
								nEventType,
								nSoundType,
								nImpactType;
	float						EventNumber;
	CROMParticleEffect	*pEffect;

	pEffect = pThis->m_pEffect;

	// what is particle in ?
	if (CParticle__IsInWater(pThis))
		nImpactType = PARTICLE_IMPACTS_EVERYFRAMEWATER;
	else
		nImpactType = PARTICLE_IMPACTS_EVERYFRAME;

	nParticleType = pEffect->m_pImpact->m_ImpactParticleType[nImpactType];
	nEventType    = pEffect->m_pImpact->m_ImpactEventType   [nImpactType];
	EventNumber   = pEffect->m_pImpact->m_ImpactEventNumber [nImpactType];
	nSoundType    = pEffect->m_pImpact->m_ImpactSoundType   [nImpactType];

	if (nParticleType != (WORD) -1)
		CParticle__Spawn(pThis, nParticleType, TRUE);

	if (nEventType != (WORD) -1)
		AI_Event_Dispatcher(&pThis->ah.ih, pThis->m_pSource, nEventType, AI_SPECIES_ALL, pThis->ah.ih.m_vPos, EventNumber);

	if (nSoundType != (WORD) -1)
		CParticle__DoSoundEffect(pThis, nSoundType, TRUE, &pThis->ah.ih.m_vPos);
}
