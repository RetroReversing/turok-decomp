#include "decompdecomp_sync_199c42b9e1e1101aaf47.h"
#line 1 "func.c"
#line 785 "reference.c"
void func_8002A2A4(CParticle *pThis, int nType)
{
	CParticleSystem	*pSystem;
	CQuatern				qRot;
	CVector3				vVelocity;

	ASSERT(pThis->m_CI.nGroundCollisionType == GROUNDCOLLISION_CEILING);

	pSystem = ((CParticleSystem*)D_80102228);
	ASSERT(pSystem);

	if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_RETAINVELOCITY)
		vVelocity = pThis->m_CI.vCollisionVelocity;
	else
		vVelocity = pThis->ah.m_vVelocity;

	qRot = CVector3__GetDirectionRotation(&vVelocity);

	CParticleSystem__CreateParticle(pSystem, pThis->m_pSource, nType,
											  vVelocity,
											  qRot,
											  pThis->m_CI.vGroundCollisionPos, pThis->m_CI.pGroundCollisionRegion, PARTICLE_CEILING, TRUE);
}

