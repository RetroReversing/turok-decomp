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
unsigned long func_8004F9AC(unsigned char *pData, unsigned long Bit);
unsigned long func_8004F9E4(CAttractBuffer *pThis);
unsigned long func_8004F9E4(CAttractBuffer *pThis){
 return func_8004F9AC(pThis->m_pData, pThis->m_CurrentBit++) ;
}
