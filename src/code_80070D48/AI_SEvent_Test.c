#include "decompdecomp_sync_f258959cde4caf2d8d18.h"
#line 1 "func.c"
#line 3923 "reference.c"
void AI_SEvent_Test (CInstanceHdr *pThis, CVector3 vPos, float Value )
{
	CEngineApp				*pApp;
	CVector3					vParticlePos;
	CGameRegion				*pParticleRegion;
	CGameObjectInstance	*pAnim;


	switch (pThis->m_Type)
	{
		case I_ANIMATED:
			pAnim = (CGameObjectInstance*) pThis;
			TRACE1("S Event 'Test' - Particles (Any) Value = %f\r\n", Value);

			// get pointer to engine app
			pApp = GetApp();
			if ( pApp == NULL ) return;

			// get particle position
			CInstanceHdr__GetNearPositionAndRegion(&pAnim->ah.ih, vPos, &vParticlePos, &pParticleRegion, INTERSECT_BEHAVIOR_STICK, INTERSECT_BEHAVIOR_STICK);

			CParticleSystem__CreateParticle(D_80102228, pThis, PARTICLE_TYPE_TEST,
													  pAnim->ah.m_vVelocity,
													  CGameObjectInstance__GetAimRotation(pAnim),
													  vParticlePos, pParticleRegion, PARTICLE_NOEDGE, TRUE);
			break;
	}
}

