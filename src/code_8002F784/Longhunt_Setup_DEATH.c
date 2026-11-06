#include "common_local_source_4576.h"

#line 1 "reference.c"
void Longhunt_Setup_DEATH(CGameObjectInstance *pThis, CLonghunt *pLonghunt)
{
	CInstanceHdr	*pOrigin = (CInstanceHdr *)pThis ;
	CLine				Line ;
	CVector3			vMiddle, vPos ;
	CDynamicSimple	*pPickup ;

	// Play sound
	AI_SEvent_GeneralSound(&pThis->ah.ih, pThis->ah.ih.m_vPos, SOUND_LONGHUNTER_TAUNT_3) ;

	// Put into mode
	pLonghunt->m_Boss.m_Mode = LONGHUNT_DEATH_MODE ;

	// Open door region in middle of arena
	Longhunt_OpenForceField(pThis, pLonghunt) ;

	// Turn off the force field object
	AI_Event_Dispatcher(pOrigin, pOrigin, AI_MEVENT_PRESSUREPLATE, pOrigin->m_pEA->m_dwSpecies, pOrigin->m_vPos, LONGHUNT_LEVEL_FORCEFIELD_ID) ;
	GetApp()->m_BossFlags |= BOSS_FLAG_LONGHUNTER_FORCEFIELD_GONE ;

	// tell the engine that the main boss for this level is dead
	//BOSS_LevelComplete() ;

	CCamera__SetObjectToTrack(&GetApp()->m_Camera, pThis) ;
	CPickupMonitor__Deactivate(&GetApp()->m_Scene.m_PickupMonitor) ;

	// Generate longhunter gun pickup and record status
	if (!(GetApp()->m_BossFlags & BOSS_FLAG_LONGHUNTER_DEAD))
	{
		CVector3__Set(&vMiddle,0,0,0) ;
		CLine__Construct(&Line, &pThis->ah.ih.m_vPos, &vMiddle) ;
		CLine__CalculateXZDirection(&Line) ;
		vPos = pThis->ah.ih.m_vPos ;
		vPos.x += 15*SCALING_FACTOR * Line.m_vDir.x ;
		vPos.z += 15*SCALING_FACTOR * Line.m_vDir.z ;

		// Start and bounce the pickup
		pPickup = AI_DoPickup(&pThis->ah.ih, vPos, AI_OBJECT_PICKUP_MACHINEGUN,0) ;
		if (pPickup)
			pPickup->s.ah.m_vVelocity.y = 5*SCALING_FACTOR ;

		GetApp()->m_BossFlags |= BOSS_FLAG_LONGHUNTER_DEAD	;
	}

	// Start cinema
	CCamera__FadeToCinema(&GetApp()->m_Camera, CINEMA_FLAG_TUROK_KILL_LONGHUNTER) ;
	pLonghunt->m_Boss.m_AnimPlayed = FALSE ;
}
