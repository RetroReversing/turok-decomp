#include "source_func_8001B1C0.h"
#line 1 "func.c"
#line 1 "reference.c"
void func_8001B1C0(CGameObjectInstance *pThis) { int				frameC, lastFrameC, frameB, lastFrameB, nextFrameC, nextLastFrameC, nextFrameB, nextLastFrameB;
 CIndexedSet		isCurrentAnim, isBlendAnim;
 void				*pbCRotY, *pbBRotY;
 CUnindexedSet	usCRotY, usBRotY;
 CVector3			vCPos, vCLastPos, vCNextPos, vCNextLastPos, vBPos, vBLastPos, vBNextPos, vBNextLastPos, vBlendPos, vLastBlendPos, vNextBlendPos, vNextLastBlendPos, vDelta, vRotDelta;
 WORD				*pCRotYs, *pBRotYs;
 float				rotBlend, lastRotBlend, nextRotBlend, nextLastRotBlend, finalRotBlend, fraction, vA, vB;
 
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
  nextFrameC = (int) func_800374D8(&pThis->m_asCurrent);
 nextLastFrameC = max(0, nextFrameC - 1);
  if (blending) { frameB = max(0, (int) pThis->m_asBlend.m_cFrame);
 lastFrameB = max(0, frameB - 1);
  nextFrameB = (int) func_800374D8(&pThis->m_asBlend);
 nextLastFrameB = max(0, nextFrameB - 1);
 }  ASSERT(pThis->m_asCurrent.m_pceAnim);
 CIndexedSet__ConstructFromRawData(&isCurrentAnim, CCacheEntry__GetData(pThis->m_asCurrent.m_pceAnim), FALSE);
  if (blending) { ASSERT(pThis->m_asBlend.m_pceAnim);
 CIndexedSet__ConstructFromRawData(&isBlendAnim, CCacheEntry__GetData(pThis->m_asBlend.m_pceAnim), FALSE);
 }    vCPos				= func_800169E0(&isCurrentAnim, 0, frameC);
 vCLastPos		= func_800169E0(&isCurrentAnim, 0, lastFrameC);
 vCNextPos		= func_800169E0(&isCurrentAnim, 0, nextFrameC);
 vCNextLastPos	= func_800169E0(&isCurrentAnim, 0, nextLastFrameC);
  if (blending) { vBPos				= func_800169E0(&isBlendAnim, 0, frameB);
 vBLastPos		= func_800169E0(&isBlendAnim, 0, lastFrameB);
 vBNextPos		= func_800169E0(&isBlendAnim, 0, nextFrameB);
 vBNextLastPos	= func_800169E0(&isBlendAnim, 0, nextLastFrameB);
 }   if (blending) { func_800141A8(&vBlendPos, pThis->m_uBlender, &vBPos, &vCPos);
 func_800141A8(&vLastBlendPos, pThis->m_uBlender, &vBLastPos, &vCLastPos);
  func_800141A8(&vNextBlendPos, pThis->m_uBlender, &vBNextPos, &vCNextPos);
 func_800141A8(&vNextLastBlendPos, pThis->m_uBlender, &vBNextLastPos, &vCNextLastPos);
 } else { vBlendPos = vCPos;
 vLastBlendPos = vCLastPos;
  vNextBlendPos = vCNextPos;
 vNextLastBlendPos = vCNextLastPos;
 }     pThis->ah.ih.m_CollisionHeightOffset = vBlendPos.z*pThis->m_vScale.y;
 pThis->ah.ih.m_CollisionHeightOffset -= pThis->ah.ih.m_pEA->m_CollisionHeight*(3.0/5.0);
 if (pThis->ah.ih.m_CollisionHeightOffset < 0) pThis->ah.ih.m_CollisionHeightOffset = 0;
   pbCRotY = CIndexedSet__GetBlock(&isCurrentAnim, CART_ANIM_usYRotations);
 func_8002DA8C(&usCRotY, pbCRotY, FALSE);
  pCRotYs = (WORD*) CUnindexedSet__GetBasePtr(&usCRotY);
 ASSERT(frameC < CUnindexedSet__GetBlockCount(&usCRotY));
 ASSERT(nextFrameC < CUnindexedSet__GetBlockCount(&usCRotY));
  if (blending) { pbBRotY = CIndexedSet__GetBlock(&isBlendAnim, CART_ANIM_usYRotations);
 func_8002DA8C(&usBRotY, pbBRotY, FALSE);
  pBRotYs = (WORD*) CUnindexedSet__GetBasePtr(&usBRotY);
 ASSERT(frameB < CUnindexedSet__GetBlockCount(&usBRotY));
 ASSERT(nextFrameB < CUnindexedSet__GetBlockCount(&usBRotY));
 }   if (blending) { rotBlend = func_800136C8(pThis->m_uBlender, INT162FLOAT(pBRotYs[frameB], ANGLE_PI), INT162FLOAT(pCRotYs[frameC], ANGLE_PI));
 lastRotBlend = func_800136C8(pThis->m_uBlender, INT162FLOAT(pBRotYs[lastFrameB], ANGLE_PI), INT162FLOAT(pCRotYs[lastFrameC], ANGLE_PI));
  nextRotBlend = func_800136C8(pThis->m_uBlender, INT162FLOAT(pBRotYs[nextFrameB], ANGLE_PI), INT162FLOAT(pCRotYs[nextFrameC], ANGLE_PI));
 nextLastRotBlend = func_800136C8(pThis->m_uBlender, INT162FLOAT(pBRotYs[nextLastFrameB], ANGLE_PI), INT162FLOAT(pCRotYs[nextLastFrameC], ANGLE_PI));
 } else { rotBlend = INT162FLOAT(pCRotYs[frameC], ANGLE_PI);
 lastRotBlend = INT162FLOAT(pCRotYs[lastFrameC], ANGLE_PI);
  nextRotBlend = INT162FLOAT(pCRotYs[nextFrameC], ANGLE_PI);
 nextLastRotBlend = INT162FLOAT(pCRotYs[nextLastFrameC], ANGLE_PI);
 }   vA = max(0, D_800B6B00 - fraction);
 vB = min(D_800B6B00, fraction);
     finalRotBlend = vA*func_80013620(rotBlend, lastRotBlend) + vB*func_80013620(nextRotBlend, nextLastRotBlend);
 pThis->m_RotY -= finalRotBlend;
 func_80013588(&pThis->m_RotY);
         if (		(AI_GetEA(pThis)->m_dwTypeFlags & AI_TYPE_SNIPER) &&	(pThis->m_AI.m_Health > 0) ) { vDelta.x = 0;
 vDelta.y = 0;
 vDelta.z = 0;
 } else { vDelta.x = (vA * (vBlendPos.x - vLastBlendPos.x)) + (vB * (vNextBlendPos.x - vNextLastBlendPos.x));
 vDelta.y = 0;
 vDelta.z = (vA * (vBlendPos.y - vLastBlendPos.y)) + (vB * (vNextBlendPos.y - vNextLastBlendPos.y));
 }  
#if USE_ORIGINAL_MATRIX
func_80014DC4(&pThis->m_qRot, mfRotate);
 func_80012E6C(mfRotY, pThis->m_RotY) ;
 func_80013224(mfRotProd, mfRotY, mfRotate);

#else
 func_80014DC4(&pThis->m_qRot, mfRotProd) ;
 func_80012B90(mfRotProd, pThis->m_RotY) ;

#endif
 func_80015754(mfRotProd, &vDelta, &vRotDelta);
   pThis->ah.ih.m_vPos.x += vRotDelta.x * pThis->m_vScale.x;
 pThis->ah.ih.m_vPos.z += vRotDelta.z * pThis->m_vScale.z;
   CIndexedSet__Destruct(&isCurrentAnim);
 CUnindexedSet__Destruct(&usCRotY);
 if (blending) { CIndexedSet__Destruct(&isBlendAnim);
 CUnindexedSet__Destruct(&usBRotY);
 } }
