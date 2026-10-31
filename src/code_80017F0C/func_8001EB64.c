#include "source_func_8001EB64.h"

#line 1 "reference.c"
void func_8001EB64(CGameObjectInstance *pThis, CROMObjectInstance *pSource,
																	 CGameRegion Regions[], CEnemyAttributes Variations[])
{
	float groundHeight;
	//int ObjectType;

	//pThis->ah.m_vPrevBackoff.x = pThis->ah.m_vPrevBackoff.y = pThis->ah.m_vPrevBackoff.z = 0;

	pThis->ah.ih.m_Type		= I_ANIMATED;
	pThis->ah.ih.m_nObjType	= ORDERBYTES(pSource->m_nObjType);
	pThis->ah.ih.m_bActiveFlags = pSource->m_bActiveFlags;

	pThis->ah.ih.m_pEA		= &Variations[ORDERBYTES(pSource->m_nVariation)];

	if (ORDERBYTES(pSource->m_nCurrentRegion) == (WORD) -1)
		pThis->ah.ih.m_pCurrentRegion	= NULL;
	else
		pThis->ah.ih.m_pCurrentRegion	= &Regions[ORDERBYTES(pSource->m_nCurrentRegion)];

#ifndef WIN32
	pThis->m_qGround = pThis->m_qShadow = func_8001ABB8(&pThis->ah.ih);
#endif

   pThis->ah.ih.m_vPos		= ORDERBYTES(pSource->m_vPos);
	pThis->ah.ih.m_CollisionHeightOffset = 0;

	pThis->m_dwFlags = pSource->m_bFlags;

   pThis->m_vScale 			= ORDERBYTES(pSource->m_vScale);
   //pThis->m_pceObjectIndex = NULL;
	//pThis->m_pceAnimsHeader = pThis->m_pceAnimsIndex = NULL;
	//pThis->m_pCache = NULL;
	pThis->m_nAnims = 0;
	pThis->m_BlendStart = pThis->m_BlendFinish = 0;

	pThis->m_cMelt = 0;
	pThis->m_ShadowPercentage = 100.0;

	CQuatern__Identity(&pThis->m_qRot);
	pThis->m_RotY				= INT162FLOAT(ORDERBYTES(pSource->m_RotY), ANGLE_PI);

	pThis->ah.m_vVelocity.x = pThis->ah.m_vVelocity.y = pThis->ah.m_vVelocity.z = 0;
	CQuatern__Identity(&pThis->m_qGround);
	CQuatern__Identity(&pThis->m_qShadow);
	//pThis->m_ShadowIntensity = 1;

	func_8001E990(pThis, 0);
	CGameObjectInstance__SetNotBlending(pThis);
	pThis->m_WaitingForAnim = -1;
	func_800376A4(&pThis->m_asCurrent);
	func_800376A4(&pThis->m_asBlend);

	pThis->m_pEventCGameObjectInstance = NULL;
	pThis->m_pAttackerCGameObjectInstance = NULL;

   pThis->m_pceObjectIndex = pThis->m_pceAnimsHeader = pThis->m_pceAnimsIndex = pThis->m_pceObjectInfo = NULL;


#ifndef WIN32
	func_80083F00(&pThis->m_AI, pThis->ah.ih.m_pEA, pThis->ah.ih.m_vPos, pThis);

	// Clear draw vars
	pThis->pmtDrawMtxs = NULL ;

	// Clear special pointers
	pThis->m_pBoss = NULL;
	pThis->m_pCollisionFunction = NULL ;
	pThis->m_pCalculateOrientation = NULL ;

	// Initialise mode
	pThis->m_Mode = IDLE_MODE ;

	// Initialise head tracking
	pThis->m_HeadTurnAngle = 0 ;
	pThis->m_HeadTurnAngleVel = 0 ;
	pThis->m_HeadTiltAngle = 0 ;
	pThis->m_HeadTiltAngleVel = 0 ;
	pThis->m_HeadTrackBlend = 0 ;
	pThis->m_pHeadTrackInfo = NULL ;

	// Initialise swooshes
	pThis->m_ActiveSwooshes = FALSE ;

	pThis->m_nTypeFlag = pSource->m_nTypeFlag;
	//ObjectType = CScene__GetObjectTypeFlag(&GetApp()->m_Scene, pThis->ah.ih.m_nObjType) ;
	func_800842CC(&pThis->m_AI, pThis->ah.ih.m_pEA, pThis->m_nTypeFlag);

	// Special case setups
	switch (pThis->m_nTypeFlag)
	{
		case AI_OBJECT_CHARACTER_MANTIS_BOSS:
		case AI_OBJECT_CHARACTER_TREX_BOSS:
		case AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS:
		case AI_OBJECT_CHARACTER_LONGHUNTER_BOSS:
		case AI_OBJECT_CHARACTER_HUMVEE_BOSS:

			// Call boss setup function
			func_8003F804(pThis, pThis->m_nTypeFlag) ;
			break;

		case AI_OBJECT_CINEMA_TUROK_ARROW:
			CCamera__SetObjectToTrack(&GetApp()->m_Camera, pThis) ;

			if (GetApp()->m_WarpID == INTRO_ZOOM_TO_LOGO_WARP_ID)
				pThis->m_pCalculateOrientation = (void *)func_8003A8D0 ;
			break ;

		// Add pickup generator to list
		case AI_OBJECT_DEVICE_PICKUP_GERATOR:
			func_80093694(&GetApp()->m_Scene.m_PickupMonitor, 1, &pThis->ah.ih.m_vPos) ;
			break ;
	}

	if (!CGameObjectInstance__IsDevice(pThis))
	{
		groundHeight = CInstanceHdr__GetGroundHeight(&pThis->ah.ih);
		if ((pThis->ah.ih.m_vPos.y - groundHeight) < 5*SCALING_FACTOR)
			pThis->ah.ih.m_vPos.y = groundHeight;
	}

#endif
}
