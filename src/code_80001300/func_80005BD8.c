#include "common_local_source_3704.h"

#line 2448 "reference.c"
void func_80005BD8(CEngineApp *pThis)
{
	float		x, y, opacity,
				dx, dy, distSquared,
				opac2;
	BOOL		visible;
	BYTE		color[4] = { 255, 255, 255, 255 };

	func_80098670(&sun, &visible, &x, &y, &opacity);
	if (!visible)
		return;

	dx = x - SCREEN_WD/2;
	dy = y - SCREEN_HT/2;

	distSquared = dx*dx + dy*dy;

#define SUNGLARE_DIST 0.33
#define SUNGLARE_OPAC (220 & 0xf8)

	opac2 = (SUNGLARE_DIST - sqrt(distSquared)/(SCREEN_WD/2)) * opacity/SUNGLARE_DIST;
	if (opac2 > 0)
	{
		color[3] = (BYTE) min(SUNGLARE_OPAC, opac2*SUNGLARE_OPAC);
		CEngineApp__RenderTint(pThis, color);
	}
}
