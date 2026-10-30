#include "common_local_source_3698.h"

#line 1 "reference.c"
void func_80005388(CEngineApp *pThis)
{
	BYTE	color[4] = { 255, 0, 0, 255 };


	switch (pThis->m_Death)
	{
		case DEATH_DIEING:
			pThis->m_uDeath += D_800B6B00/DEATH_LENGTH;
			color[3] = min(255, pThis->m_uDeath*255);

// removed because it looks crap & also screws up the game over
//			CEngineApp__DrawTint(pThis, color);

			if ((pThis->m_uDeath >= 1) || (func_80039B98(&pThis->m_Camera)))
			{
				pThis->m_Death = DEATH_NOT_DIEING;
				pThis->m_uDeath = 1 ;

				if (pThis->m_bPause)
				{
					pThis->m_bPause = FALSE ;
					pThis->m_Pause.m_Mode = PAUSE_FADEDOWN ;
				}

				func_800055A8(pThis) ;
			}
			break;
	}
}
