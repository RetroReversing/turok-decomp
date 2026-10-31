#include "common_local_source_4686.h"

#line 1 "reference.c"
void func_8004FD78(UINT8 *pDemo)
{
	CAttractDemo	*pThis = &D_80128140 ;
	CAttractHeader *pHeader = (CAttractHeader *)pDemo ;
	UINT8				*pData = (UINT8 *)pDemo ;

	pThis->m_Active = FALSE ;
	pThis->m_Record = FALSE ;
	pThis->m_Play = TRUE ;
	pThis->m_Finished = FALSE ;
	pThis->m_FirstFrame = TRUE ;

	// Set the level
	GetApp()->m_WarpID = pHeader->m_WarpID ;

	// Prepare button playback
	func_8004F910(&pThis->m_ButtonBuffer, pData, pHeader->m_ButtonStartBit,
									 func_8004FACC,
									 NULL,	// CAttractBuffer__WriteButton
									 NULL) ;	// CAttractBuffer__GetButton

	// Prepare stick x playback
	func_8004F910(&pThis->m_StickXBuffer, pData, pHeader->m_StickXStartBit,
									 func_8004FBC0,
									 NULL,	// CAttractBuffer__WriteStick
									 NULL) ; // CAttractBuffer__GetStickX

	// Prepare stick y playback
	func_8004F910(&pThis->m_StickYBuffer, pData, pHeader->m_StickYStartBit,
									 func_8004FBC0,
									 NULL,	// CAttractBuffer__WriteStick
									 NULL) ;	// CAttractBuffer__GetStickY

	// Prepare framerate playback
	func_8004F910(&pThis->m_NextFieldsBuffer, pData, pHeader->m_NextFieldsStartBit,
									 func_8004FBF0,
									 NULL,	// CAttractBuffer__WriteNextFields
									 NULL) ;	// CAttractBuffer__GetNextFields

	// Reset misc
	pThis->m_PlayRecordFrame = 0 ;
	pThis->m_TotalFrames = pHeader->m_TotalFrames ;
	pThis->m_TotalTime = 0 ;
	pThis->m_Checksum = 0 ;
}
