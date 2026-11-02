#include "decompdecomp_sync_c049d800432cfb3be9d4.h"
#line 1 "func.c"
#line 1 "reference.c"
void func_8001BAAC(CGameObjectInstance *pThis) { int					nTransitionAnim;
 CIndexedSet isAnimsIndex;
 ROMAddress *rpAnimAddress;
 DWORD animSize;
 float					fraction, u,
               
            
      
prevBlend;
 CVector3 vOldPos, vDesiredPos;
 CQuatern qNewGround;
 BOOL					collided, player, onGround, nearWater, pressurePlate;
 CCollisionInfo2	*pCI;
 CROMRegionSet		*pRegionSet;
  ASSERT((DWORD) pThis >= 0x80000000);
 ASSERT((DWORD) pThis <= 0x84000000);
  ASSERT((DWORD) (&pThis->m_AI) >= 0x80000000);
 ASSERT((DWORD) (&pThis->m_AI) <= 0x84000000);
   if ((GetApp()->m_bPause) || (GetApp()->m_bTraining)) return ;
    if (pThis->m_WaitingForAnim == -1) {    ASSERT(pThis->m_nDesiredAnim >= 0);
 CGameAnimateState__SetDesiredAnim(&pThis->m_asCurrent, pThis->m_nDesiredAnim);
  nTransitionAnim = func_80037564(&pThis->m_asCurrent);
  if (nTransitionAnim != -1) {   ASSERT(nTransitionAnim >= 0);
 ASSERT(nTransitionAnim < pThis->m_nAnims);
   if (nTransitionAnim != pThis->m_nDesiredAnim) pThis->m_AI.m_dwStatusFlags &= ~AI_WAITFOR_CYCLE;
  pThis->m_asBlend = pThis->m_asCurrent;
  CGameObjectInstance__SetNotBlending(pThis);
 pThis->m_WaitingForAnim	= nTransitionAnim;
     CIndexedSet__ConstructFromRawData(&isAnimsIndex, CCacheEntry__GetData(pThis->m_pceAnimsIndex), FALSE);
   rpAnimAddress = func_8002DBF8(&isAnimsIndex, pThis->m_rpAnims, nTransitionAnim, &animSize);
   func_8002D1F8(GetCache(), pThis, (pfnCACHENOTIFY) func_800365F0, (pfnCACHENOTIFY) func_800183C4, &pThis->m_asCurrent.m_pceAnim, rpAnimAddress, animSize, D_800F0E4C);
  CIndexedSet__Destruct(&isAnimsIndex);
 }  if (CGameObjectInstance__IsBlending(pThis)) { pThis->m_BlendPos += D_800B6B00;
  if (pThis->m_BlendPos > pThis->m_BlendLength) { TRACE0("CGameObjectInstance: End blend.\r\n");
  CGameObjectInstance__SetNotBlending(pThis);
 } else { u = pThis->m_BlendPos / ((pThis->m_BlendLength)+D_800B6B00);
  pThis->m_uBlender = GetHermiteBlender(pThis->m_BlendStart, pThis->m_BlendFinish, u);
  func_80037394(&pThis->m_asBlend);
 } }  func_80037394(&pThis->m_asCurrent);
   if (pThis->m_WaitingForAnim != -1) { pThis->m_asBlend = pThis->m_asCurrent;
 } else {  fraction = pThis->m_asCurrent.m_cFrame - ((int) pThis->m_asCurrent.m_cFrame);
   if (fraction < 0) fraction = 0;
  prevBlend = pThis->m_asBlend.m_cFrame;
 pThis->m_asBlend.m_cFrame = ((int) pThis->m_asBlend.m_cFrame) + fraction;
   if (((int) pThis->m_asBlend.m_cFrame) > ((int) prevBlend)) {
               
                                          

      
pThis->m_asCurrent.m_cFrame = max(0, pThis->m_asCurrent.m_cFrame - 0.01);
 pThis->m_asBlend.m_cFrame = max(0, pThis->m_asBlend.m_cFrame - 0.01);
  ASSERT(((int) pThis->m_asCurrent.m_cFrame) == ((int) prevCurrent));
 ASSERT(((int) pThis->m_asBlend.m_cFrame) == ((int) prevBlend));
 } } } else {   ASSERT(!CGameObjectInstance__IsBlending(pThis));
   func_80037394(&pThis->m_asCurrent);
  pThis->m_asBlend = pThis->m_asCurrent;
 }  if (!(CGameObjectInstance__IsDevice(pThis) || func_80018274(pThis, pThis->m_asCurrent.m_nAnim))) { player = (pThis == CEngineApp__GetPlayer(GetApp()));
 onGround = func_8001BA24(&pThis->ah.ih);
 if ((!player) || (func_80039B98(&GetApp()->m_Camera))) { vOldPos = pThis->ah.ih.m_vPos;
   if (		(D_800B6B00 != 0) &&	(!(pThis->m_AI.m_dwStatusFlags & AI_ALREADY_DEAD)) && (!(pThis->m_AI.m_dwStatusFlags & (s32)AI_INTERACTIVEANIMATION)) && (!(pThis->m_AI.m_dwStatusFlags & AI_INTERANIMDELAY)) &&	(GetApp()->m_Mode != MODE_GALLERY) ) { func_8001B1C0(pThis);
 }  vDesiredPos = pThis->ah.ih.m_vPos;
 pThis->ah.ih.m_vPos = vOldPos;
  pCI = func_8001AFDC(pThis);
 func_8009C5D0(pCI);
   collided = FALSE;
 if (D_800B6B00 != 0) { if (		(!(pThis->m_AI.m_dwStatusFlags & AI_INTERACTIVEANIMATION)) && (!(pThis->m_AI.m_dwStatusFlags & AI_INTERANIMDELAY)) ) { collided = func_8009A4D8(&pThis->ah, vDesiredPos, pCI);
 }   if (pThis->m_pCollisionFunction) pThis->m_pCollisionFunction(pThis, pCI);
 }   if (collided && (pCI->pInstanceCollision != &(CEngineApp__GetPlayer(GetApp())->ah.ih))) pThis->m_AI.m_dwStatusFlags |= AI_COLLISION;
 else pThis->m_AI.m_dwStatusFlags &= (~AI_COLLISION);
  ASSERT(((DWORD)pThis) > 0x80000000);
 if (pThis->ah.ih.m_pCurrentRegion) ASSERT(((DWORD)pThis->ah.ih.m_pCurrentRegion) > 0x80000000);
  pRegionSet = func_8002E438(&GetApp()->m_Scene, pThis->ah.ih.m_pCurrentRegion);
 if (pRegionSet) { if (pRegionSet->m_dwFlags & REGFLAG_PRESSUREPLATE) { if (pRegionSet->m_dwFlags & REGFLAG_PRESSUREPLATENEEDSCOLLISION) pressurePlate = (BOOL) pCI->pWallCollisionRegion;
 else pressurePlate = TRUE;
  if (pressurePlate && (AI_GetEA(pThis)->m_dwTypeFlags & AI_TYPE_USEPRESSUREPLATES)) { func_80070DA8(&pThis->ah.ih, &pThis->ah.ih, AI_MEVENT_PRESSUREPLATE, AI_SPECIES_ALL, pThis->ah.ih.m_vPos, (float) pRegionSet->m_PressureID);
 } } } }  if (pThis->ah.ih.m_pCurrentRegion) { qNewGround = func_8001ABB8(&pThis->ah.ih);
    CQuatern__Blend(&pThis->m_qShadow, min(1, D_800F1418*D_800B6B00), &pThis->m_qShadow, &qNewGround);
    nearWater = FALSE;
 if (pThis->ah.ih.m_pCurrentRegion->m_wFlags & REGFLAG_HASWATER) nearWater = TRUE;
  if (pThis->ah.ih.m_pEA->m_dwTypeFlags & AI_TYPE_TRACKGROUND) { if (nearWater) CQuatern__Identity(&qNewGround);
  if (player) { if (		(!(pThis->m_dwFlags & ANIM_INSTANCE_HANGINGON) && onGround && D_800B6B34) || nearWater ) { func_800148B8(&pThis->m_qGround, &qNewGround);
 } } else { if (onGround && !(pThis->m_dwFlags & ANIM_INSTANCE_HANGINGON)) { CQuatern__Blend(&pThis->m_qGround, min(1, NEWGROUNDROT_FACTOR*D_800B6B00), &pThis->m_qGround, &qNewGround);
 } else { CQuatern__Blend(&pThis->m_qGround, min(1, D_800F1420*D_800B6B00), &pThis->m_qGround, &qNewGround);
 } } } } } }
