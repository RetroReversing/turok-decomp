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
extern CAssoc* func_8002E020(CHashTable *pThis, void*, unsigned long*);
CAssoc* func_8002E020(CHashTable *pThis, void* key, unsigned long *pnHash);
CAssoc* func_8002E020(CHashTable *pThis, void* key, unsigned long *pnHash){
 CAssoc *pAssoc;
 *pnHash = (((unsigned long)(void*)(unsigned long)(void*)key) >> 4) % pThis->m_nHashTableSize;
 if (pThis->m_pHashTable == ((void*)0))
  return ((void*)0);
 for (pAssoc = pThis->m_pHashTable[*pnHash]; pAssoc != ((void*)0); pAssoc = pAssoc->pNext)
 {
  if (pAssoc->key == key)
   return pAssoc;
 }
 return ((void*)0);
}
