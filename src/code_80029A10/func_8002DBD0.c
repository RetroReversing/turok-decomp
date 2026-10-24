#include "common.h"

struct CIndexedSet_t;
typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;
extern unsigned long func_8002DBD0(CIndexedSet *pThis, const int nBlock, unsigned long *pLength);
unsigned long func_8002DBD0(CIndexedSet *pThis, const int nBlock, unsigned long *pLength);
unsigned long func_8002DBD0(CIndexedSet *pThis, const int nBlock, unsigned long *pLength){
 unsigned long *offsets;
                         ;
                      ;
                                                     ;
                  ;
   offsets = (unsigned long*) (((unsigned char*) pThis->m_pData) + (1*sizeof(unsigned long)));
   *pLength = (offsets[nBlock+1]) - (offsets[nBlock]);
   return (offsets[nBlock]);
}
