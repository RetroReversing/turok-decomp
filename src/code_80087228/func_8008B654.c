#include "common.h"

int audio_debug_flag = 0;
int params[4*8 +2] =
{
  4, 180 *(((int) ((float) 22050/1000))&~0x7),
 0 *(((int) ((float) 22050/1000))&~0x7), 38 *(((int) ((float) 22050/1000))&~0x7), 3276, -3276, 0x11eb, 0, 0, 0,
 0 *(((int) ((float) 22050/1000))&~0x7), 56 *(((int) ((float) 22050/1000))&~0x7), 3276, -3276, 0x15eb, 0, 0, 0,
 0 *(((int) ((float) 22050/1000))&~0x7), 70 *(((int) ((float) 22050/1000))&~0x7), 3276, -3276, 0x15eb, 0, 0, 0,
 20 *(((int) ((float) 22050/1000))&~0x7), 150 *(((int) ((float) 22050/1000))&~0x7), 10000, 0, 0x21eb, 0, 0, 0x5000,
};
float __GlobalSFXscalar = 1.0;
signed short __GlobalSEQvolume = 32000;
int stop_channel = -1;
int global_seqnum = -1;
int SeqStateFlags = (1 << 4);
int SeqStateAction = 0;
int testhandle = -1; int ObstructedFadeVol = 32000;  typedef unsigned char sa_u8;
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
typedef struct {
 unsigned char flag;
 unsigned char v[3];
} Tri;
typedef long Mtx_t[4][4];
typedef union {
    Mtx_t m;
    long long int force_structure_alignment;
} Mtx;
typedef struct {
 int cmd:8;
 unsigned int par:8;
 unsigned int len:16;
 unsigned int addr;
} Gdma;
typedef struct {
  int cmd:8;
  int pad:24;
  Tri tri;
} Gtri;
typedef struct {
  int cmd:8;
  int pad1:24;
  int pad2:24;
  unsigned char param:8;
} Gpopmtx;
typedef struct {
  int cmd:8;
  int pad0:8;
  int mw_index:8;
  int number:8;
  int pad1:8;
  int base:24;
} Gsegment;
typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeL;
typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeH;
typedef struct {
  unsigned char cmd;
  unsigned char lodscale;
  unsigned char tile;
  unsigned char on;
  unsigned short s;
  unsigned short t;
} Gtexture;
typedef struct {
  int cmd:8;
  int pad:24;
  Tri line;
} Gline3D;
typedef struct {
  int cmd:8;
  int pad1:24;
  short int pad2;
  short int scale;
} Gperspnorm;
typedef struct {
                int cmd:8;
                unsigned int fmt:3;
                unsigned int siz:2;
                unsigned int pad:7;
                unsigned int wd:12;
                unsigned int dram;
} Gsetimg;
typedef struct {
  int cmd:8;
  unsigned int muxs0:24;
  unsigned int muxs1:32;
} Gsetcombine;
typedef struct {
  int cmd:8;
  unsigned char pad;
  unsigned char prim_min_level;
  unsigned char prim_level;
  unsigned long D_80130D78;
} Gsetcolor;
typedef struct {
  int cmd:8;
  int x0:10;
  int x0frac:2;
  int y0:10;
  int y0frac:2;
  unsigned int pad:8;
  int x1:10;
  int x1frac:2;
  int y1:10;
  int y1frac:2;
} Gfillrect;
typedef struct {
  int cmd:8;
  unsigned int fmt:3;
  unsigned int siz:2;
  unsigned int pad0:1;
  unsigned int line:9;
  unsigned int tmem:9;
  unsigned int pad1:5;
  unsigned int tile:3;
  unsigned int palette:4;
  unsigned int ct:1;
  unsigned int mt:1;
  unsigned int maskt:4;
  unsigned int shiftt:4;
  unsigned int cs:1;
  unsigned int ms:1;
  unsigned int masks:4;
  unsigned int shifts:4;
} Gsettile;
typedef struct {
  int cmd:8;
  unsigned int sl:12;
  unsigned int tl:12;
  int pad:5;
  unsigned int tile:3;
  unsigned int sh:12;
  unsigned int th:12;
} Gloadtile;
typedef Gloadtile Gsettilesize;
typedef Gloadtile Gloadtlut;
typedef struct {
 unsigned int w0;
 unsigned int w1;
} Gwords;
typedef union {
 Gwords words;
 Gdma dma;
 Gtri tri;
 Gline3D line;
 Gpopmtx popmtx;
 Gsegment segment;
 GsetothermodeH setothermodeH;
 GsetothermodeL setothermodeL;
 Gtexture texture;
 Gperspnorm perspnorm;
 Gsetimg setimg;
 Gsetcombine setcombine;
 Gsetcolor D_80095060;
 Gfillrect fillrect;
 Gsettile settile;
 Gloadtile loadtile;
 Gsettilesize settilesize;
 Gloadtlut loadtlut;
        long long int force_structure_alignment;
} Gfx;
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
    ALInstrument *instrument;
    sa_s16 bendRange;
    ALFxId fxId;
    ALPan pan;
    sa_u8 priority;
    sa_u8 vol;
    sa_u8 fxmix;
    sa_u8 sustain;
    sa_f32 pitchBend;
} ALChanState;
typedef struct {
    sa_u32 trackOffset[16];
    sa_u32 division;
} ALCMidiHdr;
typedef struct ALCSeq_s {
    ALCMidiHdr *base;
    sa_u32 validTracks;
    sa_f32 qnpt;
    sa_u32 lastTicks;
    sa_u32 lastDeltaTicks;
    sa_u32 deltaFlag;
    sa_u8 *curLoc[16];
    sa_u8 *curBUPtr[16];
    sa_u8 curBULen[16];
    sa_u8 lastStatus[16];
    sa_u32 evtDeltaTicks[16];
} ALCSeq;
typedef ALMicroTime (*ALOscInit)(void **oscState,sa_f32 *initVal, sa_u8 oscType,
                                   sa_u8 oscRate, sa_u8 oscDepth, sa_u8 oscDelay);
typedef ALMicroTime (*ALOscUpdate)(void *oscState, sa_f32 *updateVal);
typedef void (*ALOscStop)(void *oscState);
typedef struct {
    ALPlayer node;
    ALSynth *drvr;
    ALCSeq *target;
    ALMicroTime curTime;
    ALBank *bank;
    sa_s32 uspt;
    sa_s32 nextDelta;
    sa_s32 state;
    sa_u16 chanMask;
    sa_s16 vol;
    sa_u8 maxChannels;
    sa_u8 debugFlags;
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
extern void D_800A4CD0(ALCSPlayer *D_8012EF2C);
struct CAssoc_t;
struct CHashPlex_t;
typedef struct CHashTable_t
{
 struct CAssoc_t **m_pHashTable;
 unsigned long m_nHashTableSize;
 int m_nCount;
 struct CAssoc_t *m_pFreeList;
 struct CHashPlex_t *m_pBlocks;
 int m_nBlockSize;
} CHashTable;
typedef ROMAddress;
struct CCartCache_t;
typedef struct CCacheEntry_t
{
   void *m_pData;
 unsigned long m_DataLength;
   ROMAddress *m_rpAddress;
   unsigned long m_rLength;
 struct CCartCache_t *m_pOwner;
 unsigned long m_LastAccessed;
   int m_InHashTable,
      m_Compressed;
 unsigned long m_Allocated;
   const char *m_szDescription;
   struct CCacheEntry_t *m_pLast, *m_pNext,
         *m_pNextFree;
} CCacheEntry;
typedef void (*pfnCACHENOTIFY)(void *pNotifyPtr, CCacheEntry **ppceTarget);
typedef struct CNotifyEntry_t
{
   void *m_pNotifyPtr;
   pfnCACHENOTIFY m_pfnDecompress,
                  m_pfnBlockReceived;
   CCacheEntry **m_ppceTarget;
   ROMAddress *m_rpRequestedAddress;
   unsigned long m_rLength;
   const char *m_szDescription;
   struct CNotifyEntry_t *m_pLast, *m_pNext,
         *m_pNextFree;
} CNotifyEntry;
typedef struct CCartCache_t
{
   CHashTable m_HashTable;
   CNotifyEntry *m_pNotifyHead, *m_pNotifyTail;
   CCacheEntry *m_pCacheHead, *m_pCacheTail;
   int m_DiscardAge;
 CCacheEntry m_CacheEntries[512];
 CCacheEntry *m_pCacheFreeHead;
 CNotifyEntry m_NotifyEntries[16];
 CNotifyEntry *m_pNotifyFreeHead;
} CCartCache;
struct CQuatern_t;
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
typedef struct CGameAnimateState_t
{
 CCacheEntry *m_pceAnim;
 unsigned long m_nAnim,
      m_nDesiredAnim,
      m_nFrames;
 float m_cFrame;
 int m_CycleCompleted;
} CGameAnimateState;
typedef struct CGeometry_t
{
 CCacheEntry *m_pceGeometry,
         *m_pceTextureSetsIndex;
} CGeometry;
struct CCacheEntry_t;
typedef struct CTextureLoader_t
{
 struct CCacheEntry_t *m_pceTextureSet;
 ROMAddress *m_rpTextureSet;
 unsigned long m_TextureSetSize;
} CTextureLoader;
struct CGameObjectInstance_t;
struct CGameRegion_t;
typedef struct CEnemyAttributes_t
{
 float m_SightRadius,
     m_SightAngle,
     m_LoudRadius,
     m_QuietRadius,
     m_ProjectileRadius,
     m_FlyingHeight,
     m_CollisionRadius,
     m_CollisionWallRadius,
     m_CollisionHeight,
     m_DeadHeight,
     m_AttackRadius,
     m_LeashRadius,
     m_InteractiveAnimDelay;
 unsigned long m_dwSpecies,
     m_dwTypeFlags,
     m_dwTypeFlags2;
 unsigned short m_wTypeFlags3;
 short m_StartHealth,
     m_Id,
     m_DeathId,
     m_Regenerate;
 unsigned char m_Aggression,
     m_InteractiveAnim,
     m_nModel;
 signed char m_nTexture,
     m_AttackStyle;
 unsigned char unused1;
} CEnemyAttributes;
typedef struct CAIDynamic_t
{
 float m_ViewAngleOffset,
     m_RetreatTimer,
     m_TeleportTime,
     m_Time1,
     m_Time2,
     m_InteractiveTimer,
     m_AvoidanceAngle,
     m_cRegenerateAppearance,
     m_cRegenerateAppearanceWhite,
     m_MeltTimer,
     m_FreezeTimer;
 unsigned long m_dwStatusFlags,
     m_dwStatusFlags2;
 short m_Agitation,
     m_PrevAgitation,
     m_Health,
     m_Evade,
     m_Regenerate;
 CVector3 m_vExplosion,
     m_vLeashCoor,
     m_vStartPos;
 int m_Invincible,
     m_FirstRun;
 int m_DeathAnimType;
 struct CGameRegion_t *m_pStartRegion;
 short m_HeadTexture,
     m_BodyTexture ;
 short m_WeaponModel,
     m_ExtraModel ;
} CAIDynamic;
struct CCollisionInfo2_t;
typedef unsigned short SF;
typedef struct CROMCorner_t
{
   CVector3 m_vCorner;
   float m_Ceiling;
} CROMCorner;
typedef struct CGameRegion_t
{
 unsigned short m_nRegionSet,
        m_wFlags;
 CROMCorner *m_pCorners[3];
 struct CGameRegion_t *m_pNeighbors[3];
} CGameRegion;
typedef struct CBoundsRect_t
{
 float m_MinX, m_MinZ,
      m_MaxX, m_MaxZ;
} CBoundsRect;
typedef struct CInstanceHdr_t
{
 unsigned char m_Type,
       m_bActiveFlags;
 unsigned short m_nObjType;
 CVector3 m_vPos;
 float m_CollisionHeightOffset;
 CGameRegion *m_pCurrentRegion;
 CEnemyAttributes *m_pEA;
} CInstanceHdr;
typedef struct CAnimInstanceHdr_t
{
 CInstanceHdr ih;
 CVector3 m_vVelocity;
} CAnimInstanceHdr;
typedef struct CGameObjectInstance_t
{
 CAnimInstanceHdr ah;
   CVector3 m_vScale;
 CQuatern m_qRot,
        m_qGround,
        m_qShadow;
 float m_RotY,
        m_cMelt,
        m_ShadowPercentage;
 Mtx m_mOrientation[2];
 CGeometry m_Geometry;
 Mtx *pmtDrawMtxs ;
 ROMAddress *m_rpObject,
        *m_rpObjectInfo,
        *m_rpAnims;
 CCacheEntry *m_pceObjectIndex,
        *m_pceObjectInfo,
        *m_pceAnimsHeader,
        *m_pceAnimsIndex;
 unsigned short m_ObjectInfoSize,
        m_nTypeFlag;
 short m_nAnims,
        m_nDesiredAnim;
 CBoundsRect m_BoundsRect;
 unsigned long m_dwFlags;
 CGameAnimateState m_asCurrent,
        m_asBlend;
 short m_BlendLength,
        m_WaitingForAnim,
        m_StartupAnimType;
 signed short m_Mode ;
 float m_ModeTime ;
 float m_ModeMisc1 ;
 float m_uBlender,
        m_BlendPos;
 struct CBoss_t *m_pBoss ;
 void (*m_pCollisionFunction)(void *pThis, struct CCollisionInfo2_t *pCollisionInfo) ;
 CQuatern(*m_pCalculateOrientation)(void *pThis) ;
 unsigned char m_BlendStart,
         m_BlendFinish;
 signed short m_ActiveSwooshes ;
 float m_HeadTrackBlend ;
 float m_HeadTurnAngle ;
 float m_HeadTurnAngleVel ;
 float m_HeadTiltAngle ;
 float m_HeadTiltAngleVel ;
 struct CHeadTrackInfo_t *m_pHeadTrackInfo ;
 CAIDynamic m_AI;
 struct CGameObjectInstance_t *m_pEventCGameObjectInstance;
 struct CGameObjectInstance_t *m_pAttackerCGameObjectInstance;
} CGameObjectInstance;
typedef struct CROMParticleImpact_t
{
 float m_ImpactEventNumber[14];
 unsigned short m_ImpactParticleType[14],
     m_ImpactEventType[14],
     m_ImpactSoundType[14];
} CROMParticleImpact;
typedef struct CROMParticleEffect_t
{
 CROMParticleImpact *m_pImpact;
 unsigned long m_dwFlags;
 SF m_BounceEnergy,
     m_DirectionSpray,
     m_SprayX,
     m_SprayY,
     m_SprayZ,
     m_DirectionX,
     m_DirectionY,
     m_DirectionZ,
     m_Gravity,
     m_GravityRandom,
     m_GroundFriction,
     m_FpsVelThreshold,
     m_AirFriction,
     m_WaterFriction,
     m_Size,
     m_SizeRandom,
     m_Scaler,
     m_ScalerRandom,
     m_Velocity,
     m_VelocityRandom,
     m_PosRandomX,
     m_PosRandomY,
     m_PosRandomZ,
     m_Rotation,
     m_RotationRandom,
     m_RotationInc,
     m_RotationIncRandom,
     m_RotationPivotX,
     m_RotationPivotY,
     m_PosX,
     m_PosY,
     m_PosZ;
 short m_nTextureSet,
     m_nParticles,
     m_nParticleRandom,
     m_nParticleFrames,
     m_nParticleFrameRandom,
     m_nParticleDelayFramesRandom;
 unsigned char m_FPS,
     m_InstanceBehavior,
     m_WallBehavior,
     m_GroundBehavior,
     m_Alignment,
     m_WhiteColor[3],
     m_BlackColor[3],
     m_RandomizeHue,
     m_RandomizeSaturation,
     m_RandomizeBrightness,
     m_Priority,
     m_Playback,
     m_Visibility,
     m_nFadeInDelay,
     m_nFadeOutDelay,
     unused;
} CROMParticleEffect;
struct CAnimInstanceHdr_t;
struct CCollisionInfo2_t;
typedef enum ECollisionResult_t
{
 CR_NO_COLLISION,
 CR_NO_COLLISION_NEWDESIREDPOS,
 CR_COLLISION,
 CR_COLLISION_NEWDESIREDPOS
} ECollisionResult;
typedef struct CClosestIntersect_t
{
 float t;
 ECollisionResult cr;
 CVector3 vNextVelocity,
       vNextDesired,
       vIntersect;
 CVector3 *pvIntersectPos;
 struct CGameRegion_t **ppRegion;
 int *pCollType,
       CollType;
 CInstanceHdr **ppInst,
       *pInstType;
} CClosestIntersect;
typedef struct CCollide_t
{
 struct CAnimInstanceHdr_t *pInst;
 struct CCollisionInfo2_t *pCI;
 CClosestIntersect clint;
 CVector3 vDesired,
       vDelta,
       vSliding,
       vNextSliding;
 float SlidingRadius,
       NextSlidingRadius;
 int SlidingType,
       NextSlidingType;
 int AllowRedirection,
       UsePhysics,
       TrackingGround,
       StartedInDeathFall;
} CCollide;
struct CInstanceHdr_t;
struct CGameRegion_t;
typedef struct CCollisionInfo2_t
{
 unsigned long dwFlags;
 int InstanceBehavior,
         WallBehavior,
         GroundBehavior;
 float GravityAcceleration,
         BounceReturnEnergy,
         GroundFriction,
         AirFriction,
         WaterFriction;
 struct CInstanceHdr_t *pInstanceCollision;
 struct CGameRegion_t *pInstanceCollisionRegion;
 CVector3 vInstanceCollisionPos;
 struct CGameRegion_t *pWallCollisionRegion;
 CVector3 vWallCollisionPos;
 int nWallCollisionEdge;
 int nGroundCollisionType;
 struct CGameRegion_t *pGroundCollisionRegion;
 CVector3 vGroundCollisionPos;
 struct CGameRegion_t *pWaterCollisionRegion;
 CVector3 vWaterCollisionPos;
 CVector3 vCollisionVelocity;
} CCollisionInfo2;
typedef struct CParticle_t
{
 CAnimInstanceHdr ah;
 Mtx m_mOrientation[2];
 CROMParticleEffect *m_pEffect;
 CTextureLoader m_TextureLoader;
 CInstanceHdr *m_pSource;
 unsigned long m_dwFlags;
 float m_cFrame,
        m_cFramePos,
        m_FPS;
 int m_nFrames,
        m_cAnimFrame,
        m_nRandomFrame;
 float m_Size, m_SizeScaler,
        m_Rotation,
        m_RotationInc,
        m_DistanceSquared;
 unsigned char m_AlphaScaler ;
 unsigned char m_ActiveSwooshes ;
 CCollisionInfo2 m_CI;
 short m_Alignment;
 unsigned char m_WhiteColor[3],
        m_BlackColor[3];
 struct CParticle_t *m_pLast, *m_pNext,
        *m_pDrawLast, *m_pDrawNext;
} CParticle;
typedef struct COverlay_t
{
 int m_OnScreen ;
 signed long *m_pScript,
   m_Mode,
   m_Time ;
 float m_X,
   m_Y,
   m_FinalX,
   m_FinalY,
   m_XVel,
   m_YVel,
   m_XAccel,
   m_YAccel,
   m_ZoomFactor ;
} COverlay ;
typedef struct COnScreen_t
{
 signed short m_SelectionTimer ;
 int m_ExplosiveAmmo ;
 int m_BarrelDirection ;
 int m_AirMode ;
 float m_AirOpacity;
 int m_BossBarMode ;
 float m_BossBarOpacity;
 float m_FlashTimer;
 char m_FlashDraw;
 int m_TopR,
    m_TopG,
    m_TopB,
    m_BottomR,
    m_BottomG,
    m_BottomB ;
 float m_FontXScale,
    m_FontYScale ;
 int m_ShadowXOff,
    m_ShadowYOff ;
 int m_HealthAlert,
    m_ArmorAlert ;
 signed long m_Ammo,
    m_Health,
    m_Armor,
    m_HealthArmourIcon,
    m_Lives,
    m_Tokens,
    m_WalkRunIcon;
 float m_CompassPos,
    m_CompassAccel ;
 COverlay m_AmmoOverlay,
    m_HealthOverlay,
    m_LivesOverlay,
    m_TokensOverlay,
    m_WeaponOverlay,
    m_RunWalkOverlay;
 struct CBoss_t *m_pBoss ;
 sa_u8 m_SelectPosition ;
} COnScreen ;
typedef struct t_RGB
{
 float Red,Green,Blue, Alpha ;
} CRGB ;
typedef struct t_PsuedoColor
{
 CRGB m_WhiteColor ;
 CRGB m_BlackColor ;
} CPsuedoColor ;
typedef struct CShield_t
{
 signed short m_Health ;
 signed short m_StartHealth ;
 signed short m_Mode ;
 signed short m_TotalColors ;
 CPsuedoColor *m_pColors ;
 float m_Alpha ;
 float m_Time ;
 CParticle *m_pParticle ;
 CPsuedoColor *m_pColor ;
 CGameObjectInstance *m_pOwner ;
 signed long m_SoundHandle ;
} CShield ;
typedef struct CBoss_t
{
 int m_Alive ;
 int m_Initialized ;
 signed long m_ObjectType ;
 signed long m_StartHealth ;
 signed long m_LastHealth ;
 signed long m_LastPercentageHealth ;
 signed long m_PercentageHealth ;
 signed long m_EventFlags ;
 signed long m_Mode, m_OldMode, m_LastMode ;
 float m_ModeTime ;
 signed long m_OldModeFlags, m_ModeFlags ;
 float m_MoveTime ;
 signed long m_AnimPlayed ;
 signed long m_AnimEndFrame ;
 int m_AnimPastEnd ;
 signed long m_AnimRepeats ;
 signed long m_Stage ;
 CCollisionInfo2 m_CollisionInfo ;
 float m_AnimSpeed ;
 float m_ModeAnimSpeed ;
 float m_PlaybackAnimSpeed ;
 float m_Speed ;
 float m_RotX, m_RotZ ;
 CVector3 m_LastPos, m_LastVel, m_LastDir ;
 signed short m_Action ;
 signed short m_ActionStage ;
 float m_ActionTime ;
 float m_LookDeltaAngle ;
 float m_DeltaAngle ;
 CVector3 m_vTarget ;
 float m_DistFromTarget ;
 float m_DistFromTargetSqr ;
 float m_Rot1 ;
 float m_Rot2 ;
 float m_Rot3 ;
 float m_Rot4 ;
 float m_Rot5 ;
 float m_DistFromTurok ;
 float m_TurokAngle ;
 float m_TurokAngleDiff ;
 float m_TurokAngleDist ;
 float m_AtTargetDist ;
 float m_TurokDeltaAngle ;
 float m_LastTurokDeltaAngle ;
 float m_AbsTurokDeltaAngle ;
 CShield *m_pShield ;
 void(*m_pInitializeFunction)(void *pThis, void *pBoss) ;
 void(*m_pUpdateFunction)(void *pThis, void *pBoss ) ;
 void (*m_pHitByParticleFunction)(void *pThis, void *pBoss, void *pParticle) ;
 struct CBossModeInfo_t *m_pModeTable ;
 void (*m_pPreDrawFunction)(void *pThis, void *pBoss, Gfx **ppDLP) ;
 void (*m_pPostDrawFunction)(void *pThis, void *pBoss, Gfx **ppDLP) ;
 void (*m_pPauseFunction)(void *pThis, void *pBoss) ;
 void (*m_pRestoreFunction)(void *pThis, void *pBoss) ;
} CBoss ;
typedef struct CBossModeInfo_t
{
 void(*m_pSetupFunction)(CGameObjectInstance *pThis, CBoss *pBoss) ;
 void(*m_pUpdateFunction)(CGameObjectInstance *pThis, CBoss *pBoss) ;
 signed long m_Anim ;
 float m_AnimSpeed ;
 signed long m_Flags ;
} CBossModeInfo ;
typedef struct CBossData_t
{
 CGameObjectInstance *m_pObject ;
 CBoss *m_pBossVars ;
 void (*m_pCollisionFunction)(CGameObjectInstance *pThis, CCollisionInfo2 *pCollisionInfo) ;
 CVector3 m_vPos ;
 float m_RotY ;
 int m_IsGone ;
 signed long m_Anim ;
 signed long m_CurrentAnimFrame ;
 unsigned long m_BossDataSize ;
 unsigned char m_BossData[800] ;
 CAIDynamic m_AIDynamicData ;
 signed short m_Mode ;
 float m_ModeTime ;
 float m_ModeMisc1 ;
} CBossData ;
extern void func_8008B490();
extern void func_8008B654();
extern int func_8008B5AC(int nTune);
extern signed short D_800ECF50;
extern ALCSPlayer *D_8012EF2C;
struct CCollisionInfo2_t;
typedef struct
{
 float MoveSpeed,
   TurnSpeed,
   ActualTurnSpeed,
   MoveCnt,
   YRotCnt,
   HeadXRot,
   HeadYRot,
   HeadZRot,
   HeadYPos,
   SpdChgXOffset,
   SpdChgX,
   RunTime,
   SideStepSpeed,
   HeadZRoll,
   HeadZRollCnt,
   HeadYPosLand,
   JumpUpForce,
   JumpLookAng,
   GunKickXRot,
   WeaponBarrelZRot,
   WeaponBarrelZRotInc,
   HeadYPosCFrame,
   JumpAngle,
   StartJumpAngle,
   DesiredJumpAngle,
   JumpU,
   ActualRotXPlayer,
   ActualRotYPlayer,
   RotXPlayer,
   RotYPlayer,
   RotZPlayer,
   MoveUpSpeed,
   OxygenTank,
   Oxygen,
   Time1,
   Time2,
   SideStepZRot,
   BurstForwardSpeed,
   ActualBurstForwardSpeed,
   ClimbSwingRotX,
   ClimbSwingRotY,
   ClimbSwingRotZ,
   ActualClimbSwingRotX,
   ActualClimbSwingRotY,
   ActualClimbSwingRotZ,
   CurrentDuckOffset,
   ClimbSideStepLookAng,
   BurstTimer,
   SelectWeaponTimer,
   LookUpDownSpeed,
   ActualLookUpDownSpeed,
   SwimBankAngle,
   ActualSwimBankAngle,
   WaterSfxTimer,
   WaterSfxTimerMax,
   BubblesSfxTimer,
   DeathRegionTimer,
   ShockwaveStarted,
   ChronoscepterStarted,
   PrevVelocityY,
   CombatTimer,
   DeathTimer,
   HitSoundTimer,
   BowStarted,
   TremorTimer,
   TremorTimerMax,
   TremorAngle,
   TremorShake,
   TremorZRot,
   AmmoUseCounter,
   MapButtonTimer,
   RealMapOffsetX,
   RealMapOffsetZ,
   MapOffsetX,
   MapOffsetZ,
   WeaponTimer,
   LookAtShover,
   InvincibleTimer;
 int MaxHealth ;
 int CheatGiven ;
 int BulletPool,
   ShotgunPool,
   EnergyPool ;
 int ExpTekBowAmmo,
   ExpShotgunPool ;
 int KnifeAmmo,
   TomahawkAmmo,
   TekBowAmmo,
   MiniGunAmmo,
   GrenadeLauncherAmmo,
   RocketAmmo,
   TechWeapon2Ammo,
   ChronoscepterAmmo;
 int ArmorAmount ;
 int KnifeFlag,
   TomahawkFlag,
   TekBowFlag,
   SemiAutomaticPistolFlag,
   RiotShotgunFlag,
   AutomaticShotgunFlag,
   AssaultRifleFlag,
   MachineGunFlag,
   MiniGunFlag,
   GrenadeLauncherFlag,
   TechWeapon1Flag,
   RocketFlag,
   ShockwaveFlag,
   TechWeapon2Flag,
   ChronoscepterFlag;
 int ArmorFlag ;
 int BackPackFlag ;
 int LastKeyTexture ;
 int D_800ED8F0,
   D_800ED92C,
   D_800ED968,
   D_800ED9A4,
   D_800ED9E0,
   D_800EDA1C,
   D_800EDA4C ;
 int Level2Access,
   Level3Access,
   Level4Access,
   Level5Access,
   Level6Access,
   Level7Access,
   Level8Access ;
 int ChronoSceptorPieces ;
 int SpdChg,
   Jumped,
   DoubleJump,
   WeaponUsed,
   WeaponChanged,
   WeaponEmpty,
   MiniGunBarrelSFX,
   RunWalkToggle,
   SwimBurstToggle,
   CannotSwimUp,
   ClimbHand,
   ClimbOneHand,
   FiredParticle,
   FiredParticleType,
   FiredProjectileParticle,
   FiredProjectileParticleType,
   ClimbCameraWobble,
   ClimbWeaponRemove,
   JumpAllowed,
   ClimbSideStep,
   CannotJumpFromSurface,
   PrevOnGround,
   CurrentOnGround,
   JustWarped,
   JustEnteredDeathRegion,
   JustEnteredSaveRegion,
   JustEnteredLockRegion,
   JustEnteredTrainingRegion,
   OxygenOut,
   OnLadder,
   InAntiGrav,
   PrevAntiGrav,
   HitSoundTimerScream,
   CannotJumpFromCliffFace,
   BowFlashOccurred,
   FiredBullet1,
   FiredBullet2,
   FiredBullet3,
   FiredShotgunShell,
   MapToggle,
   MapScrolling,
   InLava,
   FireFirstMachineGunBullet,
   AllWeaponsAmmoGiven,
   WeaponTakeOffQuickly,
   JustEnteredPressurePlate,
   Active,
   InSun;
 sa_u8 Mode,
   PrevMode,
   WeaponSelect,
   WeaponSelectIndex,
   WeaponCurrent,
   WeaponCurrentAnim,
   WeaponMode,
   DeathStage;
 sa_s8 WeaponCount;
 int WeaponFired,
   hSFXBarrel,
   Bubbles,
   FeetOnBottomStatus,
   WeaponAtStartOfClimb,
   WeaponAtStartOfWaterDive,
   WeaponAtStartOfDuck,
   Tokens,
   Lives,
   WaterFlag,
   hSFXPrevShockwaveCharge,
   hSFXNextShockwaveCharge;
 float SpiritualTime;
 unsigned long CurrentCheckpoint;
 CVector3 vLastPosition,
     vTremorPos;
 CQuatern qRealAimFix,
     qAimFix;
 CGameObjectInstance *pShoverAI,
        *pModifyEnemy;
 unsigned char MusicID,
     AmbientSound;
 float InMenuTimer ;
 CCollisionInfo2 *pLastCI;
} CTMove;
extern CTMove D_80128C20;
extern signed short D_800ECF50 ;
extern ALCSeq *seq;
extern ALCSPlayer *D_8012EF2C;
extern int D_800ECF58 ;
extern int D_800ECF5C ;
extern int D_800ECF60 ;
extern int D_8012EF30;
void func_8008B490();
int func_8008B5AC(int nTune);
void func_8008B654();
void func_8008B654(){
 int nRequestedSeq = D_80128C20.MusicID;
 static int load_timeout = 0;
 switch(D_800ECF5C)
 {
  case (1 << 5):
   if(D_800ECF60 & (1 << 2))
   {
    D_800ECF60 = 0;
    D_800ECF58 = -1;
    D_800ECF5C = (1 << 6);
   }
   break;
  case (1 << 6):
                                                    ;
   if (func_8008B5AC(nRequestedSeq))
   {
    D_800ECF5C = (1 << 7);
   }
   else
   {
    D_800ECF5C = (1 << 8);
    load_timeout = 0;
    D_800ECF60 = 0;
   }
   break;
  case (1 << 8):
   if( D_800ECF60 & (1 << 3))
   {
    D_800ECF5C = (1 << 7);
    D_800ECF60 = 0;
   }
   else
   {
    load_timeout++;
    if( load_timeout >= 10)
    {
     D_800ECF58 = -1;
     D_800ECF5C = (1 << 6);
                             ;
    }
   }
   break;
  case (1 << 7):
   func_8008B490();
   D_800A4CD0(D_8012EF2C);
   D_800ECF58 = nRequestedSeq ;
   D_800ECF60 = 0;
   D_800ECF5C = (1 << 4);
   break;
  case (1 << 4):
  default:
   if (D_800ECF58 != nRequestedSeq)
   {
                                                                   ;
    if(D_800ECF58 >= 0)
    {
     D_800ECF60 = 0;
     D_8012EF30 = D_800ECF50;
     D_800ECF60 = (1 << 1);
     D_800ECF5C = (1 << 5);
    }
    else
    {
     D_800ECF60 = 0;
     D_800ECF5C = (1 << 6);
    }
   }
   break;
 }
}
