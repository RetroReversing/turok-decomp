#include "decompdecomp_sync_0ecb00b8620aeeeb4f8b.h"
#line 1 "func.c"
#line 3798 "reference.c"
void func_800587B8 ( CTMove *pThis, CVector3 *pvVec )
{
	int						currentWeapon,
								waterFlag;
	CGameObjectInstance	*pPlayer;
	float						x, y, z, u;


	// which mode is weapon in ?
	pvVec->x = 0;
	pvVec->y = 0;
	pvVec->z = 0;

	// TEMP
//	if (		(pThis->WeaponMode == TWEAPONMODE_OFF)
//			||	(pThis->WeaponMode == TWEAPONMODE_STAYOFF) )
//	{
//		pvVec->z = 200*SCALING_FACTOR;
//	}
//	else
//	{
//		pvVec->z = 0;
//	}


	pPlayer = CEngineApp__GetPlayer(GetApp());

	if (CGameObjectInstance__IsModelLoaded(pPlayer))
		currentWeapon = pThis->WeaponCurrent;
	else
		currentWeapon = -1;

	waterFlag = CEngineApp__GetPlayerWaterStatus(GetApp());

	switch (currentWeapon)
	{
		case AI_OBJECT_WEAPON_KNIFE:
			x = 0.5;
			y = 0.78;//0.80;
			z = 0.45;
			break;

		case AI_OBJECT_WEAPON_TOMAHAWK:
			x = 0.5;
			y = 0.78;//0.80;
			z = 0.45;
			break;

		case AI_OBJECT_WEAPON_TEKBOW:
			x = 0.39;
			y = 0.77;//0.79;
			z = 0.44;
			break;

		case AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL:
			x = 0.47;
			y = 0.76;//0.78;
			z = 0.54;
			break;

		case AI_OBJECT_WEAPON_ASSAULTRIFLE:
			x = 0.5;
			y = 0.75;//0.77;
			z = 0.60;
			break;

		case AI_OBJECT_WEAPON_MACHINEGUN:
			x = 0.5;
			y = 0.78;//0.80;
			z = 0.50;
			break;

		case AI_OBJECT_WEAPON_RIOTSHOTGUN:
			x = 0.5;
			y = 0.78;//0.80;
			z = 0.50;
			break;

		case AI_OBJECT_WEAPON_AUTOMATICSHOTGUN:
			x = 0.5;
			y = 0.79;//0.81;
			z = 0.52;
			break;

		case AI_OBJECT_WEAPON_MINIGUN:
			x = 0.48;
			y = 0.79;//0.81;
			z = 0.48;
			break;

		case AI_OBJECT_WEAPON_GRENADE_LAUNCHER:
			x = 0.5;
			y = 0.78;//0.80;
			z = 0.45;
			break;

		case AI_OBJECT_WEAPON_TECHWEAPON1:
			x = 0.5;
			y = 0.78;//0.80;
			z = 0.45;
			break;

		case AI_OBJECT_WEAPON_ROCKET:
			x = 0.5;
			y = 0.78;//0.80;
			z = 0.45;
			break;

		case AI_OBJECT_WEAPON_SHOCKWAVE:
			x = 0.5;
			y = 0.78;//0.80;
			z = 0.45;
			break;

		case AI_OBJECT_WEAPON_TECHWEAPON2:
			x = 0.5;
			y = 0.68;//0.70;
			z = -0.7;
			break;

		case AI_OBJECT_WEAPON_CHRONOSCEPTER:
			x = 0.6;
			y = 0.85;
			z = 0.17;
			break;

		default:
			x = 0.5;
			y = 0.80;
			z = 0.45;
			break;
	}


	// fudge to make off screen anim for all weapons to go off screen while underwater with
	// a large angle of view
	if (!pThis->InAntiGrav)
	{
		switch (currentWeapon)
		{
			default:
				if (waterFlag == PLAYER_BELOW_WATERSURFACE)
				{
					u = pPlayer->m_asCurrent.m_cFrame / pPlayer->m_asCurrent.m_nFrames;
					y -= (u*0.2);
				}
				break;

			case AI_OBJECT_WEAPON_KNIFE:
				break;
		}
	}


	pvVec->x = -x*SCALING_FACTOR/SCALING_PLAYERWEAPON_SCALE;
	pvVec->y = -z*SCALING_FACTOR/SCALING_PLAYERWEAPON_SCALE;
	pvVec->z = y*SCALING_FACTOR/SCALING_PLAYERWEAPON_SCALE;
}

