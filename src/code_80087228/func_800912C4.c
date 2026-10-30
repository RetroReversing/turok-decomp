#include "common_local_source_5606.h"

#line 354 "reference.c"
BOOL func_800912C4(CTMove *pThis, INT32 PickupType)
{
	CGameObjectInstance	*pPlayer = CEngineApp__GetPlayer(GetApp()) ;

	switch (PickupType)
	{
		case AI_OBJECT_PICKUP_SMALL_TOKEN:
		case AI_OBJECT_PICKUP_LARGE_TOKEN:
			if (	(CTurokMovement.Lives >= TMOVE_MAX_LIVES)
				&& (CTurokMovement.Tokens == 99))
			{
				if (CTurokMovement.CheatGiven == FALSE)
				{
					GetApp()->m_bPause = TRUE;
					CPause__Construct(&GetApp()->m_Pause);
					GetApp()->m_Pause.m_Mode = PAUSE_NORMAL;
					CGiveCheatCode__Construct(&GetApp()->m_GiveCheatCode, LivesCodes) ;
					GetApp()->m_bGiveCheatCode = TRUE ;
				}
				CTurokMovement.CheatGiven = TRUE ;
				return FALSE ;
			}
			break ;

		case AI_OBJECT_PICKUP_HEALTH_2:
		case AI_OBJECT_PICKUP_HEALTH_100PLUS:
			if (pPlayer->m_AI.m_Health >= 250)
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_HEALTH_10:
		case AI_OBJECT_PICKUP_HEALTH_25:
		case AI_OBJECT_PICKUP_HEALTH_100:
			if (pPlayer->m_AI.m_Health >= CTurokMovement.MaxHealth)
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_AMMO_ARROWS:
			if (func_80057DFC(pThis, AI_OBJECT_WEAPON_TEKBOW, FALSE))
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_AMMO_EXPARROWSSMALL:
		case AI_OBJECT_PICKUP_AMMO_EXPARROWSLARGE:
			if (func_80057DFC(pThis, AI_OBJECT_WEAPON_TEKBOW, TRUE))
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_AMMO_BULLETCLIP:
		case AI_OBJECT_PICKUP_AMMO_BULLETBOX:
			if (func_80057DFC(pThis, AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL, FALSE))
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_AMMO_SHOTGUN:
		case AI_OBJECT_PICKUP_AMMO_SHOTGUNBOX:
			if (func_80057DFC(pThis, AI_OBJECT_WEAPON_RIOTSHOTGUN, FALSE))
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_AMMO_EXPSHOTGUN:
		case AI_OBJECT_PICKUP_AMMO_EXPSHOTGUNBOX:
			if (func_80057DFC(pThis, AI_OBJECT_WEAPON_RIOTSHOTGUN, TRUE))
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_AMMO_MINIGUN:
			if (func_80057DFC(pThis, AI_OBJECT_WEAPON_MINIGUN, FALSE))
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_AMMO_GRENADES:
		case AI_OBJECT_PICKUP_AMMO_GRENADEBOX:
			if (func_80057DFC(pThis, AI_OBJECT_WEAPON_GRENADE_LAUNCHER, FALSE))
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_AMMO_TECHSMALL:
		case AI_OBJECT_PICKUP_AMMO_TECHLARGE:
			if (func_80057DFC(pThis, AI_OBJECT_WEAPON_TECHWEAPON1, FALSE))
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_AMMO_ROCKETS:
			if (func_80057DFC(pThis, AI_OBJECT_WEAPON_ROCKET, FALSE))
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_AMMO_TECHWEAPON2:
			if (func_80057DFC(pThis, AI_OBJECT_WEAPON_TECHWEAPON2, FALSE))
				return FALSE ;
			break ;

		case AI_OBJECT_PICKUP_BACKPACK:
			if (CTurokMovement.BackPackFlag)
				return FALSE ;
			break ;
	}

	return TRUE ;
}
