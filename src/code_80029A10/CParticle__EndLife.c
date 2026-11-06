#include "decompdecomp_sync_51594220493c8c54d998.h"
#line 1 "func.c"
#line 11499 "reference.c"
void CParticle__EndLife(CParticle *pThis)
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
		nImpactType = PARTICLE_IMPACTS_ENDLIFEWATER;
	else
		nImpactType = PARTICLE_IMPACTS_ENDLIFE;

	nParticleType = pEffect->m_pImpact->m_ImpactParticleType[nImpactType];
	nEventType    = pEffect->m_pImpact->m_ImpactEventType   [nImpactType];
	EventNumber   = pEffect->m_pImpact->m_ImpactEventNumber [nImpactType];
	nSoundType    = pEffect->m_pImpact->m_ImpactSoundType   [nImpactType];

	if (nParticleType != (WORD) -1)
		CParticle__Spawn(pThis, nParticleType, TRUE);

	if (nEventType != (WORD) -1)
		AI_Event_Dispatcher(&pThis->ah.ih, pThis->m_pSource, nEventType, AI_SPECIES_ALL, pThis->ah.ih.m_vPos, EventNumber);

	if (nSoundType != (WORD) -1)
		CParticle__DoSoundEffect(pThis, nSoundType, FALSE, &pThis->ah.ih.m_vPos);
}

