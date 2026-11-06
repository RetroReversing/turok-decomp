#include "decompdecomp_sync_41af171a000bc5767866.h"
#line 1 "func.c"
#line 1203 "reference.c"
void CScene__DecompressCollision(CScene *pThis, CCacheEntry **ppceTarget)
{
	CIndexedSet			isCollision, isNewCollision;
	CUnindexedSet		usAttributes, usRegions, usCorners, usBlocks,
							usNewRegions, usNewCorners;
	void					*pbRegionAttributes, *pbNewRegionAttributes,
							*pbCorners, *pbNewCorners,
							*pbRegions, *pbNewRegions,
							*pbBlocks, *pbNewBlocks,
							*pbNewCollision;
	DWORD					regionAttributesSize,
							cornersSize,
							blocksSize,
							newRegionsSize;
	int					cRegion, nRegions,
							cCorner, nCorners,
							newSize,
							offset;
	BYTE					*pBytes;
	CROMRegion			*regions;
	CROMCorner			*newCorners;
	CGameRegion			*newRegions;

	ASSERT(ppceTarget == &pThis->m_pceCollision);

	TRACE0("CScene: Decompressing collision data.\r\n");

	if (!CCacheEntry__DecompressTemp(pThis->m_pceCollision))
		return;

	CIndexedSet__ConstructFromRawData(&isCollision,
												 CCacheEntry__GetData(pThis->m_pceCollision),
												 FALSE);

	pbRegionAttributes = CIndexedSet__GetBlockAndSize(&isCollision, CART_COLLISION_usRegionAttributes, &regionAttributesSize);
	CUnindexedSet__ConstructFromRawData(&usAttributes, pbRegionAttributes, FALSE);

	pbCorners = CIndexedSet__GetBlockAndSize(&isCollision, CART_COLLISION_usCorners, &cornersSize);
	CUnindexedSet__ConstructFromRawData(&usCorners, pbCorners, FALSE);

	pbRegions = CIndexedSet__GetAddress(&isCollision, CART_COLLISION_usRegions);
	CUnindexedSet__ConstructFromRawData(&usRegions, pbRegions, FALSE);

	nRegions = CUnindexedSet__GetBlockCount(&usRegions);
	TRACE("There are %d regions.\r\n", nRegions);

	pbBlocks = CIndexedSet__GetBlockAndSize(&isCollision, CART_COLLISION_usBlockBounds, &blocksSize);
	CUnindexedSet__ConstructFromRawData(&usBlocks, pbBlocks, FALSE);

	newRegionsSize = FixAlignment(US_TOTAL_SIZE(sizeof(CGameRegion), nRegions), IS_ALIGNMENT);
	newSize = IS_INDEX_SIZE(4) + regionAttributesSize + cornersSize + newRegionsSize + blocksSize;

	pBytes = CCacheEntry__AllocDataForReplacement(pThis->m_pceCollision, newSize);
	ASSERT(pBytes);	// must always be able to allocate regions!
	if (pBytes)
	{
		pbNewCollision = pBytes;
		CIndexedSet__ConstructFromRawData(&isNewCollision, pbNewCollision, FALSE);

		offset = IS_INDEX_SIZE(4);
		CIndexedSet__SetBlockCount(&isNewCollision, 0);
		CIndexedSet__SetNextOffset(&isNewCollision, offset);


		pbNewRegionAttributes = pBytes + offset;
		//memcpy(pbNewRegionAttributes, pbRegionAttributes, regionAttributesSize);
		CUnindexedSet__DeinterleaveCopy(&usAttributes, pbNewRegionAttributes, FALSE);

		offset += regionAttributesSize;
		CIndexedSet__SetBlockCount(&isNewCollision, 1);
		CIndexedSet__SetNextOffset(&isNewCollision, offset);


		pbNewCorners = pBytes + offset;
		//memcpy(pbNewCorners, pbCorners, cornersSize);
		CUnindexedSet__DeinterleaveCopy(&usCorners, pbNewCorners, FALSE);

		CUnindexedSet__ConstructFromRawData(&usNewCorners, pbNewCorners, FALSE);

		offset += cornersSize;
		CIndexedSet__SetBlockCount(&isNewCollision, 2);
		CIndexedSet__SetNextOffset(&isNewCollision, offset);

		pbNewRegions = pBytes + offset;
		ASSERT(sizeof(CGameRegion) >= sizeof(CROMRegion));
		CUnindexedSet__DeinterleaveCopy(&usRegions, pbNewRegions, TRUE);

		func_8002DA18(&usNewRegions,
															  	 pbNewRegions,				// data ptr
															  	 sizeof(CGameRegion),	// block size
															  	 nRegions,					// block count
															  	 FALSE);						// don't auto delete data

		regions = (CROMRegion*) CUnindexedSet__GetBasePtr(&usRegions);
		newRegions = (CGameRegion*) CUnindexedSet__GetBasePtr(&usNewRegions);
		newCorners = (CROMCorner*) CUnindexedSet__GetBasePtr(&usNewCorners);


		nCorners = CUnindexedSet__GetBlockCount(&usCorners);
		for (cCorner=0; cCorner<nCorners; cCorner++)
			CROMCorner__Decode(&newCorners[cCorner]);


		
		D_8011A610 = newRegions;
		for (cRegion=0; cRegion<nRegions; cRegion++)
		{
			CGameRegion__TakeFromROMRegion(&newRegions[cRegion], &regions[cRegion],
													 newCorners, newRegions);
			if (CScene__GetRegionFlag(pThis, cRegion))
				newRegions[cRegion].m_wFlags |= REGFLAG_REGIONENTERED ;
		}

		offset += newRegionsSize;
		CIndexedSet__SetBlockCount(&isNewCollision, 3);
		CIndexedSet__SetNextOffset(&isNewCollision, offset);

		// region block bounds
		pbNewBlocks = pBytes + offset;
		CUnindexedSet__DeinterleaveCopy(&usBlocks, pbNewBlocks, FALSE);

		offset += blocksSize;
		CIndexedSet__SetBlockCount(&isNewCollision, 4);
		CIndexedSet__SetNextOffset(&isNewCollision, offset);


		CIndexedSet__Destruct(&isNewCollision);
		CUnindexedSet__Destruct(&usNewCorners);
		CUnindexedSet__Destruct(&usNewRegions);
	}

	CCacheEntry__DeallocAndReplaceData(pThis->m_pceCollision, pBytes, newSize);

	TRACE0("CScene: ...Finished collision decompression.\r\n");

	CIndexedSet__Destruct(&isCollision);
	CUnindexedSet__Destruct(&usAttributes);
	CUnindexedSet__Destruct(&usRegions);
	CUnindexedSet__Destruct(&usCorners);
	CUnindexedSet__Destruct(&usBlocks);
}

