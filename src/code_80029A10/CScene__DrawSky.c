#include "decompdecomp_sync_7e2364878b7051c9db2e.h"
#line 1 "func.c"
#line 3682 "reference.c"
void CScene__DrawSky(CScene *pThis, Gfx **ppDLP)
{
                   
                                         
     
	static Vtx				fv[2][SKY_LEVELS][5][3];
      
	int						v, l,
								side;
	Vtx						*pVert;
	float						height,
								offsetX, offsetZ,
								divisor, farClip,
								minX, minZ, maxX, maxZ,
								t;
								//clipDist,
								//maxOpac;
	CVector3					sv[3], vv[3], vAB, vBC, vCross, vC[5], vA, vB;//, vDelta;
	CTextureInfo			textureInfo;
	static float			cFrame = 0;
	int						cAnimFrame;
	static float			cScrollX = 0;
	static float			cScrollZ = 0;
	BOOL						underWater, lookingUp;
	CROMRegionSet			*pRegionSet;
	float						waterOffset,
								skyDistance,
								opacValue;
	BYTE						nearColor[4], farColor[4];

	if (!pThis->m_pPlayer)
		return;

	if (!pThis->m_SkyTextureReady || !pThis->m_LevelInfoReceived)
		return;

	if (!D_80026CFC(&pThis->m_SkyTextureLoader, &pThis->m_Cache, "Sky Texture Set"))
		return;

	D_80026AD0(&pThis->m_SkyTextureLoader, &textureInfo);
	if (!textureInfo.m_nBitmaps)
		return;

	pRegionSet = CScene__GetRegionAttributes(pThis, pThis->m_pPlayer->ah.ih.m_pCurrentRegion);
	if (!pRegionSet)
		return;

	// is sky present for this region ?
	if (!(pRegionSet->m_dwFlags & REGFLAG_SKY))
		return;


	cFrame += D_800B6B00;
	if (cFrame >= textureInfo.m_nBitmaps)
		cFrame -= textureInfo.m_nBitmaps;
	cAnimFrame = cFrame/textureInfo.m_pFormat->m_PlaybackSpeed;

	farClip = 200*SCALING_FACTOR;

	//divisor = 2.0*GetApp()->m_FarClip*(SKY_LEVELS+1);
	divisor = 2.0*farClip*(SKY_LEVELS+1);
	cScrollX += (D_800B6B00*D_800B6B0C*SKY_XSPEED)*GetApp()->m_SkySpeed/100.0;
	if (cScrollX > divisor)
		cScrollX -= divisor;

	cScrollZ += (D_800B6B00*D_800B6B0C*SKY_ZSPEED)*GetApp()->m_SkySpeed/100.0;
	if (cScrollZ > divisor)
		cScrollZ -= divisor;

	D_80025B10(&pThis->m_SkyTextureLoader, ppDLP,
										 cAnimFrame % textureInfo.m_nBitmaps, 0,
										 //(1 << (8 + textureInfo.m_pFormat->m_WidthShift)),
										 //(1 << (8 + textureInfo.m_pFormat->m_HeightShift)),
										 (1 << textureInfo.m_pFormat->m_WidthShift) * 384,
										 (1 << textureInfo.m_pFormat->m_HeightShift) * 384,
										 G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
										 //G_TX_NOLOD);
										 15);

  	gSPMatrix((*ppDLP)++,
				 RSP_ADDRESS(&D_800F9E90),
				 G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

	// makes sky look better (due to alpha values interpolation)
	gSPClipRatio((*ppDLP)++, FRUSTRATIO_1);

              
	gSPClearGeometryMode((*ppDLP)++, G_FOG);
   gDPSetCycleType((*ppDLP)++, G_CYC_1CYCLE);
      

                  

                                                                              
     
	D_800239C0(ppDLP, G_RM_ZB_CLD_SURF__G_RM_ZB_CLD_SURF2);
      


	//gDPSetCombineMode((*ppDLP)++,
	//					  	G_CC_MODULATERGB, G_CC_MODULATERGB);


	switch (textureInfo.m_pFormat->m_Format)
	{
		case TEXTURE_FORMAT_CI4_IA:
			D_80023FF8(ppDLP, G_CC_ROB_PSEUDOCOLOR_SHADEALPHA__G_CC_ROB_PSEUDOCOLOR_SHADEALPHA);

			//gDPSetCombineMode((*ppDLP)++, G_CC_BLENDPEDECALA, G_CC_BLENDPEDECALA);
			//gDPSetCombineMode((*ppDLP)++, G_CC_BLENDIA, G_CC_BLENDIA);
			//gDPSetCombineMode((*ppDLP)++, G_CC_MODULATERGBA, G_CC_MODULATERGBA);

// /*
			gDPSetEnvColor((*ppDLP)++,
								 pThis->m_LevelInfo.m_WhiteColor[0],
								 pThis->m_LevelInfo.m_WhiteColor[1],
								 pThis->m_LevelInfo.m_WhiteColor[2],
								 255);
// */
/*
			gDPSetEnvColor((*ppDLP)++,
								 pThis->m_LevelInfo.m_BlackColor[0],
								 pThis->m_LevelInfo.m_BlackColor[1],
								 pThis->m_LevelInfo.m_BlackColor[2],
								 255);

 /*
			nearColor[0] = 255;
			nearColor[1] = 255;
			nearColor[2] = 255;

			farColor[0] = 255;
			farColor[1] = 255;
			farColor[2] = 255;
*/
// /*
			nearColor[0] = pThis->m_LevelInfo.m_BlackColor[0];
			nearColor[1] = pThis->m_LevelInfo.m_BlackColor[1];
			nearColor[2] = pThis->m_LevelInfo.m_BlackColor[2];

			farColor[0] = pThis->m_LevelInfo.m_BlackColor[0];
			farColor[1] = pThis->m_LevelInfo.m_BlackColor[1];
			farColor[2] = pThis->m_LevelInfo.m_BlackColor[2];
			//farColor[0] = 255;
			//farColor[1] = 0;
			//farColor[2] = 0;
// */
			break;

		case TEXTURE_FORMAT_CI4_RGBA:
		case TEXTURE_FORMAT_CI8_RGBA:
			D_80023FF8(ppDLP, G_CC_MODULATERGB__G_CC_MODULATERGB);

			nearColor[0] = 255;
			nearColor[1] = 255;
			nearColor[2] = 255;

			farColor[0] = 255;
			farColor[1] = 255;
			farColor[2] = 255;

			break;

		default:
			ASSERT(FALSE);
			break;
	}












  	gSPClearGeometryMode((*ppDLP)++, G_LIGHTING | G_CULL_BACK | G_TEXTURE_GEN);
  	gSPSetGeometryMode((*ppDLP)++, G_SHADE | G_SHADING_SMOOTH);

	underWater = FALSE;
	if (pRegionSet)
	{
		if (pRegionSet->m_dwFlags & REGFLAG_HASWATER)
		{
			waterOffset = min(2*SCALING_FACTOR, (pRegionSet->m_WaterElevation - (CEngineApp__GetEyePos(GetApp()).y))/2);

			underWater = (CEngineApp__GetEyePos(GetApp()).y < pRegionSet->m_WaterElevation);
		}
	}
	
	// Set sky height, (leave the same in cinema modes)
	if ((!D_80039B98(&GetApp()->m_Camera)) || (!pThis->m_SkyHeightSet))
	{
		pThis->m_SkyHeightSet = TRUE ;

		if (underWater)
			pThis->m_SkyHeight = pRegionSet->m_WaterElevation + ((SKY_LEVELS-1)*SKY_DROP*SCALING_FACTOR) - waterOffset;
		else
			pThis->m_SkyHeight = (TUROK_EYE_HEIGHT + GetApp()->m_SkyElevation)*SCALING_FACTOR + GetApp()->m_YPos*TRACK_HEIGHT_MULT;
	}


	//vC = GetApp()->m_vTCorners;

	lookingUp = (GetApp()->m_vTCorners[1].y + GetApp()->m_vTCorners[2].y + GetApp()->m_vTCorners[3].y + GetApp()->m_vTCorners[4].y)*0.25 > GetApp()->m_vTCorners[0].y;

	//D_800144C8(&vDelta, &GetApp()->m_vTCorners[0], &GetApp()->m_vTCorners[1]);
	//clipDist = CVector3__Magnitude(&vDelta);
	
	for (l=0; l<SKY_LEVELS; l++)
	{
		// copy corners to vC
		for (v=0; v<5; v++)
			vC[v] = GetApp()->m_vTCorners[v];
		
		height = pThis->m_SkyHeight - (l*SKY_DROP*SCALING_FACTOR);

		// don't let sides go thorough far clip

		vA.x = vC[0].x;
		vA.y = height;
		vA.z = vC[0].z;

		for (v=1; v<5; v++)
		//for (v=1; v<2; v++)
		{
			vB.x = vC[v].x;
			vB.y = height;
			vB.z = vC[v].z;

			t = CViewVolume__Intersect(&D_800F9D90, VOLUME_FAR_PLANE, &vA, &vB);
			if ((t >= 0) && (t < 1.01))
			{
				vC[v].x = BlendFLOAT(t, vC[0].x, vC[v].x);
				vC[v].y = height;
				vC[v].z = BlendFLOAT(t, vC[0].z, vC[v].z);
			}
/*			
			if (t > 1)
			{
				divisor = vC[v].y - vC[0].y;
				if (divisor == 0)
					t = 1;
				else
					t = (height - vC[0].y)/divisor;
			}

			if (t >= 0)
			{
				vC[v].x = BlendFLOAT(t, vC[0].x, vC[v].x);
				vC[v].z = BlendFLOAT(t, vC[0].z, vC[v].z);

				vC[v].y = height;
			}
*/
		}


		for (side=0; side<4; side++)
		{
			switch (side)
			{
				case 0:
					vv[0] = sv[0] = vC[0];
					vv[1] = sv[1] = vC[1];
					vv[2] = sv[2] = vC[3];
					break;

				case 1:
					vv[0] = sv[0] = vC[0];
					vv[1] = sv[1] = vC[3];
					vv[2] = sv[2] = vC[4];
					break;

				case 2:
					vv[0] = sv[0] = vC[0];
					vv[1] = sv[1] = vC[4];
					vv[2] = sv[2] = vC[2];
					break;

				case 3:
					vv[0] = sv[0] = vC[0];
					vv[1] = sv[1] = vC[2];
					vv[2] = sv[2] = vC[1];
					break;
			}

			for (v=0; v<3; v++)
			{
				// slow down sky movement
				sv[v].x -= 0.5*vv[0].x;
				sv[v].z -= 0.5*vv[0].z;

				sv[v].x += cScrollX;
				sv[v].z += cScrollZ;
			}

			D_800144C8(&vAB, &vv[1], &vv[0]);
			D_800144C8(&vBC, &vv[2], &vv[1]);
			CVector3__Cross(&vCross, &vAB, &vBC);

			if (lookingUp ^ (vCross.y <= 0))
			{
				maxX = max(sv[0].x, max(sv[1].x, sv[2].x));
				minX = min(sv[0].x, min(sv[1].x, sv[2].x));
				maxZ = max(sv[0].z, max(sv[1].z, sv[2].z));
				minZ = min(sv[0].z, min(sv[1].z, sv[2].z));

				divisor = 2.0*farClip*(l+1);
				if (maxX >= divisor)
					offsetX = ((int) (maxX/divisor)) * -divisor;
				else if (minX <= -divisor)
					offsetX = ((int) (minX/divisor)) * divisor;
				else
					offsetX = 0;

				if (maxZ >= divisor)
					offsetZ = ((int) (maxZ/divisor)) * -divisor;
				else if (minZ <= -divisor)
					offsetZ = ((int) (minZ/divisor)) * divisor;
				else
					offsetZ = 0;

				for (v=0; v<3; v++)
				{
					pVert = &fv[D_800B6AF4][l][side][v];

					pVert->v.ob[0] = (short) vv[v].x;
					pVert->v.ob[1] = (short) height;
					pVert->v.ob[2] = (short) vv[v].z;

					pVert->v.flag = 0;

					pVert->v.tc[0] = (short) ((sv[v].x + offsetX) * (16384.0/((l+1)*farClip)));
					pVert->v.tc[1] = (short) ((sv[v].z + offsetZ) * (16384.0/((l+1)*farClip)));

					if (v)
					{
						pVert->v.cn[0] = farColor[0];
						pVert->v.cn[1] = farColor[1];
						pVert->v.cn[2] = farColor[2];

						pVert->v.cn[3] = 0;

/*
						//pVert->v.cn[3] = maxOpac[v];

						
						D_800144C8(&vDelta, &vv[v], &vv[0]);
						divisor = CVector3__Magnitude(&vDelta);
						//divisor = vv[v].y - vv[0].y;
						//if (divisor == 0)
						//	maxOpac = 0;
						//else
							//maxOpac = max(0, min(1, 1 - fabs(height - vv[0].y)/divisor));
							maxOpac = max(0, min(1, 1 - divisor/clipDist));


						if (l)
							pVert->v.cn[3] = (BYTE) (BOTTOM_OPAC*maxOpac);
						else
							pVert->v.cn[3] = (BYTE) (TOP_OPAC*maxOpac);
*/
					}
					else
					{
						pVert->v.cn[0] = nearColor[0];
						pVert->v.cn[1] = nearColor[1];
						pVert->v.cn[2] = nearColor[2];

#define BOTTOM_OPAC	127
#define TOP_OPAC		200

						if (l)
							opacValue = BOTTOM_OPAC;
						else
							opacValue = TOP_OPAC;

						skyDistance = fabs(vv[0].y - height);

#define SKY_FADE_DISTANCE			(6*SCALING_FACTOR)
#define SKY_FADE_GONE_FRACTION	0.25
						if (skyDistance < SKY_FADE_DISTANCE)
						{
							opacValue = max(0, skyDistance - (SKY_FADE_GONE_FRACTION*SKY_FADE_DISTANCE))
											* opacValue / ((1.0 - SKY_FADE_GONE_FRACTION)*SKY_FADE_DISTANCE);
						}

						pVert->v.cn[3] = (BYTE) opacValue;

					}
				}

   			gSPVertex((*ppDLP)++,
							 RSP_ADDRESS(fv[D_800B6AF4][l][side]),
							 3, 0);

				gSP1Triangle((*ppDLP)++, 0, 1, 2, 0);
			}
		}
	}
}

