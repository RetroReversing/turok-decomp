#include "common.h"

typedef struct CUnindexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
   unsigned long m_CurrentAllocSize;
} CUnindexedSet;
struct CIndexedSet_t;
extern void CUnindexedSet__ConstructFromRawData(CUnindexedSet *pThis,
               void *pData, int AutoDeleteData );
typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;
extern void* CIndexedSet__GetAddress(CIndexedSet *pThis, void *pBaseAddress, int nBlock);
typedef struct CROMNodeIndex_t
{
 short m_nTranslationSet,
    m_nRotationSet;
} CROMNodeIndex;
extern CROMNodeIndex CGameObjectInstance__GetNodeAnimIndex(CIndexedSet *pisAnim, int nNode);
CROMNodeIndex CGameObjectInstance__GetNodeAnimIndex(CIndexedSet *pisAnim, int nNode);
CROMNodeIndex CGameObjectInstance__GetNodeAnimIndex(CIndexedSet *pisAnim, int nNode){
 void *pbNodeAnimIndices;
 CUnindexedSet usNodeAnimIndices;
 CROMNodeIndex *pNodeAnimIndices;
 pbNodeAnimIndices = CIndexedSet__GetAddress((pisAnim), (pisAnim)->m_pData, (1));
 CUnindexedSet__ConstructFromRawData(&usNodeAnimIndices, pbNodeAnimIndices, 0);
                                                                 ;
 pNodeAnimIndices = (CROMNodeIndex*) ( (void*) ( ((unsigned char*)((&usNodeAnimIndices)->m_pData)) + (2*sizeof(unsigned long)) ) );
                                            ;
 return pNodeAnimIndices[nNode];
}
