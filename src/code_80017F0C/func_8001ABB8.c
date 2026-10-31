#include "common_local_source_3928.h"

#line 2 "reference.c"
CQuatern func_8001ABB8(CInstanceHdr *pThis)
{
	CVector3 				vNormal,
								vUp,
								vAxis;
	float						cosTheta, theta,
								sinRotY, cosRotY;
	CQuatern					qGround, qGroundXOnly, qBlend;
	CGameObjectInstance	*pPlayer;

	if (pThis->m_pCurrentRegion && !CInstanceHdr__IsDevice(pThis))
	{
		pPlayer = CEngineApp__GetPlayer(GetApp());

		if (pThis == &pPlayer->ah.ih)
		{
			if (func_80019ED8(pThis->m_pCurrentRegion))
			{
				CQuatern__Identity(&qGround);
			}
			else
			{
				vNormal = func_80019E30(pThis->m_pCurrentRegion);
				vUp.x = 0;
				vUp.y = 1;
				vUp.z = 0;
				func_80013BBC(&vAxis, &vUp, &vNormal);
				CVector3__Normalize(&vAxis);
				cosTheta = CVector3__Dot(&vUp, &vNormal);
				theta = acos(cosTheta);
				CQuatern__BuildFromAxisAngle(&qGround, vAxis.x, vAxis.y, vAxis.z, min(ANGLE_DTOR(GR_MAX_ZTILT), theta)*GR_TOTAL_TILT_FACTOR);


				sinRotY = sin(pPlayer->m_RotY);
				cosRotY = cos(pPlayer->m_RotY);

				theta = func_8001AA68(pThis->m_pCurrentRegion,
															 pThis->m_vPos.x, pThis->m_vPos.z,
															 pThis->m_vPos.x - sinRotY, pThis->m_vPos.z - cosRotY);

				if (!func_80019ED8(pThis->m_pCurrentRegion))
					theta = min(GR_MAX_XTILT, theta)*GR_TOTAL_TILT_FACTOR;

				CQuatern__BuildFromAxisAngle(&qGroundXOnly, cosRotY,0,-sinRotY, theta);

				CQuatern__Blend(&qBlend, GR_ZTILT_FACTOR, &qGroundXOnly, &qGround);
				qGround = qBlend;
			}
		}
		else
		{
			vNormal = func_80019E30(pThis->m_pCurrentRegion);

			vUp.x = 0;
			vUp.y = 1;
			vUp.z = 0;

			func_80013BBC(&vAxis, &vUp, &vNormal);
			CVector3__Normalize(&vAxis);

			cosTheta = CVector3__Dot(&vUp, &vNormal);

			theta = acos(cosTheta);

			CQuatern__BuildFromAxisAngle(&qGround, vAxis.x, vAxis.y, vAxis.z, theta);
		}
	}
	else
	{
		CQuatern__Identity(&qGround);
	}

	return qGround;
}
