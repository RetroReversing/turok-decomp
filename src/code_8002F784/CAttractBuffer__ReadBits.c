#include "common.h"

typedef struct CAttractBuffer_t
{
 unsigned long m_Value ;
 unsigned char *m_pData ;
 unsigned long m_CurrentBit ;
 signed long m_Frames ;
 void (*m_pReadFunction)(void *pThis) ;
 void (*m_pWriteFunction)(void *pThis) ;
 unsigned long (*m_pGetValueFunction)(void *pThis) ;
} CAttractBuffer ;
unsigned long CAttractBuffer__ReadBit(CAttractBuffer *pThis);
unsigned long CAttractBuffer__ReadBits(CAttractBuffer *pThis, unsigned long Bits);
unsigned long CAttractBuffer__ReadBits(CAttractBuffer *pThis, unsigned long Bits){
 unsigned long Data = 0 ;
 while(Bits--)
 {
  Data <<= 1 ;
  Data |= CAttractBuffer__ReadBit(pThis) ;
 }
 return Data ;
}
