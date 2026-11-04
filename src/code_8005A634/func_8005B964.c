#include "decompdecomp_sync_7f98dfb3dbb5efd520c2.h"
#line 1 "func.c"
#line 5625 "reference.c"
CVector3 func_8005B964(CTMove *pThis, CEngineApp *pApp, CTControl *pCTControl, CVector3 vDesiredPos, CCollisionInfo2 *pCollInfo, BOOL Underwater)
{
	CGameObjectInstance	*pIns;
	CVector3					vForward,
								vRotatedForward,
								vSideStepR,
								vRotatedSideStepR,
								vUp,
								vVelocity,
								vStartPos;

	CQuatern					qRotateDirection;
	CMtxF						mfRot;
	float						resf,
								resb,
								resl,
								resr,
								resu,
								resbf,
								velocity,
								dm,
								grd,
								Ang,
								sinSideY,
								cosSideY;
	BOOL						moveSound = FALSE,
								shallow;

	// get instance pointer to turok
	pIns = CEngineApp__GetPlayer(pApp);
	if (pIns == NULL) return vDesiredPos;

	// player in shallow water ?
	shallow = func_800028C4(pApp);

	// get direction to travel when swimming
	vUp.x = 0;
	vUp.y = 1;
	vUp.z = 0;
	vForward.x  = 0;
	vForward.y  = 0;
	vForward.z  = 1;
	vSideStepR.x = 1;
	vSideStepR.y = 0;
	vSideStepR.z = 0;

	qRotateDirection = D_8001D464(pIns);
	func_80014DC4(&qRotateDirection, mfRot);
	func_80015754(mfRot, &vForward, &vRotatedForward);
	func_80015754(mfRot, &vSideStepR, &vRotatedSideStepR);

	// calculate sin & cos for side stepping right direction
	sinSideY = sin(pIns->m_RotY - ANGLE_PI/2);
	cosSideY = cos(pIns->m_RotY - ANGLE_PI/2);

	// player swimming up ?
	velocity = 0;
	resu = 0;


	// burst forward ?
	if (		(!pThis->InAntiGrav)
			&&	(!shallow) )
	{
		if (    (pThis->BurstTimer >= TMOVE_BURST_START_TIME)
			  && (pThis->BurstTimer <= TMOVE_BURST_END_TIME)
			  && (pThis->SwimBurstToggle) )
		{
			if (Underwater)
			{
				resbf = D_80051844(pCTControl);
				if (resbf<0)
				{
					// player bursting forward
					if (pThis->BurstForwardSpeed <= TMOVE_MAX_BURSTFORWARDSPEEDUW/3)
					{
						pThis->BurstForwardSpeed = TMOVE_MAX_BURSTFORWARDSPEEDUW;
						D_8005EED0(&pIns->ah.ih, SOUND_UNDERWATER_SWIM_2, 1, 0);
					}
				}
			}
			else
			{
				resbf = D_80051844(pCTControl);
				if (resbf<0)
				{
					// player bursting forward
					if (pThis->BurstForwardSpeed <= TMOVE_MAX_BURSTFORWARDSPEEDOW/3)
					{
						pThis->BurstForwardSpeed = TMOVE_MAX_BURSTFORWARDSPEEDOW;
						D_8005EED0(&pIns->ah.ih, SOUND_WATER_SPLASH_2, 1, 0);
					}
				}
			}
		}
	}


	if (Underwater)
	{
		if (!pThis->InAntiGrav)
			func_8005CBDC(pThis, pApp);

		resu = D_80051814(pCTControl);
		if (!pThis->CannotSwimUp)
		{
			if (resu < 0)
			{
				// digital up
				dm = TMOVE_MAX_UPSWIMSPEED - pThis->MoveUpSpeed;
				dm = dm / TMOVE_SWIM_SMOOTH;
				pThis->MoveUpSpeed += dm;
				velocity = pThis->MoveUpSpeed*D_800B6B00;
				pThis->CannotJumpFromSurface = TRUE;
			}
		}
		else if (resu==0)
		{
			// allow swimming upwards
			pThis->CannotSwimUp = FALSE;
		}

		// reduce move speed to zero if player has stopped swimming
		if (resu==0)
		{
			// not moving
			dm = 0 - pThis->MoveUpSpeed;
			dm = dm / (TMOVE_SWIM_STOP_SMOOTH*3);
			pThis->MoveUpSpeed += dm;
			velocity = pThis->MoveUpSpeed*D_800B6B00;
		}

		// move player up
		if (velocity!=0)
		{
			D_80013C2C(&vVelocity, &vUp, velocity);
			func_800144FC(&vDesiredPos, &vDesiredPos, &vVelocity);
		}
	}

	// if in shallow water do normal walking & running but with water sounds
	if (shallow)
	{
		vStartPos = vDesiredPos;
		vDesiredPos = func_80056050(pThis, pApp, pCTControl, vDesiredPos);
		vDesiredPos = D_800568A8(pThis, pApp, pCTControl, vDesiredPos);

		// did player move ?
		if (		(vDesiredPos.x != vStartPos.x)
				||	(vDesiredPos.y != vStartPos.y)
				||	(vDesiredPos.z != vStartPos.z) )
		{
			pThis->WaterSfxTimer += D_800B6B00*(1.0/FRAME_FPS);

			if (pThis->WaterSfxTimer > pThis->WaterSfxTimerMax)
			{
				pThis->WaterSfxTimer = 0;
				D_8005EED0(&pIns->ah.ih, SOUND_WATER_SPLASH_3, 1, 0);
				pThis->WaterSfxTimerMax = 0.4 + (((float)RANDOM(10))/10.0);
			}
		}

		pThis->BurstForwardSpeed = 0.0;
		pThis->ActualBurstForwardSpeed = 0.0;
		func_8005B044(pThis, pCTControl);
		update_player_head_bob(pThis);
		return vDesiredPos;
	}
	else
	{
		resf = D_80051754(pCTControl);

		// update burst speed - only if forward control is held in
		if (resf == 0)
		{
			// trying to move forwards slowly
			pThis->BurstTimer = 0.0;
		}
		else
		{
			// trying to move forwards quickly
			pThis->BurstTimer += D_800B6B00*(1.0/FRAME_FPS);
		}

		dm = (0-pThis->BurstForwardSpeed)/20;
		pThis->BurstForwardSpeed += dm * D_800B6B00 * 2;

		dm = (pThis->BurstForwardSpeed - pThis->ActualBurstForwardSpeed) / 3;
		pThis->ActualBurstForwardSpeed += dm * D_800B6B00 * 2;
	}


	// *** player swimming forwards ?
	velocity = 0;
	if (resf < 0)
	{
		// digital forward
		dm = TMOVE_MAX_SWIMSPEED - pThis->MoveSpeed;
		dm = dm / TMOVE_SWIM_SMOOTH;
		pThis->MoveSpeed += dm;
		velocity = pThis->MoveSpeed*D_800B6B00;
	}
	else if (resf > 0)
	{
		// analogue forward
		velocity = resf*pThis->MoveSpeed*D_800B6B00;
	}

	// *** player swimming backwards ?
	resb = D_80051784(pCTControl);
	if (resb < 0)
	{
		// digital backward
		dm = -TMOVE_MAX_BACKSWIMSPEED - pThis->MoveSpeed;
		dm = dm / TMOVE_SWIM_SMOOTH;
		pThis->MoveSpeed += dm;
		velocity = pThis->MoveSpeed*D_800B6B00;
	}
	else if (resb > 0)
	{
		// analogue backward
		velocity = resb*pThis->MoveSpeed*D_800B6B00;
	}

	// reduce move speed to zero if player has stopped swimming
	if (resb == 0 && resf == 0)
	{
		// not moving
		dm = 0 - pThis->MoveSpeed;
		dm = dm / (TMOVE_SWIM_STOP_SMOOTH*5);
		pThis->MoveSpeed += dm;
		velocity = pThis->MoveSpeed*D_800B6B00;
	}
	else
	{
		moveSound = TRUE;
	}

	// add in swim burst forward speed
	velocity += pThis->ActualBurstForwardSpeed*D_800B6B00;

	// move player forwards
	if (velocity!=0)
	{
		D_80013C2C(&vVelocity, &vRotatedForward, velocity);
		func_800144FC(&vDesiredPos, &vDesiredPos, &vVelocity);
	}


	// *** player swimming right ?
	velocity = 0;
	resr = D_800517E4(pCTControl);
	if (resr < 0)
	{
		// digital sidestep right
		dm = TMOVE_MAX_SIDESTEPSWIMSPEED - pThis->SideStepSpeed;
		dm = dm / TMOVE_SWIM_SMOOTH;
		pThis->SideStepSpeed += dm;
		velocity = pThis->SideStepSpeed*D_800B6B00;
	}
	else if (resr > 0)
	{
		// analogue side step right
		velocity = resr*pThis->SideStepSpeed*D_800B6B00;
	}


	// *** player swimming left ?
	resl = D_800517B4(pCTControl);
	if (resl < 0)
	{
		// digital sidestep left
		dm = -TMOVE_MAX_SIDESTEPSWIMSPEED - pThis->SideStepSpeed;
		dm = dm / TMOVE_SWIM_SMOOTH;
		pThis->SideStepSpeed += dm;
		velocity = pThis->SideStepSpeed*D_800B6B00;
	}
	else if (resl > 0)
	{
		// analogue side step left
		velocity = resl*pThis->SideStepSpeed*D_800B6B00;
	}

	// reduce side step speed to zero if player has stopped swimming
	if (resl == 0 && resr == 0)
	{
		// not moving
		dm = 0 - pThis->SideStepSpeed;
		dm = dm / (TMOVE_SWIM_STOP_SMOOTH*5);
		pThis->SideStepSpeed += dm;
		velocity = pThis->SideStepSpeed*D_800B6B00;
	}
	else
	{
		moveSound = TRUE;
	}


	// *** which way should player move ?
	if (velocity!=0)
	{
		// move player right
		vDesiredPos.x += velocity*sinSideY;
		vDesiredPos.z += velocity*cosSideY;
	}


	// play movement sound in water
	if (moveSound && !pThis->InAntiGrav)
	{
		if (Underwater)
		{
			pThis->WaterSfxTimer += D_800B6B00*(1.0/FRAME_FPS);
			if (pThis->WaterSfxTimer > 2.5)
			{
				pThis->WaterSfxTimer -= 2.5;
				D_8005EED0(&pIns->ah.ih, SOUND_UNDERWATER_SWIM_1, 1, 0);
			}
		}
		else
		{
			pThis->WaterSfxTimer += D_800B6B00*(1.0/FRAME_FPS);
			if (pThis->WaterSfxTimer > pThis->WaterSfxTimerMax)
			{
				pThis->WaterSfxTimer = 0;
				D_8005EED0(&pIns->ah.ih, SOUND_WATER_SPLASH_3, 1, 0);
				pThis->WaterSfxTimerMax = 0.4 + (((float)RANDOM(10))/10.0);
			}
		}
	}



	// *** adjust gravity underwater based on players speed
	if (pThis->MoveSpeed     <  0.5 &&
		 pThis->MoveSpeed     > -0.5 &&
		 pThis->SideStepSpeed <  0.5 &&
		 pThis->SideStepSpeed > -0.5 &&
		 pThis->MoveUpSpeed   <  0.5 &&
		 pThis->MoveUpSpeed   > -0.5    )
	{
		// no movement
		if (pCollInfo && Underwater)
		{
			dm = (GRAVITY_WATER_ACCELERATION - pCollInfo->GravityAcceleration) / 6;
			pCollInfo->GravityAcceleration += dm;
		}
	}
	else
	{
		// player is moving - underwater ?
		if (Underwater)
		{
			dm = (0 - pIns->ah.m_vVelocity.y) / 8;
			pIns->ah.m_vVelocity.y += dm;
			if (pCollInfo)
			{
				dm = (0 - pCollInfo->GravityAcceleration) / 8;
				pCollInfo->GravityAcceleration += dm;
			}
		}

		if (!Underwater)
		{
			func_8005CD90(pThis, pApp);
		}
	}

	if (!pThis->InAntiGrav)
	{
		if (Underwater)
		{
			// do underwater idle camera motion
			pThis->Time1 += (D_800B6B00/8);
			if (pThis->Time1>=ANGLE_PI*2)
				pThis->Time1 -= ANGLE_PI*2;

			pThis->Time2 += (D_800B6B00/5);
			if (pThis->Time2>=ANGLE_PI*2)
				pThis->Time2 -= ANGLE_PI*2;

			Ang = D_8009E630(pThis->Time2+ANGLE_PI)/500;
			pThis->HeadXRot += Ang;

			Ang = D_8009E630(pThis->Time2)/500;
			pThis->RotZPlayer += Ang;

			Ang = D_8009E630(pThis->Time1)/500;
			pThis->HeadYRot += Ang;
		}
		else
		{
			// do water surface idle camera motion
			pThis->Time1 += (D_800B6B00/6);
			if (pThis->Time1>=ANGLE_PI*2)
				pThis->Time1 -= ANGLE_PI*2;

			pThis->Time2 += (D_800B6B00/4);
			if (pThis->Time2>=ANGLE_PI*2)
				pThis->Time2 -= ANGLE_PI*2;

			Ang = D_8009E630(pThis->Time2+ANGLE_PI)/400;
			pThis->HeadXRot += Ang;

			Ang = D_8009E630(pThis->Time2)/400;
			pThis->RotZPlayer += Ang;

			Ang = D_8009E630(pThis->Time1)/400;
			pThis->HeadYRot += Ang;
		}
	}

	// as player approaches the ground the player's descent will slow down
	if (Underwater)
	{
		grd = max(2, ((pIns->ah.ih.m_vPos.y - func_80002614(pApp)) / 8) );
		dm = (0 - pIns->ah.m_vVelocity.y) / grd;
		pIns->ah.m_vVelocity.y += dm;
		if (pCollInfo)
		{
			dm = (0 - pCollInfo->GravityAcceleration) / grd;
			pCollInfo->GravityAcceleration += dm;
		}
	}

	// do side step z rotation for water
	if (Underwater)
	{
		dm = (pThis->SideStepSpeed * ANGLE_DTOR(-0.2) - pThis->HeadZRot) / 5;
		pThis->HeadZRot += dm;
	}
	else
	{
		dm = (pThis->SideStepSpeed * ANGLE_DTOR(-0.2) - pThis->HeadZRot) / 5;
		pThis->HeadZRot += dm;
	}

	return vDesiredPos;
}

