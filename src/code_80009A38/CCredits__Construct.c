#include "decompdecomp_sync_801ded592e28ff3ce6e7.h"

#line 733 "reference.c"
/*****************************************************************************
*
*	Function:		CCredits__Contruct()
*
******************************************************************************
*
*	Description:	Create the credits initial vars
*
*	Inputs:			none
*	Outputs:			none
*
*****************************************************************************/
void CCredits__Construct(void)
{
	Credits.pData = TheCredits ;
	Credits.ScrollY = 240 ;
	Credits.OffsetY = 0 ;
	Credits.Pause = FALSE ;
	Credits.SizeY = CREDIT_SIZE * Credits.pData->ys ;

//	GetApp()->m_WarpID = CHEAT_GALLERY_WARP_ID;
//	CEngineApp__SetupFadeTo(GetApp(), MODE_CREDITS);
}
