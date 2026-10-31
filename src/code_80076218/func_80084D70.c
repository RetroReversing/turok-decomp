#include "common_local_source_5464.h"

#line 1 "reference.c"
void func_80084D70(CPause *pThis)
{
	int	cnt;


	// reset menu items
	for (cnt=0; cnt<PAUSE_END_SELECTION; cnt++)
		D_80129384[cnt] = 1;

	for (cnt=0; cnt<TITLE_END_SELECTION; cnt++)
		D_801293A0[cnt] = 1;

	// should cheat menu be displayed ?
	if (!GetApp()->m_dwEnabledCheatFlags)
	{
		D_80129384[PAUSE_CHEATMENU] = 0;
		D_801293A0[TITLE_CHEATMENU] = 0;
	}

	// Setup default selection
	pThis->m_Selection = PAUSE_RESUME ;
	pThis->m_RealSelection = 0;
}
