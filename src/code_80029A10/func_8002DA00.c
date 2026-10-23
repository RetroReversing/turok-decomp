#include "common.h"

typedef struct CUnindexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
   unsigned long m_CurrentAllocSize;
} CUnindexedSet;
extern void func_8002DA00(CUnindexedSet *pThis, unsigned long BlockSize);
void func_8002DA00(CUnindexedSet *pThis, unsigned long BlockSize);
void func_8002DA00(CUnindexedSet *pThis, unsigned long BlockSize){
   unsigned long *pdwData;
 pdwData = (unsigned long*) pThis->m_pData;
   pdwData[1] = (BlockSize);
}
