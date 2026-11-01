#include "decompdecomp_sync_02c817e3b9d1fe20b7c0.h"
#line 1 "func.c"
#line 586 "reference.c"
INT32 func_8000C04C(CLoad *pThis)
{
	INT32				ReturnValue = -1 ;
	int				ret ;

	if (GetApp()->m_bMessageBox)
	{
		ReturnValue = CMessageBox__Update(&GetApp()->m_MessageBox) ;
		if (ReturnValue != -1)
		{
			// force exit load and continue pause
			if (GetApp()->m_MessageBox.b_Active == FALSE)
			{
				pThis->m_Mode = LOAD_FADEDOWN ;
				GetApp()->m_Load.b_Active = FALSE ;
				GetApp()->m_Pause.m_Mode = PAUSE_FADEUP ;
			}
			GetApp()->m_MessageBox.m_Mode = MESSAGEBOX_FADEDOWN ;
			GetApp()->m_MessageBox.b_Active = FALSE ;
			ReturnValue = -1 ;
		}
	}

	else
	{
		// switch sides
		if (CEngineApp__MenuLeft(GetApp()))
			pThis->m_Side ^= 1 ;
		else if (CEngineApp__MenuRight(GetApp()))
			pThis->m_Side ^= 1 ;


		// Goto next selection?
		if (CEngineApp__MenuDown(GetApp()))
		{
			// name side
			if (pThis->m_Side == 0)
			{
				BarTimer = 0 ;
				pThis->m_ASelection++ ;
				if (pThis->m_ASelection >= TurokFiles)
					pThis->m_ASelection = 0 ;

				//i = pThis->m_ASelection + 3 ;
				//if (i >= TurokFiles)
				//	i-=TurokFiles ;
				//ReadFileIndex(i) ;

				//LoadBarrel.m_Direction = BARREL_DOWN ;
				//LoadBarrel.m_Selected = pThis->m_Selection ;
			}
			// options side
			else
			{
				BarTimer = 0 ;
				pThis->m_BSelection++ ;
				if (pThis->m_BSelection >= LOADMEMORY_END_SELECTION)
					pThis->m_BSelection = 0 ;
			}
		}

		// Goto previous selection?
		if (CEngineApp__MenuUp(GetApp()))
		{
			// name side
			if (pThis->m_Side == 0)
			{
				BarTimer = 0 ;
				pThis->m_ASelection-- ;
				if (pThis->m_ASelection < 0)
				{
					if (TurokFiles)
						pThis->m_ASelection = TurokFiles-1 ;
					else
						pThis->m_ASelection = 0 ;
				}

				//i = pThis->m_Selection + 3 ;
				//if (i >= TurokFiles)
				//	i-=TurokFiles ;
				//ReadFileIndex(i) ;
			
				//LoadBarrel.m_Direction = BARREL_UP ;
				//LoadBarrel.m_Selected = pThis->m_Selection ;
			}
			// options side
			else
			{
				BarTimer = 0 ;
				pThis->m_BSelection-- ;
				if (pThis->m_BSelection < 0)
					pThis->m_BSelection = LOADMEMORY_END_SELECTION-1 ;
			}
		}

		// Exit if start pressed
		if (CTControl__IsUseMenu(pCTControl))
			ReturnValue = pThis->m_BSelection ;

		switch (ReturnValue)
		{
			case LOADMEMORY_LOAD:
				if (TurokFiles)
				{
					ret = LoadCurrent(pThis->m_ASelection) ;

					switch (ret)
					{
						case 0:
							CTMove__CTMove() ;

							// done in tengine when loaded
							CLoad__ExtractData() ;
							CEngineApp__ResetBossVars(GetApp()) ;

							// force exit pause and goto waitfordisplay....
							pThis->m_Mode = LOAD_FADEDOWN ;
							GetApp()->m_bPause = FALSE ;
							GetApp()->m_Pause.m_Mode = PAUSE_NULL ;

							GetApp()->m_WarpID = CTurokMovement.CurrentCheckpoint ;
							GetApp()->m_UseCinemaWarp = 0 ;

							GetApp()->m_JustLoadedGame = TRUE ;
							CEngineApp__SetupFadeTo(GetApp(), MODE_RESETLEVEL) ;
							break ;

						case -1:
							CMessageBox__Construct(&GetApp()->m_MessageBox,
														text_incompatible, text_gamenotloaded) ;
							GetApp()->m_bMessageBox = TRUE ;
							ReturnValue = -1 ;
							break ;

                        case 3:
                        case 5:
                        case 10:
                            CMessageBox__Construct(&GetApp()->m_MessageBox,
                                D_800B8148, D_800B815C);
                            GetApp()->m_bMessageBox = TRUE;
                            ReturnValue = -1;
                            break;

						default:
							CMessageBox__Construct(&GetApp()->m_MessageBox,
														text_error, text_gamenotloaded) ;
							GetApp()->m_bMessageBox = TRUE ;
							ReturnValue = -1 ;
							break ;
					}
				}
				else
				{
					CMessageBox__Construct(&GetApp()->m_MessageBox,
												text_novalidfiles, text_gamenotloaded) ;
					GetApp()->m_bMessageBox = TRUE ;
					ReturnValue = -1 ;
				}
				ScanFileList(FALSE);
				break ;

			case LOADMEMORY_EXIT:
				pThis->m_Mode = LOAD_FADEDOWN ;
				break ;
		}

			// load game
			//CMessageBox__Construct(&GetApp()->m_MessageBox, pThis->m_pCTControl,
			//								"game loaded", "checksum ok") ;
			//GetApp()->m_bMessageBox = TRUE ;
			//ReturnValue = -1 ;
	}

     
                                                                       
                                                                     
                                                                  
                                                              
                             
                            
                                                 
                                               
      



	return ReturnValue ;
}

