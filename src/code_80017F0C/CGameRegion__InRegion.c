#include "decompdecomp_sync_49b4450943d27902b3e3.h"
#line 11 "reference.c"
// does no floor or ceiling testing
BOOL CGameRegion__InRegion(CGameRegion *pThis, float X, float Z)
{
	int			e;
	CROMCorner	*pCornerA, *pCornerB;
	float			vNX, vNZ,
					vPX, vPZ;

	if (!pThis)
		return TRUE;

	for (e=0; e<3; e++)
	{
		pCornerA = pThis->m_pCorners[e];
		pCornerB = pThis->m_pCorners[(e + 1)%3];

		vNX = pCornerB->m_vCorner.z - pCornerA->m_vCorner.z;
		vNZ = pCornerA->m_vCorner.x - pCornerB->m_vCorner.x;

		vPX = X - pCornerA->m_vCorner.x;
		vPZ = Z - pCornerA->m_vCorner.z;

		if ((vNX*vPX + vNZ*vPZ) < 0)
			return FALSE;
	}

	return TRUE;
}
