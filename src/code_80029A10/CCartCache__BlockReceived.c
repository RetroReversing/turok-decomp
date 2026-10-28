#include "common.h"

struct CAssoc_t;
struct CHashPlex_t;
typedef struct CHashTable_t
{
 struct CAssoc_t **m_pHashTable;
 unsigned long m_nHashTableSize;
 int m_nCount;
 struct CAssoc_t *m_pFreeList;
 struct CHashPlex_t *m_pBlocks;
 int m_nBlockSize;
} CHashTable;
extern int func_8002E13C(CHashTable *pThis, void* key, void **prValue);
extern void func_8002E098(CHashTable *pThis, void* key, void* newValue);
extern int D_8002DE54(CHashTable *pThis, void* key);
typedef ROMAddress;
struct CCartCache_t;
typedef struct CCacheEntry_t
{
   void *m_pData;
 unsigned long m_DataLength;
   ROMAddress *m_rpAddress;
   unsigned long m_rLength;
 struct CCartCache_t *m_pOwner;
 unsigned long m_LastAccessed;
   int m_InHashTable,
      m_Compressed;
 unsigned long m_Allocated;
   const char *m_szDescription;
   struct CCacheEntry_t *m_pLast, *m_pNext,
         *m_pNextFree;
} CCacheEntry;
typedef void (*pfnCACHENOTIFY)(void *pNotifyPtr, CCacheEntry **ppceTarget);
typedef struct CNotifyEntry_t
{
   void *m_pNotifyPtr;
   pfnCACHENOTIFY m_pfnDecompress,
                  m_pfnBlockReceived;
   CCacheEntry **m_ppceTarget;
   ROMAddress *m_rpRequestedAddress;
   unsigned long m_rLength;
   const char *m_szDescription;
   struct CNotifyEntry_t *m_pLast, *m_pNext,
         *m_pNextFree;
} CNotifyEntry;
typedef struct CCartCache_t
{
   CHashTable m_HashTable;
   CNotifyEntry *m_pNotifyHead, *m_pNotifyTail;
   CCacheEntry *m_pCacheHead, *m_pCacheTail;
   int m_DiscardAge;
 CCacheEntry m_CacheEntries[512];
 CCacheEntry *m_pCacheFreeHead;
 CNotifyEntry m_NotifyEntries[16];
 CNotifyEntry *m_pNotifyFreeHead;
} CCartCache;
struct CCacheEntry_t;
typedef struct CTextureLoader_t
{
 struct CCacheEntry_t *m_pceTextureSet;
 ROMAddress *m_rpTextureSet;
 unsigned long m_TextureSetSize;
} CTextureLoader;
extern void CCartCache__BlockReceived(CCartCache *pThis,
                 ROMAddress *rpRequestedAddress, unsigned long rLength,
                 void *pData);
extern CCacheEntry* func_8002CD74(CCartCache *pThis);
extern void D_8002CBEC(CCartCache *pThis, CCacheEntry *pCacheEntry);
extern void D_8002CCB8(CCartCache *pThis, CNotifyEntry *pNotify);
CCacheEntry* func_8002CD74(CCartCache *pThis);
void CCartCache__BlockReceived(CCartCache *pThis,
           ROMAddress *rpRequestedAddress, unsigned long rLength, void *pData);
void D_8002CCB8(CCartCache *pThis, CNotifyEntry *pNotify);
void D_8002CBEC(CCartCache *pThis, CCacheEntry *pCacheEntry);
void CCartCache__BlockReceived(CCartCache *pThis,
           ROMAddress *rpRequestedAddress, unsigned long rLength, void *pData){
 /* Installs a received ROM block in the cache and notifies waiting clients (cart.c). */
 CCacheEntry *pCacheEntry,
          *pOldCacheEntry,
      *prevPceTarget;
 int decompressed;
 CNotifyEntry *pNotify,
      *pDeleteEntry;
 void *pNotifyPtr;
 pfnCACHENOTIFY pfnDecompress;
 pfnCACHENOTIFY pfnBlockReceived;
 CCacheEntry **ppceTarget;
 pCacheEntry = func_8002CD74(pThis);
   if (pCacheEntry)
   {
  pOldCacheEntry = ((void*)0);
  if (func_8002E13C(&pThis->m_HashTable, rpRequestedAddress, (void**) &pOldCacheEntry))
      {
                                                    ;
         D_8002DE54(&pThis->m_HashTable, pOldCacheEntry->m_rpAddress);
         pOldCacheEntry->m_InHashTable = 0;
      }
      pCacheEntry->m_rpAddress = rpRequestedAddress;
      pCacheEntry->m_pData = pData;
      pCacheEntry->m_rLength = rLength;
  pCacheEntry->m_DataLength = rLength;
      pCacheEntry->m_InHashTable = 1;
  pCacheEntry->m_Compressed = 0;
      func_8002E098(&pThis->m_HashTable, rpRequestedAddress, pCacheEntry);
      if (pThis->m_pCacheHead)
         pThis->m_pCacheHead->m_pLast = pCacheEntry;
  if (!pThis->m_pCacheTail)
   pThis->m_pCacheTail = pCacheEntry;
      pCacheEntry->m_pLast = ((void*)0);
      pCacheEntry->m_pNext = pThis->m_pCacheHead;
      pThis->m_pCacheHead = pCacheEntry;
                                    ;
      decompressed = 0;
      pNotify = pThis->m_pNotifyHead;
      while (pNotify)
      {
         if ((pNotify->m_rpRequestedAddress == rpRequestedAddress) && (pNotify->m_rLength <= rLength))
         {
            pCacheEntry->m_szDescription = pNotify->m_szDescription;
            ppceTarget = pNotify->m_ppceTarget;
            pNotifyPtr = pNotify->m_pNotifyPtr;
            pfnDecompress = pNotify->m_pfnDecompress;
            pfnBlockReceived = pNotify->m_pfnBlockReceived;
            pDeleteEntry = pNotify;
            pNotify = pNotify->m_pNext;
            D_8002CCB8(pThis, pDeleteEntry);
    prevPceTarget = *ppceTarget;
            *ppceTarget = pCacheEntry;
            if (pCacheEntry->m_pData)
            {
               if ((!decompressed) && pfnDecompress)
     {
      pfnDecompress(pNotifyPtr, ppceTarget);
      decompressed = 1;
     }
     if (pCacheEntry->m_pData)
     {
      if (pfnBlockReceived)
       pfnBlockReceived(pNotifyPtr, ppceTarget);
     }
     else
     {
      *ppceTarget = prevPceTarget;
      D_8002DE54(&pThis->m_HashTable, pCacheEntry->m_rpAddress);
      pCacheEntry->m_InHashTable = 0;
     }
            }
         }
         else
         {
            pNotify = pNotify->m_pNext;
         }
      }
      if (!pCacheEntry->m_pData)
         D_8002CBEC(pThis, pCacheEntry);
   }
 else
 {
      pNotify = pThis->m_pNotifyHead;
      while (pNotify)
      {
         if ((pNotify->m_rpRequestedAddress == rpRequestedAddress) && (pNotify->m_rLength <= rLength))
         {
            pDeleteEntry = pNotify;
            pNotify = pNotify->m_pNext;
            D_8002CCB8(pThis, pDeleteEntry);
   }
  }
 }
}
