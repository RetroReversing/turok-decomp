#include "common.h"

typedef unsigned char sa_u8;
typedef unsigned short sa_u16;
typedef signed char sa_s8;
typedef struct {
 sa_u16 button;
 sa_s8 stick_x;
 sa_s8 stick_y;
 sa_u8 errno;
} OSContPad;
extern OSContPad D_801199C8 ;
extern int nDisplayLists,
      D_8011992C;
extern void func_800501E0() ;
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
void func_800501E0();
void func_800501E0(){
 CAttractDemo *pThis = &D_80128140 ;
 if (pThis->m_Active)
 {
  if (pThis->m_Record)
  {
   D_801199C8.stick_x >>= 8-8 ;
   D_801199C8.stick_x <<= 8-8 ;
   D_801199C8.stick_y >>= 8-8 ;
   D_801199C8.stick_y <<= 8-8 ;
  }
  if (pThis->m_Play)
  {
   D_801199C8.button = pThis->m_ButtonBuffer.m_Value ;
   D_801199C8.stick_x = pThis->m_StickXBuffer.m_Value ;
   D_801199C8.stick_y = pThis->m_StickYBuffer.m_Value ;
   D_8011992C = pThis->m_NextFieldsBuffer.m_Value ;
  }
 }
}
