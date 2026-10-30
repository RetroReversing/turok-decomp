#include "common_local_source_3723.h"

#line 1 "reference.c"
void func_8000826C(CEngineApp *pThis)
{
	INT32						ret;
	//CGameObjectInstance	*pPlayer;

	if (pThis->m_bTraining)
	{
		func_80087B38(&pThis->m_Training) ;

		if ((pThis->m_bTrainingMode == 2) && (func_80051EA4(D_800F9E44)))
		{
			pThis->m_bTrainingMode = FALSE ;
			pThis->m_bTraining	= FALSE;

//			pThis->m_WarpID = 0 ;
//			CEngineApp__SetupFadeTo(pThis, MODE_RESETLEVEL);
			func_80004504(pThis, MODE_RESETGAME);
		}
	}
	else if	(pThis->m_bPause)
	{
		// read pause info
		ret = func_80084E9C(&pThis->m_Pause);

		switch (ret)
		{
			case PAUSE_RESUME:
				pThis->m_bPause = FALSE ;
				break;
#if 0
			case PAUSE_PREVLEVEL:
				pThis->m_pBossActive = NULL ;
				pThis->m_bPause = FALSE;
				switch (pThis->m_WarpBase)
				{
					//case 9000:
					//case 9100:
					//case 9200:
					//case 9300:
					//case 9400:
					//case 9500:
					//case 9600:
					//case 9700:
					//case 9800:
					//	pThis->m_WarpBase -= 100 ;
					//	if (pThis->m_WarpBase <9000)
					//		pThis->m_WarpBase = 8000 ;	// goto lastlevel
					//	break ;

					//case 2000:
					//	pThis->m_WarpBase = 0 ;
					//	break ;


					default:
						pThis->m_WarpBase -= 1000 ;
						if (pThis->m_WarpBase < 0)
							pThis->m_WarpBase = 8000 ;
						break ;
				}
				pThis->m_WarpID = pThis->m_WarpBase ;
				CEngineApp__Warp(pThis, pThis->m_WarpID, WARP_BETWEENLEVELS, FALSE);
				break ;

			case PAUSE_NEXTLEVEL:
				pThis->m_pBossActive = NULL;
				pThis->m_bPause = FALSE;
				switch (pThis->m_WarpBase)
				{
					//case 9000:
					//case 9100:
					//case 9200:
					//case 9300:
					//case 9400:
					//case 9500:
					//case 9600:
					//case 9700:
					//case 9800:
					//	pThis->m_WarpBase += 100 ;
					//	if (pThis->m_WarpBase >9800)
					//		pThis->m_WarpBase = 20000 ;	// goto bosses
					//	break ;

					//case 0:
					//	pThis->m_WarpBase = 2000 ;
					//	break ;

					default:
						pThis->m_WarpBase += 1000 ;
						if (pThis->m_WarpBase > 8000)
							pThis->m_WarpBase = 0 ;
						break ;
				}
				pThis->m_WarpID = pThis->m_WarpBase ;
				CEngineApp__Warp(pThis, pThis->m_WarpID, WARP_BETWEENLEVELS, FALSE);
				break ;
#endif

			case PAUSE_RESTART_GAME:
				pThis->m_bPause = FALSE ;
				func_80004504(pThis, MODE_RESETGAME);
				break;
		}

		// if come out of pause
		if (pThis->m_bPause == FALSE)
		{
			D_800B6B04 = D_800B6B10;
			D_800B6B0C = D_800B6B18;
			D_800B6B08 = D_800B6B14;

			// switch volume back to what it was
//			pThis->m_ActualMusicVolume = pThis->m_Pause.m_MusicVolume;
//			pThis->m_ActualSFXVolume = pThis->m_Pause.m_SFXVolume;
		}
	}
	else
	{
		// Check for pausing game (also pauses if turok is dead!)

		if (		(func_800513F4(D_800F9E44))
				&& (!func_800510C4(D_800F9E44)) )
		{
			//CCartCache__MemoryDump(&pThis->m_Scene.m_Cache);

			// can only pause if not already paused, and no cinema is active!
			if ((pThis->m_bPause == FALSE) && (!func_80039B98(&pThis->m_Camera)))
			{
				// quit training mode?
				if (		((pThis->m_bTrainingMode == TRUE) || (pThis->m_bTrainingMode == -1))
						&& (!pThis->m_bTraining))
				{
					GetApp()->m_bPause = TRUE;
					func_80084BB0(&GetApp()->m_Pause);
					GetApp()->m_Pause.m_Mode = PAUSE_NORMAL;
					func_8000DEB8(&GetApp()->m_Requestor,
												D_800B6ACC, D_800B6ADC) ;
					GetApp()->m_bRequestor = TRUE ;
					GetApp()->m_Requestor.m_Selection = REQUESTOR_NO ;
					D_80129380 = -1 ;

					//CEngineApp__SetupFadeTo(pThis, MODE_RESETGAME);
				}
				else
				{
					// kill all sfx's going into pause menu
					func_8008A750();

					func_80006D14(pThis);
					pThis->m_Flash = 0;
				}
			}
		}
	}
}
