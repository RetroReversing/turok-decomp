#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void CVector3__YIntersect(CVector3 *pvThis, CVector3 *pvStart, CVector3 *pvEnd, float Y);
void CVector3__YIntersect(CVector3 *pvThis, CVector3 *pvStart, CVector3 *pvEnd, float Y);
void CVector3__YIntersect(CVector3 *pvThis, CVector3 *pvStart, CVector3 *pvEnd, float Y)
{
	float		dy, u;

	dy = pvEnd->y - pvStart->y;
	if (dy == 0)
	{
		*pvThis = *pvStart;
	}
	else
	{
		u = (Y - pvStart->y)/dy;

		pvThis->x = pvStart->x + u*(pvEnd->x - pvStart->x);
		pvThis->y = Y;
		pvThis->z = pvStart->z + u*(pvEnd->z - pvStart->z);
	}
}
