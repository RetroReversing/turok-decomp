#include "decompdecomp_sync_9debb67812ba35766dbb.h"
#line 1 "func.c"
extern const float D_800F2914,D_800F2918,D_800F2928,D_800F2938,D_800F2948;
extern const double D_800F2920,D_800F2930,D_800F2940;
#line 1098 "reference.c"
void func_80047AA0(CGameObjectInstance *pThis, CTRex *pTRex)
{
	CMtxF		mfMtx ;
	CVector3	vLaserStart, vLaserStartLocal ;
	CVector3	vLaserEnd, vLaserEndLocal ;
	CVector3	vI, vPos ;
	CLine		LaserLine, TurokLine, NormalLine ;
	CGameObjectInstance *pTurok ;
	FLOAT		t ;

	// Turn laser off?
	if ((!(pTRex->m_Boss.m_ModeFlags & BF_LASER_ON)) ||
		 (GetApp()->m_bPause) ||
         (BOSS_Health(pThis) <= 0) ||
		 (CCamera__InCinemaMode(&GetApp()->m_Camera)))
	{
		// Kill sound
		if (pTRex->m_LaserSoundHandle != -1)
		{
			killCFX(pTRex->m_LaserSoundHandle) ;
			pTRex->m_LaserSoundHandle = -1 ;
            func_8008A4DC(SOUND_TREX_SERVO_1);
		}
		return ;
	}
	else
	if (!pThis->m_ActiveSwooshes)
		CFxSystem__AddObjectSwoosh(&GetApp()->m_FxSystem, pThis, &TRexLaserSwooshInfo) ;


	// Must have a node and a matrix
	if (!pThis->pmtDrawMtxs)
		return ;

	// Setup local positions for laser start and end
	CVector3__Set(&vLaserStartLocal,	  0*SCALING_FACTOR*10, 0*SCALING_FACTOR*10, D_800F2914) ;
	CVector3__Set(&vLaserEndLocal,	  150*SCALING_FACTOR*10, 0*SCALING_FACTOR*10, D_800F2918) ;

	// Transform local positions into world positions using node matrix
	CMtxF__FromMtx(mfMtx, pThis->pmtDrawMtxs[4]) ;
	CMtxF__VectorMult(mfMtx, &vLaserStartLocal, &vLaserStart) ;
	CMtxF__VectorMult(mfMtx, &vLaserEndLocal, &vLaserEnd) ;

	// Calculate laser line
	CLine__Construct(&LaserLine, &vLaserStart, &vLaserEnd) ;

	// Calculate normal line of laser start to turok
	pTurok = CEngineApp__GetPlayer(GetApp()) ;
	CLine__Construct(&TurokLine, &vLaserStart, &pTurok->ah.ih.m_vPos) ;
	CVector3__Add(&vPos, &TurokLine.m_vNormal, &pTurok->ah.ih.m_vPos) ;
	CLine__Construct(&NormalLine, &pTurok->ah.ih.m_vPos, &vPos) ;

	// Calculate intersection pt on laser line
	if ((CLine__IntersectsLine(&NormalLine, &LaserLine, &t)) && (t >= 0))
	{
		if (t > 1)
			t = 1 ;

		vI.x = LaserLine.m_vPt[0].x + (t * LaserLine.m_vDelta.x) ;
		vI.y = LaserLine.m_vPt[0].y + (t * LaserLine.m_vDelta.y) ;
		vI.z = LaserLine.m_vPt[0].z + (t * LaserLine.m_vDelta.z) ;

		if (pTRex->m_LaserSoundHandle == -1)
			pTRex->m_vLaserLastSoundPos = vI ;

		t = (5*SCALING_FACTOR) - CVector3__Dist(&vI, &pTRex->m_vLaserLastSoundPos) ;
		if (t < 0)
			t = 0 ;
		else
		if (t > (5*SCALING_FACTOR))
			t = D_800F2928 ;

		pTRex->m_vLaserLastSoundPos = vI ;

		vI.x += (vI.x - pTurok->ah.ih.m_vPos.x) * t ;
		vI.y += (vI.y - pTurok->ah.ih.m_vPos.y) * t ;
		vI.z += (vI.z - pTurok->ah.ih.m_vPos.z) * t ;

     
                                                                   
                        
                              
                              
                                
      

		// Start laser?
		if (pTRex->m_LaserSoundHandle == -1)
		{
			vPos = pThis->ah.ih.m_vPos ;
			pThis->ah.ih.m_vPos = vI ;
			pTRex->m_LaserSoundHandle = AI_DoSound(&pThis->ah.ih, SOUND_TREX_SERVO_1, 1, 0) ;
			pThis->ah.ih.m_vPos = vPos ;

		}

		// Update laser sound position
		if (pTRex->m_LaserSoundHandle != -1)
		{
			UpdateSoundVector(pTRex->m_LaserSoundHandle, &vI) ;
			t = sqrt(AI_DistanceSquared(pTurok, vI)) ;

     
                                                               
      

			t = 1.0 - (t / (SCALING_FACTOR * 300)) ;
			t *= t*t ;
//			osSyncPrintf("t:%f\r\n", t) ;

			if (t < D_800F2930)
				t = D_800F2938 ;
			else
			if (t > D_800F2940)
				t = D_800F2948 ;

			UpdateSoundPitch(pTRex->m_LaserSoundHandle, t) ;
		}
	}
	else
	// Kill sound
	if (pTRex->m_LaserSoundHandle != -1)
	{
		killCFX(pTRex->m_LaserSoundHandle) ;
		pTRex->m_LaserSoundHandle = -1 ;
	}
}

