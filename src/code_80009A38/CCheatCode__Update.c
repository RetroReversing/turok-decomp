#include "decompdecomp_sync_4bf2f2a16ac58b7c1683.h"
#line 1 "func.c"
#line 3303 "reference.c"
INT32 CCheatCode__Update(CCheatCode *pThis)
{
	INT32				ReturnValue = -1 ;
	INT32				i, cheat ;

	if (GetApp()->m_bMessageBox)
	{
		ReturnValue = CMessageBox__Update(&GetApp()->m_MessageBox) ;
		if (ReturnValue != -1)
		{
			GetApp()->m_bMessageBox = FALSE ;
			ReturnValue = -1 ;
		}
	}

	else
	{
		// Goto next selection?
		if (CEngineApp__MenuDown(GetApp()))
			CCheatCode__PasswordDOWN(pThis) ;

		// Goto previous selection?
		if (CEngineApp__MenuUp(GetApp()))
			CCheatCode__PasswordUP(pThis) ;


		// any sub items
//		if (loadpassword_text[pThis->m_Selection].items)
//		{
			// Goto left selection?
			if (CEngineApp__MenuLeft(GetApp()))
   			CCheatCode__PasswordLEFT(pThis) ;

			// Goto right selection?
			if (CEngineApp__MenuRight(GetApp()))
				CCheatCode__PasswordRIGHT(pThis) ;
//		}



		// Exit if start pressed
		// returns to game when exited
		if (CTControl__IsUseMenu(pCTControl))
		{
			ReturnValue = pThis->m_Selection ;

#define	MAX_CHEATCODE		18			// MAKE THIS EVEN!!!
			if (cheatcode_nibbles == MAX_CHEATCODE)
				pThis->m_EntryPos = cheatcode_nibbles-1 ;

			switch (ReturnValue)
			{
				case CHEATCODE_GRID1:
					cheatcode_string[pThis->m_EntryPos] = 0 + pThis->m_SubSelection ;
					if (cheatcode_nibbles < MAX_CHEATCODE)
					{
						cheatcode_nibbles++ ;
						pThis->m_EntryPos++ ;
					}
					ReturnValue = -1 ;
					break ;
				case CHEATCODE_GRID2:
					cheatcode_string[pThis->m_EntryPos] = 4 + pThis->m_SubSelection ;
					if (cheatcode_nibbles < MAX_CHEATCODE)
					{
						cheatcode_nibbles++ ;
						pThis->m_EntryPos++ ;
					}
					ReturnValue = -1 ;
					break ;
				case CHEATCODE_GRID3:
					cheatcode_string[pThis->m_EntryPos] = 8 + pThis->m_SubSelection ;
					if (cheatcode_nibbles < MAX_CHEATCODE)
					{
						cheatcode_nibbles++ ;
						pThis->m_EntryPos++ ;
					}
					ReturnValue = -1 ;
					break ;
				case CHEATCODE_GRID4:
					cheatcode_string[pThis->m_EntryPos] = 12 + pThis->m_SubSelection ;
					if (cheatcode_nibbles < MAX_CHEATCODE)
					{
						cheatcode_nibbles++ ;
						pThis->m_EntryPos++ ;
					}
					ReturnValue = -1 ;
					break ;

				
				case CHEATCODE_DELETE:
					if (pThis->m_EntryPos)
					{
						pThis->m_EntryPos-- ;
						cheatcode_nibbles-- ;
					}
					ReturnValue = -1 ;
					break ;

				case CHEATCODE_ENTER:
					// clear the data
					CCheatCode__ClearData() ;

					// convert current string to data
					CCheatCode__ConvertStringToData() ;

					// search through all cheat codes
					cheat = -1 ;
					for (i=0; i<(sizeof(cheatcodes)/sizeof(t_cheatcode)); i++)
					{
						if (cheatcode_nibbles == cheatcodes[i].length)
						{
							if (CheckCheatCode(i))
							{
								cheat = i ;
								break ;
							}
						}
					}
					// activate cheat?
					if (cheat != -1)
					{
						GetApp()->m_dwEnabledCheatFlags |= cheatcodes[cheat].flags ;
						CMessageBox__Construct(&GetApp()->m_MessageBox,
													cheatcodes[cheat].string, text_activated) ;
						GetApp()->m_bMessageBox = TRUE ;
					}
					else
					{
						CMessageBox__Construct(&GetApp()->m_MessageBox,
													text_invalid, text_code) ;
						GetApp()->m_bMessageBox = TRUE ;
					}
					ReturnValue = -1 ;
					break ;

				case CHEATCODE_EXIT:
					pThis->m_Mode = CHEATCODE_FADEDOWN ;
					break ;
			}
		}
	}


	return ReturnValue ;
}

