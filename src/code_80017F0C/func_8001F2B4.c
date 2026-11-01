#include "decompdecomp_sync_b26f3aefe710a9e79527.h"
#line 1 "func.c"
#line 2154 "reference.c"
void func_8001F2B4(CGameStaticInstance *pThis, CROMStaticInstance *pSource,
																	 ROMAddress *rpObjectAddress,
																	 CGameRegion Regions[], CEnemyAttributes Variations[])
{
                       
                        
                         
      

	CQuatern	qRot;
	CMtxF		mfRotate ;

	pThis->ih.m_Type = I_STATIC;
	pThis->ih.m_nObjType = pSource->m_nObjType;
	pThis->ih.m_bActiveFlags = pSource->m_bActiveFlags;

	pThis->m_Bounds.m_vMin.x = SF2FLOAT(pSource->m_BoundsMinX) + pSource->m_vPos.x;
	pThis->m_Bounds.m_vMin.y = SF2FLOAT(pSource->m_BoundsMinY) + pSource->m_vPos.y;
	pThis->m_Bounds.m_vMin.z = SF2FLOAT(pSource->m_BoundsMinZ) + pSource->m_vPos.z;

	pThis->m_Bounds.m_vMax.x = SF2FLOAT(pSource->m_BoundsMaxX) + pSource->m_vPos.x;
	pThis->m_Bounds.m_vMax.y = SF2FLOAT(pSource->m_BoundsMaxY) + pSource->m_vPos.y;
	pThis->m_Bounds.m_vMax.z = SF2FLOAT(pSource->m_BoundsMaxZ) + pSource->m_vPos.z;

	pThis->m_rpObjectIndexAddress = rpObjectAddress;

	if (pSource->m_nVariation == (WORD) -1)
		pThis->ih.m_pEA = NULL;
	else
		pThis->ih.m_pEA = &Variations[pSource->m_nVariation];

	qRot.x = pSource->m_RotX*(1.0/127.0);
	qRot.y = pSource->m_RotY*(1.0/127.0);
	qRot.z = pSource->m_RotZ*(1.0/127.0);
	qRot.t = pSource->m_RotT*(1.0/127.0);
	CQuatern__Normalize(&qRot);

                       

                                
                                                                                      
                                     

                                                  
                                                                                  

                                             
                                          

                                              
     

	// Optimized matrix version
	CQuatern__ToMatrix(&qRot, mfRotate);
	CMtxF__PreMultScale(mfRotate, pSource->m_vScale.x, pSource->m_vScale.y, pSource->m_vScale.z);

	//CVector3__Clamp(&pSource->m_vPos, WORLD_LIMIT);
	CMtxF__PostMultTranslate(mfRotate, pSource->m_vPos.x, pSource->m_vPos.y, pSource->m_vPos.z);

	CMtxF__ToMtx(mfRotate, pThis->m_mOrientation);
	//CMtxF__ToMtxPostMultTranslate(mfRotate, &(pThis->m_mOrientation), pSource->m_vPos.x, pSource->m_vPos.y, pSource->m_vPos.z);

      


	pThis->ih.m_vPos = pSource->m_vPos;
	pThis->ih.m_CollisionHeightOffset = 0;

	if (ORDERBYTES(pSource->m_nCurrentRegion) == (WORD) -1)
		pThis->ih.m_pCurrentRegion	= NULL;
	else
		pThis->ih.m_pCurrentRegion	= &Regions[ORDERBYTES(pSource->m_nCurrentRegion)];

	pThis->m_dwFlags = pSource->m_bFlags;
}

