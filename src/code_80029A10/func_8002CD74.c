#include "common.h"

extern unsigned long D_800B6AF0;
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
extern unsigned long D_800B6AF0;
extern CCacheEntry* func_8002CD74(CCartCache *pThis);
extern int func_8002CD18(CCartCache *pThis);
int func_8002CD18(CCartCache *pThis);
CCacheEntry* func_8002CD74(CCartCache *pThis);
CCacheEntry* func_8002CD74(CCartCache *pThis){
 CCacheEntry *pEntry;
 if (!pThis->m_pCacheFreeHead)
 {
  if (func_8002CD18(pThis))
  {
                                  ;
                                                                                                    ;
  }
  else
  {
                                                                 ;
   return ((void*)0);
  }
 }
 pEntry = pThis->m_pCacheFreeHead;
 pThis->m_pCacheFreeHead = pThis->m_pCacheFreeHead->m_pNextFree;
                                                      ;
 pEntry->m_Allocated = 489554;
 pEntry->m_pOwner = pThis;
 pEntry->m_LastAccessed = D_800B6AF0;
 return pEntry;
}
