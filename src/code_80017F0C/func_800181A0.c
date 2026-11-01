#include "decompdecomp_sync_17c08435efa16e0ad060.h"
#line 1 "func.c"
#line 5315 "reference.c"
int func_800181A0(CGameObjectInstance *pThis, int nAnimIndex)
{
	CIndexedSet		isObjectInfo;
	CUnindexedSet	usAnimTypes;
	void				*pbAnimTypes;
	DWORD				*animTypes;
	int				nType;

	if (!pThis->m_rpObjectInfo)
		return -1;

	pThis->m_pceObjectInfo = NULL;
	CCartCache__RequestBlock(GetCache(),
									 NULL, NULL, NULL,
									 &pThis->m_pceObjectInfo,
									 pThis->m_rpObjectInfo, pThis->m_ObjectInfoSize,
									 ((char*)D_800F0DBC));

	if (!pThis->m_pceObjectInfo)
		return -1;

	CIndexedSet__ConstructFromRawData(&isObjectInfo,
												 CCacheEntry__GetData(pThis->m_pceObjectInfo),
												 FALSE);

	pbAnimTypes = CIndexedSet__GetBlock(&isObjectInfo, CART_OBJECTINFO_usAnimTypes);

	CUnindexedSet__ConstructFromRawData(&usAnimTypes, pbAnimTypes, FALSE);

	animTypes = (DWORD*) CUnindexedSet__GetBasePtr(&usAnimTypes);
	ASSERT(nAnimIndex < CUnindexedSet__GetBlockCount(&usAnimTypes));

	nType = animTypes[nAnimIndex];

	CIndexedSet__Destruct(&isObjectInfo);
	CUnindexedSet__Destruct(&usAnimTypes);

	return nType;
}

