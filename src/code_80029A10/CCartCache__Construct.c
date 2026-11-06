#include "decompdecomp_sync_69d19dee3ce805432ecf.h"
#line 1 "func.c"
#line 1293 "reference.c"
void CCartCache__Construct(CCartCache *pThis)
{
	int i;

	TRACE0("CCartCache construction\r\n");

   pThis->m_DiscardAge = 2;
   pThis->m_pNotifyHead = pThis->m_pNotifyTail = NULL;
   pThis->m_pCacheHead = pThis->m_pCacheTail = NULL;


	// initialize lists of entries in cache
	for (i=1; i<CARTCACHE_CACHEENTRY_COUNT; i++)
		pThis->m_CacheEntries[i-1].m_pNextFree = &pThis->m_CacheEntries[i];

	pThis->m_CacheEntries[CARTCACHE_CACHEENTRY_COUNT-1].m_pNextFree = NULL;
	pThis->m_pCacheFreeHead = &pThis->m_CacheEntries[0];

	for (i=0; i<CARTCACHE_CACHEENTRY_COUNT; i++)
		pThis->m_CacheEntries[i].m_Allocated = CACHEENTRY_UNALLOCATED;

	for (i=1; i<CARTCACHE_NOTIFYENTRY_COUNT; i++)
		pThis->m_NotifyEntries[i-1].m_pNextFree = &pThis->m_NotifyEntries[i];

	pThis->m_NotifyEntries[CARTCACHE_NOTIFYENTRY_COUNT-1].m_pNextFree = NULL;
	pThis->m_pNotifyFreeHead = &pThis->m_NotifyEntries[0];

	CHashTable__Construct(&pThis->m_HashTable, HASH_ALLOC_BLOCK);
	CHashTable__InitHashTable(&pThis->m_HashTable, HASH_TABLE_SIZE, TRUE);

	TRACE0("CCartCache construction DONE\r\n");
}

