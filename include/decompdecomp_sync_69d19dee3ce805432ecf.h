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
#define CACHE_BLOCK_VERSION_MASK 1
#define ASSERT(x)
#define TRACE0(x)
#define TRACE2(a,b,c)
#define TRACE3(a,b,c,d)
#define TRACE4(a,b,c,d,e)
void func_8002D410(CCartCache*,CCacheEntry*);
void*func_8002D648(CCacheEntry*,DWORD,BOOL);
BOOL func_8002C9C0(void*,void*);
void func_80011DDC(void*);
void func_8002E254(CHashTable*,int);
void func_8002DFA0(CHashTable*,UINT,BOOL);
BOOL func_8002E13C(CHashTable*,void*,void**);
CNotifyEntry*func_8002D1D0(CCartCache*);
void*func_8002D120(CCartCache*,DWORD,BOOL);
void func_8002D020(CCartCache*,CNotifyEntry*);
void CCartCache__BlockReceived(CCartCache*,ROMAddress*,DWORD,void*);
void func_8002CAE0(void*,ROMAddress*,DWORD);
#define CCacheEntry__ResetAge(p) func_8002D410((p)->m_pOwner,(p))
#define CCacheEntry__GetData(p) (CCacheEntry__ResetAge(p),(p)->m_pData)
#define CCacheEntry__DoAllocDataForReplacement func_8002D648
#define CMP_GetDecompressedSize(p) (((DWORD*)(p))[1])
#define CMP_DecompressData func_8002C9C0
#define DEALLOC(p) func_80011DDC(p)
#define CCacheEntry__DeallocAndReplaceData(p,b,n) (DEALLOC((p)->m_pData),(p)->m_pData=(b),(p)->m_DataLength=(n))
#define CHashTable__Construct func_8002E254
#define CHashTable__InitHashTable func_8002DFA0
#define CHashTable__Lookup func_8002E13C
#define CCartCache__AllocNotifyEntry func_8002D1D0
#define CCartCache__Alloc func_8002D120
#define CCartCache__DeallocNotifyEntry func_8002D020
#define BrokenUpDMA func_8002CAE0


