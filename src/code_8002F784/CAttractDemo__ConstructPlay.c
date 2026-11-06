#include "common_local_source_4686.h"

#line 1 "reference.c"
void CAttractDemo__ConstructPlay(UINT8 *pDemo)
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
	CAttractBuffer__Construct(&pThis->m_ButtonBuffer, pData, pHeader->m_ButtonStartBit,
									 CAttractBuffer__ReadButton,
									 NULL,	// CAttractBuffer__WriteButton
									 NULL) ;	// CAttractBuffer__GetButton

	// Prepare stick x playback
	CAttractBuffer__Construct(&pThis->m_StickXBuffer, pData, pHeader->m_StickXStartBit,
									 CAttractBuffer__ReadStick,
									 NULL,	// CAttractBuffer__WriteStick
									 NULL) ; // CAttractBuffer__GetStickX

	// Prepare stick y playback
	CAttractBuffer__Construct(&pThis->m_StickYBuffer, pData, pHeader->m_StickYStartBit,
									 CAttractBuffer__ReadStick,
									 NULL,	// CAttractBuffer__WriteStick
									 NULL) ;	// CAttractBuffer__GetStickY

	// Prepare framerate playback
	CAttractBuffer__Construct(&pThis->m_NextFieldsBuffer, pData, pHeader->m_NextFieldsStartBit,
									 CAttractBuffer__ReadNextFields,
									 NULL,	// CAttractBuffer__WriteNextFields
									 NULL) ;	// CAttractBuffer__GetNextFields

	// Reset misc
	pThis->m_PlayRecordFrame = 0 ;
	pThis->m_TotalFrames = pHeader->m_TotalFrames ;
	pThis->m_TotalTime = 0 ;
	pThis->m_Checksum = 0 ;
}
