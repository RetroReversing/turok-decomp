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
struct CIndexedSet_t;
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
typedef struct CGeometry_t
{
 CCacheEntry *m_pceGeometry,
         *m_pceTextureSetsIndex;
} CGeometry;
extern void func_80021BC0(CGeometry *pThis, int nNode, float Frame);
extern void func_800220BC(CGeometry *pThis, int nNode, float Increment);
struct CCacheEntry_t;
typedef struct CTextureLoader_t
{
 struct CCacheEntry_t *m_pceTextureSet;
 ROMAddress *m_rpTextureSet;
 unsigned long m_TextureSetSize;
} CTextureLoader;
typedef struct CGameGeometryInfo_t
{
 unsigned long m_MorphFrameNumber;
 float m_cMorph;
} CGameGeometryInfo;
extern unsigned long D_800B6AF0;
void func_800220BC(CGeometry *pThis, int nNode, float Increment);
void func_80021BC0(CGeometry *pThis, int nNode, float Frame);
void func_800220BC(CGeometry *pThis, int nNode, float Increment){
 CIndexedSet isGeometry;
 CGameGeometryInfo *pInfo;
 if (!pThis->m_pceGeometry)
  return;
 func_8002DD28(&isGeometry,
             func_8002D690(pThis->m_pceGeometry),
             0);
 pInfo = (CGameGeometryInfo*) D_8002DC68((&isGeometry), (&isGeometry)->m_pData, (0));
 if (pInfo->m_MorphFrameNumber != D_800B6AF0)
 {
  pInfo->m_cMorph += Increment;
  func_80021BC0(pThis, nNode, pInfo->m_cMorph);
 }
                                   ;
}
