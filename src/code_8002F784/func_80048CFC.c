#include "common_local_source_4522.h"

#line 1917 "reference.c"
BOOL func_80048CFC(CGameObjectInstance *pThis, CTRex *pTRex)
{
	CGameObjectInstance *pTurok ;
	FLOAT						AngleDiff ;
	INT32						Index ;

	// Hit by an explosion?
	if ((!(pTRex->m_Boss.m_ModeFlags & (BF_INVINCIBLE | BF_ENTER_MODE | BF_EXPLODE_MODE))) &&
		 (AI_GetDyn(pThis)->m_dwStatusFlags & AI_EV_EXPLOSION))
	{
		// Clear explosion flag
		AI_GetDyn(pThis)->m_dwStatusFlags &= ~AI_EV_EXPLOSION ;


#if DEBUG_TREX
		rmonPrintf("\r\n...EXPLOSION HIT!!...\r\n") ;
#endif

		// Been hit enough?
		if (++pTRex->m_ExplosionHits >= pTRex->m_pStageInfo->HitsBeforeExplode)
		{
			pTRex->m_ExplosionHits = 0 ;

			// Decide what to do
			switch(pTRex->m_Boss.m_Mode)
			{
				case TREX_CAVE_NOSE_HIT_MODE:
				case TREX_DEATH_MODE:
					return FALSE ;

				case TREX_CAVE_STOOP_MODE:
				case TREX_CAVE_LOOK_MODE:
				case TREX_CAVE_BITE_MODE:
					// Force anim to restart if same mode
					pTRex->m_Boss.m_OldMode = -1 ;
					TRex_SetupMode((CGameObjectInstance *)pThis, TREX_CAVE_NOSE_HIT_MODE) ;
					return TRUE ;

				default:
					// Force anim to restart if same mode
					pTRex->m_Boss.m_OldMode = -1 ;

					pTurok = CEngineApp__GetPlayer(GetApp());
					AngleDiff = (pTurok->m_RotY -  pThis->m_RotY - ANGLE_DTOR(45)) / ANGLE_DTOR(90) ;
					Index = (INT32)AngleDiff ;

					TRex_SetupMode((CGameObjectInstance *)pThis, TRexExplodeModes[Index & 3]) ;
					return TRUE ;
			}
		}
	}

	return FALSE ;
}
