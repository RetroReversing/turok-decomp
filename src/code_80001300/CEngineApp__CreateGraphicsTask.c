#include "common_local_source_3721.h"

#line 1 "reference.c"
CFrameData* CEngineApp__CreateGraphicsTask(CEngineApp *pThis)
{
	CFrameData	*pFData;
	OSTime		startTime;

	pFData = CEngineApp__GetFrameData(pThis);

	if ((pThis->m_Mode == MODE_GAME) || (pThis->m_Mode == MODE_GAMEOVER))
	{
		// Update on screen overlays
		COnScreen__Update(&pThis->m_OnScreen);
	}

	// build display list for next frame
	startTime = D_8009D2D0();

	switch (pThis->m_Mode)
	{
		case MODE_INTRO:
		case MODE_GAME:
		case MODE_GAMEOVER:
		case MODE_LEGALSCREEN:
		case MODE_GAMEPAK:
		case MODE_TITLE:
		case MODE_CREDITS:
		case MODE_GALLERY:
			CEngineApp__BuildDispList(pThis);
			break;

		default:
			ASSERT(FALSE);
			break;
	}

	D_800B6B2C = __ull_to_f(__ull_div(((u64)(D_8009D2D0()-startTime))*1000000000LL,D_800EE4D0))/1000000;

	// end the display list
	gDPFullSync(pThis->m_pDLP++);
	gSPEndDisplayList(pThis->m_pDLP++);

	pFData->m_DisplayListSize = (((DWORD)pThis->m_pDLP) - ((DWORD)pFData->m_pDisplayList));

#ifndef MAKE_CART
	if ((pThis->m_pDLP - pFData->m_pDisplayList) > GLIST_LEN)
		rmonPrintf("over by:%d\n", (pThis->m_pDLP - pFData->m_pDisplayList) - GLIST_LEN) ;
#endif

	ASSERT((pThis->m_pDLP - pFData->m_pDisplayList) < GLIST_LEN);

// CARL, make 1 to draw map
#if 1
	pFData->m_DrawMap = (pThis->m_MapMode && (pThis->m_Mode == MODE_GAME) && D_800B6B38);
#else
	pFData->m_DrawMap = FALSE;
#endif

	// line draw display list
	if (pFData->m_DrawMap)
	{
		pThis->m_pDLP = CEngineApp__GetFrameData(pThis)->m_pLineList;

		CEngineApp__DrawMap(pThis);

		gDPFullSync(pThis->m_pDLP++);
		gSPEndDisplayList(pThis->m_pDLP++);

		pFData->m_LineListSize = (((DWORD)pThis->m_pDLP) - ((DWORD)pFData->m_pLineList));
		ASSERT((pThis->m_pDLP - pFData->m_pLineList) < LINELIST_LEN);
	}
	// map is not being drawn, but still needs to know what is revealed by player, so update silently...
	else
		CEngineApp__RevealMap(pThis) ;

	return pFData;
}
