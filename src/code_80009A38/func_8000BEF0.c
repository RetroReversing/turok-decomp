#include "decompdecomp_sync_56fd028a8d024643fd98.h"
#line 1 "func.c"
#line 28 "reference.c"
void func_8000BEF0(CLoad *pThis)
{
	int	ret ;

	// Setup default selection
	pThis->m_ASelection = 0 ;
	pThis->m_BSelection = 0 ;
	pThis->m_Side = 1 ;

	pThis->m_FirstVisible = 0 ;
	pThis->m_MaxVisible = 8 ;

	pThis->m_Selection = 0 ;


	if (pThis->m_Mode == LOAD_NULL)
		pThis->m_Alpha = 0 ;


	GetApp()->m_bMessageBox = FALSE ;

	pThis->m_Mode = LOAD_FADEUP ;
	pThis->b_Active = TRUE ;

	// if setting up the file system causes an error, then use password
	SetupFileSystem() ;
	ret = SetupFileSystem() ;
//	if (	(ret == PFS_ERR_CONTRFAIL)
//		|| (ret == PFS_ERR_DEVICE)
//		|| (ret == PFS_ERR_ID_FATAL))
	if (ret == 4 || ret == 11 || ret == 10)
	{
		pThis->m_Mode = LOAD_FADEDOWN ;
		CMessageBox__Construct(&GetApp()->m_MessageBox,
									text_errorcontroller, text_pakdamaged) ;
		GetApp()->m_bMessageBox = TRUE ;
		GetApp()->m_MessageBox.b_Active = FALSE ;
	}
	else if (validpaks == 0 || ret == 1)
	{
		pThis->m_Mode = LOAD_FADEDOWN ;
		CMessageBox__Construct(&GetApp()->m_MessageBox,
									text_nocontroller, text_pakfound) ;
		GetApp()->m_bMessageBox = TRUE ;
		GetApp()->m_MessageBox.b_Active = FALSE ;
//		pThis->m_LoadType = LOAD_PASSWORD ;
//		pThis->m_EntryPos = password_nibbles ;
//		if (pThis->m_EntryPos)
//			pThis->m_Selection = LOADPASSWORD_ENTER ;
//		else
//			pThis->m_Selection = LOADPASSWORD_EXIT ;
	}
	else
	{
		pThis->m_LoadType = LOAD_MEMORYCARD ;
		ScanFileList(FALSE) ;
		if (TurokFiles==0)
			pThis->m_BSelection = LOADMEMORY_EXIT ;
	}
}

