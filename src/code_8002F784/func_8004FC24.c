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
void func_8004F938(CAttractBuffer *pThis);
void func_8004FC24(CAttractBuffer *pThis);
void func_8004FC24(CAttractBuffer *pThis){
 if (--pThis->m_Frames <= 0)
  func_8004F938(pThis) ;
}
