#include "common_local_source_3715.h"

#line 1 "reference.c"
void func_80006D14(CEngineApp *pThis)
{
	if (pThis->m_FadeStatus == FADE_NULL)
	{
		pThis->m_MapMode = FALSE ;
		pThis->m_bPause = TRUE;
		func_80084BB0(&pThis->m_Pause);
	}
}
