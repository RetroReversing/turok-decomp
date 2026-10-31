#include "common.h"

typedef struct {f32 x,y,z;} CVector3;
typedef s32 BOOL;
#define CVector3__MagnitudeSquared(v) ((v)->x*(v)->x+(v)->y*(v)->y+(v)->z*(v)->z)
f32 func_8009E7A0(f32);
void func_80013C2C(CVector3*,CVector3*,f32);
BOOL func_80013DC8(CVector3 *pvThis, float MaxVal)
{
	float	magSq, mag;

	magSq = CVector3__MagnitudeSquared(pvThis);

	if (magSq > (MaxVal*MaxVal))
	{
		mag = func_8009E7A0(magSq);

		if (mag != 0)
		{
			func_80013C2C(pvThis, pvThis, MaxVal/mag);

			return TRUE;
		}
	}

	return FALSE;
}
