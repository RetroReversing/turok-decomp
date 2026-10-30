#include "common_local_source_3683.h"

#line 1 "reference.c"
void func_800034D0(CEngineApp *pThis)
{
	pThis->m_TitleAlpha += .1 * D_800B6B00 ;
	if (pThis->m_TitleAlpha > 1.0)
		pThis->m_TitleAlpha = 1.0 ;


	func_80002B40(pThis) ;

	func_80031B6C(&pThis->m_Scene, &pThis->m_pDLP);

	if (pThis->m_dwCheatFlags & CHEATFLAG_PENANDINKMODE)
	{
		gDPPipeSync(pThis->m_pDLP++);
		gDPSetCycleType(pThis->m_pDLP++, G_CYC_1CYCLE);
		gDPSetBlendColor(pThis->m_pDLP++, 255, 255, 255, 255);
		gDPSetPrimDepth(pThis->m_pDLP++, 0xffff, 0xffff);
		gDPSetDepthSource(pThis->m_pDLP++, G_ZS_PRIM);
		D_800239C0(&pThis->m_pDLP, G_RM_VISCVG__G_RM_VISCVG2);
		gDPFillRectangle(pThis->m_pDLP++, 0, 0, SCREEN_WD-1, SCREEN_HT-1);
	}

	// prepare to font textures
	// using billinear interpolation for scaled bitmaps
	COnScreen__InitFontDraw(&pThis->m_pDLP) ;


	// draw all menu screens last, over everything else
	if (pThis->m_Pause.m_Mode != PAUSE_NULL)
		func_80087228(&pThis->m_Pause, &pThis->m_pDLP) ;


//	if (pThis->m_GamePak.m_Mode != GAMEPAK_NULL)
//		CGamePak__Draw(&pThis->m_GamePak, &pThis->m_pDLP) ;


	func_800042D4(pThis) ;
}
