#include "decompdecomp_sync_fd6a9a27024ca89033f5.h"
#line 1 "reference.c"
void CGameObjectInstance__AdvanceAccumulation(CGameObjectInstance *pThis)
{
	int				frameC, lastFrameC,
						frameB, lastFrameB,
						nextFrameC, nextLastFrameC,
						nextFrameB, nextLastFrameB;
	CIndexedSet		isCurrentAnim, isBlendAnim;
	void				*pbCRotY, *pbBRotY;
	CUnindexedSet	usCRotY, usBRotY;
	CVector3			vCPos, vCLastPos,
						vCNextPos, vCNextLastPos,
						vBPos, vBLastPos,
						vBNextPos, vBNextLastPos,
						vBlendPos, vLastBlendPos,
						vNextBlendPos, vNextLastBlendPos,
						vDelta, vRotDelta;
	WORD				*pCRotYs, *pBRotYs;
	float				rotBlend, lastRotBlend,
						nextRotBlend, nextLastRotBlend,
						finalRotBlend,
						fraction,
						vA, vB;

#if USE_ORIGINAL_MATRIX
	CMtxF				mfRotate, mfRotY ;
#endif
	CMtxF				mfRotProd ;

	BOOL				blending;

	ASSERT(pThis->m_nAnims);

	blending = CGameObjectInstance__IsBlending(pThis);

	fraction = pThis->m_asCurrent.m_cFrame - ((int) pThis->m_asCurrent.m_cFrame);

	frameC = max(0, (int) pThis->m_asCurrent.m_cFrame);
	lastFrameC = max(0, frameC - 1);

	nextFrameC = (int) CGameAnimateState__GetNextFrame(&pThis->m_asCurrent);
	nextLastFrameC = max(0, nextFrameC - 1);

	if (blending)
	{
		frameB = max(0, (int) pThis->m_asBlend.m_cFrame);
		lastFrameB = max(0, frameB - 1);

		nextFrameB = (int) CGameAnimateState__GetNextFrame(&pThis->m_asBlend);
		nextLastFrameB = max(0, nextFrameB - 1);
	}

	ASSERT(pThis->m_asCurrent.m_pceAnim);
	CIndexedSet__ConstructFromRawData(&isCurrentAnim,
												 CCacheEntry__GetData(pThis->m_asCurrent.m_pceAnim),
												 FALSE);

	if (blending)
	{
		ASSERT(pThis->m_asBlend.m_pceAnim);
		CIndexedSet__ConstructFromRawData(&isBlendAnim,
													 CCacheEntry__GetData(pThis->m_asBlend.m_pceAnim),
													 FALSE);
	}


	// get translation data
	vCPos				= CGameObjectInstance__GetNodePos(&isCurrentAnim, 0, frameC);
	vCLastPos		= CGameObjectInstance__GetNodePos(&isCurrentAnim, 0, lastFrameC);
	vCNextPos		= CGameObjectInstance__GetNodePos(&isCurrentAnim, 0, nextFrameC);
	vCNextLastPos	= CGameObjectInstance__GetNodePos(&isCurrentAnim, 0, nextLastFrameC);

	if (blending)
	{
		vBPos				= CGameObjectInstance__GetNodePos(&isBlendAnim, 0, frameB);
		vBLastPos		= CGameObjectInstance__GetNodePos(&isBlendAnim, 0, lastFrameB);
		vBNextPos		= CGameObjectInstance__GetNodePos(&isBlendAnim, 0, nextFrameB);
		vBNextLastPos	= CGameObjectInstance__GetNodePos(&isBlendAnim, 0, nextLastFrameB);
	}

	// calculate translation
	if (blending)
	{
		CVector3__Blend(&vBlendPos, pThis->m_uBlender, &vBPos, &vCPos);
		CVector3__Blend(&vLastBlendPos, pThis->m_uBlender, &vBLastPos, &vCLastPos);

		CVector3__Blend(&vNextBlendPos, pThis->m_uBlender, &vBNextPos, &vCNextPos);
		CVector3__Blend(&vNextLastBlendPos, pThis->m_uBlender, &vBNextLastPos, &vCNextLastPos);
	}
	else
	{
		vBlendPos = vCPos;
		vLastBlendPos = vCLastPos;

		vNextBlendPos = vCNextPos;
		vNextLastBlendPos = vCNextLastPos;
	}


/*
	// collision offset based on root node movement (z axis up and down in 3ds space)
	pThis->ah.ih.m_CollisionHeightOffset = vBlendPos.z*pThis->m_vScale.y;

	if (pThis->m_AI.m_Health > 0)
		pThis->ah.ih.m_CollisionHeightOffset -= pThis->ah.ih.m_pEA->m_CollisionHeight/2;
	else
		pThis->ah.ih.m_CollisionHeightOffset -= pThis->ah.ih.m_pEA->m_DeadHeight/2;

	if ((pThis->ah.ih.m_CollisionHeightOffset < 0) && (CInstanceHdr__IsOnGround(&pThis->ah.ih)))
		pThis->ah.ih.m_CollisionHeightOffset = 0;
*/
	// collision offset based on root node movement (z axis up and down in 3ds space)
	pThis->ah.ih.m_CollisionHeightOffset = vBlendPos.z*pThis->m_vScale.y;
	pThis->ah.ih.m_CollisionHeightOffset -= pThis->ah.ih.m_pEA->m_CollisionHeight*(3.0/5.0);
	if (pThis->ah.ih.m_CollisionHeightOffset < 0)
		pThis->ah.ih.m_CollisionHeightOffset = 0;

	// get rotation data
	pbCRotY = CIndexedSet__GetAddress(&isCurrentAnim, CART_ANIM_usYRotations);
	CUnindexedSet__ConstructFromRawData(&usCRotY, pbCRotY, FALSE);

	pCRotYs = (WORD*) CUnindexedSet__GetBasePtr(&usCRotY);
	ASSERT(frameC < CUnindexedSet__GetBlockCount(&usCRotY));
	ASSERT(nextFrameC < CUnindexedSet__GetBlockCount(&usCRotY));

	if (blending)
	{
		pbBRotY = CIndexedSet__GetAddress(&isBlendAnim, CART_ANIM_usYRotations);
		CUnindexedSet__ConstructFromRawData(&usBRotY, pbBRotY, FALSE);

		pBRotYs = (WORD*) CUnindexedSet__GetBasePtr(&usBRotY);
		ASSERT(frameB < CUnindexedSet__GetBlockCount(&usBRotY));
		ASSERT(nextFrameB < CUnindexedSet__GetBlockCount(&usBRotY));
	}

	// calculate rotation
	if (blending)
	{
		rotBlend = BlendRotFLOAT(pThis->m_uBlender, INT162FLOAT(pBRotYs[frameB], ANGLE_PI), INT162FLOAT(pCRotYs[frameC], ANGLE_PI));
		lastRotBlend = BlendRotFLOAT(pThis->m_uBlender, INT162FLOAT(pBRotYs[lastFrameB], ANGLE_PI), INT162FLOAT(pCRotYs[lastFrameC], ANGLE_PI));

		nextRotBlend = BlendRotFLOAT(pThis->m_uBlender, INT162FLOAT(pBRotYs[nextFrameB], ANGLE_PI), INT162FLOAT(pCRotYs[nextFrameC], ANGLE_PI));
		nextLastRotBlend = BlendRotFLOAT(pThis->m_uBlender, INT162FLOAT(pBRotYs[nextLastFrameB], ANGLE_PI), INT162FLOAT(pCRotYs[nextLastFrameC], ANGLE_PI));
	}
	else
	{
		rotBlend = INT162FLOAT(pCRotYs[frameC], ANGLE_PI);
		lastRotBlend = INT162FLOAT(pCRotYs[lastFrameC], ANGLE_PI);

		nextRotBlend = INT162FLOAT(pCRotYs[nextFrameC], ANGLE_PI);
		nextLastRotBlend = INT162FLOAT(pCRotYs[nextLastFrameC], ANGLE_PI);
	}

	// blend values for accumulated interpolations between animation frames
	vA = max(0, D_800B6B00 - fraction);
	vB = min(D_800B6B00, fraction);

	//TRACE4("vA:%f, vB:%f inc:%f, frac:%f\r\n", vA, vB, frame_increment, fraction);

	//finalRotBlend = (vA * (rotBlend - lastRotBlend)) + (vB * (nextRotBlend - nextLastRotBlend));
	finalRotBlend = vA*RotDifference(rotBlend, lastRotBlend) + vB*RotDifference(nextRotBlend, nextLastRotBlend);
	pThis->m_RotY -= finalRotBlend;
	NormalizeRotation(&pThis->m_RotY);

// DIDN'T WORK!
/*
	// prevent snapping
	if (blending)
	{
		if (CGameObjectInstance__IsFirstBlendFrame(pThis))
		{
			CGameObjectInstance__SetNotFirstBlendFrame(pThis);

			// decide to blend to right or to left
			if (RotDifference(INT162FLOAT(pBRotYs[frameB], ANGLE_PI), INT162FLOAT(pCRotYs[frameC], ANGLE_PI)) > 0)
				CGameObjectInstance__SetBlendingToRight(pThis);
			else
				CGameObjectInstance__SetNotBlendingToRight(pThis);
		}

		if ((RotDifference(pThis->m_RotY, INT162FLOAT(pCRotYs[frameC], ANGLE_PI)) > 0) ^ (CGameObjectInstance__IsBlendingToRight(pThis) != 0))
		{
			// do 180 flip if it's blending the wrong way
			if (pThis->m_RotY > 0)
				pThis->m_RotY -= ANGLE_PI;
			else
				pThis->m_RotY += ANGLE_PI;
		}
	}
*/

	// don't accumulate Y axis
	// use Y for Z to switch from 3D Studio coordinate system

	// TEMP
	if (		(AI_GetEA(pThis)->m_dwTypeFlags & AI_TYPE_SNIPER)
			&&	(pThis->m_AI.m_Health > 0) )
	{
		vDelta.x = 0;
		vDelta.y = 0;
		vDelta.z = 0;
	}
	else
	{
		vDelta.x = (vA * (vBlendPos.x - vLastBlendPos.x)) + (vB * (vNextBlendPos.x - vNextLastBlendPos.x));
		vDelta.y = 0;
		vDelta.z = (vA * (vBlendPos.y - vLastBlendPos.y)) + (vB * (vNextBlendPos.y - vNextLastBlendPos.y));
	}

	// rotate delta
#if USE_ORIGINAL_MATRIX
	CQuatern__ToMatrix(&pThis->m_qRot, mfRotate);
	CMtxF__RotateY(mfRotY, pThis->m_RotY) ;
	CMtxF__PostMult(mfRotProd, mfRotY, mfRotate);
#else
	// Use optimized matrix functions
	CQuatern__ToMatrix(&pThis->m_qRot, mfRotProd) ;
	CMtxF__PreMultRotateY(mfRotProd, pThis->m_RotY) ;
#endif

	CMtxF__VectorMult(mfRotProd, &vDelta, &vRotDelta);

	// make sure there is still no Y change
	pThis->ah.ih.m_vPos.x += vRotDelta.x * pThis->m_vScale.x;
	pThis->ah.ih.m_vPos.z += vRotDelta.z * pThis->m_vScale.z;


	CIndexedSet__Destruct(&isCurrentAnim);
	CUnindexedSet__Destruct(&usCRotY);
	if (blending)
	{
		CIndexedSet__Destruct(&isBlendAnim);
		CUnindexedSet__Destruct(&usBRotY);
	}
}
