#include "decompdecomp_sync_11ca78dd555f6bb4ea34.h"
#line 1 "func.c"
#line 9465 "reference.c"
BOOL func_80071F08(CGameObjectInstance *pMe, CGameObjectInstance *pTarget)
{
	// declare variables
	float dx, dz, dist, angle;

	// can this ai see target ?
	if (    (pTarget == NULL)
		  || (AI_GetDyn(pTarget)->m_Health == 0) )
	{
		AI_GetDyn(pMe)->m_dwStatusFlags &= (~AI_EV_SEETARGET);
		AI_GetDyn(pMe)->m_ViewAngleOffset = 0;
		return 0;
	}

	// get distance between ai & target
	dx   = AI_GetPos(pMe).x - AI_GetPos(pTarget).x;
	dz   = AI_GetPos(pMe).z - AI_GetPos(pTarget).z;

	dist = dx * dx + dz * dz;

	// did ai hear a get attention
	if ( AI_GetEA(pMe)->m_SightRadius >= dist )
	{
		angle = func_80071DA4(pMe, AI_GetPos(pTarget)) - AI_GetDyn(pMe)->m_ViewAngleOffset;
		if (angle > D_800F5630)
			angle -= D_800F5638;
		else if (angle < D_800F5640)
			angle += D_800F5648;

		// within sight angle ?
		if (		(fabs(angle) <= AI_GetEA(pMe)->m_SightAngle)
				&& func_8001DE20(&pMe->ah, &pTarget->ah.ih) )
		{
			// make ai enter attack mode - it has spotted target
			AI_GetDyn(pMe)->m_dwStatusFlags |= AI_EV_SEETARGET;
			func_8005F2B8 ( pMe, AI_AGITATION_SEETARGET, 300 );
			AI_GetDyn(pMe)->m_ViewAngleOffset = 0;

			return 1;
		}
		else AI_GetDyn(pMe)->m_dwStatusFlags &= (~AI_EV_SEETARGET);
	}
	else AI_GetDyn(pMe)->m_dwStatusFlags &= (~AI_EV_SEETARGET);


	AI_GetDyn(pMe)->m_ViewAngleOffset = 0;
	return 0;
}

