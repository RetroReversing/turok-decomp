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
extern void func_8002E098(CHashTable *pThis, void* key, void* newValue);
extern void func_8002DFA0(CHashTable *pThis, unsigned long hashSize, int bAllocNow );
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
extern CAssoc* func_8002E020(CHashTable *pThis, void*, unsigned long*);
void func_8002DFA0(CHashTable *pThis, unsigned long nHashSize, int bAllocNow );
CAssoc* D_8002DEF0(CHashTable *pThis);
CAssoc* func_8002E020(CHashTable *pThis, void* key, unsigned long *pnHash);
void func_8002E098(CHashTable *pThis, void* key, void* newValue);
void func_8002E098(CHashTable *pThis, void* key, void* newValue){
 unsigned long nHash;
 CAssoc* pAssoc;
 if ((pAssoc = func_8002E020(pThis, key, &nHash)) == ((void*)0))
 {
  if (pThis->m_pHashTable == ((void*)0))
   func_8002DFA0(pThis, pThis->m_nHashTableSize, 1);
  pAssoc = D_8002DEF0(pThis);
  pAssoc->nHashValue = nHash;
  pAssoc->key = key;
  pAssoc->pNext = pThis->m_pHashTable[nHash];
  pThis->m_pHashTable[nHash] = pAssoc;
 }
 pAssoc->value = newValue;
}
