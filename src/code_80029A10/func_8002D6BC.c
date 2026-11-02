#include "decompdecomp_sync_b45b2fc76cd07a4ba230.h"
#line 1 "func.c"
#line 1233 "reference.c"
BOOL func_8002D6BC(CCacheEntry *pThis, BOOL AllocTop)
{
            

               
              

     

               
                                       
      
	DWORD				allocSize;
	void				*pCompressedData, *pBytes;
	BOOL				ret;
	BYTE				*headers;

	pCompressedData = CCacheEntry__GetData(pThis);

	headers = (BYTE*) pCompressedData;
	if (		(headers[0] == 'R')
			&& (headers[1] == 'N')
			&& (headers[2] == 'C') )
	{
               
                                                       
                          
      

		// allocate block for decompressed data
		allocSize = CMP_GetDecompressedSize(pCompressedData);
		pBytes = CCacheEntry__DoAllocDataForReplacement(pThis, allocSize, AllocTop);
		if (pBytes)
		{
			ret = CMP_DecompressData(pCompressedData, pBytes);
			ASSERT(ret);
		}

		CCacheEntry__DeallocAndReplaceData(pThis, pBytes, allocSize);

               
                        
                                 

                                                                   
                                                 
      

		return (pBytes != NULL);
	}
	else
	{
		return TRUE;
	}
      
}

static void* CCacheEntry__GetData(CCacheEntry *pThis)
{

             

	// extra debugging info
               
                                                
                                                       
      

      

	ASSERT(pThis->m_Allocated == CACHEENTRY_ALLOCATED);
	ASSERT(!pThis->m_Compressed);

	CCacheEntry__ResetAge(pThis);

   return pThis->m_pData;
}

static void CCacheEntry__DeallocAndReplaceData(CCacheEntry *pThis, void *pNewData, DWORD NewLength)
{
   ASSERT(pThis->m_pData);

             
	TRACE4("CCacheEntry: Replacing 0x%x, len 0x%x with 0x%x, len 0x%x.\r\n",
			 pThis->m_pData, pThis->m_DataLength,
			 pNewData, NewLength);
      

   DEALLOC(pThis->m_pData);
   pThis->m_pData = pNewData;
	pThis->m_DataLength = NewLength;
}

static DWORD CMP_GetDecompressedSize(void *pCompressedData)
{
            
               
          
     
	ASSERT(pCompressedData);

	//return (DWORD) (BIGENDIANL(((RNC_fileptr)pCompressedData)->UncompressedSize));
	return ((DWORD*)pCompressedData)[1];
      
}

