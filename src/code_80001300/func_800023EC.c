#include "common_local_source_3669.h"

#line 1 "reference.c"
void func_800023EC(CEngineApp *pThis)
{
	CCamera	*pCamera = &pThis->m_Camera ;

	// clears current render and combine modes
	D_80023824() ;


	func_80006ED0(pThis);
	func_80001EB4(pThis);

	switch (pThis->m_Mode)
	{
		case MODE_LEGALSCREEN:
			func_80002D94(pThis);
			break ;
		case MODE_GAMEPAK:
			func_80002DE0(pThis);
			break ;
		case MODE_TITLE:
			func_800034D0(pThis);
			break ;
		case MODE_INTRO:
		case MODE_GAME:
		case MODE_GAMEOVER:
			func_800036B0(pThis);
			break ;
		case MODE_CREDITS:
			func_80003D78(pThis);
			break ;
		case MODE_GALLERY:
			func_800036B0(pThis);
			func_80002E28(pThis);
			break ;
	}

	if ((pThis->m_Mode == MODE_GAME) && (!func_80039B98(&pThis->m_Camera)))
		func_8000826C(pThis);

	// Erase top and bottom line of letterbox to fix nasty aliasing pixel bits
	if (func_80039BF0(pCamera))
	{
		gDPPipeSync(pThis->m_pDLP++);
		gDPSetCycleType(pThis->m_pDLP++, G_CYC_1CYCLE);
		D_800239C0(&pThis->m_pDLP, G_RM_XLU_SURF__G_RM_XLU_SURF2);
		D_80023FF8(&pThis->m_pDLP, G_CC_PRIMITIVE__G_CC_PRIMITIVE);
		gDPSetPrimColor(pThis->m_pDLP++, 0, 0, 0, 0, 0, 0);

		gDPFillRectangle(pThis->m_pDLP++, 0,			pCamera->m_LetterBoxTop,
													 SCREEN_WD, pCamera->m_LetterBoxTop+1) ;

		gDPFillRectangle(pThis->m_pDLP++, 0,			pCamera->m_LetterBoxBottom-1,
													 SCREEN_WD, pCamera->m_LetterBoxBottom-1+1) ;
	}
}
