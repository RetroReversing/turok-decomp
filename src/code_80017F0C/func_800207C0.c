#include "decompdecomp_sync_a16a4c646969ec594b5a.h"
#line 1 "func.c"
#line 479 "reference.c"
CVector3 func_800207C0(CGameRegion *pThis)
{
	static CGameRegion	*pNormalCache = NULL;
	static CVector3		vNormalCache;
	CVector3					vLeft, vRight;

	if (!pThis)
	{
		vNormalCache.x = 0;
		vNormalCache.y = -1;
		vNormalCache.z = 0;
	}
	else if (pThis != pNormalCache)
	{
		vLeft.x = pThis->m_pCorners[1]->m_vCorner.x - pThis->m_pCorners[0]->m_vCorner.x;
		vLeft.y = pThis->m_pCorners[1]->m_Ceiling   - pThis->m_pCorners[0]->m_Ceiling;
		vLeft.z = pThis->m_pCorners[1]->m_vCorner.z - pThis->m_pCorners[0]->m_vCorner.z;

		vRight.x = pThis->m_pCorners[2]->m_vCorner.x - pThis->m_pCorners[1]->m_vCorner.x;
		vRight.y = pThis->m_pCorners[2]->m_Ceiling   - pThis->m_pCorners[1]->m_Ceiling;
		vRight.z = pThis->m_pCorners[2]->m_vCorner.z - pThis->m_pCorners[1]->m_vCorner.z;

		CVector3__Cross(&vNormalCache, &vRight, &vLeft);
	}

	pNormalCache = pThis;

	return vNormalCache;
}

