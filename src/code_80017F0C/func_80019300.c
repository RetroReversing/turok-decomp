#include "common_local_source_3919.h"
#line 1 "func.c"
extern unsigned char D_8011A0CC[];
#line 1 "reference.c"
void func_80019300(CGameObjectInstance *pThis, Gfx **ppDLP)
{
	CVector3					vPos;
	static Lights1			glareLight;
	float						mag;
	BYTE						bMag;
	CMtxF						mfRotate;
	CQuatern					qRot;


	if (!CGameObjectInstance__IsDevice(pThis))
		D_800B6B00 *= D_800B6B04;

#ifndef KANJI
	if (		(GetApp()->m_Mode == MODE_GAME)
			&&	(GetApp()->m_dwCheatFlags & CHEATFLAG_DISCO)
			&& pThis->m_AI.m_Health )
	{
		if ((D_800B6AF0 % 250) > 150)
			D_800B6B00 *= 2.0;
	}
#endif

	// Boss function?
	if ((pThis->m_pBoss) && (pThis->m_pBoss->m_pPreDrawFunction))
	{
		pThis->m_pBoss->m_pPreDrawFunction(pThis, pThis->m_pBoss, ppDLP);
	}
	// melting ?
	else if (pThis->m_cMelt > 0)
	{
		D_800B9878 = FXMODE_TOTRANSPARENT;
		D_800B987C[3] = max(0, min(255, 255 - (int) (pThis->m_cMelt*(255/MELT_LENGTH))));
	}
	// is character frozen ?
	else if (pThis->m_AI.m_FreezeTimer != 0.0)
	{
#define	DARKNESS_FORBLACK		204.0
#define	DARKNESS_FORYELLOW	204.0

		// which color change ?
		D_800B9878 = FXMODE_TOCOLOR;
		if (pThis->m_AI.m_FreezeTimer > 0.0)
		{
			if (pThis->m_AI.m_FreezeTimer >= AI_FREEZE_FADETOBLACK)
			{
				// pulse yellow
				mag = (AI_FREEZE_START - pThis->m_AI.m_FreezeTimer) * 180.0 / (AI_FREEZE_START - AI_FREEZE_FADETOBLACK);
				bMag = (BYTE) (__sinf(ANGLE_DTOR(mag)) * DARKNESS_FORYELLOW);
				D_800B987C[0] = 255;
				D_800B987C[1] = 255;
				D_800B987C[2] = 0;
				D_800B987C[3] = bMag;
			}
			else
			{
				// fade to black
				if (pThis->m_AI.m_FreezeTimer >= AI_FREEZE_FADETOBLACKEND)
					mag = (AI_FREEZE_FADETOBLACK - pThis->m_AI.m_FreezeTimer) * DARKNESS_FORBLACK / (AI_FREEZE_FADETOBLACK - AI_FREEZE_FADETOBLACKEND);
				else
					mag = DARKNESS_FORBLACK;

				bMag = (BYTE) mag;
				D_800B987C[0] = 0;
				D_800B987C[1] = 0;
				D_800B987C[2] = 0;
				D_800B987C[3] = bMag;
			}

			// reduce time
			pThis->m_AI.m_FreezeTimer -= D_800B6B00*(1.0/FRAME_FPS);
			if (pThis->m_AI.m_FreezeTimer <= 0.0)
				pThis->m_AI.m_FreezeTimer = AI_FREEZE_END;
		}
		else
		{
			D_800B987C[0] = 0;
			D_800B987C[1] = 0;
			D_800B987C[2] = 0;
			D_800B987C[3] = (BYTE) DARKNESS_FORBLACK;
		}

		// freeze the enemy
		D_800B6B00 = 0.0;
	}
	// regeneration appearance ?
	else if (pThis->m_AI.m_cRegenerateAppearance)
	{
//		fx_mode = FXMODE_TOTRANSPARENT;
//		fx_color[3] = max(0, min(255, 255 - (int) (pThis->m_AI.m_cRegenerateAppearance*(255/APPEARANCE_LENGTH))));

		D_800B9878 = FXMODE_TOCOLORANDTRANSPARENT;
		D_800B987C[0] = 240;		// env r
		D_800B987C[1] = 240;		// env g
		D_800B987C[2] = 240;		// env b
		D_800B987C[3] = 255;
		D_800B987C[4] = max(0, min(255, 255 - (int) (pThis->m_AI.m_cRegenerateAppearance*(255/APPEARANCE_LENGTH))));
	}
	else if (pThis->m_AI.m_cRegenerateAppearanceWhite)
	{
		D_800B9878 = FXMODE_TOCOLOR;
		D_800B987C[0] = 240;
		D_800B987C[1] = 240;
		D_800B987C[2] = 240;
		D_800B987C[3] = 255 - max(0, min(255, 255 - (int) (pThis->m_AI.m_cRegenerateAppearanceWhite*(255/APPEARANCEWHITE_LENGTH))));
	}
	// any glaring particles ?
	else if (		(D_8011A0D0)
					&&	(CEngineApp__GetPlayer(GetApp()) == pThis) )
	{
		qRot = GetApp()->m_qViewAlign;
		CQuatern__Negate(&qRot);
		func_80014DC4(&qRot, mfRotate);
		func_800144C8(&vPos, &D_8011A0C0, &pThis->ah.ih.m_vPos);
		func_80015754(mfRotate, &vPos, &vPos);
		mag = CVector3__Magnitude(&vPos);

		if (mag != 0)
			func_80013C2C(&vPos, &vPos, 60.0/mag);

		bMag = 255 - (BYTE) min(255, mag*(255.0/(30.0*SCALING_FACTOR)));

		glareLight.a.l.col [0] = 0;
		glareLight.a.l.col [1] = 0;
		glareLight.a.l.col [2] = 0;
		glareLight.a.l.colc[0] = 0;
		glareLight.a.l.colc[1] = 0;
		glareLight.a.l.colc[2] = 0;

		glareLight.l[0].l.col [0] = bMag;
		glareLight.l[0].l.col [1] = bMag;
		glareLight.l[0].l.col [2] = bMag;
		glareLight.l[0].l.colc[0] = bMag;
		glareLight.l[0].l.colc[1] = bMag;
		glareLight.l[0].l.colc[2] = bMag;

		glareLight.l[0].l.dir [0] = (signed char) vPos.x;
		glareLight.l[0].l.dir [1] = (signed char) vPos.y;
		glareLight.l[0].l.dir [2] = (signed char) vPos.z;

		//gDPPipeSync((*ppDLP)++);
		gSPSetLights1((*ppDLP)++, glareLight);

		D_800B9878 = FXMODE_GLARE;

		D_800B987C[0] = D_8011A0CC[0];
		D_800B987C[1] = D_8011A0CC[1];
		D_800B987C[2] = D_8011A0CC[2];
	}
	else
	{
/*		if (	  (GetApp()->m_Mode == MODE_GAME)
			  && (GetApp()->m_dwCheatFlags & CHEATFLAG_MODIFYENEMY) )
		{
			if (pThis == CTurokMovement.pModifyEnemy)
			{
				fx_mode = FXMODE_TOCOLOR;
				fx_color[0] = 255 ;
				fx_color[1] = 0 ;
				fx_color[2] = 255 ;
				fx_color[3] = (frame_number%64 <32) ? frame_number%64 : 64-(frame_number%64) ;
				fx_color[3] *= 3 ;

			}
		}
*/		switch (CGameObjectInstance__TypeFlag(pThis))
		{
			case AI_OBJECT_DEVICE_PORTAL:
				D_800B9878 = FXMODE_TOTRANSPARENT;
				D_800B987C[3] = 255 * pThis->m_AI.m_Time1 ;
				//fx_color[3] = (BYTE) max(0, min(255, fabs(((frame_number%60) - 30.0)) * 255.0/30.0));
				break ;
		}
	}

	// NOTE: This mode may not work properly with untextured objects
	//fx_mode = FXMODE_TOCOLORANDTRANSPARENT;
	//fx_color[0] = 255;	// env r
	//fx_color[1] = 0;	// env g
	//fx_color[2] = 0;	// env b
	//fx_color[3] = 0;	// env a		0: 0% color, 255: 100% color
	//fx_color[4] = 128;	// prim a	0: transparent, 255: opaque

	//fx_mode = FXMODE_TOTRANSPARENT;
	//fx_color[3] = 128;	// env a		0: transparent, 255: opaque

	// NOTE: This mode is the only mode besides FXMODE_NONE that uses the z-buffer
	//fx_mode = FXMODE_TOCOLOR;
	//fx_color[0] = 255;	// env r
	//fx_color[1] = 0;	// env g
	//fx_color[2] = 0;	// env b
	//fx_color[3] = 0;	// env a		0: 0% color, 255: 100% color

	//fx_mode = FXMODE_FROMCOLOR_TOTRANSPARENT
	//fx_color[0] = 255;	// env r
	//fx_color[1] = 0;	// env g
	//fx_color[2] = 0;	// env b
	//fx_color[3] = 128;	// env a		0: transparent, 255: opaque
}

