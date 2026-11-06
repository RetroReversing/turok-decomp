#include "decompdecomp_sync_8259b88657ce15479773.h"
#line 2675 "reference.c"
/* menu control up ? */ BOOL CEngineApp__MenuUp(CEngineApp *pThis)
{
	float	res;

	if (pThis->m_FadeStatus == FADE_DOWN)
		return FALSE ;


	// check for digital use of menus
	if (		(CTControl__IsClickUp(pCTControl))
			&& (pThis->m_MenuUpChangeCount == MENU_START_SPEED)
			&& (pThis->m_MenuDownChangeCount == MENU_START_SPEED)
			&& (pThis->m_MenuRightChangeCount == MENU_START_SPEED)
			&& (pThis->m_MenuLeftChangeCount == MENU_START_SPEED) )
	{
		pThis->m_MenuUpChangeCount = MENU_START_SPEED;
		CScene__DoSoundEffect(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &pThis->m_Camera.m_vPos, 0);
		return TRUE;
	}
	else
	{
		res = CTControl__IsAnalogUp(pCTControl);
		if (res<= MENU_VERTICAL_THRESHHOLD)
		{
			pThis->m_MenuUpChangeCount = MENU_START_SPEED;
			return FALSE;
		}
		else
		{
			pThis->m_MenuUpChangeCount += res * frame_increment;
			if (pThis->m_MenuUpChangeCount >= MAX_MENU_SPEED)
			{
				pThis->m_MenuUpChangeCount = 0;
				CScene__DoSoundEffect(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &pThis->m_Camera.m_vPos, 0);
				return TRUE;
			}
			else
				return FALSE;
		}
	}
}
