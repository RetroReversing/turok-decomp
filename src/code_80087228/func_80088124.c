#include "decompdecomp_sync_55008710168d9c8faad2.h"
#line 1 "func.c"
#line 411 "reference.c"
INT32 func_80088124(CCheat *pThis)
{
	INT32						ReturnValue = -1;
	CGameObjectInstance	*pPlayer;


	// do gallery instructions
	if (GetApp()->m_GInst.b_Active)
	{
		func_80088F3C(&GetApp()->m_GInst) ;
		ReturnValue = -1 ;
	}
	else
	{


		// Goto next selection?
		if (func_8000658C(GetApp()))
		{
			D_800EC0C0 = 0 ;
			do
			{
				do
				{
					pThis->m_Selection++ ;
					if (pThis->m_Selection >= CHEAT_END_SELECTION)
						pThis->m_Selection = 0 ;

				} while (!D_801293F0[pThis->m_Selection]);

				pThis->m_RealSelection++;
				if (pThis->m_RealSelection >= func_800880CC(pThis))
					pThis->m_RealSelection = 0;

			} while (		(GetApp()->m_Mode == MODE_GAME)
							&& (		(pThis->m_Selection == CHEAT_GALLERY)
									||	(pThis->m_Selection == CHEAT_SHOWCREDITS) ) );
		}

		// Goto previous selection?
		if (func_80006770(GetApp()))
		{
			D_800EC0C0 = 0 ;
			do
			{
				do
				{
					pThis->m_Selection-- ;
					if (pThis->m_Selection < 0)
						pThis->m_Selection = CHEAT_END_SELECTION-1 ;

				} while (!D_801293F0[pThis->m_Selection]);

				pThis->m_RealSelection--;
				if (pThis->m_RealSelection < 0)
					pThis->m_RealSelection = func_800880CC(pThis)-1;

			} while (		(GetApp()->m_Mode == MODE_GAME)
							&& (		(pThis->m_Selection == CHEAT_GALLERY)
									||	(pThis->m_Selection == CHEAT_SHOWCREDITS) ) );
		}


		// Exit if start pressed
		if (func_80051EA4(D_800F9E44))
			ReturnValue = pThis->m_Selection ;

		switch (ReturnValue)
		{
			case CHEAT_INVINCIBILITY:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_INVINCIBILITY;
				break ;

			case	CHEAT_SPIRITMODE:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_SPIRITMODE;
				break ;

			case	CHEAT_ALLWEAPONS:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_ALLWEAPONS;

				if ((GetApp()->m_Mode == MODE_TITLE) && ((GetApp()->m_dwCheatFlags & CHEATFLAG_ALLWEAPONS)==0))
					func_80052484() ;
				break ;

			case	CHEAT_UNLIMITEDAMMO:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_UNLIMITEDAMMO;
				break ;

			case	CHEAT_BIGHEADS:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_BIGHEADS;
				break ;

			case	CHEAT_ALLMAP:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_ALLMAP;
				break ;

			case	CHEAT_SHOWALLENEMIES:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_SHOWALLENEMIES;
				break ;

			case	CHEAT_TINYENEMYMODE:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_TINYENEMYMODE;
//				GetApp()->m_dwCheatFlags &= ~CHEATFLAG_BIGENEMYMODE;
				break ;

//			case	CHEAT_BIGENEMYMODE:
//				ReturnValue = -1 ;
//				GetApp()->m_dwCheatFlags ^= CHEATFLAG_BIGENEMYMODE;
//				GetApp()->m_dwCheatFlags &= ~CHEATFLAG_TINYENEMYMODE;
//				break ;

			case	CHEAT_PENANDINKMODE:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_PENANDINKMODE;
				break ;

			case	CHEAT_PURDYCOLORS:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_PURDYCOLORS;
				break ;

			case	CHEAT_WARPLEVEL1:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = 0;
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

			case	CHEAT_WARPLEVEL2:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = 1000;
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

			case	CHEAT_WARPLEVEL3:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = 2000;
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

			case	CHEAT_WARPLEVEL4:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = 3000;
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

			case	CHEAT_WARPLEVEL5:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = 4000;
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

			case	CHEAT_WARPLEVEL6:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = 5000;
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

			case	CHEAT_WARPLEVEL7:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = 7000;
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

			case	CHEAT_WARPLEVEL8:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = 8000;
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

			case	CHEAT_WARPLONGHUNTER:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = LONGHUNTER_BOSS_START_WARP_ID;
				GetApp()->m_BossFlags &= ~LONGHUNTER_BOSS_FLAGS ;
				GetApp()->m_BossFlags |= BOSS_FLAG_RESET_LEVEL ;
				func_8000B008(GetApp());
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;
			case	CHEAT_WARPMANTIS:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = MANTIS_BOSS_WARP_ID;
				GetApp()->m_BossFlags &= ~MANTIS_BOSS_FLAGS ;
				GetApp()->m_BossFlags |= BOSS_FLAG_RESET_LEVEL ;
				func_8000B008(GetApp());
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;
			case	CHEAT_WARPTREX:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = TREX_BOSS_WARP_ID;
				GetApp()->m_BossFlags &= ~TREX_BOSS_FLAGS ;
				GetApp()->m_BossFlags |= BOSS_FLAG_RESET_LEVEL ;
				func_8000B008(GetApp());
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;
			case	CHEAT_WARPCAMPAIGNER:
				ReturnValue = -1 ;
				func_80009FBC(GetApp()) ;
				GetApp()->m_WarpID = CAMPAIGNER_BOSS_WARP_ID;
				GetApp()->m_BossFlags &= ~CAMPAIGNER_BOSS_FLAGS ;
				GetApp()->m_BossFlags |= BOSS_FLAG_RESET_LEVEL ;
				func_8000B008(GetApp());
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

			case	CHEAT_GALLERY:
				ReturnValue = -1 ;
				pThis->m_Mode = CHEAT_FADEDOWN ;
				func_80088F10(&GetApp()->m_GInst) ;
				GetApp()->m_bGInst = TRUE ;
				break ;

			case	CHEAT_SHOWCREDITS:
				ReturnValue = -1 ;
				pThis->m_Mode = CHEAT_FADEDOWN;
				func_8000B924();
				GetApp()->m_WarpID = CREDITS_WARP_ID;
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

//			case	CHEAT_MODIFYENEMY:
//				ReturnValue = -1 ;
//				GetApp()->m_dwCheatFlags ^= CHEATFLAG_MODIFYENEMY;
//				break ;

			case	CHEAT_ALLKEYS:
				D_80128C20.Level2Keys = 7 ;
				D_80128C20.Level3Keys = 7 ;
				D_80128C20.Level4Keys = 7 ;
				D_80128C20.Level5Keys = 7 ;
				D_80128C20.Level6Keys = 7 ;
				D_80128C20.Level7Keys = 7 ;
				D_80128C20.Level8Keys = 31 ;
				ReturnValue = -1 ;
				GetApp()->m_WarpID = 666;	// Hub warp
				func_80004504(GetApp(), MODE_RESETLEVEL);
				break ;

			case	CHEAT_INFINITELIVES:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_INFINITELIVES ;
				break ;


			case	CHEAT_FLYMODE:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_FLYMODE;

				// exiting fly mode - find nearest region
				if (!(GetApp()->m_dwCheatFlags & CHEATFLAG_FLYMODE))
				{
					pPlayer = CEngineApp__GetPlayer(GetApp());;

					if (pPlayer)
					{
						pPlayer->ah.ih.m_pCurrentRegion = func_8002E280(&GetApp()->m_Scene, &pPlayer->ah.ih.m_vPos);
					}
				}
				break ;

			case	CHEAT_QUACKMODE:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_QUACKMODE;
				break ;

             
			case	CHEAT_DISCO:
				ReturnValue = -1 ;
				GetApp()->m_dwCheatFlags ^= CHEATFLAG_DISCO;

				// Reset lights if turning off
				if (!(GetApp()->m_dwCheatFlags & CHEATFLAG_DISCO))
					func_80033B48(&GetApp()->m_Scene) ;

				break ;
      

			case CHEAT_EXIT:
				pThis->m_Mode = CHEAT_FADEDOWN ;
				break ;
		}
	}

	return ReturnValue ;
}

