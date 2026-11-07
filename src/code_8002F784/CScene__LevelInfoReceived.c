#include "decompdecomp_sync_b529ab3481a025b426a1.h"
#line 1137 "reference.c"
void CScene__LevelInfoReceived(CScene *pThis, CCacheEntry **ppceTarget)
{
	void			*pbRomLevel;
	int			i;
	float			lighting;
	int			v;

	ASSERT(ppceTarget == &pThis->m_pceLevelInfo);
	ASSERT(pThis->m_rpGridBoundsAddress);

	pbRomLevel = CCacheEntry__GetData(pThis->m_pceLevelInfo);
	memcpy(&pThis->m_LevelInfo, pbRomLevel, sizeof(CROMLevel));

	pThis->m_LevelInfoReceived = TRUE;

	// clear map if player just entered another major level
	if ((pThis->m_LevelInfo.m_bFlags & LEVEL_STORE_MAP) && (pThis->m_nLevel != GetApp()->m_LastSaveMapLevel))
	{
		CScene__ClearAllRegionFlags(pThis);

		GetApp()->m_LastSaveMapLevel = pThis->m_nLevel;
	}

	// pick microcode version
	if (pThis->m_LevelInfo.m_bFlags & LEVEL_LOW_PRECISION)
		microcode_version = MICROCODE_LOW_PRECISION;
	else
		microcode_version = MICROCODE_HIGH_PRECISION;


	// set up real-time light
	CScene__SetupRealTimeLight(pThis) ;

	// build pre-light table
	for (i=0; i<64; i++)
	{
		//lighting = i*(2.0/32.0) - 1;
		//v = (BYTE) (min(max(0, (lighting+0.5)/1.5*(1 - ambient)) + ambient, 1) * 256);
		lighting = i/63.0;
		v = max(0, min(255, lighting*255));
		//rmonPrintf("v:%d\n", v);

		light_table_red[i]	= (BYTE) min(255, ( (((int)pThis->m_LevelInfo.m_AmbientLight[0]) << 8)
												 + pThis->m_LevelInfo.m_DirectionalLight[0]*v ) >> 8);
		light_table_green[i]	= (BYTE) min(255, ( (((int)pThis->m_LevelInfo.m_AmbientLight[1]) << 8)
												 + pThis->m_LevelInfo.m_DirectionalLight[1]*v ) >> 8);
		light_table_blue[i]	= (BYTE) min(255, ( (((int)pThis->m_LevelInfo.m_AmbientLight[2]) << 8)
												 + pThis->m_LevelInfo.m_DirectionalLight[2]*v ) >> 8);

/*
		rmonPrintf("r:%d, g:%d, b:%d\n",
				light_table_red[i],
				light_table_green[i],
				light_table_blue[i]);
*/
	}

	// request grid bounds
	CCartCache__RequestBlock(&pThis->m_Cache,
									 pThis, (pfnCACHENOTIFY) CScene__DecompressGridBounds, (pfnCACHENOTIFY) CScene__GridBoundsReceived,
									 &pThis->m_pceGridBounds,
									 pThis->m_rpGridBoundsAddress, pThis->m_GridBoundsSize,
									 "Grid Bounds");

}
