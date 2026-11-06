#include "common.h"

typedef ROMAddress;
struct CIndexedSet_t;
typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;
extern ROMAddress* CIndexedSet__GetROMAddress(CIndexedSet *pThis,
                                       ROMAddress *rpBaseAddress, int nBlock);
ROMAddress* CIndexedSet__GetROMAddress(CIndexedSet *pThis,
                                       ROMAddress *rpBaseAddress, int nBlock);
ROMAddress* CIndexedSet__GetROMAddress(CIndexedSet *pThis,
                                       ROMAddress *rpBaseAddress, int nBlock){
   unsigned long offset;
   offset = (((unsigned long*) ((pThis)->m_pData))[1 + (nBlock)]);
   return (ROMAddress*) (((unsigned long) rpBaseAddress) + offset);
}
