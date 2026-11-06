typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL,ROMAddress;typedef unsigned long DWORD;typedef unsigned int UINT;typedef unsigned char BYTE;
typedef struct CHashTable_t
{
	struct CAssoc_t      **m_pHashTable;
	UINT                 m_nHashTableSize;
	int                  m_nCount;
	struct CAssoc_t      *m_pFreeList;
	struct CHashPlex_t   *m_pBlocks;
	int                  m_nBlockSize;
} CHashTable;
typedef struct CCacheEntry_t
{
   void           *m_pData;         // address of data in memory
	DWORD				m_DataLength;		// length of data in memory

   ROMAddress     *m_rpAddress;     // address of requested data
   DWORD          m_rLength;        // length of requested data

	struct CCartCache_t	*m_pOwner;			// cart cache that this cache entry belongs to

	//int            m_Age;            // age cycles left
	DWORD				m_LastAccessed;	// last used frame number
   BOOL           m_InHashTable,    // cache entries can be in linked list, but not hash table
						m_Compressed;		// if TRUE, object has been compressed and is waiting to discard

#define CACHEENTRY_ALLOCATED 		489554
#define CACHEENTRY_UNALLOCATED 	89355
	DWORD				m_Allocated;		// for debugging
   const char     *m_szDescription; // for debugging

   struct CCacheEntry_t 	*m_pLast, *m_pNext,	// in use list
									*m_pNextFree;			// free list
} CCacheEntry;
typedef void (*pfnCACHENOTIFY)(void*,CCacheEntry**);
typedef struct CNotifyEntry_t
{
   void           *m_pNotifyPtr;          // pointer to pass to callback functions
   pfnCACHENOTIFY m_pfnDecompress,        // give to requester to decompress block
                                          // to use, ALLOC() new block, then call CCacheEntry__DeleteAndReplaceData()
                  m_pfnBlockReceived;     // notifies requester that block is ready

   CCacheEntry    **m_ppceTarget;         // address of pointer to copy cache entry address to when data arrives

   ROMAddress     *m_rpRequestedAddress;  // address of data requested from cardridge
   DWORD          m_rLength;              // length of requested data
   const char     *m_szDescription;       // for debugging

   struct CNotifyEntry_t 	*m_pLast, *m_pNext,	// in use list
									*m_pNextFree;			// free list
} CNotifyEntry;
#define CARTCACHE_CACHEENTRY_COUNT 512
#define CARTCACHE_NOTIFYENTRY_COUNT 16
typedef struct CCartCache_t
{
   CHashTable     m_HashTable;
   CNotifyEntry   *m_pNotifyHead, *m_pNotifyTail;
   CCacheEntry    *m_pCacheHead, *m_pCacheTail;
   int            m_DiscardAge;

	CCacheEntry		m_CacheEntries[CARTCACHE_CACHEENTRY_COUNT];
	CCacheEntry		*m_pCacheFreeHead;

	CNotifyEntry	m_NotifyEntries[CARTCACHE_NOTIFYENTRY_COUNT];
	CNotifyEntry	*m_pNotifyFreeHead;

} CCartCache;

#define NULL ((void*)0)
#define TRUE 1
#define FALSE 0
#define SHIP_IT 1
#define HASH_ALLOC_BLOCK 512
#define HASH_TABLE_SIZE 473
#define CACHE_BLOCK_VERSION_MASK 0xc0000000
#define ASSERT(x)
#define TRACE0(x)
#define TRACE2(a,b,c)
#define TRACE3(a,b,c,d)
#define TRACE4(a,b,c,d,e)
void CCartCache__ResetAge(CCartCache*,CCacheEntry*);
void*CCacheEntry__DoAllocDataForReplacement(CCacheEntry*,DWORD,BOOL);
BOOL CMP_DecompressData(void*,void*);
void i3D_free(void*);
void CHashTable__Construct(CHashTable*,int);
void CHashTable__InitHashTable(CHashTable*,UINT,BOOL);
BOOL CHashTable__Lookup(CHashTable*,void*,void**);
CNotifyEntry*CCartCache__AllocNotifyEntry(CCartCache*);
void*CCartCache__Alloc(CCartCache*,DWORD,BOOL);

void CCartCache__BlockReceived(CCartCache*,ROMAddress*,DWORD,void*);
void BrokenUpDMA(void*,ROMAddress*,DWORD);
#define CCacheEntry__ResetAge(p) CCartCache__ResetAge((p)->m_pOwner,(p))

#define CCacheEntry__DoAllocDataForReplacement CCacheEntry__DoAllocDataForReplacement

#define CMP_DecompressData CMP_DecompressData
#define DEALLOC(p) i3D_free(p)

#define CHashTable__Construct CHashTable__Construct
#define CHashTable__InitHashTable CHashTable__InitHashTable
#define CHashTable__Lookup CHashTable__Lookup
#define CCartCache__AllocNotifyEntry CCartCache__AllocNotifyEntry
#define CCartCache__Alloc CCartCache__Alloc

#define BrokenUpDMA BrokenUpDMA
static void CCartCache__DeallocNotifyEntry(CCartCache *pThis, CNotifyEntry *pEntry)
{
	ASSERT(pEntry);

	pEntry->m_pNextFree = pThis->m_pNotifyFreeHead;
	pThis->m_pNotifyFreeHead = pEntry;

                
                                                             
      
}

static void* CCacheEntry__GetData(CCacheEntry *pThis);
static void CCacheEntry__DeallocAndReplaceData(CCacheEntry *pThis, void *pNewData, DWORD NewLength);


static DWORD CMP_GetDecompressedSize(void *pCompressedData);
