#include "common.h"

typedef struct CUnindexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
   unsigned long m_CurrentAllocSize;
} CUnindexedSet;
struct CIndexedSet_t;
extern void func_8002DA8C(CUnindexedSet *pThis,
               void *pData, int AutoDeleteData );
typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;
extern void* D_8002DC68(CIndexedSet *pThis, void *pBaseAddress, int nBlock);
typedef struct CROMNodeIndex_t
{
 short m_nTranslationSet,
    m_nRotationSet;
} CROMNodeIndex;
extern CROMNodeIndex func_8001697C(CIndexedSet *pisAnim, int nNode);
CROMNodeIndex func_8001697C(CIndexedSet *pisAnim, int nNode);
CROMNodeIndex func_8001697C(CIndexedSet *pisAnim, int nNode){
 void *pbNodeAnimIndices;
 CUnindexedSet usNodeAnimIndices;
 CROMNodeIndex *pNodeAnimIndices;
 pbNodeAnimIndices = D_8002DC68((pisAnim), (pisAnim)->m_pData, (1));
 func_8002DA8C(&usNodeAnimIndices, pbNodeAnimIndices, 0);
                                                                 ;
 pNodeAnimIndices = (CROMNodeIndex*) ( (void*) ( ((unsigned char*)((&usNodeAnimIndices)->m_pData)) + (2*sizeof(unsigned long)) ) );
                                            ;
 return pNodeAnimIndices[nNode];
}
