#include "decompdecomp_sync_5a560949d48bdd20adce.h"
#line 1 "func.c"
#line 11395 "reference.c"
void func_8002A800(CParticle *pThis)
{
	// declare variables
	int						nParticleType,
								nEventType,
								nSoundType;
	float						EventNumber;
	CROMParticleEffect	*pEffect;


	pEffect = pThis->m_pEffect;

	nParticleType = pEffect->m_pImpact->m_ImpactParticleType[PARTICLE_IMPACTS_WATERSURFACE];
	nEventType    = pEffect->m_pImpact->m_ImpactEventType   [PARTICLE_IMPACTS_WATERSURFACE];
	EventNumber   = pEffect->m_pImpact->m_ImpactEventNumber [PARTICLE_IMPACTS_WATERSURFACE];
	nSoundType    = pEffect->m_pImpact->m_ImpactSoundType   [PARTICLE_IMPACTS_WATERSURFACE];

	if (nParticleType != (WORD) -1)
		CParticle__SpawnWaterSurfaceCollision(pThis, nParticleType);

	if (nEventType != (WORD) -1)
		AI_Event_Dispatcher(&pThis->ah.ih, pThis->m_pSource, nEventType, AI_SPECIES_ALL, pThis->m_CI.vWaterCollisionPos, EventNumber);

	if (nSoundType != (WORD) -1)
		CParticle__DoSoundEffect(pThis, nSoundType, FALSE, &pThis->m_CI.vWaterCollisionPos);

	if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_DIEONWATERSURFACE)
		CParticle__Delete(pThis);
}

