#include "decompdecomp_sync_d9424e888c8c4866b7cb.h"
#line 1 "func.c"
#line 795 "reference.c"
BOOL CGameRegion__GetCeilingIntersection(CGameRegion *pThis, CVector3 *pvStart, CVector3 *pvEnd, float *Out)
{
	CVector3		vNormal, vDelta,
					vCorner, vCornerDelta;
	float			normalDotMovementDelta, normalDotCornerDelta;

	if (!pThis)
		return FALSE;

	vNormal = CGameRegion__GetCeilingNormal(pThis);
	CVector3__Subtract(&vDelta, pvEnd, pvStart);

	vCorner.x = pThis->m_pCorners[0]->m_vCorner.x;
	vCorner.y = pThis->m_pCorners[0]->m_Ceiling;
	vCorner.z = pThis->m_pCorners[0]->m_vCorner.z;

	//if (pvEnd->y <= pvStart->y)
	//	return FALSE;

	normalDotMovementDelta = CVector3__Dot(&vNormal, &vDelta);
	//if (normalDotMovementDelta == 0)
	if (normalDotMovementDelta >= 0)
	{
		*Out = 1;
		return FALSE;
	}

	CVector3__Subtract(&vCornerDelta, pvStart, &vCorner);
	normalDotCornerDelta = CVector3__Dot(&vNormal, &vCornerDelta);

	*Out = -normalDotCornerDelta/normalDotMovementDelta;
	return ((*Out > 0) && (*Out < 1));
}

