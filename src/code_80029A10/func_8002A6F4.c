#include "decompdecomp_sync_1ede0eb5a8fd7b229547.h"
#line 1 "func.c"
#line 809 "reference.c"
void func_8002A6F4(CParticle *pThis, int nType)
{
	CParticleSystem	*pSystem;
	CQuatern				qRot;
	CVector3				vVelocity;

	ASSERT(pThis->m_CI.pWaterCollisionRegion);

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
											  pThis->m_CI.vWaterCollisionPos, pThis->m_CI.pWaterCollisionRegion, PARTICLE_UP, TRUE);
}

