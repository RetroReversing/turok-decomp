#include "decompdecomp_sync_f56865daf68e9869d537.h"
#line 1 "func.c"
#line 771 "reference.c"
CGameRegion* CCollide__CanEnter(CCollide *pThis, CGameRegion *pCurrent, int nDesiredEdge, CVector3 *pvComparePos)
{
	CGameRegion			*pDesired;
	CAnimInstanceHdr	*pInst;
	float					currentHeight,
							desiredHeight,
							edgeAngle, dt,
							compareHeight,
							dot;
	int					cEdge;
	BOOL					found,
							moveUpLedges, moveDownLedges,
							currentIsCliff, desiredIsCliff;
	CVector3				vNextLower,
							vCeilingNormal, vDelta;

	ASSERT(pCurrent);

	pInst = pThis->pInst;
	
	pDesired = pCurrent->m_pNeighbors[nDesiredEdge];


	// TEMP
	//return pDesired;


	if (!pDesired)
		return NULL;

	if (pCurrent->m_wFlags & REGFLAG_BRIDGE)
	{
		// if pDesired is linked back to pCurrent, this is a normal
		// transition -- otherwise, the instance went off the edge of
		// a bridge

		found = FALSE;
		for (cEdge=0; cEdge<3; cEdge++)
		{
			if (pDesired->m_pNeighbors[cEdge] == pCurrent)
			{
				found = TRUE;
				break;
			}
		}

		if (!found)
		{
			// this is a bridge transition
			// first, see if pvCurrent is within pDesired

			if (!func_8001E21C(pDesired, pvComparePos->x, pvComparePos->z))
			{
				// missed with guess
				// search all regions

				vNextLower.x = pvComparePos->x;
				vNextLower.y = pInst->ih.m_vPos.y;
				vNextLower.z = pvComparePos->z;

				pDesired = CGameRegion__FindNextLowerRegion(pCurrent, vNextLower);
				if (!pDesired)
					return NULL;
			}
		}
	}

	// WHY SPECIAL CASE THIS -- WHAT'S WRONG WITH RESTRICTED AREAS?
	// Used to keep TREX out of big life area
	if (		(pThis->pCI->dwFlags & COLLISIONFLAG_AVOIDPRESSUREPLATE)
			&& (		(pDesired->m_wFlags & REGFLAG_PRESSUREPLATE)
					||	(pDesired->m_wFlags & REGFLAG_PRESSUREPLATENEEDSCOLLISION) ) )
	{
		return NULL;
	}

	// keep bad guys out of trouble
	if (		(pDesired->m_wFlags & REGFLAG_RESTRICTEDAREA)
			&& !(pThis->pCI->dwFlags & COLLISIONFLAG_CANENTERRESTRICTEDAREA) )
	{
		return NULL;
	}

	// keep in water
	if (		!(pThis->pCI->dwFlags & COLLISIONFLAG_EXITWATER)
			&& !(pDesired->m_wFlags & REGFLAG_HASWATER)
			&& (pCurrent->m_wFlags & REGFLAG_HASWATER) )
	{
		return NULL;
	}

	// avoid water
	if (		!(pThis->pCI->dwFlags & COLLISIONFLAG_ENTERWATER)
			&& (pDesired->m_wFlags & REGFLAG_HASWATER)
			&& !(pCurrent->m_wFlags & REGFLAG_HASWATER) )
	{
		return NULL;
	}

	// need to be ducking to enter ducking area
	if (		(pDesired->m_wFlags & REGFLAG_DUCK)
			&&	!(pThis->pCI->dwFlags & COLLISIONFLAG_DUCKING) )
	{
		return NULL;
	}

	// can't enter closed door
	if (		!(pThis->pCI->dwFlags & COLLISIONFLAG_MOVETHROUGHDOORS)
			&&	(pDesired->m_wFlags & REGFLAG_DOOR)
			&& !(pDesired->m_wFlags & REGFLAG_OPENDOOR) )
	{
		return NULL;
	}


	// bump in to wall above ceiling
/*
	if ((pDesired->m_wFlags & REGFLAG_CEILING) && !(pCurrent->m_wFlags & REGFLAG_CEILING))
	{
		if (pInst->ih.m_vPos.y > CGameRegion__GetCeilingHeight(pDesired, pInst->ih.m_vPos.x, pInst->ih.m_vPos.z))
		{
			// only hit front side of ceiling
			vCeilingNormal = CGameRegion__GetCeilingNormal(pDesired);
			
			vDelta.x = pInst->ih.m_vPos.x - pDesired->m_pCorners[0]->m_vCorner.x;
			vDelta.y = pInst->ih.m_vPos.y - pDesired->m_pCorners[0]->m_Ceiling;
			vDelta.z = pInst->ih.m_vPos.z - pDesired->m_pCorners[0]->m_vCorner.z;

			dot = CVector3__Dot(&vCeilingNormal, &vDelta);
			if (dot >= 0.0)
				return NULL;
		}
	}
*/
	if ((pDesired->m_wFlags & REGFLAG_CEILING) && !(pCurrent->m_wFlags & REGFLAG_CEILING))
		if (pvComparePos->y > CGameRegion__GetCeilingHeight(pDesired, pvComparePos->x, pvComparePos->z))
			return NULL;

	currentIsCliff = CGameRegion__IsCliff(pCurrent);
	desiredIsCliff = CGameRegion__IsCliff(pDesired);
	
	if (pThis->pCI->dwFlags & COLLISIONFLAG_CLIFFONLY)
	{
		if (desiredIsCliff)
			return pDesired;
		else
			return NULL;
	}

	// stay on climbable portion of cliff
	if (		(pThis->pCI->dwFlags & COLLISIONFLAG_CANCLIMBCLIMBABLE)
			&& currentIsCliff
			&& desiredIsCliff
			&& (pCurrent->m_wFlags & REGFLAG_CLIMBABLE)
			&& !(pDesired->m_wFlags & REGFLAG_CLIMBABLE) )
	{
		currentHeight = CGameRegion__GetGroundHeight(pCurrent, pInst->ih.m_vPos.x, pInst->ih.m_vPos.z);
		if (pInst->ih.m_vPos.y < (currentHeight + 0.1*SCALING_FACTOR))
			return NULL;
	}

	if (desiredIsCliff && !currentIsCliff)
	{
		moveUpLedges	= pThis->pCI->dwFlags & COLLISIONFLAG_CLIMBUP;
		moveDownLedges	= pThis->pCI->dwFlags & COLLISIONFLAG_CLIMBDOWN;
		
		if ((pDesired->m_wFlags & REGFLAG_CLIMBABLE) && (pThis->pCI->dwFlags & COLLISIONFLAG_CANCLIMBCLIMBABLE))
		{
			// test angle
			edgeAngle = CGameRegion__GetEdgeAngle(pCurrent, nDesiredEdge);
			edgeAngle += ANGLE_PI;
			NormalizeRotation(&edgeAngle);

			// COLLISIONFLAG_CANCLIMBCLIMBABLE should only be set for CGameObjectInstance's
			ASSERT(pInst->ih.m_Type == I_ANIMATED);

			dt = RotDifference(edgeAngle, ((CGameObjectInstance*)pInst)->m_RotY);

#define ALLOW_CLIMB_ANGLE	ANGLE_DTOR(40)

			if (fabs(dt) <= ALLOW_CLIMB_ANGLE)
				moveUpLedges = TRUE;
		}

		if (moveUpLedges && moveDownLedges)
			return pDesired;

		currentHeight = CGameRegion__GetGroundHeight(pCurrent, pInst->ih.m_vPos.x, pInst->ih.m_vPos.z);
		desiredHeight = CGameRegion__GetGroundHeight(pDesired, pThis->vDesired.x, pThis->vDesired.z);

		if (desiredHeight > currentHeight)
		{
			if (moveUpLedges)
			{
				return pDesired;
			}
			else
			{
#define COMPARE_HEIGHT_RANGE	(0.1*SCALING_FACTOR)
//#define COMPARE_HEIGHT_RANGE	(1*SCALING_FACTOR)
				compareHeight = pInst->ih.m_vPos.y + COMPARE_HEIGHT_RANGE;
				//compareHeight = pInst->ih.m_vPos.y;

				// change to intersection?

				if (		(compareHeight > pDesired->m_pCorners[0]->m_vCorner.y)
						&&	(compareHeight > pDesired->m_pCorners[1]->m_vCorner.y)
						&& (compareHeight > pDesired->m_pCorners[2]->m_vCorner.y) )
				{
					return pDesired;
				}
				else
				{
					return NULL;
				}
			}
		}
		else
		{
			return moveDownLedges ? pDesired : NULL;
		}
	}
	else
	{
		return pDesired;
	}
}

