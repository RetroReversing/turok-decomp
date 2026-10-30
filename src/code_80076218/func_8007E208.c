#include "common_local_source_5386.h"

#line 2 "reference.c"
void func_8007E208(Gfx **ppDLP)
{
	float				x, y, opacity,
						size, scaler;
	BOOL				visible;

	func_80098670(&sun, &visible, &x, &y, &opacity);
	if (!visible)
		return;

	func_80081A10(ppDLP, 255*(1 - opacity));

	D_800239C0(ppDLP, G_RM_PASS__G_RM_CLD_SURF2);
	gDPSetTextureFilter((*ppDLP)++, G_TF_BILERP);

	scaler = 2;

	scaler *= 1.1;

	size = 32*scaler/2;

	if (		(x > (          - size))
			&& (x < (SCREEN_WD + size))
			&&	(y > (          - size))
			&& (y < (SCREEN_HT + size)) )
	{

		func_80082FA0(ppDLP,
													(C16BitGraphic *)D_800CB0E0,
													x-size, y-size, scaler, scaler) ;

	}

	gDPSetTexturePersp((*ppDLP)++, G_TP_PERSP);
}
