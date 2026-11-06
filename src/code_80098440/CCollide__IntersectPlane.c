#include "source_func_80099744.h"
#line 1 "func.c"
#line 1 "reference.c"
BOOL CCollide__IntersectPlane(CCollide *pThis,
										CVector3 *pvNormal, CVector3 *pvPointOnPlane,
										BOOL BackCull,
										int Behavior,
										float SurfaceFriction)
{
	float			normalDotMovementDelta,
					normalDotPointDelta,
					t,
					magNormal;
	CVector3		vPointDelta, vUnitNormal,
					vRemainDelta,
					vReflectDelta, vProjectDelta,
					vProject, vRedirect,
					vBackOffFromEdge;

	if (Behavior == INTERSECT_BEHAVIOR_IGNORE)
		return FALSE;

	// don't intersect with surface that it's sliding on
	if (CCollide__IsSlidePlane(pThis, pvNormal))
		return FALSE;

	normalDotMovementDelta = CVector3__Dot(pvNormal, &pThis->vDelta);
	if (		(normalDotMovementDelta == 0.0)
			||	(BackCull && (normalDotMovementDelta > 0.0)) )
	{
		return FALSE;
	}

	CVector3__Subtract(&vPointDelta, pvPointOnPlane, &pThis->pInst->ih.m_vPos);
	normalDotPointDelta = CVector3__Dot(pvNormal, &vPointDelta);

	t = normalDotPointDelta/normalDotMovementDelta;
	if (t >= pThis->clint.t)
	{
		// this is not the closest intersection
		return FALSE;
	}

	if (t < -0.2)
		t = -0.2;

//	if (		(!pThis->AllowRedirection && (t < 0.0))
//			||	(t < -0.1) )
//	{
//		t = 0.0;
//	}

	pThis->clint.t = t;
	CVector3__Blend(&pThis->clint.vIntersect, t,
						 &pThis->pInst->ih.m_vPos, &pThis->vDesired);

	if (Behavior == INTERSECT_BEHAVIOR_SLIDEBOUNCE)
	{
		if (pThis->TrackingGround)
			Behavior = INTERSECT_BEHAVIOR_SLIDE;
		else
			Behavior = INTERSECT_BEHAVIOR_BOUNCE;
	}

	// roll
	if ((Behavior == INTERSECT_BEHAVIOR_BOUNCE) && (pThis->pCI->BounceReturnEnergy < 1.0))
	{
		if (CVector3__MagnitudeSquared(&pThis->vDelta) < SQR(0.4*SCALING_FACTOR))
		{
			if ((SQR(pThis->vDelta.x) + SQR(pThis->vDelta.z)) < SQR(0.1*SCALING_FACTOR))
				Behavior = INTERSECT_BEHAVIOR_STICK;
			else
				Behavior = INTERSECT_BEHAVIOR_SLIDE;
		}
	}

	switch (Behavior)
	{
		case INTERSECT_BEHAVIOR_ITERATE:

			CCollide__ClearSlideSurface(pThis);

			pThis->clint.cr = CR_NO_COLLISION_NEWDESIREDPOS;

			if (pThis->UsePhysics)
				pThis->clint.vNextVelocity = pThis->pInst->m_vVelocity;

			pThis->clint.vNextDesired = pThis->vDesired;

			break;

		case INTERSECT_BEHAVIOR_STICK:

			CCollide__ClearSlideSurface(pThis);

			pThis->clint.cr = CR_COLLISION;

			if (pThis->UsePhysics)
			{
				// clear velocity
				pThis->clint.vNextVelocity.x
						= pThis->clint.vNextVelocity.y
						= pThis->clint.vNextVelocity.z
						= 0.0;
			}
			break;

		case INTERSECT_BEHAVIOR_BOUNCE:

			CCollide__ClearSlideSurface(pThis);

			if (pThis->UsePhysics || pThis->AllowRedirection)
			{
				magNormal = CVector3__Magnitude(pvNormal);
				if (magNormal == 0.0)
					return FALSE;

				CVector3__MultScaler(&vUnitNormal, pvNormal, 1.0/magNormal);
			}

			if (pThis->UsePhysics)
			{
				// reflect velocity
				pThis->clint.vNextVelocity = CVector3__Reflect(&pThis->pInst->m_vVelocity,
																			  &vUnitNormal,
																			  pThis->pCI->BounceReturnEnergy);
				CVector3__MultScaler(&pThis->clint.vNextVelocity,
											&pThis->clint.vNextVelocity,
											1.0 - SurfaceFriction);
			}

			if (pThis->AllowRedirection)
			{
				pThis->clint.cr = CR_COLLISION_NEWDESIREDPOS;

				// reflect remaining motion
				CVector3__MultScaler(&vRemainDelta, &pThis->vDelta, 1.0 - t);

				vReflectDelta = CVector3__Reflect(&vRemainDelta,
															 &vUnitNormal,
															 pThis->pCI->BounceReturnEnergy);
				CVector3__MultScaler(&vReflectDelta,
											&vReflectDelta,
											1.0 - SurfaceFriction);

				CVector3__Add(&pThis->clint.vNextDesired,
								  &pThis->clint.vIntersect, &vReflectDelta);
			}
			else
			{
				pThis->clint.cr = CR_COLLISION;
			}
			break;

		case INTERSECT_BEHAVIOR_SLIDE:

			CCollide__SetSlidePlane(pThis, pvNormal);

			if (pThis->UsePhysics || pThis->AllowRedirection)
			{
				magNormal = CVector3__Magnitude(pvNormal);
				if (magNormal == 0.0)
					return FALSE;

				CVector3__MultScaler(&vUnitNormal, pvNormal, 1.0/magNormal);
			}

			if (pThis->UsePhysics)
			{
				// project velocity on plane
				pThis->clint.vNextVelocity = CVector3__Project(&pThis->pInst->m_vVelocity,
																			  &vUnitNormal);

				CVector3__MultScaler(&pThis->clint.vNextVelocity,
											&pThis->clint.vNextVelocity,
											1.0 - SurfaceFriction);
			}

			if (pThis->AllowRedirection)
			{
				pThis->clint.cr = CR_COLLISION_NEWDESIREDPOS;

				// project remaining motion
				CVector3__MultScaler(&vRemainDelta, &pThis->vDelta, 1.0 - t);

				vProjectDelta = CVector3__Project(&vRemainDelta, &vUnitNormal);
				CVector3__MultScaler(&vProjectDelta,
											&vProjectDelta,
											1.0 - SurfaceFriction);

				CVector3__Add(&pThis->clint.vNextDesired,
								  &pThis->clint.vIntersect, &vProjectDelta);

				CVector3__MultScaler(&vBackOffFromEdge, &vUnitNormal, INTERSECT_BACKOFF_DIST);
				CVector3__Add(&pThis->clint.vNextDesired, &pThis->clint.vNextDesired, &vBackOffFromEdge);
			}
			else
			{
				pThis->clint.cr = CR_COLLISION;
			}
			break;

		case INTERSECT_BEHAVIOR_REDIRECT:

			CCollide__SetSlidePlane(pThis, pvNormal);

			if (pThis->UsePhysics || pThis->AllowRedirection)
			{
				magNormal = CVector3__Magnitude(pvNormal);
				if (magNormal == 0.0)
					return FALSE;

				CVector3__MultScaler(&vUnitNormal, pvNormal, 1.0/magNormal);
			}

			if (pThis->UsePhysics)
			{
				// project velocity on plane
				pThis->clint.vNextVelocity = CVector3__Redirect(&pThis->pInst->m_vVelocity,
																				&vUnitNormal);
			}

			if (pThis->AllowRedirection)
			{
				pThis->clint.cr = CR_COLLISION_NEWDESIREDPOS;

				// redirect remaining motion
				CVector3__MultScaler(&vRemainDelta, &pThis->vDelta, 1.0 - t);

				vProjectDelta = CVector3__Redirect(&vRemainDelta, &vUnitNormal);

				CVector3__Add(&pThis->clint.vNextDesired,
								  &pThis->clint.vIntersect, &vProjectDelta);

				CVector3__MultScaler(&vBackOffFromEdge, &vUnitNormal, INTERSECT_BACKOFF_DIST);
				CVector3__Add(&pThis->clint.vNextDesired, &pThis->clint.vNextDesired, &vBackOffFromEdge);
			}
			else
			{
				pThis->clint.cr = CR_COLLISION;
			}
			break;

		case INTERSECT_BEHAVIOR_GREASE:

			CCollide__SetSlidePlane(pThis, pvNormal);

			if (pThis->UsePhysics || pThis->AllowRedirection)
			{
				magNormal = CVector3__Magnitude(pvNormal);
				if (magNormal == 0.0)
					return FALSE;

				CVector3__MultScaler(&vUnitNormal, pvNormal, 1.0/magNormal);
			}

			if (pThis->UsePhysics)
			{
				// project velocity on plane
				vProject = CVector3__Project(&pThis->pInst->m_vVelocity, &vUnitNormal);
				vRedirect = CVector3__Redirect(&pThis->pInst->m_vVelocity, &vUnitNormal);

				CVector3__Blend(&pThis->clint.vNextVelocity,
									 COLLISION_GREASE_FACTOR,
									 &vProject, &vRedirect);
				CVector3__MultScaler(&pThis->clint.vNextVelocity,
											&pThis->clint.vNextVelocity,
											1.0 - SurfaceFriction);
			}

			if (pThis->AllowRedirection)
			{
				pThis->clint.cr = CR_COLLISION_NEWDESIREDPOS;

				// project remaining motion
				CVector3__MultScaler(&vRemainDelta, &pThis->vDelta, 1.0 - t);


				vProject = CVector3__Project(&vRemainDelta, &vUnitNormal);
				vRedirect = CVector3__Redirect(&vRemainDelta, &vUnitNormal);

				CVector3__Blend(&vProjectDelta,
									 COLLISION_GREASE_FACTOR,
									 &vProject, &vRedirect);
				CVector3__MultScaler(&vProjectDelta,
											&vProjectDelta,
											1.0 - SurfaceFriction);


				CVector3__Add(&pThis->clint.vNextDesired,
								  &pThis->clint.vIntersect, &vProjectDelta);

				CVector3__MultScaler(&vBackOffFromEdge, &vUnitNormal, INTERSECT_BACKOFF_DIST);
				CVector3__Add(&pThis->clint.vNextDesired, &pThis->clint.vNextDesired, &vBackOffFromEdge);
			}
			else
			{
				pThis->clint.cr = CR_COLLISION;
			}
			break;

		default:
			ASSERT(FALSE);
			break;
	}

	return TRUE;
}

