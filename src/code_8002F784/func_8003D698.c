#include "common_local_source_4318.h"

#line 1629 "reference.c"
void func_8003D698(CTimerFx *pThis)
{
	CVector3		vPos ;
	int			i = 3 ;
	CCamera		*pCamera = &GetApp()->m_Camera ;
	CGameObjectInstance *pTurok = CEngineApp__GetPlayer(GetApp()) ;

	// Turok valid?
	if (!pTurok)
		return ;

	// Start a bunch of explosions
	while(i--)
	{
		// Setup a random direction ray
		vPos.x = RandomRangeFLOAT(-200*SCALING_FACTOR, 130*SCALING_FACTOR) ;
		vPos.z = RandomRangeFLOAT(-115*SCALING_FACTOR, 130*SCALING_FACTOR) ;

		if (vPos.x > 0)
			vPos.y = (130*SCALING_FACTOR) - vPos.x ;
		else
			vPos.y = RandomRangeFLOAT(0, 30*SCALING_FACTOR) ;

		// Start explosion
		func_8005F840(&pTurok->ah.ih, PARTICLE_TYPE_GENERIC235, vPos) ;
	}

	// Start tremor going
	pCamera->m_vTremor.x = RandomRangeFLOAT(ANGLE_DTOR(-0.5), ANGLE_DTOR(0.5)) ;
	pCamera->m_vTremor.y = RandomRangeFLOAT(0*SCALING_FACTOR, 0.25*SCALING_FACTOR) ;
	pCamera->m_vTremor.z = RandomRangeFLOAT(ANGLE_DTOR(-0.5), ANGLE_DTOR(0.5)) ;


	// Play explosion sound
	if ((game_frame_number & 7) == 0)
	{
		if (RANDOM(2))
			func_80063AE8(&pTurok->ah.ih, vPos, SOUND_GENERIC_218) ;
		else
			func_80063AE8(&pTurok->ah.ih, vPos, SOUND_EXPLOSION_2) ;
	}
}
