#include "common.h"

typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 unsigned char cn[4];
} Vtx_t;
typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 signed char n[3];
 unsigned char a;
} Vtx_tn;
typedef union {
    Vtx_t v;
    Vtx_tn n;
    long long int force_structure_alignment;
} Vtx;
extern unsigned long D_800B6AF0;
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
typedef ROMAddress;
struct CIndexedSet_t;
typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;
extern void CIndexedSet__ConstructFromRawData(CIndexedSet *pThis, void *pData, int AutoDeleteData );
extern void* CIndexedSet__GetBlock(CIndexedSet *pThis, void *pBaseAddress, int nBlock);
struct CCartCache_t;
typedef struct CCacheEntry_t
{
   void *m_pData;
 unsigned long m_DataLength;
   ROMAddress *m_rpAddress;
   unsigned long m_rLength;
 struct CCartCache_t *m_pOwner;
 unsigned long m_LastAccessed;
   int m_InHashTable,
      m_Compressed;
 unsigned long m_Allocated;
   const char *m_szDescription;
   struct CCacheEntry_t *m_pLast, *m_pNext,
         *m_pNextFree;
} CCacheEntry;
extern void* CCacheEntry__GetData(CCacheEntry *pThis);
typedef void (*pfnCACHENOTIFY)(void *pNotifyPtr, CCacheEntry **ppceTarget);
typedef struct CNotifyEntry_t
{
   void *m_pNotifyPtr;
   pfnCACHENOTIFY m_pfnDecompress,
                  m_pfnBlockReceived;
   CCacheEntry **m_ppceTarget;
   ROMAddress *m_rpRequestedAddress;
   unsigned long m_rLength;
   const char *m_szDescription;
   struct CNotifyEntry_t *m_pLast, *m_pNext,
         *m_pNextFree;
} CNotifyEntry;
typedef struct CCartCache_t
{
   CHashTable m_HashTable;
   CNotifyEntry *m_pNotifyHead, *m_pNotifyTail;
   CCacheEntry *m_pCacheHead, *m_pCacheTail;
   int m_DiscardAge;
 CCacheEntry m_CacheEntries[512];
 CCacheEntry *m_pCacheFreeHead;
 CNotifyEntry m_NotifyEntries[16];
 CNotifyEntry *m_pNotifyFreeHead;
} CCartCache;
typedef struct CGeometry_t
{
 CCacheEntry *m_pceGeometry,
         *m_pceTextureSetsIndex;
} CGeometry;
extern void CGeometry__Morph(CGeometry *pThis, int nNode, float Frame);
struct CCacheEntry_t;
typedef struct CTextureLoader_t
{
 struct CCacheEntry_t *m_pceTextureSet;
 ROMAddress *m_rpTextureSet;
 unsigned long m_TextureSetSize;
} CTextureLoader;
typedef struct CGameGeometryInfo_t
{
 unsigned long m_MorphFrameNumber;
 float m_cMorph;
} CGameGeometryInfo;
extern unsigned long D_800B6AF0;
extern unsigned long D_800B6AF4;
void CGeometry__Morph(CGeometry *pThis, int nNode, float Frame);
void CGeometry__Morph(CGeometry *pThis, int nNode, float Frame){
 /* Blend two geometry frames into the destination vertex and normal buffers once per game frame. */
 CIndexedSet isGeometry,
        isNodes, isNode,
        isParts, isFramePart[2], isDestPart,
        isSection[2], isDestSection;
 CGameGeometryInfo *pInfo;
 void *pbNodes, *pbNode,
        *pbParts, *pbPart,
        *pbSection, *pbData;
 int nParts,
        cSection, nDestSections, nSections[2],
        nDestVertices, nVertices[2], cVert;
 float fraction;
 int frame,
        i,
        c1, c2,
        s1, s2;
 Vtx *destVertices, *pDestVert,
        *vertices[2], *pV1, *pV2;
 if (!pThis->m_pceGeometry)
  return;
 CIndexedSet__ConstructFromRawData(&isGeometry,
             CCacheEntry__GetData(pThis->m_pceGeometry),
             0);
 pInfo = (CGameGeometryInfo*) CIndexedSet__GetBlock((&isGeometry), (&isGeometry)->m_pData, (0));
 if (pInfo->m_MorphFrameNumber != D_800B6AF0)
 {
  pInfo->m_MorphFrameNumber = D_800B6AF0;
  pbNodes = CIndexedSet__GetBlock((&isGeometry), (&isGeometry)->m_pData, (1));
  CIndexedSet__ConstructFromRawData(&isNodes, pbNodes, 0);
  if (nNode < (((unsigned long*) (&isNodes)->m_pData)[0]))
  {
   pbNode = CIndexedSet__GetBlock((&isNodes), (&isNodes)->m_pData, (nNode));
   CIndexedSet__ConstructFromRawData(&isNode, pbNode, 0);
     pbParts = CIndexedSet__GetBlock((&isNode), (&isNode)->m_pData, (2));
   CIndexedSet__ConstructFromRawData(&isParts, pbParts, 0);
   nParts = (((unsigned long*) (&isParts)->m_pData)[0]);
   if (nParts >= 3)
   {
    pbPart = CIndexedSet__GetBlock((&isParts), (&isParts)->m_pData, (D_800B6AF4));
    CIndexedSet__ConstructFromRawData(&isDestPart, pbPart, 0);
    nDestSections = (((unsigned long*) (&isDestPart)->m_pData)[0]);
    while (Frame < 0)
     Frame += nParts - 2;
    while (Frame >= (nParts - 2))
     Frame -= nParts - 2;
    pInfo->m_cMorph = Frame;
    fraction = Frame - (int) Frame;
    c2 = (int) (fraction*256);
    c1 = 256 - c2;
    s2 = (int) (fraction*65536);
    s1 = 65536 - s2;
    for (i=0; i<2; i++)
    {
     frame = ((((int) Frame) + i) % (nParts - 2)) + 2;
     pbPart = CIndexedSet__GetBlock((&isParts), (&isParts)->m_pData, (frame));
     CIndexedSet__ConstructFromRawData(&isFramePart[i], pbPart, 0);
     nSections[i] = (((unsigned long*) (&isFramePart[i])->m_pData)[0]);
    }
    if ((nSections[0] == nDestSections) && (nSections[1] == nDestSections))
    {
     for (cSection=0; cSection<nDestSections; cSection++)
     {
      pbSection = CIndexedSet__GetBlock((&isDestPart), (&isDestPart)->m_pData, (cSection));
      CIndexedSet__ConstructFromRawData(&isDestSection, pbSection, 0);
      pbData = CIndexedSet__GetBlock((&isDestSection), (&isDestSection)->m_pData, (1));
      nDestVertices = *((unsigned long*) pbData);
      destVertices = (Vtx*) *(((unsigned long*) pbData) + 1);
      for (i=0; i<2; i++)
      {
       pbSection = CIndexedSet__GetBlock((&isFramePart[i]), (&isFramePart[i])->m_pData, (cSection));
       CIndexedSet__ConstructFromRawData(&isSection[i], pbSection, 0);
       pbData = CIndexedSet__GetBlock((&isSection[i]), (&isSection[i])->m_pData, (1));
       nVertices[i] = *((unsigned long*) pbData);
       vertices[i] = (Vtx*) *(((unsigned long*) pbData) + 1);
      }
      if ((nVertices[0] == nDestVertices) && (nVertices[1] == nDestVertices))
      {
       for (cVert=0; cVert<nDestVertices; cVert++)
       {
        pDestVert = &destVertices[cVert];
        pV1 = &vertices[0][cVert];
        pV2 = &vertices[1][cVert];
        pDestVert->n.ob[0] = ((short) ((((pV1->n.ob[0])*(int)(s1)) + ((pV2->n.ob[0])*(int)(s2))) >> 16));
        pDestVert->n.ob[1] = ((short) ((((pV1->n.ob[1])*(int)(s1)) + ((pV2->n.ob[1])*(int)(s2))) >> 16));
        pDestVert->n.ob[2] = ((short) ((((pV1->n.ob[2])*(int)(s1)) + ((pV2->n.ob[2])*(int)(s2))) >> 16));
        pDestVert->n.n[0] = ((signed char) ((((pV1->n.n[0])*(int)(c1)) + ((pV2->n.n[0])*(int)(c2))) >> 8));
        pDestVert->n.n[1] = ((signed char) ((((pV1->n.n[1])*(int)(c1)) + ((pV2->n.n[1])*(int)(c2))) >> 8));
        pDestVert->n.n[2] = ((signed char) ((((pV1->n.n[2])*(int)(c1)) + ((pV2->n.n[2])*(int)(c2))) >> 8));
       }
      }
                                           ;
                                          ;
                                          ;
     }
    }
                                      ;
                                          ;
                                          ;
   }
                                  ;
                                 ;
  }
                                 ;
 }
                                   ;
}
