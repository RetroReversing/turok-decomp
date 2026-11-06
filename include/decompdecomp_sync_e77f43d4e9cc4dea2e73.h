typedef short ADPCM_STATE[16];typedef short POLEF_STATE[4];typedef short RESAMPLE_STATE[16];typedef short ENVMIX_STATE[40];
#define __GCC_HAVE_DWARF2_CFI_ASM 1
#define __STDC__ 1
#define __STDC_HOSTED__ 1
#define __STDC_VERSION__ 201710L
#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define __STDC_EMBED_NOT_FOUND__ 0
#define __STDC_EMBED_FOUND__ 1
#define __STDC_EMBED_EMPTY__ 2
typedef signed char s8;typedef unsigned char u8;typedef signed short s16;typedef unsigned short u16;typedef signed int s32;typedef unsigned int u32;typedef signed long long s64;typedef unsigned long long u64;typedef float f32;typedef double f64;typedef union{struct{u32 w0,w1;}words;u64 force;}Acmd;
#define __LIB_AUDIO__ 
#define NULL 0
#define AL_FX_BUFFER_SIZE 8192
#define AL_FRAME_INIT -1
#define AL_USEC_PER_FRAME 16000
#define AL_MAX_PRIORITY 127
#define AL_GAIN_CHANGE_TIME 1000
typedef s32 ALMicroTime;
typedef u8 ALPan;
#define AL_PAN_CENTER 64
#define AL_PAN_LEFT 0
#define AL_PAN_RIGHT 127
#define AL_VOL_FULL 127
#define AL_KEY_MIN 0
#define AL_KEY_MAX 127
#define AL_DEFAULT_FXMIX 0
#define AL_SUSTAIN 63
#define ALFailIf(condition,error) if (condition) { return; }
#define ALFlagFailIf(condition,flag,error) if (condition) { return; }
typedef struct ALLink_s {
    struct ALLink_s *next;
    struct ALLink_s *prev;
} ALLink;
void alUnlink(ALLink *element);
void alLink(ALLink *element, ALLink *after);
typedef s32 (*ALDMAproc)(s32 addr, s32 len, void *state);
typedef ALDMAproc (*ALDMANew)(void *state);
void alCopy(void *src, void *dest, s32 len);
typedef struct {
    u8 *base;
    u8 *cur;
    s32 len;
    s32 count;
} ALHeap;
#define AL_HEAP_DEBUG 1
#define AL_HEAP_MAGIC 0x20736a73
#define AL_HEAP_INIT 0
void alHeapInit(ALHeap *hp, u8 *base, s32 len);
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
s32 alHeapCheck(ALHeap *hp);
#define alHeapAlloc(hp,elem,size) alHeapDBAlloc(0, 0,(hp),(elem),(size))
#define AL_FX_NONE 0
#define AL_FX_SMALLROOM 1
#define AL_FX_BIGROOM 2
#define AL_FX_CHORUS 3
#define AL_FX_FLANGE 4
#define AL_FX_ECHO 5
#define AL_FX_CUSTOM 6
typedef u8 ALFxId;
typedef void *ALFxRef;
#define AL_BANK_VERSION 'B1'
enum {AL_ADPCM_WAVE = 0,
         AL_RAW16_WAVE};
typedef struct {
    s32 order;
    s32 npredictors;
    s16 book[1];
} ALADPCMBook;
typedef struct {
    u32 start;
    u32 end;
    u32 count;
    ADPCM_STATE state;
} ALADPCMloop;
typedef struct {
    u32 start;
    u32 end;
    u32 count;
} ALRawLoop;
typedef struct {
    ALMicroTime attackTime;
    ALMicroTime decayTime;
    ALMicroTime releaseTime;
    u8 attackVolume;
    u8 decayVolume;
} ALEnvelope;
typedef struct {
    u8 velocityMin;
    u8 velocityMax;
    u8 keyMin;
    u8 keyMax;
    u8 keyBase;
    s8 detune;
} ALKeyMap;
typedef struct {
    ALADPCMloop *loop;
    ALADPCMBook *book;
} ALADPCMWaveInfo;
typedef struct {
    ALRawLoop *loop;
} ALRAWWaveInfo;
typedef struct ALWaveTable_s {
    u8 *base;
    s32 len;
    u8 type;
    u8 flags;
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
    u8 sampleVolume;
    u8 flags;
} ALSound;
typedef struct {
    u8 volume;
    ALPan pan;
    u8 priority;
    u8 flags;
    u8 tremType;
    u8 tremRate;
    u8 tremDepth;
    u8 tremDelay;
    u8 vibType;
    u8 vibRate;
    u8 vibDepth;
    u8 vibDelay;
    s16 bendRange;
    s16 soundCount;
    ALSound *soundArray[1];
} ALInstrument;
typedef struct ALBank_s {
    s16 instCount;
    u8 flags;
    u8 pad;
    s32 sampleRate;
    ALInstrument *percussion;
    ALInstrument *instArray[1];
} ALBank;
typedef struct {
    s16 revision;
    s16 bankCount;
    ALBank *bankArray[1];
} ALBankFile;
void alBnkfNew(ALBankFile *f, u8 *table);
#define AL_SEQBANK_VERSION 'S1'
typedef struct {
    u8 *offset;
    s32 len;
} ALSeqData;
typedef struct {
    s16 revision;
    s16 seqCount;
    ALSeqData seqArray[1];
} ALSeqFile;
void alSeqFileNew(ALSeqFile *f, u8 *base);
typedef ALMicroTime (*ALVoiceHandler)(void *);
typedef struct {
    s32 maxVVoices;
    s32 maxPVoices;
    s32 maxUpdates;
    s32 maxFXbusses;
    void *dmaproc;
    ALHeap *heap;
    s32 outputRate;
    ALFxId fxType;
    s32 *params;
} ALSynConfig;
typedef struct ALPlayer_s {
    struct ALPlayer_s *next;
    void *clientData;
    ALVoiceHandler handler;
    ALMicroTime callTime;
    s32 samplesLeft;
} ALPlayer;
typedef struct ALVoice_s {
    ALLink node;
    struct PVoice_s *pvoice;
    ALWaveTable *table;
    void *clientPrivate;
    s16 state;
    s16 priority;
    s16 fxBus;
    s16 unityPitch;
} ALVoice;
typedef struct ALVoiceConfig_s {
    s16 priority;
    s16 fxBus;
    u8 unityPitch;
} ALVoiceConfig;
typedef struct {
    ALPlayer *head;
    ALLink pFreeList;
    ALLink pAllocList;
    ALLink pLameList;
    s32 paramSamples;
    s32 curSamples;
    ALDMANew dma;
    ALHeap *heap;
    struct ALParam_s *paramList;
    struct ALMainBus_s *mainBus;
    struct ALAuxBus_s *auxBus;
    struct ALFilter_s *outputFilter;
    s32 numPVoices;
    s32 maxAuxBusses;
    s32 outputRate;
    s32 maxOutSamples;
} ALSynth;
void alSynNew(ALSynth *s, ALSynConfig *config);
void alSynDelete(ALSynth *s);
void alSynAddPlayer(ALSynth *s, ALPlayer *client);
void alSynRemovePlayer(ALSynth *s, ALPlayer *client);
s32 alSynAllocVoice(ALSynth *s, ALVoice *v, ALVoiceConfig *vc);
void alSynFreeVoice(ALSynth *s, ALVoice *voice);
void alSynStartVoice(ALSynth *s, ALVoice *voice, ALWaveTable *w);
void alSynStartVoiceParams(ALSynth *s, ALVoice *voice, ALWaveTable *w,
                              f32 pitch, s16 vol, ALPan pan, u8 fxmix,
                              ALMicroTime t);
void alSynStopVoice(ALSynth *s, ALVoice *voice);
void alSynSetVol(ALSynth *s, ALVoice *v, s16 vol, ALMicroTime delta);
void alSynSetPitch(ALSynth *s, ALVoice *voice, f32 ratio);
void alSynSetPan(ALSynth *s, ALVoice *voice, ALPan pan);
void alSynSetFXMix(ALSynth *s, ALVoice *voice, u8 fxmix);
void alSynSetPriority(ALSynth *s, ALVoice *voice, s16 priority);
s16 alSynGetPriority(ALSynth *s, ALVoice *voice);
ALFxRef *alSynAllocFX(ALSynth *s, s16 bus, ALSynConfig *c, ALHeap *hp);
ALFxRef alSynGetFXRef(ALSynth *s, s16 bus, s16 index);
void alSynFreeFX(ALSynth *s, ALFxRef *fx);
void alSynSetFXParam(ALSynth *s, ALFxRef fx, s16 paramID, void *param);
typedef struct {
    ALSynth drvr;
} ALGlobals;
extern ALSynth *D_800EF260;
#define alGlobals_unused 0

void alInit(ALGlobals *glob, ALSynConfig *c);
void alClose(ALGlobals *glob);
Acmd *alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen);
#define AL_STOPPED 0
#define AL_PLAYING 1
#define AL_STOPPING 2
#define AL_DEFAULT_PRIORITY 5
#define AL_DEFAULT_VOICE 0
#define AL_MAX_CHANNELS 16
enum ALMsg {
    AL_SEQ_REF_EVT,
    AL_SEQ_MIDI_EVT,
    AL_SEQP_MIDI_EVT,
    AL_TEMPO_EVT,
    AL_SEQ_END_EVT,
    AL_NOTE_END_EVT,
    AL_SEQP_ENV_EVT,
    AL_SEQP_META_EVT,
    AL_SEQP_PROG_EVT,
    AL_SEQP_API_EVT,
    AL_SEQP_VOL_EVT,
    AL_SEQP_LOOP_EVT,
    AL_SEQP_PRIORITY_EVT,
    AL_SEQP_SEQ_EVT,
    AL_SEQP_BANK_EVT,
    AL_SEQP_PLAY_EVT,
    AL_SEQP_STOP_EVT,
    AL_SEQP_STOPPING_EVT,
    AL_TRACK_END,
    AL_CSP_LOOPSTART,
    AL_CSP_LOOPEND,
    AL_CSP_NOTEOFF_EVT,
    AL_TREM_OSC_EVT,
    AL_VIB_OSC_EVT
};
#define AL_EVTQ_END 0x7fffffff
enum AL_MIDIstatus {
    AL_MIDI_ChannelMask = 0x0F,
    AL_MIDI_StatusMask = 0xF0,
    AL_MIDI_ChannelVoice = 0x80,
    AL_MIDI_NoteOff = 0x80,
    AL_MIDI_NoteOn = 0x90,
    AL_MIDI_PolyKeyPressure = 0xA0,
    AL_MIDI_ControlChange = 0xB0,
    AL_MIDI_ChannelModeSelect = 0xB0,
    AL_MIDI_ProgramChange = 0xC0,
    AL_MIDI_ChannelPressure = 0xD0,
    AL_MIDI_PitchBendChange = 0xE0,
    AL_MIDI_SysEx = 0xF0,
    AL_MIDI_SystemCommon = 0xF1,
    AL_MIDI_TimeCodeQuarterFrame = 0xF1,
    AL_MIDI_SongPositionPointer = 0xF2,
    AL_MIDI_SongSelect = 0xF3,
    AL_MIDI_Undefined1 = 0xF4,
    AL_MIDI_Undefined2 = 0xF5,
    AL_MIDI_TuneRequest = 0xF6,
    AL_MIDI_EOX = 0xF7,
    AL_MIDI_SystemRealTime = 0xF8,
    AL_MIDI_TimingClock = 0xF8,
    AL_MIDI_Undefined3 = 0xF9,
    AL_MIDI_Start = 0xFA,
    AL_MIDI_Continue = 0xFB,
    AL_MIDI_Stop = 0xFC,
    AL_MIDI_Undefined4 = 0xFD,
    AL_MIDI_ActiveSensing = 0xFE,
    AL_MIDI_SystemReset = 0xFF,
    AL_MIDI_Meta = 0xFF
};
enum AL_MIDIctrl {
    AL_MIDI_VOLUME_CTRL = 0x07,
    AL_MIDI_PAN_CTRL = 0x0A,
    AL_MIDI_PRIORITY_CTRL = 0x10,
    AL_MIDI_FX_CTRL_0 = 0x14,
    AL_MIDI_FX_CTRL_1 = 0x15,
    AL_MIDI_FX_CTRL_2 = 0x16,
    AL_MIDI_FX_CTRL_3 = 0x17,
    AL_MIDI_FX_CTRL_4 = 0x18,
    AL_MIDI_FX_CTRL_5 = 0x19,
    AL_MIDI_FX_CTRL_6 = 0x1A,
    AL_MIDI_FX_CTRL_7 = 0x1B,
    AL_MIDI_FX_CTRL_8 = 0x1C,
    AL_MIDI_FX_CTRL_9 = 0x1D,
    AL_MIDI_SUSTAIN_CTRL = 0x40,
    AL_MIDI_FX1_CTRL = 0x5B,
    AL_MIDI_FX3_CTRL = 0x5D
};
enum AL_MIDImeta {
    AL_MIDI_META_TEMPO = 0x51,
    AL_MIDI_META_EOT = 0x2f
};
#define AL_CMIDI_BLOCK_CODE 0xFE
#define AL_CMIDI_LOOPSTART_CODE 0x2E
#define AL_CMIDI_LOOPEND_CODE 0x2D
#define AL_CMIDI_CNTRL_LOOPSTART 102
#define AL_CMIDI_CNTRL_LOOPEND 103
#define AL_CMIDI_CNTRL_LOOPCOUNT_SM 104
#define AL_CMIDI_CNTRL_LOOPCOUNT_BIG 105
typedef struct {
    u8 *curPtr;
    s32 lastTicks;
    s32 curTicks;
    s16 lastStatus;
} ALSeqMarker;
typedef struct {
    s32 ticks;
    u8 status;
    u8 byte1;
    u8 byte2;
    u32 duration;
} ALMIDIEvent;
typedef struct {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
    u8 byte1;
    u8 byte2;
    u8 byte3;
} ALTempoEvent;
typedef struct {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
} ALEndEvent;
typedef struct {
    struct ALVoice_s *voice;
} ALNoteEvent;
typedef struct {
    struct ALVoice_s *voice;
    ALMicroTime delta;
    u8 vol;
} ALVolumeEvent;
typedef struct {
    s16 vol;
} ALSeqpVolEvent;
typedef struct {
    ALSeqMarker *start;
    ALSeqMarker *end;
    s32 count;
} ALSeqpLoopEvent;
typedef struct {
    u8 chan;
    u8 priority;
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
    u8 chan;
} ALOscEvent;
typedef struct {
    s16 type;
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
    ALLink node;
    ALMicroTime delta;
    ALEvent evt;
} ALEventListItem;
typedef struct {
    ALLink freeList;
    ALLink allocList;
    s32 eventCount;
} ALEventQueue;
void alEvtqNew(ALEventQueue *evtq, ALEventListItem *items,
                          s32 itemCount);
ALMicroTime alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt);
void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt,
                                ALMicroTime delta);
void alEvtqFlush(ALEventQueue *evtq);
void alEvtqFlushType(ALEventQueue *evtq, s16 type);
#define AL_PHASE_ATTACK 0
#define AL_PHASE_NOTEON 0
#define AL_PHASE_DECAY 1
#define AL_PHASE_SUSTAIN 2
#define AL_PHASE_RELEASE 3
#define AL_PHASE_SUSTREL 4
typedef struct ALVoiceState_s {
    struct ALVoiceState_s *next;
    ALVoice voice;
    ALSound *sound;
    ALMicroTime envEndTime;
    f32 pitch;
    f32 vibrato;
    u8 envGain;
    u8 channel;
    u8 key;
    u8 velocity;
    u8 envPhase;
    u8 phase;
    u8 tremelo;
    u8 flags;
} ALVoiceState;
typedef struct {
    ALInstrument *instrument;
    s16 bendRange;
    ALFxId fxId;
    ALPan pan;
    u8 priority;
    u8 vol;
    u8 fxmix;
    u8 sustain;
    f32 pitchBend;
} ALChanState;
typedef struct ALSeq_s {
    u8 *base;
    u8 *trackStart;
    u8 *curPtr;
    s32 lastTicks;
    s32 len;
    f32 qnpt;
    s16 division;
    s16 lastStatus;
} ALSeq;
typedef struct {
    u32 trackOffset[16];
    u32 division;
} ALCMidiHdr;
typedef struct ALCSeq_s {
    ALCMidiHdr *base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    u32 deltaFlag;
    u8 *curLoc[16];
    u8 *curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
} ALCSeq;
typedef struct {
    u32 validTracks;
    s32 lastTicks;
    u32 lastDeltaTicks;
    u8 *curLoc[16];
    u8 *curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
} ALCSeqMarker;
#define NO_SOUND_ERR_MASK 0x01
#define NOTE_OFF_ERR_MASK 0x02
#define NO_VOICE_ERR_MASK 0x04
typedef struct {
    s32 maxVoices;
    s32 maxEvents;
    u8 maxChannels;
    u8 debugFlags;
    ALHeap *heap;
    void *initOsc;
    void *updateOsc;
    void *stopOsc;
} ALSeqpConfig;
typedef ALMicroTime (*ALOscInit)(void **oscState,f32 *initVal, u8 oscType,
                                   u8 oscRate, u8 oscDepth, u8 oscDelay);
typedef ALMicroTime (*ALOscUpdate)(void *oscState, f32 *updateVal);
typedef void (*ALOscStop)(void *oscState);
typedef struct {
    ALPlayer node;
    ALSynth *drvr;
    ALSeq *target;
    ALMicroTime curTime;
    ALBank *bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    u16 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    ALEvent nextEvent;
    ALEventQueue evtq;
    ALMicroTime frameTime;
    ALChanState *chanState;
    ALVoiceState *vAllocHead;
    ALVoiceState *vAllocTail;
    ALVoiceState *vFreeList;
    ALOscInit initOsc;
    ALOscUpdate updateOsc;
    ALOscStop stopOsc;
    ALSeqMarker *loopStart;
    ALSeqMarker *loopEnd;
    s32 loopCount;
} ALSeqPlayer;
typedef struct {
    ALPlayer node;
    ALSynth *drvr;
    ALCSeq *target;
    ALMicroTime curTime;
    ALBank *bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    u16 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    ALEvent nextEvent;
    ALEventQueue evtq;
    ALMicroTime frameTime;
    ALChanState *chanState;
    ALVoiceState *vAllocHead;
    ALVoiceState *vAllocTail;
    ALVoiceState *vFreeList;
    ALOscInit initOsc;
    ALOscUpdate updateOsc;
    ALOscStop stopOsc;
} ALCSPlayer;
void alSeqNew(ALSeq *seq, u8 *ptr, s32 len);
void alSeqNextEvent(ALSeq *seq, ALEvent *event);
s32 alSeqGetTicks(ALSeq *seq);
f32 alSeqTicksToSec(ALSeq *seq, s32 ticks, u32 tempo);
u32 alSeqSecToTicks(ALSeq *seq, f32 sec, u32 tempo);
void alSeqNewMarker(ALSeq *seq, ALSeqMarker *m, u32 ticks);
void alSeqSetLoc(ALSeq *seq, ALSeqMarker *marker);
void alSeqGetLoc(ALSeq *seq, ALSeqMarker *marker);
void alCSeqNew(ALCSeq *seq, u8 *ptr);
void alCSeqNextEvent(ALCSeq *seq,ALEvent *evt);
s32 alCSeqGetTicks(ALCSeq *seq);
f32 alCSeqTicksToSec(ALCSeq *seq, s32 ticks, u32 tempo);
u32 alCSeqSecToTicks(ALCSeq *seq, f32 sec, u32 tempo);
void alCSeqNewMarker(ALCSeq *seq, ALCSeqMarker *m, u32 ticks);
void alCSeqSetLoc(ALCSeq *seq, ALCSeqMarker *marker);
void alCSeqGetLoc(ALCSeq *seq, ALCSeqMarker *marker);
f32 alCents2Ratio(s32 cents);
void alSeqpNew(ALSeqPlayer *seqp, ALSeqpConfig *config);
void alSeqpDelete(ALSeqPlayer *seqp);
void alSeqpSetSeq(ALSeqPlayer *seqp, ALSeq *seq);
ALSeq *alSeqpGetSeq(ALSeqPlayer *seqp);
void alSeqpPlay(ALSeqPlayer *seqp);
void alSeqpStop(ALSeqPlayer *seqp);
s32 alSeqpGetState(ALSeqPlayer *seqp);
void alSeqpSetBank(ALSeqPlayer *seqp, ALBank *b);
void alSeqpSetTempo(ALSeqPlayer *seqp, s32 tempo);
s32 alSeqpGetTempo(ALSeqPlayer *seqp);
s16 alSeqpGetVol(ALSeqPlayer *seqp);
void alSeqpSetVol(ALSeqPlayer *seqp, s16 vol);
void alSeqpLoop(ALSeqPlayer *seqp, ALSeqMarker *start, ALSeqMarker *end, s32 count);
void alSeqpSetChlProgram(ALSeqPlayer *seqp, u8 chan, u8 prog);
s32 alSeqpGetChlProgram(ALSeqPlayer *seqp, u8 chan);
void alSeqpSetChlFXMix(ALSeqPlayer *seqp, u8 chan, u8 fxmix);
u8 alSeqpGetChlFXMix(ALSeqPlayer *seqp, u8 chan);
void alSeqpSetChlVol(ALSeqPlayer *seqp, u8 chan, u8 vol);
u8 alSeqpGetChlVol(ALSeqPlayer *seqp, u8 chan);
void alSeqpSetChlPan(ALSeqPlayer *seqp, u8 chan, ALPan pan);
ALPan alSeqpGetChlPan(ALSeqPlayer *seqp, u8 chan);
void alSeqpSetChlPriority(ALSeqPlayer *seqp, u8 chan, u8 priority);
u8 alSeqpGetChlPriority(ALSeqPlayer *seqp, u8 chan);
void alSeqpSendMidi(ALSeqPlayer *seqp, s32 ticks, u8 status, u8 byte1, u8 byte2);
#define alSeqpSetProgram alSeqpSetChlProgram
#define alSeqpGetProgram alSeqpGetChlProgram
#define alSeqpSetFXMix alSeqpSetChlFXMix
#define alSeqpGetFXMix alSeqpGetChlFXMix
#define alSeqpSetPan alSeqpSetChlPan
#define alSeqpGetPan alSeqpGetChlPan
#define alSeqpSetChannelPriority alSeqpSetChlPriority
#define alSeqpGetChannelPriority alSeqpGetChlPriority
void alCSPNew(ALCSPlayer *seqp, ALSeqpConfig *config);
void alCSPDelete(ALCSPlayer *seqp);
void alCSPSetSeq(ALCSPlayer *seqp, ALCSeq *seq);
ALCSeq *alCSPGetSeq(ALCSPlayer *seqp);
void alCSPPlay(ALCSPlayer *seqp);
void alCSPStop(ALCSPlayer *seqp);
s32 alCSPGetState(ALCSPlayer *seqp);
void alCSPSetBank(ALCSPlayer *seqp, ALBank *b);
void alCSPSetTempo(ALCSPlayer *seqp, s32 tempo);
s32 alCSPGetTempo(ALCSPlayer *seqp);
s16 alCSPGetVol(ALCSPlayer *seqp);
void alCSPSetVol(ALCSPlayer *seqp, s16 vol);
void alCSPSetChlProgram(ALCSPlayer *seqp, u8 chan, u8 prog);
s32 alCSPGetChlProgram(ALCSPlayer *seqp, u8 chan);
void alCSPSetChlFXMix(ALCSPlayer *seqp, u8 chan, u8 fxmix);
u8 alCSPGetChlFXMix(ALCSPlayer *seqp, u8 chan);
void alCSPSetChlPan(ALCSPlayer *seqp, u8 chan, ALPan pan);
ALPan alCSPGetChlPan(ALCSPlayer *seqp, u8 chan);
void alCSPSetChlVol(ALCSPlayer *seqp, u8 chan, u8 vol);
u8 alCSPGetChlVol(ALCSPlayer *seqp, u8 chan);
void alCSPSetChlPriority(ALCSPlayer *seqp, u8 chan, u8 priority);
u8 alCSPGetChlPriority(ALCSPlayer *seqp, u8 chan);
void alCSPSendMidi(ALCSPlayer *seqp, s32 ticks, u8 status,
                       u8 byte1, u8 byte2);
#define alCSPSetProgram alCSPSetChlProgram
#define alCSPGetProgram alCSPGetChlProgram
#define alCSPSetFXMix alCSPSetChlFXMix
#define alCSPGetFXMix alCSPGetChlFXMix
#define alCSPSetPan alCSPSetChlPan
#define alCSPGetPan alCSPGetChlPan
#define alCSPSetChannelPriority alCSPSetChlPriority
#define alCSPGetChannelPriority alCSPGetChlPriority
typedef struct {
    s32 maxSounds;
    s32 maxEvents;
    ALHeap *heap;
} ALSndpConfig;
typedef struct {
    ALPlayer node;
    ALEventQueue evtq;
    ALEvent nextEvent;
    ALSynth *drvr;
    s32 target;
    void *sndState;
    s32 maxSounds;
    ALMicroTime frameTime;
    ALMicroTime nextDelta;
    ALMicroTime curTime;
} ALSndPlayer;
typedef s16 ALSndId;
void alSndpNew(ALSndPlayer *sndp, ALSndpConfig *c);
void alSndpDelete(ALSndPlayer *sndp);
ALSndId alSndpAllocate(ALSndPlayer *sndp, ALSound *sound);
void alSndpDeallocate(ALSndPlayer *sndp, ALSndId id);
void alSndpSetSound(ALSndPlayer *sndp, ALSndId id);
ALSndId alSndpGetSound(ALSndPlayer *sndp);
void alSndpPlay(ALSndPlayer *sndp);
void alSndpPlayAt(ALSndPlayer *sndp, ALMicroTime delta);
void alSndpStop(ALSndPlayer *sndp);
void alSndpSetVol(ALSndPlayer *sndp, s16 vol);
void alSndpSetPitch(ALSndPlayer *sndp, f32 pitch);
void alSndpSetPan(ALSndPlayer *sndp, ALPan pan);
void alSndpSetPriority(ALSndPlayer *sndp, ALSndId id, u8 priority);
void alSndpSetFXMix(ALSndPlayer *sndp, u8 mix);
s32 alSndpGetState(ALSndPlayer *sndp);
void alParseAbiCL(Acmd *cmdList, u32 nbytes);
#define __audioInternals__ 
enum {
    AL_FILTER_FREE_VOICE,
    AL_FILTER_SET_SOURCE,
    AL_FILTER_ADD_SOURCE,
    AL_FILTER_ADD_UPDATE,
    AL_FILTER_RESET,
    AL_FILTER_SET_WAVETABLE,
    AL_FILTER_SET_DRAM,
    AL_FILTER_SET_PITCH,
    AL_FILTER_SET_UNITY_PITCH,
    AL_FILTER_START,
    AL_FILTER_SET_STATE,
    AL_FILTER_SET_VOLUME,
    AL_FILTER_SET_PAN,
    AL_FILTER_START_VOICE_ALT,
    AL_FILTER_START_VOICE,
    AL_FILTER_STOP_VOICE,
    AL_FILTER_SET_FXAMT
};
#define AL_MAX_RSP_SAMPLES 160
#define AL_DECODER_IN 0
#define AL_RESAMPLER_OUT 0
#define AL_TEMP_0 0
#define AL_DECODER_OUT 320
#define AL_TEMP_1 320
#define AL_TEMP_2 640
#define AL_MAIN_L_OUT 1088
#define AL_MAIN_R_OUT 1408
#define AL_AUX_L_OUT 1728
#define AL_AUX_R_OUT 2048
enum {
    AL_ADPCM,
    AL_RESAMPLE,
    AL_BUFFER,
    AL_SAVE,
    AL_ENVMIX,
    AL_FX,
    AL_AUXBUS,
    AL_MAINBUS
};
typedef struct ALParam_s {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    union {
        f32 f;
        s32 i;
    } data;
    union {
        f32 f;
        s32 i;
    } moredata;
    union {
        f32 f;
        s32 i;
    } stillmoredata;
    union {
        f32 f;
        s32 i;
    } yetstillmoredata;
} ALParam;
typedef struct {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    s16 unity;
    f32 pitch;
    s16 volume;
    ALPan pan;
    u8 fxMix;
    s32 samples;
    struct ALWaveTable_s *wave;
} ALStartParamAlt;
typedef struct {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    s16 unity;
    struct ALWaveTable_s *wave;
} ALStartParam;
typedef struct {
    struct ALParam_s *next;
    s32 delta;
    s16 type;
    struct PVoice_s *pvoice;
} ALFreeParam;
typedef Acmd *(*ALCmdHandler)(void *, s16 *, s32, s32, Acmd *);
typedef s32 (*ALSetParam)(void *, s32, void *);
typedef struct ALFilter_s {
    struct ALFilter_s *source;
    ALCmdHandler handler;
    ALSetParam setParam;
    s16 inp;
    s16 outp;
    s32 type;
} ALFilter;
void alFilterNew(ALFilter *f, ALCmdHandler h, ALSetParam s, s32 type);
#define AL_MAX_ADPCM_STATES 3
typedef struct {
    ALFilter filter;
    ADPCM_STATE *state;
    ADPCM_STATE *lstate;
    ALRawLoop loop;
    struct ALWaveTable_s *table;
    s32 bookSize;
    ALDMAproc dma;
    void *dmaState;
    s32 sample;
    s32 lastsam;
    s32 first;
    s32 memin;
} ALLoadFilter;
void alLoadNew(ALLoadFilter *f, ALDMANew dma, ALHeap *hp);
Acmd *alAdpcmPull(void *f, s16 *outp, s32 byteCount, s32 sampleOffset, Acmd *p);
Acmd *alRaw16Pull(void *f, s16 *outp, s32 byteCount, s32 sampleOffset, Acmd *p);
s32 alLoadParam(void *filter, s32 paramID, void *param);
typedef struct ALResampler_s {
    ALFilter filter;
    RESAMPLE_STATE *state;
    f32 ratio;
    s32 upitch;
    f32 delta;
    s32 first;
    ALParam *ctrlList;
    ALParam *ctrlTail;
    s32 motion;
} ALResampler;
typedef struct {
    s16 fc;
    s16 fgain;
    union {
        s16 fccoef[16];
        s64 force_aligned;
    } fcvec;
    POLEF_STATE *fstate;
    s32 first;
} ALLowPass;
typedef struct {
    u32 input;
    u32 output;
    s16 ffcoef;
    s16 fbcoef;
    s16 gain;
    f32 rsinc;
    f32 rsval;
    s32 rsdelta;
    f32 rsgain;
    ALLowPass *lp;
    ALResampler *rs;
} ALDelay;
typedef struct {
    struct ALFilter_s filter;
    s16 *base;
    s16 *input;
    u32 length;
    ALDelay *delay;
    u8 section_count;
    s32 (*paramHdl)(void *, s32, void *);
} ALFx;
void alFxNew(ALFx *r, ALSynConfig *c, ALHeap *hp);
Acmd *alFxPull(void *f, s16 *outp, s32 out, s32 sampleOffset, Acmd *p);
s32 alFxParam(void *filter, s32 paramID, void *param);
#define AL_MAX_MAIN_BUS_SOURCES 1
typedef struct ALMainBus_s {
    ALFilter filter;
    s32 sourceCount;
    s32 maxSources;
    ALFilter **sources;
} ALMainBus;
void alMainBusNew(ALMainBus *m, void *ptr, s32 len);
Acmd *alMainBusPull(void *f, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);
s32 func_800ADEF0(void *filter, s32 paramID, void *param);
#define AL_MAX_AUX_BUS_SOURCES 8
#define AL_MAX_AUX_BUS_FX 1
typedef struct ALAuxBus_s {
    ALFilter filter;
    s32 sourceCount;
    s32 maxSources;
    ALFilter **sources;
    ALFx fx[1];
} ALAuxBus;
void alAuxBusNew(ALAuxBus *m, void *ptr, s32 len);
Acmd *alAuxBusPull(void *f, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);
s32 func_800AFAF0(void *filter, s32 paramID, void *param);
void alResampleNew(ALResampler *r, ALHeap *hp);
Acmd *alResamplePull(void *f, s16 *outp, s32 out, s32 sampleOffset, Acmd *p);
s32 alResampleParam(void *f, s32 paramID, void *param);
typedef struct ALSave_s {
    ALFilter filter;
    s32 dramout;
    s32 first;
} ALSave;
void alSaveNew(ALSave *r);
Acmd *alSavePull(void *f, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);
s32 alSaveParam(void *f, s32 paramID, void *param);
typedef struct ALEnvMixer_s {
    ALFilter filter;
    ENVMIX_STATE *state;
    s16 pan;
    s16 volume;
    s16 cvolL;
    s16 cvolR;
    s16 dryamt;
    s16 wetamt;
    u16 lratl;
    s16 lratm;
    s16 ltgt;
    u16 rratl;
    s16 rratm;
    s16 rtgt;
    s32 delta;
    s32 segEnd;
    s32 first;
    ALParam *ctrlList;
    ALParam *ctrlTail;
    ALFilter **sources;
    s32 motion;
} ALEnvMixer;
void alEnvmixerNew(ALEnvMixer *e, ALHeap *hp);
Acmd *alEnvmixerPull(void *f, s16 *outp, s32 out, s32 sampleOffset, Acmd *p);
s32 alEnvmixerParam(void *filter, s32 paramID, void *param);
typedef struct {
    s32 magic;
    s32 size;
    u8 *file;
    s32 line;
    s32 count;
    s32 pad0;
    s32 pad1;
    s32 pad2;
} HeapInfo;
#define AL_CACHE_ALIGN 15
typedef struct PVoice_s {
    ALLink node;
    struct ALVoice_s *vvoice;
    ALFilter *channelKnob;
    ALLoadFilter decoder;
    ALResampler resampler;
    ALEnvMixer envmixer;
    s32 offset;
} PVoice;
ALParam *__allocParam(void);
void __freeParam(ALParam *param);
void _freePVoice(ALSynth *drvr, PVoice *pvoice);
void _collectPVoices(ALSynth *drvr);
s32 _timeToSamples(ALSynth *ALSynth, s32 micros);
ALMicroTime _samplesToTime(ALSynth *synth, s32 samples);
#define __SNDP__ 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN_RATIO 0.0001
typedef enum {
    AL_SNDP_PLAY_EVT,
    AL_SNDP_STOP_EVT,
    AL_SNDP_PAN_EVT,
    AL_SNDP_VOL_EVT,
    AL_SNDP_PITCH_EVT,
    AL_SNDP_API_EVT,
    AL_SNDP_DECAY_EVT,
    AL_SNDP_END_EVT,
    AL_SNDP_FX_EVT
} ALSndpMsgType;
typedef struct {
    ALVoice voice;
    ALSound *sound;
    s16 priority;
    f32 pitch;
    s32 state;
    s16 vol;
    ALPan pan;
    u8 fxMix;
} ALSoundState;
typedef union {
    ALEvent msg;
    struct {
        s16 type;
        ALSoundState *state;
    } common;
    struct {
        s16 type;
        ALSoundState *state;
        s16 vol;
    } vol;
    struct {
        s16 type;
        ALSoundState *state;
        f32 pitch;
    } pitch;
    struct {
        s16 type;
        ALSoundState *state;
        ALPan pan;
    } pan;
    struct {
        s16 type;
        ALSoundState *state;
        u8 mix;
    } fx;
} ALSndpEvent;
extern ALMicroTime func_800A366C(void *node);
extern void _handleEvent(ALSndPlayer *sndp, ALSndpEvent *event);
extern void _removeEvents(ALEventQueue *evtq, ALSoundState *state);
extern s32 _DivS32ByF32 (s32 i, f32 f);

void func_800A2170(ALBank*,s32,s32);u32 osSetIntMask(u32);
#define OS_IM_NONE 1

typedef u32 OSIntMask;u32 osSetIntMask(u32);
#define osSetIntMask osSetIntMask

#define	_ABI_H_
#define	A_SPNOOP		0
#define	A_ADPCM			1
#define	A_CLEARBUFF		2
#define	A_ENVMIXER		3
#define	A_LOADBUFF		4
#define	A_RESAMPLE		5
#define A_SAVEBUFF	        6
#define A_SEGMENT		7
#define A_SETBUFF		8
#define A_SETVOL		9
#define A_DMEMMOVE              10
#define A_LOADADPCM             11
#define A_MIXER		        12
#define A_INTERLEAVE            13
#define A_POLEF                 14
#define A_SETLOOP               15
#define ACMD_SIZE               32
#define A_INIT			0x01
#define A_CONTINUE		0x00
#define A_LOOP                  0x02
#define A_OUT                   0x02
#define A_LEFT			0x02
#define	A_RIGHT			0x00
#define A_VOL			0x04
#define A_RATE			0x00
#define A_AUX			0x08
#define A_NOAUX			0x00
#define A_MAIN			0x00
#define A_MIX			0x10
#define ADPCMVSIZE	8
#define ADPCMFSIZE      16
#define UNITY_PITCH 0x8000
#define MAX_RATIO 1.99996	/* within .03 cents of +1 octave */
#define	aADPCMdec(pkt, f, s)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_ADPCM, 24, 8) | _SHIFTL(f, 16, 8);     \
	_a->words.w1 = (unsigned int)(s);				\
}
#define	aPoleFilter(pkt, f, g, s)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_POLEF, 24, 8) | _SHIFTL(f, 16, 8) |	\
			_SHIFTL(g, 0, 16)); 				\
	_a->words.w1 = (unsigned int)(s);				\
}
#define	aClearBuffer(pkt, d, c)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_CLEARBUFF, 24, 8) | _SHIFTL(d, 0, 24);	\
	_a->words.w1 = (unsigned int)(c);				\
}
#define	aEnvMixer(pkt, f, s)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_ENVMIXER, 24, 8) | _SHIFTL(f, 16, 8);	\
	_a->words.w1 = (unsigned int)(s);				\
}
#define	aInterleave(pkt, l, r)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_INTERLEAVE, 24, 8);    		\
	_a->words.w1 = _SHIFTL(l, 16, 16) | _SHIFTL(r, 0, 16);		\
}
#define	aLoadBuffer(pkt, s)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_LOADBUFF, 24, 8);			\
	_a->words.w1 = (unsigned int)(s);				\
}
#define	aMix(pkt, f, g, i, o)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_MIXER, 24, 8) | _SHIFTL(f, 16, 8) |	\
			_SHIFTL(g, 0, 16)); 				\
	_a->words.w1 = _SHIFTL(i,16, 16) | _SHIFTL(o, 0, 16);		\
}
#define	aPan(pkt, f, d, s)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_PAN, 24, 8) | _SHIFTL(f, 16, 8) |	\
			_SHIFTL(d, 0, 16)); 				\
	_a->words.w1 = (unsigned int)(s);				\
}
#define	aResample(pkt, f, p, s)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_RESAMPLE, 24, 8) | _SHIFTL(f, 16, 8) |\
			_SHIFTL(p, 0, 16)); 				\
	_a->words.w1 = (unsigned int)(s);				\
}
#define	aSaveBuffer(pkt, s)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_SAVEBUFF, 24, 8);			\
	_a->words.w1 = (unsigned int)(s);				\
}
#define	aSegment(pkt, s, b)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_SEGMENT, 24, 8);			\
	_a->words.w1 = _SHIFTL(s, 24, 8) | _SHIFTL(b, 0, 24);		\
}
#define	aSetBuffer(pkt, f, i, o, c)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_SETBUFF, 24, 8) | _SHIFTL(f, 16, 8) |	\
			_SHIFTL(i, 0, 16)); 				\
	_a->words.w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16);		\
}
#define	aSetVolume(pkt, f, v, t, r)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_SETVOL, 24, 8) | _SHIFTL(f, 16, 16) |	\
			_SHIFTL(v, 0, 16)); 				\
	_a->words.w1 = _SHIFTL(t, 16, 16) | _SHIFTL(r, 0, 16);		\
}
#define aSetLoop(pkt, a)                                                \
{                                                                       \
        Acmd *_a = (Acmd *)pkt;                                         \
        _a->words.w0 = _SHIFTL(A_SETLOOP, 24, 8);                       \
        _a->words.w1 = (unsigned int)(a);                               \
}
#define	aDMEMMove(pkt, i, o, c)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_DMEMMOVE, 24, 8) | _SHIFTL(i, 0, 24);	\
	_a->words.w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16);		\
}
#define	aLoadADPCM(pkt, c, d)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_LOADADPCM, 24, 8) | _SHIFTL(c, 0, 24);	\
        _a->words.w1 = (unsigned int) d;                                \
}

#define _SHIFTL(v,s,w) ((u32)(((u32)(v) & ((1U << (w))-1)) << (s)))
u32 osVirtualToPhysical(void*);

#define ADPCMFBYTES 9
#define LFSAMPLES 4
extern s16 D_800EF540[128];
#define eqpower D_800EF540

Acmd *func_800AE5C0(Acmd *ptr, ALLoadFilter *f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags)

;

extern
Acmd* func_800AF254(void *filter, s16 *inp, s16 *outp, s32 outCount,
                    s32 sampleOffset, Acmd *p) 
;

extern
f32 func_800AF4EC(f32 ivol, s32 samples, s16 ratem, u16 ratel)
;

f32 _doModFunc(ALDelay *d, s32 count)
;

Acmd *_loadBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
;

Acmd *_saveBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
;

Acmd *_loadOutputBuffer(ALFx *r, ALDelay *d, s32 buff, s32 incount, Acmd *p)
;

Acmd *_filterBuffer(ALLowPass *lp, s32 buff, s32 count, Acmd *p)
;

s32 alFxParamHdl(void*,s32,void*);void init_lpfilter(ALLowPass*);

#define EQPOWER_LENGTH 128
#define RANGE 2.0
typedef s32 (*ALSetFXParam)(void*,s32,void*);
extern s32 D_800EF518[];
#define NULL_PARAMS D_800EF518
extern s32 D_800EF3B0[];
#define SMALLROOM_PARAMS D_800EF3B0
extern s32 D_800EF418[];
#define BIGROOM_PARAMS D_800EF418
extern s32 D_800EF4F0[];
#define ECHO_PARAMS D_800EF4F0
extern s32 D_800EF4A0[];
#define CHORUS_PARAMS D_800EF4A0
extern s32 D_800EF4C8[];
#define FLANGE_PARAMS D_800EF4C8

#define alFilterNew alFilterNew
void alFilterNew(ALFilter*,ALCmdHandler,ALSetParam,s32);

void __freeParam(ALParam*);
#define _freeParam __freeParam

#define __freeParam __freeParam
#define assert(x) ((void)0)
#define alFxParam alFxParam
s32 alFxParam(void*,s32,void*);
#undef ECHO_PARAMS
#undef CHORUS_PARAMS
#undef FLANGE_PARAMS
#define ECHO_PARAMS D_800EF4A0
#define CHORUS_PARAMS D_800EF4C8
#define FLANGE_PARAMS D_800EF4F0

#define K0_TO_PHYS(x) ((u32)(x)&0x1FFFFFFF)

#define SWAP(in,out) {s16 t=out;out=in;in=t;}

#define osSetIntMask osSetIntMask
