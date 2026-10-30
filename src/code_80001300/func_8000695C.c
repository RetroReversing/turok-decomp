#include "common_local_source_3712.h"

#line 1 "reference.c"
void func_8000695C(CEngineApp *pThis)
{
	CGameObjectInstance	*pPlayer;
	t_Ears					ears;
	float						newY, newYSQ;
	CROMRegionSet			*pRegionSet;
	BOOL						keepInSphere;


	pPlayer = CEngineApp__GetPlayer(pThis);
	if (!pPlayer)
		return;

	pRegionSet = func_8002E438(&pThis->m_Scene, pPlayer->ah.ih.m_pCurrentRegion) ;

	if (func_80039B98(&pThis->m_Camera))
	{
		keepInSphere = TRUE;
	}
	else
	{
		if (pRegionSet)
			keepInSphere = (pRegionSet->m_dwFlags & REGFLAG_FALLDEATH);
		else
			keepInSphere = FALSE;
	}

	pThis->m_YPos = pPlayer->ah.ih.m_vPos.y;

	// let it crash in some cases so player won't get stuck
	if (keepInSphere)
	{
		// deal with problems if player goes out of bounds
		if (CVector3__MagnitudeSquared(&pPlayer->ah.ih.m_vPos) > SQR(WORLD_LIMIT))
		{
			newYSQ = SQR(WORLD_LIMIT) - SQR(pPlayer->ah.ih.m_vPos.x) - SQR(pPlayer->ah.ih.m_vPos.z);
			newY = sqrt(max(0, newYSQ));

			pPlayer->ah.ih.m_vPos.y = (pPlayer->ah.ih.m_vPos.y < 0) ? -newY : newY;

			if (pRegionSet->m_dwFlags & REGFLAG_FALLDEATH)
			{
				pThis->m_YPos = pPlayer->ah.ih.m_vPos.y;

				pPlayer->ah.ih.m_vPos.y = CInstanceHdr__GetGroundHeight(&pPlayer->ah.ih) - 1.0;
			}
			else
			{
				pThis->m_YPos = pPlayer->ah.ih.m_vPos.y;
			}
		}
	}


	// set camera to this instance
	pThis->m_XPos 		= pPlayer->ah.ih.m_vPos.x;
	pThis->m_ZPos 		= pPlayer->ah.ih.m_vPos.z;
	pThis->m_RotY		= pPlayer->m_RotY;
	pThis->m_qGround	= pPlayer->m_qGround;

	// sound position
//	ears.vPos.x = pThis->m_XPos;
//	ears.vPos.y = pThis->m_YPos;
//	ears.vPos.z = pThis->m_ZPos;
//	ears.YRot = pPlayer->m_RotY;

	// Get ears from camera so pause menu and title menu work properly
	ears.vPos = pThis->m_Camera.m_vPos ;
	ears.YRot = pThis->m_Camera.m_vRotation.y ;

	ears.Radius = SCALING_MAX_DIST(pThis->m_FarClip, FIELD_OF_VIEW_ANGLE(pThis->m_FieldOfView, SCREEN_WD/SCREEN_HT));

	func_8008B45C(&ears);
}
