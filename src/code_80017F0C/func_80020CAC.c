#include "decompdecomp_sync_5632be47ceb943d2a964.h"
#line 1 "func.c"
#line 829 "reference.c"
BOOL func_80020CAC(CGameRegion *pThis, CVector3 *pvStart, CVector3 *pvEnd, float *Out)
{
	static CGameRegion	*pRegionCache = NULL;
	static CROMRegionSet	*pRegionSetCache = NULL;
	float						divisor;

	if (!pThis)
		return FALSE;

	if (!(pThis->m_wFlags & REGFLAG_HASWATER))
		return FALSE;

	if (pThis != pRegionCache)
	{
		pRegionSetCache = CScene__GetRegionAttributes(((void*)D_800FA3C8), pThis);

		pRegionCache = pThis;
	}

	if (!pRegionSetCache)
		return FALSE;

	//if (!(pRegionSetCache->m_dwFlags & REGIONSET_HASWATER))
	//	return FALSE;

	//if (pvEnd->y >= pvStart->y)
	//	return FALSE;

	divisor = pvEnd->y - pvStart->y;
	if (divisor == 0)
	{
		return FALSE;
	}
	else
	{
		*Out = (pRegionSetCache->m_WaterElevation - pvStart->y)/divisor;

		return ((*Out > 0) && (*Out < 1));
	}
}

