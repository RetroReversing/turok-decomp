#include "decompdecomp_sync_6ce99e147b3681eabd85.h"
#line 1 "func.c"
#line 2541 "reference.c"
BOOL func_800061C4(CEngineApp *pThis)
{
	float	res;

	if (pThis->m_FadeStatus == FADE_DOWN)
		return FALSE ;

	// check for digital use of menus
	if (		(CTControl__IsClickLeft(pCTControl))
			&& (pThis->m_MenuLeftChangeCount == MENU_START_SPEED)
			&& (pThis->m_MenuRightChangeCount == MENU_START_SPEED)
			&& (pThis->m_MenuDownChangeCount == MENU_START_SPEED)
			&& (pThis->m_MenuUpChangeCount == MENU_START_SPEED) )
	{
		pThis->m_MenuLeftChangeCount = MENU_START_SPEED;
		CScene__DoSoundEffect(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &pThis->m_Camera.m_vPos, 0);
		return TRUE;
	}
	else
	{
		res = CTControl__IsAnalogLeft(pCTControl);
		if (res<= MENU_HORIZONTAL_THRESHHOLD)
		{
			pThis->m_MenuLeftChangeCount = MENU_START_SPEED;
			return FALSE;
		}
		else
		{
			pThis->m_MenuLeftChangeCount += res * frame_increment;
			if (pThis->m_MenuLeftChangeCount >= MAX_MENU_SPEED)
			{
				pThis->m_MenuLeftChangeCount = 0;
				CScene__DoSoundEffect(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &pThis->m_Camera.m_vPos, 0);
				return TRUE;
			}
			else
				return FALSE;
		}
	}
}

