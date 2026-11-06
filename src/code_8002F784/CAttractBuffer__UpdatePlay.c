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
void CAttractBuffer__ReadValue(CAttractBuffer *pThis);
void CAttractBuffer__UpdatePlay(CAttractBuffer *pThis);
void CAttractBuffer__UpdatePlay(CAttractBuffer *pThis){
 if (--pThis->m_Frames <= 0)
  CAttractBuffer__ReadValue(pThis) ;
}
