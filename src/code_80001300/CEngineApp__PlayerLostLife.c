#include "common_local_source_3699.h"

#line 1 "reference.c"
void CEngineApp__PlayerLostLife(CEngineApp *pThis)
{
	if (!pThis->m_bGameOver)
	{
		if (CTMove__DecreaseLives(&D_80128C20))
		{
			CEngineApp__NewLife(pThis) ;

			if (	(pThis->m_CurrentWarpID >=9000)
				&& (pThis->m_CurrentWarpID < 9999))
			{
				pThis->m_WarpID = RETURN_WARP_ID ;
			}
			else
			{
				pThis->m_CinemaFlags |= CINEMA_FLAG_PLAY_RESURRECT ;
			}
		}
		else
		{
			pThis->m_bGameOver = TRUE ;
			pThis->m_GameOverAlpha = 0 ;
			pThis->m_GameOverMode = 0 ;
			pThis->m_GameOverTime = SECONDS_TO_FRAMES(4) ;
		}
	}
}
