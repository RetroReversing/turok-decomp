#include "decompdecomp_sync_ac050356d2dfedb2076e.h"
#line 1 "func.c"
#line 9189 "reference.c"
void func_8002A3B0(CParticle *pThis)
{
	// declare variables
	int						nWall,
								nParticleType,
								nEventType,
								nSoundType;
	float						EventNumber;
	CROMParticleEffect	*pEffect;

	nWall		= CGameRegion__GetWallMaterial(pThis->ah.ih.m_pCurrentRegion);
	pEffect	= pThis->m_pEffect;

	nParticleType = pEffect->m_pImpact->m_ImpactParticleType[nWall];
	nEventType    = pEffect->m_pImpact->m_ImpactEventType   [nWall];
	EventNumber   = pEffect->m_pImpact->m_ImpactEventNumber [nWall];
	nSoundType    = pEffect->m_pImpact->m_ImpactSoundType   [nWall];

	if (nParticleType != (WORD) -1)
		CParticle__SpawnCeilingCollision(pThis, nParticleType);

	if (nEventType != (WORD) -1)
		AI_Event_Dispatcher(&pThis->ah.ih, pThis->m_pSource, nEventType, AI_SPECIES_ALL, pThis->m_CI.vGroundCollisionPos, EventNumber);

	if (nSoundType != (WORD) -1)
		CParticle__DoSoundEffect(pThis, nSoundType, FALSE, &pThis->m_CI.vGroundCollisionPos);

	// ?
	if (pThis->m_CI.GroundBehavior == INTERSECT_BEHAVIOR_STICK)
		CParticle__Delete(pThis);
}

