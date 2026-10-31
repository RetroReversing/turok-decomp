#include "common_local_source_4641.h"

#line 1799 "reference.c"
void func_8004E3E0(CGameObjectInstance *pThis, CCampaigner *pCampaigner)
{
	FLOAT	DeltaAngle = pCampaigner->m_Boss.m_DeltaAngle ;
//	CGameObjectInstance *pTurok = CEngineApp__GetPlayer(GetApp());
//	osSyncPrintf("DeltaAngle:%f RDeltaAngle:%f\r\n",
//					 ANGLE_RTOD(DeltaAngle),
//					 ANGLE_RTOD(AI_GetAvoidanceAngle(pThis, TUROK_GetPos(pTurok), pTurok, AVOIDANCE_RADIUS_DISTANCE_FACTOR))) ;

	// Within run distance?
	if ((pCampaigner->m_Boss.m_DistFromTarget	> CAMPAIGNER_RUN_DIST) ||
		 (pCampaigner->m_Boss.m_ModeFlags & BF_RUNNING_MODE))
	{
		// Perform attack?
		if (!Campaigner_CheckForRunAttack(pThis, pCampaigner))
		{
			// Turn?
			if (pCampaigner->m_Boss.m_Mode != CAMPAIGNER_RUN_TURN180_MODE)
			{
				// Perform gradual turn
				func_8004016C(pThis, (CBoss *)pCampaigner, CAMPAIGNER_RUN_TURN_SPEED, DeltaAngle) ;

				// Turn 180?
				if (DeltaAngle < -CAMPAIGNER_RUN_TURN180_ANGLE)
					pCampaigner->m_Boss.m_Mode = CAMPAIGNER_RUN_TURN180_MODE  ;
				else
				// Turn left?
				if (DeltaAngle < -CAMPAIGNER_RUN_TURN90_ANGLE)
					pCampaigner->m_Boss.m_Mode = CAMPAIGNER_RUN_TURN_LEFT90_MODE  ;
				else
				// Turn Right?
				if (DeltaAngle > CAMPAIGNER_RUN_TURN90_ANGLE)
					pCampaigner->m_Boss.m_Mode = CAMPAIGNER_RUN_TURN_RIGHT90_MODE  ;
			}
			// Perform running weapon attack?
			if ((pCampaigner->m_Boss.m_ModeFlags & BF_RUNNING_MODE) &&
			    (pCampaigner->m_Boss.m_DistFromTarget	< CAMPAIGNER_RUN_MAX_WEAPON_DIST) &&
			    (pCampaigner->m_Boss.m_DistFromTarget	> CAMPAIGNER_RUN_MIN_WEAPON_DIST) &&
				 (abs(pCampaigner->m_Boss.m_DeltaAngle) < ANGLE_DTOR(5)) &&
				 (GetApp()->m_BossVars.m_TurokSpeed < (SCALING_FACTOR*0.5)))
				func_8004DACC(pThis, CAMPAIGNER_RUN_WEAPON_OVERHEAD_SMASH_MODE) ;
			else
			if (abs(DeltaAngle) <= CAMPAIGNER_RUN_FACING_ANGLE)
			{
				// Put into run mode
				pCampaigner->m_Boss.m_Mode = CAMPAIGNER_RUN_MODE ;
			}
		}
	}
	else
	// Within walk distance?
	if (pCampaigner->m_Boss.m_DistFromTarget	> CAMPAIGNER_WALK_DIST)
	{
		// Perform attack?
		if (!Campaigner_CheckForRunAttack(pThis, pCampaigner))
		{
			// Turn?
			if (pCampaigner->m_Boss.m_Mode != CAMPAIGNER_WALK_TURN180_ANGLE)
			{
				// Perform gradual turn
				func_8004016C(pThis, (CBoss *)pCampaigner, CAMPAIGNER_WALK_TURN_SPEED, DeltaAngle) ;

				// Turn 180?
				if (DeltaAngle < -CAMPAIGNER_WALK_TURN180_ANGLE)
					pCampaigner->m_Boss.m_Mode = CAMPAIGNER_WALK_TURN180_MODE  ;
				else
				// Turn left?
				if (DeltaAngle < -CAMPAIGNER_WALK_TURN90_ANGLE)
					pCampaigner->m_Boss.m_Mode = CAMPAIGNER_WALK_TURN_LEFT90_MODE  ;
				else
				// Turn Right?
				if (DeltaAngle > CAMPAIGNER_WALK_TURN90_ANGLE)
					pCampaigner->m_Boss.m_Mode = CAMPAIGNER_WALK_TURN_RIGHT90_MODE  ;
			}

			// Walk straight
			if (abs(DeltaAngle) <= CAMPAIGNER_WALK_FACING_ANGLE)
			{
				// Put into run mode
				pCampaigner->m_Boss.m_Mode = CAMPAIGNER_WALK_MODE ;
			}
		}
	}

	// Attack?
	if (pCampaigner->m_Boss.m_DistFromTarget <= CAMPAIGNER_WALK_DIST)
	{
		// Turn 180?
		if (pCampaigner->m_Boss.m_Mode != CAMPAIGNER_TURN180_MODE)
		{
			if (DeltaAngle < -CAMPAIGNER_TURN180_ANGLE)
				pCampaigner->m_Boss.m_Mode = CAMPAIGNER_TURN180_MODE ;
			else
			// Turn left, right or walk?
			if (DeltaAngle < -CAMPAIGNER_TURN90_ANGLE)
				pCampaigner->m_Boss.m_Mode = CAMPAIGNER_TURN_LEFT90_MODE ;
			else
			if (DeltaAngle > CAMPAIGNER_TURN90_ANGLE)
				pCampaigner->m_Boss.m_Mode = CAMPAIGNER_TURN_RIGHT90_MODE ;
		}

		// Do attack
		if (abs(DeltaAngle) <= CAMPAIGNER_FACING_ANGLE)
		{
			pCampaigner->m_Boss.m_Mode = CAMPAIGNER_IDLE_MODE ;
			Campaigner_PerformCloseAttack(pThis, pCampaigner) ;
		}
	}
}
