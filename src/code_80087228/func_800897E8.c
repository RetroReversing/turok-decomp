#include "common.h"

typedef unsigned char sa_u8;
typedef unsigned long sa_u32;
typedef signed char sa_s8;
typedef short sa_s16;
typedef long sa_s32;
typedef short ADPCM_STATE[16];
typedef sa_s32 ALMicroTime;
typedef sa_u8 ALPan;
typedef struct {
    sa_s32 order;
    sa_s32 npredictors;
    sa_s16 book[1];
} ALADPCMBook;
typedef struct {
    sa_u32 start;
    sa_u32 end;
    sa_u32 count;
    ADPCM_STATE state;
} ALADPCMloop;
typedef struct {
    sa_u32 start;
    sa_u32 end;
    sa_u32 count;
} ALRawLoop;
typedef struct {
    ALMicroTime attackTime;
    ALMicroTime decayTime;
    ALMicroTime releaseTime;
    sa_u8 attackVolume;
    sa_u8 decayVolume;
} ALEnvelope;
typedef struct {
    sa_u8 velocityMin;
    sa_u8 velocityMax;
    sa_u8 keyMin;
    sa_u8 keyMax;
    sa_u8 keyBase;
    sa_s8 detune;
} ALKeyMap;
typedef struct {
    ALADPCMloop *loop;
    ALADPCMBook *book;
} ALADPCMWaveInfo;
typedef struct {
    ALRawLoop *loop;
} ALRAWWaveInfo;
typedef struct ALWaveTable_s {
    sa_u8 *base;
    sa_s32 len;
    sa_u8 type;
    sa_u8 flags;
    union {
        ALADPCMWaveInfo adpcmWave;
        ALRAWWaveInfo rawWave;
    } waveInfo;
} ALWaveTable;
typedef struct ALSound_s {
    ALEnvelope *envelope;
    ALKeyMap *keyMap;
    ALWaveTable *wavetable;
    ALPan samplePan;
    sa_u8 sampleVolume;
    sa_u8 flags;
} ALSound;
typedef struct {
    sa_u8 volume;
    ALPan pan;
    sa_u8 priority;
    sa_u8 flags;
    sa_u8 tremType;
    sa_u8 tremRate;
    sa_u8 tremDepth;
    sa_u8 tremDelay;
    sa_u8 vibType;
    sa_u8 vibRate;
    sa_u8 vibDepth;
    sa_u8 vibDelay;
    sa_s16 bendRange;
    sa_s16 soundCount;
    ALSound *soundArray[1];
} ALInstrument;
extern void func_800897E8();
void func_800897E8(ALInstrument *inst);
void func_800897E8(ALInstrument *inst){
 int i, j;
 ALSound *temp;
 for(i = 0; i < inst->soundCount; i++)
 {
  for(j = i+1; j < inst->soundCount; j++)
  {
   if(inst->soundArray[j] < inst->soundArray[i])
   {
    temp = inst->soundArray[i];
    inst->soundArray[i] = inst->soundArray[j];
    inst->soundArray[j] = temp;
   }
  }
 }
}
