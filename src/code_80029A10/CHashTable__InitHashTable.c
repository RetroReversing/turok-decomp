#include "common.h"

extern void *D_80011E98 (int size) ;
extern int D_80011DDC (void *address) ;
extern void memset(void *pDest, unsigned char Val, int Count);
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
void CHashTable__InitHashTable(CHashTable *pThis, unsigned long nHashSize, int bAllocNow );
void CHashTable__InitHashTable(CHashTable *pThis, unsigned long nHashSize, int bAllocNow ){
                                          ;
                             ;
                      ;
                                                 ;
 if (pThis->m_pHashTable != ((void*)0))
 {
  D_80011DDC(pThis->m_pHashTable);
  pThis->m_pHashTable = ((void*)0);
 }
 if (bAllocNow)
 {
  pThis->m_pHashTable = (CAssoc**) D_80011E98(sizeof(CAssoc*) * nHashSize);
  memset(pThis->m_pHashTable, 0, sizeof(CAssoc*) * nHashSize);
 }
 pThis->m_nHashTableSize = nHashSize;
}
