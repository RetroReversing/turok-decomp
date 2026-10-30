#include "common_local_source_4605.h"

#line 1326 "reference.c"
void func_8004CD6C(CGameObjectInstance *pThis, CHumvee *pHumvee)
{
	FLOAT	DeltaAngle = pHumvee->m_Boss.m_DeltaAngle ;
//	FLOAT	Assist = HUMVEE_TURN_SPEED * pHumvee->m_Boss.m_PlaybackAnimSpeed ;

	FLOAT	Speed, Assist ;
	
	// Calc assist
	Speed = pHumvee->m_Boss.m_Speed / 14 ;
	if (Speed > 1.0)
		Speed = 1.0 ;
	Assist = HUMVEE_TURN_SPEED * Speed ;

	// Go straight?
//	if (abs(DeltaAngle) <= HUMVEE_FACING_ANGLE)
		pHumvee->m_Boss.m_Mode = HUMVEE_RUN_MODE ;

	// Turok dead?
	if (!CTurokMovement.Active)
		Humvee_SetupMode(pThis, HUMVEE_IDLE_MODE) ;
	else
	// Turning?
	if (pHumvee->m_Boss.m_Mode != HUMVEE_TURN180_MODE)
	{
		// Turn 180?
		if (DeltaAngle < -HUMVEE_TURN180_ANGLE)
		{
			if (RANDOM(2))
				pHumvee->m_Boss.m_Mode = HUMVEE_TURN180_MODE ;
			else
				pHumvee->m_Boss.m_Mode = HUMVEE_STOP_MODE ;
		}
		else
		{
			// Turn left?
			if (DeltaAngle < -HUMVEE_TURN90_ANGLE)
			{
//				if (pHumvee->m_Boss.m_Mode != HUMVEE_TURN_LEFT90_MODE)
				{
					Assist *= 2 ;
					pThis->ah.m_vVelocity.x = pHumvee->m_Boss.m_LastVel.x * 2 ;
					pThis->ah.m_vVelocity.z = pHumvee->m_Boss.m_LastVel.z * 2 ;

					func_8004D0BC(&pThis->ah.ih, pThis->ah.ih.m_vPos, SOUND_GENERIC_85) ;
//					pHumvee->m_Boss.m_Mode = HUMVEE_TURN_LEFT90_MODE ;
				}
			}
			else
			// Turn Right?
			if (DeltaAngle > HUMVEE_TURN90_ANGLE)
			{
//				if (pHumvee->m_Boss.m_Mode != HUMVEE_TURN_RIGHT90_MODE)
				{
					Assist *= 2 ;
					pThis->ah.m_vVelocity.x = pHumvee->m_Boss.m_LastVel.x * 2 ;
					pThis->ah.m_vVelocity.z = pHumvee->m_Boss.m_LastVel.z * 2 ;


					func_8004D0BC(&pThis->ah.ih, pThis->ah.ih.m_vPos, SOUND_GENERIC_85) ;
//					pHumvee->m_Boss.m_Mode = HUMVEE_TURN_RIGHT90_MODE ;
				}
			}
		}
	}

	// Assist with the turn
	func_8004016C(pThis, (CBoss *)pHumvee, Assist, DeltaAngle) ;
}
