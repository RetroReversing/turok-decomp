#include "common_local_source_4849.h"

#line 6508 "reference.c"
CVector3 func_8005D738(CTMove *pThis, CEngineApp *pApp, CTControl *pCTControl, CVector3 vDesiredPos)
{
	// declare variables
	float						resf, resb, dm,
								sinRotY,  cosRotY,
								resj;
	CGameObjectInstance *pIns;


#define	TMOVE_MAX_CLIMB_SPEED				(1.4*SCALING_FACTOR)
#define	TMOVE_CLIMB_SPEED_SMOOTH			4
#define	TMOVE_JUMPOFF_SPEED					(2.3*15.0*SCALING_FACTOR)
#define	TMOVE_CLIMB_SPEED_STOP_SMOOTH		2

#define	TMOVE_MAX_LADDER_SPEED				(0.8*SCALING_FACTOR)//(0.55*SCALING_FACTOR)
#define	TMOVE_LADDER_SPEED_SMOOTH			6
#define	TMOVE_LADDER_SPEED_STOP_SMOOTH	4


	// get instance pointer to turok
	pIns = CEngineApp__GetPlayer(pApp);
	if (pIns == NULL) return vDesiredPos;

	// calculate sin & cos for straight ahead direction
	sinRotY = sin(pIns->m_RotY + ANGLE_PI);
	cosRotY = cos(pIns->m_RotY + ANGLE_PI);

	// jumping ?
	resj = CTControl__IsJump(pCTControl);
	if (		(resj < 0)
			&&	(!pThis->CannotJumpFromCliffFace) )
	{
		// initialize - digital jump
		pThis->Mode		         = TMMODE_GRDJUMP;
		pThis->JumpUpForce		= 0;
		pThis->Jumped				= FALSE;
		pThis->DoubleJump			= FALSE;
		AI_DoSound(&pIns->ah.ih, SOUND_GENERIC_21, 1, 0);
		func_800573F0(pThis);
		func_8005AE80(pThis);
		func_80057134(pThis, pApp, pCTControl);

		// make turok jump from cliff away from cliff
		sinRotY = sin(pIns->m_RotY + ANGLE_PI*2);
		cosRotY = cos(pIns->m_RotY + ANGLE_PI*2);
		pIns->ah.m_vVelocity.x += TMOVE_JUMPOFF_SPEED*frame_increment*sinRotY;
		pIns->ah.m_vVelocity.z += TMOVE_JUMPOFF_SPEED*frame_increment*cosRotY;
		pIns->ah.m_vVelocity.y	= 0;

		// put weapon back to what it was prior to climbing
		if (!func_80058D60(pThis, pThis->WeaponAtStartOfClimb, FALSE))
			func_80058D60(pThis, AI_OBJECT_WEAPON_KNIFE, FALSE);

		pThis->WeaponAtStartOfClimb		= -1;

		pThis->CannotJumpFromCliffFace = TRUE;
		return vDesiredPos;
	}
	else if (resj == 0)
	{
		pThis->CannotJumpFromCliffFace = FALSE;
	}

	// do counter
	if (pThis->ClimbOneHand)
	{
		pThis->Time1 += frame_increment;
		if (pThis->Time1 >= 11)
		{
			// camera should swing
			pThis->Time1 -= 11;
			pThis->ClimbOneHand = FALSE;
		}
	}

	// turok moving up
	resf = CTControl__IsClimbUp(pCTControl);
	if (    (resf < 0)
		  && (!pThis->ClimbOneHand)
		  && (!CTControl__IsClimbLeft(pCTControl))
		  && (!CTControl__IsClimbRight(pCTControl)) )
	{
		pThis->ClimbOneHand = TRUE;
		pThis->Time1 = 0;
		pThis->ClimbCameraWobble = TRUE;

		if (pThis->ClimbHand)
			AI_DoSound(&pIns->ah.ih, SOUND_GENERIC_23,  1, 0);
		else
			AI_DoSound(&pIns->ah.ih, SOUND_GENERIC_24,  1, 0);

		if (pThis->ClimbWeaponRemove)
		{
			func_80058E84(pThis, pApp);
			pThis->ClimbWeaponRemove = FALSE;
		}
	}

	// turok moving down
/*	if (resf==0 && pThis->OnLadder)
	{
		resb = CTControl__IsClimbDown(pCTControl);
		if (    (resb < 0)
			  && (!pThis->ClimbOneHand)
			  && (!CTControl__IsClimbLeft(pCTControl))
			  && (!CTControl__IsClimbRight(pCTControl)) )
		{
			pThis->ClimbOneHand = TRUE;
			pThis->Time1 = 0;
			pThis->ClimbCameraWobble = TRUE;

			if (pThis->ClimbHand)
				AI_DoSound(&pIns->ah.ih, SOUND_GENERIC_23,  1, 0);
			else
				AI_DoSound(&pIns->ah.ih, SOUND_GENERIC_24,  1, 0);

			if (pThis->ClimbWeaponRemove)
			{
				CTMove__RemoveWeaponFromScreen(pThis, pApp);
				pThis->ClimbWeaponRemove = FALSE;
			}
		}
		else
			resb = 0;
	}
	else*/
		resb = 0;

#ifdef TMOVE_ALLOW_WEAPON_WHILE_CLIMBING
	if (!pThis->ClimbOneHand)
	{
		if (!pThis->ClimbWeaponRemove)
		{
			if ( (!func_8005843C(pThis, AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL, 1)) &&
				    func_80058708(pThis, AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL)			)
			{
				func_80058D60(pThis, AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL, TRUE);
			}
			else
			{
				func_80058D60(pThis, AI_OBJECT_WEAPON_KNIFE, TRUE);
			}
			pThis->ClimbWeaponRemove = TRUE;
		}
	}
#endif

	// do climbing
	if (pThis->ClimbOneHand)
	{
		// climbing up
		if (resf)
		{
			if (pThis->OnLadder)
			{
				dm = TMOVE_MAX_LADDER_SPEED - pThis->MoveSpeed;
				dm = dm / TMOVE_LADDER_SPEED_SMOOTH;
			}
			else
			{
				dm = TMOVE_MAX_CLIMB_SPEED - pThis->MoveSpeed;
				dm = dm / TMOVE_CLIMB_SPEED_SMOOTH;
			}

			pThis->MoveSpeed += dm;
		}

		// allow climbing down on ladders
		if (resb)
		{
			if (pThis->OnLadder)
			{
				dm = (-TMOVE_MAX_LADDER_SPEED/2) - pThis->MoveSpeed;
				dm = dm / TMOVE_LADDER_SPEED_SMOOTH;
			}

			pThis->MoveSpeed += dm;
		}

	}

	// reduce movement speed if we are not climbing
	if (!pThis->ClimbOneHand || pThis->Time1 >= 8)
	{
		if (pThis->OnLadder)
		{
			dm = 0 - pThis->MoveSpeed;
			dm = dm / TMOVE_LADDER_SPEED_STOP_SMOOTH;
		}
		else
		{
			dm = 0 - pThis->MoveSpeed;
			dm = dm / TMOVE_CLIMB_SPEED_STOP_SMOOTH;
		}
		pThis->MoveSpeed += dm;

		if (pThis->ClimbCameraWobble)
		{
			if (pThis->ClimbHand)
			{
				// right hand - camera swings to left
				pThis->ActualClimbSwingRotX = ANGLE_DTOR(-13);
				pThis->ActualClimbSwingRotZ = ANGLE_DTOR(-13);
			}
			else
			{
				// left hand - camera swings to right
				pThis->ActualClimbSwingRotX = ANGLE_DTOR(-13);
				pThis->ActualClimbSwingRotZ = ANGLE_DTOR(13);
			}
			pThis->ClimbHand = !pThis->ClimbHand;
			pThis->ClimbCameraWobble = FALSE;
		}
	}
	else
	{
		player_is_moving = TRUE;
	}

	// move player
	vDesiredPos.x += pThis->MoveSpeed*frame_increment*sinRotY;
	vDesiredPos.z += pThis->MoveSpeed*frame_increment*cosRotY;
	func_8005AEDC(pThis);


	// return desired position
	return vDesiredPos;
}
