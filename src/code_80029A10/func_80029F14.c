#include "common_local_source_4038.h"

#line 1 "reference.c"
void func_80029F14(CParticle *pThis)
{
	// declare variables
	int						nMaterial,
								nParticleType,
								nEventType,
								nSoundType;
	float						EventNumber;
	CROMParticleEffect	*pEffect;
	CInstanceHdr			*pIns;
	BOOL						Blood = TRUE;

	pIns = pThis->m_CI.pInstanceCollision;

	// get type of instance struck
	nMaterial = func_80071B18(pIns);
	pEffect = pThis->m_pEffect;

	if (func_8002814C(pThis))
	{
		switch(nMaterial)
		{
			case REGMAT_FLESH:
			case REGMAT_ALIENFLESH:
				nMaterial=REGMAT_FLESHWATER;
				break;

			default:;
		}
	}

	nParticleType = pEffect->m_pImpact->m_ImpactParticleType[nMaterial];
	nEventType    = pEffect->m_pImpact->m_ImpactEventType   [nMaterial];
	EventNumber   = pEffect->m_pImpact->m_ImpactEventNumber [nMaterial];
	nSoundType    = pEffect->m_pImpact->m_ImpactSoundType   [nMaterial];

	if (func_80018B08(pIns))
		func_8008DCA0(pIns, pThis);

	// get pointer to instance we are hitting (must be animated instance)
	switch (pIns->m_Type)
	{
		case I_ANIMATED:
			// Execute special-case boss hit function?
			if ((((CGameObjectInstance *)pIns)->m_pBoss) &&
				(((CGameObjectInstance *)pIns)->m_pBoss->m_pHitByParticleFunction))
				((CGameObjectInstance *)pIns)->m_pBoss->m_pHitByParticleFunction(pIns,
				((CGameObjectInstance *)pIns)->m_pBoss, pThis) ;

			// if the player
			if (		((CGameObjectInstance *)pIns == CEngineApp__GetPlayer(GetApp()))
					&&	(nParticleType == PARTICLE_TYPE_BLOOD)
					&&	(!(func_80039B98(&GetApp()->m_Camera))) )
			{
				nParticleType = PARTICLE_TYPE_PLAYER_IMPACT_BLOOD;
			}

			// move impact position to that of the instance it hit ?
			if (pEffect->m_dwFlags & PARTICLE_BEHAVIOR_CENTERIMPACTONINSTANCE)
			{
				pThis->ah.ih.m_vPos = ((CGameObjectInstance *)pIns)->ah.ih.m_vPos;
				pThis->ah.ih.m_pCurrentRegion = ((CGameObjectInstance *)pIns)->ah.ih.m_pCurrentRegion;
			}

			// can this ai generate blood ?
			if (AI_GetEA((CGameObjectInstance *)pIns)->m_dwTypeFlags2 & AI_TYPE2_NOBLOOD)
				Blood = FALSE;

			if (AI_GetDyn((CGameObjectInstance *)pIns)->m_Invincible)
				Blood = FALSE;

			break;
	}

	if (nParticleType != (WORD) -1)
		CParticle__Spawn(pThis, nParticleType, Blood);

	if (nEventType != (WORD) -1)
	{
		//AI_Event_Dispatcher(IsSingleEvent(nEventType) ? pIns : &pThis->ah.ih, pThis->m_pSource,
		func_80070DA8(func_80070D48(nEventType) ? pIns : &pThis->ah.ih, &pThis->ah.ih,
								  nEventType, AI_SPECIES_ALL, pThis->m_CI.vInstanceCollisionPos, EventNumber);
	}

	if (nSoundType != (WORD) -1)
		CParticle__DoSoundEffect(pThis, nSoundType, FALSE, &pThis->m_CI.vInstanceCollisionPos);

	// ?
	if ((pThis->m_CI.InstanceBehavior == INTERSECT_BEHAVIOR_STICK) || func_8007636C(EventNumber))
		CParticleSystem__DeallocateParticle(&GetApp()->m_Scene.m_ParticleSystem, pThis);
}
