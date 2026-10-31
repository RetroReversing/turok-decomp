#include "source_CParticle__Draw.h"
#line 1 "func.c"
extern char D_800F17E4[];
#line 1 "reference.c"
void CParticle__Draw(CParticle *pThis, Gfx **ppDLP, CCartCache *pCache)
{
	CTextureInfo			textureInfo;
	BOOL						intersectWithGround;
	float						farClip, distance, advanceAmount;
	int						cFrame,
								alpha,
								multU, multV;

	BOOL	crossfade;
	float cAnimFrame,
			fraction;
	int	cUseFrame[2], nUseFrames, i;
	int	*pUseFrame ;
	BYTE	alphaValues[2];
	DWORD	dlistRemain;


	dlistRemain = GLIST_LEN - (((DWORD)*ppDLP) - ((DWORD)CEngineApp__GetFrameData(GetApp())->m_pDisplayList))/sizeof(Gfx);
	if (dlistRemain < DISPLAY_LIST_RESERVE_FRONTEND)
		return;

	if (pThis->m_cFrame < 0)
		return;

	if (!func_80026CFC(&pThis->m_TextureLoader, pCache, D_800F17E4))
		return;

	func_80026AD0(&pThis->m_TextureLoader, &textureInfo);

	if ((pThis->m_dwFlags & PARTICLE_HASHITGROUND) && (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_HOLDANIMONBOUNCE))
	{
		crossfade = FALSE;
		nUseFrames = 0;
		cUseFrame[0] = pThis->m_cAnimFrame;
	}
	else
	{
		//if (pThis->m_pEffect->m_FpsVelThreshold)
		//	rmonPrintf("fps:%f\n", Fps);

		//cAnimFrame = pThis->m_cFrame*pThis->m_FPS*(1.0/FRAME_FPS);
		cAnimFrame = pThis->m_cFramePos;
		cUseFrame[0] = (int) cAnimFrame;

		advanceAmount = D_800B6B00*pThis->m_FPS*(1.0/FRAME_FPS)*D_800B6B08;
		crossfade =		((pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_CROSSFADE) || D_80128C20.SpiritualTime)
						&& ((advanceAmount + 0.01) < D_800B6B00);
		if (crossfade)
		{
			nUseFrames = 2;
			cUseFrame[1] = cUseFrame[0] + 1;
			fraction = cAnimFrame - cUseFrame[0];
		}
		else
	 	{
			nUseFrames = 1;
		}
	}

	cFrame = (int) pThis->m_cFrame;

	for (i=0; i<nUseFrames; i++)
	{
		pUseFrame = &cUseFrame[i] ;

		switch (pThis->m_pEffect->m_Playback)
		{
			case PARTICLE_PLAYBACK_RUNONCE:
				if (*pUseFrame >= (textureInfo.m_nBitmaps - 1))
				{
					*pUseFrame = textureInfo.m_nBitmaps - 1;
					pThis->m_cFrame = cFrame = pThis->m_nFrames;
					crossfade = FALSE;
				}
				break;

			case PARTICLE_PLAYBACK_RUNANDHOLD:
				if (*pUseFrame >= textureInfo.m_nBitmaps)
				{
					*pUseFrame = textureInfo.m_nBitmaps - 1;
					crossfade = FALSE;
				}
				break;

			case PARTICLE_PLAYBACK_LOOP:
				*pUseFrame %= textureInfo.m_nBitmaps;
				break;

			case PARTICLE_PLAYBACK_PINGPONG:
				*pUseFrame %= max(1, (textureInfo.m_nBitmaps*2 - 2));
				if (*pUseFrame >= textureInfo.m_nBitmaps)
					*pUseFrame = (textureInfo.m_nBitmaps*2 - 2) - *pUseFrame;
				break;

			case PARTICLE_PLAYBACK_RANDOM:
				*pUseFrame = RANDOM(textureInfo.m_nBitmaps);
				crossfade = FALSE;
				break;

			case PARTICLE_PLAYBACK_RANDOMANDHOLD:
				if (pThis->m_nRandomFrame == -1)
					pThis->m_nRandomFrame = RANDOM(textureInfo.m_nBitmaps);
				*pUseFrame = pThis->m_nRandomFrame;
				crossfade = FALSE;
				break;

			default:
				ASSERT(FALSE);
		}
	}
	pThis->m_cAnimFrame = cUseFrame[0];

	if (crossfade)
		if (cUseFrame[0] == cUseFrame[1])
			crossfade = FALSE;

	func_80026EC4(pThis, &distance, &intersectWithGround);

	multU = (1 << ( ((pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_MIRRORWIDTH)  ? 9 : 8) + textureInfo.m_pFormat->m_WidthShift) );
	multV = (1 << ( ((pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_MIRRORHEIGHT) ? 9 : 8) + textureInfo.m_pFormat->m_HeightShift) );

	D_80025B10(&pThis->m_TextureLoader, ppDLP,
										 cUseFrame[0], 0,
										 multU, multV,
										 G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR,
										 G_TX_NOLOD);

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_QUACKMODE)
	{
		D_80023FF8(ppDLP, G_CC_ROB_QUACK_PRIM__G_CC_ROB_QUACK_PRIM);
	}
	else
	{
		switch (textureInfo.m_pFormat->m_Format)
		{
			case TEXTURE_FORMAT_CI4_IA:
				D_80023FF8(ppDLP, G_CC_ROB_PSEUDOCOLOR_PRIMALPHA__G_CC_ROB_PSEUDOCOLOR_PRIMALPHA);
				break;

			case TEXTURE_FORMAT_CI4_RGBA:
			case TEXTURE_FORMAT_CI8_RGBA:
				D_80023FF8(ppDLP, G_CC_ROB_DECALRGBA_PRIMALPHA__G_CC_ROB_DECALRGBA_PRIMALPHA);
				break;

			default:
				ASSERT(FALSE);
				break;
		}
	}

 	if (intersectWithGround)
	{
		D_800239C0(ppDLP, G_RM_ZB_XLU_DECAL__G_RM_ZB_XLU_DECAL2);

		gSPTextureL((*ppDLP)++,
						multU, multV,
						0,
						255,	// z compare range
						0, G_ON);
	}
	else if ((pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_INTERSECTION) && (pThis->m_pEffect->m_Alignment != PARTICLE_ALIGN_AUTO))
	{
		//if (cloud_sparkle)
		//{
		//	gDPSetAlphaCompare((*ppDLP)++, G_AC_NONE);
		//	cloud_sparkle = FALSE ;
		//}
		D_800239C0(ppDLP, G_RM_ZB_XLU_DECAL__G_RM_ZB_XLU_DECAL2);
	}
	else
	{
		if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_SPARKLE)
		{
			// cloud sparkle
			//cloud_sparkle = TRUE ;
			D_800239C0(ppDLP, RM_ROB_ZB_PCL_SURF_BLEND1__RM_ROB_ZB_PCL_SURF_BLEND2);
		}
		else
		{
			if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_ZBUFFER)
			{
				//if (cloud_sparkle)
				//{
				//	gDPSetAlphaCompare((*ppDLP)++, G_AC_NONE);
				//	cloud_sparkle = FALSE ;
				//}

				if (GetApp()->m_dwCheatFlags & CHEATFLAG_PENANDINKMODE)
					D_800239C0(ppDLP, G_RM_AA_ZB_TEX_EDGE__G_RM_AA_ZB_TEX_EDGE2);

				else
					D_800239C0(ppDLP, G_RM_ZB_CLD_SURF__G_RM_ZB_CLD_SURF2);
			}
			else
			{
				//if (cloud_sparkle)
				//{
				// 	gDPSetAlphaCompare((*ppDLP)++, G_AC_NONE);
				//	cloud_sparkle = FALSE ;
				//}

				if (GetApp()->m_dwCheatFlags & CHEATFLAG_PENANDINKMODE)
					D_800239C0(ppDLP, G_RM_AA_TEX_EDGE__G_RM_AA_TEX_EDGE2);

				else
					D_800239C0(ppDLP, G_RM_CLD_SURF__G_RM_CLD_SURF2);
			}
		}
	}

	// add distance to alpha value
	if ((pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_FADEOUT) && (pThis->m_nFrames > 0))
		alpha = (pThis->m_nFrames - cFrame)*255/pThis->m_nFrames;
	else
		alpha = 255;

	if (cFrame < pThis->m_pEffect->m_nFadeInDelay)
		alpha = (alpha*(cFrame + 1))/(pThis->m_pEffect->m_nFadeInDelay + 1);

	if (max(0, (pThis->m_nFrames - cFrame)) < pThis->m_pEffect->m_nFadeOutDelay)
		alpha = max(0, (alpha*(pThis->m_nFrames - cFrame)))/(pThis->m_pEffect->m_nFadeOutDelay + 1);

	farClip = GetApp()->m_FarClip;

	switch (pThis->m_pEffect->m_Visibility)
	{
		case PARTICLE_VISIBLE_ALWAYS:
			alpha = alpha*min(1, (farClip - distance)*10/farClip);
			break;

		case PARTICLE_VISIBLE_CLOSE:
			alpha = alpha*min(1, (farClip - distance)*5/farClip);
			break;

		case PARTICLE_VISIBLE_FAR:
			alpha = alpha*(farClip/2 - fabs(farClip/2 - distance))/(farClip/2);
			break;
	}

	if (textureInfo.m_pFormat->m_Format == TEXTURE_FORMAT_CI4_IA)
	{
		gDPSetEnvColor((*ppDLP)++,
							 pThis->m_BlackColor[0],
							 pThis->m_BlackColor[1],
							 pThis->m_BlackColor[2],
							 255);
	}

	if (crossfade)
	{
/*
		totalSprite = alpha/255.0;


		fTemp = totalSprite*fraction;
		denom = 1 - fTemp;
		if (denom == 0)
		{
			if (fraction == 0)
				alphaValues[0] = 255;
			else
				alphaValues[0] = 0;
		}
		else
		{
			alphaValues[0] = max(0, min(255, 255*(totalSprite - fTemp)/denom));
		}

		alphaValues[1] = max(0, min(255, 255*fTemp));
*/
		//alphaValues[0] = max(0, min(255, 255*cos(fraction*(ANGLE_PI/2))));
		//alphaValues[1] = max(0, min(255, 255*cos((1-fraction)*(ANGLE_PI/2))));

		alphaValues[0] = max(0, min(255, alpha*(1-fraction)));
		alphaValues[1] = max(0, min(255, alpha*fraction));
	}
	else
	{
		alphaValues[0] = max(0, min(255, alpha));
		nUseFrames = 1;
	}

  	gSPMatrix((*ppDLP)++,
				 RSP_ADDRESS(&CParticle__GetOrientationMatrix(pThis)),
	   		 G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

	gSPVertex((*ppDLP)++,
				 RSP_ADDRESS(D_80119F70),
				 4, 0);

	for (i=0; i<nUseFrames; i++)
	{
		if (i)
		{
			D_80025B10(&pThis->m_TextureLoader, ppDLP,
												 cUseFrame[i], 0,
												 multU, multV,
												 G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR,
												 G_TX_NOLOD);

			if (intersectWithGround)
			{
				gSPTextureL((*ppDLP)++,
								multU, multV,
								0,
								255,	// z compare range
								0, G_ON);
			}
		}

		gDPSetPrimColor((*ppDLP)++,
							 256, 256,				// LOD stuff
							 pThis->m_WhiteColor[0],
							 pThis->m_WhiteColor[1],
							 pThis->m_WhiteColor[2],
							 (alphaValues[i]*pThis->m_AlphaScaler) >> 8);

		gSP2Triangles((*ppDLP)++,
						  0, 1, 2, 0,
						  2, 3, 0, 0);
	}

	// add swoosh edge if a swoosh is active
	if (pThis->m_ActiveSwooshes)
		func_800425F8(&GetApp()->m_FxSystem, pThis, &CParticle__GetOrientationMatrix(pThis)) ;

/*
	CMtxF__VectorMult4x4(GetApp()->m_mfProjection, &pThis->ah.ih.m_vPos, &vProj);


	vProj.x = (vProj.x * (SCREEN_WD/2)) + (SCREEN_WD/2);
	vProj.y = (vProj.y * -(SCREEN_HT/2)) + (SCREEN_HT/2);


	gDPPipeSync((*ppDLP)++);

	gDPSetRenderMode((*ppDLP)++,
							G_RM_CLD_SURF,
							G_RM_CLD_SURF2);

	gDPSetCombineMode((*ppDLP)++,
							G_CC_PRIMITIVE,
							G_CC_PRIMITIVE);

	gDPSetPrimColor((*ppDLP)++,
						 256, 256,				// LOD stuff
						 255, 0, 0,
						 128);

	gDPScisFillRectangle((*ppDLP)++,
								(int) vProj.x, (int) vProj.y,
								(int) (vProj.x + 10), (int) (vProj.y + 10));


	CGeometry__ResetDrawModes();
*/
}

