#include "common_local_source_5591.h"

#line 1850 "reference.c"
void func_80090330(CGameObjectInstance *pThis)
{
	int		prev ;

	switch (AI_GetEA(pThis)->m_Id)
	{
		case 2:
			prev = CTurokMovement.Level2Access ;
			CTurokMovement.Level2Access = 0 ;
			if (CTurokMovement.Level2Keys &1)
				CTurokMovement.Level2Access++ ;
			if (CTurokMovement.Level2Keys &2)
				CTurokMovement.Level2Access++ ;
			if (CTurokMovement.Level2Keys &4)
				CTurokMovement.Level2Access++ ;

			if (CTurokMovement.Level2Access != prev)
				AI_DoSound((CInstanceHdr *)pThis, 206, 1, 0);
			break ;

		case 3:
			prev = CTurokMovement.Level3Access ;
			CTurokMovement.Level3Access = 0 ;
			if (CTurokMovement.Level3Keys &1)
				CTurokMovement.Level3Access++ ;
			if (CTurokMovement.Level3Keys &2)
				CTurokMovement.Level3Access++ ;
			if (CTurokMovement.Level3Keys &4)
				CTurokMovement.Level3Access++ ;

			if (CTurokMovement.Level3Access != prev)
				AI_DoSound((CInstanceHdr *)pThis, 206, 1, 0);
			break ;

		case 4:
			prev = CTurokMovement.Level4Access ;
			CTurokMovement.Level4Access = 0 ;
			if (CTurokMovement.Level4Keys &1)
				CTurokMovement.Level4Access++ ;
			if (CTurokMovement.Level4Keys &2)
				CTurokMovement.Level4Access++ ;
			if (CTurokMovement.Level4Keys &4)
				CTurokMovement.Level4Access++ ;

			if (CTurokMovement.Level4Access != prev)
				AI_DoSound((CInstanceHdr *)pThis, 206, 1, 0);
			break ;

		case 5:
			prev = CTurokMovement.Level5Access ;
			CTurokMovement.Level5Access = 0 ;
			if (CTurokMovement.Level5Keys &1)
				CTurokMovement.Level5Access++ ;
			if (CTurokMovement.Level5Keys &2)
				CTurokMovement.Level5Access++ ;
			if (CTurokMovement.Level5Keys &4)
				CTurokMovement.Level5Access++ ;

			if (CTurokMovement.Level5Access != prev)
				AI_DoSound((CInstanceHdr *)pThis, 206, 1, 0);
			break ;

		case 6:
			prev = CTurokMovement.Level6Access ;
			CTurokMovement.Level6Access = 0 ;
			if (CTurokMovement.Level6Keys &1)
				CTurokMovement.Level6Access++ ;
			if (CTurokMovement.Level6Keys &2)
				CTurokMovement.Level6Access++ ;
			if (CTurokMovement.Level6Keys &4)
				CTurokMovement.Level6Access++ ;

			if (CTurokMovement.Level6Access != prev)
				AI_DoSound((CInstanceHdr *)pThis, 206, 1, 0);
			break ;

		case 7:
			prev = CTurokMovement.Level7Access ;
			CTurokMovement.Level7Access = 0 ;
			if (CTurokMovement.Level7Keys &1)
				CTurokMovement.Level7Access++ ;
			if (CTurokMovement.Level7Keys &2)
				CTurokMovement.Level7Access++ ;
			if (CTurokMovement.Level7Keys &4)
				CTurokMovement.Level7Access++ ;

			if (CTurokMovement.Level7Access != prev)
				AI_DoSound((CInstanceHdr *)pThis, 206, 1, 0);
			break ;

		// at least one had to be different!
		case 8:
			prev = CTurokMovement.Level8Access ;
			CTurokMovement.Level8Access = 0 ;
			if (CTurokMovement.Level8Keys &1)
				CTurokMovement.Level8Access++ ;
			if (CTurokMovement.Level8Keys &2)
				CTurokMovement.Level8Access++ ;
			if (CTurokMovement.Level8Keys &4)
				CTurokMovement.Level8Access++ ;
			if (CTurokMovement.Level8Keys &8)
				CTurokMovement.Level8Access++ ;
			if (CTurokMovement.Level8Keys &16)
				CTurokMovement.Level8Access++ ;

			if (CTurokMovement.Level8Access != prev)
				AI_DoSound((CInstanceHdr *)pThis, 206, 1, 0);

			if ((CTurokMovement.Level8Access >= MAX_KEY8) && (!(pThis->m_AI.m_dwStatusFlags & AI_STARTED)))
			{
				pThis->m_AI.m_Time1 = 0 ;
				pThis->m_AI.m_dwStatusFlags |= (AI_STARTED | AI_DOOROPEN) ;
				pThis->m_AI.m_dwStatusFlags &= ~AI_DOORPREOPEN;

				// store original positions
				pThis->m_AI.m_Time2 = pThis->ah.ih.m_vPos.y ;
				pThis->m_AI.m_TeleportTime = func_80019D3C(pThis->ah.ih.m_pCurrentRegion, pThis->ah.ih.m_vPos.x, pThis->ah.ih.m_vPos.z) ;

				// keep state for saved game
				CScene__SetInstanceFlag(&GetApp()->m_Scene, pThis, TRUE);
			}
			break ;
	}
}
