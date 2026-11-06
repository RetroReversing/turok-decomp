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
unsigned long ReadBit(unsigned char *pData, unsigned long Bit);
unsigned long CAttractBuffer__ReadBit(CAttractBuffer *pThis);
unsigned long CAttractBuffer__ReadBit(CAttractBuffer *pThis){
 return ReadBit(pThis->m_pData, pThis->m_CurrentBit++) ;
}
