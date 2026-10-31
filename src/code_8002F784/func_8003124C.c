#include "common_local_source_4151.h"

#line 2 "reference.c"
void func_8003124C(CScene *pThis, Gfx **ppDLP, CUnindexedSet *pusInstances)
{
	int 						nInstances;
	CGameObjectInstance	*instances, *pSelf;
	int						sx, sy, ex, ey;


	CSun__ReadZDepth(&sun, ppDLP);

	if (!CCamera__InCinemaMode(&GetApp()->m_Camera))
	{
		func_80081A10(ppDLP, 100);
		COnScreen__DrawSunLensFlare(&GetApp()->m_OnScreen, ppDLP);

		if (!(GetApp()->m_dwCheatFlags & CHEATFLAG_QUACKMODE))
			gDPSetTextureFilter((*ppDLP)++, G_TF_BILERP);

		gDPSetTexturePersp((*ppDLP)++, G_TP_PERSP);
		D_80023824();
	}

	// Don't draw player during intro
// CARL
//	if (GetApp()->m_Mode == MODE_INTRO || GetApp()->m_Mode == MODE_GALLERY)
//	{
//		gDPPipeSync((*ppDLP)++);
//
//#ifdef USE_FOG
//		gDPSetCycleType((*ppDLP)++, G_CYC_2CYCLE);
//#else		// !USE_FOG
//		gDPSetCycleType((*ppDLP)++, G_CYC_1CYCLE);
//#endif
//		return ;
//	}


	ASSERT(pThis->m_pceTextureSetsIndex);

	// Only clear z buffer if not in cinema mode
	if (CCamera__InCinemaMode(&GetApp()->m_Camera))
	{
		gDPPipeSync((*ppDLP)++);

#ifdef USE_FOG
		gDPSetCycleType((*ppDLP)++, G_CYC_2CYCLE);
#else		// !USE_FOG
		gDPSetCycleType((*ppDLP)++, G_CYC_1CYCLE);
#endif
	}
	else
	{
		if (CTMove__ClearWeaponZBuffer(&CTurokMovement))
		{
			switch (CTurokMovement.WeaponCurrent)
			{
				case AI_OBJECT_WEAPON_KNIFE:
					sx = 0;
					sy = SCREEN_HT*2/5;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_TOMAHAWK:
					sx = 0;
					sy = SCREEN_HT*2/5;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_TEKBOW:
					sx = 80;
					sy = SCREEN_HT*3/5;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL:
					sx = 180;
					sy = 155;
					ex = SCREEN_WD-30;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_ASSAULTRIFLE:
					sx = 110;
					sy = 135;
					ex = SCREEN_WD-20;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_MACHINEGUN:
					sx = 170;
					sy = 90;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_RIOTSHOTGUN:
					sx = 50;
					sy = 80;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_AUTOMATICSHOTGUN:
					sx = 190;
					sy = 150;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_MINIGUN:
					sx = 140;
					sy = 145;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_GRENADE_LAUNCHER:
					sx = 220;
					sy = 110;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_TECHWEAPON1:
					sx = 110;
					sy = 170;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_ROCKET:
					sx = 194;
					sy = 135;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_SHOCKWAVE:
					sx = 157;
					sy = 150;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_TECHWEAPON2:
					sx = 150;
					sy = 135;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				case AI_OBJECT_WEAPON_CHRONOSCEPTER:
					sx = 120;
					sy = 0;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;

				// fills 2/5 of the screen
				default:
					sx = 0;
					sy = SCREEN_HT*2/5;
					ex = SCREEN_WD-1;
					ey = SCREEN_HT-1;
					break;
			}

			// clear the z buffer to the correct dimensions
			func_8000221C(GetApp(), sx, ex, sy, ey);
		}
	}

#ifdef USE_FOG
	gSPSetGeometryMode((*ppDLP)++, G_FOG);
#endif

   nInstances = CUnindexedSet__GetBlockCount(pusInstances);
   instances = (CGameObjectInstance*) CUnindexedSet__GetBasePtr(pusInstances);

	if (nInstances)
	{
		pSelf = &instances[0];

		if (CScene__BetterSelfClipping(pThis, pSelf))
		{
			gSPClipRatio((*ppDLP)++, FRUSTRATIO_1);
		}
		else
		{
			// performance tuned
			gSPClipRatio((*ppDLP)++, FRUSTRATIO_2);
		}

		if (pSelf->m_pceObjectInfo)
		{
			func_8001C9D8(pSelf, ppDLP,
											  pThis->m_pceTextureSetsIndex);
		}
	}
}
