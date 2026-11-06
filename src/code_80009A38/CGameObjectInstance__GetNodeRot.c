#include "decompdecomp_sync_233281df9061efcdf15c.h"
#line 1 "func.c"
#line 3907 "reference.c"
CQuatern CGameObjectInstance__GetNodeRot(CIndexedSet *pisAnim, int nNode, int nFrame)
{
	CROMNodeIndex				nodeAnimIndex;
	void							*pbInitialOrients,
									*pbRotSets,
									*pbRotFrames;
	CUnindexedSet				usInitialOrients,
									usRotSets,
									usRotFrames;
	CROMInitialOrientation	*initialOrients, *pInit;
	CRotFrame					*pRotFrames, *pFrame;
	CQuatern						qRot;

	ASSERT(nFrame >= 0);

	nodeAnimIndex = CGameObjectInstance__GetNodeAnimIndex(pisAnim, nNode);

	if (nodeAnimIndex.m_nRotationSet == -1)
	{
		// get initial rotation

		pbInitialOrients = CIndexedSet__GetAddress(pisAnim, CART_ANIM_usInitialOrients);
		CUnindexedSet__ConstructFromRawData(&usInitialOrients, pbInitialOrients, FALSE);

		ASSERT(nNode < CUnindexedSet__GetBlockCount(&usInitialOrients));
		initialOrients = (CROMInitialOrientation*) CUnindexedSet__GetBasePtr(&usInitialOrients);

		CUnindexedSet__Destruct(&usInitialOrients);

		//return initialOrients[nNode].m_qRot;
		pInit = &initialOrients[nNode];

		qRot.x = INT162FLOAT(pInit->m_RotX, 1);
		qRot.y = INT162FLOAT(pInit->m_RotY, 1);
		qRot.z = INT162FLOAT(pInit->m_RotZ, 1);
		qRot.t = INT162FLOAT(pInit->m_RotT, 1);
	}
	else
	{
		// get keyframed rotation

		pbRotSets = CIndexedSet__GetAddress(pisAnim, CART_ANIM_usRotationSets);
		CUnindexedSet__ConstructFromRawData(&usRotSets, pbRotSets, FALSE);

		ASSERT(nodeAnimIndex.m_nRotationSet < CUnindexedSet__GetBlockCount(&usRotSets));
		pbRotFrames = CUnindexedSet__GetBlock(&usRotSets, nodeAnimIndex.m_nRotationSet);
		CUnindexedSet__ConstructFromRawData(&usRotFrames, pbRotFrames, FALSE);

		pRotFrames = (CRotFrame*) CUnindexedSet__GetBasePtr(&usRotFrames);
		ASSERT(nFrame < CUnindexedSet__GetBlockCount(&usRotFrames));

		CUnindexedSet__Destruct(&usRotSets);
		CUnindexedSet__Destruct(&usRotFrames);

		//return pRotFrames[nFrame].m_qRot;
		pFrame = &pRotFrames[nFrame];

		qRot.x = INT162FLOAT(pFrame->x, 1);
		qRot.y = INT162FLOAT(pFrame->y, 1);
		qRot.z = INT162FLOAT(pFrame->z, 1);
		qRot.t = INT162FLOAT(pFrame->t, 1);
	}

	return qRot;
}

