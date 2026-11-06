#include "common.h"

extern void D_8003F9B8(void) ;
extern int CAttractDemo__Play(void) ;
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
typedef struct CAttractDemo_t
{
 signed short *m_pCurrentDemo ;
 int m_DemoRequested ;
 volatile int m_DemoRecieved ;
 unsigned char m_DemoBuffer[(1024*2)] ;
 int m_Active ;
 int m_Record ;
 int m_Play ;
 int m_FirstFrame ;
 int m_Finished ;
 CAttractBuffer m_ButtonBuffer ;
 CAttractBuffer m_StickXBuffer ;
 CAttractBuffer m_StickYBuffer ;
 CAttractBuffer m_NextFieldsBuffer ;
 CAttractBuffer m_UpdatedBuffer ;
 signed long m_PlayRecordFrame ;
 signed long m_TotalFrames ;
 float m_TotalTime ;
 unsigned long m_Checksum ;
} CAttractDemo ;
extern CAttractDemo D_80128140 ;
void CAttractDemo__ConstructPlay(unsigned char *pDemo);
int CAttractDemo__Play(void);
int CAttractDemo__Play(void){
 CAttractDemo *pThis = &D_80128140 ;
 D_8003F9B8() ;
 if (!pThis->m_DemoRecieved)
  return 0 ;
 CAttractDemo__ConstructPlay(pThis->m_DemoBuffer) ;
 return 1 ;
}
