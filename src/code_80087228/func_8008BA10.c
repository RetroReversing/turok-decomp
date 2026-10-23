#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef unsigned short SF;
extern float func_8001F298(SF sfValue);
typedef struct CROMEnvelope_t
{
 SF m_MaxValue,
      m_StartFactor, m_EndFactor;
 unsigned short m_nDuration, m_EnvStartTime;
} CROMEnvelope;
typedef struct CROMSoundElement_t
{
 unsigned short m_nSampleNum,
      m_nDelayTime,
      m_Priority,
      m_wFlags,
      m_Probability;
 CROMEnvelope m_Volume,
      m_Pitch;
 unsigned char m_RadioVolume,
      unused2;
} CROMSoundElement;
struct CROMSoundElement_t;
extern signed short func_80089BF8(signed long VirtualHandle, CVector3 *vPos, int flags);
extern int func_8008AD08(signed long VirtualHandle, signed long HandleType);
extern void func_8008ADD8(signed long channel, float X, float Y, float Z, int flags);
extern signed long func_80089858(CROMSoundElement *pElement,
         void *pInstance, CVector3 *vPos,
         float Volume, float Pitch);
extern void func_8008C250(CROMSoundElement *pElement, signed long channel, int SndFlags);
extern void func_8008C470(CROMSoundElement *pElement, signed long channel);
extern void func_8008BA10(CROMSoundElement *pElement,
        void *pInstance, CVector3 *vPos,
        float Volume, int cfxnum, int cfxhandle, int SndFlags);
extern signed long func_8008BEA4(CROMSoundElement *pElement, int cfxnum, int cfxhandle, CVector3 *vPos);
extern void func_8008BC74(int cfxnum, CVector3 *vPos, int SndFlags);
extern void func_8008C15C(int channel, int SndFlags);
void func_8008BA10(CROMSoundElement *pElement,
        void *pInstance, CVector3 *vPos,
        float Volume, int cfxnum, int cfxhandle, int SndFlags);
void func_8008BC74(int cfxnum, CVector3 *vPos, int SndFlags);
signed long func_8008BEA4(CROMSoundElement *pElement, int cfxnum, int cfxhandle, CVector3 *vPos);
void func_8008C15C(int channel, int SndFlags);
void func_8008C250(CROMSoundElement *pElement, signed long channel, int SndFlags);
void func_8008C470(CROMSoundElement *pElement, signed long channel);
void func_8008BA10(CROMSoundElement *pElement,
        void *pInstance, CVector3 *vPos,
        float Volume, int cfxnum, int cfxhandle, int SndFlags){
 signed long handle, channel;
 CVector3 VecPos;
 if ( (pElement->m_wFlags & 1)
   && (pInstance) )
 {
  func_80089858(pElement, pInstance, vPos,
        func_8001F298(pElement->m_Volume.m_MaxValue) * Volume,
        func_8001F298(pElement->m_Pitch.m_MaxValue));
 }
 else
 {
  handle = func_8008BEA4(pElement, cfxnum, cfxhandle, vPos);
  channel = func_8008AD08(handle, 0);
   if (channel == -1)
  {
   return;
  }
  func_8008C15C(channel, SndFlags);
  func_8008C250(pElement, channel, SndFlags);
  func_8008C470(pElement, channel);
  VecPos.x = vPos->x;
  VecPos.y = vPos->y;
  VecPos.z = vPos->z;
  func_8008BC74(cfxnum, &VecPos, SndFlags);
  func_8008ADD8(channel, VecPos.x, VecPos.y, VecPos.z, 0);
  func_80089BF8(handle, &VecPos, 0);
 }
}
