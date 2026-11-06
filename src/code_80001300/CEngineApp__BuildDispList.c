#include "common_local_source_3669.h"

#line 1 "reference.c"
void CEngineApp__BuildDispList(CEngineApp *pThis)
{
	CCamera	*pCamera = &pThis->m_Camera ;

	// clears current render and combine modes
	D_80023824() ;


	CEngineApp__InitDisplayLists(pThis);
	CEngineApp__ClearBuffers(pThis);

	switch (pThis->m_Mode)
	{
		case MODE_LEGALSCREEN:
			CEngineApp__DrawLEGALSCREEN(pThis);
			break ;
		case MODE_GAMEPAK:
			CEngineApp__DrawGAMEPAK(pThis);
			break ;
		case MODE_TITLE:
			CEngineApp__DrawTITLE(pThis);
			break ;
		case MODE_INTRO:
		case MODE_GAME:
		case MODE_GAMEOVER:
			CEngineApp__DrawGAME(pThis);
			break ;
		case MODE_CREDITS:
			func_80003D78(pThis);
			break ;
		case MODE_GALLERY:
			CEngineApp__DrawGAME(pThis);
			CEngineApp__DrawGALLERY(pThis);
			break ;
	}

	if ((pThis->m_Mode == MODE_GAME) && (!CCamera__InCinemaMode(&pThis->m_Camera)))
		CEngineApp__UpdatePause(pThis);

	// Erase top and bottom line of letterbox to fix nasty aliasing pixel bits
	if (CCamera__InLetterBoxMode(pCamera))
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
