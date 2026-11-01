#include "decompdecomp_sync_d3ee1c511da3452560d4.h"
#line 1 "func.c"
#line 2046 "reference.c"
void func_8001F4E0(CGameStaticInstance *pThis, CROMEfficientStaticInstance *pSource,
																				 ROMAddress *rpObjectAddress,
																				 CGameRegion Regions[], CEnemyAttributes Variations[],
																				 float GridDistance)
{
                       
                        
                         
      

	CMtxF		mfRotate ;
	CVector3	vPos;
	float		theta;

	pThis->ih.m_Type = I_STATIC;
	pThis->ih.m_nObjType = pSource->m_nObjType;
	pThis->ih.m_bActiveFlags = pSource->m_bActiveFlags;

	pThis->m_rpObjectIndexAddress = rpObjectAddress;

	if (pSource->m_nVariation == (WORD) -1)
		pThis->ih.m_pEA = NULL;
	else
		pThis->ih.m_pEA = &Variations[pSource->m_nVariation];

	vPos.x = pSource->m_nPosX*GridDistance;
	if (pSource->m_bFlags & EFFICIENT_FLAGS_POSX_NEG)
		vPos.x = -vPos.x;
	vPos.z = pSource->m_nPosZ*GridDistance;
	if (pSource->m_bFlags & EFFICIENT_FLAGS_POSZ_NEG)
		vPos.z = -vPos.z;
	vPos.y = pSource->m_nPosY*(EFFICIENT_Y_ACCURACY*SCALING_FACTOR);

	//CVector3__Clamp(&vPos, WORLD_LIMIT);

	pThis->m_Bounds.m_vMin.x = vPos.x + pSource->m_nMinX*SCALING_FACTOR;
	pThis->m_Bounds.m_vMin.y = vPos.y + pSource->m_nMinY*SCALING_FACTOR;
	pThis->m_Bounds.m_vMin.z = vPos.z + pSource->m_nMinZ*SCALING_FACTOR;

	pThis->m_Bounds.m_vMax.x = vPos.x + pSource->m_nMaxX*SCALING_FACTOR;
	pThis->m_Bounds.m_vMax.y = vPos.y + pSource->m_nMaxY*SCALING_FACTOR;
	pThis->m_Bounds.m_vMax.z = vPos.z + pSource->m_nMaxZ*SCALING_FACTOR;

	switch (pSource->m_bFlags & EFFICIENT_ROT_MASK)
	{
		case EFFICIENT_ROT_0:	theta = ANGLE_DTOR(0);		break;
		case EFFICIENT_ROT_90:	theta = ANGLE_DTOR(90);		break;
		case EFFICIENT_ROT_180:	theta = ANGLE_DTOR(180);	break;
		case EFFICIENT_ROT_270:	theta = ANGLE_DTOR(270);	break;
		default:						ASSERT(FALSE);					break;
	}

                       
                                
                                                                             
                                  
                                                 

                                             
                                          

                                              

     

     
                            
                                  
                                                                                     
                                                            
                                               
      

	// Optimized matrix version 2 with fixed point translation
	CMtxF__RotateY(mfRotate, theta) ;
	CMtxF__PreMultScale(mfRotate, pSource->m_Scale, pSource->m_Scale, pSource->m_Scale) ;
	CMtxF__PostMultTranslate(mfRotate, vPos.x, vPos.y, vPos.z);
	CMtxF__ToMtx(mfRotate, pThis->m_mOrientation);
	//CMtxF__ToMtxPostMultTranslate(mfRotate, &(pThis->m_mOrientation), vPos.x, vPos.y, vPos.z);

      


	pThis->ih.m_vPos = vPos;
	pThis->ih.m_CollisionHeightOffset = 0;

	if (ORDERBYTES(pSource->m_nCurrentRegion) == (WORD) -1)
		pThis->ih.m_pCurrentRegion	= NULL;
	else
		pThis->ih.m_pCurrentRegion	= &Regions[ORDERBYTES(pSource->m_nCurrentRegion)];

	pThis->m_dwFlags = pSource->m_wFlags;
}

