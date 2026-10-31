#include "source_CGameSimpleInstance__TakeFromROMSimpleInstance.h"
#line 1 "func.c"
#line 1 "reference.c"
void CGameSimpleInstance__TakeFromROMSimpleInstance(CGameSimpleInstance *pThis, CROMSimpleInstance *pSource,
																	 ROMAddress *rpObjectAddress,
																	 CGameRegion Regions[], CEnemyAttributes Variations[])
{
	int	nObjType;

	pThis->ah.ih.m_Type = I_SIMPLE;
	pThis->ah.ih.m_nObjType = pSource->m_nObjType;
	pThis->ah.ih.m_bActiveFlags = pSource->m_bActiveFlags;

	pThis->ah.ih.m_vPos = pSource->m_vPos;
	pThis->ah.ih.m_CollisionHeightOffset = 0;

	pThis->m_RotAngle = INT82FLOAT(pSource->m_RotY, ANGLE_PI);

// NOTE: SCALES HIGHER THAN SCALING_SIMPLE_OBJECT_SCALE WILL NOT BE PROPERLY CLIPPED!!
	pThis->m_Scale = SCALING_SIMPLE_OBJECT_SCALE;
	pThis->m_OffsetY = 0;

	pThis->m_Bounds.m_vMin.x = pSource->m_vPos.x - pSource->m_MaxRadius;
	pThis->m_Bounds.m_vMin.y = pSource->m_vPos.y - pSource->m_MaxRadius;
	pThis->m_Bounds.m_vMin.z = pSource->m_vPos.z - pSource->m_MaxRadius;
	pThis->m_Bounds.m_vMax.x = pSource->m_vPos.x + pSource->m_MaxRadius;
	pThis->m_Bounds.m_vMax.y = pSource->m_vPos.y + pSource->m_MaxRadius;
	pThis->m_Bounds.m_vMax.z = pSource->m_vPos.z + pSource->m_MaxRadius;

	pThis->m_rpObjectIndexAddress = rpObjectAddress;

	if (pSource->m_nVariation == (WORD) -1)
		pThis->ah.ih.m_pEA = NULL;
	else
		pThis->ah.ih.m_pEA = &Variations[pSource->m_nVariation];

	if (ORDERBYTES(pSource->m_nCurrentRegion) == (WORD) -1)
		pThis->ah.ih.m_pCurrentRegion	= NULL;
	else
		pThis->ah.ih.m_pCurrentRegion	= &Regions[ORDERBYTES(pSource->m_nCurrentRegion)];

	pThis->m_wFlags = pSource->m_wFlags;


	nObjType = func_8001D398(&pThis->ah.ih);

	if (func_80071820(nObjType) || func_800717E8(nObjType))
	{
		pThis->m_wFlags |= SIMPLE_FLAG_VISIBLE;
		pThis->m_Time = 0 ;
	}
	else	// if (AI_IsWarp(nObjType))
	{
		// if returning from warp, or in a warp
		if (	(GetApp()->m_WarpID == -1)
			||	(pThis->ah.ih.m_pEA->m_wTypeFlags3 & AI_TYPE3_RETURNWARP))
		{
			pThis->m_wFlags |= SIMPLE_FLAG_VISIBLE;
			pThis->m_Time = WARP_CLOSE_TIME*pThis->ah.ih.m_pEA->m_Aggression;
		}
		// otherwise start invisible, nearly ready to appear
		else
		{
			pThis->m_Time = .70*pThis->ah.ih.m_pEA->m_AttackStyle ;
		}
	}

	//pThis->m_cFrame = 0;
	pThis->m_MorphInc = 0;

	pThis->m_nID = pSource->m_nID;
}

