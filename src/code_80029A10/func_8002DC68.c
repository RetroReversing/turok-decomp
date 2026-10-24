#include "common.h"

struct CIndexedSet_t;
typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;
extern void* func_8002DC68(CIndexedSet *pThis, void *pBaseAddress, int nBlock);
void* func_8002DC68(CIndexedSet *pThis, void *pBaseAddress, int nBlock);
void* func_8002DC68(CIndexedSet *pThis, void *pBaseAddress, int nBlock){
   unsigned long offset;
   offset = (((unsigned long*) ((pThis)->m_pData))[1 + (nBlock)]);
   return (void*) (((unsigned long) pBaseAddress) + offset);
}
