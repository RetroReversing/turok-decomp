#include "source_func_80060464.h"
#line 1 "func.c"
#line 1 "reference.c"
void AI_AimParticleAtPlayer(CInstanceHdr *pThis, int nType, CVector3 vPos, FLOAT MaxYRot)
{
	CEngineApp				*pApp;
	CGameObjectInstance	*pPlayer;
	float						dot, theta;
	CVector3					vParticlePos,
								vPlayerPos,
								vDelta, vZ, vZi, vAxis,
								vVelocity;
	CQuatern					qAim, qRot, qFinal;
	CMtxF						mfRot;
	CGameRegion				*pParticleRegion;
	CGameObjectInstance	*pAnim;
	BOOL						Blood = TRUE;

	if (pThis->m_Type == I_ANIMATED)
	{
		pAnim = (CGameObjectInstance*) pThis;

		if (AI_GetEA(pAnim)->m_dwTypeFlags2 & AI_TYPE2_NOBLOOD)
			Blood = FALSE;

		qRot = CGameObjectInstance__GetAimRotation(pAnim);
		CQuatern__ToMatrix(&qRot, mfRot);
		vZi.x = 0;
		vZi.y = 0;
		vZi.z = 1;
		CMtxF__VectorMult(mfRot, &vZi, &vZ);

	}
	else
	{
		vZ.x = 0;
		vZ.y = 0;
		vZ.z = 1;
	}

	pApp = GetApp();
	if (pThis->m_Type == I_ANIMATED)
	{
		pPlayer = ((CGameObjectInstance*)pThis)->m_pAttackerCGameObjectInstance;
		if (!pPlayer)
			pPlayer = CEngineApp__GetPlayer(pApp);
	}
	else
	{
		pPlayer = CEngineApp__GetPlayer(pApp);
	}

	// get particle position
	CInstanceHdr__GetNearPositionAndRegion(pThis, vPos, &vParticlePos, &pParticleRegion, INTERSECT_BEHAVIOR_STICK, INTERSECT_BEHAVIOR_STICK);

	// find aiming rotation
	vPlayerPos = AI_GetPos(pPlayer);
	vPlayerPos.y += (TUROK_HEIGHT/2)*SCALING_FACTOR;

	CVector3__Subtract(&vDelta, &vPlayerPos, &vParticlePos);
	CVector3__Normalize(&vDelta);

	CVector3__Cross(&vAxis, &vZ, &vDelta);
	CVector3__Normalize(&vAxis);

	dot = CVector3__Dot(&vZ, &vDelta);
	theta = min(acos(dot), MaxYRot);

	CQuatern__BuildFromAxisAngle(&qAim, vAxis.x, vAxis.y, vAxis.z, theta);

	if (pThis->m_Type == I_ANIMATED)
		CQuatern__Mult(&qFinal, &qRot, &qAim);
	else
		qFinal = qAim;

	vVelocity.x = vVelocity.y = vVelocity.z = 0;
	D_80028970(&pApp->m_Scene.m_ParticleSystem, pThis, nType,
											  vVelocity,
											  qFinal,
											  vParticlePos, pParticleRegion, PARTICLE_NOEDGE, Blood);

/*
	CEngineApp				*pApp;
	CGameObjectInstance	*pPlayer;
	CVector3					vParticlePos,
								vPlayerPos,
								vDelta,
								vVelocity;
	CQuatern					qFinal, qYRot, qXRot ;
	CGameRegion				*pParticleRegion;

	FLOAT						XZAngle, XYAngle, DeltaAngle ;

	// Get player pointer
	pApp = GetApp() ;
	if (pThis->m_Type == I_ANIMATED)
	{
		pPlayer = ((CGameObjectInstance*)pThis)->m_pAttackerCGameObjectInstance ;
		if (!pPlayer)
			pPlayer = CEngineApp__GetPlayer(pApp) ;
	}
	else
		pPlayer = CEngineApp__GetPlayer(pApp) ;

	// Get particle position
	CInstanceHdr__GetNearPositionAndRegion(pThis, vPos, &vParticlePos, &pParticleRegion, INTERSECT_BEHAVIOR_STICK, INTERSECT_BEHAVIOR_STICK) ;

	// Find aiming rotation
	vPlayerPos = AI_GetPos(pPlayer);
	vPlayerPos.y += (TUROK_HEIGHT/2)*SCALING_FACTOR;

	CVector3__Subtract(&vDelta, &vPlayerPos, &vParticlePos) ;
	XZAngle = CVector3__XZAngle(&vDelta) ;

	// Limit XZ angle
	if (pThis->m_Type == I_ANIMATED)
	{
		DeltaAngle = AngleDiff(((CGameObjectInstance *)pThis)->m_RotY, XZAngle) ;
		if (DeltaAngle < -MaxYRot)
			DeltaAngle = -MaxYRot ;
		else
		if (DeltaAngle > MaxYRot)
			DeltaAngle = MaxYRot ;

		XZAngle = ((CGameObjectInstance *)pThis)->m_RotY + DeltaAngle ;
	}

	// Calculate direction - note ground orientation is not taken into account
	XYAngle = CVector3__XYAngle(&vDelta) ;
	CQuatern__BuildFromAxisAngle(&qXRot, 1, 0, 0, XYAngle) ;
	CQuatern__BuildFromAxisAngle(&qYRot, 0, 1, 0, XZAngle + ANGLE_DTOR(180)) ;
	CQuatern__Mult(&qFinal, &qXRot, &qYRot) ;


	vVelocity.x = vVelocity.y = vVelocity.z = 0 ;
	CParticleSystem__CreateParticle(&pApp->m_Scene.m_ParticleSystem, pThis, nType,
											  vVelocity,
											  qFinal,
											  vParticlePos, pParticleRegion, PARTICLE_NOEDGE, TRUE) ;
*/
}

