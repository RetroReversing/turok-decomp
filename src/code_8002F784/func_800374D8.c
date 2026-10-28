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
struct CIndexedSet_t;
typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;
extern void CIndexedSet__ConstructFromRawData(CIndexedSet *pThis, void *pData, int AutoDeleteData );
extern void* CIndexedSet__GetBlock(CIndexedSet *pThis, void *pBaseAddress, int nBlock);
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
extern void* CCacheEntry__GetData(CCacheEntry *pThis);
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
extern int func_800374D8(CGameAnimateState *pThis);
typedef struct CROMTransition_t
{
 unsigned short m_BlendFromLength,
    m_nExitToFrame,
    m_BlendStart,
    m_BlendFinish;
} CROMTransition;
struct CCacheEntry_t;
typedef struct CTextureLoader_t
{
 struct CCacheEntry_t *m_pceTextureSet;
 ROMAddress *m_rpTextureSet;
 unsigned long m_TextureSetSize;
} CTextureLoader;
int func_800374D8(CGameAnimateState *pThis);
int func_800374D8(CGameAnimateState *pThis){
 CIndexedSet isAnim,
       isTransitionTable;
 void *pbTransitionTable;
 CROMTransition *pTransition;
 int cNextFrame;
 cNextFrame = ((int) pThis->m_cFrame) + 1;
 if (cNextFrame >= pThis->m_nFrames)
 {
                          ;
  CIndexedSet__ConstructFromRawData(&isAnim,
              CCacheEntry__GetData(pThis->m_pceAnim),
              0);
  pbTransitionTable = CIndexedSet__GetBlock((&isAnim), (&isAnim)->m_pData, (5));
  CIndexedSet__ConstructFromRawData(&isTransitionTable, pbTransitionTable, 0);
  pTransition = (CROMTransition*) CIndexedSet__GetBlock((&isTransitionTable), (&isTransitionTable)->m_pData, (0));
  cNextFrame = pTransition->m_nExitToFrame;
                                ;
                                           ;
 }
                        ;
 return cNextFrame;
}
