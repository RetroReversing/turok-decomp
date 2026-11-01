#include "decompdecomp_sync_167423be0e0131092af9.h"
#line 1 "func.c"
#line 11356 "reference.c"
void func_8002AA38(CParticle *pThis)
{
	// declare variables
	int						nWall,
								nParticleType,
								nEventType,
								nSoundType;
	float						EventNumber;
	CROMParticleEffect	*pEffect;

	// don't do anything on second wall hit
	if (!(		(pThis->m_dwFlags & PARTICLE_HASHITWALL)
				&& (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_BOUNCEONLYONCE) ))
	{
		nWall   = CGameRegion__GetWallMaterial(pThis->ah.ih.m_pCurrentRegion);
		pEffect = pThis->m_pEffect;

		nParticleType = pEffect->m_pImpact->m_ImpactParticleType[nWall];
		nEventType    = pEffect->m_pImpact->m_ImpactEventType   [nWall];
		EventNumber   = pEffect->m_pImpact->m_ImpactEventNumber [nWall];
		nSoundType    = pEffect->m_pImpact->m_ImpactSoundType   [nWall];


		if (nParticleType != (WORD) -1)
			CParticle__SpawnWallCollision(pThis, nParticleType);

		if (nEventType != (WORD) -1)
			AI_Event_Dispatcher(&pThis->ah.ih, pThis->m_pSource, nEventType, AI_SPECIES_ALL, pThis->m_CI.vWallCollisionPos, EventNumber);

		if (nSoundType != (WORD) -1)
			CParticle__DoSoundEffect(pThis, nSoundType, FALSE, &pThis->m_CI.vWallCollisionPos);
	}

	// ?
	if (pThis->m_CI.WallBehavior == INTERSECT_BEHAVIOR_STICK)
		CParticle__Delete(pThis);
}

