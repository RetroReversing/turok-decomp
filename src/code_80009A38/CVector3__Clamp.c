#include "common.h"

typedef struct {f32 x,y,z;} CVector3;
typedef s32 BOOL;
#define CVector3__MagnitudeSquared(v) ((v)->x*(v)->x+(v)->y*(v)->y+(v)->z*(v)->z)
f32 sqrtf(f32);
void CVector3__MultScaler(CVector3*,CVector3*,f32);
BOOL CVector3__Clamp(CVector3 *pvThis, float MaxVal)
{
	float	magSq, mag;

	magSq = CVector3__MagnitudeSquared(pvThis);

	if (magSq > (MaxVal*MaxVal))
	{
		mag = sqrtf(magSq);

		if (mag != 0)
		{
			CVector3__MultScaler(pvThis, pvThis, MaxVal/mag);

			return TRUE;
		}
	}

	return FALSE;
}
