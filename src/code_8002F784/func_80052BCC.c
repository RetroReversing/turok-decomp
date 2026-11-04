#include "decompdecomp_sync_82dae71829e9945fc7a0.h"
#line 1 "func.c"
#line 530 "reference.c"
void func_80052BCC(CTMove *pThis, CEngineApp *pApp, CTControl *pCTControl)
{
	// declare variables
	CGameObjectInstance	*pIns, *pLook;
	CCamera					*pCamera;

	float						dm,
								ang,
								topCliff,
								time,
								turnang,
								scalerv;
	BOOL						pressurePlate,
								currentOnGround,
								playsound;
	CROMRegionSet			*pRegionSet;
	int						waterFlag,
								climbFlag,
								duckFlag,
								nObjType;
	CCollisionInfo2		*pCI = NULL;
	BYTE						tint[4] = {255, 255, 255, 255};
	CVector3					vPos ;
//	static float			ycoor,
//								ycoorjump = -30000.0;
//	static char				buffer1[60],
//								buffer2[60];
//	static char				ste[80] ;

	vPos.x = D_80129520.Ears.vPos.x;
	vPos.y = D_80129520.Ears.vPos.y;
	vPos.x = D_80129520.Ears.vPos.z;

	if (pThis->InMenuTimer)
	{
		pThis->InMenuTimer -= D_800B6B00*(1.0/FRAME_FPS) ;
		if (pThis->InMenuTimer < 0.0)
			pThis->InMenuTimer = 0.0 ;
	}


	// get instance pointer to turok
	pIns = CEngineApp__GetPlayer(pApp);
	if (!pIns)
		return;

	pCamera = &pApp->m_Camera;
	if (!pCamera)
		return;

	// Update the spinning warp sound
	D_80052608(pThis) ;

	// in test fly mode ?
	if (GetApp()->m_dwCheatFlags & CHEATFLAG_FLYMODE)
	{
		D_80054AC8(pThis, pApp, pCTControl);
		return;
	}

	pRegionSet = func_8002E438(&GetApp()->m_Scene, pIns->ah.ih.m_pCurrentRegion) ;

	// Update active flag
	pThis->Active = (pIns->m_AI.m_Health > 0) && (!D_80039B98(pCamera)) ;

	// get player environment status
	waterFlag = D_800027BC(pApp);
	pThis->WaterFlag = waterFlag;
	climbFlag = func_80002950(pApp);
	duckFlag = func_80002A8C(pApp);
	pThis->OnLadder = func_8005E618(pThis);
	pThis->PrevAntiGrav = pThis->InAntiGrav;
	pThis->InAntiGrav = func_8005E594(pThis);

//	sprintf(ste, "index %d", pThis->m_WeaponSelectIndex);
//	COnScreen__AddGameTextWithId(ste, 4);

	// Update music/ambient sounds so that they work during the intro.. otherwise they erm don't.
	if (pRegionSet)
	{
		if (		(waterFlag == PLAYER_BELOW_WATERSURFACE)
				&&	(!pThis->InAntiGrav) )
		{
			pThis->MusicID = MUSIC_UNDERWATER;
		}
		else
		{
			pThis->MusicID = pRegionSet->m_MusicID ;
		}

		// don't play ambient sfx's if turok is dead
		if (pIns->m_AI.m_Health)
			pThis->AmbientSound = pRegionSet->m_AmbientSounds;
		else
			pThis->AmbientSound = REG_AMBIENTNONE;

//		sprintf(ste, "Music ID %d", pThis->MusicID) ;
//		COnScreen__AddGameTextWithId(ste,32) ;

//		ASSERT(pThis->AmbientSound == REG_AMBIENTNONE);
	}
	else
	{

//		This line was commented out on 12/15/96 By Stephen Broumley.
//		It stops the music restarting during cinemas and such. Let's hope it doesn't break anything......
//		pThis->MusicID = 255;
		pThis->AmbientSound = REG_AMBIENTNONE;
	}

	// spirit cheat mode on ?
	if (GetApp()->m_dwCheatFlags & CHEATFLAG_SPIRITMODE)
		pThis->SpiritualTime = SPIRITUAL_TIMEOUT ;

	// is all weapon cheat mode on ?
	if ((GetApp()->m_dwCheatFlags & CHEATFLAG_ALLWEAPONS) || (func_80050280()))
	{
		pThis->KnifeFlag						= TRUE;
		pThis->TekBowFlag						= TRUE;
		pThis->SemiAutomaticPistolFlag	= TRUE;
		pThis->AssaultRifleFlag				= TRUE;
		pThis->MachineGunFlag				= TRUE;
		pThis->RiotShotgunFlag				= TRUE;
		pThis->AutomaticShotgunFlag		= TRUE;
		pThis->MiniGunFlag					= TRUE;
		pThis->GrenadeLauncherFlag			= TRUE;
		pThis->TechWeapon1Flag				= TRUE;
		pThis->RocketFlag						= TRUE;
		pThis->ShockwaveFlag					= TRUE;
		pThis->TechWeapon2Flag				= TRUE;
		pThis->ChronoscepterFlag			= TRUE;

		// has player received all ammo yet ? - this can only be given once per game
		if (!pThis->AllWeaponsAmmoGiven)
		{
			pThis->TekBowAmmo						= MAX_ARROWS;
			pThis->BulletPool						= MAX_BULLETS;
			pThis->EnergyPool						= MAX_ENERGY;
			pThis->ShotgunPool					= MAX_SHOTGUN;
			pThis->MiniGunAmmo					= MAX_MINIGUN;
			pThis->GrenadeLauncherAmmo			= MAX_GRENADES;
			pThis->RocketAmmo						= MAX_ROCKETS;
			pThis->TechWeapon2Ammo				= MAX_TECH2;
			pThis->ChronoscepterAmmo			= MAX_CHRONOSCEPTER;
			pThis->AllWeaponsAmmoGiven			= TRUE;
		}
	}

	if ((GetApp()->m_dwCheatFlags & CHEATFLAG_UNLIMITEDAMMO) || (func_80050280()))
	{
		pThis->TekBowAmmo						= MAX_ARROWS;
		pThis->BulletPool						= MAX_BULLETS;
		pThis->EnergyPool						= MAX_ENERGY;
		pThis->ShotgunPool					= MAX_SHOTGUN;
		pThis->MiniGunAmmo					= MAX_MINIGUN;
		pThis->GrenadeLauncherAmmo			= MAX_GRENADES;
		pThis->RocketAmmo						= MAX_ROCKETS;
		pThis->TechWeapon2Ammo				= MAX_TECH2;
		pThis->ChronoscepterAmmo			= MAX_CHRONOSCEPTER;
	}

	// is player invincible at start of new life ?
	if (!D_80039B98(pCamera))
	{
		if (pThis->InvincibleTimer)
		{
			pThis->InvincibleTimer -= D_800B6B00*(1.0/FRAME_FPS);
			if (pThis->InvincibleTimer < 0.0)
				pThis->InvincibleTimer = 0.0;

			AI_GetDyn(pIns)->m_Invincible = TRUE;
		}
		else
		{
			AI_GetDyn(pIns)->m_Invincible = FALSE;
		}
	}

	// get current on ground status
	currentOnGround = func_8001BA24(&pIns->ah.ih);
	pThis->PrevOnGround = pThis->CurrentOnGround;
	pThis->CurrentOnGround = currentOnGround;

	// animate rotating gun barrel weapons on relevant weapons
	func_8005970C(pThis, pThis->WeaponCurrent);

	// update tremor shake screen effect
	func_8005901C(pThis);

	// update in combat timer
	D_8005AF38(pThis);

	pApp->m_YPosOffset			= TUROK_EYE_HEIGHT*SCALING_FACTOR ;
	pApp->m_RotXOffset			= 0.0;
	pApp->m_RotYOffset			= 0.0;
	pApp->m_RotZOffset			= 0.0;
	pThis->ActualSwimBankAngle = 0.0;

	D_800398FC(pCamera);

	// if player dies kill any weapon sfx's
	if (		(pIns->m_AI.m_Health == 0)
			||	(D_80039B98(pCamera)) )
	{
		// kill weapon sfx's
		func_8007CC14(pThis);

		if (waterFlag == PLAYER_NOT_NEAR_WATER)
		{
			pIns->ah.m_vVelocity.y = -15*SCALING_FACTOR;
			D_8009A4D8(&pIns->ah, pIns->ah.ih.m_vPos, &D_80135CA0);
			pThis->pLastCI = &D_80135CA0;
		}
	}


	// Don't do any of this if we are in cinema mode
	if (!D_80039B98(pCamera))
	{
		D_8005ED10(pThis);

		// is player alive ?
		if (pIns->m_AI.m_Health)
		{
			// is turok looking at someone who shoved him ?
			if (pThis->LookAtShover > 0.0)
			{
				pThis->LookAtShover -= D_800B6B00*(1.0/FRAME_FPS);
				if (pThis->LookAtShover < 0.0)
					pThis->LookAtShover = 0.0;

				pLook = pThis->pShoverAI;
				if (pLook)
				{
					turnang = func_80071DA4(pIns, AI_GetPos(pLook));
					func_80072110(pIns, D_800B6B00*turnang/1.2);
				}
			}
			else
				pThis->pShoverAI = NULL;

			// increase hit sound timer
			pThis->HitSoundTimer += D_800B6B00*(1.0/FRAME_FPS);

			// did turok take the peyote?
			if (pThis->SpiritualTime)
			{
				// blend to
				if (pThis->SpiritualTime > (SECONDS_TO_FRAMES(SPIRITUAL_TIMER) - SPIRITUAL_TIMEIN))
				{
					time = (SECONDS_TO_FRAMES(SPIRITUAL_TIMER) - pThis->SpiritualTime) / SPIRITUAL_TIMEIN ;
					D_800B6B0C = BlendFLOAT(time, 1.0, SPIRITUAL_SKY) ;
					D_800B6B04 = BlendFLOAT(time, D_8000AEB4(pApp), SPIRITUAL_ENEMY) ;
					D_800B6B08 = BlendFLOAT(time, 1.0, SPIRITUAL_PARTICLE) ;
				}
				// blend from
				else if (pThis->SpiritualTime <= SPIRITUAL_TIMEOUT)
				{
					time = pThis->SpiritualTime / SPIRITUAL_TIMEOUT ;
					D_800B6B0C = BlendFLOAT(time, 1.0, SPIRITUAL_SKY) ;
					D_800B6B04 = BlendFLOAT(time, D_8000AEB4(pApp), SPIRITUAL_ENEMY) ;
					D_800B6B08 = BlendFLOAT(time, 1.0, SPIRITUAL_PARTICLE) ;
				}

				pThis->SpiritualTime -= D_800B6B00 ;
				if (pThis->SpiritualTime <= 0)
				{								   
					pThis->SpiritualTime = 0 ;
					D_80033B48(&GetApp()->m_Scene) ;
				}
			}

			// are we shorter ?
			D_8005E238(pThis, pApp);

			// turok using his map ?
			func_8005E7EC(pThis, pCTControl);

			// alllow player to get closer to wall while jumping
			if (pThis->Mode == TMMODE_GRDJUMP)
				D_80135C20.dwFlags |= COLLISIONFLAG_SMALLWALLRADIUS;
			else
				D_80135C20.dwFlags &= ~COLLISIONFLAG_SMALLWALLRADIUS;


			// calc scaler value to adjust vertical analog motion for control
			scalerv = ((float)GetApp()->m_Options.m_VAnalog);
			if (scalerv < 20.0)
				scalerv = 20.0;
			scalerv = scalerv / 128.0;

			// do looking around for swimming
			switch (waterFlag)
			{
				case PLAYER_BELOW_WATERSURFACE:
					if (!pThis->InAntiGrav)
					{
                                  
                                                   
     
						pThis->ActualRotXPlayer = (D_80051454   (pCTControl) - D_80051484(pCTControl))*ANGLE_DTOR(-90)/80;
						dm = (pThis->ActualRotXPlayer - pThis->RotXPlayer) / (12/scalerv);
						pThis->RotXPlayer += dm * D_800B6B00 * 2;
      
						pCI = &D_80135D20;
					}
					else
					{
						pThis->ActualRotXPlayer = (D_80051454   (pCTControl) - D_80051484(pCTControl))*ANGLE_DTOR(-80)/80;
						dm = (pThis->ActualRotXPlayer - pThis->RotXPlayer) / (6/scalerv);
						pThis->RotXPlayer += dm * D_800B6B00 * 2;
						pCI = &D_80135D20;
					}
					break;

				case PLAYER_ON_WATERSURFACE:
					if (		(climbFlag == PLAYER_AT_CLIMBING_SURFACE)
							&&	(pThis->Mode == TMMODE_CLIMBING) )
					{
						func_8005CEBC(pThis, pApp, pCTControl);
					}
					else
					{
						pThis->ActualRotXPlayer = (D_80051454   (pCTControl) - D_80051484(pCTControl))*ANGLE_DTOR(-80)/80;
						dm = (pThis->ActualRotXPlayer - pThis->RotXPlayer) / (6/scalerv);
						pThis->RotXPlayer += dm * D_800B6B00 * 2;
					}
					pCI = &D_80135E20;
					break;

				default:
					if (		(climbFlag == PLAYER_AT_CLIMBING_SURFACE)
							&&	(pThis->Mode == TMMODE_CLIMBING) )
					{
						func_8005CEBC(pThis, pApp, pCTControl);
					}
					else
					if (D_80039BA0(pCamera))
					{
						pThis->RotYPlayer = (D_800514E4(pCTControl) - D_800514B4(pCTControl))*ANGLE_DTOR( 90)/80;

						// make it so you can't look backwards when you jump
						pThis->ActualRotXPlayer = -pThis->JumpLookAng;

						ang = ANGLE_DTOR(90) - pThis->ActualRotXPlayer;
						pThis->ActualRotXPlayer += D_80051484(pCTControl)*ang / 80;

						ang = pThis->ActualRotXPlayer + ANGLE_DTOR(78);
						pThis->ActualRotXPlayer -= D_80051454(pCTControl)*ang / 80;

						dm = (pThis->ActualRotXPlayer - pThis->RotXPlayer) / (6/scalerv);
						pThis->RotXPlayer += dm * D_800B6B00 * 2;
					}
					pCI = &D_80135C20;
					break;
			}


			// make rot x wrap around
			func_80013588(&pThis->RotXPlayer);
			func_80013588(&pThis->RotZPlayer);
			if (climbFlag != PLAYER_AT_CLIMBING_SURFACE)
				func_80013588(&pThis->RotYPlayer);
			func_80013588(&pIns->m_RotY);

			// set rotation offsets
			pApp->m_RotXOffset = pThis->RotXPlayer;
			pApp->m_RotYOffset = pThis->RotYPlayer;
			pApp->m_RotZOffset = pThis->RotZPlayer;

			// do land sfx ?
			if (		(GetApp()->m_Camera.m_Mode != CAMERA_CINEMA_TUROK_FALL_DEATH_MODE)
					&&	(!pThis->PrevOnGround)
					&&	(pThis->CurrentOnGround)
					&& (pThis->PrevVelocityY <= 0) )
			{
				switch (waterFlag)
				{
					case PLAYER_ON_WATERSURFACE:
						if (pThis->PrevVelocityY < -2.0*15.0)		// used to be -0.5
							func_8005CCF0(pThis, pApp, TRUE);

						if (pThis->PrevVelocityY < (-65.0*15.0))			// used to be -50.0
							D_8005EED0(&pIns->ah.ih, SOUND_GENERIC_22, 1, 0);
						break;

					case PLAYER_ABOVE_WATERSURFACE:
					case PLAYER_NOT_NEAR_WATER:
						if (		(pRegionSet)
								&& (pRegionSet->m_dwFlags & REGFLAG_FALLDEATH) )
						{
							break;
						}

						if (pThis->PrevVelocityY < (-65.0*15.0))			// used to be -50.0
							D_8005EED0(&pIns->ah.ih, SOUND_GENERIC_22, 1, 0);
						break;
				}
			}

			// store previous velocity
			pThis->PrevVelocityY = pIns->ah.m_vVelocity.y;


			// is player in a ducking area but not below water ?
			if (waterFlag != PLAYER_BELOW_WATERSURFACE)
			{
				switch(duckFlag)
				{
					case	PLAYER_NOT_DUCKING:
						// if player was previously ducking then set weapon back to what it was
						if (pThis->WeaponAtStartOfDuck != -1)
						{
							if (!func_80058D60(pThis, pThis->WeaponAtStartOfDuck, FALSE))
								func_80058D60(pThis, AI_OBJECT_WEAPON_KNIFE, FALSE);

							pThis->WeaponAtStartOfDuck = -1;
						}
						break;

					case	PLAYER_DUCKING:
					case	PLAYER_DUCKING_ENTRANCE_EXIT:
						// remember weapon if we're just entering a ducking region
						if (pThis->WeaponAtStartOfDuck == -1)
						{
							pThis->WeaponAtStartOfDuck = D_80058E7C(pThis);
							pThis->WeaponAtStartOfWaterDive = pThis->WeaponAtStartOfDuck;

							func_80058D60(pThis, AI_OBJECT_WEAPON_KNIFE, FALSE);
						}
						break;
				}
			}


			// is player on surface or below water ?
			switch (waterFlag)
			{
				case	PLAYER_NOT_NEAR_WATER:
					// allow leaving water in a water cube (from the side)
					if (pThis->PrevMode == TMMODE_SWIMWATER)
					{
						pThis->MoveUpSpeed = 0;
						D_80057410(pThis);

						if (!pThis->PrevAntiGrav)
						{
							// do gasp sfx
							if (pThis->OxygenOut)
								D_8005EED0(&pIns->ah.ih, SOUND_GENERIC_17, 1, 0);
							else
								D_8005EED0(&pIns->ah.ih, SOUND_GENERIC_16, 1, 0);

							pIns->ah.m_vVelocity.y	= 0;

							if (!func_80058D60(pThis, pThis->WeaponAtStartOfWaterDive, FALSE))
								func_80058D60(pThis, AI_OBJECT_WEAPON_KNIFE, FALSE);

							pThis->WeaponAtStartOfWaterDive = -1;

							D_8007F428(&pApp->m_OnScreen, AIRMODE_FADEOUT) ;
							pThis->CannotJumpFromSurface = FALSE;
							func_80055768(pThis);
						}
						pThis->ActualBurstForwardSpeed = 0.0;
						pThis->BurstForwardSpeed = 0.0;
					}
					// fall through

				default:
				case	PLAYER_ABOVE_WATERSURFACE:
					pThis->FeetOnBottomStatus = TMOVE_LAST_NOTINWATER;
					pThis->Oxygen = 0;
					if (pThis->Mode == TMMODE_SWIMWATER ||
						 pThis->Mode == TMMODE_SWIMSURFACE)
					{
						pThis->Mode = TMMODE_GROUND;
					}
					else
					{
						// is player climbing ?
						if (    (climbFlag == PLAYER_AT_CLIMBING_SURFACE)
							  && (pThis->Mode != TMMODE_CLIMBING)
							  && (pThis->Mode != TMMODE_GRDJUMP) )
						{

							// we can't grab onto to top of cliff
	#define	TMOVE_PLAYER_GRABCLIFF		(4*SCALING_FACTOR)
							topCliff = D_80002A44(pApp);
							if (topCliff >= TMOVE_PLAYER_GRABCLIFF)
							{
								// player going into climbing mode
								pThis->Mode = TMMODE_CLIMBING;
								D_8005ED68(pThis);
								D_80057410(pThis);
								pThis->WeaponAtStartOfClimb = D_80058E7C(pThis);
								func_80058E84(pThis, pApp);
								pThis->MoveSpeed = 0.0;
							}
						}
						else if (pThis->Mode == TMMODE_CLIMBING && climbFlag != PLAYER_AT_CLIMBING_SURFACE)
						{
							// player leaving climbing mode
							pThis->Mode = TMMODE_GROUND;

							// put weapon back to what it was prior to climbing
							if (!func_80058D60(pThis, pThis->WeaponAtStartOfClimb, FALSE))
								func_80058D60(pThis, AI_OBJECT_WEAPON_KNIFE, FALSE);

							pThis->WeaponAtStartOfClimb		= -1;
						}
					}
					break;

				case	PLAYER_BELOW_WATERSURFACE:
					if (!pThis->InAntiGrav)
						D_8005B0D4(pThis, pCTControl);

					pThis->FeetOnBottomStatus = TMOVE_LAST_UNDERWATER;
					if (pThis->Mode != TMMODE_SWIMWATER)
					{
						if (pThis->InAntiGrav)
						{
							D_80057410(pThis);
							pThis->MoveSpeed = 0;
							pThis->MoveUpSpeed = 0;
							pThis->SideStepSpeed = 0;
						}
						else
						{
							D_80057410(pThis);
							pThis->MoveSpeed = 0;
							pThis->MoveUpSpeed = 0;
							pThis->SideStepSpeed = 0;
							pThis->CannotSwimUp = TRUE;
							D_8005ED68(pThis);
							func_8005CB40(pThis, pApp);
							pThis->OxygenOut = FALSE;
							func_8005CCF0(pThis, pApp, TRUE);

							if (pThis->WeaponAtStartOfWaterDive == -1)
								pThis->WeaponAtStartOfWaterDive = D_80058E7C(pThis);

							func_80058E84(pThis, pApp);
							//COnScreen__SetAirMode(&pApp->m_OnScreen, AIRMODE_FADEON) ;

							// Start camera wobble
							func_80038EF0(pCamera) ;
						}
					}

					// if 15 seconds away from death, bring on timer
					if (pThis->Oxygen > (TMOVE_OXYGEN_AIRGULP_TIMER-TMOVE_OXYGEN_DISPLAY_TIMER))
						D_8007F428(&pApp->m_OnScreen, AIRMODE_FADEON) ;

					pThis->Mode = TMMODE_SWIMWATER;
					if (!pThis->InAntiGrav)
						func_8005C8BC(pThis, pApp);
					break;

				case	PLAYER_ON_WATERSURFACE:
					if (!pThis->InAntiGrav)
						D_8005B0D4(pThis, pCTControl);

					// are players feet on the bottom of the sea floor ?
					if (		(pThis->PrevOnGround)
							&&	(!pThis->CurrentOnGround) )
					{
						// player has reached drop off - is player ready to fall in quickly ?
						if (pThis->FeetOnBottomStatus == TMOVE_LAST_READYFORFALL)
						{
							// make player fall underwater if they were previously above the water
							if (pThis->Mode == TMMODE_SWIMSURFACE)
							{
								pThis->FeetOnBottomStatus = TMOVE_LAST_UNDERWATER;
								if (pRegionSet)
								{
									if (		(!pThis->InAntiGrav)
											&&	(!(pRegionSet->m_dwFlags & REGFLAG_SHALLOWWATER)) )
									{
										pIns->ah.m_vVelocity.y -= (5*15.0*SCALING_FACTOR);
									}
								}
							}
						}
					}
					else
					{
						// player is ready for a big fall off
						pThis->FeetOnBottomStatus = TMOVE_LAST_READYFORFALL;
					}

					pThis->Oxygen = 0;
					if (    (!D_800511B4(pCTControl))
						  || (pThis->CannotJumpFromSurface) )
					{
						if (pThis->Mode != TMMODE_SWIMSURFACE)
						{
							if (pThis->InAntiGrav)
							{
								pThis->MoveUpSpeed = 0;
								D_80057410(pThis);

								// do leaving anti grav chamber sfx
								if (pThis->PrevMode == TMMODE_SWIMWATER)
								{
									//AI_DoSound(&pIns->ah.ih, SOUND_GENERIC_17, 1, 0);
								}
							}
							else
							{
								pThis->MoveUpSpeed = 0;
								D_80057410(pThis);
								func_8005CD90(pThis, pApp);

								// do gasp sfx
								if (pThis->PrevMode == TMMODE_SWIMWATER)
								{
									func_8005CCF0(pThis, pApp, FALSE);

									if (pThis->OxygenOut)
										D_8005EED0(&pIns->ah.ih, SOUND_GENERIC_17, 1, 0);
									else
										D_8005EED0(&pIns->ah.ih, SOUND_GENERIC_16, 1, 0);
								}

								// put weapon back to what it was prior to water dive
								if (pThis->Mode == TMMODE_SWIMWATER)
								{
									pIns->ah.m_vVelocity.y	= 0;

									if (!func_80058D60(pThis, pThis->WeaponAtStartOfWaterDive, FALSE))
										func_80058D60(pThis, AI_OBJECT_WEAPON_KNIFE, FALSE);

									pThis->WeaponAtStartOfWaterDive = -1;

									D_8007F428(&pApp->m_OnScreen, AIRMODE_FADEOUT) ;

								}
							}
						}
						pThis->Mode = TMMODE_SWIMSURFACE;
					}
					break;
			}

			// assume player is not moving - this means camera changes based on the regions will not take place
			D_800B6B34 = FALSE;

			// is player in the air ? - avoids problem of camera being wonky after jumping onto something
			if (!func_8001BA24(&pIns->ah.ih))
				D_800B6B34 = TRUE;

			// which mode is turok in ?
			if (D_80039BCC(pCamera))
			{
				switch(pThis->Mode)
				{
					case TMMODE_GROUND:
						D_80054CFC ( pThis, pApp, pCTControl );
						break;

					case TMMODE_GRDROLL:
						func_80056D80 ( pThis, pApp, pCTControl );
						D_800B6B34 = TRUE;
						break;

					case TMMODE_GRDJUMP:
						func_80057134 ( pThis, pApp, pCTControl );
						D_800B6B34 = TRUE;
						break;

					case TMMODE_SWIMSURFACE:
						D_8005B0E0(pThis, pApp, pCTControl);
						break;

					case TMMODE_SWIMWATER:
						func_8005B644(pThis, pApp, pCTControl);
						break;

					case TMMODE_CLIMBING:
						func_8005D528(pThis, pApp, pCTControl);
						break;
				}
			}
		}
		else
		{
			// player is dead
			if (	 (!D_800398FC(&GetApp()->m_Camera))
				 && (	  (func_8001BA24(&pIns->ah.ih))
					  || (waterFlag != PLAYER_NOT_NEAR_WATER) ) )
			{
				if (pThis->DeathStage == TMOVE_HEALTH_ALIVE)
				{
					// turok is just starting death
					D_80057410(pThis);
					pIns->ah.m_vVelocity.x = pIns->m_AI.m_vExplosion.x;
					pIns->ah.m_vVelocity.y = pIns->m_AI.m_vExplosion.y;
					pIns->ah.m_vVelocity.z = pIns->m_AI.m_vExplosion.z;
					pThis->DeathStage = TMOVE_HEALTH_DEADSTART;

				}

				pApp->m_RotXOffset = pThis->RotXPlayer;
				pApp->m_RotYOffset = pThis->RotYPlayer;
				pApp->m_RotZOffset = pThis->RotZPlayer;
				func_8005A9F8 ( pThis, pApp, pCTControl );
			}
		}
	}


	// update camera motion
	func_80057428(pThis);

	// straighten knees
	pThis->HeadYPosLand = BlendFLOAT(min(1,TKNEE_STRAIGHTEN_SMOOTH * D_800B6B00),
												pThis->HeadYPosLand,
												0);

	// stop head z rotation
	if (pThis->RotZPlayer > 0)
	{
		dm = (0 - pThis->RotZPlayer) / 4;
		pThis->RotZPlayer += dm;
		if ( pThis->RotZPlayer < 0) pThis->RotZPlayer = 0;
	}
	else if (pThis->RotZPlayer < 0)
	{
		dm = (0 - pThis->RotZPlayer) / 4;
		pThis->RotZPlayer += dm;
		if (pThis->RotZPlayer > 0) pThis->RotZPlayer = 0;
	}

	// stop gun kick x rotation
	if ( pThis->GunKickXRot > 0 )
	{
		dm = pThis->GunKickXRot / TTHEAD_GUNKICKXROT_SMOOTH;
		pThis->GunKickXRot -= dm;
		if ( pThis->GunKickXRot < 0 ) pThis->GunKickXRot = 0;
	}
	else if ( pThis->GunKickXRot < 0 )
	{
		dm = pThis->GunKickXRot / TTHEAD_GUNKICKXROT_SMOOTH;
		pThis->GunKickXRot -= dm;
		if ( pThis->GunKickXRot > 0 ) pThis->GunKickXRot = 0;
	}

	// add swimming bank angle
	pThis->RotZPlayer += pThis->SwimBankAngle;
	dm = (pThis->ActualSwimBankAngle - pThis->SwimBankAngle) / 9;
	pThis->SwimBankAngle += dm;

	D_800574C4(pThis, pApp);
	D_8005DC98(pThis, pApp);

	// pressure plates
	// add support for other collision infos
	if (pIns->m_AI.m_Health && pCI)
	{
		if (pRegionSet)
		{
			if (pRegionSet->m_dwFlags & REGFLAG_PRESSUREPLATE)
			{
				if (pRegionSet->m_dwFlags & REGFLAG_PRESSUREPLATENEEDSCOLLISION)
					pressurePlate = (pCI->pWallCollisionRegion != NULL);
				else
					pressurePlate = TRUE;

				if (pressurePlate)
				{
					if (		(pRegionSet->m_dwFlags & REGFLAG_PRESSUREPLATESOUND)
							&& (!pThis->JustEnteredPressurePlate) )
					{
						playsound = TRUE ;
						pThis->JustEnteredPressurePlate = TRUE;

						if (		(GetApp()->m_bTrainingMode)			// in training mode
								&&	(GetApp()->m_TrainingType)				// in timed mode
								&& (pRegionSet->m_PressureID > 10000)	// low
								&& (pRegionSet->m_PressureID < 11000))	// high
								playsound = FALSE ;

						if (playsound)
							D_8005EED0(&pIns->ah.ih, pRegionSet->m_PressurePlateSoundNumber, 1, 0);
					}
					D_80070DA8(&pIns->ah.ih, &pIns->ah.ih, AI_MEVENT_PRESSUREPLATE, AI_SPECIES_ALL, pIns->ah.ih.m_vPos, (float) pRegionSet->m_PressureID);
				}
			}
			else
				pThis->JustEnteredPressurePlate = FALSE;
		}


		// get pickups
		// add support for other collision infos
		if (pThis->pLastCI)
		{
			if (pThis->pLastCI->pInstanceCollision)
			{
				if (pThis->pLastCI->pInstanceCollision->m_Type == I_SIMPLE)
				{
					nObjType = D_8001D398(pThis->pLastCI->pInstanceCollision);

					if (func_80071820(nObjType))
					{
						func_800915C4((CGameSimpleInstance*)pThis->pLastCI->pInstanceCollision);
					}
					else if (func_80071804(nObjType))
					{
						func_80093A00((CGameSimpleInstance*)pThis->pLastCI->pInstanceCollision);
					}
				}
			}
		}


		// player standing in area with the sun ?
		if (		pRegionSet
				&& (!GetApp()->m_Camera.m_LetterBoxScale) )
		{
			if (pRegionSet->m_dwFlags & REGFLAG_SUN)
				pThis->InSun = TRUE;
			else
				pThis->InSun = FALSE;
		}
		else
		{
			pThis->InSun = FALSE;
		}

		// player warping ?
		if (pRegionSet)
		{
			// warp points
			if (		(pRegionSet->m_dwFlags & REGFLAG_WARPENTRANCE)
					&&	(!pThis->JustWarped) )
			{
				if (		(func_8001BA24(&pIns->ah.ih))
						||	(pRegionSet->m_dwFlags & REGFLAG_WARPIFINAIR) )
				{
					D_8005ED68(pThis);

					D_800056B8(GetApp(),
										  pRegionSet->m_WarpID,
										  WARP_WITHINLEVEL,
										  pRegionSet->m_dwFlags & REGFLAG_STOREWARPRETURN);

					pThis->JustWarped = TRUE;
				}
			}
			else if (!(pRegionSet->m_dwFlags & REGFLAG_WARPENTRANCE))
			{
				pThis->JustWarped = FALSE;
			}
		}

		// player standing in lava ?
		if (pRegionSet)
		{
			if (		(pRegionSet->m_dwFlags & REGFLAG_LAVA)
					&&	(func_8001BA24(&pIns->ah.ih)) )
			{
				pThis->InLava = TRUE;
			}
			else
			{
				pThis->InLava = FALSE;
			}
		}


		// player standing on return warp ?
		if (pRegionSet)
		{
			// return warp
			if (		(pRegionSet->m_dwFlags & REGFLAG_WARPRETURN)
					&&	(!pThis->JustWarped) )
			{
				if (func_8001BA24(&pIns->ah.ih))
				{
					D_8005ED68(pThis);

					D_80005690(pApp);
					pThis->JustWarped = TRUE;
				}
			}
			else if (		(!(pRegionSet->m_dwFlags & REGFLAG_WARPRETURN))
							&&	(!(pRegionSet->m_dwFlags & REGFLAG_WARPENTRANCE)) )
			{
				pThis->JustWarped = FALSE;
			}
		}


		// player entering checkpoint ?
		if (pRegionSet)
		{
			// different checkpoint than current WARPID?
			if ((pThis->CurrentCheckpoint != pRegionSet->m_SaveCheckpointID) &&
				(pRegionSet->m_dwFlags & REGFLAG_CHECKPOINT))
			{
				// Special case for bosses
				if ((GetApp()->m_BossLevel) && (GetApp()->m_FadeStatus == FADE_NULL))
				{
					// Cinema's and dying will take player back to start pt!
					GetApp()->m_WarpID = pRegionSet->m_SaveCheckpointID ;
					pThis->CurrentCheckpoint = pRegionSet->m_SaveCheckpointID ;
				}
				else
				{
					func_800831E4(D_800BDEB0) ;
					D_8005EED0(&pIns->ah.ih, SOUND_GENERIC_249, 1, 0);
				}
			}
			// entered a save region?
			if (!D_800510C4(pCTControl))
			{
				if (pRegionSet->m_dwFlags & REGFLAG_SAVEPOINT)
				{
					if (func_8001BA24(&pIns->ah.ih))
					{
						if (pThis->JustEnteredSaveRegion)
						{
							GetApp()->m_MapMode = FALSE ;
							GetApp()->m_MapAlpha = 0 ;
							GetApp()->m_MapStatus = MAP_NULL ;

							GetApp()->m_bPause = TRUE;
							D_80084BB0(&GetApp()->m_Pause);
							GetApp()->m_Pause.m_Mode = PAUSE_NORMAL;
							D_8000DEB8(&GetApp()->m_Requestor,
														D_800BDEBC, D_800BDECC) ;
							func_8007CC14(pThis);
							D_8005ED68(pThis);
							GetApp()->m_bRequestor = TRUE ;
							pThis->JustEnteredSaveRegion = FALSE ;
						}
					}
					else
						pThis->JustEnteredSaveRegion = TRUE ;
				}
				else
					pThis->JustEnteredSaveRegion = TRUE ;
			}
			else if (		(!pThis->JustEnteredSaveRegion)
							&&	(!(pRegionSet->m_dwFlags & REGFLAG_SAVEPOINT)) )
			{
				pThis->JustEnteredSaveRegion = TRUE;
			}


			if (pRegionSet->m_dwFlags & (REGFLAG_CHECKPOINT | REGFLAG_SAVEPOINT))
			{
				pThis->CurrentCheckpoint = pRegionSet->m_SaveCheckpointID;
//	 rmonPrintf("touched checkpoint id:%d\n", pThis->CurrentCheckpoint) ;
			}
		}


		// player entering training text region?
		if ((pRegionSet) && (GetApp()->m_bTrainingMode))
		{
			if ((pRegionSet->m_dwFlags & REGFLAG_PRESSUREPLATE) &&
				(pRegionSet->m_PressureID >= 10000) &&
				(pRegionSet->m_PressureID != 10008) &&
				(pRegionSet->m_PressureID != 10014))
			{
				if (pThis->JustEnteredTrainingRegion == FALSE)
				{
					if (	(pRegionSet->m_PressureID == 10021)
						|| (GetApp()->m_TrainingType ==0))
					{
						GetApp()->m_bTraining = TRUE;
						D_80087B10(&GetApp()->m_Training, pRegionSet->m_PressureID);
						pThis->JustEnteredTrainingRegion = TRUE ;
					}
				}
			}
			else
			{
				GetApp()->m_bTraining = FALSE;
				GetApp()->m_Training.m_Mode = TRAINING_FADEDOWN ;
				pThis->JustEnteredTrainingRegion = FALSE ;
			}
		}


		// player touching lock?
		if (pRegionSet)
		{
			if ((pRegionSet->m_PressureID <=8) && (pRegionSet->m_dwFlags & REGFLAG_PRESSUREPLATE))
			{
				if (func_8001BA24(&pIns->ah.ih))
				{
					//if (pThis->JustEnteredLockRegion)
					{
						switch (pRegionSet->m_PressureID)
						{
							case 2:
								func_80083288(D_800BDEDC, 0x10) ;
								func_80083288(D_800BDEF0, 0x11) ;
								break ;
							case 3:
								func_80083288(D_800BDEFC, 0x20) ;
								func_80083288(D_800BDF10, 0x21) ;
								break ;
							case 4:
								func_80083288(D_800BDF24, 0x30) ;
								func_80083288(D_800BDF38, 0x31) ;
								break ;
							case 5:
								func_80083288(D_800BDF44, 0x40) ;
								func_80083288(D_800BDF58, 0x41) ;
								break ;
							case 6:
								func_80083288(D_800BDF68, 0x50) ;
								func_80083288(D_800BDF7C, 0x51) ;
								break ;
							case 7:
								func_80083288(D_800BDF90, 0x70) ;
								func_80083288(D_800BDFA4, 0x71) ;
								break ;
							case 8:
								func_80083288(D_800BDFB4, 0x80) ;
								func_80083288(D_800BDFC8, 0x81) ;
								break ;

							//default:
							//	pThis->JustEnteredLockRegion = TRUE ;
							//	break ;
						}
						//if (txtA)
						//	txtA->DisplayTime = 40 ;
						//if (txtB)
						//	txtB->DisplayTime = 40 ;
						//if ((txtA) || (txtB))
						//	pThis->JustEnteredLockRegion = FALSE ;
					}
				}
//				else
//					pThis->JustEnteredLockRegion = TRUE ;
			}
//			else
//				pThis->JustEnteredLockRegion = TRUE ;
		}


		// player entering instant death region ?
		if (pRegionSet)
		{
			if (pRegionSet->m_dwFlags & REGFLAG_INSTANTDEATH)
			{
				if (!D_80039B98(pCamera))
				{
					if (func_8001BA24(&pIns->ah.ih))
					{
						if (pThis->JustEnteredDeathRegion)
						{
							pThis->DeathRegionTimer = pRegionSet->m_DeathTimeDelay;
							pThis->JustEnteredDeathRegion = FALSE;
						}

						if (!pThis->JustEnteredDeathRegion)
						{
							// do hit points damage
							pThis->DeathRegionTimer += D_800B6B00*(1.0/FRAME_FPS);
							if (pThis->DeathRegionTimer >= pRegionSet->m_DeathTimeDelay)
							{
								pThis->DeathRegionTimer -= pRegionSet->m_DeathTimeDelay;
								D_80071058(pIns, pRegionSet->m_DeathHitPoints, TRUE, TRUE);
							}
						}
					}
					else
					{
						// character is not on the ground
						pThis->JustEnteredDeathRegion = TRUE;
					}
				}
			}
			else
			{
				pThis->JustEnteredDeathRegion = TRUE;
			}
		}
	}

	// if in cinema mode or player is dead - switch off map
	if (!(pIns->m_AI.m_Health))
	{
		pThis->MapToggle = FALSE;
		pThis->MapScrolling = FALSE;
		pThis->MapButtonTimer = 0.0;
	}


	// blend the aim direction
	func_8005E410(pThis);
	pThis->PrevMode = pThis->Mode;

	// update on screen items
	func_8007F320(&pApp->m_OnScreen, func_80058644(pThis), D_800583D4(pThis));
	func_8007F11C(&pApp->m_OnScreen, pIns->m_AI.m_Health);
	D_8007F270(&pApp->m_OnScreen, pThis->Lives);
	D_8007F2D4(&pApp->m_OnScreen, pThis->Tokens);

//	if (!(pApp->m_dwCheatFlags & CHEATFLAG_MODIFYENEMY))
		D_8005EA80(pThis, pApp);

	// modify enemies position ?
/*	if (pApp->m_dwCheatFlags & CHEATFLAG_MODIFYENEMY)
	{
		CTMove__ModifyEnemy(pThis, pApp);

		if (CTControl__IsSelectEnemyPrev(pCTControl))
			CTMove__ChangeEnemy(pThis, pApp, FALSE);

		else if (CTControl__IsSelectEnemyNext(pCTControl))
			CTMove__ChangeEnemy(pThis, pApp, TRUE);

		CTMove__MoveEnemy(pThis, pApp, pCTControl);

		if (CTControl__IsGrenadeLauncherFired(pCTControl))
			CTMove__ResetEnemy(pThis);
	}
*/

	// don't allow turoks eyes to get closer than this distance
	if (pApp->m_YPosOffset<0.5*SCALING_FACTOR)
		pApp->m_YPosOffset = 0.5*SCALING_FACTOR;


// should be 116.390594
//	if (pIns && pCamera && (!CCamera__InCinemaMode(pCamera)) )
//	{
//		ycoor = pIns->ah.ih.m_vPos.y;
//		if (ycoorjump < pIns->ah.ih.m_vPos.y)
//			ycoorjump = pIns->ah.ih.m_vPos.y;
//
//		sprintf(buffer1, "%f", ycoor);
//		sprintf(buffer2, "%f", ycoorjump - ycoor);
//
//		COnScreen__AddGameTextWithId(buffer1, 27);
//		COnScreen__AddGameTextWithId(buffer2, 28);
//	}
//		sprintf(buffer1, "%f", pIns->ah.m_vVelocity.y);
//		COnScreen__AddGameTextWithId(buffer1, 27);

}

