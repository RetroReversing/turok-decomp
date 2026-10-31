#include "common_local_source_5440.h"

#line 3571 "reference.c"
void func_80083938(CBarrel *pThis, Gfx **ppDLP)
{
	float	XPos, YPos ;
	int	i, index ;
	float	angle, alpha ;

	// draw list, starting with current
	pThis->InitGraphics(ppDLP) ;

	// item to start with
	i = pThis->m_Display/2 ;
	index = pThis->m_Current ;
	while (i--)
	{
		index-- ;
		if (index <0)
			index += pThis->m_Buffersize ;
	}

//	index = pThis->m_Current -4;
//	if (index <0)
//		index += pThis->m_Buffersize ;

	// check incase not enough items!
//	if (index == -2)
//		index = 0 ;
//	else if ((index <0) || (index > pThis->m_Buffersize-1))
//		index = pThis->m_Buffersize-1 ;

	for (i=0 ; i<pThis->m_Display; i++)
	{
		angle = i*(3.141592654*2) / pThis->m_Display ;
		angle += 3.141592654 ;
		angle -= pThis->m_ViewAngleOffset ;

		XPos = pThis->m_X ;
		YPos = pThis->m_Y ;
		XPos += pThis->m_XStep * cos(angle) ;
		YPos += pThis->m_YStep * sin(angle) ;

		alpha = 128+(127*cos(angle)) ;

		if (alpha >0)
		{
			pThis->DrawItem(ppDLP,
								 index, XPos, YPos,
								 0.6+(0.4*cos(angle)), 0.6+(0.4*cos(angle)),
								 alpha) ;
		}
		index++ ;
		if (index > pThis->m_Buffersize-1)
			index = 0 ;
	}
}
