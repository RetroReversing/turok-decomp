#include "decompdecomp_sync_56349a3edd4a863d1a9c.h"
#line 1 "func.c"
#line 1 "reference.c"
void CScene__GetGridSections(CScene *pThis, CBoundsRect *pBoundsRect,
									  CGameGridBounds **ppGrids[], int *pIndices[], int *pnGrids)
{
#define MAX_GRID	128
	int					nGridSections,
							cX, nXs,
							cZ, nZs,
							leftX, rightX,
							leftZ, rightZ,
							index;
	CIndexedSet			isGridBounds;
	CUnindexedSet		usMinXs, usMaxXs,
							usMinZs, usMaxZs,
							usBounds;
	float					*minXs, *maxXs,
							*minZs, *maxZs;
	CGameGridBounds	*gridBounds, *pBounds;
	void					*pbMinXs, *pbMaxXs,
							*pbMinZs, *pbMaxZs,
							*pbBounds;
	extern CGameGridBounds *D_8011A1D0[];
#define pgrids D_8011A1D0
	extern int D_8011A410[];
#define indices D_8011A410

	ASSERT(pBoundsRect);
	ASSERT(ppGrids);
	ASSERT(pnGrids);

	if (!pThis->m_pceGridBounds)
	{
		*pnGrids = 0;
		return;
	}

	nGridSections = 0;

	CIndexedSet__ConstructFromRawData(&isGridBounds,
												 CCacheEntry__GetData(pThis->m_pceGridBounds),
												 FALSE);

	pbMinXs = CIndexedSet__GetBlock(&isGridBounds, CART_GRIDBOUNDS_usMinXs);
	func_8002DA8C(&usMinXs, pbMinXs, FALSE);
	nXs = CUnindexedSet__GetBlockCount(&usMinXs);
	minXs = (float*) CUnindexedSet__GetBasePtr(&usMinXs);

	pbMaxXs = CIndexedSet__GetBlock(&isGridBounds, CART_GRIDBOUNDS_usMaxXs);
	func_8002DA8C(&usMaxXs, pbMaxXs, FALSE);
	maxXs = (float*) CUnindexedSet__GetBasePtr(&usMaxXs);

	pbMinZs = CIndexedSet__GetBlock(&isGridBounds, CART_GRIDBOUNDS_usMinZs);
	func_8002DA8C(&usMinZs, pbMinZs, FALSE);
	nZs = CUnindexedSet__GetBlockCount(&usMinZs);
	minZs = (float*) CUnindexedSet__GetBasePtr(&usMinZs);

	pbMaxZs = CIndexedSet__GetBlock(&isGridBounds, CART_GRIDBOUNDS_usMaxZs);
	func_8002DA8C(&usMaxZs, pbMaxZs, FALSE);
	maxZs = (float*) CUnindexedSet__GetBasePtr(&usMaxZs);

	pbBounds = CIndexedSet__GetBlock(&isGridBounds, CART_GRIDBOUNDS_usBounds);
	func_8002DA8C(&usBounds, pbBounds, FALSE);
	gridBounds = (CGameGridBounds*) CUnindexedSet__GetBasePtr(&usBounds);
	ASSERT((nXs*nZs) == CUnindexedSet__GetBlockCount(&usBounds));
	ASSERT(nXs && nZs);

	leftX = 0;
	while ((leftX < nXs) && (pBoundsRect->m_MinX > maxXs[leftX]))
		leftX++;

	rightX = nXs - 1;
	while ((rightX >= 0) && (pBoundsRect->m_MaxX < minXs[rightX]))
		rightX--;

	leftZ = 0;
	while ((leftZ < nZs) && (pBoundsRect->m_MinZ > maxZs[leftZ]))
		leftZ++;

	rightZ = nZs - 1;
	while ((rightZ >= 0) && (pBoundsRect->m_MaxZ < minZs[rightZ]))
		rightZ--;

	for (cZ=leftZ; cZ<=rightZ; cZ++)
	{
		for (cX=leftX; (s32)cX<=rightX; cX++)
		{
			if (nGridSections != MAX_GRID)
			{
				index = cX + cZ*nXs;

				pBounds = &gridBounds[index];
				if (CBoundsRect__IsOverlapping(&pBounds->m_BoundsRect, pBoundsRect))
				{
					indices[nGridSections] = index;
					pgrids[nGridSections] = pBounds;

					nGridSections++;
				}
			}
		}
	}

	*ppGrids = pgrids;
	*pIndices = indices;
	*pnGrids = nGridSections;


	CIndexedSet__Destruct(&isGridBounds);
	CUnindexedSet__Destruct(&usMinXs);
	CUnindexedSet__Destruct(&usMaxXs);
	CUnindexedSet__Destruct(&usMinZs);
	CUnindexedSet__Destruct(&usMaxZs);
	CUnindexedSet__Destruct(&usBounds);
}

