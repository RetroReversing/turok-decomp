#include "decompdecomp_sync_f68de04e095aa12b0178.h"
#line 1071 "reference.c"
/* #define BOUNDS_CHECK_THRESHOLD 16 */ void CGeometry__Decompress(CGeometry *pThis, CCacheEntry **ppceTarget)
{
	int				allocSize,
						dispListSize, verticesSize,
						cNode, nNodes,
						cPart, nParts,
						cSection, nSections,
						cVertex, nVertices,
						cVertexLoad, nVertexLoads,
						vertexCount,
						cFacet, nFacets, nFacetLoads, nThisFacetLoad,
						gameSectionSize,
						newSectionSize,
						offset,
						nodesOffset, nodeOffset,
						partsOffset, partOffset,
						sectionOffset;
	void				*pbGeometry,
						*pbGeometryInfo,
						*pbNodes, *pbNode,
						*pbChildNodeIndices,
						*pbPartIndices,
						*pbParts, *pbPart,
						*pbSection, *pbNewSection,
						*pbROMSection,
						*pbPStream,
						*pbVertices,
						*pbNewGeometry,
						*pbNewGeometryInfo,
						*pbNewNodes, *pbNewNode,
						*pbNewChildNodeIndices,
						*pbNewPartIndices,
						*pbNewParts, *pbNewPart,
						*pbDispList;
	CGameSection	*pbNewGameSection;
	CIndexedSet		isGeometry, isNewGeometry,
						isNodes, isNode,
						isParts, isPart,
						isSection, isNewSection,
						isNewPart, isNewParts,
						isNewNodes, isNewNode;
	CUnindexedSet	usVertices,
						usPStream;
	DWORD				childNodeIndicesSize,
						partIndicesSize,
						*pVertexCount;
	BYTE				*pBytes;
	Gfx 				*pDLP;
	Vtx				*vertices, *newVertices, *pVert, *boundsVertices;
	BYTE				*inBytes, *pOutPlace;
	int				cBlock, cSize;
	BOOL				boundsCheck;
	int				dir[3], dot;
	WORD				*facets;
	short				minX, minY, minZ, maxX, maxY, maxZ;
	WORD				poly, nextPoly;
	BOOL				last;
               
                                       
      

	ASSERT(pThis->m_pceGeometry == *ppceTarget);
	ASSERT(BOUNDS_CHECK_THRESHOLD >= 1);

	if (!CCacheEntry__DecompressTemp(*ppceTarget))
		return;

	TRACE0("CGeometry: Starting geometry decompression...\r\n");
               
                           
      

	// calculate allocation size
	allocSize = 0;

	// geometry
	pbGeometry = D_8002D690(pThis->m_pceGeometry);
	D_8002DD28(&isGeometry, pbGeometry, FALSE);
	allocSize += IS_INDEX_SIZE(CART_GEOMETRY_nItems);

	// geometry info
	pbGeometryInfo = CIndexedSet__GetAddress(&isGeometry, CART_GEOMETRY_info);
	allocSize += FixAlignment(sizeof(CGameGeometryInfo), IS_ALIGNMENT);

	// nodes
	pbNodes = CIndexedSet__GetAddress(&isGeometry, CART_GEOMETRY_isNodes);
	D_8002DD28(&isNodes, pbNodes, FALSE);
	nNodes = CIndexedSet__GetBlockCount(&isNodes);
	allocSize += IS_INDEX_SIZE(nNodes);

	for (cNode=0; cNode<nNodes; cNode++)
	{
		// node
		pbNode = CIndexedSet__GetAddress(&isNodes, cNode);
		D_8002DD28(&isNode, pbNode, FALSE);
		allocSize += IS_INDEX_SIZE(CART_NODE_nItems);

		// child node indices
		pbChildNodeIndices = CIndexedSet__GetBlockAndSize(&isNode, CART_NODE_usChildNodeIndices, &childNodeIndicesSize);
		allocSize += childNodeIndicesSize;

		// part indices
		pbPartIndices = CIndexedSet__GetBlockAndSize(&isNode, CART_NODE_usPartIndices, &partIndicesSize);
		allocSize += partIndicesSize;

		// parts
		pbParts = CIndexedSet__GetAddress(&isNode, CART_NODE_isParts);
		D_8002DD28(&isParts, pbParts, FALSE);
		nParts = CIndexedSet__GetBlockCount(&isParts);
		allocSize += IS_INDEX_SIZE(nParts);

		for (cPart=0; cPart<nParts; cPart++)
		{
			// part
			pbPart = CIndexedSet__GetAddress(&isParts, cPart);
			D_8002DD28(&isPart, pbPart, FALSE);
			nSections = CIndexedSet__GetBlockCount(&isPart);
			allocSize += IS_INDEX_SIZE(nSections);

			for (cSection=0; cSection<nSections; cSection++)
			{
				// section
				pbSection = CIndexedSet__GetAddress(&isPart, cSection);
				D_8002DD28(&isSection, pbSection, FALSE);
				allocSize += IS_INDEX_SIZE(2);

				// poly stream
				pbPStream = CIndexedSet__GetAddress(&isSection, CART_SECTION_usPStream);
				D_8002DA8C(&usPStream, pbPStream, FALSE);
				nFacets = CUnindexedSet__GetBlockCount(&usPStream);
				facets = (WORD*) CUnindexedSet__GetBasePtr(&usPStream);

				// vertices
				pbVertices = CIndexedSet__GetAddress(&isSection, CART_SECTION_usVertices);
				D_8002DA8C(&usVertices, pbVertices, FALSE);
				nVertices = CUnindexedSet__GetBlockCount(&usVertices);

				TRACE2("CGeometry: nVertices:%u, nFacets:%u\r\n", nVertices, nFacets);

				// gameSection struct
				gameSectionSize = FixAlignment(sizeof(CGameSection), IS_ALIGNMENT);
				allocSize += gameSectionSize;

				// number of vertex loads required
				if (nVertices == 0)
				{
					nVertexLoads = 0;
				}
				else if (nVertices <= VERTEX_CACHE_SIZE)
				{
					nVertexLoads = 1;
				}
				else
				{
					nVertexLoads = 1 + ((nVertices - VERTEX_CACHE_SIZE) / (VERTEX_CACHE_SIZE/2));

					if ((nVertices - VERTEX_CACHE_SIZE) % (VERTEX_CACHE_SIZE/2))
						nVertexLoads++;
				}

				// number of polygon draw commands required
				nFacetLoads = nThisFacetLoad = 0;
				for (cFacet=0; cFacet<nFacets; cFacet++)
				{
					if (nThisFacetLoad)
					{
						nThisFacetLoad = 0;
						nFacetLoads++;
					}
					else
					{
						if (POLYSTREAM_ISLASTINRUN(facets[cFacet]))
							nFacetLoads++;
						else
							nThisFacetLoad++;
					}
				}

				dispListSize = (nVertexLoads + nFacetLoads + 1)*sizeof(Gfx);
				verticesSize = nVertices*sizeof(Vtx);

				// bounds check
				boundsCheck = (nNodes && (nVertices > BOUNDS_CHECK_THRESHOLD));
				if (boundsCheck)
				{
					dispListSize += 2*sizeof(Gfx);
					verticesSize += 8*sizeof(Vtx);
				}

				newSectionSize = 8 + dispListSize + verticesSize;
				newSectionSize = FixAlignment(newSectionSize, IS_ALIGNMENT);

				allocSize += newSectionSize;

				CIndexedSet__Destruct(&isSection);
				CUnindexedSet__Destruct(&usPStream);
				CUnindexedSet__Destruct(&usVertices);
			}

			CIndexedSet__Destruct(&isPart);
		}

		CIndexedSet__Destruct(&isParts);
		CIndexedSet__Destruct(&isNode);
	}

	// allocate block for decompressed data
	pBytes = CCacheEntry__AllocDataForReplacement(pThis->m_pceGeometry, allocSize);
	if (pBytes)
	{
		// for debugging
		//memset(pBytes, 0xcd, allocSize);

		// isNewGeometry
		pbNewGeometry = pBytes;
		D_8002DD28(&isNewGeometry, pbNewGeometry, FALSE);

		// isNewGeometry index
		offset = IS_INDEX_SIZE(CART_GEOMETRY_nItems);
		CIndexedSet__SetBlockCount(&isNewGeometry, 0);
		CIndexedSet__SetNextOffset(&isNewGeometry, offset);

		// scaler
		pbNewGeometryInfo = pBytes + offset;
		D_8001E648((CGameGeometryInfo*) pbNewGeometryInfo, (CROMGeometryInfo*) pbGeometryInfo);

		offset += FixAlignment(sizeof(CGameGeometryInfo), IS_ALIGNMENT);
		CIndexedSet__SetBlockCount(&isNewGeometry, 1);
		CIndexedSet__SetNextOffset(&isNewGeometry, offset);

		// isNewNodes
		pbNewNodes = pBytes + offset;
		D_8002DD28(&isNewNodes, pbNewNodes, FALSE);

		// isNewNodes index
		nodesOffset = IS_INDEX_SIZE(nNodes);
		CIndexedSet__SetBlockCount(&isNewNodes, 0);
		CIndexedSet__SetNextOffset(&isNewNodes, nodesOffset);

		for (cNode=0; cNode<nNodes; cNode++)
		{
			// isNode
			pbNode = CIndexedSet__GetAddress(&isNodes, cNode);
			D_8002DD28(&isNode, pbNode, FALSE);

			// isNewNode
			pbNewNode = pBytes + offset + nodesOffset;
			D_8002DD28(&isNewNode, pbNewNode, FALSE);

			// isNewNode index
			nodeOffset = IS_INDEX_SIZE(CART_NODE_nItems);
			CIndexedSet__SetBlockCount(&isNewNode, 0);
			CIndexedSet__SetNextOffset(&isNewNode, nodeOffset);

			// usChildNodeIndices
			pbChildNodeIndices = CIndexedSet__GetBlockAndSize(&isNode, CART_NODE_usChildNodeIndices, &childNodeIndicesSize);

			// usNewChildNodeIndices
			pbNewChildNodeIndices = pBytes + offset + nodesOffset + nodeOffset;
			D_8009FA50(pbNewChildNodeIndices, pbChildNodeIndices, childNodeIndicesSize);

			nodeOffset += childNodeIndicesSize;
			CIndexedSet__SetBlockCount(&isNewNode, 1);
			CIndexedSet__SetNextOffset(&isNewNode, nodeOffset);

			// usPartIndices
			pbPartIndices = CIndexedSet__GetBlockAndSize(&isNode, CART_NODE_usPartIndices, &partIndicesSize);

			// usNewChildNodeIndices
			pbNewPartIndices = pBytes + offset + nodesOffset + nodeOffset;
			D_8009FA50(pbNewPartIndices, pbPartIndices, partIndicesSize);

			nodeOffset += partIndicesSize;
			CIndexedSet__SetBlockCount(&isNewNode, 2);
			CIndexedSet__SetNextOffset(&isNewNode, nodeOffset);

			// isParts
			pbParts = CIndexedSet__GetAddress(&isNode, CART_NODE_isParts);
			D_8002DD28(&isParts, pbParts, FALSE);
			nParts = CIndexedSet__GetBlockCount(&isParts);

			// isNewParts
			pbNewParts = pBytes + offset + nodesOffset + nodeOffset;
			D_8002DD28(&isNewParts, pbNewParts, FALSE);

			// isNewParts index
			partsOffset = IS_INDEX_SIZE(nParts);
			CIndexedSet__SetBlockCount(&isNewParts, 0);
			CIndexedSet__SetNextOffset(&isNewParts, partsOffset);

			for (cPart=0; cPart<nParts; cPart++)
			{
				// isPart
				pbPart = CIndexedSet__GetAddress(&isParts, cPart);
				D_8002DD28(&isPart, pbPart, FALSE);
				nSections = CIndexedSet__GetBlockCount(&isPart);

				// isNewPart
				pbNewPart = pBytes + offset + nodesOffset + nodeOffset + partsOffset;
				D_8002DD28(&isNewPart, pbNewPart, FALSE);

				// isNewPart index
				partOffset = IS_INDEX_SIZE(nSections);
				CIndexedSet__SetBlockCount(&isNewPart, 0);
				CIndexedSet__SetNextOffset(&isNewPart, partOffset);

				for (cSection=0; cSection<nSections; cSection++)
				{
					// isSection
					pbSection = CIndexedSet__GetAddress(&isPart, cSection);
					D_8002DD28(&isSection, pbSection, FALSE);

					// isNewSection
					pbNewSection = pBytes + offset + nodesOffset + nodeOffset + partsOffset + partOffset;
					D_8002DD28(&isNewSection, pbNewSection, FALSE);

					// isNewSection index
					sectionOffset = IS_INDEX_SIZE(2);
					CIndexedSet__SetBlockCount(&isNewSection, 0);
					CIndexedSet__SetNextOffset(&isNewSection, sectionOffset);

					// romSection
               pbROMSection = CIndexedSet__GetAddress(&isSection, CART_SECTION_section);

               // newGameSection
               pbNewGameSection = (CGameSection*) (pBytes + offset + nodesOffset + nodeOffset + partsOffset + partOffset + sectionOffset);

               D_8001E550(pbNewGameSection, pbROMSection,
																pThis->m_pceTextureSetsIndex);

					gameSectionSize = FixAlignment(sizeof(CGameSection), IS_ALIGNMENT);
         		sectionOffset += gameSectionSize;
         		CIndexedSet__SetBlockCount(&isNewSection, 1);
         		CIndexedSet__SetNextOffset(&isNewSection, sectionOffset);

					// poly stream
					pbPStream = CIndexedSet__GetAddress(&isSection, CART_SECTION_usPStream);
					D_8002DA8C(&usPStream, pbPStream, FALSE);
					nFacets = CUnindexedSet__GetBlockCount(&usPStream);
					facets = (WORD*) CUnindexedSet__GetBasePtr(&usPStream);

					// vertices
					pbVertices = CIndexedSet__GetAddress(&isSection, CART_SECTION_usVertices);
					D_8002DA8C(&usVertices, pbVertices, FALSE);
					nVertices = CUnindexedSet__GetBlockCount(&usVertices);
					vertices = (Vtx*) CUnindexedSet__GetBasePtr(&usVertices);

					// number of vertex loads required
					if (nVertices == 0)
					{
						nVertexLoads = 0;
					}
					else if (nVertices <= VERTEX_CACHE_SIZE)
					{
						nVertexLoads = 1;
					}
					else
					{
						nVertexLoads = 1 + ((nVertices - VERTEX_CACHE_SIZE) / (VERTEX_CACHE_SIZE/2));

						if ((nVertices - VERTEX_CACHE_SIZE) % (VERTEX_CACHE_SIZE/2))
							nVertexLoads++;
					}

					// number of polygon draw commands required
					nFacetLoads = nThisFacetLoad = 0;
					for (cFacet=0; cFacet<nFacets; cFacet++)
					{
						if (nThisFacetLoad)
						{
							nFacetLoads++;
							nThisFacetLoad = 0;
						}
						else
						{
							if (POLYSTREAM_ISLASTINRUN(facets[cFacet]))
								nFacetLoads++;
							else
								nThisFacetLoad++;
						}
					}

   				dispListSize = (nVertexLoads + nFacetLoads + 1)*sizeof(Gfx);
   				verticesSize = nVertices*sizeof(Vtx);

					// bounds check
					boundsCheck = (nNodes && (nVertices > BOUNDS_CHECK_THRESHOLD));
					if (boundsCheck)
					{
						dispListSize += 2*sizeof(Gfx);
						verticesSize += 8*sizeof(Vtx);
					}

   				newSectionSize = 8 + dispListSize + verticesSize;
   				newSectionSize = FixAlignment(newSectionSize, IS_ALIGNMENT);

   				// vertex count
					pVertexCount = (DWORD*) (pBytes + offset + nodesOffset + nodeOffset + partsOffset + partOffset + sectionOffset);
					*pVertexCount = nVertices;

					// display list
               pbDispList = ((BYTE*)pVertexCount) + 8;

   				// new vertices
   				newVertices = (Vtx*) (((BYTE*)pbDispList) + dispListSize);
					// bounds check
					if (boundsCheck)
					{
						boundsVertices = newVertices;
						newVertices += 8;
					}

					// vertex address
					pVertexCount++;
					*pVertexCount = (DWORD) newVertices;

					// deinterleave and copy outside of CUnindexedSet
					pOutPlace = (BYTE*) newVertices;
					inBytes = (BYTE*) vertices;
					for (cBlock=0; cBlock<nVertices; cBlock++)
					{
						for (cSize=0; cSize<sizeof(Vtx); cSize++)
						{
							*pOutPlace = inBytes[cSize*nVertices + cBlock];
							pOutPlace++;
						}
					}

					// light vertices
					if (		(pbNewGameSection->m_dwMatFlags & MATERIAL_PRELIT)
							&& !(GetApp()->m_dwCheatFlags & CHEATFLAG_PURDYCOLORS) )
					{
						switch (CACHE_BLOCK_GETVERSION(CCacheEntry__GetRequestedAddress(pThis->m_pceGeometry)))
						{
							case 0:
								// rotate 0
								dir[0] = GetApp()->m_Scene.m_LightDirection[0];
								dir[1] = GetApp()->m_Scene.m_LightDirection[1];
								dir[2] = GetApp()->m_Scene.m_LightDirection[2];
								break;

							case 1:
								// rotate 90
								dir[0] = -GetApp()->m_Scene.m_LightDirection[2];
								dir[1] = GetApp()->m_Scene.m_LightDirection[1];
								dir[2] = GetApp()->m_Scene.m_LightDirection[0];
								break;

							case 2:
								// rotate 180
								dir[0] = -GetApp()->m_Scene.m_LightDirection[0];
								dir[1] = GetApp()->m_Scene.m_LightDirection[1];
								dir[2] = -GetApp()->m_Scene.m_LightDirection[2];
								break;

							case 3:
								// rotate 270
								dir[0] = GetApp()->m_Scene.m_LightDirection[2];
								dir[1] = GetApp()->m_Scene.m_LightDirection[1];
								dir[2] = -GetApp()->m_Scene.m_LightDirection[0];
								break;

							default:
								ASSERT(FALSE);
								break;
						}

						for (cVertex=0; cVertex<nVertices; cVertex++)
						{
							pVert = &newVertices[cVertex];

							dot = ((pVert->n.n[0]*dir[0]
									+ pVert->n.n[1]*dir[1]
									+ pVert->n.n[2]*dir[2]) + 16384) >> 9;

							//dot = max(0, min(63, dot));
							// slightly faster version
							dot = (dot < 0) ? 0 : ((dot > 63) ? 63 : dot);

							pVert->v.cn[0] = D_8011A150[dot];
							pVert->v.cn[1] = D_8011A190[dot];
							pVert->v.cn[2] = D_8011A3D0[dot];
						}
					}

					// set up display list
   				pDLP = (Gfx*) pbDispList;

               if (boundsCheck)
					{
      				gSPVertex(pDLP++,
      							 RSP_ADDRESS(boundsVertices),
      							 8, 0);
						gSPCullDisplayList(pDLP++, 0, 7);

						minX = maxX = newVertices[0].v.ob[0];
						minY = maxY = newVertices[0].v.ob[1];
						minZ = maxZ = newVertices[0].v.ob[2];
						for (cVertex=1; cVertex<nVertices; cVertex++)
						{
							pVert = &newVertices[cVertex];

							minX = min(minX, pVert->v.ob[0]);
							maxX = max(maxX, pVert->v.ob[0]);

							minY = min(minY, pVert->v.ob[1]);
							maxY = max(maxY, pVert->v.ob[1]);

							minZ = min(minZ, pVert->v.ob[2]);
							maxZ = max(maxZ, pVert->v.ob[2]);
						}

						memset(boundsVertices, 0, 8*sizeof(Vtx));

						for (cVertex=0; cVertex<8; cVertex++)
						{
							pVert = &boundsVertices[cVertex];

							pVert->v.ob[0] = (cVertex & 1) ? minX : maxX;
							pVert->v.ob[1] = (cVertex & 2) ? minY : maxY;
							pVert->v.ob[2] = (cVertex & 4) ? minZ : maxZ;
						}
					}

					cVertex = 0;
               cFacet = 0;
               for (cVertexLoad=0; cVertexLoad<nVertexLoads; cVertexLoad++)
               {
                  // load a set of vertices
                  if (cVertexLoad)
                  {
                     vertexCount = min(nVertices - cVertex, (VERTEX_CACHE_SIZE/2));

      					gSPVertex(pDLP++,
      								 RSP_ADDRESS(&newVertices[cVertex]),
      								 vertexCount,
      								 (cVertexLoad & 1) ? 0 : (VERTEX_CACHE_SIZE/2));  // load at VERTEX_CACHE_SIZE/2 on evens, 0 on odds

                      
                                           
                                                        
                                                                                              
      
                  }
                  else
                  {
                     vertexCount = min(nVertices, VERTEX_CACHE_SIZE);      // load up to 16 on first pass

      					gSPVertex(pDLP++,
      								 RSP_ADDRESS(&newVertices[cVertex]),
      								 vertexCount, 0);             // load at 0

                      
                                                            
      
                  }

                  cVertex += vertexCount;

                  // draw polygons
                  do
                  {
                     poly = facets[cFacet++];

							last = POLYSTREAM_ISLASTINRUN(poly);

							if (last)
							{
								gSP1Triangle(pDLP++,
												 POLYSTREAM_GETVA(poly),
												 POLYSTREAM_GETVB(poly),
												 POLYSTREAM_GETVC(poly),
												 0);  // flag
							}
							else
							{
								nextPoly = facets[cFacet++];

								last = POLYSTREAM_ISLASTINRUN(nextPoly);

								gSP2Triangles(pDLP++,
												  POLYSTREAM_GETVA(poly),
												  POLYSTREAM_GETVB(poly),
												  POLYSTREAM_GETVC(poly),
												  0,	// flag
												  POLYSTREAM_GETVA(nextPoly),
												  POLYSTREAM_GETVB(nextPoly),
												  POLYSTREAM_GETVC(nextPoly),
												  0);	// flag
							}
                  } while (!last);
               }
               ASSERT(cFacet == nFacets);
               ASSERT(cVertex == nVertices);

   			 	gSPEndDisplayList(pDLP++);

					ASSERT((pDLP == (Gfx*)(((BYTE*)pbDispList) + dispListSize)));

					sectionOffset += newSectionSize;
					CIndexedSet__SetBlockCount(&isNewSection, 2);
					CIndexedSet__SetNextOffset(&isNewSection, sectionOffset);

   				partOffset += sectionOffset;
   				CIndexedSet__SetBlockCount(&isNewPart, cSection + 1);
   				CIndexedSet__SetNextOffset(&isNewPart, partOffset);

					CIndexedSet__Destruct(&isSection);
					CIndexedSet__Destruct(&isNewSection);
            }

				partsOffset += partOffset;
				CIndexedSet__SetBlockCount(&isNewParts, cPart + 1);
				CIndexedSet__SetNextOffset(&isNewParts, partsOffset);

				CIndexedSet__Destruct(&isPart);
				CUnindexedSet__Destruct(&usPStream);
				CUnindexedSet__Destruct(&usVertices);
			}

			nodeOffset += partsOffset;
			CIndexedSet__SetBlockCount(&isNewNode, 4);
			CIndexedSet__SetNextOffset(&isNewNode, nodeOffset);

			nodesOffset += nodeOffset;
			CIndexedSet__SetBlockCount(&isNewNodes, cNode + 1);
			CIndexedSet__SetNextOffset(&isNewNodes, nodesOffset);

			CIndexedSet__Destruct(&isNode);
			CIndexedSet__Destruct(&isNewNode);
			CIndexedSet__Destruct(&isParts);
			CIndexedSet__Destruct(&isNewParts);
		}

		offset += nodesOffset;
		ASSERT(offset == allocSize);
		CIndexedSet__SetBlockCount(&isNewGeometry, 2);
		CIndexedSet__SetNextOffset(&isNewGeometry, offset);

		CIndexedSet__Destruct(&isNewGeometry);
		CIndexedSet__Destruct(&isNewNodes);
	}
	else
	{
		TRACE("CGeometry: WARNING - could not allocate %x bytes for geometry.\r\n", allocSize);
	}

	CCacheEntry__DeallocAndReplaceData(pThis->m_pceGeometry, pBytes, allocSize);

               
                         
                                
      
	TRACE("...Finished geometry decompression in %8.2f msec.\r\n",
			((float)(CYCLES_TO_NSEC(diffTime)))/1000000);

	CIndexedSet__Destruct(&isNodes);
	CIndexedSet__Destruct(&isGeometry);
}
