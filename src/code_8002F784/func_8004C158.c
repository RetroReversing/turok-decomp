#include "common_local_source_4590.h"

#line 813 "reference.c"
void func_8004C158(CGameObjectInstance *pThis, CHumvee *pHumvee)
{
	CGameObjectInstance *pTurok ;
	CVector3		vDir, vTurokPos ;
	FLOAT			DistFromCentre, rot ;
	BOOL			SetNewTarget ;


	// Calculate distance from centre of arena
	pHumvee->m_DistFromCentre = (BOSS_GetPos(pThis).x * BOSS_GetPos(pThis).x) +
										 (BOSS_GetPos(pThis).z * BOSS_GetPos(pThis).z) ;

	if (pHumvee->m_DistFromCentre)
		pHumvee->m_DistFromCentre = sqrt(pHumvee->m_DistFromCentre) ;
	else
		pHumvee->m_DistFromCentre = 0 ;


	// Swap targets
	if (pHumvee->m_Boss.m_DistFromTarget < RandomRangeFLOAT(20*SCALING_FACTOR, 40*SCALING_FACTOR))
	{
		// Next target
		pHumvee->m_TargetNumber++ ;
		if (pHumvee->m_TargetNumber > 1)
			pHumvee->m_TargetNumber = 0 ;


#if DEBUG_HUMVEE
		if (BOSS_Health(pThis) > 0)
		{
			if (pHumvee->m_TargetNumber)
			{
				rmonPrintf("\r\nHumvee:%d - ", AI_GetEA(pThis)->m_Id) ;
				rmonPrintf("Going to run down Turok!\r\n") ;
			}
			else
			{
				rmonPrintf("\r\nHumvee:%d - ", AI_GetEA(pThis)->m_Id) ;
				rmonPrintf("Going away for a little drive...\r\n") ;
			}
		}
#endif

		SetNewTarget = TRUE ;
	}
	else
		SetNewTarget = FALSE ;


	// Setup Turok pos
	pTurok = CEngineApp__GetPlayer(GetApp());
	vTurokPos = TUROK_GetPos(pTurok) ;

	// Calculate direction towards centre of arena
	vDir = vTurokPos ;
	vDir.y = 0 ;
	CVector3__Normalize(&vDir) ;


	// Which target?
	switch(pHumvee->m_TargetNumber)
	{

		// Go to middle or outside of arena
		case 0:
			if (SetNewTarget)
			{
				// Calculate Turok distance from centre of arena
				if (DistFromCentre = (vTurokPos.x * vTurokPos.x) +	(vTurokPos.z * vTurokPos.z))
					DistFromCentre = sqrt(DistFromCentre) ;

#define	HUMVEE_INNER_TARGET_DIST 	(60*SCALING_FACTOR)
#define	HUMVEE_OUTER_TARGET_DIST 	(HUMVEE_ARENA_RADIUS - (60*SCALING_FACTOR))


				// Use outer or inner?
				if (DistFromCentre > (HUMVEE_ARENA_RADIUS / 2))
				{
					vDir.x *= HUMVEE_INNER_TARGET_DIST ;
					vDir.z *= HUMVEE_INNER_TARGET_DIST ;
				}
				else
				{
					vDir.x *= HUMVEE_OUTER_TARGET_DIST ;
					vDir.z *= HUMVEE_OUTER_TARGET_DIST ;
				}
			}
			else
				vDir = pHumvee->m_Boss.m_vTarget ;

			break ;


		// Go for Turok
		case 1:
			rot = pTurok->m_RotY ;
			vDir.x = vTurokPos.x - (HUMVEE_TUROK_TARGET_OFFSET * sin(rot)) ;
			vDir.z = vTurokPos.z - (HUMVEE_TUROK_TARGET_OFFSET * cos(rot)) ;
			break ;
	}


	// Calculate distance from this target
	pHumvee->m_Boss.m_vTarget = vDir ;
	pHumvee->m_Boss.m_DistFromTargetSqr = func_8005F34C(pThis, vDir) ;
	if (pHumvee->m_Boss.m_DistFromTargetSqr)
		pHumvee->m_Boss.m_DistFromTarget = sqrt(pHumvee->m_Boss.m_DistFromTargetSqr) ;
	else
		pHumvee->m_Boss.m_DistFromTarget = 0 ;


	// Calculate angle to drive at
	pHumvee->m_Boss.m_DeltaAngle =
		func_800747C0(pThis, pHumvee->m_Boss.m_vTarget, pTurok, AVOIDANCE_RADIUS_DISTANCE_FACTOR) ;
}
