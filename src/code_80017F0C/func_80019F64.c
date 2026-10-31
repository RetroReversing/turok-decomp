#include "source_func_80019F64.h"
#line 1 "func.c"
#line 1 "reference.c"
void func_80019F64(CGameObjectInstance *pThis, Gfx **ppDLP, CVector3 *pvOffset)
{
#if USE_ORIGINAL_MATRIX
	CMtxF			mfPos, mfScale,
					mfTemp1, mfTemp2;
#endif
	CMtxF			mfRotate ;
	CVector3		vTranslate;

	float			raise, radius, groundHeight, height;
	Mtx			*pmShadow;
	BOOL			drawShadow, isPlayer;
	BYTE			shadowTransparency;
	int			duckFlag;

	isPlayer = (pThis == CEngineApp__GetPlayer(GetApp()));

	drawShadow = TRUE;
	if (func_80019ED8(pThis->ah.ih.m_pCurrentRegion))
		drawShadow = FALSE;

	if (		(pThis->ah.ih.m_pCurrentRegion)
			&&	(pThis->ah.ih.m_pCurrentRegion->m_wFlags & REGFLAG_FALLDEATH) )
		drawShadow = FALSE;

	if (!(pThis->ah.ih.m_pEA->m_dwTypeFlags & AI_TYPE_SHADOW))
		drawShadow = FALSE;

	if ((isPlayer) && (GetApp()->m_Camera.m_CinemaMode))
		drawShadow = FALSE;


	if (drawShadow)
	{
		// Allocate mtx table
		pmShadow = func_800356E0(1) ;
		if (!pmShadow)
			return;

		//if (pThis->m_dwFlags & ANIM_INSTANCE_NEAREDGE)
		//	groundHeight = pThis->ah.ih.m_vPos.y;
		//else
		//groundHeight = CInstanceHdr__GetGroundHeight(&pThis->ah.ih);
		groundHeight = func_80019D3C(pThis->ah.ih.m_pCurrentRegion,
																  pThis->ah.ih.m_vPos.x + pvOffset->x,
																  pThis->ah.ih.m_vPos.z + pvOffset->z);
		//rmonPrintf("groundHeight:%f\n", groundHeight);


		height = pThis->ah.ih.m_vPos.y + pThis->ah.ih.m_CollisionHeightOffset - groundHeight;
		radius = max(0, min(pThis->ah.ih.m_pEA->m_CollisionRadius, pThis->ah.ih.m_pEA->m_CollisionRadius - height*0.1));

		// raise shadow a bit above ground to avoid problems
		//if (pThis->m_dwFlags & ANIM_INSTANCE_NEAREDGE)
		//{
		//	raise = 0;
		//
		//	// TEMP
		//	raise += 0.5;
		//}
		//else
		//{
		if (isPlayer)
		{
			raise = 1.5*SCALING_FACTOR;
			radius *= 0.5;
		}
		else
		{
			raise = 0;
			radius *= 0.7;
		}
		//}

		vTranslate.x = pThis->ah.ih.m_vPos.x + pvOffset->x;
		vTranslate.z = pThis->ah.ih.m_vPos.z + pvOffset->z;
		vTranslate.y = groundHeight + raise + + pvOffset->y;
		func_80013DC8(&vTranslate, WORLD_LIMIT);

#if USE_ORIGINAL_MATRIX
		func_80014DC4(&pThis->m_qShadow, mfRotate);
		CMtxF__Scale(mfScale, radius, 1, radius);
		CMtxF__Translate(mfPos, vTranslate.x, vTranslate.y, vTranslate.z);
		func_80013224(mfTemp1, mfScale, mfRotate);
		func_80013224(mfTemp2, mfTemp1, mfPos);
		CMtxF__ToMtx(mfTemp2, *pmShadow);

#else
		// Optimized matrix version
		func_80014DC4(&pThis->m_qShadow, mfRotate);
		func_800130DC(mfRotate, radius, 1, radius);
		func_8001315C(mfRotate, vTranslate.x, vTranslate.y, vTranslate.z);
		CMtxF__ToMtx(mfRotate, *pmShadow);
#endif

		// calc shadow transparency value
		if (pThis->m_AI.m_cRegenerateAppearance)
			shadowTransparency = (BYTE) max(0, min(255, (1 - pThis->m_AI.m_cRegenerateAppearance/APPEARANCE_LENGTH)*(200 - height*(isPlayer ? (9/SCALING_FACTOR) : (12.5/SCALING_FACTOR)))));
		else
			//shadowTransparency = (BYTE) max(0, min(255, (1 - pThis->m_cMelt/MELT_LENGTH)*(200 - height*(isPlayer ? (9/SCALING_FACTOR) : (12.5/SCALING_FACTOR)))));
			shadowTransparency = (BYTE) max(0, min(255, (1 - pThis->m_cMelt/MELT_LENGTH)*(200 - height*(12.5/SCALING_FACTOR))));


		// if player is in ducking region remove make the shadow completely transparent
		duckFlag = func_80002A8C(GetApp());
		if (    (duckFlag == PLAYER_DUCKING)
			  || (duckFlag == PLAYER_DUCKING_ENTRANCE_EXIT) )
		{
			pThis->m_ShadowPercentage = 0;
		}
		else
		{
			pThis->m_ShadowPercentage += D_800B6B00*10;
			pThis->m_ShadowPercentage  = min(100.0, pThis->m_ShadowPercentage);
		}

		shadowTransparency = (BYTE)(((float)shadowTransparency) * pThis->m_ShadowPercentage / 100.0);

		D_8002383C(ppDLP, pmShadow, !isPlayer, shadowTransparency);
	}
}

