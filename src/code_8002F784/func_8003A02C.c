#include "common_local_source_4272.h"

#line 316 "reference.c"
void func_8003A02C(CCamera *pThis)
{
	pThis->m_Mode = CAMERA_INTRO_IGGY_MODE ;
	pThis->m_CinemaMode = TRUE ;
	pThis->m_LetterBoxScale = 0 ;

	// Close up start position
	pThis->m_View.m_vEye.x = 0*SCALING_FACTOR ;
	pThis->m_View.m_vEye.y = 10*SCALING_FACTOR ;
	pThis->m_View.m_vEye.z = -5*SCALING_FACTOR ;
	
	pThis->m_View.m_vFocus.x = 0*SCALING_FACTOR ;
	pThis->m_View.m_vFocus.y = 10*SCALING_FACTOR ;
	pThis->m_View.m_vFocus.z = 0*SCALING_FACTOR ;
}
