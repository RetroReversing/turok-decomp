#include "decompdecomp_sync_d1a9230c436ba570f40b.h"
#line 1 "func.c"
#line 1597 "reference.c"
void func_8002D1F8(CCartCache *pThis,
										void *pNotifyPtr,
                              pfnCACHENOTIFY pfnDecompress,
                              pfnCACHENOTIFY pfnBlockReceived,
                              CCacheEntry **ppceTarget,
                              ROMAddress *rpRequestAddress, DWORD rLength,
                              const char *szDescription /*=""*/)
{
	BOOL 				found,
						retrieve,
						alreadyRetreiving;
   CCacheEntry		*pCacheEntry;
	CNotifyEntry 	*pNotify,
						*pSearchNotify;
	void				*pData;

             
	ASSERT(osGetThreadId(NULL) == THREAD_MAIN);
      

   ASSERT(rpRequestAddress);
   ASSERT(ppceTarget);
   ASSERT(rLength);

	pCacheEntry = NULL;	// not used, just supresses warning;
	found = CHashTable__Lookup(&pThis->m_HashTable, rpRequestAddress, (void**) &pCacheEntry);

   if (found)
      retrieve = (pCacheEntry->m_rLength < rLength); // retrieve if requested length is larger
   else
      retrieve = TRUE;

   if (retrieve)
   {
      // DON'T clear target address pointer!  This way it can continue using
		// old data until new data comes back
      //*ppceTarget = NULL;

		// ROM address and length should be 2 byte aligned for DMA operation
		ASSERT(!(((DWORD)rpRequestAddress) & 0x1));
		if (rLength & 0x1)
			rLength++;
		ASSERT(!(rLength & 0x1));

		pNotify = CCartCache__AllocNotifyEntry(pThis);

		if (pNotify)
		{
			// don't need to request block from ROM if valid request
			// has already been made
			alreadyRetreiving = FALSE;
			pSearchNotify = pThis->m_pNotifyHead;
			while (pSearchNotify)
			{
				if ((pSearchNotify->m_rpRequestedAddress == rpRequestAddress) && (pSearchNotify->m_rLength >= rLength))
				{
					alreadyRetreiving = TRUE;
					break;
				}

				pSearchNotify = pSearchNotify->m_pNext;
			}

			if (!alreadyRetreiving)
			{
				pData = CCartCache__Alloc(pThis, rLength, pfnDecompress != NULL);
				if (pData)
				{
					// RDRAM address should be 8 byte aligned
					ASSERT(!(((DWORD)pData) & 0x7));
				}
				else
				{
					CCartCache__DeallocNotifyEntry(pThis, pNotify);
				}
			}

			if (pData || alreadyRetreiving)
			{
				pNotify->m_pNotifyPtr         = pNotifyPtr;
				pNotify->m_pfnDecompress      = pfnDecompress;
				pNotify->m_pfnBlockReceived   = pfnBlockReceived;
				pNotify->m_ppceTarget         = ppceTarget;
				pNotify->m_rpRequestedAddress = rpRequestAddress;
				pNotify->m_rLength            = rLength;
				pNotify->m_szDescription      = szDescription;

				// insert at tail of notify list
				if (pThis->m_pNotifyTail)
					pThis->m_pNotifyTail->m_pNext = pNotify;
				else
					pThis->m_pNotifyHead  = pNotify;
				pNotify->m_pNext  	= NULL;
				pNotify->m_pLast  	= pThis->m_pNotifyTail;
				pThis->m_pNotifyTail	= pNotify;
			}

			if (pData && (!alreadyRetreiving))
			{
      		TRACE3("Cache: Request block \"%s\" at 0x%x, len 0x%x.\r\n",
						 szDescription,
						 rpRequestAddress,
						 rLength);

            
                                                                     
                                                                                           
     
				// FOR NOW, REQUEST IS SYNCHRONOUS
				BrokenUpDMA(pData,
								(ROMAddress*) ((DWORD) rpRequestAddress & ~CACHE_BLOCK_VERSION_MASK),
								rLength);
/*
				//rmonPrintf("----  rpRequestAddress:%x, rLength:%x, pData:%x\r\n", rpRequestAddress, rLength, pData);

				//memset(pData, 0, rLength);

				osWritebackDCache(pData, rLength);
				osInvalDCache(dynamic_memory_pool, MEMORY_POOL_SIZE);

				osPiStartDma(&dmaIOMessageBuf, OS_MESG_PRI_NORMAL, OS_READ,
								 (DWORD) rpRequestAddress & ~CACHE_BLOCK_VERSION_MASK, pData, rLength,
								 &dmaMessageQ);

				// wait for DMA to finish
				osRecvMesg(&dmaMessageQ, NULL, OS_MESG_BLOCK);
				osInvalDCache(pData, rLength);
*/
//				romcpy(pData, (DWORD) rpRequestAddress & ~CACHE_BLOCK_VERSION_MASK, rLength);
      
				CCartCache__BlockReceived(pThis, rpRequestAddress, rLength, pData);
			}
		}
   }
   else
   {
      // ??
      //pCacheEntry->ResetAge();

      *ppceTarget = pCacheEntry;
      if (pfnBlockReceived)
         pfnBlockReceived(pNotifyPtr, ppceTarget);
   }
}

