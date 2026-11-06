#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef unsigned short SF;
extern float SF2FLOAT(SF sfValue);
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
extern signed short playElement(signed long VirtualHandle, CVector3 *vPos, int flags);
extern int SoundHandleToChannel(signed long VirtualHandle, signed long HandleType);
extern void SetSoundPosition(signed long channel, float X, float Y, float Z, int flags);
extern signed long PlayEnvironmentSound(CROMSoundElement *pElement,
         void *pInstance, CVector3 *vPos,
         float Volume, float Pitch);
extern void SetCFXPitch(CROMSoundElement *pElement, signed long channel, int SndFlags);
extern void SetCFXVolume(CROMSoundElement *pElement, signed long channel);
extern void DoSoundElement(CROMSoundElement *pElement,
        void *pInstance, CVector3 *vPos,
        float Volume, int cfxnum, int cfxhandle, int SndFlags);
extern signed long initCFX(CROMSoundElement *pElement, int cfxnum, int cfxhandle, CVector3 *vPos);
extern void DoSoundRandomization(int cfxnum, CVector3 *vPos, int SndFlags);
extern void SetReverbMix(int channel, int SndFlags);
void DoSoundElement(CROMSoundElement *pElement,
        void *pInstance, CVector3 *vPos,
        float Volume, int cfxnum, int cfxhandle, int SndFlags);
void DoSoundRandomization(int cfxnum, CVector3 *vPos, int SndFlags);
signed long initCFX(CROMSoundElement *pElement, int cfxnum, int cfxhandle, CVector3 *vPos);
void SetReverbMix(int channel, int SndFlags);
void SetCFXPitch(CROMSoundElement *pElement, signed long channel, int SndFlags);
void SetCFXVolume(CROMSoundElement *pElement, signed long channel);
void DoSoundElement(CROMSoundElement *pElement,
        void *pInstance, CVector3 *vPos,
        float Volume, int cfxnum, int cfxhandle, int SndFlags){
 signed long handle, channel;
 CVector3 VecPos;
 if ( (pElement->m_wFlags & 1)
   && (pInstance) )
 {
  PlayEnvironmentSound(pElement, pInstance, vPos,
        SF2FLOAT(pElement->m_Volume.m_MaxValue) * Volume,
        SF2FLOAT(pElement->m_Pitch.m_MaxValue));
 }
 else
 {
  handle = initCFX(pElement, cfxnum, cfxhandle, vPos);
  channel = SoundHandleToChannel(handle, 0);
   if (channel == -1)
  {
   return;
  }
  SetReverbMix(channel, SndFlags);
  SetCFXPitch(pElement, channel, SndFlags);
  SetCFXVolume(pElement, channel);
  VecPos.x = vPos->x;
  VecPos.y = vPos->y;
  VecPos.z = vPos->z;
  DoSoundRandomization(cfxnum, &VecPos, SndFlags);
  SetSoundPosition(channel, VecPos.x, VecPos.y, VecPos.z, 0);
  playElement(handle, &VecPos, 0);
 }
}
