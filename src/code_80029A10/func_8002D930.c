#include "common.h"

typedef struct CUnindexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
   unsigned long m_CurrentAllocSize;
} CUnindexedSet;
extern unsigned long func_8002D930(CUnindexedSet *pThis);
unsigned long func_8002D930(CUnindexedSet *pThis);
unsigned long func_8002D930(CUnindexedSet *pThis){
 return (2*sizeof(unsigned long)) + ( (unsigned long) (((unsigned long*) (pThis)->m_pData)[0]) )*( (unsigned long) (((unsigned long*) (pThis)->m_pData)[1]) );
}
