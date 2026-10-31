#include "source_func_80034BA0.h"

#line 1 "reference.c"
void func_80034BA0(CScene *pThis, CCacheEntry **ppceTarget)
{
	CIndexedSet		isWarpPoints;
	CUnindexedSet	usIDs,
						usWarpDests;
	void				*pbIDs,
						*pbWarpDests;
	DWORD				*ids;
	int				nWarpPoints,
						first, last,
						choice;
	CROMWarpPoint	*warpPoints;

	ASSERT(ppceTarget == &pThis->m_pceWarpPoints);
	TRACE0("CScene: Warp points received.\r\n");

	CIndexedSet__ConstructFromRawData(&isWarpPoints,
												 CCacheEntry__GetData(pThis->m_pceWarpPoints),
												 FALSE);

	pbIDs = CIndexedSet__GetBlock(&isWarpPoints, CART_WARPDESTS_usIDs);
	func_8002DA8C(&usIDs, pbIDs, FALSE);
	ids = (DWORD*) CUnindexedSet__GetBasePtr(&usIDs);
	nWarpPoints = CUnindexedSet__GetBlockCount(&usIDs);

	pbWarpDests = CIndexedSet__GetBlock(&isWarpPoints, CART_WARPDESTS_usWarpDests);
	func_8002DA8C(&usWarpDests, pbWarpDests, FALSE);
	warpPoints = (CROMWarpPoint*) CUnindexedSet__GetBasePtr(&usWarpDests);
	ASSERT(nWarpPoints == CUnindexedSet__GetBlockCount(&usWarpDests));


	// handle ID -1 as return warp
	if (pThis->m_nWarpID == RETURN_WARP_ID)
	{
		if (GetApp()->m_ReturnWarpSaved)
		{
			pThis->m_WarpFound = TRUE;
			pThis->m_WarpPoint = GetApp()->m_ReturnWarp;
			pThis->m_nLevel = pThis->m_WarpPoint.m_nLevel;
		}
		else
		{
			pThis->m_WarpFound = FALSE;
			pThis->m_nLevel = 0;
		}
	}
	else
	if (pThis->m_nWarpID == CRASH_WARP_ID)
	{
		pThis->m_WarpFound = TRUE;
		pThis->m_WarpPoint = D_8014F670;
		pThis->m_nLevel = pThis->m_WarpPoint.m_nLevel;
	}
	else
	if (pThis->m_nWarpID == CINEMA_WARP_ID)
	{
			pThis->m_WarpFound = TRUE ;
			pThis->m_WarpPoint = GetApp()->m_CinemaWarp ;
			pThis->m_nLevel = pThis->m_WarpPoint.m_nLevel ;
	}
	else
	{
		pThis->m_WarpFound = func_80083C74(ids, nWarpPoints, pThis->m_nWarpID, &first, &last);
		if (pThis->m_WarpFound)
		{
			choice = first + RANDOM((last + 1) - first);

			// must copy data because pceWarpPoints may not be around later
			pThis->m_WarpPoint = warpPoints[choice];
			pThis->m_nLevel = pThis->m_WarpPoint.m_nLevel;
		}
		else
		{
			pThis->m_nLevel = 0;
		}
	}

	// request object types
   func_8002D1F8(&pThis->m_Cache,
									 pThis, NULL, (pfnCACHENOTIFY) func_80034498,
                            &pThis->m_pceObjectTypes,
                            pThis->m_rpObjectTypesAddress, pThis->m_ObjectTypesSize,
                            "Objects Types");

	CIndexedSet__Destruct(&isWarpPoints);
	CUnindexedSet__Destruct(&usIDs);
	CUnindexedSet__Destruct(&usWarpDests);
}
