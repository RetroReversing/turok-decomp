#include "decompdecomp_sync_4f30d4b42a39f946d62d.h"
#line 1 "func.c"
#line 1059 "reference.c"
INT32 func_80084E9C(CPause *pThis)
{
	INT32				ReturnValue = -1 ;


           
                         
                      
      

	D_80128C20.InMenuTimer = .3 ;

	// force the icons to be displayed
	GetApp()->m_OnScreen.m_Lives = -1 ;
	GetApp()->m_OnScreen.m_Tokens = -1 ;
	COnScreen__SetLives(&GetApp()->m_OnScreen, D_80128C20.Lives);
	COnScreen__SetTokens(&GetApp()->m_OnScreen, D_80128C20.Tokens);

	// do cheat options
	if (GetApp()->m_Cheat.b_Active)
	{
		GetApp()->m_ModeTime = 0 ;
		// returns quite a lot of stuff
		ReturnValue = func_80088124(&GetApp()->m_Cheat) ;
		if (ReturnValue != -1)
		{
			pThis->m_Mode = PAUSE_FADEUP ;
			GetApp()->m_Cheat.b_Active = FALSE ;
			CPause__ResetMenuItems(pThis);
		}
		ReturnValue = -1 ;
	}

	// do cheatcode options
	else if (GetApp()->m_CheatCode.b_Active)
	{
		GetApp()->m_ModeTime = 0 ;
		// returns quite a lot of stuff
		ReturnValue = CCheatCode__Update(&GetApp()->m_CheatCode) ;
		if (ReturnValue != -1)
		{
			pThis->m_Mode = PAUSE_FADEUP ;
			GetApp()->m_CheatCode.b_Active = FALSE ;
			CPause__ResetMenuItems(pThis);
		}
		ReturnValue = -1 ;
	}

	// do givecheatcode options
	else if (GetApp()->m_GiveCheatCode.b_Active)
	{
		GetApp()->m_ModeTime = 0 ;
		ReturnValue = CGiveCheatCode__Update(&GetApp()->m_GiveCheatCode) ;
		if (ReturnValue != -1)
		{
			pThis->m_Mode = PAUSE_FADEUP ;
			GetApp()->m_GiveCheatCode.b_Active = FALSE ;
			CPause__ResetMenuItems(pThis);
		}
		ReturnValue = -1 ;
	}


	// do game options
	else if (GetApp()->m_Options.b_Active)
	{
		GetApp()->m_ModeTime = 0 ;
		// returns quite a lot of stuff
		ReturnValue = COptions__Update(&GetApp()->m_Options) ;
		if (ReturnValue != -1)
		{
			pThis->m_Mode = PAUSE_FADEUP ;
			GetApp()->m_Options.b_Active = FALSE ;
			CPause__ResetMenuItems(pThis);
		}
		ReturnValue = -1 ;
	}


	// do key options
	else if (GetApp()->m_Keys.b_Active)
	{
		GetApp()->m_ModeTime = 0 ;
		ReturnValue = CKeys__Update(&GetApp()->m_Keys) ;
		if (ReturnValue != -1)
		{
			pThis->m_Mode = PAUSE_FADEUP ;
			GetApp()->m_Keys.b_Active = FALSE ;
			CPause__ResetMenuItems(pThis);
		}
		ReturnValue = -1 ;
	}


	// do load options
	else if (GetApp()->m_Load.b_Active)
	{
		GetApp()->m_ModeTime = 0 ;
		// will only return -1 or LOAD_EXIT
		ReturnValue = func_8000C02C(&GetApp()->m_Load) ;
		if (ReturnValue != -1)
		{
			CPause__ResetMenuItems(pThis);
			pThis->m_Mode = PAUSE_FADEUP ;
			GetApp()->m_Load.b_Active = FALSE ;
			ReturnValue = -1 ;
			CPause__ResetMenuItems(pThis);
		}
	}

	// do save options - ONLY FROM REQUESTOR (NO LONGER PART OF PAUSE) SO QUIT TO GAME ON EXIT
	else if (GetApp()->m_Save.b_Active)
	{
		GetApp()->m_ModeTime = 0 ;
		// will only return -1 or SAVE_EXIT
		ReturnValue = CSave__Update(&GetApp()->m_Save) ;
		if (ReturnValue != -1)
		{
			GetApp()->m_Pause.m_Mode = PAUSE_FADEDOWN ;
			GetApp()->m_bPause = FALSE ;

			//pThis->m_Mode = PAUSE_FADEUP ;
			GetApp()->m_Save.b_Active = FALSE ;
			ReturnValue = -1 ;
			//pThis->m_Selection = PAUSE_RESUME ;
		}
	}

	// do you wish to save?
	else if (GetApp()->m_Requestor.b_Active)
	{
		GetApp()->m_ModeTime = 0 ;
		ReturnValue = CRequestor__Update(&GetApp()->m_Requestor) ;
		if (ReturnValue != -1)
		{
			switch (D_80129380)
			{
				case NULL:
					// do save
					if (ReturnValue == REQUESTOR_YES)
					{
						CSave__Construct(&GetApp()->m_Save) ;
						GetApp()->m_bSave = TRUE ;
					}
					// return to game
					else
					{
						GetApp()->m_Pause.m_Mode = PAUSE_FADEDOWN ;
						GetApp()->m_bPause = FALSE ;
					}
					ReturnValue = -1 ;
					break ;

				case PAUSE_RESTART_GAME:
					if (ReturnValue == REQUESTOR_YES)
					{
						ReturnValue = PAUSE_RESTART_GAME ;
						D_80129380 = NULL ;
						GetApp()->m_Pause.m_Mode = PAUSE_FADEDOWN ;
						GetApp()->m_bPause = FALSE ;
					}
					else
						ReturnValue = -1 ;
					break ;

				case TITLE_TRAINING:
					GetApp()->m_bTrainingMode = TRUE ;
					pThis->m_Mode = PAUSE_FADEDOWN ;

					if (ReturnValue == REQUESTOR_YES)
						GetApp()->m_TrainingType = 0 ;
					else
						GetApp()->m_TrainingType = 1 ;
					break ;

				// exit from training level
				case -1:
					if (ReturnValue == REQUESTOR_YES)
						ReturnValue = PAUSE_RESTART_GAME ;
					else
						ReturnValue = -1 ;

					D_80129380 = NULL ;
					GetApp()->m_Pause.m_Mode = PAUSE_FADEDOWN ;
					GetApp()->m_bPause = FALSE ;
					break ;
			}
			GetApp()->m_Requestor.m_Mode = REQUESTOR_FADEDOWN ;
			GetApp()->m_Requestor.b_Active = FALSE ;

		}
	}
	// only from titlescreen for DAMAGED CONTROLLER message
	else if (GetApp()->m_MessageBox.b_Active == 2)
	{
		GetApp()->m_ModeTime = 0 ;
		ReturnValue = CMessageBox__Update(&GetApp()->m_MessageBox) ;
		if (ReturnValue != -1)
		{
			ReturnValue = -1 ;
			GetApp()->m_MessageBox.m_Mode = MESSAGEBOX_FADEDOWN ;
			GetApp()->m_MessageBox.b_Active = FALSE ;
		}

	}


	// do pause options
	else
	{
		if (GetApp()->m_Mode == MODE_TITLE)
		{
			// in title mode
			if (CEngineApp__MenuDown(GetApp()))
			{
				D_800EC0C0 = 0 ;
				GetApp()->m_ModeTime = 0 ;
				do
				{
					pThis->m_Selection++ ;
					if (pThis->m_Selection >= TITLE_END_SELECTION)
						pThis->m_Selection = 0 ;

				} while (!D_801293A0[pThis->m_Selection]);

				pThis->m_RealSelection++;
				if (pThis->m_RealSelection >= CPause__GetTitleOptionAmt(pThis))
					pThis->m_RealSelection = 0;


            
             
                                                                         
                                      
       

			}

			if (CEngineApp__MenuUp(GetApp()))
			{
				D_800EC0C0 = 0 ;
				GetApp()->m_ModeTime = 0 ;
				do
				{
					pThis->m_Selection-- ;
					if (pThis->m_Selection < 0)
						pThis->m_Selection = TITLE_END_SELECTION-1 ;

				} while (!D_801293A0[pThis->m_Selection]);

				pThis->m_RealSelection--;
				if (pThis->m_RealSelection < 0)
					pThis->m_RealSelection = CPause__GetTitleOptionAmt(pThis)-1;

            
             
                  
                
                                      
       

			}
		}
		else
		{
			// in pause mode
			if (CEngineApp__MenuDown(GetApp()))
			{
				D_800EC0C0 = 0 ;
				do
				{
					pThis->m_Selection++ ;
					if (pThis->m_Selection >= PAUSE_END_SELECTION)
						pThis->m_Selection = 0 ;

				} while (!D_80129384[pThis->m_Selection]);

				pThis->m_RealSelection++;
				if (pThis->m_RealSelection >= CPause__GetPauseOptionAmt(pThis))
					pThis->m_RealSelection = 0;

            
             
                                      
       

			}

			if (CEngineApp__MenuUp(GetApp()))
			{
				D_800EC0C0 = 0 ;
				do
				{
					pThis->m_Selection-- ;
					if (pThis->m_Selection < 0)
						pThis->m_Selection = PAUSE_END_SELECTION-1 ;

				} while (!D_80129384[pThis->m_Selection]);

				pThis->m_RealSelection--;
				if (pThis->m_RealSelection < 0)
					pThis->m_RealSelection = CPause__GetPauseOptionAmt(pThis)-1;

            
             
                  
                
                                      
       

			}
		}

            

                                          
   
                                                                                 
   

                                               
                

       

            

                                            
   
                
                                         
   

                                           
   
                
                  
                
                                         
   

       


		// Exit if start pressed
		if (CTControl__IsUseMenu(D_800F9E44))
			ReturnValue = pThis->m_Selection ;

		// do corresponding action TITLE SCREEN
		if (GetApp()->m_Mode == MODE_TITLE)
		{
			switch (ReturnValue)
			{
				case TITLE_LOAD:
					ReturnValue = -1 ;
					pThis->m_Mode = PAUSE_FADEDOWN ;

					func_8000BEF0(&GetApp()->m_Load) ;
					GetApp()->m_bLoad = TRUE ;
					break ;

				case TITLE_OPTIONS:
					ReturnValue = -1 ;
					pThis->m_Mode = PAUSE_FADEDOWN ;

					COptions__Construct(&GetApp()->m_Options) ;
					GetApp()->m_bOptions = TRUE ;
					break ;

				case TITLE_DIFFICULTY:
					GetApp()->m_ModeTime = 0 ;
					ReturnValue = -1 ;
					GetApp()->m_Difficulty++ ;
					if (GetApp()->m_Difficulty > 2)
						GetApp()->m_Difficulty=0 ;
					break ;


				case TITLE_START:
					pThis->m_Mode = PAUSE_FADEDOWN ;
					break ;

				case TITLE_TRAINING:
					CRequestor__Construct(&GetApp()->m_Requestor,
									D_800EC170, D_800EC17C) ;
					GetApp()->m_Requestor.Selections = D_800EC1D4 ;
					GetApp()->m_bRequestor = TRUE ;
					D_80129380 = TITLE_TRAINING ;
					ReturnValue = -1 ;

//					GetApp()->m_bTrainingMode = TRUE ;
//					pThis->m_Mode = PAUSE_FADEDOWN ;
					break ;


				case TITLE_CHEATMENU:
					ReturnValue = -1 ;

					pThis->m_Mode = PAUSE_FADEDOWN ;

					CCheat__Construct(&GetApp()->m_Cheat) ;
					GetApp()->m_bCheat = TRUE ;
					break;

				case TITLE_ENTERCHEAT:
					ReturnValue = -1 ;

					pThis->m_Mode = PAUSE_FADEDOWN ;

					CCheatCode__Construct(&GetApp()->m_CheatCode) ;
					GetApp()->m_bCheatCode = TRUE ;
					break ;

			}
		}
		// do corresponding action GAME PAUSED
		else
		{
			switch (ReturnValue)
			{
               
                     
                       
                                 
            
      
				case PAUSE_ENTERCHEAT:
					ReturnValue = -1 ;

					pThis->m_Mode = PAUSE_FADEDOWN ;

					CCheatCode__Construct(&GetApp()->m_CheatCode) ;
					GetApp()->m_bCheatCode = TRUE ;
					break ;

				case PAUSE_CHEATMENU:
					ReturnValue = -1 ;

					pThis->m_Mode = PAUSE_FADEDOWN ;

					CCheat__Construct(&GetApp()->m_Cheat) ;
					GetApp()->m_bCheat = TRUE ;
					break ;

				case PAUSE_LOAD:
					ReturnValue = -1 ;
					pThis->m_Mode = PAUSE_FADEDOWN ;

					func_8000BEF0(&GetApp()->m_Load) ;
					GetApp()->m_bLoad = TRUE ;
					break ;

                 
                    
                       
                                     

                                          
                               
            
      

				case PAUSE_OPTIONS:
					ReturnValue = -1 ;
					pThis->m_Mode = PAUSE_FADEDOWN ;

					COptions__Construct(&GetApp()->m_Options) ;
					GetApp()->m_bOptions = TRUE ;
					break ;

				case PAUSE_KEYS:
					ReturnValue = -1 ;
					pThis->m_Mode = PAUSE_FADEDOWN ;

					CKeys__Construct(&GetApp()->m_Keys) ;
					GetApp()->m_bKeys = TRUE ;
					break ;

                          
                       
                       
                                     

                                                
                                           
                                  
            

                         
                       
                                     

                                                
                                             
                                  
            
      


				case PAUSE_RESUME:
//				case PAUSE_PREVLEVEL:
//				case PAUSE_NEXTLEVEL:
					pThis->m_Mode = PAUSE_FADEDOWN ;
					break ;

				case PAUSE_RESTART_GAME:
					CRequestor__Construct(&GetApp()->m_Requestor,
									D_800EC104, D_800EC18C) ;
					GetApp()->m_bRequestor = TRUE ;
					GetApp()->m_Requestor.m_Selection = REQUESTOR_NO ;
					D_80129380 = PAUSE_RESTART_GAME ;
					ReturnValue = -1 ;
					break ;

			}
		}
	}

	return ReturnValue ;
}

