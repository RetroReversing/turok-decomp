#include "common_local_source_4791.h"

#line 2850 "reference.c"
void func_80057134 ( CTMove *pThis, CEngineApp *pApp, CTControl *pCTControl )
{
	// declare variables
	float						dm;
	CGameObjectInstance	*pIns;
	CVector3					vDesiredPos;
	int						waterFlag;


	// get instance pointer to turok
	pIns = CEngineApp__GetPlayer(pApp);
	if ( pIns == NULL ) return;

	// initialize current position into desired position before we change it
	vDesiredPos = pIns->ah.ih.m_vPos;

	// update turning & movement of turok
	vDesiredPos = func_800558F0 ( pThis, pApp, pCTControl, vDesiredPos );
	func_800576EC ( pThis, pApp, pCTControl );

//#define JUMP_SPECIAL		12.402036
#define JUMP_SPECIAL		14.28292

	// is jump pressed ?
	if ( CTControl__IsJump ( pCTControl ) && !pThis->Jumped )
	{
		dm = ((((float)TJUMP_UPFORCE_MAX)*JUMP_SPECIAL) - pThis->JumpUpForce) / 8;

		pThis->JumpUpForce += dm*2*frame_increment;
		pIns->ah.m_vVelocity.y = pThis->JumpUpForce;

		if ( pThis->JumpUpForce > (float)TJUMP_UPFORCE_MAX/2*JUMP_SPECIAL)
		{
			pThis->JumpUpForce  = (float)TJUMP_UPFORCE_MAX/2*JUMP_SPECIAL;
			pThis->Jumped       = TRUE;
			pIns->ah.m_vVelocity.y = pThis->JumpUpForce;
		}
	}
	else
	{
		pThis->Jumped			= TRUE;
	}


	// do collision test to see how far turok really got
	waterFlag = CEngineApp__GetPlayerWaterStatus(pApp);
	if (    (waterFlag == PLAYER_ON_WATERSURFACE)
		  || (waterFlag == PLAYER_BELOW_WATERSURFACE) )
	{
		if (waterFlag == PLAYER_ON_WATERSURFACE)
		{
			CAnimInstanceHdr__Collision3(&pIns->ah, vDesiredPos, &ci_playeronwatersurface);
			pThis->pLastCI = &ci_playeronwatersurface;
		}
		else
		{
			CAnimInstanceHdr__Collision3(&pIns->ah, vDesiredPos, &ci_playerunderwater);
			pThis->pLastCI = &ci_playerunderwater;
		}
	}
	else
	{
		CAnimInstanceHdr__Collision3(&pIns->ah, vDesiredPos, &ci_player);
		pThis->pLastCI = &ci_player;
//		{
//			// turok has collided with something
//			TRACE0("Viewer colliding with boundary during jump.\r\n");
//		}
	}


	// has turok landed on ground after jumping ?
	if (func_8001BA24(&pIns->ah.ih) && pThis->Jumped)
	{
		if (pThis->HeadYPosLand>=-0.3)
			pThis->HeadYPosLand = (ci_player.vCollisionVelocity.y/15.0) * frame_increment;

		pThis->Mode         = TMMODE_GROUND;
		pThis->JumpUpForce  = 0;
		pThis->MoveSpeed    = 0;				// slow down when landing from a jump
		CTMove__StopJumping(pThis);
	}
}
