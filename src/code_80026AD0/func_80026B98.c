#include "common.h"

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
extern void* D_8002DC3C(CIndexedSet *pThis, void *pBaseAddress, int nBlock, unsigned long *pLength);
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
extern int D_8002D6BC(CCacheEntry *pThis, int AllocTop);
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
struct CROMTextureFormat_t;
struct CCacheEntry_t;
typedef struct CTextureInfo_t
{
 int m_nBitmaps,
          m_nPalettes;
 struct CROMTextureFormat_t *m_pFormat;
} CTextureInfo;
typedef struct CTextureLoader_t
{
 struct CCacheEntry_t *m_pceTextureSet;
 ROMAddress *m_rpTextureSet;
 unsigned long m_TextureSetSize;
} CTextureLoader;
typedef struct CROMTextureFormat_t
{
 unsigned char m_Format,
    m_PlaybackSpeed,
    m_WidthShift,
    m_HeightShift,
    m_Effect,
    m_EffectMode;
} CROMTextureFormat;
extern void func_80026B98(CTextureLoader *pThis, CCacheEntry **ppceTarget);
void func_80026B98(CTextureLoader *pThis, CCacheEntry **ppceTarget);
void func_80026B98(CTextureLoader *pThis, CCacheEntry **ppceTarget){
 CIndexedSet isTextureSet,
       isPalettes;
 void *pbPalettes, *pbPalette;
 CROMTextureFormat *pFormat;
 int cPalette, nPalettes,
       cColor, nColors;
 unsigned long paletteSize;
 unsigned short *colors, *pColor;
 unsigned int r, g, b, a;
                                              ;
 if (!D_8002D6BC(pThis->m_pceTextureSet, 0))
  return;
 if ((((unsigned long)(((pThis->m_pceTextureSet)->m_rpAddress))) >> 30))
 {
  CIndexedSet__ConstructFromRawData(&isTextureSet,
              CCacheEntry__GetData(pThis->m_pceTextureSet),
              0);
  pFormat = (CROMTextureFormat*) CIndexedSet__GetBlock((&isTextureSet), (&isTextureSet)->m_pData, (0));
  switch (pFormat->m_Format)
  {
   case 0:
   case 1:
    pbPalettes = CIndexedSet__GetBlock((&isTextureSet), (&isTextureSet)->m_pData, (2));
    CIndexedSet__ConstructFromRawData(&isPalettes, pbPalettes, 0);
    nPalettes = (((unsigned long*) (&isPalettes)->m_pData)[0]);
    for (cPalette=0; cPalette<nPalettes; cPalette++)
    {
     pbPalette = D_8002DC3C((&isPalettes), (&isPalettes)->m_pData, (cPalette), (&paletteSize));
     colors = (unsigned short*) pbPalette;
     nColors = paletteSize/sizeof(unsigned short);
     for (cColor=0; cColor<nColors; cColor++)
     {
      pColor = &colors[cColor];
      r = ((*pColor) >> 8) & 0xf8;
      g = ((*pColor) >> 3) & 0xf8;
      b = ((*pColor) << 2) & 0xf8;
      a = (*pColor) & 0x01;
      *pColor = (unsigned short) ((g << 8)
            | (r << 3)
            | (b >> 2)
            | a);
     }
    }
                                      ;
    break;
  }
                                      ;
 }
}
