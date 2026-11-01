typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef unsigned int UINT;typedef void* HASHPOS;
typedef struct CAssoc_t {struct CAssoc_t*pNext;UINT nHashValue;void*key,*value;} CAssoc;
typedef struct CHashTable_t {CAssoc**m_pHashTable;UINT m_nHashTableSize;int m_nCount;CAssoc*m_pFreeList;void*m_pBlocks;int m_nBlockSize;} CHashTable;
#define ASSERT(x)
#define NULL ((void*)0)
#define BEFORE_START_HASHPOS ((HASHPOS)-1)

