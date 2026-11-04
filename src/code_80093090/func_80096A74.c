#include "decompdecomp_sync_0b3ff25e3e5964593623.h"
#line 1 "func.c"
#line 403 "reference.c"
void func_80096A74(Gfx **ppDLP)
{
              

	CGameRegion			*regions, *pRegion;
	int					cRegion,
							nBlocks,
							cBlock,
							cCorner,
							cEdge, cNextEdge;
	CIndexedSet			isCollision;
	CUnindexedSet		usRegions,
							usBlocks;
	void					*pbRegions,
							*pbBlocks;
	int					cVertex,
							nRemainingVertices,
							nLoad,
							i;
	DWORD					clip[3], *pClip;
	CVector3				*pvCorner, *pvCorner2;
	Vtx					*vtxs ;
	CMtxF					mfMap, mfInvMap, mfNorth;
	static Mtx			mMap[2], mIdent[2];
	float					scaleX, scaleY;//, yrot;
	CROMRegionBlock	*blocks, *pBlock;
	CBoundsRect			clipRect;
	CEngineApp			*pApp;
	CGameObjectInstance	*pInstance, *pPlayer ;
	int					nInsts ;
	CVector3				vCorners[4], vTCorners[4];

	float					cx, cz ;
	float					opacity ;
	float					sinTheta, cosTheta;
	BOOL					addvertex, drawedge, drawWholeMap, showenemy;
	int					cConnection ;
	int					diff, col, opac ;

	CUnindexedSet			usRegionAttributes;
	CROMRegionSet			*regionSets, *pRegionSet;
	void						*pbRegionAttributes;

	pApp = GetApp();

	if (!D_800B6B38)
		return;

	if (!pApp->m_Scene.m_pceCollision)
		return;

	vtxs = D_80130D80[D_800B6AF4];

	// get the centre position
	cx = pApp->m_XPos ;
	cz = pApp->m_ZPos ;

	// rotate the fucker so movements on x and z will be not dependant on the direction you're facing
	sinTheta = sin(pApp->m_RotY);
	cosTheta = cos(pApp->m_RotY);
	cx += (D_80128C20.MapOffsetZ * sinTheta) - (D_80128C20.MapOffsetX * cosTheta) ;
	cz += (D_80128C20.MapOffsetZ * cosTheta) + (D_80128C20.MapOffsetX * sinTheta) ;

	scaleX = 0.1;
	scaleY = 0.1;

	// Translate around player, and scale it
	cx = max(-32000, min(32000, cx));
	cz = max(-32000, min(32000, cz));
	D_80015578(mfMap, -cx, -cz, 0);

	D_80012F8C(mfMap, scaleX, scaleY, 1);
	func_80012918(mfMap, pApp->m_RotY + ANGLE_DTOR(180));

	// translate to center of screen
	D_8001315C(mfMap, SCREEN_WD/2, SCREEN_HT/2, 0);

	func_80014FAC(mfInvMap, mfMap);

     
	vCorners[0].x = 0;			vCorners[0].y = 0;			vCorners[0].z = 0;
	vCorners[1].x = SCREEN_WD;	vCorners[1].y = 0;			vCorners[1].z = 0;
	vCorners[2].x = SCREEN_WD;	vCorners[2].y = SCREEN_HT;	vCorners[2].z = 0;
	vCorners[3].x = 0;			vCorners[3].y = SCREEN_HT;	vCorners[3].z = 0;
     
                                                                                 
                                                                                       
                                                                                                 
                                                                                          
      

	for (i=0; i<4; i++)
		func_80015754(mfInvMap, &vCorners[i], &vTCorners[i]);

	clipRect.m_MinX = clipRect.m_MaxX = vTCorners[0].x;
	clipRect.m_MinZ = clipRect.m_MaxZ = vTCorners[0].y;
	for (i=1; i<4; i++)
	{
		clipRect.m_MinX = min(clipRect.m_MinX, vTCorners[i].x);
		clipRect.m_MinZ = min(clipRect.m_MinZ, vTCorners[i].y);

		clipRect.m_MaxX = max(clipRect.m_MaxX, vTCorners[i].x);
		clipRect.m_MaxZ = max(clipRect.m_MaxZ, vTCorners[i].y);
	}

	CMtxF__ToMtx(mfMap, mMap[D_800B6AF4]);
	gSPMatrix((*ppDLP)++, RSP_ADDRESS(&mMap[D_800B6AF4]),
	   		 G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);


	// use CCacheEntry__GetDataPtr() if accessing cache in higher priority thread
	D_8002DD28(&isCollision,
												 D_8002D690(pApp->m_Scene.m_pceCollision),
												 FALSE);


	pbRegions = CIndexedSet__GetBlock(&isCollision, CART_COLLISION_usRegions);
	D_8002DA8C(&usRegions, pbRegions, FALSE);

	regions = (CGameRegion*) CUnindexedSet__GetBasePtr(&usRegions);

	pbBlocks =  CIndexedSet__GetBlock(&isCollision, CART_COLLISION_usBlockBounds);
	D_8002DA8C(&usBlocks, pbBlocks, FALSE);

	blocks = (CROMRegionBlock*) CUnindexedSet__GetBasePtr(&usBlocks);
	nBlocks = CUnindexedSet__GetBlockCount(&usBlocks);


	pbRegionAttributes = CIndexedSet__GetBlock(&isCollision, CART_COLLISION_usRegionAttributes);

	D_8002DA8C(&usRegionAttributes, pbRegionAttributes, FALSE);
	regionSets = (CROMRegionSet*) CUnindexedSet__GetBasePtr(&usRegionAttributes);


	cVertex = 0;
	cConnection = 0 ;
	//rmonPrintf("nBlocks:%d, nRegions:%d\n", nBlocks, CUnindexedSet__GetBlockCount(&usRegions));

	drawWholeMap = !(pApp->m_Scene.m_LevelInfo.m_bFlags & LEVEL_STORE_MAP);

	if (GetApp()->m_dwCheatFlags & CHEATFLAG_ALLMAP)
		drawWholeMap = TRUE ;

	// search through blocks
	cRegion = 0;
	for (cBlock=0; cBlock<nBlocks; cBlock++)
	{
		pBlock = &blocks[cBlock];

		if (CBoundsRect__IsOverlapping(&pBlock->m_BoundsRect, &clipRect))
		{
			for (i=0; i<pBlock->m_nRegions; i++)
			{
				// get a pointer to current region
				pRegion = &regions[cRegion];

				pRegionSet = &regionSets[pRegion->m_nRegionSet];
				if ((pRegionSet->m_dwFlags & REGFLAG_DONTDRAWONMAP) == 0)
				{
					// check if entire triangle is clipped
					for (cCorner=0; cCorner<3; cCorner++)
					{
						pvCorner = &pRegion->m_pCorners[cCorner]->m_vCorner;
						pClip = &clip[cCorner];

						if (pvCorner->x < clipRect.m_MinX)
							*pClip = CLIP_LEFT;
						else if (pvCorner->x >= clipRect.m_MaxX)
							*pClip = CLIP_RIGHT;
						else
							*pClip = 0;

						if (pvCorner->z < clipRect.m_MinZ)
							*pClip |= CLIP_BOTTOM;
						else if (pvCorner->z >= clipRect.m_MaxZ)
							*pClip |= CLIP_TOP;
					}

 					// if not completly clipped
					if (!(clip[0] & clip[1] & clip[2]))
					{
     
     
                                           
                                                                      
                                                   
     
                                                           
                                                       
       
                                      
        
                                                          
                                         
                                         
                                
                            
         
                                                     
                                                                   
                
         
        
       
      
      
						if (drawWholeMap || (pRegion->m_wFlags & REGFLAG_REGIONENTERED))
						{
							// check each edge
							for (cEdge=0; cEdge<3; cEdge++)
							{
								drawedge = FALSE ;
								// if this edge has no neighbor, or is different from its neighbor
								if (!pRegion->m_pNeighbors[cEdge])
									drawedge = TRUE ;
								else if (pRegion->m_nRegionSet < pRegion->m_pNeighbors[cEdge]->m_nRegionSet)
									drawedge = TRUE ;

								//else if (pRegion->m_pNeighbors[cEdge]->m_wFlags & REGFLAG_CLIFF)
								//	drawedge = TRUE ;


								if (drawedge)
								{
									cNextEdge = (cEdge == 2) ? 0 : (cEdge + 1);

									// if edge is not completely clipped
									if (!(clip[cEdge] & clip[cNextEdge]))
									{
										pvCorner = &pRegion->m_pCorners[cEdge]->m_vCorner;
										pvCorner2 = &pRegion->m_pCorners[cNextEdge]->m_vCorner;


										// exact clip
										if (func_80096904(vTCorners, pvCorner, pvCorner2))
										{

											//---------------------------------- point 1
											//ASSERT(fabs(pvCorner->x) < 32767);
											//ASSERT(fabs(pvCorner->z) < 32767);

											addvertex = TRUE ;

											// check if connecting to previous vertex
								  			if ((cVertex !=0) &&
								  				 (vtxs[cVertex-1].v.ob[0] == (short)pvCorner->x) &&
								  				 (vtxs[cVertex-1].v.ob[1] == (short)pvCorner->z))
								  			{
								  					addvertex = FALSE ;
								  			}

											if (addvertex)
								  			{
												D_801352E0[cConnection++] = cVertex ;
												vtxs[cVertex].v.ob[0] = (short) pvCorner->x;
												vtxs[cVertex].v.ob[1] = (short) pvCorner->z;

												COLOR_VERTEX ;
												cVertex++;
											}
											else
												D_801352E0[cConnection++] = cVertex-1 ;

											//---------------------------------- point 2
											//ASSERT(fabs(pvCorner2->x) < 32767);
											//ASSERT(fabs(pvCorner2->z) < 32767);
											D_801352E0[cConnection++] = cVertex ;
											vtxs[cVertex].v.ob[0] = (short) pvCorner2->x;
											vtxs[cVertex].v.ob[1] = (short) pvCorner2->z;

											COLOR_VERTEX ;
											cVertex++;

											if (cVertex >= (MAX_MAP_VTXS-1))
												goto map_finished_adding_vertices;
										}
									}
								}
							}
						}
					}
				}

				cRegion++;
			}
		}
		else
		{
			cRegion += pBlock->m_nRegions;
		}
	}
	ASSERT(cRegion == CUnindexedSet__GetBlockCount(&usRegions));

map_finished_adding_vertices:

	opacity = 255 * GetApp()->m_MapAlpha ;

	// draw all the added regions
	nRemainingVertices = cVertex;
	cVertex = 0;
	i = 0 ;
	while (nRemainingVertices > 1)
	{
		nLoad = min(VERTEX_CACHE_SIZE, nRemainingVertices);
		gSPVertex((*ppDLP)++,
      			 RSP_ADDRESS(&vtxs[cVertex]),
      			 nLoad, 0);

//rmonPrintf("loaded %d, from %d\n", nLoad, cVertex) ;

		// go through the lines until trying to draw out of loaded vertices range
		//while ((Connections[i]-cVertex < (nLoad-1)) && (i < (cConnection-1)))
		while ((D_801352E0[i+1]-cVertex < nLoad) && (i < (cConnection-1)))
		{
			ASSERT(D_801352E0[i]-cVertex >=0) ;
			ASSERT(D_801352E0[i]-cVertex < nLoad) ;

//rmonPrintf("connecting %d to %d\n", Connections[i]-cVertex, Connections[i+1]-cVertex) ;
			gSPLine3D((*ppDLP)++,
						 D_801352E0[i]-cVertex, D_801352E0[i+1]-cVertex,
						 0);

 			i += 2 ;
		}

		if (D_801352E0[i+1]-cVertex == nLoad)
		{
			nLoad-- ;
	  	}

		nRemainingVertices -= nLoad;
		cVertex += nLoad;
	}


	// draw the player
	vtxs = D_80134D80[D_800B6AF4];

#define XOFFSET	25
#define YOFFSET	40

	vtxs[0].v.ob[0] = pApp->m_XPos - (YOFFSET * sinTheta);
	vtxs[0].v.ob[1] = pApp->m_ZPos - (YOFFSET * cosTheta);

	vtxs[1].v.ob[0] = pApp->m_XPos + (XOFFSET * cosTheta) + (YOFFSET * sinTheta);
	vtxs[1].v.ob[1] = pApp->m_ZPos - (XOFFSET * sinTheta) + (YOFFSET * cosTheta);

	vtxs[2].v.ob[0] = pApp->m_XPos - (XOFFSET * cosTheta) + (YOFFSET * sinTheta);
	vtxs[2].v.ob[1] = pApp->m_ZPos + (XOFFSET * sinTheta) + (YOFFSET * cosTheta);

	vtxs[0].v.cn[3] = opacity ;
	vtxs[1].v.cn[3] = opacity ;
	vtxs[2].v.cn[3] = opacity ;

	gSPVertex((*ppDLP)++,
     			 RSP_ADDRESS(vtxs),
     			 3, 0);
	gSPLine3D((*ppDLP)++,
				 0, 1,
				 0);
	gSPLine3D((*ppDLP)++,
				 0, 2,
				 0);


	// Retail guards the enemy-map pass with cheat flag bit 28.
	if (GetApp()->m_dwCheatFlags & (1UL << 28))
	{
	// draw animated instances
	vtxs = D_80134DE0[D_800B6AF4];
	cVertex = 0 ;
	nInsts = pApp->m_Scene.m_nActiveAnimInstances;

	pPlayer = CEngineApp__GetPlayer(pApp) ;

	for (i=1; i<nInsts; i++)
	{
		pInstance = GetApp()->m_Scene.m_pActiveAnimInstances[i];

		//rmonPrintf("flag:%d\n", AI_GetEA(pInstance)->m_dwTypeFlags2 & AI_TYPE2_DONTDRAWONMAP) ;

		showenemy = FALSE ;


//		if ((GetApp()->m_dwCheatFlags & CHEATFLAG_SHOWALLENEMIES) &&
//			(!CGameObjectInstance__IsDevice(pInstance)))
//			showenemy = TRUE ;

//		else
		if ((D_8001DE20(&pPlayer->ah, &pInstance->ah.ih)) &&
			(!CGameObjectInstance__IsDevice(pInstance)) &&
			(!(AI_GetEA(pInstance)->m_dwTypeFlags2 & AI_TYPE2_DONTDRAWONMAP)))
			showenemy = TRUE ;

		// don't show interactive animations
		if ((showenemy) && (AI_GetDyn(pInstance)->m_dwStatusFlags & AI_INTERACTIVEANIMATION))
			showenemy = FALSE ;

		// if enemy is dead, don't show it
		if ((showenemy) && (AI_GetDyn(pInstance)->m_Health <=0))
			showenemy = FALSE ;

		if (showenemy)
		{
			sinTheta = sin(pInstance->m_RotY);
			cosTheta = cos(pInstance->m_RotY);
			
			vtxs[(cVertex*3)+0].v.ob[0] = pInstance->ah.ih.m_vPos.x - (YOFFSET * sinTheta);
			vtxs[(cVertex*3)+0].v.ob[1] = pInstance->ah.ih.m_vPos.z - (YOFFSET * cosTheta);

			vtxs[(cVertex*3)+1].v.ob[0] = pInstance->ah.ih.m_vPos.x + (XOFFSET * cosTheta) + (YOFFSET * sinTheta);
			vtxs[(cVertex*3)+1].v.ob[1] = pInstance->ah.ih.m_vPos.z - (XOFFSET * sinTheta) + (YOFFSET * cosTheta);

			vtxs[(cVertex*3)+2].v.ob[0] = pInstance->ah.ih.m_vPos.x - (XOFFSET * cosTheta) + (YOFFSET * sinTheta);
			vtxs[(cVertex*3)+2].v.ob[1] = pInstance->ah.ih.m_vPos.z + (XOFFSET * sinTheta) + (YOFFSET * cosTheta);


			opacity = 255 ;
			diff = ((pInstance->ah.ih.m_vPos.y-pApp->m_YPos)/SCALING_FACTOR) *4 ;
			if (diff > 50)
			{
				opacity -= (diff-50) ;
				if (opacity < 75)
					opacity = 75 ;
			}
			else if (diff < -50)
			{
				opacity -= (50-diff) ;
				if (opacity < 75)
					opacity = 75 ;
			}
			vtxs[(cVertex*3)+0].v.cn[3] = opacity * GetApp()->m_MapAlpha ;
			vtxs[(cVertex*3)+1].v.cn[3] = opacity * GetApp()->m_MapAlpha ;
			vtxs[(cVertex*3)+2].v.cn[3] = opacity * GetApp()->m_MapAlpha ;

			gSPVertex((*ppDLP)++,
		   			 RSP_ADDRESS(&vtxs[cVertex*3]),
		   			 3, 0);
			gSPLine3D((*ppDLP)++,
						 0, 1,
						 0);
			gSPLine3D((*ppDLP)++,
						 0, 2,
						 0);

			cVertex++ ;
			if (cVertex == MAX_VISIBLE_ENEMIES)
				break ;
		}
	}

	}
	// draw a compass
#define	CW		15
#define	CH		15
	vtxs = D_801351A0[D_800B6AF4];

	D_8001551C(mfNorth, .5, .5, 1);
	D_8001315C(mfNorth, SCREEN_WD/2, 32, 0);

	CMtxF__ToMtx(mfNorth, mIdent[D_800B6AF4]);
	gSPMatrix((*ppDLP)++, RSP_ADDRESS(&mIdent[D_800B6AF4]),
	   		 G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);


	// arrow head
	vtxs[0].v.ob[0] = CW*sin(pApp->m_RotY) ;
	vtxs[0].v.ob[1] = -CH*cos(pApp->m_RotY) ;
	vtxs[1].v.ob[0] = vtxs[0].v.ob[0] - (40 * sin(-pApp->m_RotY)) ;
	vtxs[1].v.ob[1] = vtxs[0].v.ob[1] - (40 * cos(-pApp->m_RotY)) ;
	vtxs[2].v.ob[0] = vtxs[1].v.ob[0] + (15 * sin(-pApp->m_RotY-.4));
	vtxs[2].v.ob[1] = vtxs[1].v.ob[1] + (15 * cos(-pApp->m_RotY-.4));
	vtxs[3].v.ob[0] = vtxs[1].v.ob[0] + (15 * sin(-pApp->m_RotY+.4));
	vtxs[3].v.ob[1] = vtxs[1].v.ob[1] + (15 * cos(-pApp->m_RotY+.4));

	// N
	vtxs[4].v.ob[0] = -CW/2 ;
	vtxs[4].v.ob[1] = -CH/2 ;
	vtxs[5].v.ob[0] = vtxs[4].v.ob[0] ;
	vtxs[5].v.ob[1] = vtxs[4].v.ob[1] +CH;
	vtxs[6].v.ob[0] = vtxs[5].v.ob[0] +CW; 
	vtxs[6].v.ob[1] = vtxs[5].v.ob[1] -CH;
	vtxs[7].v.ob[0] = vtxs[6].v.ob[0] ;
	vtxs[7].v.ob[1] = vtxs[6].v.ob[1] +CH;

	vtxs[0].v.cn[3] = opacity ;
	vtxs[1].v.cn[3] = opacity ;
	vtxs[2].v.cn[3] = opacity ;
	vtxs[3].v.cn[3] = opacity ;
	vtxs[4].v.cn[3] = opacity ;
	vtxs[5].v.cn[3] = opacity ;
	vtxs[6].v.cn[3] = opacity ;
	vtxs[7].v.cn[3] = opacity ;

	gSPVertex((*ppDLP)++,
     			 RSP_ADDRESS(vtxs),
     			 8, 0);
	gSPLine3D((*ppDLP)++,
				 0, 1,
				 0);
	gSPLine3D((*ppDLP)++,
				 1, 2,
				 0);
	gSPLine3D((*ppDLP)++,
				 1, 3,
				 0);

	gSPLine3D((*ppDLP)++,
				 4, 5,
				 0);
	gSPLine3D((*ppDLP)++,
				 5, 6,
				 0);
	gSPLine3D((*ppDLP)++,
				 6, 7,
				 0);






	CUnindexedSet__Destruct(&usRegions);
	CUnindexedSet__Destruct(&usBlocks);
	CUnindexedSet__Destruct(&usRegionAttributes);
	CIndexedSet__Destruct(&isCollision);


	D_80005DD8(GetApp());
	D_80005388(GetApp());
	D_800042D4(GetApp()) ;

      
}

