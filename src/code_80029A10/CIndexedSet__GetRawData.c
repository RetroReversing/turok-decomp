#include "common.h"

struct CIndexedSet_t;
typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;
extern void CIndexedSet__GetRawData(CIndexedSet *pThis, void **ppData, unsigned long *pSize);
void CIndexedSet__GetRawData(CIndexedSet *pThis, void **ppData, unsigned long *pSize);
void CIndexedSet__GetRawData(CIndexedSet *pThis, void **ppData, unsigned long *pSize){
                         ;
                 ;
                ;
   *ppData = (void*) pThis->m_pData;
   *pSize = (((unsigned long*) ((pThis)->m_pData))[1 + (((unsigned long*) (pThis)->m_pData)[0])]);
}
