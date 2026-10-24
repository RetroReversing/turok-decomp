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
typedef ROMAddress;
typedef struct CUnindexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
   unsigned long m_CurrentAllocSize;
} CUnindexedSet;
struct CIndexedSet_t;
extern void func_8002DA8C(CUnindexedSet *pThis,
               void *pData, int AutoDeleteData );
typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;
extern void func_8002DD28(CIndexedSet *pThis, void *pData, int AutoDeleteData );
extern void* D_8002DC68(CIndexedSet *pThis, void *pBaseAddress, int nBlock);
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
extern void* func_8002D690(CCacheEntry *pThis);
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
typedef struct CGameAnimateState_t
{
 CCacheEntry *m_pceAnim;
 unsigned long m_nAnim,
      m_nDesiredAnim,
      m_nFrames;
 float m_cFrame;
 int m_CycleCompleted;
} CGameAnimateState;
extern int func_80037564(CGameAnimateState *pThis);
typedef struct CROMTransitionEntry_t
{
 unsigned long m_nRequestedAnim,
    m_nWaitForFrame,
    m_nDeliveredAnim;
} CROMTransitionEntry;
struct CCacheEntry_t;
typedef struct CTextureLoader_t
{
 struct CCacheEntry_t *m_pceTextureSet;
 ROMAddress *m_rpTextureSet;
 unsigned long m_TextureSetSize;
} CTextureLoader;
extern float D_800B6B00;
int func_80037564(CGameAnimateState *pThis);
int func_80037564(CGameAnimateState *pThis){
 CIndexedSet isAnim,
        isTransitionTable;
 void *pbTransitionTable,
        *pbTransitionEntries;
 CUnindexedSet usTableEntries;
 int deliveredAnim,
        cEntry, nEntries;
 CROMTransitionEntry *pTransitionEntries,
        *pEntry, *pCurrentEntry;
                                    ;
                                    ;
                                   ;
 if (1)
   {
                          ;
  func_8002DD28(&isAnim,
              func_8002D690(pThis->m_pceAnim),
              0);
  pbTransitionTable = D_8002DC68((&isAnim), (&isAnim)->m_pData, (5));
  func_8002DD28(&isTransitionTable, pbTransitionTable, 0);
  pbTransitionEntries = D_8002DC68((&isTransitionTable), (&isTransitionTable)->m_pData, (1));
  func_8002DA8C(&usTableEntries, pbTransitionEntries, 0);
  pEntry = ((void*)0);
  pTransitionEntries = (CROMTransitionEntry*) ( (void*) ( ((unsigned char*)((&usTableEntries)->m_pData)) + (2*sizeof(unsigned long)) ) );
  nEntries = ( (unsigned long) (((unsigned long*) (&usTableEntries)->m_pData)[1]) );
  for (cEntry=0; cEntry<nEntries; cEntry++)
  {
   pCurrentEntry = &pTransitionEntries[cEntry];
   if (pCurrentEntry->m_nRequestedAnim == pThis->m_nDesiredAnim)
   {
    pEntry = pCurrentEntry;
    break;
   }
  }
      if (pEntry)
      {
   if ((pEntry->m_nWaitForFrame == ((unsigned long) -1))
     || ((pThis->m_cFrame >= pEntry->m_nWaitForFrame)
        && (pThis->m_cFrame < (pEntry->m_nWaitForFrame + D_800B6B00))) )
         {
            deliveredAnim = pEntry->m_nDeliveredAnim;
         }
   else
   {
    deliveredAnim = -1;
   }
      }
      else
  {
   if (pThis->m_nDesiredAnim == pThis->m_nAnim)
   {
    deliveredAnim = -1;
   }
   else
   {
    deliveredAnim = pThis->m_nDesiredAnim;
                                      ;
   }
  }
                                ;
                                           ;
                                          ;
   }
 return deliveredAnim;
}
