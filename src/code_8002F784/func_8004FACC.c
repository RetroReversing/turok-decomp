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
unsigned long func_8004F9E4(CAttractBuffer *pThis);
void func_8004FA7C(CAttractBuffer *pThis);
void func_8004FACC(CAttractBuffer *pThis);
void func_8004FACC(CAttractBuffer *pThis){
 pThis->m_Value = func_8004F9E4(pThis) * 0x8000 ;
 pThis->m_Value |= func_8004F9E4(pThis) * 0x4000 ;
 pThis->m_Value |= func_8004F9E4(pThis) * 0x0010 ;
 pThis->m_Value |= func_8004F9E4(pThis) * 0x2000 ;
 pThis->m_Value |= func_8004F9E4(pThis) * 0x0008 ;
 pThis->m_Value |= func_8004F9E4(pThis) * 0x0002 ;
 pThis->m_Value |= func_8004F9E4(pThis) * 0x0001 ;
 pThis->m_Value |= func_8004F9E4(pThis) * 0x0004 ;
 pThis->m_Value |= func_8004F9E4(pThis) * 0x0100 ;
 func_8004FA7C(pThis) ;
}
