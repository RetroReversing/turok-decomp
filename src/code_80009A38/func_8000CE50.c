#include "decompdecomp_sync_8d942e4aae2bf705b999.h"
#line 1 "func.c"
#line 1369 "reference.c"
void func_8000CE50(int ret)
{
	switch (ret)
	{
		case 0:
			func_8000E498(D_80119568,
										D_800B7EB4, D_800B7EC8) ;
			GetApp()->m_bMessageBox = TRUE ;
			GetApp()->active = FALSE ;

			// force exit pause and continue game
			//pThis->m_Mode = SAVE_FADEDOWN ;
			//GetApp()->m_bPause = FALSE ;
			//GetApp()->m_Pause.m_Mode = PAUSE_NULL ;
			break ;

		case -1:
			func_8000E498(D_80119568,
										D_800B7ED8, D_800B7EE8) ;
			GetApp()->m_bMessageBox = TRUE ;
			break ;

		case PFS_DIR_FULL:
			func_8000E498(D_80119568,
										D_800B7EF8, D_800B7F10) ;
			GetApp()->m_bMessageBox = TRUE ;
			break ;

		case PFS_DATA_FULL:
			func_8000E498(D_80119568,
										D_800B7F08, D_800B7F10) ;
			GetApp()->m_bMessageBox = TRUE ;
			break ;


		case 3:
		case 5:
		case 10:
			func_8000E498(D_80119568,D_800B8148,D_800B815C);
			GetApp()->m_bMessageBox = TRUE;
			break;

		default:
			func_8000E498(D_80119568,
										D_800B7E7C, D_800B7F10) ;
			GetApp()->m_bMessageBox = TRUE ;
			break ;
	}
}

