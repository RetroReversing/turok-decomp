#include "common_local_source_5405.h"

#line 1787 "reference.c"
void func_8007F5EC(COverlay *pThis)
{
	BOOL	DoNextCommand ;
	FLOAT	XVel, YVel ;

	// Update movement
	do
	{
		DoNextCommand = FALSE ;
		switch(pThis->m_Mode)
		{
			case OVERLAY_INACTIVE_MODE:
				break ;

			case OVERLAY_READ_SCRIPT_MODE:

				// Script active?
				if (pThis->m_pScript)
				{
					// Process new script command
					switch(*pThis->m_pScript++)
					{
						case OVERLAY_SCRIPT_SET_POS:
							pThis->m_X = (FLOAT)*pThis->m_pScript++ ;
							pThis->m_Y = (FLOAT)*pThis->m_pScript++ ;
							DoNextCommand = TRUE ;
							break ;

						case OVERLAY_SCRIPT_WAIT:
							pThis->m_Mode = OVERLAY_WAIT_MODE ;
							pThis->m_Time = *pThis->m_pScript++ ;
							break ;

						case OVERLAY_SCRIPT_ZOOM:
							pThis->m_OnScreen = TRUE ;
							pThis->m_Mode = OVERLAY_ZOOM_MODE ;
							pThis->m_FinalX = (FLOAT)*pThis->m_pScript++ ;
							pThis->m_FinalY = (FLOAT)*pThis->m_pScript++ ;
							pThis->m_ZoomFactor = 1.0 / (FLOAT)*pThis->m_pScript++ ;
							break ;

						case OVERLAY_SCRIPT_DROP_OFF:
							pThis->m_OnScreen = TRUE ;
							pThis->m_Mode = OVERLAY_DROP_OFF_MODE ;
							pThis->m_YVel = 0.0 ;
							pThis->m_YAccel = ((FLOAT)*pThis->m_pScript++) / 65536.0 ;
							break ;

						case OVERLAY_SCRIPT_HORZDROP_OFF:
							pThis->m_OnScreen = TRUE ;
							pThis->m_Mode = OVERLAY_HORZDROP_OFF_MODE ;
							pThis->m_XVel = 0.0 ;
							pThis->m_XAccel = ((FLOAT)*pThis->m_pScript++) / 65536.0 ;
							break ;

						default:
							pThis->m_Mode = OVERLAY_INACTIVE_MODE ;
							pThis->m_pScript = NULL ;
							break ;
					}
				}
				else
					pThis->m_Mode = OVERLAY_INACTIVE_MODE ;

				break ;

			case OVERLAY_WAIT_MODE:

				// Timer ran out?
				if (pThis->m_Time-- <= 0)
					DoNextCommand = TRUE ;

				break ;

			case OVERLAY_ZOOM_MODE:

				// Calculate zoom vels
				XVel = (pThis->m_FinalX - pThis->m_X) * pThis->m_ZoomFactor ;
				YVel = (pThis->m_FinalY - pThis->m_Y) * pThis->m_ZoomFactor ;

				// Move overlay
				pThis->m_X += XVel ;
				pThis->m_Y += YVel ;

				// Snap to final target
				if ((abs(XVel) < 0.25) && (abs(YVel) < 0.25))
				{
					pThis->m_X = pThis->m_FinalX ;
					pThis->m_Y = pThis->m_FinalY ;
					DoNextCommand = TRUE ;
				}
			  	break ;

			case OVERLAY_DROP_OFF_MODE:

				// Move
				pThis->m_Y += pThis->m_YVel ;
				pThis->m_YVel += pThis->m_YAccel ;

				// Off bottom of screen?
				if ((pThis->m_Y > (240+96)) || (pThis->m_Y<-90))
				{
					pThis->m_OnScreen = FALSE ;
					DoNextCommand = TRUE ;
				}

				break ;

			case OVERLAY_HORZDROP_OFF_MODE:

				// Move
				pThis->m_X += pThis->m_XVel ;
				pThis->m_XVel += pThis->m_XAccel ;

				// Off left / right of screen?
				if ((pThis->m_X > (320+96)) || (pThis->m_X<-90))
				{
					pThis->m_OnScreen = FALSE ;
					DoNextCommand = TRUE ;
				}

				break ;
		}

		// Process next command?
		if (DoNextCommand)
			pThis->m_Mode = OVERLAY_READ_SCRIPT_MODE ;

	}
	while(DoNextCommand) ;
}
