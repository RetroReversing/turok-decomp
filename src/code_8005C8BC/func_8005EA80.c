#include "decompdecomp_sync_16178d2b34d0176eef8f.h"
#line 1 "func.c"
#line 7217 "reference.c"
void func_8005EA80(CTMove *pThis, CEngineApp *pApp)
{
	float		dm;


if (pApp->m_MapMode)
 {
  if (func_80039B98(&pApp->m_Camera) && pApp->m_MapStatus != 32)
  { pApp->m_MapStatus=32; pApp->m_MapAlpha=0; }
  else if (pApp->m_MapStatus==32) pApp->m_MapStatus=MAP_FADEUP;
 }
	if (pApp->m_MapMode)
	{
		switch (pApp->m_MapStatus)
		{
			case MAP_FADEUP:
				pApp->m_MapAlpha += .1 * D_800B6B00 ;
				if (pApp->m_MapAlpha >= 1.0)
				{
					pApp->m_MapAlpha = 1 ;
					pApp->m_MapStatus = MAP_ON ;
				}
				break ;
			case MAP_FADEDOWN:
				pApp->m_MapAlpha -= .1 * D_800B6B00 ;
				if (pApp->m_MapAlpha <= 0.0)
				{
					pApp->m_MapAlpha = 0 ;
					pApp->m_MapStatus = MAP_NULL ;
					pApp->m_MapMode = FALSE ;
				}
				break ;
		}
	}

	// map on ?
	if (pThis->MapToggle)
	{
		// map is on
		if (pApp->m_MapMode == FALSE)
			pApp->m_MapStatus = MAP_FADEUP ;

		pApp->m_MapMode = TRUE;

		// calculate used map offsets
		dm = (pThis->RealMapOffsetX - pThis->MapOffsetX) / 3;
		pThis->MapOffsetX += dm * D_800B6B00;

		dm = (pThis->RealMapOffsetZ - pThis->MapOffsetZ) / 4;
		pThis->MapOffsetZ += dm * D_800B6B00;
	}
	else
	{
		// map is off
		if (pApp->m_MapStatus != MAP_NULL)
			pApp->m_MapStatus = MAP_FADEDOWN ;

//		pApp->m_MapMode = FALSE;
		pThis->RealMapOffsetX = 0.0;
		pThis->RealMapOffsetZ = 0.0;
		pThis->MapOffsetX = 0.0;
		pThis->MapOffsetZ = 0.0;
	}
}

