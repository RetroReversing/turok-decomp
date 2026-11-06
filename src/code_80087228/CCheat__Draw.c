#include "decompdecomp_sync_f36b0bb2906cab299f69.h"
#line 1 "func.c"
#line 718 "reference.c"
void CCheat__Draw(CCheat *pThis, Gfx **ppDLP)
{
	int		i,
				yStart;

	int		amount ;
	int		CHEAT_Y,
				CHEAT_HEIGHT ;
	int		CHEATMENU_SPACING ;
	float		CHEAT_SCALE ;


	// update fade status
	switch (pThis->m_Mode)
	{
		case CHEAT_FADEUP:
			pThis->m_Alpha += .2 * D_800B6B00 ;
			if (pThis->m_Alpha >= 1.0)
			{
				pThis->m_Alpha = 1.0 ;
				pThis->m_Mode = CHEAT_NORMAL ;
			}
			break ;

		case CHEAT_FADEDOWN:
			pThis->m_Alpha -= .2 * D_800B6B00 ;
			if (pThis->m_Alpha <= 0.0)
			{
				pThis->m_Alpha = 0.0 ;
				pThis->m_Mode = CHEAT_NULL ;
				if (pThis->b_Active == FALSE)
					GetApp()->m_bCheat = FALSE ;
			}
			break ;
	}


	// create a proper scale and size for cheat box
	CHEATMENU_SPACING = 18 ;
	CHEAT_SCALE = 1 ;
	amount = func_800880CC(pThis) ;
	CHEAT_HEIGHT = amount * CHEATMENU_SPACING ;
	CHEAT_HEIGHT += (CHEATMENU_Y*2) ;

	// temptemptemptemptemptemptemptemp
	//CTurokMovement.Tokens = amount ;

	// time to start scaling
	if (amount > 12)
	{
		switch (amount)
		{
			case	13:		CHEATMENU_SPACING = 16 ;		break ;
			case	14:		CHEATMENU_SPACING = 15 ;		break ;
			case	15:		CHEATMENU_SPACING = 14 ;		break ;
			case	16:		CHEATMENU_SPACING = 13 ;		break ;
			case	17:
			case	18:		CHEATMENU_SPACING = 12 ;		break ;
			case	19:		CHEATMENU_SPACING = 11 ;		break ;
			case	20:
			case	21:		CHEATMENU_SPACING = 10 ;		break ;
			case	22:
			case	23:
			case	24:		CHEATMENU_SPACING = 9 ;			break ;
			case	25:
			case	26:
			case	27:
			case	28:		CHEATMENU_SPACING = 8 ;			break ;
			case	29:
			case	30:		CHEATMENU_SPACING = 7 ;			break ;
 
			default:			CHEATMENU_SPACING = 6 ;			break ;
		}
		CHEAT_HEIGHT = amount * CHEATMENU_SPACING ;
		CHEAT_HEIGHT += (CHEATMENU_Y*2) ;
		CHEAT_SCALE = (float)(CHEATMENU_SPACING+1) / 18.0 ;
	}
/*
	if (CHEAT_HEIGHT > 220)
	{
		CHEATMENU_SPACING = (220-(CHEATMENU_Y*2))/amount ;
		CHEAT_HEIGHT = amount * CHEATMENU_SPACING ;
		CHEAT_HEIGHT += (CHEATMENU_Y*2) ;
		CHEAT_SCALE = (float)CHEATMENU_SPACING / 18 ;
	}
*/

	CHEAT_Y =((240/2) - (CHEAT_HEIGHT/2)) ;

	// prepare to draw boxes
	COnScreen__InitBoxDraw(ppDLP) ;
	COnScreen__DrawHilightBox(ppDLP,
							 CHEAT_X, CHEAT_Y,
							 CHEAT_X+CHEAT_WIDTH, CHEAT_Y+CHEAT_HEIGHT,
							 1, FALSE,
							 0,0,0, 200 * pThis->m_Alpha) ;

	// draw polygon selection bar
	CPause__InitPolygon(ppDLP) ;
	CPause__DrawBar(ppDLP, CHEAT_X+8, CHEAT_Y+CHEATMENU_Y+(pThis->m_RealSelection*CHEATMENU_SPACING),
						CHEAT_WIDTH-16, CHEATMENU_SPACING, pThis->m_Alpha) ;


	// setup pointers to correct on/off text
	if (GetApp()->m_dwCheatFlags & CHEATFLAG_INVINCIBILITY)
		D_800ECE38[CHEAT_INVINCIBILITY] = D_800ECAF0 ;
	else
		D_800ECE38[CHEAT_INVINCIBILITY] = D_800ECB04 ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_SPIRITMODE)
		D_800ECE38[CHEAT_SPIRITMODE] = D_800ECB18 ;
	else
		D_800ECE38[CHEAT_SPIRITMODE] = D_800ECB28 ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_ALLWEAPONS)
		D_800ECE38[CHEAT_ALLWEAPONS] = D_800ECB38 ;
	else
		D_800ECE38[CHEAT_ALLWEAPONS] = D_800ECB48 ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_UNLIMITEDAMMO)
		D_800ECE38[CHEAT_UNLIMITEDAMMO] = D_800ECB58 ;
	else
		D_800ECE38[CHEAT_UNLIMITEDAMMO] = D_800ECB6C ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_BIGHEADS)
		D_800ECE38[CHEAT_BIGHEADS] = D_800ECB80 ;
	else
		D_800ECE38[CHEAT_BIGHEADS] = D_800ECB94 ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_ALLMAP)
		D_800ECE38[CHEAT_ALLMAP] = D_800ECBA8 ;
	else
		D_800ECE38[CHEAT_ALLMAP] = D_800ECBB4 ;

if (GetApp()->m_dwCheatFlags & (1<<28))
        D_800ECE38[CHEAT_SHOWALLENEMIES] = D_800ECBC0;
    else
        D_800ECE38[CHEAT_SHOWALLENEMIES] = D_800ECBD0;
//	if (GetApp()->m_dwCheatFlags & CHEATFLAG_SHOWALLENEMIES)
//		cheat_text[CHEAT_SHOWALLENEMIES] = text_showallenemies_on ;
//	else
//		cheat_text[CHEAT_SHOWALLENEMIES] = text_showallenemies_off ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_TINYENEMYMODE)
		D_800ECE38[CHEAT_TINYENEMYMODE] = D_800ECBE4 ;
	else
		D_800ECE38[CHEAT_TINYENEMYMODE] = D_800ECBF8 ;

//	if (GetApp()->m_dwCheatFlags & CHEATFLAG_BIGENEMYMODE)
//		cheat_text[CHEAT_BIGENEMYMODE] = text_bigenemymode_on ;
//	else
//		cheat_text[CHEAT_BIGENEMYMODE] = text_bigenemymode_off ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_PENANDINKMODE)
		D_800ECE38[CHEAT_PENANDINKMODE] = D_800ECC0C ;
	else
		D_800ECE38[CHEAT_PENANDINKMODE] = D_800ECC20 ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_PURDYCOLORS)
		D_800ECE38[CHEAT_PURDYCOLORS] = D_800ECC38 ;
	else
		D_800ECE38[CHEAT_PURDYCOLORS] = D_800ECC48 ;

//	if (GetApp()->m_dwCheatFlags & CHEATFLAG_MODIFYENEMY)
//		cheat_text[CHEAT_MODIFYENEMY] = text_modifyenemy_on ;
//	else
//		cheat_text[CHEAT_MODIFYENEMY] = text_modifyenemy_off ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_INFINITELIVES)
		D_800ECE38[CHEAT_INFINITELIVES] = D_800ECC5C ;
	else
		D_800ECE38[CHEAT_INFINITELIVES] = D_800ECC70 ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_FLYMODE)
		D_800ECE38[CHEAT_FLYMODE] = D_800ECC84 ;
	else
		D_800ECE38[CHEAT_FLYMODE] = D_800ECC90 ;

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_QUACKMODE)
		D_800ECE38[CHEAT_QUACKMODE] = D_800ECCA0 ;
	else
		D_800ECE38[CHEAT_QUACKMODE] = D_800ECCB0 ;

             
	if (GetApp()->m_dwCheatFlags & CHEATFLAG_DISCO)
		D_800ECE38[CHEAT_DISCO] = D_800ECCC0 ;
	else
		D_800ECE38[CHEAT_DISCO] = D_800ECCD0 ;
      

	// draw each option
	COnScreen__InitFontDraw(ppDLP) ;
	func_8008092C(D_800F60E0, CHEAT_SCALE) ;
	func_800808F8(ppDLP, 200, 200, 200, 200, 200, 200) ;
//	COnScreen__SetFontColor(ppDLP, 200, 200, 138, 86, 71,47) ; // default colors (from onscrn.cpp)
	yStart = CHEAT_Y + CHEATMENU_Y;

	for (i=0; i<CHEAT_END_SELECTION; i++)
	{
		if (D_801293F0[i])
		{
			COnScreen__DrawText(ppDLP, D_800ECE38[i], 320/2, yStart, (int)(255 * pThis->m_Alpha), TRUE, FALSE);
			yStart += CHEATMENU_SPACING;
		}
	}
}

