#include "decompdecomp_sync_ad04e31fa56b5eacf212.h"
#line 1 "func.c"
#line 9899 "reference.c"
void CGameObjectInstance__DoDraw(CGameObjectInstance *pThis, CAnimDraw *pAnimDraw,
											int nNode, CMtxF mfParent, BOOL OnlyChild)
{
	// these variables are declared static because function
	// is recursive and uses lots of stack space

	static BOOL						blending;
	static void 					*pbNode,
										*pbChildIndices;
	static CMtxF					mfTranslate, mfRotate,
										mfProd1;
	static Mtx						*pmFinal;
	static int						nFrameC, nFrameB,
										nNextFrameC, nNextFrameB;
	static CVector3				vBlendPos, vNextBlendPos, vFinalBlendPos;
	static CQuatern				qBlendRot, qNextBlendRot, qFinalBlendRot,
										qFinalRot;
	static float					fraction;
	static CQuatern				qC, qNextC,
										qB, qNextB,
										qTemp, qXRot, qYRot, qZRot;
	static CVector3				vC, vNextC,
										vB, vNextB;

	static CHeadTrackInfo 		*pHeadTrackInfo;
	static CHeadTrackNodeInfo	*pHeadTrackNodeInfo;
	static BOOL						BigHead;

   // these variables cannot be declared static
	CMtxF								mfFinal;
	CIndexedSet 					isNode;
   CUnindexedSet					usChildIndices;
	DWORD								cChild, nChildren,
										*childIndices;

	ASSERT(pThis->pmtDrawMtxs);

	BigHead = FALSE ;

	blending = CGameObjectInstance__IsBlending(pThis);

	if (    (GetApp()->m_Mode == MODE_GAME)
		  && (GetApp()->m_dwCheatFlags & CHEATFLAG_QUACKMODE) )
		fraction = 0;
	else
		fraction = pThis->m_asCurrent.m_cFrame - ((int) pThis->m_asCurrent.m_cFrame);

	// single node
	pbNode = CIndexedSet__GetAddress(pAnimDraw->pisNodes, nNode);
	D_8002DD28(&isNode, pbNode, FALSE);

	// single node's animation
	if ( 	  (GetApp()->m_Mode == MODE_GAME)
		  && (GetApp()->m_dwCheatFlags & CHEATFLAG_QUACKMODE) )
		nFrameC = max(0, ((int) pThis->m_asCurrent.m_cFrame) & ~1);
	else
		nFrameC = max(0, (int) pThis->m_asCurrent.m_cFrame);

	nNextFrameC = (int) CGameAnimateState__GetNextFrame(&pThis->m_asCurrent);

	qC			= D_80016AF4(pAnimDraw->pisCurrentAnim, nNode, nFrameC);
	qNextC	= D_80016AF4(pAnimDraw->pisCurrentAnim, nNode, nNextFrameC);

	vC			= D_800169E0(pAnimDraw->pisCurrentAnim, nNode, nFrameC);
	vNextC	= D_800169E0(pAnimDraw->pisCurrentAnim, nNode, nNextFrameC);

	if (blending)
	{
		nFrameB = max(0, (int) pThis->m_asBlend.m_cFrame);
		nNextFrameB = (int) CGameAnimateState__GetNextFrame(&pThis->m_asBlend);

		qB			= D_80016AF4(pAnimDraw->pisBlendAnim, nNode, nFrameB);
		qNextB	= D_80016AF4(pAnimDraw->pisBlendAnim, nNode, nNextFrameB);

		vB			= D_800169E0(pAnimDraw->pisBlendAnim, nNode, nFrameB);
		vNextB	= D_800169E0(pAnimDraw->pisBlendAnim, nNode, nNextFrameB);

		CQuatern__Blend(&qBlendRot, pThis->m_uBlender, &qB, &qC);
		CQuatern__Blend(&qNextBlendRot, pThis->m_uBlender, &qNextB, &qNextC);

		CVector3__Blend(&vBlendPos, pThis->m_uBlender, &vB, &vC);
		CVector3__Blend(&vNextBlendPos, pThis->m_uBlender, &vNextB, &vNextC);
	}
	else
	{
		qBlendRot		= qC;
		qNextBlendRot	= qNextC;

		vBlendPos		= vC;
		vNextBlendPos	= vNextC;
	}

	CQuatern__Blend(&qFinalBlendRot, fraction, &qBlendRot, &qNextBlendRot);

	CVector3__Blend(&vFinalBlendPos, fraction, &vBlendPos, &vNextBlendPos);

	// build matrices
	if (nNode)
	{
		// rotation
		if ((pThis == CEngineApp__GetPlayer(GetApp())) && (nNode == 1))
		{
			// hack to rotate minigun and auto-shotgun's barrels
			CQuatern__BuildFromAxisAngle(&qZRot, 0, 1, 0, D_800B6B30);
			CQuatern__Mult(&qFinalRot, &qZRot, &qFinalBlendRot);
		}
		else
		if ((CGameObjectInstance__TypeFlag(pThis) == AI_OBJECT_BUNKER_TURRET) && (nNode == 1))
		{
			CQuatern__BuildFromAxisAngle(&qZRot, 1, 0, 0, pThis->m_HeadTiltAngle) ;
			CQuatern__Mult(&qFinalRot, &qFinalBlendRot, &qZRot);
		}
		else
		if ((CGameObjectInstance__TypeFlag(pThis) == AI_OBJECT_CEILING_TURRET) && (nNode == 1))
		{
			CQuatern__BuildFromAxisAngle(&qZRot, 1, 0, 0, pThis->m_HeadTiltAngle) ;
			CQuatern__Mult(&qFinalRot, &qFinalBlendRot, &qZRot);
		}
		else
		if (CGameObjectInstance__TypeFlag(pThis) == AI_OBJECT_CHARACTER_HUMVEE_BOSS)
		{
			switch (nNode)
			{
				case 12:
					CQuatern__BuildFromAxisAngle(&qZRot, 0, 1, 0, pThis->m_pBoss->m_Rot1) ;
					CQuatern__Mult(&qFinalRot, &qZRot, &qFinalBlendRot);
					break ;

				case 18:
					CQuatern__BuildFromAxisAngle(&qZRot, 0, 1, 0, pThis->m_pBoss->m_Rot2) ;
					CQuatern__Mult(&qFinalRot, &qZRot, &qFinalBlendRot);
					break ;

				case 14:
					CQuatern__BuildFromAxisAngle(&qZRot, 0, 1, 0, pThis->m_pBoss->m_Rot3) ;
					CQuatern__Mult(&qTemp, &qZRot, &qFinalBlendRot);

					// Add steer
					CQuatern__BuildFromAxisAngle(&qZRot, 0, 0, 1, pThis->m_pBoss->m_Rot5) ;
					CQuatern__Mult(&qFinalRot, &qTemp, &qZRot);
					break ;

				case 16:
					CQuatern__BuildFromAxisAngle(&qZRot, 0, 1, 0, pThis->m_pBoss->m_Rot4) ;
					CQuatern__Mult(&qTemp, &qZRot, &qFinalBlendRot);

					// Add steer
					CQuatern__BuildFromAxisAngle(&qZRot, 0, 0, 1, pThis->m_pBoss->m_Rot5) ;
					CQuatern__Mult(&qFinalRot, &qTemp, &qZRot);
					break ;

				default:
					qFinalRot = qFinalBlendRot;
			}
		}
		else
		// Generic head tracking
		if (((pHeadTrackInfo = pThis->m_pHeadTrackInfo)) &&
			(nNode >= pHeadTrackInfo->MinHeadNode) &&	(nNode <= pHeadTrackInfo->MaxHeadNode))
		{
			pHeadTrackNodeInfo = &pHeadTrackInfo->pNodeInfo[nNode - pHeadTrackInfo->MinHeadNode] ;
			fraction = pThis->m_pHeadTrackInfo->MaxHeadNode - pThis->m_pHeadTrackInfo->MinHeadNode + 1 ;

			// Use big head?
			if ((GetApp()->m_Mode == MODE_GAME) &&
				 (GetApp()->m_dwCheatFlags & CHEATFLAG_BIGHEADS) &&
				 (pHeadTrackInfo->MaxHeadNode == nNode))
				BigHead = TRUE ;

			// Create turn angle
			if (pHeadTrackNodeInfo->Flags & TURN_FLIP_DIR)
			{
				CQuatern__BuildFromAxisAngle(&qZRot,
													  ((pHeadTrackNodeInfo->Flags & TURN_AXIS_X) != 0),
													  ((pHeadTrackNodeInfo->Flags & TURN_AXIS_Y) != 0),
													  ((pHeadTrackNodeInfo->Flags & TURN_AXIS_Z) != 0),
													  (-pThis->m_HeadTurnAngle / fraction)) ;
			}
			else
			{
				CQuatern__BuildFromAxisAngle(&qZRot,
													  ((pHeadTrackNodeInfo->Flags & TURN_AXIS_X) != 0),
													  ((pHeadTrackNodeInfo->Flags & TURN_AXIS_Y) != 0),
													  ((pHeadTrackNodeInfo->Flags & TURN_AXIS_Z) != 0),
													  (pThis->m_HeadTurnAngle / fraction)) ;
			}

			// Create tilt angle
			if (pHeadTrackNodeInfo->Flags & TILT_FLIP_DIR)
			{
				CQuatern__BuildFromAxisAngle(&qXRot,
													  ((pHeadTrackNodeInfo->Flags & TILT_AXIS_X) != 0),
													  ((pHeadTrackNodeInfo->Flags & TILT_AXIS_Y) != 0),
													  ((pHeadTrackNodeInfo->Flags & TILT_AXIS_Z) != 0),
													  (-pThis->m_HeadTiltAngle / fraction)) ;
			}
			else
			{
				CQuatern__BuildFromAxisAngle(&qXRot,
													  ((pHeadTrackNodeInfo->Flags & TILT_AXIS_X) != 0),
													  ((pHeadTrackNodeInfo->Flags & TILT_AXIS_Y) != 0),
													  ((pHeadTrackNodeInfo->Flags & TILT_AXIS_Z) != 0),
													  (pThis->m_HeadTiltAngle / fraction)) ;
			}

			// Concatenate rotations
			if (pHeadTrackNodeInfo->Flags & REVERSE_CONCAT)
				CQuatern__Mult(&qFinalRot, &qXRot, &qZRot);
			else
				CQuatern__Mult(&qFinalRot, &qZRot, &qXRot);

			// Blend head tracking with identity
			CQuatern__Identity(&qZRot) ;
			CQuatern__Blend(&qXRot, pThis->m_HeadTrackBlend, &qZRot, &qFinalRot) ;

			// Concatenate onto animation rotation
			CQuatern__Mult(&qFinalRot, &qFinalBlendRot, &qXRot) ;
		}
		else
			qFinalRot = qFinalBlendRot;
	}
	else
	{
  		if (pAnimDraw->RemoveRootXZ)
			vFinalBlendPos.x = vFinalBlendPos.y = 0;

		qFinalRot = qFinalBlendRot;
	}


                       
                                          

                              
                                                              

                                                 

     

	// Using optimized matrix functions
	CQuatern__ToMatrix(&qFinalRot, mfProd1) ;

	// Make head big?
	if (BigHead)
	{
		D_800130DC(mfProd1,
								  pThis->m_pHeadTrackInfo->BigHeadScale,
								  pThis->m_pHeadTrackInfo->BigHeadScale,
								  pThis->m_pHeadTrackInfo->BigHeadScale) ;
	}

	// TEMP
	//if (nNode == 0)
	//	CMtxF__PreMultScale(mfProd1, 1.6, 1.6, 1.6);
	//else
	//	CMtxF__PreMultScale(mfProd1, 0.8, 0.8, 0.8);

	//if (OnlyChild)
	//	CMtxF__PreMultScale(mfProd1, 3,3,3);

	D_8001315C(mfProd1, vFinalBlendPos.x, vFinalBlendPos.y, vFinalBlendPos.z) ;

      

	pmFinal = &(pThis->pmtDrawMtxs[nNode]) ;

	// Only keep track of matrices if swooshes are active on object
	if ((pThis->m_ActiveSwooshes) || (pThis->m_pBoss))
	{
		CMtxF__PostMult(mfFinal, mfProd1, mfParent);

		CMtxF__ToMtx(mfFinal, *pmFinal);

		if (OnlyChild)
		{
			// no need to push matrix on stack if only child
			gSPMatrix((*pAnimDraw->ppDLP)++,
				 		 RSP_ADDRESS(pmFinal),
	   		 		 G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		}
		else
		{
			gSPMatrix((*pAnimDraw->ppDLP)++,
				 		 RSP_ADDRESS(pmFinal),
	   		 		 G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
		}
	}
	else
	{
		CMtxF__ToMtx(mfProd1, *pmFinal);

		if (OnlyChild)
		{
			// no need to push matrix on stack if only child
			gSPMatrix((*pAnimDraw->ppDLP)++,
				 		 RSP_ADDRESS(pmFinal),
	   		 		 G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
		}
		else
		{
			gSPMatrix((*pAnimDraw->ppDLP)++,
				 		 RSP_ADDRESS(pmFinal),
	   		 		 G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
		}
	}


	D_800258D0(&pThis->m_Geometry, pAnimDraw->ppDLP, GetCache(),
							  nNode,
							  D_80016730(pThis, CGameObjectInstance__TypeFlag(pThis), nNode),
							  pAnimDraw->Inter,
                  
              
     
							  pAnimDraw->Better,
      
							  CInstanceHdr__GetTextureIndex(&pThis->ah.ih, pThis->m_nTypeFlag, nNode));

   // recurse on children
   pbChildIndices = CIndexedSet__GetAddress(&isNode, CART_NODE_usChildNodeIndices);

	D_8002DA8C(&usChildIndices, pbChildIndices, FALSE);
   nChildren = CUnindexedSet__GetBlockCount(&usChildIndices);

   childIndices = (DWORD*) CUnindexedSet__GetBasePtr(&usChildIndices);

	// must draw node before drawing children so that only child won't
	// overwrite matrix

	for (cChild=0; cChild<nChildren; cChild++)
	{
		CGameObjectInstance__DoDraw(pThis, pAnimDraw, childIndices[cChild],
											 mfFinal,
											 (nChildren == 1));
	}

	if (!OnlyChild)
		gSPPopMatrix((*pAnimDraw->ppDLP)++, G_MTX_MODELVIEW);

	CIndexedSet__Destruct(&isNode);
	CUnindexedSet__Destruct(&usChildIndices);
}

