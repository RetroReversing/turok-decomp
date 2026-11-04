#include "decompdecomp_sync_1874f110bdd74908c497.h"
#line 1 "func.c"
#line 487 "reference.c"
void func_800915C4(CGameSimpleInstance *pPickup)
{
	CVector3					vPos;
	CGameObjectInstance	*pPlayer;
	int						CurrentWeapon,
								duckFlag;
	BOOL						noammo ;
	CInstanceHdr			*pInst ;

	// dynamic simple instance may have been deallocated since the collision
	// list was built
	if (pPickup->m_wFlags & SIMPLE_FLAG_DYNAMIC)
		if (!CDynamicSimple__IsAllocated((CDynamicSimple*) pPickup))
			return;

	vPos.x = D_80129520.Ears.vPos.x;
	vPos.y = D_80129520.Ears.vPos.y;
	vPos.z = D_80129520.Ears.vPos.z;

	// at the end of the switch, should we delete the pickup
	// only time it wouldn't is if a weapon is full...
	pPlayer = CEngineApp__GetPlayer(GetApp());

	duckFlag = func_80002A8C(GetApp());

	CurrentWeapon = func_80091550(D_80128C20.WeaponSelect) ;

	noammo = FALSE ;

	// do whatever is needed
	switch (D_8001D398(&pPickup->ah.ih))
	{
		// ------------------------------------------------------------------
		// Health Types
		// ------------------------------------------------------------------
		// Adds to health
		// some types go above 100, some increase max to above 100

		case AI_OBJECT_PICKUP_HEALTH_2:
			pPlayer->m_AI.m_Health += 2 ;
			if (pPlayer->m_AI.m_Health >250)
				pPlayer->m_AI.m_Health = 250 ;
			func_80031974(&GetApp()->m_Scene, SOUND_HEALTH_PICKUP_1, 0, NULL, &vPos, 0);

			func_800831E4(D_800ED510) ;
			break ;

		case AI_OBJECT_PICKUP_HEALTH_10:
			pPlayer->m_AI.m_Health += 10 ;
			if (pPlayer->m_AI.m_Health > D_80128C20.MaxHealth)
				pPlayer->m_AI.m_Health = D_80128C20.MaxHealth ;

			func_80031974(&GetApp()->m_Scene, SOUND_HEALTH_PICKUP_1, 0, NULL, &vPos, 0);
			func_800831E4(D_800ED51C) ;
			break ;

		case AI_OBJECT_PICKUP_HEALTH_25:
			pPlayer->m_AI.m_Health += 25 ;
			if (pPlayer->m_AI.m_Health > D_80128C20.MaxHealth)
				pPlayer->m_AI.m_Health = D_80128C20.MaxHealth ;
			func_80031974(&GetApp()->m_Scene, SOUND_HEALTH_PICKUP_1, 0, NULL, &vPos, 0);
			func_800831E4(D_800ED528) ;
			break ;

		case AI_OBJECT_PICKUP_HEALTH_100:
			pPlayer->m_AI.m_Health = D_80128C20.MaxHealth ;
			func_80031974(&GetApp()->m_Scene, SOUND_HEALTH_PICKUP_1, 0, NULL, &vPos, 0);
			func_800831E4(D_800ED534) ;
			break ;

		case AI_OBJECT_PICKUP_HEALTH_100PLUS:
			pPlayer->m_AI.m_Health += 100 ;			// increase regardless of current max
			if (pPlayer->m_AI.m_Health >250)
				pPlayer->m_AI.m_Health = 250 ;
			func_80031974(&GetApp()->m_Scene, SOUND_HEALTH_PICKUP_1, 0, NULL, &vPos, 0);
			func_800831E4(D_800ED540) ;
			break ;


		case AI_OBJECT_PICKUP_MORTAL_WOUND:
			D_80128C20.MaxHealth += 5 ;
			if (D_80128C20.MaxHealth > AI_HEALTH_PLAYER_MAX)
				D_80128C20.MaxHealth = AI_HEALTH_PLAYER_MAX ;

			if (pPlayer->m_AI.m_Health < D_80128C20.MaxHealth)
				pPlayer->m_AI.m_Health = D_80128C20.MaxHealth ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);
			func_800831E4(D_800ED550) ;
			break ;

		// ------------------------------------------------------------------
		// Misc Types
		// ------------------------------------------------------------------
		case AI_OBJECT_PICKUP_BACKPACK:
			D_80128C20.BackPackFlag = TRUE;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);
			func_800831E4(D_800ED560) ;
			break ;

		case AI_OBJECT_PICKUP_SPIRITUAL:
			func_800831E4(D_800ED56C) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);

			D_80128C20.SpiritualTime = SECONDS_TO_FRAMES(SPIRITUAL_TIMER) ;
			break ;

//		case AI_OBJECT_PICKUP_MAP:
//			COnScreen__AddGameText("map") ;
//			CScene__DoSoundEffect(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);
//			CEngineApp__RevealAllMap(GetApp()) ;
//			// set map TRUE
//			break ;

		case AI_OBJECT_PICKUP_KEY2:
			D_80128C20.LastKeyTexture = 0 ;
			D_80128C20.Level2Keys |= (1<<(AI_GetEA(pPickup)->m_Id&3)) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);
			D_8003983C(&GetApp()->m_Camera, CINEMA_FLAG_TUROK_PICKUP_KEY) ;
			break ;

		case AI_OBJECT_PICKUP_KEY3:
			D_80128C20.LastKeyTexture = 1 ;
			D_80128C20.Level3Keys |= (1<<(AI_GetEA(pPickup)->m_Id&3)) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);
			D_8003983C(&GetApp()->m_Camera, CINEMA_FLAG_TUROK_PICKUP_KEY) ;
			break ;

		case AI_OBJECT_PICKUP_KEY4:
			D_80128C20.LastKeyTexture = 2 ;
			D_80128C20.Level4Keys |= (1<<(AI_GetEA(pPickup)->m_Id&3)) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);
			D_8003983C(&GetApp()->m_Camera, CINEMA_FLAG_TUROK_PICKUP_KEY) ;
			break ;

		case AI_OBJECT_PICKUP_KEY5:
			D_80128C20.LastKeyTexture = 3 ;
			D_80128C20.Level5Keys |= (1<<(AI_GetEA(pPickup)->m_Id&3)) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);
			D_8003983C(&GetApp()->m_Camera, CINEMA_FLAG_TUROK_PICKUP_KEY) ;
			break ;

		case AI_OBJECT_PICKUP_KEY6:
			D_80128C20.LastKeyTexture = 4 ;
			D_80128C20.Level6Keys |= (1<<(AI_GetEA(pPickup)->m_Id&3)) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);
			D_8003983C(&GetApp()->m_Camera, CINEMA_FLAG_TUROK_PICKUP_KEY) ;
			break ;

		case AI_OBJECT_PICKUP_KEY7:
			D_80128C20.LastKeyTexture = 5 ;
			D_80128C20.Level7Keys |= (1<<(AI_GetEA(pPickup)->m_Id&3)) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);
			D_8003983C(&GetApp()->m_Camera, CINEMA_FLAG_TUROK_PICKUP_KEY) ;
			break ;

		case AI_OBJECT_PICKUP_KEY8:
		case AI_OBJECT_PICKUP_KEY8MANTIS:
			// setup for different sun key models, uses texture 0!
			if (AI_GetEA(pPickup)->m_Id != 4)
				D_80128C20.LastKeyTexture = -1 ;
			else
				D_80128C20.LastKeyTexture = -2 ;

			D_80128C20.Level8Keys |= (1<<(AI_GetEA(pPickup)->m_Id%10)) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_4, 0, NULL, &vPos, 0);
			D_8003983C(&GetApp()->m_Camera, CINEMA_FLAG_TUROK_PICKUP_KEY) ;
			break ;



		case AI_OBJECT_PICKUP_CHRONOSCEPTOR1:
			D_80128C20.ChronoSceptorPieces |= 1 ;
			goto chrono;
		case AI_OBJECT_PICKUP_CHRONOSCEPTOR2:
			D_80128C20.ChronoSceptorPieces |= 2 ;
			goto chrono;
		case AI_OBJECT_PICKUP_CHRONOSCEPTOR3:
			D_80128C20.ChronoSceptorPieces |= 4 ;
			goto chrono;
		case AI_OBJECT_PICKUP_CHRONOSCEPTOR4:
			D_80128C20.ChronoSceptorPieces |= 8 ;
			goto chrono;
		case AI_OBJECT_PICKUP_CHRONOSCEPTOR5:
			D_80128C20.ChronoSceptorPieces |= 16 ;
			goto chrono;
		case AI_OBJECT_PICKUP_CHRONOSCEPTOR6:
			D_80128C20.ChronoSceptorPieces |= 32 ;
			goto chrono;
		case AI_OBJECT_PICKUP_CHRONOSCEPTOR7:
			D_80128C20.ChronoSceptorPieces |= 64 ;
			goto chrono;
		case AI_OBJECT_PICKUP_CHRONOSCEPTOR8:
			D_80128C20.ChronoSceptorPieces |= 128 ;

chrono:
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &vPos, 0);

			// completed weapon
			if (D_80128C20.ChronoSceptorPieces == 0xff)
			{
				func_800831E4(D_800ED584) ;
				D_80128C20.ChronoscepterFlag	= TRUE;
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_CHRONOSCEPTER, DEFAULT_CHRONOSCEPTOR_AMMO) ;

				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_CHRONOSCEPTER, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			else
				func_800831E4(D_800ED594) ;
			break ;





		// ------------------------------------------------------------------
		// Armor Types
		// ------------------------------------------------------------------
		case AI_OBJECT_PICKUP_ARMOR_TEK:
			D_80128C20.ArmorFlag = TRUE;
			D_80128C20.ArmorAmount += (DEFAULT_TEK_ARMOR *3);
			func_80031974(&GetApp()->m_Scene, SOUND_HEALTH_PICKUP_1, 0, NULL, &vPos, 0);
			func_800831E4(D_800ED5A8) ;
			break ;

		// ------------------------------------------------------------------
		// Token Types
		// ------------------------------------------------------------------
		case AI_OBJECT_PICKUP_SMALL_TOKEN:
			D_80128C20.Tokens += 1 ;

			if (	(D_80128C20.Lives >= TMOVE_MAX_LIVES)
				&& (D_80128C20.Tokens >= 99))
				D_80128C20.Tokens = 99 ;
			else if (D_80128C20.Tokens >= 100)
			{
				D_80128C20.Tokens -= 100 ;
				D_8005E768(&D_80128C20, 1);
			}

			func_80031974(&GetApp()->m_Scene, SOUND_HEALTH_PICKUP_1, 0, NULL, &vPos, 0);
//   		COnScreen__AddGameText("life force") ;
			break ;

		case AI_OBJECT_PICKUP_LARGE_TOKEN:
			D_80128C20.Tokens += 10 ;

			if (	(D_80128C20.Lives >= TMOVE_MAX_LIVES)
				&& (D_80128C20.Tokens >= 99))
				D_80128C20.Tokens = 99 ;
			else if (D_80128C20.Tokens >= 100)
			{
				D_80128C20.Tokens -= 100 ;
				D_8005E768(&D_80128C20, 1);
			}

			func_80031974(&GetApp()->m_Scene, SOUND_HEALTH_PICKUP_1, 0, NULL, &vPos, 0);
//   		COnScreen__AddGameText("10 life force") ;
			break ;




		// ------------------------------------------------------------------
		// Weapon Types
		// ------------------------------------------------------------------
		// when picking up a weapon, it will become the currently chosen one
		// only if it is of higher power than the current weapon using,
		// if weapon is not owned, but you have all the ammo, pick it up with no ammo

		case AI_OBJECT_PICKUP_TEKBOW:
			// you always have this weapon, so any checks are redundant (made payable to carl!)
			func_800831E4(D_800ED5B4) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &vPos, 0);

			if (		(TEKBOW > CurrentWeapon)
					&&	(D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&&	(duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_TEKBOW, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_PISTOL:
			if (D_80128C20.SemiAutomaticPistolFlag == FALSE)
				func_800831E4(D_800ED5BC) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &vPos, 0);
			D_80128C20.SemiAutomaticPistolFlag	= TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL, DEFAULT_PISTOL_AMMO) ;

			if (		(PISTOL > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&&	(duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_RIFLE:
			if (D_80128C20.AssaultRifleFlag	== FALSE)
				func_800831E4(D_800ED5C4) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &vPos, 0);
			D_80128C20.AssaultRifleFlag	= TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_ASSAULTRIFLE, DEFAULT_RIFLE_AMMO) ;

			if (		(RIFLE > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_ASSAULTRIFLE, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_RIOTSHOTGUN:
			if (D_80128C20.RiotShotgunFlag == FALSE)
				func_800831E4(D_800ED5D4) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_2, 0, NULL, &vPos, 0);
			D_80128C20.RiotShotgunFlag = TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_RIOTSHOTGUN, DEFAULT_RIOTSHOTGUN_AMMO) ;

			if (		(SHOTGUN > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_RIOTSHOTGUN, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_AUTOSHOTGUN:
			if (D_80128C20.AutomaticShotgunFlag == FALSE)
				func_800831E4(D_800ED5DC) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_2, 0, NULL, &vPos, 0);
			D_80128C20.AutomaticShotgunFlag = TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_AUTOMATICSHOTGUN, DEFAULT_AUTOSHOTGUN_AMMO) ;

			if (		(AUTOSHOTGUN > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_AUTOMATICSHOTGUN, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_MINIGUN:
			if (D_80128C20.MiniGunFlag == FALSE)
				func_800831E4(D_800ED5EC) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &vPos, 0);
			D_80128C20.MiniGunFlag = TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_MINIGUN, DEFAULT_MINIGUN_AMMO) ;

			if (		(MINIGUN > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_MINIGUN, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_GRENADELAUNCHER:
			if (D_80128C20.GrenadeLauncherFlag == FALSE)
				func_800831E4(D_800ED5F4) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_5, 0, NULL, &vPos, 0);
			D_80128C20.GrenadeLauncherFlag = TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_GRENADE_LAUNCHER, DEFAULT_GRENADELAUNCHER_AMMO) ;

			if (		(GRENADE > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_GRENADE_LAUNCHER, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		// longhunter pulse rifle
		case AI_OBJECT_PICKUP_MACHINEGUN:
			if (D_80128C20.MachineGunFlag == FALSE)
				func_800831E4(D_800ED608) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_3, 0, NULL, &vPos, 0);
			D_80128C20.MachineGunFlag = TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_MACHINEGUN, DEFAULT_MACHINEGUN_AMMO) ;

			if (		(PULSERIFLE > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_MACHINEGUN, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_TECHWEAPON1:
			if (D_80128C20.TechWeapon1Flag == FALSE)
				func_800831E4(D_800ED614) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_3, 0, NULL, &vPos, 0);
			D_80128C20.TechWeapon1Flag = TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_TECHWEAPON1, DEFAULT_TECH1_AMMO) ;

			if (		(INFANTRY > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_TECHWEAPON1, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;


		case AI_OBJECT_PICKUP_ROCKET:
			if (D_80128C20.RocketFlag == FALSE)
				func_800831E4(D_800ED624) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_7, 0, NULL, &vPos, 0);
			D_80128C20.RocketFlag = TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_ROCKET, DEFAULT_ROCKET_AMMO) ;

			if (		(ROCKET > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_ROCKET, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_SHOCKWAVE:
			if (D_80128C20.ShockwaveFlag == FALSE)
				func_800831E4(D_800ED63C) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_3, 0, NULL, &vPos, 0);
			D_80128C20.ShockwaveFlag = TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_SHOCKWAVE, DEFAULT_SHOCKWAVE_AMMO) ;

			if (		(SHOCKWAVE > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_SHOCKWAVE, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_TECHWEAPON2:
			if (D_80128C20.TechWeapon2Flag == FALSE)
				func_800831E4(D_800ED650) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_3, 0, NULL, &vPos, 0);
			D_80128C20.TechWeapon2Flag = TRUE;
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_TECHWEAPON2, DEFAULT_TECH2_AMMO) ;

			if (		(FUSION > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_TECHWEAPON2, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;


		// ------------------------------------------------------------------
		// Ammunition Types
		// ------------------------------------------------------------------
		// adds to pool, or individual weapon ammo
		// if weapon is full, will not pickup.
		// if ammo is currently empty, and weapon is higher power than
		// weapon currently using, switch to it.

		case AI_OBJECT_PICKUP_AMMO_ARROWS:
			if (D_80128C20.TekBowAmmo == 0)
				noammo = TRUE ;
			func_800831E4(D_800ED660) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_6, 0, NULL, &vPos, 0);
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_TEKBOW, REFILL_ARROW) ;

			if (		(noammo)
					&& (TEKBOW > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_TEKBOW, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_AMMO_EXPARROWSSMALL:
			if (D_80128C20.ExpTekBowAmmo == 0)
				noammo = TRUE ;
			func_800831E4(D_800ED66C) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_6, 0, NULL, &vPos, 0);
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_TEKBOW, -REFILL_EXPARROW_SMALL) ;

			if (		(noammo)
					&& (POWEREDUP_TEKBOW > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_TEKBOW, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}

			break ;

		case AI_OBJECT_PICKUP_AMMO_EXPARROWSLARGE:
			if (D_80128C20.ExpTekBowAmmo == 0)
				noammo = TRUE ;
			func_800831E4(D_800ED67C) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_6, 0, NULL, &vPos, 0);
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_TEKBOW, -REFILL_EXPARROW_LARGE) ;

			if (		(noammo)
					&& (POWEREDUP_TEKBOW > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_TEKBOW, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_AMMO_BULLETCLIP:
		case AI_OBJECT_PICKUP_AMMO_BULLETBOX:
			// if you have an empty pistol, or rifle, and its more powerful than current, use it
			if (D_80128C20.BulletPool == 0)
				noammo = TRUE ;
			if (D_8001D398(&pPickup->ah.ih) == AI_OBJECT_PICKUP_AMMO_BULLETCLIP)
			{
				func_800831E4(D_800ED68C) ;
				func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &vPos, 0);
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL, REFILL_BULLET_CLIP) ;
			}
			else
			{
				func_800831E4(D_800ED694) ;
				func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &vPos, 0);
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL, REFILL_BULLET_BOX) ;
			}
			if (noammo)
			{
				if (		(D_80128C20.AssaultRifleFlag)
						&& (RIFLE > CurrentWeapon)
						&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
						&& (duckFlag == PLAYER_NOT_DUCKING) )
				{
					func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_ASSAULTRIFLE, FALSE) ;
					D_8005ED68(&D_80128C20) ;
				}
				else if (		(D_80128C20.SemiAutomaticPistolFlag)
								&& (PISTOL > CurrentWeapon)
								&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
								&& (duckFlag == PLAYER_NOT_DUCKING) )
				{
					func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL, FALSE) ;
					D_8005ED68(&D_80128C20) ;
				}
			}
			break ;


		case AI_OBJECT_PICKUP_AMMO_SHOTGUN:
		case AI_OBJECT_PICKUP_AMMO_SHOTGUNBOX:
			// if you have an empty shotgun, and its more powerful than current, use it
			if (D_80128C20.ShotgunPool == 0)
				noammo = TRUE ;
			if (D_8001D398(&pPickup->ah.ih) == AI_OBJECT_PICKUP_AMMO_SHOTGUN)
			{
				func_800831E4(D_800ED6A4) ;
				func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_2, 0, NULL, &vPos, 0);
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_AUTOMATICSHOTGUN, REFILL_SHOTGUN_SHELLS) ;
			}
			else
			{
				func_800831E4(D_800ED6B4) ;
				func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_2, 0, NULL, &vPos, 0);
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_AUTOMATICSHOTGUN, REFILL_SHOTGUN_BOX) ;
			}
			if (noammo)
			{
				if (		(D_80128C20.AutomaticShotgunFlag)
						&& (AUTOSHOTGUN > CurrentWeapon)
						&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
						&& (duckFlag == PLAYER_NOT_DUCKING) )
				{
					func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_AUTOMATICSHOTGUN, FALSE) ;
					D_8005ED68(&D_80128C20) ;
				}
				else if (		(D_80128C20.RiotShotgunFlag)
								&& (SHOTGUN > CurrentWeapon)
								&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
								&& (duckFlag == PLAYER_NOT_DUCKING) )
				{
					func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_RIOTSHOTGUN, FALSE) ;
					D_8005ED68(&D_80128C20) ;
				}
			}
			break ;

		case AI_OBJECT_PICKUP_AMMO_EXPSHOTGUN:
		case AI_OBJECT_PICKUP_AMMO_EXPSHOTGUNBOX:
			// if you have an empty shotgun, and its more powerful than current, use it
			if (D_80128C20.ExpShotgunPool == 0)
				noammo = TRUE ;
			if (D_8001D398(&pPickup->ah.ih) == AI_OBJECT_PICKUP_AMMO_EXPSHOTGUN)
			{
				func_800831E4(D_800ED6CC) ;
				func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_2, 0, NULL, &vPos, 0);
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_AUTOMATICSHOTGUN, -REFILL_EXPSHOTGUN_SHELLS) ;
			}
			else
			{
				func_800831E4(D_800ED6E0) ;
				func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_2, 0, NULL, &vPos, 0);
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_AUTOMATICSHOTGUN, -REFILL_EXPSHOTGUN_BOX) ;
			}
			if (noammo)
			{
				if (		(D_80128C20.AutomaticShotgunFlag)
						&& (POWEREDUP_AUTOSHOTGUN > CurrentWeapon)
						&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
						&& (duckFlag == PLAYER_NOT_DUCKING) )
				{
					func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_AUTOMATICSHOTGUN, FALSE) ;
					D_8005ED68(&D_80128C20) ;
				}
				else if (		(D_80128C20.RiotShotgunFlag)
								&& (POWEREDUP_SHOTGUN > CurrentWeapon)
								&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
								&& (duckFlag == PLAYER_NOT_DUCKING) )
				{
					func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_RIOTSHOTGUN, FALSE) ;
					D_8005ED68(&D_80128C20) ;
				}
			}
			break ;

		case AI_OBJECT_PICKUP_AMMO_MINIGUN:
			// if you have an empty minigun, and its more powerful than current, use it
			if (D_80128C20.MiniGunAmmo == 0)
				noammo = TRUE ;
			func_800831E4(D_800ED6F8) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_1, 0, NULL, &vPos, 0);
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_MINIGUN, REFILL_MINIGUN) ;

			if (		(noammo)
					&& (D_80128C20.MiniGunFlag)
					&& (MINIGUN > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_MINIGUN, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_AMMO_GRENADES:
		case AI_OBJECT_PICKUP_AMMO_GRENADEBOX:
			// if you have an empty grende launcher, and its more powerful than current, use it
			if (D_80128C20.GrenadeLauncherAmmo == 0)
				noammo = TRUE ;
			if (D_8001D398(&pPickup->ah.ih) == AI_OBJECT_PICKUP_AMMO_GRENADES)
			{
				func_800831E4(D_800ED708) ;
				func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_5, 0, NULL, &vPos, 0);
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_GRENADE_LAUNCHER, REFILL_GRENADE) ;
			}
			else
			{
				func_800831E4(D_800ED714) ;
				func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_5, 0, NULL, &vPos, 0);
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_GRENADE_LAUNCHER, REFILL_GRENADE_BOX) ;
			}
			if (		(noammo)
					&& (D_80128C20.GrenadeLauncherFlag)
					&& (GRENADE > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_GRENADE_LAUNCHER, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;

		case AI_OBJECT_PICKUP_AMMO_TECHSMALL:
		case AI_OBJECT_PICKUP_AMMO_TECHLARGE:
			// if you have an pulse rifle, or alien gun, and its more powerful than current, use it
			if (D_80128C20.EnergyPool == 0)
				noammo = TRUE ;
			if (D_8001D398(&pPickup->ah.ih) == AI_OBJECT_PICKUP_AMMO_TECHSMALL)
			{
				func_800831E4(D_800ED724) ;
				func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_3, 0, NULL, &vPos, 0);
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_TECHWEAPON1, REFILL_TECH_SMALL) ;
			}
			else
			{
				func_800831E4(D_800ED730) ;
				func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_3, 0, NULL, &vPos , 0);
				func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_TECHWEAPON1, REFILL_TECH_LARGE) ;
			}
			if (noammo)
			{
				if (		(D_80128C20.TechWeapon1Flag)
						&& (INFANTRY > CurrentWeapon)
						&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
						&& (duckFlag == PLAYER_NOT_DUCKING) )
				{
					func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_TECHWEAPON1, FALSE) ;
					D_8005ED68(&D_80128C20) ;
				}
				else if (		(D_80128C20.MachineGunFlag)
								&& (PULSERIFLE > CurrentWeapon)
								&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
								&& (duckFlag == PLAYER_NOT_DUCKING) )
				{
					func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_MACHINEGUN, FALSE) ;
					D_8005ED68(&D_80128C20) ;
				}
			}
			break ;

		case AI_OBJECT_PICKUP_AMMO_ROCKETS:
			// if you have an empty rocket launcher, and its more powerful than current, use it
			if (D_80128C20.RocketAmmo == 0)
				noammo = TRUE ;
			func_800831E4(D_800ED744) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_7, 0, NULL, &vPos, 0);
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_ROCKET, REFILL_ROCKET) ;

			if (		(noammo)
					&& (D_80128C20.RocketFlag)
					&& (ROCKET > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_ROCKET, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;


		case AI_OBJECT_PICKUP_AMMO_TECHWEAPON2:
			// if you have an empty fusion cannon, and its more powerful than current, use it
			if (D_80128C20.TechWeapon2Ammo == 0)
				noammo = TRUE ;
			func_800831E4(D_800ED750) ;
			func_80031974(&GetApp()->m_Scene, SOUND_GENERIC_3, 0, NULL, &vPos, 0);
			func_80057B58(&D_80128C20, AI_OBJECT_WEAPON_TECHWEAPON2, REFILL_TECH2) ;

			if (		(noammo)
					&& (D_80128C20.TechWeapon2Flag)
					&& (FUSION > CurrentWeapon)
					&& (D_80128C20.WaterFlag != PLAYER_BELOW_WATERSURFACE)
					&& (duckFlag == PLAYER_NOT_DUCKING) )
			{
				func_80058D60(&D_80128C20, AI_OBJECT_WEAPON_TECHWEAPON2, FALSE) ;
				D_8005ED68(&D_80128C20) ;
			}
			break ;
	}


	if (AI_GetEA(pPickup)->m_dwTypeFlags & AI_TYPE_USEPRESSUREPLATES)
	{
		pInst = &pPickup->ah.ih ;
		D_80070DA8(pInst, pInst, AI_MEVENT_PRESSUREPLATE, pInst->m_pEA->m_dwSpecies, vPos, ((CGameObjectInstance *)pPickup)->ah.ih.m_pEA->m_Id);
	}

	pPickup->m_wFlags |= SIMPLE_FLAG_GONE;

	if (pPickup->m_wFlags & SIMPLE_FLAG_DYNAMIC)
	{
		// dynamic, delete it
		D_800365C8((CDynamicSimple*) pPickup) ;
	}
	else
	{
		// instance, keep the state when terrain is reloaded
		D_80034950(&GetApp()->m_Scene, pPickup, TRUE) ;
	}



	D_80003EC8(GetApp(), 200, 200/4, 50, 50, 255) ;
}

