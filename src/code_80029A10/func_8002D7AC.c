#include "common.h"

typedef struct CUnindexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
   unsigned long m_CurrentAllocSize;
} CUnindexedSet;
extern void func_8002D7AC(CUnindexedSet *pThis, void *pDest, int CopyBack);
void func_8002D7AC(CUnindexedSet *pThis, void *pDest, int CopyBack);
void func_8002D7AC(CUnindexedSet *pThis, void *pDest, int CopyBack){
 unsigned char *inBytes, *pOutPlace;
 int blockSize, blockCount,
   cSize, cBlock;
              ;
                                ;
                                                  ;
 inBytes = (unsigned char*) ( (void*) ( ((unsigned char*)((pThis)->m_pData)) + (2*sizeof(unsigned long)) ) );
 pOutPlace = (unsigned char*) pDest;
 func_8009FA50(pDest, pThis->m_pData, (2*sizeof(unsigned long)));
 pOutPlace += (2*sizeof(unsigned long));
 blockSize = ( (unsigned long) (((unsigned long*) (pThis)->m_pData)[0]) );
 blockCount = ( (unsigned long) (((unsigned long*) (pThis)->m_pData)[1]) );
 for (cBlock=0; cBlock<blockCount; cBlock++)
 {
  for (cSize=0; cSize<blockSize; cSize++)
  {
   *pOutPlace = inBytes[cSize*blockCount + cBlock];
   pOutPlace++;
  }
 }
 if (CopyBack)
  func_8009FA50(pThis->m_pData, pDest, (2*sizeof(unsigned long)) + blockCount*blockSize);
}
