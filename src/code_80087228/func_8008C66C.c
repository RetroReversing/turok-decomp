#include "common.h"

typedef unsigned char sa_u8;
typedef unsigned short sa_u16;
typedef unsigned long sa_u32;
typedef unsigned long long sa_u64;
typedef signed char sa_s8;
typedef short sa_s16;
typedef long sa_s32;
typedef float sa_f32;
typedef double sa_f64;
typedef sa_s32 OSPri;
typedef sa_s32 OSId;
typedef union {
    struct {
        sa_f32 f_odd;
        sa_f32 f_even;
    } f;
    sa_f64 d;
} __OSfp;
typedef struct {
    sa_u64 at, v0, v1, a0, a1, a2, a3;
    sa_u64 t0, t1, t2, t3, t4, t5, t6, t7;
    sa_u64 s0, s1, s2, s3, s4, s5, s6, s7;
    sa_u64 t8, t9;
    sa_u64 gp, sp, sa_s8, ra;
    sa_u64 lo, hi;
    sa_u32 sr, pc, cause, badvaddr, rcp;
    sa_u32 fpcsr;
    __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
    __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;
typedef struct {
    sa_u32 flag;
    sa_u32 count;
    sa_u64 time;
} __OSThreadprofile_s;
typedef struct OSThread_s {
    struct OSThread_s *next;
    OSPri priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    sa_u16 state;
    sa_u16 flags;
    OSId id;
    int fp;
    __OSThreadprofile_s *thprof;
    __OSThreadContext context;
} OSThread;
typedef void *OSMesg;
typedef struct OSMesgQueue_s {
    OSThread *mtqueue;
    OSThread *fullqueue;
    sa_s32 validCount;
    sa_s32 first;
    sa_s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;
typedef struct {
    sa_u32 errStatus;
    void *dramAddr;
    void *C2Addr;
    sa_u32 sectorSize;
    sa_u32 C1ErrNum;
    sa_u32 C1ErrSector[4];
} __OSBlockInfo;
typedef struct {
    sa_u32 cmdType;
    sa_u16 transferMode;
    sa_u16 blockNum;
    sa_s32 sectorNum;
    sa_u32 devAddr;
    sa_u32 bmCtlShadow;
    sa_u32 seqCtlShadow;
    __OSBlockInfo block[2];
} __OSTranxInfo;
typedef struct OSPiHandle_s {
    struct OSPiHandle_s *next;
    sa_u8 type;
    sa_u8 latency;
    sa_u8 pageSize;
    sa_u8 relDuration;
    sa_u8 pulse;
    sa_u8 domain;
    sa_u32 baseAddress;
    sa_u32 speed;
    __OSTranxInfo transferInfo;
} OSPiHandle;
typedef struct {
    sa_s32 active;
    OSThread *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    sa_s32 (*dma)(sa_s32, sa_u32, void *, sa_u32);
    sa_s32 (*edma)(OSPiHandle *, sa_s32, sa_u32, void *, sa_u32);
} OSDevMgr;
typedef short ADPCM_STATE[16];
typedef sa_s32 ALMicroTime;
typedef sa_u8 ALPan;
typedef struct ALLink_s {
    struct ALLink_s *next;
    struct ALLink_s *prev;
} ALLink;
typedef sa_s32 (*ALDMAproc)(sa_s32 addr, sa_s32 len, void *state);
typedef ALDMAproc (*ALDMANew)(void *state);
typedef struct {
    sa_u8 *base;
    sa_u8 *cur;
    sa_s32 len;
    sa_s32 count;
} ALHeap;
typedef sa_u8 ALFxId;
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
typedef struct ALBank_s {
    sa_s16 instCount;
    sa_u8 flags;
    sa_u8 pad;
    sa_s32 sampleRate;
    ALInstrument *percussion;
    ALInstrument *instArray[1];
} ALBank;
typedef ALMicroTime (*ALVoiceHandler)(void *);
typedef struct {
    sa_s32 maxVVoices;
    sa_s32 maxPVoices;
    sa_s32 maxUpdates;
    sa_s32 maxFXbusses;
    void *dmaproc;
    ALHeap *heap;
    sa_s32 outputRate;
    ALFxId fxType;
    sa_s32 *D_800ECEC4;
} ALSynConfig;
typedef struct ALPlayer_s {
    struct ALPlayer_s *next;
    void *clientData;
    ALVoiceHandler handler;
    ALMicroTime callTime;
    sa_s32 samplesLeft;
} ALPlayer;
typedef struct ALVoice_s {
    ALLink node;
    struct PVoice_s *pvoice;
    ALWaveTable *table;
    void *clientPrivate;
    sa_s16 state;
    sa_s16 priority;
    sa_s16 fxBus;
    sa_s16 unityPitch;
} ALVoice;
typedef struct {
    ALPlayer *head;
    ALLink pFreeList;
    ALLink pAllocList;
    ALLink pLameList;
    sa_s32 paramSamples;
    sa_s32 curSamples;
    ALDMANew dma;
    ALHeap *heap;
    struct ALParam_s *paramList;
    struct ALMainBus_s *mainBus;
    struct ALAuxBus_s *auxBus;
    struct ALFilter_s *outputFilter;
    sa_s32 numPVoices;
    sa_s32 maxAuxBusses;
    sa_s32 outputRate;
    sa_s32 maxOutSamples;
} ALSynth;
typedef struct {
    ALSynth drvr;
} ALGlobals;
typedef struct {
    sa_u8 *curPtr;
    sa_s32 lastTicks;
    sa_s32 curTicks;
    sa_s16 lastStatus;
} ALSeqMarker;
typedef struct {
    sa_s32 ticks;
    sa_u8 status;
    sa_u8 byte1;
    sa_u8 byte2;
    sa_u32 duration;
} ALMIDIEvent;
typedef struct {
    sa_s32 ticks;
    sa_u8 status;
    sa_u8 type;
    sa_u8 len;
    sa_u8 byte1;
    sa_u8 byte2;
    sa_u8 byte3;
} ALTempoEvent;
typedef struct {
    sa_s32 ticks;
    sa_u8 status;
    sa_u8 type;
    sa_u8 len;
} ALEndEvent;
typedef struct {
    struct ALVoice_s *voice;
} ALNoteEvent;
typedef struct {
    struct ALVoice_s *voice;
    ALMicroTime delta;
    sa_u8 vol;
} ALVolumeEvent;
typedef struct {
    sa_s16 vol;
} ALSeqpVolEvent;
typedef struct {
    ALSeqMarker *start;
    ALSeqMarker *end;
    sa_s32 count;
} ALSeqpLoopEvent;
typedef struct {
    sa_u8 chan;
    sa_u8 priority;
} ALSeqpPriorityEvent;
typedef struct {
    void *seq;
} ALSeqpSeqEvent;
typedef struct {
    ALBank *bank;
} ALSeqpBankEvent;
typedef struct {
    struct ALVoiceState_s *vs;
    void *oscState;
    sa_u8 chan;
} ALOscEvent;
typedef struct {
    sa_s16 type;
    union {
        ALMIDIEvent midi;
        ALTempoEvent tempo;
        ALEndEvent end;
        ALNoteEvent note;
        ALVolumeEvent vol;
        ALSeqpLoopEvent loop;
        ALSeqpVolEvent spvol;
 ALSeqpPriorityEvent sppriority;
 ALSeqpSeqEvent spseq;
 ALSeqpBankEvent spbank;
        ALOscEvent osc;
    } msg;
} ALEvent;
typedef struct {
    ALLink freeList;
    ALLink allocList;
    sa_s32 eventCount;
} ALEventQueue;
typedef struct ALVoiceState_s {
    struct ALVoiceState_s *next;
    ALVoice voice;
    ALSound *sound;
    ALMicroTime envEndTime;
    sa_f32 pitch;
    sa_f32 vibrato;
    sa_u8 envGain;
    sa_u8 channel;
    sa_u8 key;
    sa_u8 velocity;
    sa_u8 envPhase;
    sa_u8 phase;
    sa_u8 tremelo;
    sa_u8 flags;
} ALVoiceState;
typedef struct {
    sa_s32 maxSounds;
    sa_s32 maxEvents;
    ALHeap *heap;
} ALSndpConfig;
typedef struct {
    ALPlayer node;
    ALEventQueue evtq;
    ALEvent nextEvent;
    ALSynth *drvr;
    sa_s32 target;
    void *sndState;
    sa_s32 maxSounds;
    ALMicroTime frameTime;
    ALMicroTime nextDelta;
    ALMicroTime curTime;
} ALSndPlayer;
typedef sa_s16 ALSndId;
extern void D_800A3E50(ALSndPlayer *sndp, ALPan pan);
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef unsigned short SF;
typedef struct CROMEnvelope_t
{
 SF m_MaxValue,
      m_StartFactor, m_EndFactor;
 unsigned short m_nDuration, m_EnvStartTime;
} CROMEnvelope;
typedef struct
{
 ALBank *sfxBank;
 sa_u8 *sfxBankPtr;
 ALSndPlayer Sndp;
 ALSndPlayer *NextPlayer;
 ALSndId idlist[16];
 signed short SoundCount;
} t_SoundPlayer;
typedef struct
{
 unsigned long StartTime;
 signed long Vol;
 signed long MaxVol;
 signed short FXmix;
 float Pitch;
 signed short Pan;
 void *pEnvSound;
 signed short Priority;
 signed short SfxNum;
 signed short CfxNum;
 float dist;
 signed long QuedVoice;
 CVector3 vPos;
 unsigned char RadioVolume,
        unused2;
} t_SndObject;
typedef struct
{
 float RawValue;
 float IncrValue;
} t_EnvClac;
typedef struct
{
 signed long CFXhandle;
 signed long PhysicalHandle;
 signed long VirtualHandle;
 t_SndObject theSFX;
 CROMEnvelope PitchEnv;
 t_EnvClac PitchCalc;
 CROMEnvelope VolEnv;
 t_EnvClac VolCalc;
 signed long delay;
 ALSndPlayer *SndPlayer;
 int ChannelFlags;
} t_Channel;
typedef struct s_WaitQue
{
 struct s_WaitQue *Prev;
 struct s_WaitQue *Next;
 t_Channel QuedChannel;
} t_WaitQue;
typedef struct
{
 CVector3 vPos;
 float YRot;
 float Radius;
} t_Ears;
typedef struct
{
 ALSynConfig SynthConfig;
 ALSndpConfig SPConfig;
 ALGlobals GlobalAudio;
 t_SoundPlayer SndPlayerList;
 signed short NumPlayers;
 t_Channel VoiceChannels[16 +1];
 t_WaitQue SFXWaitQue[32];
 signed short ChannelLock;
 t_Ears Ears;
 float VolScaleFactor;
 float PanScaleFactor;
 signed long sfx_timer;
 signed long sfx_counter;
 signed long cfx_counter;
} t_AudioWorld;
extern int func_80089EC4(signed short Channel);
extern t_AudioWorld D_80129520;
extern void func_8008C66C(signed long channel);
void func_8008C66C(signed long channel);
void func_8008C66C(signed long channel){
 ALSndPlayer *Sndp = &D_80129520.SndPlayerList.Sndp;
 t_SndObject *pSound = &D_80129520.VoiceChannels[channel].theSFX;
 t_Channel *pChannel = &D_80129520.VoiceChannels[channel];
 if(pChannel->ChannelFlags & (1 << 10))
 {
  func_80089EC4(channel);
  D_800A3E50(Sndp, pSound->Pan);
 }
}
