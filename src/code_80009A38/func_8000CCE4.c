#include "decompdecomp_sync_ae870b7ff2c3a415f79d.h"
#line 1 "func.c"
#line 1290 "reference.c"
void func_8000CCE4(CSave *pThis)
{
	int	ret ;

	// Setup default selection
	pThis->m_ASelection = 0 ;
	pThis->m_BSelection = 0 ;
	pThis->m_Side = 1 ;

	pThis->m_Selection = 0 ;

	pThis->m_FirstVisible = 0 ;
	pThis->m_MaxVisible = 7 ;

	pThis->m_ShowAll = FALSE ;


	if (pThis->m_Mode == SAVE_NULL)
		pThis->m_Alpha = 0 ;

	pThis->m_Mode = SAVE_FADEUP ;
	pThis->b_Active = TRUE ;

	GetApp()->m_bRequestor = FALSE ;
	GetApp()->m_bMessageBox = FALSE ;

	// if setting up the file system causes an error, then use password
	SetupFileSystem() ;
	ret = SetupFileSystem() ;
//	if (	(ret == PFS_ERR_CONTRFAIL)
//		|| (ret == PFS_ERR_DEVICE)
//		|| (ret == PFS_ERR_ID_FATAL))
	if ((ret == 4) || (ret == 11) || (ret == 10))
	{
		pThis->m_Mode = SAVE_FADEDOWN ;
		func_8000E498(D_80119568,
									D_800B8148, D_800B815C) ;
		GetApp()->m_bMessageBox = TRUE ;
		GetApp()->messageActive = FALSE ;
	}
	else if ((validpaks == 0) || (ret == 1))
	{
		pThis->m_Mode = SAVE_FADEDOWN ;
		func_8000E498(D_80119568,
									D_800B7E50, D_800B7E60) ;
		GetApp()->m_bMessageBox = TRUE ;
		GetApp()->messageActive = FALSE ;
//		pThis->m_SaveType = SAVE_PASSWORD ;
//		CPassword__Create() ;
	}
	else
	{
		pThis->m_SaveType = SAVE_MEMORYCARD ;
		ScanFileList(pThis->m_ShowAll) ;
	}
	SaveRequestMode = NULL ;
}

