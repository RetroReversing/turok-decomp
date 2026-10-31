#include "common_local_source_5383.h"

#line 1 "reference.c"
void func_8007D5F4(COnScreen *pThis, Gfx **ppDLP)
{
	INT16				nRunWalkMode;
	INT32				Offset ;
	C16BitGraphic	*Grid ;
	int				xoff, yoff ;
	u32				time ;
	static float 	oxygen,
						health = 0.0;

#ifndef SHIP_IT
//	char			floatbuff[32] ;

	int				i;
	float				slowest, value;
	char				*string;

	CGameObjectInstance *pTurok = CEngineApp__GetPlayer(GetApp());

	if (!pTurok)
		return;
#endif



	//--------------------------------------------------------------------------------------
	// display enemy modify stuff
/*
	if ((GetApp()->m_dwCheatFlags & CHEATFLAG_MODIFYENEMY) && (CTurokMovement.pModifyEnemy))
	{
		COnScreen__InitFontDraw(ppDLP) ;

		sprintf(floatbuff, "x %.2f", AI_GetDyn(CTurokMovement.pModifyEnemy)->m_vLeashCoor.x / SCALING_FACTOR) ;
		COnScreen__DrawText(ppDLP, floatbuff, 64, 20, 255, FALSE, TRUE);
		sprintf(floatbuff, "z %.2f", AI_GetDyn(CTurokMovement.pModifyEnemy)->m_vLeashCoor.z / SCALING_FACTOR) ;
		COnScreen__DrawText(ppDLP, floatbuff, 64, 20+16, 255, FALSE, TRUE);
		sprintf(floatbuff, "yrot %.2f", ANGLE_RTOD(CTurokMovement.pModifyEnemy->m_RotY)) ;
		COnScreen__DrawText(ppDLP, floatbuff, 64, 20+32, 255, FALSE, TRUE);
	}
*/



	// Prepare for drawing texture graphics
	func_80081A10(ppDLP, GetApp()->m_Options.m_Opacity) ;


	if (GetApp()->m_Options.m_Opacity)
	{

		//--------------------------------------------------------------------------------------
		// Display ammo info
		if ((pThis->m_SelectPosition != (u8) -1) && COverlay__OnScreen(&pThis->m_AmmoOverlay))
		{
			// Calculate 1/2 of pixel width
			if (pThis->m_ExplosiveAmmo)
			{
				Grid = (C16BitGraphic *)(D_800BF0DC[pThis->m_SelectPosition].Icon) ;
				xoff = D_800BF0DC[pThis->m_SelectPosition].XOff ;
				yoff = D_800BF0DC[pThis->m_SelectPosition].YOff ;
			}
			else
			{
				Grid = (C16BitGraphic *)(D_800BF028[pThis->m_SelectPosition].Icon) ;
				xoff = D_800BF028[pThis->m_SelectPosition].XOff ;

				yoff = D_800BF028[pThis->m_SelectPosition].YOff ;
			}

			if (Grid)
			{
				Offset = 32 ;

				// Draw ammo overlay
				func_80082E64(ppDLP,
													Grid,
													pThis->m_AmmoOverlay.m_X-Offset+xoff,
													pThis->m_AmmoOverlay.m_Y-8+yoff) ;

				// display rock piece for numbers
				func_80082E64(ppDLP,
													(C16BitGraphic *)D_800CDE90,
													pThis->m_AmmoOverlay.m_X-Offset+18,
													pThis->m_AmmoOverlay.m_Y-8) ;


					// Display ammo numbers
				func_800803D0(ppDLP,
											 pThis->m_Ammo,
											 (int)pThis->m_AmmoOverlay.m_X-12,
											 (int)pThis->m_AmmoOverlay.m_Y-4);
			}
		}

		//--------------------------------------------------------------------------------------
		// Display health info
		if (pThis->m_HealthArmourIcon == ONSCRN_HEALTH_ICON)
			Grid = (C16BitGraphic *)D_800C2ED8 ;
		else
			Grid = (C16BitGraphic *)D_800C35C8 ;
		Offset = 30 ;

		// Draw health overlay
		func_80082E64(ppDLP,
											Grid,
											pThis->m_HealthOverlay.m_X-Offset,
											pThis->m_HealthOverlay.m_Y-8) ;
		// draw rock
		func_80082E64(ppDLP,
											(C16BitGraphic *)D_800CDE90,
											pThis->m_HealthOverlay.m_X-Offset+21,
											pThis->m_HealthOverlay.m_Y-8) ;

		// Display numbers - do we need to flash them ?
		#define	ONSCRN_FLASH_TIMER_HEALTH		0.3
		#define	ONSCRN_FLASH_TIMER_ARMOUR		0.3

		if (pThis->m_HealthArmourIcon == ONSCRN_HEALTH_ICON)
		{
			if ((pThis->m_Health <= LOWHEALTH_ALERT) && (pThis->m_HealthAlert))
			{
				//osSyncPrintf("health:%d\n", pThis->m_Health) ;
				func_800831E4(D_800BF010) ;
				pThis->m_HealthAlert = FALSE ;
			}

			// flash health if <=10
			if (pThis->m_Health > 10)
			{
				pThis->m_FlashDraw = -1;
				pThis->m_FlashTimer = 0.0;
			}
			else
			{
				pThis->m_FlashTimer += D_800B6B00*(1.0/FRAME_FPS);
				if (pThis->m_FlashTimer >= ONSCRN_FLASH_TIMER_HEALTH)
				{
					pThis->m_FlashTimer -= ONSCRN_FLASH_TIMER_HEALTH;
					pThis->m_FlashDraw = ~pThis->m_FlashDraw;
				}
			}
			if (pThis->m_FlashDraw)
				func_800803D0(ppDLP,
											 pThis->m_Health,
											 (int)pThis->m_HealthOverlay.m_X-6,
											 (int)pThis->m_HealthOverlay.m_Y-4) ;

		}
		else
		{
			if ((pThis->m_Armor <= LOWARMOR_ALERT) && (pThis->m_ArmorAlert))
			{
				func_800831E4(D_800BF01C) ;
				pThis->m_ArmorAlert = FALSE ;
			}

			//flash armor if <=5
			if (pThis->m_Armor > 5)
			{
				pThis->m_FlashDraw = -1;
				pThis->m_FlashTimer = 0.0;
			}
			else
			{
				pThis->m_FlashTimer += D_800B6B00*(1.0/FRAME_FPS);
				if (pThis->m_FlashTimer >= ONSCRN_FLASH_TIMER_ARMOUR)
				{
					pThis->m_FlashTimer -= ONSCRN_FLASH_TIMER_ARMOUR;
					pThis->m_FlashDraw = ~pThis->m_FlashDraw;
				}
			}
			if (pThis->m_FlashDraw)
				func_800803D0(ppDLP,
											 pThis->m_Armor,
											 (int)pThis->m_HealthOverlay.m_X-6,
											 (int)pThis->m_HealthOverlay.m_Y-4) ;

		}

		//--------------------------------------------------------------------------------------
		// display tokens info
		if (COverlay__OnScreen(&pThis->m_TokensOverlay))
		{
			xoff = pThis->m_TokensOverlay.m_X ;
			yoff = pThis->m_TokensOverlay.m_Y ;

			// draw icon overlay
			func_80082E64(ppDLP,
												(C16BitGraphic *)D_800C49F0,
												xoff,
												yoff);

			// display numbers
			Offset = (pThis->m_Tokens<10) ? -8 : -8-(ONSCRN_ALIGNEDWIDTH+ONSCRN_NUMERAL_SPACER);
			func_800803D0(ppDLP,
										 pThis->m_Tokens,
										 xoff + Offset,
										 yoff + 8);
		}

		//--------------------------------------------------------------------------------------
		// display lives info
		if (COverlay__OnScreen(&pThis->m_LivesOverlay))
		{
			xoff = pThis->m_LivesOverlay.m_X ;
			yoff = pThis->m_LivesOverlay.m_Y ;

			// draw icon overlay
			func_80082E64(ppDLP,
												(C16BitGraphic *)D_800C3C68,
												xoff,
												yoff) ;

			// display numbers
			func_800803D0(ppDLP,
										 pThis->m_Lives,
										 xoff+30,
										 yoff+32) ;
		}

//#ifdef DISPLAY_FRAMERATE
#ifndef SHIP_IT
	if (GetApp()->m_bDebug)
	{
		// increase time, if not finished
		if (GetApp()->m_bPause == FALSE)
			GetApp()->m_LevelTime += D_800B6B00 ;

		COnScreen__InitFontDraw(ppDLP) ;
		func_80080B0C(ppDLP) ;

		COnScreen__SetFontColor(ppDLP, 255, 55, 255, 255, 255, 255) ;
		COnScreen__DrawText(ppDLP, "time", 80, 22, 255, TRUE, TRUE) ;

		COnScreen__SetFontScale(1.0, 2.0) ;
		time = GetApp()->m_LevelTime / FRAME_FPS ;
		i = 192+(63 * cos((float)D_800B6AF8/3)) ;
		COnScreen__SetFontColor(ppDLP, i, i, i, i, i, i) ;
		sprintf(textbuffer, "%02d:%02d", time/60, time%60) ;
		COnScreen__DrawText(ppDLP, textbuffer, 80, 32, 255, TRUE, TRUE) ;

		func_80081A10(ppDLP, GetApp()->m_Options.m_Opacity) ;

//		if (!(GetApp()->m_dwCheatFlags & CHEATFLAG_MODIFYENEMY))
		{
			//--------------------------------------------------------------------------------------
			func_800803D0(ppDLP,
										 GetApp()->m_Scene.m_nActiveAnimInstances - 1,
										 60,
										 POSITION_YPOS + 40 + (0*16));

			ASSERT(D_800B6B00) ;
			func_800803D0(ppDLP,
										 (int) (FRAME_FPS/D_800B6B00),
										 60,
										 POSITION_YPOS + 40 + (1*16));

			func_800803D0(ppDLP,
										 (int) rsp_graphics_time,
										 60,
										 POSITION_YPOS + 50 + (2*16));

			func_800803D0(ppDLP,
										 (int) (rsp_audio_time*FRAME_INC_TO_REFRESHES(D_800B6B00)),
										 60,
										 POSITION_YPOS + 50 + (3*16));

			func_800803D0(ppDLP,
										 (int) rsp_total_time,
										 60,
										 POSITION_YPOS + 60 + (4*16));

			func_800803D0(ppDLP,
										 (int) rdp_time,
										 60,
										 POSITION_YPOS + 60 + (5*16));

			func_800803D0(ppDLP,
										 (int) cpu_time,
										 60,
										 POSITION_YPOS + 60 + (6*16));

			COnScreen__InitFontDraw(ppDLP) ;
			func_80080940(ppDLP);
			COnScreen__SetFontScale(0.8, 0.7) ;
			COnScreen__SetFontColor(ppDLP,
											255, 255, 255,
											255, 255, 255) ;

			COnScreen__DrawText(ppDLP, "ais", 25, POSITION_YPOS + 40 + (0*16), 255, FALSE, FALSE);
			COnScreen__DrawText(ppDLP, "fps", 25, POSITION_YPOS + 40 + (1*16), 255, FALSE, FALSE);

			COnScreen__DrawText(ppDLP, "spg", 25, POSITION_YPOS + 50 + (2*16), 255, FALSE, FALSE);
			COnScreen__DrawText(ppDLP, "spa", 25, POSITION_YPOS + 50 + (3*16), 255, FALSE, FALSE);

			slowest = max(rsp_total_time, max(rdp_time, cpu_time));
			for (i=0; i<3; i++)
			{
				switch (i)
				{
					case 0:
						string = "rsp";
						value = rsp_total_time;
						break;
					case 1:
						string = "rdp";
						value = rdp_time;
						break;
					case 2:
						string = "cpu";
						value = cpu_time;
						break;
				}

				if (value == slowest)
				{
					COnScreen__SetFontColor(ppDLP,
													255, 128, 128,
													255, 0, 0) ;
				}

				COnScreen__DrawText(ppDLP, string, 25, POSITION_YPOS + 60 + (4*16) + i*16, 255, FALSE, FALSE);

				if (value == slowest)
				{
					COnScreen__SetFontColor(ppDLP,
													255, 255, 255,
													255, 255, 255) ;
				}
			}

			func_80081A10(ppDLP, GetApp()->m_Options.m_Opacity) ;
		}
	}
#endif



//#ifdef DISPLAY_COORDINATES
#ifndef SHIP_IT
	if (GetApp()->m_bDebug)
	{
		//--------------------------------------------------------------------------------------
		// display world position
		func_800803D0(ppDLP,
									 (int)(pTurok->ah.ih.m_vPos.x/SCALING_FACTOR),
									 POSITION_XPOS,
									 POSITION_YPOS);
		func_800803D0(ppDLP,
									 (int)(pTurok->ah.ih.m_vPos.y/SCALING_FACTOR),
									 POSITION_XPOS,
									 POSITION_YPOS+16);
		func_800803D0(ppDLP,
									 (int)(pTurok->ah.ih.m_vPos.z/SCALING_FACTOR),
									 POSITION_XPOS,
									 POSITION_YPOS+32);
	}
#endif

		//--------------------------------------------------------------------------------------
		// Draw compass graphics
//		COnScreen__DrawCompassGraphic(ppDLP,
//											(C16BitGraphic *)NESWOverlay,
//											COMPASS_XPOS,
//											COMPASS_YPOS) ;


		//--------------------------------------------------------------------------------------
		// Display run / walk icon
		if (COverlay__OnScreen(&pThis->m_RunWalkOverlay))
		{
			if (pThis->m_WalkRunIcon==ONSCRN_WALK_ICON)
				nRunWalkMode = 0;
			else
				nRunWalkMode = 1;

			func_80082E64(ppDLP,
												(C16BitGraphic *)D_800BF2FC[nRunWalkMode],
												pThis->m_RunWalkOverlay.m_X,
												pThis->m_RunWalkOverlay.m_Y) ;
		}

	}

	//--------------------------------------------------------------------------------------
	// Draw weapon selection
	func_8007F024(pThis, ppDLP) ;


	//--------------------------------------------------------------------------------------
	// display bossbar last coz it changes opacity
	if (pThis->m_BossBarMode)
	{
		// Make boss bar vanish?
		if ((pThis->m_pBoss) && (pThis->m_pBoss->m_PercentageHealth <= 0))
		{
			pThis->m_pBoss = NULL ;
			func_8007F3C0(pThis, BOSSBARMODE_FADEOUT) ;
		}

		health = 0 ;	// Default
		switch(pThis->m_BossBarMode)
		{
			// fade up
			case BOSSBARMODE_FADEON:
				if (pThis->m_pBoss)
					health = ((float)(pThis->m_pBoss->m_PercentageHealth)) / 100.0 ;

				pThis->m_BossBarOpacity += GetApp()->m_Options.m_Opacity / BOSSBAR_TIMEIN ;
				if (pThis->m_BossBarOpacity >= GetApp()->m_Options.m_Opacity)
				{
					pThis->m_BossBarOpacity = GetApp()->m_Options.m_Opacity ;
					pThis->m_BossBarMode = BOSSBARMODE_WAIT ;
				}
				break ;

			case BOSSBARMODE_FADEOUT:
				pThis->m_BossBarOpacity -= GetApp()->m_Options.m_Opacity / BOSSBAR_TIMEOUT ;
				if (pThis->m_BossBarOpacity <= 0)
				{
					pThis->m_BossBarOpacity = 0 ;
					pThis->m_BossBarMode = BOSSBARMODE_NULL ;
				}
				break ;

			default:
				if (pThis->m_pBoss)
					health = ((float)(pThis->m_pBoss->m_PercentageHealth)) / 100.0;
				break ;
		}

		func_80081A10(ppDLP, pThis->m_BossBarOpacity) ;
		func_80082E64(ppDLP,
											(C16BitGraphic *)D_800C7958,
											BOSS_XPOS, BOSS_YPOS) ;
		func_8008000C(ppDLP,
											BOSS_XPOS+11, BOSS_YPOS+15,
											health, pThis->m_BossBarOpacity) ;
	}


	//--------------------------------------------------------------------------------------
	// display airbar last coz it changes opacity
	if (pThis->m_AirMode)
	{
		switch(pThis->m_AirMode)
		{
			// fade up
			case AIRMODE_FADEON:
				oxygen = func_8005CAB0(&D_80128C20) ;
				pThis->m_AirOpacity += GetApp()->m_Options.m_Opacity / AIR_TIMEIN ;
				if (pThis->m_AirOpacity >= GetApp()->m_Options.m_Opacity)
				{
					pThis->m_AirOpacity = GetApp()->m_Options.m_Opacity ;
					pThis->m_AirMode = AIRMODE_WAIT ;
				}
				break ;
			case AIRMODE_FADEOUT:
				pThis->m_AirOpacity -= GetApp()->m_Options.m_Opacity / AIR_TIMEOUT ;
				if (pThis->m_AirOpacity <= 0)
				{
					pThis->m_AirOpacity = 0 ;
					pThis->m_AirMode = AIRMODE_NULL ;
				}
				break ;
			default:
				oxygen = func_8005CAB0(&D_80128C20) ;
				break ;
		}
		func_80081A10(ppDLP, pThis->m_AirOpacity) ;
		func_80082E64(ppDLP,
											(C16BitGraphic *)D_800C5130,
											AIR_XPOS, AIR_YPOS) ;
		func_8008000C(ppDLP,
											AIR_XPOS+11, AIR_YPOS+15,
											oxygen, pThis->m_AirOpacity) ;
	}


	// draw all lens flares for all particles
	func_8007DFE4(pThis, ppDLP);

	// draw lens flare for sun
	//COnScreen__DrawSunLensFlare(pThis, ppDLP);


	//--------------------------------------------------------------------------------------
}
