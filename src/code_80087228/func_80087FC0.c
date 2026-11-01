#include "decompdecomp_sync_cfc58d2683e09f062358.h"
#line 1 "func.c"
#line 335 "reference.c"
void func_80087FC0(CCheat *pThis)
{
	int	cnt;

	if (pThis->m_Mode == CHEAT_NULL)
		pThis->m_Alpha = 0 ;

	pThis->m_Mode = CHEAT_FADEUP ;
	pThis->b_Active = TRUE ;

/*
GetApp()->m_dwEnabledCheatFlags =		CHEATFLAG_INVINCIBILITY
											  |	CHEATFLAG_SPIRITMODE
											  |	CHEATFLAG_ALLWEAPONS
											  |	CHEATFLAG_UNLIMITEDAMMO
											  |	CHEATFLAG_BIGHEADS
											  |	CHEATFLAG_ALLMAP
											  |	CHEATFLAG_SHOWALLENEMIES
											  |	CHEATFLAG_TINYENEMYMODE
											  |	CHEATFLAG_BIGENEMYMODE
											  |	CHEATFLAG_PENANDINKMODE
											  |	CHEATFLAG_PURDYCOLORS
											  |	CHEATFLAG_WARPLEVEL1
											  |	CHEATFLAG_WARPLEVEL2
											  |	CHEATFLAG_WARPLEVEL3
											  |	CHEATFLAG_WARPLEVEL4
											  |	CHEATFLAG_WARPLEVEL5
											  |	CHEATFLAG_WARPLEVEL6
											  |	CHEATFLAG_WARPLEVEL7
											  |	CHEATFLAG_WARPLEVEL8
											  |	CHEATFLAG_WARPLONGHUNTER
											  |	CHEATFLAG_WARPMANTIS
											  |	CHEATFLAG_WARPTREX
											  |	CHEATFLAG_WARPCAMPAIGNER
											  |	CHEATFLAG_GALLERY
											  |	CHEATFLAG_SHOWCREDITS
											  |	CHEATFLAG_MODIFYENEMY
											  |	CHEATFLAG_ALLKEYS
											  |	CHEATFLAG_INFINITELIVES
											  |	CHEATFLAG_FLYMODE
											  |	CHEATFLAG_QUACKMODE ;

*/
	// reset cheat menu items
	for (cnt=0; cnt<CHEAT_END_SELECTION-1; cnt++)
		cheat_menu_items[cnt] = ((GetApp()->m_dwEnabledCheatFlags & (1<<cnt)) == (1<<cnt));

	// exit option is always available
	cheat_menu_items[CHEAT_EXIT] = 1;

	// setup default selection
	pThis->m_Selection = CHEAT_EXIT;			// position on exit on startup
	pThis->m_RealSelection = CCheat__GetOptionAmt(pThis) - 1;
}

