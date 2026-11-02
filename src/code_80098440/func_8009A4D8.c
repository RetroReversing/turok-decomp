#include "decompdecomp_sync_597d100d0ca3fc90b2ca.h"
#line 1 "func.c"
extern const double D_800F6C18;
extern const double D_800F6C20;
#line 43 "reference.c"
int func_8009A4D8(CAnimInstanceHdr *pThis,
											CVector3 vDesired,
											CCollisionInfo2 *pCI)
{
#define COLLISION_MAX_ITERATIONS	100	// safety cap for loop

	int					cf,					// current collision routine
							cIteration,			// iteration counter
							cCollision,			// collision counter
							nMaxCollisions;	// max number of collisions allowed
//							prevGroundBehavior;
	CCollide				cd;					// collision data shared by collision
													//   routines
	float					remainT,				// remaining motion (range: 0.0 - 1.0)
							dt,					// time (sec) for movement computation
							dtd2,
							friction,			// air/water/ground friction
													//   (range: 0.0 - 1.0)
							groundHeight,
							startYPos;
	CVector3				vAcceleration,		// total acceleration
							vZero = { 0.0, 0.0, 0.0 },
							vGroundUnitNormal,
							vCornerDelta,
							vProjected,
							*pvCorner;
	BOOL					newDesiredPos,		// desired pos changed
							slideHeight;
	CROMRegionSet		*pRegionSet;

	// TEMP
	//pCI->dwFlags |= COLLISIONFLAG_USEWALLRADIUS;

	ASSERT(pThis);
	ASSERT(pCI);

	pRegionSet = func_8002E438(&GetApp()->m_Scene, pThis->ih.m_pCurrentRegion);

	// clear collision results
	func_8009C5D0(pCI);

	// initialize CCollide variables for entire collision operation
	cd.pInst = pThis;
	cd.pCI = pCI;
	cd.vDesired = vDesired;
	CCollide__InitSlideSurface(&cd);

	// initialize collision variables
	cIteration = 0;
	cCollision = 0;
	remainT = 1.0;
	
	dt = FRAME_INC_TO_SECONDS(D_800B6B00);

	if (pCI->dwFlags & COLLISIONFLAG_TWOREDIRECTIONS)
	{
		// allow 2 redirections
		nMaxCollisions = 3;
	}
	else
	{
		// allow 1 redirection
		nMaxCollisions = 2;
	}

	cd.UsePhysics = (pCI->dwFlags & COLLISIONFLAG_PHYSICS) && (dt != 0.0);

	if (cd.UsePhysics)
	{
		startYPos = pThis->ih.m_vPos.y;

		// friction
		friction = pCI->AirFriction;
		if (pCI->WaterFriction != pCI->AirFriction)
		{
			if (pThis->ih.m_pCurrentRegion)
			{
				if (pThis->ih.m_pCurrentRegion->m_wFlags & REGFLAG_HASWATER)
				{
					if (pRegionSet && (pThis->ih.m_vPos.y < pRegionSet->m_WaterElevation))
						friction = pCI->WaterFriction;
				}
			}
		}

		friction = min(1.0/dt, 15*friction);

		// acceleration = -friction*(velocity^2) + gravity
		if (friction == 0.0)
		{
			vAcceleration.x =	0.0;
			vAcceleration.y = pCI->GravityAcceleration;
			vAcceleration.z = 0.0;
		}
		else
		{
			vAcceleration.x = -pThis->m_vVelocity.x*friction;
			vAcceleration.y = -pThis->m_vVelocity.y*friction + pCI->GravityAcceleration;
			vAcceleration.z = -pThis->m_vVelocity.z*friction;
		}

		// pos = initialPos + initialVelocity*dt + 0.5*acceleration*(dt^2)
		dtd2 = 0.5*dt;
		cd.vDesired.x += (pThis->m_vVelocity.x + vAcceleration.x*dtd2)*dt;
		cd.vDesired.y += (pThis->m_vVelocity.y + vAcceleration.y*dtd2)*dt;
		cd.vDesired.z += (pThis->m_vVelocity.z + vAcceleration.z*dtd2)*dt;

		// velocity = initialVelocity + acceleration*dt
		pThis->m_vVelocity.x += vAcceleration.x*dt;
		pThis->m_vVelocity.y += vAcceleration.y*dt;
		pThis->m_vVelocity.z += vAcceleration.z*dt;

		pCI->vCollisionVelocity = pThis->m_vVelocity;
	}

	// skip collision if desired is same as current position
	if (CVector3__IsEqual(&pThis->ih.m_vPos, &cd.vDesired))
		return 0;

	//prevGroundBehavior = pCI->GroundBehavior;
	if (pRegionSet)
		cd.StartedInDeathFall = (pRegionSet->m_dwFlags & REGFLAG_FALLDEATH);
	else
		cd.StartedInDeathFall = FALSE;

	//if (pRegionSet && (pRegionSet->m_dwFlags & REGFLAG_FALLDEATH))
	//	pCI->GroundBehavior = INTERSECT_BEHAVIOR_IGNORE;

	cd.AllowRedirection = (cCollision + 1) < nMaxCollisions;

	func_80098F6C(&cd);
	
	if (cd.TrackingGround && cd.UsePhysics)
	{
		func_80013C2C(&pThis->m_vVelocity,
									&pThis->m_vVelocity,
									1.0 - min(1.0, pCI->GroundFriction));
	}

/*
	if ((pThis == &CEngineApp__GetPlayer(GetApp())->ah) && (pCI == &ci_player))
	{
		osSyncPrintf("ducking:%d\n", (pCI->dwFlags & COLLISIONFLAG_DUCKING) != 0);
		//osSyncPrintf("-- collision start -- pInst:%x\n", pThis);
	}
*/
	do
	{
		// initialize CCollide variables for iteration
		func_8009A4B4(&cd.clint);
		func_800144C8(&cd.vDelta, &cd.vDesired, &pThis->ih.m_vPos);

		if (cd.UsePhysics)
			cd.clint.vNextVelocity = pThis->m_vVelocity;

		// call collision routines
		for (cf=0; D_800EE480[cf]; cf++)
			D_800EE480[cf](&cd);

		switch (cd.clint.cr)
		{
			case CR_COLLISION:
			case CR_COLLISION_NEWDESIREDPOS:
				cCollision++;
			case CR_NO_COLLISION_NEWDESIREDPOS:
				// update current position
				pThis->ih.m_vPos = cd.clint.vIntersect;

				func_8009A44C(&cd.clint, pThis);

				if (cd.UsePhysics)
					pThis->m_vVelocity = cd.clint.vNextVelocity;

				CCollide__UpdateNextSlideSurface(&cd);

				break;

			case CR_NO_COLLISION:
				pThis->ih.m_vPos = cd.vDesired;
				break;

			default:
				ASSERT(FALSE);
				break;
		}

		if (		(pCI->dwFlags & COLLISIONFLAG_ENDONBOUNCE)
				&& pCI->pWallCollisionRegion )
		{
			return cCollision;
		}

		// t time has passed
		remainT -= cd.clint.t*remainT;

		if (cd.TrackingGround)
		{
 groundHeight = CInstanceHdr__GetGroundHeight(&pThis->ih);
 pThis->ih.m_vPos.y = max(pThis->ih.m_vPos.y, groundHeight);
}

		newDesiredPos =	 (cd.clint.cr == CR_NO_COLLISION_NEWDESIREDPOS)
							 || (cd.clint.cr == CR_COLLISION_NEWDESIREDPOS);

		if (newDesiredPos)
		{
			// update desired position for next iteration
			cd.vDesired = cd.clint.vNextDesired;

			cd.AllowRedirection = (cCollision + 1) < nMaxCollisions;

			func_80098F6C(&cd);
		}

		cIteration++;

	} while (	newDesiredPos
				&& (cIteration < COLLISION_MAX_ITERATIONS)
				&& (cCollision < nMaxCollisions) );


	// post collision stuff
	if (		(func_80098F20(&cd, pThis->ih.m_pCurrentRegion) != INTERSECT_BEHAVIOR_IGNORE)
			&& (pCI->WallBehavior != INTERSECT_BEHAVIOR_IGNORE)
			)
	{
		// didn't finish motion

if((remainT > D_800F6C18)) { if(cd.clint.pvIntersectPos == &pCI->vInstanceCollisionPos) slideHeight=(pCI->InstanceBehavior != INTERSECT_BEHAVIOR_STICK);
 else if(cd.clint.pvIntersectPos == &pCI->vWallCollisionPos) slideHeight=(pCI->WallBehavior != INTERSECT_BEHAVIOR_STICK);
 else slideHeight=FALSE;
 } else slideHeight=FALSE;


		groundHeight = CInstanceHdr__GetGroundHeight(&pThis->ih);
		pThis->ih.m_vPos.y = max((slideHeight ? cd.vDesired.y : pThis->ih.m_vPos.y), groundHeight);
	}


/*
	if (pCI->GroundBehavior != INTERSECT_BEHAVIOR_IGNORE)
	{
		// keep above ground
		groundHeight = CInstanceHdr__GetGroundHeight(&pThis->ih);
		if (cd.UsePhysics && (remainT > 0.01))
//		if (cd.UsePhysics && (remainT > 0.01) && !cd.TrackingGround)
			pThis->ih.m_vPos.y = max(cd.vDesired.y, groundHeight);
		else
			pThis->ih.m_vPos.y = max(pThis->ih.m_vPos.y, groundHeight);

		// ceiling?
	}
*/
	// set y velocity for ramps
	if (		cd.TrackingGround
			&& cd.UsePhysics
			&& (dt != 0.0)
			&& (pCI->GravityAcceleration != 0.0) )
	{
		if ((pThis->ih.m_vPos.y - startYPos) < D_800F6C20)
			pThis->m_vVelocity.y = (pThis->ih.m_vPos.y - startYPos)/dt;
	}

	//CVector3__Clamp(&pThis->ih.m_vPos, WORLD_LIMIT);

	//pCI->GroundBehavior = prevGroundBehavior;

/*
	if (pThis == &CEngineApp__GetPlayer(GetApp())->ah)
	{
		osSyncPrintf("-- collision done -- its:%d, cols:%d, pos(%f,%f,%f)\n\n",
			cIteration,
			cCollision,
			pThis->ih.m_vPos.x,
			pThis->ih.m_vPos.y,
			pThis->ih.m_vPos.z);
	}
*/
	return cCollision;
}

