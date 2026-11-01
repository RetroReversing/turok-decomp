#include "decompdecomp_sync_736faa5a757d60c7c57e.h"
#line 1 "func.c"
#line 3243 "reference.c"
void func_800183C4(CGameObjectInstance *pThis, CCacheEntry **ppceTarget)
{
	CIndexedSet			isAnim,
							isTransitionTable;
	CUnindexedSet		usYRots;
	void					*pbAnim,
							*pbYRots,
							*pbTransitionTable;
	CROMTransition		*pTransition;
	float					fraction;

	ASSERT(ppceTarget == &pThis->m_asCurrent.m_pceAnim);
	TRACE0("CGameObjectInstance: Animation received.\r\n");

	pbAnim = CCacheEntry__GetData(pThis->m_asCurrent.m_pceAnim);

	CIndexedSet__ConstructFromRawData(&isAnim, pbAnim, FALSE);

	// translation collection
	pbYRots = CIndexedSet__GetBlock(&isAnim, CART_ANIM_usYRotations);
	CUnindexedSet__ConstructFromRawData(&usYRots, pbYRots, FALSE);

	pThis->m_asCurrent.m_nFrames 			= CUnindexedSet__GetBlockCount(&usYRots);
	pThis->m_asCurrent.m_CycleCompleted	= FALSE;

	fraction = pThis->m_asCurrent.m_cFrame - ((int) pThis->m_asCurrent.m_cFrame);

	if (CGameObjectInstance__IsAnimChanged(pThis))
	{
		if (pThis->m_AI.m_dwStatusFlags2 & AI_IGNORESOUNDEVENTS)
		{
			// go to last frame
			pThis->m_asCurrent.m_cFrame = (pThis->m_asCurrent.m_nFrames - 1) + fraction;

			CGameObjectInstance__SendAllDoorEvents(pThis, &isAnim);
		}
		else
		{
			// a new anim has been loaded
			// start on frame one
			pThis->m_asCurrent.m_cFrame = 1 + fraction; // skip frame 0
		}
	}
	else
	{
		// an old animation has been reloaded
		// keep current frame
		if (pThis->m_asCurrent.m_cFrame >= pThis->m_asCurrent.m_nFrames)
		{
			pThis->m_asCurrent.m_cFrame = pThis->m_asCurrent.m_nFrames - 1 + fraction;
		}
	}
	CGameObjectInstance__SetAnimNotChanged(pThis);


	ASSERT(pThis->m_asCurrent.m_nFrames >= 2);	// animations must have at least 2 frames

	// setup blend if necessary
	if (pThis->m_WaitingForAnim != -1)
	{
		// get transition table block
		pbTransitionTable = CIndexedSet__GetBlock(&isAnim, CART_ANIM_isTransitionTable);
		CIndexedSet__ConstructFromRawData(&isTransitionTable, pbTransitionTable, FALSE);

		pTransition = (CROMTransition*) CIndexedSet__GetBlock(&isTransitionTable, CART_TRANTABLE_transition);

		// only start a blend if the object has a blend, and the object is visible
		// or it's a special "animate when not visible" object
	   if (		pTransition->m_BlendFromLength
				&& (		(CGameObjectInstance__IsVisible(pThis))
						||	(CGameObjectInstance__TypeFlag(pThis) == AI_OBJECT_DEVICE_ANIMOFFSCREENACTION) ) )
	   {
			TRACE0("CGameObjectInstance: Start blend.\r\n");

			CGameObjectInstance__SetBlending(pThis);
	      pThis->m_BlendLength = pTransition->m_BlendFromLength;
	      pThis->m_BlendPos 	= 0;
			pThis->m_BlendStart	= pTransition->m_BlendStart;
			pThis->m_BlendFinish	= pTransition->m_BlendFinish;
	   }
		else
		{
			CGameObjectInstance__SetNotBlending(pThis);
		}

		pThis->m_asCurrent.m_nAnim = pThis->m_WaitingForAnim;
		pThis->m_WaitingForAnim = -1;

		if (CGameObjectInstance__IsAbsoluteAnim(pThis, pThis->m_asBlend.m_nAnim))
			if (!CGameObjectInstance__IsAbsoluteAnim(pThis, pThis->m_asCurrent.m_nAnim))
				CGameObjectInstance__MoveToEndOfAbsoluteAnim(pThis, &pThis->m_asBlend);

		CIndexedSet__Destruct(&isTransitionTable);
	}

	CIndexedSet__Destruct(&isAnim);
	CUnindexedSet__Destruct(&usYRots);
}

