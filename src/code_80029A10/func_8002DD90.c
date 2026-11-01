#include "decompdecomp_sync_4602a6fc5b7caae1eca9.h"
#line 1 "func.c"
#line 7 "reference.c"
void func_8002DD90(CHashTable *pThis, HASHPOS *prNextPosition, void **prKey, void **prValue)
{
	CAssoc	*pAssocRet,
				*pAssocNext;
	UINT		nBucket;

	ASSERT(pThis->m_pHashTable != NULL);  // never call on empty map

	pAssocRet = (CAssoc*) *prNextPosition;
	ASSERT(pAssocRet != NULL);

	if (pAssocRet == (CAssoc*) BEFORE_START_HASHPOS)
	{
		// find the first association
		for (nBucket = 0; nBucket < pThis->m_nHashTableSize; nBucket++)
			if ((pAssocRet = pThis->m_pHashTable[nBucket]) != NULL)
				break;
		ASSERT(pAssocRet != NULL);  // must find something
	}

	// find next association
            
                                                      
      
	if ((pAssocNext = pAssocRet->pNext) == NULL)
	{
		// go to next bucket
		for (nBucket = pAssocRet->nHashValue + 1;
		  nBucket < pThis->m_nHashTableSize; nBucket++)
			if ((pAssocNext = pThis->m_pHashTable[nBucket]) != NULL)
				break;
	}

	*prNextPosition = (HASHPOS) pAssocNext;

	// fill in return data
	*prKey = pAssocRet->key;
	*prValue = pAssocRet->value;
}

