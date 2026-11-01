#include "decompdecomp_sync_233281df9061efcdf15c.h"
#line 1 "func.c"
#line 3858 "reference.c"
CVector3 func_800169E0(CIndexedSet *pisAnim, int nNode, int nFrame)
{
	CROMNodeIndex				nodeAnimIndex;
	void							*pbInitialOrients,
									*pbTransSets,
									*pbPosFrames;
	CUnindexedSet				usInitialOrients,
									usTransSets,
									usPosFrames;
	CROMInitialOrientation	*initialOrients;
	CPosFrame					*pPosFrames;

	ASSERT(nFrame >= 0);

	nodeAnimIndex = CGameObjectInstance__GetNodeAnimIndex(pisAnim, nNode);
	if (nodeAnimIndex.m_nTranslationSet == -1)
	{
		// get initial translation
		pbInitialOrients = CIndexedSet__GetBlock(pisAnim, CART_ANIM_usInitialOrients);
		CUnindexedSet__ConstructFromRawData(&usInitialOrients, pbInitialOrients, FALSE);

		ASSERT(nNode < CUnindexedSet__GetBlockCount(&usInitialOrients));
		initialOrients = (CROMInitialOrientation*) CUnindexedSet__GetBasePtr(&usInitialOrients);

		CUnindexedSet__Destruct(&usInitialOrients);

		return initialOrients[nNode].m_vPos;
	}
	else
	{
		// get keyframed translation

		pbTransSets = CIndexedSet__GetBlock(pisAnim, CART_ANIM_usTranslationSets);
		CUnindexedSet__ConstructFromRawData(&usTransSets, pbTransSets, FALSE);

		ASSERT(nodeAnimIndex.m_nTranslationSet < CUnindexedSet__GetBlockCount(&usTransSets));
		pbPosFrames = CUnindexedSet__GetBlock(&usTransSets, nodeAnimIndex.m_nTranslationSet);
		CUnindexedSet__ConstructFromRawData(&usPosFrames, pbPosFrames, FALSE);

		pPosFrames = (CPosFrame*) CUnindexedSet__GetBasePtr(&usPosFrames);
		ASSERT(nFrame < CUnindexedSet__GetBlockCount(&usPosFrames));

		CUnindexedSet__Destruct(&usTransSets);
		CUnindexedSet__Destruct(&usPosFrames);

		return pPosFrames[nFrame].m_vPos;
	}
}

