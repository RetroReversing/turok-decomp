#include "decompdecomp_sync_a65e9f63c83d45148758.h"
#line 1 "func.c"
#line 720 "reference.c"
void CParticle__SpawnWallCollision(CParticle *pThis, int nType)
{
	CParticleSystem	*pSystem;
	CQuatern				qRot;
	CVector3				vVelocity;
	CROMRegionSet		*pRegionSet;

	ASSERT(pThis->m_CI.pWallCollisionRegion);

	pSystem = ((CParticleSystem*)D_80102228);
	ASSERT(pSystem);

	if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_RETAINVELOCITY)
		vVelocity = pThis->m_CI.vCollisionVelocity;
	else
		vVelocity = pThis->ah.m_vVelocity;

	qRot = CVector3__GetDirectionRotation(&vVelocity);

	// Start of FUCKED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// special fudge to stop blood splats on walls while in caves
	// if the cave music is on for this region don't allow blood splats on walls
	// technically speaking this should check the pEffect of the new nType but Thomas assures me
	// the particle hitting the wall will always be a blood type anyway so we don't need to bother.
	if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_BLOODEFFECT)
	{
		pRegionSet = CScene__GetRegionAttributes(((void*)D_800FA3C8), pThis->ah.ih.m_pCurrentRegion);
		if (pRegionSet)
		{
			if (pRegionSet->m_AmbientSounds == REG_AMBIENTCAVES)
				return;
		}
	}
	// End of FUCKED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	CParticleSystem__CreateParticle(pSystem, pThis->m_pSource, nType,
											  vVelocity,
											  qRot,
											  pThis->m_CI.vWallCollisionPos, pThis->m_CI.pWallCollisionRegion, pThis->m_CI.nWallCollisionEdge, TRUE);
}

