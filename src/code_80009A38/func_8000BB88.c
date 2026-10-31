#include "common_local_source_3743.h"

#line 1 "reference.c"
void func_8000BB88(Gfx **ppDLP)
{
	int	y ;
	float	opacity ;
	float time ;
	float	MaxY, MinY ;
	float	xscale, yscale, yscaleadd ;
	t_Credit	*credit ;




	COnScreen__InitFontDraw(ppDLP) ;
#ifdef KANJI
	func_80080940(ppDLP);
#endif
	GetApp()->m_OnScreen.m_ShadowXOff = 1 ;
	GetApp()->m_OnScreen.m_ShadowYOff = 1 ;


	y = D_80119950.ScrollY - D_80119950.OffsetY ;
	credit = D_80119950.pData ;

	MinY = GetApp()->m_Camera.m_LetterBoxTop-10 ;
	MaxY = GetApp()->m_Camera.m_LetterBoxBottom ;

	// draw each option
	while ((y < MaxY) && (credit))
 	{

		// skip the pause line
		if (credit->xs == -2)
			credit++ ;

		if (y <= (MinY+40))
		{
			time = (((float)((MinY+40)-y)) / ((float)40)) ;
//			xscale = BlendFLOATCosine(time, credit->xs, credit->xs*2) ;
//			yscale = BlendFLOATCosine(time, credit->ys, 0) ;
			opacity = BlendFLOATCosine(time, 255, 0) ;
//			yscaleadd = credit->ys ;
		}
		else if (y > (MaxY-40))
		{
			time = (((float)(MaxY-y)) / ((float)40)) ;
//			xscale = BlendFLOATCosine(time, credit->xs*2, credit->xs) ;
//			yscale = BlendFLOATCosine(time, 0, credit->ys) ;
			opacity = BlendFLOATCosine(time, 0, 255) ;
//			yscaleadd = yscale ;
		}
		else
		{
			opacity = 255 ;
		}

		xscale = credit->xs ;
		yscale = credit->ys ;
		yscaleadd = yscale ;

		// set font color depending on title size
		if (credit->xs == (float)CREDIT_XS)
		{
			func_800808F8(ppDLP,
											0, 200, 200,
											0, 0, 200);
		}
		else if (credit->xs == (float)CREDIT_TXS)
		{
			func_800808F8(ppDLP,
											200, 200, 200,
											0, 200, 200);
		}
		else if (credit->xs == (float)CREDIT_HXS)
		{
			func_800808F8(ppDLP,
											255, 255, 255,
											200, 200, 200);
		}

		func_8008092C(xscale, yscale) ;
		draw_onscreen_text(ppDLP,
								  credit->string,
								  320/2, y,
								  opacity, TRUE, TRUE) ;

		y += CREDIT_SIZE * yscaleadd ;

		credit++ ;
		if (credit->xs == -1)
			credit = NULL ;
	}
}
