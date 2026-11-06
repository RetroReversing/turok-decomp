#include "common.h"

typedef struct CUnindexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
   unsigned long m_CurrentAllocSize;
} CUnindexedSet;
extern void CUnindexedSet__SetBlockCount(CUnindexedSet *pThis, unsigned long BlockSize);
void CUnindexedSet__SetBlockCount(CUnindexedSet *pThis, unsigned long BlockSize);
void CUnindexedSet__SetBlockCount(CUnindexedSet *pThis, unsigned long BlockSize){
   unsigned long *pdwData;
 pdwData = (unsigned long*) pThis->m_pData;
   pdwData[1] = (BlockSize);
}
