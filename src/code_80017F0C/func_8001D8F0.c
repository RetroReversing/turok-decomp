#include "common_local_source_3944.h"

#line 2 "reference.c"
CQuatern func_8001D8F0(CGameObjectInstance *pThis, CVector3 vPos, CQuatern *pqFixResult, float Angle)
{
	int			cInst, nInsts;
	float			minDot, dot, theta, u;
	CVector3		vDelta, vForward, vAim, vAxis, vChosenDelta, vTarget;
	CQuatern		qAim, qFix, qResult;
	CMtxF			mfAim;
	CGameObjectInstance	*pChosenOne,
								*pTarget;

	vForward.x = 0;
	vForward.y = 0;
	vForward.z = 1;


	qAim = CGameObjectInstance__GetAimRotation(pThis);

	if (Angle == 0)
	{
		if (pqFixResult)
			CQuatern__Identity(pqFixResult);

		return qAim;
	}

	func_80014DC4(&qAim, mfAim);
	func_80015754(mfAim, &vForward, &vAim);

	minDot = cos(ANGLE_DTOR(Angle/2));

	pChosenOne = NULL;

	nInsts = GetApp()->m_Scene.m_nActiveAnimInstances;
	for (cInst=0; cInst<nInsts; cInst++)
	{
		pTarget = GetApp()->m_Scene.m_pActiveAnimInstances[cInst];
		if (		(pTarget != pThis)
				&&	(!CGameObjectInstance__IsDevice(pTarget))
				&& (pTarget->m_AI.m_Health) )
		{
			vTarget = pTarget->ah.ih.m_vPos;
			vTarget.y += pTarget->ah.ih.m_CollisionHeightOffset + (pTarget->ah.ih.m_pEA->m_CollisionHeight*0.72);

			CVector3__Subtract(&vDelta, &vTarget, &vPos);
			CVector3__Normalize(&vDelta);

			dot = CVector3__Dot(&vAim, &vDelta);
			if (dot > minDot)
			{
				minDot = dot;
				vChosenDelta = vDelta;
				pChosenOne = pTarget;
			}
		}
	}

	if (pChosenOne)
	{
		func_80013BBC(&vAxis, &vAim, &vChosenDelta);
		CVector3__Normalize(&vAxis);

		theta = acos(minDot);
		u = 1 - theta/(ANGLE_DTOR(Angle/2));
		u = sqrt(sqrt(u));
		theta *= u;

		CQuatern__BuildFromAxisAngle(&qFix, vAxis.x, vAxis.y, vAxis.z, theta);
		func_80014CB8(&qResult, &qAim, &qFix);

		if (pqFixResult)
			*pqFixResult = qFix;

		return qResult;
	}
	else
	{
		if (pqFixResult)
			CQuatern__Identity(pqFixResult);

		return qAim;
	}
}
