#include "decompdecomp_sync_e5d15ec69bbe68faccfe.h"
#line 1 "func.c"
#line 689 "reference.c"
BOOL func_8009A158(CCollide *pThis,
											CVector3 *pvCenter, float Radius,
											BOOL UseHeight, float Top, float Bottom,
											BOOL BackCull,
											int Behavior,
											float SurfaceFriction)
{
	CVector3		h, M,
					hminusmhDotM,
					vPoint, vNormal;
	float			hDotDelta,
					magDelta,
					invMagDelta,
					hdotM,
					magSqRight, radSq,
					sub,
					t;

	if (CCollide__IsSlideCylinder(pThis, pvCenter, Radius))
		return FALSE;

	h.x = pvCenter->x - pThis->pInst->ih.m_vPos.x;
	h.z = pvCenter->z - pThis->pInst->ih.m_vPos.z;

	if (BackCull)
	{
		hDotDelta = h.x*pThis->vDelta.x + h.z*pThis->vDelta.z;
		if (hDotDelta < 0.0)
			return FALSE;
	}

	magDelta = sqrt(SQR(pThis->vDelta.x) + SQR(pThis->vDelta.z));
	if (magDelta != 0.0)
	{
		invMagDelta = 1.0/magDelta;
		M.x = pThis->vDelta.x*invMagDelta;
		M.z = pThis->vDelta.z*invMagDelta;

		hdotM = h.x*M.x + h.z*M.z;

		hminusmhDotM.x = h.x - M.x*hdotM;
		hminusmhDotM.z = h.z - M.z*hdotM;

		magSqRight = SQR(hminusmhDotM.x) + SQR(hminusmhDotM.z);
		radSq = SQR(Radius);

		sub = radSq - magSqRight;
		if (sub > 0.0)
		{
			// movement did cross cylinder

			//t = max(0.0, (hdotM - sqrt(sub))*invMagDelta);
			t = (hdotM - sqrt(sub))*invMagDelta;
			if (t < pThis->clint.t)
			{
				func_800141A8(&vPoint, t, &pThis->pInst->ih.m_vPos, &pThis->vDesired);

				if (UseHeight)
					if ((vPoint.y > Top) || (vPoint.y < Bottom))
						return FALSE;

				vNormal.x = vPoint.x - pvCenter->x;
				vNormal.y = 0.0;
				vNormal.z = vPoint.z - pvCenter->z;
				
				if (func_80099744(pThis,
													  &vNormal, &vPoint,
													  FALSE,
													  Behavior,
													  SurfaceFriction))
				{
					CCollide__SetSlideCylinder(pThis, pvCenter, Radius);

					return TRUE;
				}
			}
		}
	}

	return FALSE;
}

