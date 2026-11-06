#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"
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
extern void CHashTable__SetAt(CHashTable *pThis, void* key, void* newValue);
extern void CHashTable__InitHashTable(CHashTable *pThis, unsigned long hashSize, int bAllocNow );
typedef struct CHashPlex_t
{
 struct CHashPlex_t *pNext;
 unsigned long nMax,
              nCur;
} CHashPlex;
typedef struct CAssoc_t
{
 struct CAssoc_t *pNext;
 unsigned long nHashValue;
 void *key;
 void *value;
} CAssoc;
extern CAssoc* D_8002DEF0(CHashTable *pThis);
extern CAssoc* CHashTable__GetAssocAt(CHashTable *pThis, void*, unsigned long*);
void CHashTable__InitHashTable(CHashTable *pThis, unsigned long nHashSize, int bAllocNow );
CAssoc* D_8002DEF0(CHashTable *pThis);
CAssoc* CHashTable__GetAssocAt(CHashTable *pThis, void* key, unsigned long *pnHash);
void CHashTable__SetAt(CHashTable *pThis, void* key, void* newValue);
void CHashTable__SetAt(CHashTable *pThis, void* key, void* newValue){
 unsigned long nHash;
 CAssoc* pAssoc;
 if ((pAssoc = CHashTable__GetAssocAt(pThis, key, &nHash)) == ((void*)0))
 {
  if (pThis->m_pHashTable == ((void*)0))
   CHashTable__InitHashTable(pThis, pThis->m_nHashTableSize, 1);
  pAssoc = D_8002DEF0(pThis);
  pAssoc->nHashValue = nHash;
  pAssoc->key = key;
  /* 'pAssoc->value' is a constructed object, nothing more */ /* put into hash table */ pAssoc->pNext = pThis->m_pHashTable[nHash];
  pThis->m_pHashTable[nHash] = pAssoc;
 }
 /* set new value */ pAssoc->value = newValue;
}
