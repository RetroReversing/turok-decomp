#include "common.h"

typedef unsigned char sa_u8;
typedef unsigned short sa_u16;
typedef unsigned long sa_u32;
typedef unsigned long long sa_u64;
typedef signed char sa_s8;
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
typedef sa_u64 OSTime;
typedef struct {
 sa_u16 button;
 sa_s8 stick_x;
 sa_s8 stick_y;
 sa_u8 errno;
} OSContPad;
typedef struct {
 sa_u32 type;
 sa_u32 flags;
 sa_u64 *ucode_boot;
 sa_u32 ucode_boot_size;
 sa_u64 *ucode;
 sa_u32 ucode_size;
 sa_u64 *ucode_data;
 sa_u32 ucode_data_size;
 sa_u64 *dram_stack;
 sa_u32 dram_stack_size;
 sa_u64 *output_buff;
 sa_u64 *output_buff_size;
 sa_u64 *data_ptr;
 sa_u32 data_size;
 sa_u64 *yield_data_ptr;
 sa_u32 yield_data_size;
} OSTask_t;
typedef union {
    OSTask_t t;
    long long int force_structure_alignment;
} OSTask;
typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 unsigned char cn[4];
} Vtx_t;
typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 signed char n[3];
 unsigned char a;
} Vtx_tn;
typedef union {
    Vtx_t v;
    Vtx_tn n;
    long long int force_structure_alignment;
} Vtx;
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
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
  signed char dir[3];
  char pad3;
} Light_t;
typedef union {
    Light_t l;
    long long int force_structure_alignment[2];
} Light;
typedef struct {
    Light l[2];
} LookAt;
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
typedef float CMtxF[4][4];
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
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
typedef struct CROMBounds_t
{
 CVector3 m_vMin, m_vMax;
} CROMBounds;
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
typedef struct CGameSimpleInstance_t
{
 CAnimInstanceHdr ah;
   CCacheEntry *m_pceObjectIndex,
       *m_pceStaticEvents;
 ROMAddress *m_rpObjectIndexAddress;
 Mtx m_mOrientation[2],
       m_mShadow[2];
 CGeometry m_Geometry;
 CVector3 vRotAxis ;
 float m_RotAngle, m_AngleVel;
 CROMBounds m_Bounds;
 float m_Scale, m_OffsetY;
 unsigned short m_wFlags,
       m_nID;
 float m_Time, m_MorphInc;
} CGameSimpleInstance;
typedef struct CGameStaticInstance_t
{
 CInstanceHdr ih;
   CCacheEntry *m_pceObjectIndex,
       *m_pceStaticEvents;
 ROMAddress *m_rpObjectIndexAddress;
 Mtx m_mOrientation;
 CGeometry m_Geometry;
 CROMBounds m_Bounds;
 unsigned long m_dwFlags;
} CGameStaticInstance;
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
extern void func_8001E93C(CGameObjectInstance *pThis);
typedef struct CROMLevel_t
{
 float m_GridDistance;
 unsigned char m_BlackColor[3],
      m_WhiteColor[3],
      m_DirectionalLight[3],
      m_AmbientLight[3],
      m_bFlags;
 signed char m_Direction[3];
} CROMLevel;
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
typedef struct CROMWarpPoint_t
{
 CVector3 m_vPos;
 float m_RotY;
 unsigned short m_nLevel,
     m_nRegion;
} CROMWarpPoint;
extern void D_80070DA8 (CInstanceHdr *pThis, CInstanceHdr *pOrigin, int Event, unsigned long dwSpecies, CVector3 vPos, float Value);
extern int func_8005FCF4 (CGameObjectInstance *pAI, int nAnim, int InterruptBlend);
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
typedef struct CParticleSystem_t
{
 CParticle m_Particles[2],
     *m_pFreeHead,
     *m_pActiveHead, *m_pActiveTail,
     *m_pDrawHead, *m_pDrawTail;
 CCartCache *m_pCache;
   CCacheEntry *m_pceParticleEffects,
     *m_pceTextureSetsIndex;
} CParticleSystem;
struct CScene_t;
typedef struct CDynamicSimple_t
{
 CGameSimpleInstance s;
 float m_LifeTime ;
 float m_SparkleTime ;
 unsigned long m_dwFlags;
 struct CDynamicSimple_t **m_ppPickup ;
 struct CDynamicSimple_t *m_pLast, *m_pNext;
} CDynamicSimple;
typedef struct CSimplePool_t
{
 CDynamicSimple m_Simples[32],
       *m_pFreeHead,
       *m_pActiveHead, *m_pActiveTail;
 CCartCache *m_pCache;
 CCacheEntry *m_pceObjectsIndex;
 ROMAddress *m_rpObjectsAddress;
 int m_Initialized;
} CSimplePool;
typedef struct CPickupGenerator_t
{
 float m_Time ;
 CDynamicSimple *m_pPickup ;
 CVector3 m_vPos ;
 CGameRegion *m_pRegion ;
} CPickupGenerator ;
typedef struct CPickupMonitor_t
{
 int m_Active ;
 CPickupGenerator m_Generators[16] ;
 signed long m_NoOfGenerators ;
} CPickupMonitor ;
typedef struct CScene_t
{
 CCartCache m_Cache;
 ROMAddress *m_rpBaseAddress;
   CCacheEntry *m_pceIndex;
   ROMAddress *m_rpObjectsAddress,
        *m_rpTextureSetsAddress,
        *m_rpLevelsAddress,
        *m_rpLevelAddress,
        *m_rpGridSectionsAddress,
        *m_rpObjectTypesAddress,
        *m_rpObjectAttributesAddress,
        *m_rpParticleEffectsAddress,
        *m_rpGridBoundsAddress,
        *m_rpWarpPointsAddress,
        *m_rpBinaries;
   CCacheEntry *m_pceObjectAttributes,
        *m_pceObjectTypes,
        *m_pceObjectsHeader,
        *m_pceObjectsIndex,
        *m_pceCollision,
        *m_pceInstances,
        *m_pceTextureSetsHeader,
        *m_pceTextureSetsIndex,
        *m_pceLevelsHeader,
        *m_pceLevelsIndex,
        *m_pceLevelIndex,
        *m_pceGridBounds,
        *m_pceGridSectionsIndex,
        *m_pcePersistantCounts,
        *m_pceSkyTextureSet,
        *m_pceWarpPoints,
        *m_pceSoundEffects,
        *m_pceLevelInfo,
        *m_pceBinariesIndex,
        *m_pceBinaryTypes;
 unsigned long m_ObjectTypesSize,
        m_ObjectAttributesSize,
        m_ParticleEffectsSize,
        m_GridBoundsSize,
        m_WarpPointsSize;
 CInstanceHdr *m_pInstances[1024];
 int m_nInstances;
 CGameStaticInstance *m_pStaticEventsInstances[64];
 int m_nStaticEventsInstances;
 CGameObjectInstance *m_pPlayer;
 CGameObjectInstance *m_pActiveAnimInstances[64];
 int m_nActiveAnimInstances;
 int m_nTransparentInstances;
 CInstanceHdr *m_pTransparentInstances[64];
 CParticleSystem m_ParticleSystem;
 CSimplePool m_SimplePool;
 CROMLevel m_LevelInfo;
 signed short m_LightDirection[4];
 CTextureLoader m_SkyTextureLoader;
 int m_SkyTextureReady, m_SkyHeightSet,
        m_LevelInfoReceived;
 float m_SkyHeight ;
 float m_RotYPickup;
 CQuatern m_qRotYPickup;
 int m_nLevel,
        m_nWarpID;
 int m_WarpFound;
 CROMWarpPoint m_WarpPoint;
 float m_cSendStaticEventsFrame;
 unsigned long pad1, pad2, pad3, m_bPlayerActiveFlags;
 CPickupMonitor m_PickupMonitor ;
} CScene;
extern int func_80031974(CScene *pThis,
             int nSoundType, float Volume,
             void *pSource, CVector3 *pvSourcePos, int SndFlags);
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
typedef struct CControlState_t
{
 sa_u16 BDown,
   BUp,
   BSingle,
   BDbl,
   BDblHold,
   BTimer [ 16 ];
 sa_s8 StickX,
   StickY;
 float Smooth,
   SStickX,
   SStickY;
} CControlState;
typedef struct
{
 CControlState *pCState;
 sa_u8 CenteringX,
       CenteringY;
 sa_u8 LookIndependant;
 sa_u16 Fire1,
       Forward,
       Backward,
       Left,
       Right,
       Duck,
       Jump,
       JumpReleased,
       MapToggle,
       SideStepLeft,
       SideStepRight,
       SelectWeaponPrev,
       SelectWeaponNext,
       SelectEnemyPrev,
       SelectEnemyNext,
       OpenDoor,
       RollRight,
       RollLeft,
       Pause,
       Start,
       StartHeld,
       UseMenu,
       LookUp,
       LookDown,
       LookLeft,
       LookRight,
       RunBackward,
       RunForward,
       RollSpeedL,
       RollSpeedR,
       GrenadeLauncherFired,
       ToggleOnScreen,
       ClickUp,
       ClickDown,
       ClickLeft,
       ClickRight,
       RunWalkToggle,
       SwimForward,
       SwimBackward,
       SwimSideStepL,
       SwimSideStepR,
       SwimUp,
       SwimBurstForward,
       MapLeft,
       MapRight,
       MapDown,
       MapUp,
       StartJump,
       AnalogLeft,
       AnalogRight,
       AnalogDown,
       AnalogUp,
       ClimbLookLeft,
       ClimbLookRight,
       ClimbUp,
       ClimbDown,
       ClimbLeft,
       ClimbRight,
       BurstSwimToggle,
       DigitalUp,
       DigitalDown,
       ZRotTog,
       ZRotLeft,
       ZRotRight,
       EnemyForward,
       EnemyBackward,
       EnemyLeft,
       EnemyRight,
       EnemyRotLeft,
       EnemyRotRight,
       FlyUp,
       FlyDown,
       FlyLeft,
       FlyRight,
       FlyForward,
       FlyBackward;
 sa_u16 PreFire1,
       PreForward,
       PreBackward,
       PreLeft,
       PreRight,
       PreDuck,
       PreJump,
       PreJumpReleased,
       PreMapToggle,
       PreSideStepLeft,
       PreSideStepRight,
       PreSelectWeaponPrev,
       PreSelectWeaponNext,
       PreSelectEnemyPrev,
       PreSelectEnemyNext,
       PreOpenDoor,
       PreRollLeft,
       PreRollRight,
       PrePause,
       PreStart,
       PreStartHeld,
       PreUseMenu,
       PreLookUp,
       PreLookDown,
       PreLookLeft,
       PreLookRight,
       PreRunBackward,
       PreRunForward,
       PreRollSpeedL,
       PreRollSpeedR,
       PreGrenadeLauncherFired,
       PreToggleOnScreen,
       PreClickUp,
       PreClickDown,
       PreClickLeft,
       PreClickRight,
       PreRunWalkToggle,
       PreSwimForward,
       PreSwimBackward,
       PreSwimSideStepL,
       PreSwimSideStepR,
       PreSwimUp,
       PreSwimBurstForward,
       PreMapLeft,
       PreMapRight,
       PreMapDown,
       PreMapUp,
       PreStartJump,
       PreAnalogLeft,
       PreAnalogRight,
       PreAnalogDown,
       PreAnalogUp,
       PreClimbLookLeft,
       PreClimbLookRight,
       PreClimbUp,
       PreClimbDown,
       PreClimbLeft,
       PreClimbRight,
       PreBurstSwimToggle,
       PreDigitalUp,
       PreDigitalDown,
       PreZRotTog,
       PreZRotLeft,
       PreZRotRight,
       PreEnemyForward,
       PreEnemyBackward,
       PreEnemyLeft,
       PreEnemyRight,
       PreEnemyRotLeft,
       PreEnemyRotRight,
       PreFlyUp,
       PreFlyDown,
       PreFlyLeft,
       PreFlyRight,
       PreFlyForward,
       PreFlyBackward;
 sa_u16 NotFire1,
       NotForward,
       NotBackward,
       NotLeft,
       NotRight,
       NotDuck,
       NotJump,
       NotJumpReleased,
       NotMapToggle,
       NotSideStepLeft,
       NotSideStepRight,
       NotSelectWeaponPrev,
       NotSelectWeaponNext,
       NotSelectEnemyPrev,
       NotSelectEnemyNext,
       NotOpenDoor,
       NotRollLeft,
       NotRollRight,
       NotPause,
       NotStart,
       NotStartHeld,
       NotUseMenu,
       NotLookUp,
       NotLookDown,
       NotLookLeft,
       NotLookRight,
       NotRunBackward,
       NotRunForward,
       NotRollSpeedL,
       NotRollSpeedR,
       NotGrenadeLauncherFired,
       NotToggleOnScreen,
       NotClickUp,
       NotClickDown,
       NotClickLeft,
       NotClickRight,
       NotRunWalkToggle,
       NotSwimForward,
       NotSwimBackward,
       NotSwimSideStepL,
       NotSwimSideStepR,
       NotSwimUp,
       NotSwimBurstForward,
       NotMapLeft,
       NotMapRight,
       NotMapDown,
       NotMapUp,
       NotStartJump,
       NotAnalogLeft,
       NotAnalogRight,
       NotAnalogDown,
       NotAnalogUp,
       NotClimbLookLeft,
       NotClimbLookRight,
       NotClimbUp,
       NotClimbDown,
       NotClimbLeft,
       NotClimbRight,
       NotBurstSwimToggle,
       NotDigitalUp,
       NotDigitalDown,
       NotZRotTog,
       NotZRotLeft,
       NotZRotRight,
       NotEnemyForward,
       NotEnemyBackward,
       NotEnemyLeft,
       NotEnemyRight,
       NotEnemyRotLeft,
       NotEnemyRotRight,
       NotFlyUp,
       NotFlyDown,
       NotFlyLeft,
       NotFlyRight,
       NotFlyForward,
       NotFlyBackward;
 sa_u8 TypeFire1,
       TypeForward,
       TypeBackward,
       TypeLeft,
       TypeRight,
       TypeDuck,
       TypeJump,
       TypeJumpReleased,
       TypeMapToggle,
       TypeSideStepLeft,
       TypeSideStepRight,
       TypeSelectWeaponPrev,
       TypeSelectWeaponNext,
       TypeSelectEnemyPrev,
       TypeSelectEnemyNext,
       TypeOpenDoor,
       TypeRollLeft,
       TypeRollRight,
       TypePause,
       TypeStart,
       TypeStartHeld,
       TypeUseMenu,
       TypeLookUp,
       TypeLookDown,
       TypeLookLeft,
       TypeLookRight,
       TypeRunBackward,
       TypeRunForward,
       TypeRollSpeedL,
       TypeRollSpeedR,
       TypeGrenadeLauncherFired,
       TypeToggleOnScreen,
       TypeClickUp,
       TypeClickDown,
       TypeClickLeft,
       TypeClickRight,
       TypeRunWalkToggle,
       TypeSwimForward,
       TypeSwimBackward,
       TypeSwimSideStepL,
       TypeSwimSideStepR,
       TypeSwimUp,
       TypeSwimBurstForward,
       TypeMapLeft,
       TypeMapRight,
       TypeMapDown,
       TypeMapUp,
       TypeStartJump,
       TypeAnalogLeft,
       TypeAnalogRight,
       TypeAnalogDown,
       TypeAnalogUp,
       TypeClimbLookLeft,
       TypeClimbLookRight,
       TypeClimbUp,
       TypeClimbDown,
       TypeClimbLeft,
       TypeClimbRight,
       TypeBurstSwimToggle,
       TypeDigitalUp,
       TypeDigitalDown,
       TypeZRotTog,
       TypeZRotLeft,
       TypeZRotRight,
       TypeEnemyForward,
       TypeEnemyBackward,
       TypeEnemyLeft,
       TypeEnemyRight,
       TypeEnemyRotLeft,
       TypeEnemyRotRight,
       TypeFlyUp,
       TypeFlyDown,
       TypeFlyLeft,
       TypeFlyRight,
       TypeFlyForward,
       TypeFlyBackward;
} CTControl;
extern float func_800510C4 (CTControl *pThis);
typedef struct CRequestor_t
{
 float m_Alpha ;
 signed short m_Mode ;
 int b_Active ;
 signed long m_Selection ;
 char **Selections ;
 char *Line1 ;
 char *Line2 ;
} CRequestor ;
typedef struct CMessageBox_t
{
 float m_Alpha ;
 signed short m_Mode ;
 int b_Active ;
 signed long m_Selection ;
 char *Line1 ;
 char *Line2 ;
} CMessageBox ;
typedef struct CLoad_t
{
 float m_Alpha ;
 signed short m_Mode ;
 int b_Active ;
 signed short m_LoadType ;
 sa_s32 m_Side ;
 signed long m_ASelection ;
 signed long m_BSelection ;
 signed long m_FirstVisible ;
 signed long m_MaxVisible ;
 signed long m_Selection ;
 signed long m_SubSelection ;
 signed long m_EntryPos ;
} CLoad ;
typedef struct CSave_t
{
 float m_Alpha ;
 signed short m_Mode ;
 int b_Active ;
 signed short m_SaveType ;
 sa_s32 m_Side ;
 signed long m_ASelection ;
 signed long m_BSelection ;
 signed long m_FirstVisible ;
 signed long m_MaxVisible ;
 int m_ShowAll ;
 signed long m_Selection ;
} CSave ;
typedef struct CGamePak_t
{
 float m_Alpha ;
 signed short m_Mode ;
 int b_Active ;
 signed long m_Selection ;
 signed long m_Timer ;
} CGamePak ;
typedef struct CCheatCode_t
{
 float m_Alpha ;
 signed short m_Mode ;
 int b_Active ;
 signed long m_Selection ;
 signed long m_SubSelection ;
 signed long m_EntryPos ;
} CCheatCode ;
typedef struct CGiveCheatCode_t
{
 float m_Alpha ;
 signed short m_Mode ;
 int b_Active ;
 int *m_Codes ;
 signed long m_Selection ;
} CGiveCheatCode ;
typedef struct COption_t
{
 signed long m_Mode ;
 float m_Alpha ;
 int b_Active ;
 int m_RHControl;
 int m_Blood;
 signed long m_Selection ;
 signed long m_MusicVolume ;
 signed long m_SFXVolume ;
 signed long m_Opacity ;
 signed long m_HAnalog ;
 signed long m_VAnalog ;
 int m_OptionsStored ;
 signed long m_Storage_CheatFlags ;
 int m_Storage_RHControl ;
 int m_Storage_Blood ;
 signed long m_Storage_Opacity ;
 signed long m_Storage_HAnalog ;
 signed long m_Storage_VAnalog ;
 signed long m_Storage_Difficulty ;
} COptions ;
typedef struct CKeys_t
{
 signed long m_Mode ;
 float m_Alpha ;
 int b_Active ;
} CKeys ;
typedef struct CCheat_t
{
 signed long m_Mode ;
 float m_Alpha ;
 int b_Active ;
 signed long m_Selection ;
 int m_RealSelection ;
} CCheat ;
typedef struct CGInst_t
{
 signed long m_Mode ;
 float m_Alpha ;
 int b_Active ;
 signed long m_Selection ;
} CGInst ;
typedef struct CPause_t
{
 signed long m_Mode ;
 float m_Alpha ;
 signed long m_Selection ;
 int m_RealSelection;
} CPause ;
typedef struct CBossVars_t
{
 signed long m_SwitchesOn ;
 unsigned long m_SwitchFlags ;
 float m_TurokSpeed ;
 CGameRegion *m_pRegionList[4] ;
 float m_StartBossTimer ;
 CGameObjectInstance *m_pMantisInstance ;
 CVector3 m_vTurokLastPos ;
 CVector3 m_vTurokDir ;
} CBossVars ;
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
typedef struct CBossEvent_t
{
 CInstanceHdr *m_pInst ;
 CVector3 m_vPos ;
 int m_nType ;
 float m_Value ;
} CBossEvent ;
typedef struct CBossPickup_t
{
 int m_nType ;
 CVector3 m_vPos ;
} CBossPickup ;
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
typedef struct CBossesStatus_t
{
 CGameObjectInstance *m_pBossActive ;
 CBossData m_BossData[3] ;
 CBossEvent m_EventData[20] ;
 signed long m_CurrentEvent ;
 int m_PickupMonitorActive ;
 CBossPickup m_PickupData[20] ;
 signed long m_CurrentPickup ;
} CBossesStatus ;
typedef struct CNode_t
{
 struct CNode_t *m_pPrev ;
 struct CNode_t *m_pNext ;
} CNode ;
typedef struct CList_t
{
 CNode *m_pHead ;
 CNode *m_pTail ;
 signed long m_Length ;
} CList ;
typedef struct CDynamicList_t
{
 CList m_FreeList ;
 CList m_ActiveList ;
} CDynamicList ;
typedef struct CSwooshVertex_t
{
 CVector3 m_vPos ;
 CRGB m_Color ;
 float m_Alpha ;
} CSwooshVertex ;
typedef struct CSwooshEdgeVertexInfo_t
{
 CSwooshVertex m_Start, m_End ;
} CSwooshEdgeVertexInfo ;
typedef struct CSwooshInfo_t
{
 float m_LifeTime ;
 float m_FadeOutTime ;
 float m_EdgeLifeTime ;
 signed short m_Node ;
 float m_Scale ;
 signed short m_Flags ;
 signed short m_NoOfEdgeVertices ;
 CSwooshEdgeVertexInfo *m_pEdgeVertexList ;
} CSwooshInfo ;
typedef struct CSwooshEdge_t
{
 CNode m_Node ;
 float m_LifeTime ;
 float m_TotalLifeTime ;
 Mtx m_mMatrix ;
} CSwooshEdge ;
typedef struct CSwoosh_t
{
 CNode m_Node ;
 signed short m_Type ;
 float m_LifeTime ;
 CSwooshInfo *m_pInfo ;
 CGameObjectInstance *m_pObject ;
 CParticle *m_pParticle ;
 CList m_EdgeList ;
} CSwoosh ;
typedef struct CTimerFx_t
{
 CNode m_Node ;
 float m_Time ;
 float m_Spacing ;
 signed long m_Count ;
 CGameObjectInstance *m_pInst ;
 void (*m_pFunction)(void *pThis) ;
} CTimerFx ;
typedef struct CFxSystem_t
{
 Vtx m_VertexList[2][400] ;
 signed long m_VtxsFree ;
 Vtx *m_pFreeVertex ;
 CSwooshEdge m_SwooshEdgeVars[150] ;
 CList m_SwooshEdgeList ;
 CSwoosh m_SwooshVars[32] ;
 CDynamicList m_SwooshList ;
 CTimerFx m_TimerFxVars[3] ;
 CDynamicList m_TimerFxList ;
} CFxSystem ;
typedef struct {
    short type;
    char misc[30];
} OSScMsg;
typedef struct OSScTask_s {
    struct OSScTask_s *next;
    sa_u32 state;
    sa_u32 flags;
    void *framebuffer;
    OSTask list;
    OSMesgQueue *msgQ;
    OSMesg msg;
    OSTime startTime;
    OSTime totalTime;
} OSScTask;
typedef struct CCameraTrackInfo_t
{
 float m_StartYRotOffset, m_FinalYRotOffset ;
 float m_StartRadius, m_FinalRadius ;
 float m_StartEyeYOffset, m_FinalEyeYOffset ;
 float m_StartFocusYOffset, m_FinalFocusYOffset ;
} CCameraTrackInfo ;
typedef struct CCameraView_t
{
 float m_Time ;
 CVector3 m_vEye ;
 CVector3 m_vFocus ;
 CVector3 m_vRotation ;
 float m_YRotOffset,
     m_Radius,
     m_EyeYOffset,
     m_FocusYOffset ;
} CCameraView ;
typedef struct CShake_t
{
 float m_Shake ;
 float m_LastShake ;
 float m_Amp ;
 float m_Angle ;
} CShake ;
typedef struct CCamera_t
{
 float m_PixelXScale ;
 float m_PixelYScale ;
 signed short m_Mode ;
 float m_Time ;
 int m_CinemaMode ;
 int m_CinemaFadingOut ;
 int m_NextCinematicStage ;
 int m_StartPressed ;
 signed short m_Stage ;
 float m_StageTime ;
 sa_u16 m_PerspNorm;
 float m_LetterBoxScale ;
 signed short m_LetterBoxTop ;
 signed short m_LetterBoxBottom ;
 float m_Fov, m_AspectRatio ;
 CCameraView m_View ;
 float m_ViewBlend ;
 CCameraView m_ViewA, m_ViewB, m_ViewC ;
 CVector3 m_vPos ;
 CVector3 m_vRotation ;
 CGameObjectInstance *m_pObject ;
 CCameraTrackInfo *m_pTrackInfo ;
 CVector3 m_vPos1, m_vPos2 ;
 float m_XScale, m_YScale ;
 float m_WaterWobbleXScale, m_WaterWobbleYScale ;
 float m_WaterWobbleXAngle, m_WaterWobbleYAngle ;
 float m_WaterWobbleXSpeed, m_WaterWobbleYSpeed ;
 CShake m_ShakeX, m_ShakeY, m_ShakeZ ;
 CVector3 m_vTremor ;
 signed long m_WarpMode ;
 float m_WarpTime ;
 CVector3 m_vWarpPos ;
 float m_WarpXScale ;
 float m_WarpYScale ;
 float m_WarpSpin ;
 signed long m_UserSoundHandles[8] ;
 signed long m_Flags ;
} CCamera ;
typedef struct CSunFrameData_t
{
 sa_u64 m_DepthData[2];
 int m_DepthPos;
 int m_Visible,
     m_VisibleZ,
     align;
} CSunFrameData;
typedef struct CTraining_t
{
 signed long m_Mode ;
 float m_Alpha ;
 sa_s32 m_ID ;
} CTraining ;
typedef union
{
 struct
 {
  short type;
 } gen;
 struct
 {
  short type;
 } done;
 OSScMsg app;
} GFXMsg;
typedef struct CFrameData_t
{
 Mtx m_mProjection;
 LookAt m_LookAt;
 CSunFrameData m_SunFrame;
 OSScTask m_Task,
       m_LineTask;
 GFXMsg m_Msg;
 void *m_pFrameBuffer;
 Gfx *m_pDisplayList,
       *m_pLineList;
 unsigned long m_DisplayListSize,
       m_LineListSize,
       m_nPredictFields;
 int m_DrawMap;
} CFrameData;
typedef struct CPersistantData_t
{
 int SemiAutomaticPistolFlag,
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
   ChronoSceptorFlag ;
 int ArmorFlag,
   BackPackFlag ;
 int BulletPool,
   ShotgunPool,
   EnergyPool,
   ExpTekBowAmmo,
   ExpShotgunPool,
   TekBowAmmo,
   MiniGunAmmo,
   GrenadeLauncherAmmo,
   RocketAmmo,
   TechWeapon2Ammo,
   ChronoSceptorAmmo;
 int ArmorAmount ;
 int WeaponUsing ;
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
 int Difficulty ;
 int RunWalk ;
 int ControlSide ;
 int Blood ;
 int Stereo ;
 sa_u32 MusicVolume ;
 sa_u32 SFXVolume ;
 sa_u32 Opacity ;
 sa_u32 HAnalog ;
 sa_u32 VAnalog ;
 sa_u32 CheatFlags ;
 sa_u32 EnabledCheatFlags ;
 int Health,
   MaxHealth,
   Tokens,
   Lives ;
 sa_u16 Checkpoint ;
 float BestTrainTime ;
 signed long BossFlags ;
 sa_u32 Crash ;
} CPersistantData;
typedef struct CEngineApp_t
{
 CFrameData m_FrameData[3];
 CFrameData *m_pCurrentFrameData;
 CPersistantData *m_pPersistant;
 CScene m_Scene;
 COnScreen m_OnScreen;
 CBossesStatus m_BossesStatus ;
 signed long m_BossFlags ;
 CGameObjectInstance *m_pBossActive ;
 CBossVars m_BossVars ;
 CCamera m_Camera;
 CFxSystem m_FxSystem ;
 CPause m_Pause;
 COptions m_Options;
 CKeys m_Keys;
 CLoad m_Load;
 CSave m_Save;
 CRequestor m_Requestor;
 CMessageBox m_MessageBox;
 CCheatCode m_CheatCode;
 CGiveCheatCode m_GiveCheatCode;
 CCheat m_Cheat;
 CGInst m_GInst;
 CGamePak m_GamePak;
 unsigned long m_Mode, m_NextMode ;
 unsigned long m_dwCheatFlags,
       m_dwEnabledCheatFlags;
 int m_Level ;
 int m_BossLevel ;
 signed long m_hMusic;
 sa_u8 m_FadeFast, m_FadeStatus, unused1, unused2;
 unsigned char m_PortraitNameMode;
 float m_FadeAlpha ;
 float m_RotY,
       m_RotXOffset, m_RotYOffset, m_RotZOffset,
       m_XPos, m_YPos, m_ZPos,
       m_YPosOffset,
       m_TranslateHorizontal,
       m_TranslateVertical;
 CQuatern m_qGround,
       m_qViewAlign,
       m_qViewAlignNoZ;
 CMtxF m_mfViewOrient,
       m_mfProjection;
 CVector3 m_vTCorners[5];
 Gfx *m_pDLP;
 void *m_pStaticSegment;
 int m_DebugMode,
       m_DoIdle,
       m_SloMo,
       m_LegalBypass,
       m_GamePakCheck,
       m_FirstRun,
       m_JustLoadedGame,
       m_MapMode ;
 int m_LegalTimer ;
 float m_MapAlpha ;
 sa_u16 m_MapStatus ;
 float m_GameOverAlpha ,
       m_GameOverMode,
       m_GameOverTime ;
 float m_TitleAlpha ;
 float m_LevelTime ;
 float m_BestTrainTime ;
 float m_ModeTime ;
 int m_bTrainingMode ;
 int m_bTraining ;
 int m_TrainingType ;
 CTraining m_Training ;
 int m_Difficulty ;
 int m_bGameOver,
       m_bReset,
       m_bPause,
       m_bOptions,
       m_bKeys,
       m_bLoad,
       m_bSave,
       m_bRequestor,
       m_bMessageBox,
       m_bCheatCode,
       m_bGiveCheatCode,
       m_bCheat,
       m_bGInst,
       m_bGamePak,
       m_bDebug,
       m_UnderWater;
 sa_u8 m_Flash,
       m_FlashDec,
       m_Alpha,
       m_AlphaDec;
 unsigned long m_nCurrentRegionSet;
 float m_cRegionSetBlend;
 unsigned char m_FogColor[4],
       m_LastFogColor[4],
       m_FlashColor[4];
 float m_FarClip,
       m_LastFarClip,
       m_FieldOfView,
       m_LastFieldOfView,
       m_SkySpeed,
       m_SkyElevation,
       m_LastSkySpeed,
       m_LastSkyElevation;
 unsigned long m_FogStart,
       m_LastFogStart;
 int m_Warp,
       m_WarpID,
       m_CurrentWarpID,
       m_WarpSound;
 int m_WarpBase ;
 int m_PlayedSound;
 float m_uWarp,
       m_WarpLength;
 unsigned char m_WarpColors[4];
 int m_Death;
 float m_uDeath;
 int m_ReturnWarpSaved;
 CROMWarpPoint m_ReturnWarp;
 signed long m_CinemaFlags ;
 CROMWarpPoint m_CinemaWarp ;
 int m_UseCinemaWarp ;
 float m_PortraitZoom,
        m_ActualPortraitZoom,
        m_ActualPortraitRotXSpd,
        m_ActualPortraitRotYSpd,
        m_ActualPortraitRotZSpd,
        m_PortraitRotXSpd,
        m_PortraitRotYSpd,
        m_PortraitRotZSpd,
        m_PortraitAlpha,
        m_PortraitTimer;
 CVector3 m_vPortrait;
 int m_Portrait,
        m_PortraitName;
 CQuatern m_qPortraitOrientation;
 int m_PortraitExit;
 int m_LastSaveMapLevel;
 float m_MenuUpChangeCount,
        m_MenuDownChangeCount,
        m_MenuLeftChangeCount,
        m_MenuRightChangeCount;
 float m_ActualMusicVolume,
        m_ActualSFXVolume,
        m_MusicVolume,
        m_SFXVolume;
 int m_RecordMode ;
 int m_AttractMode ;
 unsigned char *m_pAttractData ;
 signed long m_AttractCurrentBit ;
 unsigned char m_AttractPadFrames ;
 OSContPad m_AttractPad ;
} CEngineApp;
extern sa_u64 dram_stack[];
extern CTControl *D_800F9E44;
extern CEngineApp D_800F9F10;
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
extern int func_8005843C (CTMove *pThis, int weapon, int variation);
extern void func_800587B0 (CTMove *pThis, int status);
extern void func_80057DC8 (CTMove *pThis, int *pAmt, int nAmt);
extern void func_80058B6C (CTMove *pThis, int ammo, int next);
extern void func_80059244 (CTMove *pThis, CEngineApp *pApp, float shake, float ang, int rotstyle);
extern void D_80059994 (CTMove *pThis, int WFired);
extern void func_8005AFE8 (CTMove *pThis, int Direction);
extern int func_8007BA2C (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *D_800F9E48, int waterFlag);
enum SOUND_TYPES
{
 SOUND_MENU_OPTION_SELECT=0,
 SOUND_GAME_SAVED,
 SOUND_READY_PISTOL,
 SOUND_READY_SHOTGUN,
 SOUND_READY_TEK_WEAPON_1,
 SOUND_READY_TEK_WEAPON_2,
 SOUND_CHARGE_TEK_WEAPON_2,
 SOUND_READY_MISSILE_LAUNCHER,
 SOUND_READY_BFG,
 SOUND_KNIFE_SWISH_1,
 SOUND_KNIFE_SWISH_2,
 SOUND_KNIFE_SWISH_3,
 SOUND_BOW_STRETCH,
 SOUND_BOW_TWANG,
 SOUND_ARROW_FLY_NORMAL,
 SOUND_ARROW_FLY_TEK,
 SOUND_PISTOL_SHOT,
 SOUND_RIFLE_SHOT,
 SOUND_MACHINE_GUN_SHOT_1,
 SOUND_MACHINE_GUN_SHOT_2,
 SOUND_GRENADE_LAUNCH,
 SOUND_AUTO_SHOTGUN_SHOT,
 SOUND_RIOT_SHOTGUN_SHOT,
 SOUND_MINI_GUN_SHOT,
 SOUND_MINI_GUN_WHIR,
 SOUND_TEK_WEAPON_1,
 SOUND_TEK_WEAPON_2,
 SOUND_MISSILE_LAUNCH,
 SOUND_BFG_SHOT,
 SOUND_BLOW_GUN_SHOT,
 SOUND_HULK_BLASTER_FIRE,
 SOUND_CAMPAIGNERS_CONCUSSION,
 SOUND_CAMPAIGNERS_SCATTER_BLAST,
 SOUND_PENDULUM_SWOOSH_1,
 SOUND_PENDULUM_SWOOSH_2,
 SOUND_PENDULUM_SWOOSH_3,
 SOUND_PENDULUM_SWOOSH_4,
 SOUND_PENDULUM_SWOOSH_5,
 SOUND_METAL_SHELL_LAND,
 SOUND_SHOTGUN_SHELL_LAND,
 SOUND_INCOMING_PROJECTILE_1,
 SOUND_INCOMING_PROJECTILE_2,
 SOUND_INCOMING_PROJECTILE_3,
 SOUND_BULLET_RICOCHET_1,
 SOUND_BULLET_RICOCHET_2,
 SOUND_BULLET_RICOCHET_3,
 SOUND_BULLET_RICOCHET_4,
 SOUND_BULLET_IMPACT_1,
 SOUND_BULLET_IMPACT_2,
 SOUND_BULLET_IMPACT_3,
 SOUND_BULLET_IMPACT_4,
 SOUND_BULLET_IMPACT_5,
 SOUND_BULLET_IMPACT_6,
 SOUND_BULLET_IMPACT_7,
 SOUND_BULLET_IMPACT_8,
 SOUND_BULLET_IMPACT_9,
 SOUND_BULLET_IMPACT_10,
 SOUND_BULLET_IMPACT_13,
 SOUND_BULLET_IMPACT_14,
 SOUND_BULLET_IMPACT_15,
 SOUND_BODY_ARMOR_IMPACT_1,
 SOUND_BODY_ARMOR_IMPACT_2,
 SOUND_BODY_ARMOR_IMPACT_3,
 SOUND_BODY_ARMOR_IMPACT_4,
 SOUND_BODY_ARMOR_IMPACT_5,
 SOUND_EXPLOSION_1,
 SOUND_EXPLOSION_2,
 SOUND_EXPLOSION_3,
 SOUND_FIRE_RUMBLE,
 SOUND_FIRE_SPARK_1,
 SOUND_FIRE_SPARK_2,
 SOUND_FIRE_SPARK_3,
 SOUND_FIRE_SPARK_4,
 SOUND_FIRE_SPARK_5,
 SOUND_FIRE_SPARK_6,
 SOUND_FIRE_SPARK_7,
 SOUND_FIRE_SPARK_8,
 SOUND_TORCH_IGNIGHT,
 SOUND_ELECTRICAL_SPARK_1,
 SOUND_ELECTRICAL_SPARK_2,
 SOUND_ELECTRICAL_SPARK_3,
 SOUND_ELECTRICAL_SPARK_4,
 SOUND_ELECTRICAL_SPARK_5,
 SOUND_ELECTRICAL_SPARK_6,
 SOUND_PULLEY_SQUEAK_1,
 SOUND_PULLEY_SQUEAK_2,
 SOUND_PULLEY_SQUEAK_3,
 SOUND_PULLEY_SQUEAK_4,
 SOUND_PULLEY_SQUEAK_5,
 SOUND_ROPE_STRETCH_1,
 SOUND_ROPE_STRETCH_2,
 SOUND_ROPE_STRETCH_3,
 SOUND_ROPE_STRETCH_4,
 SOUND_ROPE_STRETCH_5,
 SOUND_STONEROCK_CRUMBLE_1,
 SOUND_STONEROCK_CRUMBLE_2,
 SOUND_STONEROCK_CRUMBLE_3,
 SOUND_STONEROCK_CRUMBLE_4,
 SOUND_STONEBOULDER_THUD ,
 SOUND_MUD_SLOSH_1,
 SOUND_MUD_SLOSH_2,
 SOUND_MUD_SLOSH_3,
 SOUND_DIRT_DEBRIS_1,
 SOUND_DIRT_DEBRIS_2,
 SOUND_DIRT_DEBRIS_3,
 SOUND_TREE_FALLING,
 SOUND_TREE_HIT_EARTH,
 SOUND_WATER_DRIP_1,
 SOUND_WATER_DRIP_2,
 SOUND_WATER_DRIP_3,
 SOUND_WATER_DRIP_4,
 SOUND_WATER_DRIP_5,
 SOUND_WATER_SPLASH_1,
 SOUND_WATER_SPLASH_2,
 SOUND_WATER_SPLASH_3,
 SOUND_WATER_SPLASH_4,
 SOUND_WATER_SPLASH_5,
 SOUND_UNDERWATER_SWIM_1,
 SOUND_UNDERWATER_SWIM_2,
 SOUND_UNDERWATER_SWIM_3,
 SOUND_UNDERWATER_SWIM_4,
 SOUND_UNDERWATER_SWIM_5,
 SOUND_BIRD_CALL_1,
 SOUND_BIRD_CALL_2,
 SOUND_BIRD_CALL_3,
 SOUND_BIRD_CALL_4,
 SOUND_BIRD_CALL_5,
 SOUND_BIRD_CALL_6,
 SOUND_BIRD_CALL_7,
 SOUND_BIRD_CALL_8,
 SOUND_CRICKET_CHIRP,
 SOUND_CICAADA_CHIRP,
 SOUND_LOCUST_CHIRP,
 SOUND_FROG_CHIRP_1,
 SOUND_FROG_CHIRP_2,
 SOUND_FROG_CHIRP_3,
 SOUND_FROG_CHIRP_4,
 SOUND_INSECT_BUZZ_1,
 SOUND_INSECT_BUZZ_2,
 SOUND_INSECT_BUZZ_3,
 SOUND_MONKEY_CHIPSCREAM_1,
 SOUND_MONKEY_CHIPSCREAM_2,
 SOUND_MONKEY_CHIPSCREAM_3,
 SOUND_MONKEY_CHIPSCREAM_4,
 SOUND_WILD_BOAR_SQUEAL_1,
 SOUND_WILD_BOAR_SQUEAL_2,
 SOUND_WILD_BOAR_SQUEAL_3,
 SOUND_WILD_BOAR_SQUEAL_4,
 SOUND_BIRD_FLUSHING,
 SOUND_BRUSH_RUSTLE_1,
 SOUND_BRUSH_RUSTLE_2,
 SOUND_BRUSH_RUSTLE_3,
 SOUND_BRUSH_RUSTLE_4,
 SOUND_WIND_BLOW_1,
 SOUND_WIND_BLOW_2,
 SOUND_WIND_BLOW_3,
 SOUND_WIND_BLOW_4,
 SOUND_WIND_BLOW_5,
 SOUND_RAIN_LIGHTLY,
 SOUND_RAIN_MEDIUM,
 SOUND_RAIN_HEAVY,
 SOUND_THUNDER_ROLL_1,
 SOUND_THUNDER_ROLL_2,
 SOUND_THUNDER_ROLL_3,
 SOUND_THUNDER_ROLL_4,
 SOUND_LIGHTNING_STRIKE_1,
 SOUND_LIGHTNING_STRIKE_2,
 SOUND_LIGHTNING_STRIKE_3,
 SOUND_RIVER_FLOW_LIGHTLY,
 SOUND_RIVER_FLOW_MEDIUM,
 SOUND_RIVER_FLOW_HEAVY,
 SOUND_WATERFALL_RUSH,
 SOUND_LAVA_FLOW,
 SOUND_GYSER_SPOUTING,
 SOUND_STALACTITES_BREAK,
 SOUND_OMINOUS_CAVE_GROWL_1,
 SOUND_OMINOUS_CAVE_GROWL_2,
 SOUND_OMINOUS_CAVE_GROWL_3,
 SOUND_GHOSTLY_CATACOMB_MOAN_1,
 SOUND_GHOSTLY_CATACOMB_MOAN_2,
 SOUND_GHOSTLY_CATACOMB_MOAN_3,
 SOUND_LIGHT_JUNGLE_FOOTFALL,
 SOUND_HEAVY_JUNGLE_FOOTFALL,
 SOUND_ROPE_BRIDGE_FOOTFALL,
 SOUND_CLIMB_CLIFF_FOOTFALL,
 SOUND_SWAMP_FOOTFALL,
 SOUND_WATER_FOOTFALL,
 SOUND_STONE_FOOTFALL,
 SOUND_METAL_FOOTFALL,
 SOUND_LARGE_THUD,
 SOUND_FALL_INTO_PIT,
 SOUND_STONE_SCRAPE_ON_STONE,
 SOUND_QUICKSAND_SWALLOW,
 SOUND_ELEVATOR_MECHANISM,
 SOUND_CEREMONIAL_SLAB_RISE,
 SOUND_CLAY_POT_SMASH,
 SOUND_ROCKS_SQUISH_IN_SWAMP,
 SOUND_DOORWAY_OPENCLOSE_1,
 SOUND_DOORWAY_OPENCLOSE_2,
 SOUND_ENERGY_SHIELD_HUM,
 SOUND_ENERGY_BLAST,
 SOUND_WARP_INOUT,
 SOUND_MACHINE_HUM,
 SOUND_POWER_HUM,
 SOUND_THERMAL_GOGGLES_ON,
 SOUND_THERMAL_GOGGLES_POWER,
 SOUND_HEALTH_PICKUP_1,
 SOUND_HEALTH_PICKUP_2,
 SOUND_HEALTH_PICKUP_3,
 SOUND_ULTRA_HEALTH_PICKUP,
 SOUND_HIT_POINT_PICKUP,
 SOUND_SPIRITUALITY_PICKUP,
 SOUND_SPIRITUALITY_DEATH_ATTACK,
 SOUND_ALL_MAP_PICKUP,
 SOUND_RAPTOR_SCREAM,
 SOUND_RAPTOR_ALERT,
 SOUND_RAPTOR_FOOTFALL,
 SOUND_RAPTOR_INJURY,
 SOUND_RAPTOR_ATTACK,
 SOUND_RAPTOR_DEATH,
 SOUND_RAPTOR_VIOLENT_DEATH,
 SOUND_RAPTOR_SNIFF,
 SOUND_TIGER_FOOTFALL,
 SOUND_TIGER_ROAR,
 SOUND_TIGER_ALERT,
 SOUND_TIGER_INJURY,
 SOUND_TIGER_ATTACK,
 SOUND_TIGER_DEATH,
 SOUND_TIGER_VIOLENT_DEATH,
 SOUND_TIGER_BREATHE,
 SOUND_DIMETRODON_FOOTFALL,
 SOUND_DIMETRODON_SCREAM,
 SOUND_DIMETRODON_ALERT,
 SOUND_DIMETRODON_INJURY,
 SOUND_DIMETRODON_DEATH,
 SOUND_DIMETRODON_VIOLENT_DEATH,
 SOUND_DIMETRODON_COUGHSNARL,
 SOUND_MOSCHOPS_FOOTFALL,
 SOUND_MOSCHOPS_SCREAM,
 SOUND_MOSCHOPS_ALERT,
 SOUND_MOSCHOPS_INJURY,
 SOUND_MOSCHOPS_ATTACK,
 SOUND_MOSCHOPS_DEATH,
 SOUND_MOSCHOPS_VIOLENT_DEATH,
 SOUND_MOSCHOPS_BREATHE,
 SOUND_PTERANODN_SCREAM,
 SOUND_PTERANODN_WING_FLAP,
 SOUND_PTERANODN_INJURY,
 SOUND_PTERANODN_DEATH,
 SOUND_PTERANODN_HISS,
 SOUND_TRICERATOPS_FOOTFALL,
 SOUND_TRICERATOPS_SCREAM,
 SOUND_TRICERATOPS_ALERT,
 SOUND_TRICERATOPS_INJURY,
 SOUND_DRAGONFLY_BUZZ,
 SOUND_DRAGONFLY_CLICKSCHATTER_1,
 SOUND_DRAGONFLY_CLICKSCHATTER_2,
 SOUND_DRAGONFLY_INJURY,
 SOUND_DRAGONFLY_DEATH,
 SOUND_DRAGONFLY_ATTACK,
 SOUND_BEETLE_FOOTFALL,
 SOUND_BEETLE_BUZZ,
 SOUND_BEETLE_CLICKSCHATTER_1,
 SOUND_BEETLE_CLICKSCHATTER_2,
 SOUND_BEETLE_INJURY,
 SOUND_BEETLE_DEATH,
 SOUND_BEETLE_ATTACK,
 SOUND_HUMAN_EFFORTINJURY_GRUNT_1,
 SOUND_HUMAN_EFFORTINJURY_GRUNT_2,
 SOUND_HUMAN_EFFORTINJURY_GRUNT_3,
 SOUND_HUMAN_EFFORTINJURY_GRUNT_4,
 SOUND_HUMAN_EFFORTINJURY_GRUNT_5,
 SOUND_HUMAN_ALERT_1,
 SOUND_HUMAN_ALERT_2,
 SOUND_HUMAN_ALERT_3,
 SOUND_HUMAN_DEATH_SCREAM_1,
 SOUND_HUMAN_DEATH_SCREAM_2,
 SOUND_HUMAN_DEATH_SCREAM_3,
 SOUND_HUMAN_VIOLENT_DEATH_1,
 SOUND_HUMAN_VIOLENT_DEATH_2,
 SOUND_HUMAN_VIOLENT_DEATH_3,
 SOUND_ANCIENT_WARRIOR_SCREAM,
 SOUND_ANCIENT_WARRIOR_ALERT,
 SOUND_ANCIENT_WARRIOR_ATTACK,
 SOUND_ANCIENT_WARRIOR_DEATH,
 SOUND_HIGH_PRIEST_TELEPORT,
 SOUND_HIGH_PRIEST_SPELL_ATTACK,
 SOUND_SUBTERRANEAN_SCREAM,
 SOUND_SUBTERRANEAN_EARTH_RUMBLE,
 SOUND_SUBTERRANEAN_ACID_ATTACK,
 SOUND_SUBTERRANEAN_ACID_IMPACT,
 SOUND_SUBTERRANEAN_DEATH,
 SOUND_SUBTERRANEAN_VIOLENT_DEATH,
 SOUND_LEAPER_FOOTFALL,
 SOUND_LEAPER_SCREAM,
 SOUND_LEAPER_ALERT,
 SOUND_LEAPER_INJURY,
 SOUND_LEAPER_ATTACK,
 SOUND_LEAPER_DEATH,
 SOUND_LEAPER_VIOLENT_DEATH,
 SOUND_LEAPER_CHITTER,
 SOUND_ALIEN_FOOTFALL,
 SOUND_ALIEN_SCREAM,
 SOUND_ALIEN_ALERT,
 SOUND_ALIEN_INJURY,
 SOUND_ALIEN_DEATH,
 SOUND_ALIEN_JETPACK_MALFUNCTION,
 SOUND_ALIEN_VIOLENT_DEATH,
 SOUND_HULK_FOOTFALL,
 SOUND_HULK_SCREAM,
 SOUND_HULK_ALERT,
 SOUND_HULK_INJURY,
 SOUND_HULK_ATTACK,
 SOUND_HULK_DEATH,
 SOUND_HULK_VIOLENT_DEATH,
 SOUND_HULK_BREATHE,
 SOUND_ROBOT_FOOTFALL,
 SOUND_ROBOT_SERVO_1,
 SOUND_ROBOT_SERVO_2,
 SOUND_ROBOT_SERVO_3,
 SOUND_ROBOT_SERVO_4,
 SOUND_ROBOT_VOICE_FX_1,
 SOUND_ROBOT_VOICE_FX_2,
 SOUND_ROBOT_VOICE_FX_3,
 SOUND_ROBOT_SHORT_1,
 SOUND_ROBOT_SHORT_2,
 SOUND_ROBOT_SHORT_3,
 SOUND_ROBOT_SHUTDOWN,
 SOUND_DROID_MOVE,
 SOUND_DROID_SERVO_1,
 SOUND_DROID_SERVO_2,
 SOUND_DROID_SERVO_3,
 SOUND_DROID_OBJECT_LOCATED,
 SOUND_SECURITY_DROID_MOVE,
 SOUND_SECURITY_DROID_LASER_FIRE,
 SOUND_SECURITY_DROID_LASER_LOCK_ON,
 SOUND_SECURITY_DROID_EXTINGUISH,
 SOUND_MANTIS_SCREAM_1,
 SOUND_MANTIS_SCREAM_2,
 SOUND_MANTIS_CHITTER,
 SOUND_MANTIS_INJURY,
 SOUND_MANTIS_ATTACK,
 SOUND_MANTIS_VIOLENT_DEATH,
 SOUND_TREX_FOOTFALL,
 SOUND_TREX_SCREAM,
 SOUND_TREX_SERVO_1,
 SOUND_TREX_SERVO_2,
 SOUND_TREX_SERVO_3,
 SOUND_TREX_SNIFF,
 SOUND_TREX_EYE_LASER_FIRE,
 SOUND_TREX_FIRE_BREATHE,
 SOUND_TREX_BITE_ATTACK,
 SOUND_TREX_VIOLENT_DEATH,
 SOUND_LONGHUNTER_TAUNT_1,
 SOUND_LONGHUNTER_TAUNT_2,
 SOUND_LONGHUNTER_TAUNT_3,
 SOUND_CAMPAIGNERS_TAUNT_1_PATHETIC,
 SOUND_CAMPAIGNERS_TAUNT_2_DIE,
 SOUND_CAMPAIGNERS_RAGE_UNIVERSE,
 SOUND_CAMPAIGNERS_ATTACK,
 SOUND_CAMPAIGNERS_SPELL,
 SOUND_CAMPAIGNERS_SHORTING_OUT_LAUGH,
 SOUND_CAMPAIGNERS_DEATH,
 SOUND_THROW_TOMAHAWK,
 SOUND_TOMAHAWK_GLOW,
 SOUND_TOMAHAWK_IMPACT_FLESH,
 SOUND_SHOCKWAVE_WEAPON_FIRE,
 SOUND_SHOCKWAVE_WEAPON_READY,
 SOUND_SHOCKWAVE_WEAPON_FRY,
 SOUND_RAPTOR_LASER_FIRE,
 SOUND_ROTATING_LIFT_SERVO,
 SOUND_PTERANODON_FLY_SWOOSH,
 SOUND_ROBOT_MALFUNCTION,
 SOUND_MANTIS_FIREBALL,
 SOUND_MANTIS_DEATH_RAIN,
 SOUND_FOOTFALL_ON_WOOD_PLANK,
 SOUND_TOUCAN_FLY_BY,
 SOUND_ANTELOPE_FLEE,
 SOUND_READY_GRENADE_LAUNCHER,
 SOUND_MINIGUN_STOP,
 SOUND_READY_PULSE_RIFLE,
 SOUND_READY_ASSAULT_RIFLE,
 SOUND_READY_MINI_GUN,
 SOUND_READY_AUTO_SHOTGUN,
 SOUND_RELOAD_MISSLE_LAUNCHER,
 SOUND_RELOAD_AUTO_SHOTGUN,
 SOUND_GENERIC_1,
    SOUND_GENERIC_2,
    SOUND_GENERIC_3,
    SOUND_GENERIC_4,
    SOUND_GENERIC_5,
    SOUND_GENERIC_6,
    SOUND_GENERIC_7,
 SOUND_GENERIC_8,
    SOUND_GENERIC_9,
    SOUND_GENERIC_10,
    SOUND_GENERIC_11,
    SOUND_GENERIC_12,
    SOUND_GENERIC_13,
    SOUND_GENERIC_14,
    SOUND_GENERIC_15,
    SOUND_GENERIC_16,
    SOUND_GENERIC_17,
    SOUND_GENERIC_18,
    SOUND_GENERIC_19,
    SOUND_GENERIC_20,
    SOUND_GENERIC_21,
    SOUND_GENERIC_22,
    SOUND_GENERIC_23,
    SOUND_GENERIC_24,
    SOUND_GENERIC_25,
    SOUND_GENERIC_26,
    SOUND_GENERIC_27,
    SOUND_GENERIC_28,
    SOUND_GENERIC_29,
    SOUND_GENERIC_30,
    SOUND_GENERIC_31,
    SOUND_GENERIC_32,
    SOUND_GENERIC_33,
    SOUND_GENERIC_34,
    SOUND_GENERIC_35,
    SOUND_GENERIC_36,
    SOUND_GENERIC_37,
    SOUND_GENERIC_38,
    SOUND_GENERIC_39,
    SOUND_GENERIC_40,
    SOUND_GENERIC_41,
    SOUND_GENERIC_42,
    SOUND_GENERIC_43,
    SOUND_GENERIC_44,
    SOUND_GENERIC_45,
    SOUND_GENERIC_46,
    SOUND_GENERIC_47,
    SOUND_GENERIC_48,
    SOUND_GENERIC_49,
    SOUND_GENERIC_50,
    SOUND_GENERIC_51,
    SOUND_GENERIC_52,
    SOUND_GENERIC_53,
    SOUND_GENERIC_54,
    SOUND_GENERIC_55,
    SOUND_GENERIC_56,
    SOUND_GENERIC_57,
    SOUND_GENERIC_58,
    SOUND_GENERIC_59,
    SOUND_GENERIC_60,
    SOUND_GENERIC_61,
    SOUND_GENERIC_62,
    SOUND_GENERIC_63,
    SOUND_GENERIC_64,
    SOUND_GENERIC_65,
    SOUND_GENERIC_66,
    SOUND_GENERIC_67,
    SOUND_GENERIC_68,
    SOUND_GENERIC_69,
    SOUND_GENERIC_70,
    SOUND_GENERIC_71,
    SOUND_GENERIC_72,
    SOUND_GENERIC_73,
    SOUND_GENERIC_74,
    SOUND_GENERIC_75,
    SOUND_GENERIC_76,
    SOUND_GENERIC_77,
    SOUND_GENERIC_78,
    SOUND_GENERIC_79,
    SOUND_GENERIC_80,
    SOUND_GENERIC_81,
    SOUND_GENERIC_82,
    SOUND_GENERIC_83,
    SOUND_GENERIC_84,
    SOUND_GENERIC_85,
    SOUND_GENERIC_86,
    SOUND_GENERIC_87,
    SOUND_GENERIC_88,
    SOUND_GENERIC_89,
    SOUND_GENERIC_90,
    SOUND_GENERIC_91,
    SOUND_GENERIC_92,
    SOUND_GENERIC_93,
    SOUND_GENERIC_94,
    SOUND_GENERIC_95,
    SOUND_GENERIC_96,
    SOUND_GENERIC_97,
    SOUND_GENERIC_98,
    SOUND_GENERIC_99,
    SOUND_GENERIC_100,
    SOUND_GENERIC_101,
    SOUND_GENERIC_102,
    SOUND_GENERIC_103,
    SOUND_GENERIC_104,
    SOUND_GENERIC_105,
    SOUND_GENERIC_106,
    SOUND_GENERIC_107,
    SOUND_GENERIC_108,
    SOUND_GENERIC_109,
    SOUND_GENERIC_110,
    SOUND_GENERIC_111,
    SOUND_GENERIC_112,
    SOUND_GENERIC_113,
    SOUND_GENERIC_114,
    SOUND_GENERIC_115,
    SOUND_GENERIC_116,
    SOUND_GENERIC_117,
    SOUND_GENERIC_118,
    SOUND_GENERIC_119,
    SOUND_GENERIC_120,
    SOUND_GENERIC_121,
    SOUND_GENERIC_122,
    SOUND_GENERIC_123,
    SOUND_GENERIC_124,
    SOUND_GENERIC_125,
    SOUND_GENERIC_126,
    SOUND_GENERIC_127,
    SOUND_GENERIC_128,
    SOUND_GENERIC_129,
    SOUND_GENERIC_130,
    SOUND_GENERIC_131,
    SOUND_GENERIC_132,
    SOUND_GENERIC_133,
    SOUND_GENERIC_134,
    SOUND_GENERIC_135,
    SOUND_GENERIC_136,
    SOUND_GENERIC_137,
    SOUND_GENERIC_138,
 SOUND_GENERIC_139,
 SOUND_GENERIC_140,
 SOUND_GENERIC_141,
 SOUND_GENERIC_142,
 SOUND_GENERIC_143,
 SOUND_GENERIC_144,
 SOUND_GENERIC_145,
 SOUND_GENERIC_146,
 SOUND_GENERIC_147,
 SOUND_GENERIC_148,
 SOUND_GENERIC_149,
 SOUND_GENERIC_150,
 SOUND_GENERIC_151,
 SOUND_GENERIC_152,
 SOUND_GENERIC_153,
 SOUND_GENERIC_154,
 SOUND_GENERIC_155,
 SOUND_GENERIC_156,
 SOUND_GENERIC_157,
 SOUND_GENERIC_158,
 SOUND_GENERIC_159,
 SOUND_GENERIC_160,
 SOUND_GENERIC_161,
 SOUND_GENERIC_162,
 SOUND_GENERIC_163,
 SOUND_GENERIC_164,
 SOUND_GENERIC_165,
 SOUND_GENERIC_166,
 SOUND_GENERIC_167,
 SOUND_GENERIC_168,
 SOUND_GENERIC_169,
 SOUND_GENERIC_170,
 SOUND_GENERIC_171,
 SOUND_GENERIC_172,
 SOUND_GENERIC_173,
 SOUND_GENERIC_174,
 SOUND_GENERIC_175,
 SOUND_GENERIC_176,
 SOUND_GENERIC_177,
 SOUND_GENERIC_178,
 SOUND_GENERIC_179,
 SOUND_GENERIC_180,
 SOUND_GENERIC_181,
 SOUND_GENERIC_182,
 SOUND_GENERIC_183,
 SOUND_GENERIC_184,
 SOUND_GENERIC_185,
 SOUND_GENERIC_186,
 SOUND_GENERIC_187,
 SOUND_GENERIC_188,
 SOUND_GENERIC_189,
 SOUND_GENERIC_190,
 SOUND_GENERIC_191,
 SOUND_GENERIC_192,
 SOUND_GENERIC_193,
 SOUND_GENERIC_194,
 SOUND_GENERIC_195,
 SOUND_GENERIC_196,
 SOUND_GENERIC_197,
 SOUND_GENERIC_198,
 SOUND_GENERIC_199,
 SOUND_GENERIC_200,
    SOUND_GENERIC_201,
    SOUND_GENERIC_202,
    SOUND_GENERIC_203,
    SOUND_GENERIC_204,
    SOUND_GENERIC_205,
    SOUND_GENERIC_206,
    SOUND_GENERIC_207,
    SOUND_GENERIC_208,
    SOUND_GENERIC_209,
    SOUND_GENERIC_210,
    SOUND_GENERIC_211,
    SOUND_GENERIC_212,
    SOUND_GENERIC_213,
    SOUND_GENERIC_214,
    SOUND_GENERIC_215,
    SOUND_GENERIC_216,
    SOUND_GENERIC_217,
    SOUND_GENERIC_218,
    SOUND_GENERIC_219,
    SOUND_GENERIC_220,
    SOUND_GENERIC_221,
    SOUND_GENERIC_222,
    SOUND_GENERIC_223,
    SOUND_GENERIC_224,
    SOUND_GENERIC_225,
    SOUND_GENERIC_226,
    SOUND_GENERIC_227,
    SOUND_GENERIC_228,
    SOUND_GENERIC_229,
    SOUND_GENERIC_230,
    SOUND_GENERIC_231,
    SOUND_GENERIC_232,
    SOUND_GENERIC_233,
    SOUND_GENERIC_234,
    SOUND_GENERIC_235,
    SOUND_GENERIC_236,
    SOUND_GENERIC_237,
    SOUND_GENERIC_238,
 SOUND_GENERIC_239,
 SOUND_GENERIC_240,
 SOUND_GENERIC_241,
 SOUND_GENERIC_242,
 SOUND_GENERIC_243,
 SOUND_GENERIC_244,
 SOUND_GENERIC_245,
 SOUND_GENERIC_246,
 SOUND_GENERIC_247,
 SOUND_GENERIC_248,
 SOUND_GENERIC_249,
 SOUND_GENERIC_250,
 SOUND_TYPES_TOTAL
};
extern int D_80128F90;
int func_8007BA2C ( CGameObjectInstance *pMe, CTControl *pCTControl, CTMove *pCTMove, int waterFlag);
int func_8007BA2C ( CGameObjectInstance *pMe, CTControl *pCTControl, CTMove *pCTMove, int waterFlag){
 /* Fire a grenade, consume ammo, and trigger its sound, event, recoil, and animation. */
 CEngineApp *pApp;
 CVector3 vPos;
 pApp = (&D_800F9F10);
 if (pApp == 0) return 0;
 if (func_800510C4(pCTControl))
 {
  func_800587B0(pCTMove, 10);
  if (func_8005843C(pCTMove, 109, 1))
  {
   if (D_80128F90)
    func_80058B6C(pCTMove, 1, 0);
   else
    func_80058B6C(pCTMove, 1, 1);
   func_8005AFE8(pCTMove, 1);
   return 0;
  }
  vPos = ((pMe)->ah.ih.m_vPos);
  func_80031974(&(&D_800F9F10)->m_Scene, SOUND_GRENADE_LAUNCH, 0, 0, &vPos, 0);
  D_80070DA8 (&pMe->ah.ih, &pMe->ah.ih, 29, 0xffffffff, ((pMe)->ah.ih.m_vPos), 10);
  func_80057DC8(pCTMove, &pCTMove->GrenadeLauncherAmmo, 1);
  func_80059244 ( pCTMove, pApp, 5*(1024.0/100.0)/12, -(3.14159265358979323846/90), 1 );
  D_80059994 ( pCTMove, 10 );
  func_8005FCF4 ( pMe, 45, 1 );
  (&((pMe)->m_AI))->m_dwStatusFlags |= (1<<4);
  func_8001E93C(pMe);
  return 1;
 }
 else
 {
  if (func_8005843C(pCTMove, 109, 1))
  {
   if (D_80128F90)
    func_80058B6C(pCTMove, 1, 0);
   else
    func_80058B6C(pCTMove, 1, 1);
   func_8005AFE8(pCTMove, 1);
  }
 }
 return 0;
}
