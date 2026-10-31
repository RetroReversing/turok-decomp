#include "source_func_800036B0.h"

extern char D_800EF7BC[];
extern char D_800EF7C8[];
extern char D_800EF7A8[];
extern char D_800EF7B0[];
#line 1 "reference.c"
void func_800036B0(CEngineApp *pThis)
{
	float		x ;
	int		time, i ;
	C16BitGraphic	*Grid ;
//	DWORD		dls, dle;

//	sprintf(buffer1, "level %d boss lvl %d", pThis->m_Level, pThis->m_BossLevel) ;
//	sprintf(buffer2, "warp %d cur %d", pThis->m_WarpID, pThis->m_CurrentWarpID) ;
//	COnScreen__AddGameTextWithId(buffer1, 32) ;
//	COnScreen__AddGameTextWithId(buffer2, 33) ;

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

	func_80006188(pThis);
	func_800041B4(pThis);
	func_80004084(pThis);

//	dls = (DWORD) pThis->m_pDLP;

	// Only draw on screen info if not in letter box or cinematic mode
	if (		!func_80039BF0(&GetApp()->m_Camera)
			&&	!func_80039B98(&GetApp()->m_Camera) )
	{
		func_8007D5F4(&pThis->m_OnScreen, &pThis->m_pDLP);
	}


	// Display game text
	func_800833C0(&pThis->m_pDLP) ;


	// if player dead, draw game over
	if (pThis->m_bGameOver)
	{
		Grid = (C16BitGraphic *)D_800E2FC8 ;

		if (pThis->m_GameOverMode == 0)
		{
			pThis->m_GameOverAlpha += 16 * D_800B6B00 ;
			if (pThis->m_GameOverAlpha > 255)
			{
				pThis->m_GameOverAlpha = 255 ;
				pThis->m_GameOverMode = 1 ;
			}
		}

		pThis->m_GameOverTime -= 1*D_800B6B00 ;
		if (pThis->m_GameOverTime < 0)
			func_80004504(pThis, MODE_RESETGAME);

		// prepare to draw
		func_80081A10(&pThis->m_pDLP, pThis->m_GameOverAlpha) ;
		x = (SCREEN_WD/2) - (Grid->m_Width /2) ;
   	func_80082E64(&pThis->m_pDLP,
											Grid,
											x, (SCREEN_HT/2) - (Grid->m_Height/2)) ;
	}

	// draw all menu screens last, over everything else
	if (pThis->m_Pause.m_Mode != PAUSE_NULL)
		func_80087228(&pThis->m_Pause, &pThis->m_pDLP) ;


	// draw the training text
	if ((pThis->m_Training.m_Mode != TRAINING_NULL) && (pThis->m_bTrainingMode))
	{
		if (!((pThis->m_Training.m_Mode == TRAINING_FADEDOWN) && (pThis->m_Training.m_Alpha == 0.0)))
		{
			//sprintf(buffer, "mode %d", pThis->m_Training.m_Mode) ;
			//COnScreen__AddGameTextWithId(buffer, 45) ;
			func_80087B94(&pThis->m_Training, &pThis->m_pDLP) ;
		}
	}

	// draw the training clock...
	if ((pThis->m_bTrainingMode) && (pThis->m_TrainingType))
	{
		// increase time, if not finished
		if (		(pThis->m_bTraining == FALSE)
				&& (pThis->m_bRequestor == FALSE))
		{
			pThis->m_LevelTime += D_800B6B00 ;
			if (pThis->m_LevelTime >= ((999*60*FRAME_FPS)+(60*FRAME_FPS)))
				pThis->m_LevelTime -= ((999*60*FRAME_FPS)+(60*FRAME_FPS)) ;
		}
		else if (pThis->m_bTrainingMode == 2)
		{
			if (pThis->m_LevelTime < pThis->m_BestTrainTime)
				pThis->m_BestTrainTime = pThis->m_LevelTime ;
		}


		COnScreen__InitFontDraw(&pThis->m_pDLP) ;
		func_80080B0C(&pThis->m_pDLP) ;

		func_800808F8(&pThis->m_pDLP, 255, 55, 255, 255, 255, 255) ;
#ifndef GERMAN
		draw_onscreen_text(&pThis->m_pDLP, D_800EF7A8, (320/2)-(80/2), 22, 255, TRUE, TRUE) ;
#else
		draw_onscreen_text(&pThis->m_pDLP, "zeit", (320/2)-(80/2), 22, 255, TRUE, TRUE) ;
#endif

		func_800808F8(&pThis->m_pDLP, 255, 255, 55, 255, 255, 255) ;
#ifndef GERMAN
		draw_onscreen_text(&pThis->m_pDLP, D_800EF7B0, (320/2)+(80/2), 22, 255, TRUE, TRUE) ;
#else
		draw_onscreen_text(&pThis->m_pDLP, "bestzeit", (320/2)+(80/2), 22, 255, TRUE, TRUE) ;
#endif

		func_8008092C(1.0, 2.0) ;
		time = pThis->m_BestTrainTime / FRAME_FPS ;
		sprintf(D_80119938, D_800EF7BC, time/60, time%60) ;
		draw_onscreen_text(&pThis->m_pDLP, D_80119938, (320/2)+(80/2), 32, 255, TRUE, TRUE) ;

		time = pThis->m_LevelTime / FRAME_FPS ;
		i = 192+(63 * cos((float)D_800B6AF8/3)) ;
		func_800808F8(&pThis->m_pDLP, i, i, i, i, i, i) ;
		sprintf(D_80119938, D_800EF7C8, time/60, time%60) ;
		draw_onscreen_text(&pThis->m_pDLP, D_80119938, (320/2)-(80/2), 32, 255, TRUE, TRUE) ;
	}

//	dle = (DWORD) pThis->m_pDLP;
//	COnScreen__Init16BitDraw(&pThis->m_pDLP, 255);
//	COnScreen__DrawDigits(&pThis->m_pDLP, (dle - dls)/sizeof(Gfx), 50, 50);

	// must be last if you wanna fade everything...
	if (pThis->m_MapMode == 0)
	{
		func_80005BD8(pThis);
		func_80005DD8(pThis);
		func_80005388(pThis);
		func_800042D4(pThis);
	}

}
