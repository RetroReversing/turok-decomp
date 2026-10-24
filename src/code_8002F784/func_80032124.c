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
typedef struct CUnindexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
   unsigned long m_CurrentAllocSize;
} CUnindexedSet;
struct CIndexedSet_t;
extern void func_8002DA8C(CUnindexedSet *pThis,
               void *pData, int AutoDeleteData );
extern void D_8002DA18(CUnindexedSet *pThis,
                  void *pData, int BlockSize, int BlockCount, int AutoDeleteData );
extern void func_8002D7AC(CUnindexedSet *pThis, void *pDest, int CopyBack);
typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;
extern void func_8002DD28(CIndexedSet *pThis, void *pData, int AutoDeleteData );
extern void* D_8002DC68(CIndexedSet *pThis, void *pBaseAddress, int nBlock);
extern ROMAddress* D_8002DC24(CIndexedSet *pThis,
                                       ROMAddress *rpBaseAddress, int nBlock);
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
extern void* func_8002D690(CCacheEntry *pThis);
extern void* func_8002D648(CCacheEntry *pThis, unsigned long NewSize, int AllocTop);
extern void func_8002D604(CCacheEntry *pThis, void *pNewData, unsigned long NewLength);
extern int D_8002D6BC(CCacheEntry *pThis, int AllocTop);
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
typedef struct CROMSimpleInstance_t
{
 CVector3 m_vPos;
 float m_MaxRadius;
 unsigned short m_nObjType,
      m_nCurrentRegion,
      m_nVariation,
      m_wFlags,
      m_nID;
 signed char m_RotY;
 unsigned char m_bActiveFlags;
} CROMSimpleInstance;
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
extern void func_800203B0(CGameSimpleInstance *pThis, CROMSimpleInstance *pSource,
                    ROMAddress *rpObjectAddress,
                    CGameRegion Regions[], CEnemyAttributes Variations[]);
typedef struct CROMEfficientStaticInstance_t
{
 float m_Scale;
 unsigned short m_nObjType,
      m_nCurrentRegion,
      m_nVariation,
      m_wFlags;
 short m_nPosY;
 unsigned char m_bFlags,
      m_bActiveFlags,
      m_nPosX, m_nPosZ;
 signed char m_nMinX, m_nMaxX,
      m_nMinY, m_nMaxY,
      m_nMinZ, m_nMaxZ;
} CROMEfficientStaticInstance;
typedef struct CROMStaticInstance_t
{
   CVector3 m_vPos,
      m_vScale;
 SF m_BoundsMinX, m_BoundsMinY, m_BoundsMinZ,
      m_BoundsMaxX, m_BoundsMaxY, m_BoundsMaxZ;
 unsigned short m_nObjType,
      m_nCurrentRegion,
      m_nVariation;
 unsigned char m_bFlags,
      m_bActiveFlags;
 signed char m_RotX, m_RotY, m_RotZ, m_RotT;
} CROMStaticInstance;
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
extern void func_8001F4E0(CGameStaticInstance *pThis, CROMEfficientStaticInstance *pSource,
                       ROMAddress *rpObjectAddress,
                       CGameRegion Regions[], CEnemyAttributes Variations[],
                       float GridDistance);
extern void func_8001F2B4(CGameStaticInstance *pThis, CROMStaticInstance *pSource,
                    ROMAddress *rpObjectAddress,
                    CGameRegion Regions[], CEnemyAttributes Variations[]);
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
 CParticle m_Particles[128],
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
extern int func_800320E4(CScene *pThis, CGameSimpleInstance *pSimple);
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
struct CCollisionInfo2_t;
extern void func_80032124(CScene *pThis, CCacheEntry **ppceTarget);
int func_800320E4(CScene *pThis, CGameSimpleInstance *pSimple);
void func_80032124(CScene *pThis, CCacheEntry **ppceTarget);
void func_80032124(CScene *pThis, CCacheEntry **ppceTarget){
 CCacheEntry *pceGridSection;
 CIndexedSet isCollision,
        isObjectsIndex,
        isGridSection,
        isNewGridSection;
 void *pbEStaticInstances,
        *pbStaticInstances,
        *pbSimpleInstances,
        *pbNewGridSection,
        *pbNewStaticInstances,
        *pbNewSimpleInstances,
        *pbRegions;
 CUnindexedSet usEStaticInstances,
        usStaticInstances,
        usSimpleInstances,
        usNewStaticInstances,
        usNewSimpleInstances,
        usObjectAttributes,
        usRegions;
 unsigned char *pBytes;
 int
        cEStatic, nEStatics,
        cStatic, nStatics,
        cSimple, nSimples,
        newStaticSize, newSimpleSize,
        newSize,
        offset;
   CROMEfficientStaticInstance *romEStaticInstances;
   CROMStaticInstance *romStaticInstances;
   CGameStaticInstance *gameStaticInstances;
   CROMSimpleInstance *romSimpleInstances;
   CGameSimpleInstance *gameSimpleInstances;
 CGameRegion *regions;
 CEnemyAttributes *variations;
 ROMAddress *rpObjectAddress;
                              ;
 if (!D_8002D6BC(*ppceTarget, 1))
  return;
                                                       ;
 pceGridSection = *ppceTarget;
   func_8002DD28(&isGridSection,
             func_8002D690(pceGridSection),
             0);
 if (!(((unsigned long*) (&isGridSection)->m_pData)[0]))
 {
                                       ;
  return;
 }
 pbEStaticInstances = D_8002DC68((&isGridSection), (&isGridSection)->m_pData, (0));
 func_8002DA8C(&usEStaticInstances, pbEStaticInstances, 0);
 nEStatics = ( (unsigned long) (((unsigned long*) (&usEStaticInstances)->m_pData)[1]) );
                                                                 ;
 pbStaticInstances = D_8002DC68((&isGridSection), (&isGridSection)->m_pData, (1));
 func_8002DA8C(&usStaticInstances, pbStaticInstances, 0);
 nStatics = ( (unsigned long) (((unsigned long*) (&usStaticInstances)->m_pData)[1]) );
                                                      ;
 newStaticSize = ( ( (((2*sizeof(unsigned long)) + (sizeof(CGameStaticInstance))*(nEStatics + nStatics))) + ((8) - 1) ) & ~((unsigned long) (8) - 1) );
 pbSimpleInstances = D_8002DC68((&isGridSection), (&isGridSection)->m_pData, (2));
 func_8002DA8C(&usSimpleInstances, pbSimpleInstances, 0);
 nSimples = ( (unsigned long) (((unsigned long*) (&usSimpleInstances)->m_pData)[1]) );
                                                      ;
 newSimpleSize = ( ( (((2*sizeof(unsigned long)) + (sizeof(CGameSimpleInstance))*(nSimples))) + ((8) - 1) ) & ~((unsigned long) (8) - 1) );
 newSize = ( ( ((1*sizeof(unsigned long)) + ((2)+1)*sizeof(unsigned long)) + ((8) - 1) ) & ~((unsigned long) (8) - 1) ) + newStaticSize + newSimpleSize;
 pBytes = func_8002D648(pThis->m_pceCollision, newSize, 0);
 if (pBytes)
 {
  pbNewGridSection = pBytes;
  func_8002DD28(&isNewGridSection, pbNewGridSection, 0);
  offset = ( ( ((1*sizeof(unsigned long)) + ((2)+1)*sizeof(unsigned long)) + ((8) - 1) ) & ~((unsigned long) (8) - 1) );
  ((unsigned long*) ((&isNewGridSection)->m_pData))[0] = ((unsigned long) (0));
  ((unsigned long*) ((&isNewGridSection)->m_pData))[1 + (((unsigned long*) (&isNewGridSection)->m_pData)[0])] = ((unsigned long) (offset));
  pbNewStaticInstances = pBytes + offset;
                                                                            ;
  func_8002D7AC(&usEStaticInstances, pbNewStaticInstances, 1);
                                                                   ;
  func_8002D7AC(&usStaticInstances, pbNewStaticInstances, 1);
  D_8002DA18(&usNewStaticInstances,
                 pbNewStaticInstances,
                 sizeof(CGameStaticInstance),
                 nEStatics + nStatics,
                 0);
  romEStaticInstances = (CROMEfficientStaticInstance*) ( (void*) ( ((unsigned char*)((&usEStaticInstances)->m_pData)) + (2*sizeof(unsigned long)) ) );
  romStaticInstances = (CROMStaticInstance*) ( (void*) ( ((unsigned char*)((&usStaticInstances)->m_pData)) + (2*sizeof(unsigned long)) ) );
  gameStaticInstances = (CGameStaticInstance*) ( (void*) ( ((unsigned char*)((&usNewStaticInstances)->m_pData)) + (2*sizeof(unsigned long)) ) );
                               ;
  func_8002DD28(&isCollision,
              func_8002D690(pThis->m_pceCollision),
              0);
  pbRegions = D_8002DC68((&isCollision), (&isCollision)->m_pData, (2));
  func_8002DA8C(&usRegions, pbRegions, 0);
  regions = (CGameRegion*) ( (void*) ( ((unsigned char*)((&usRegions)->m_pData)) + (2*sizeof(unsigned long)) ) );
                                  ;
  func_8002DD28(&isObjectsIndex,
              func_8002D690(pThis->m_pceObjectsIndex),
              0);
                                      ;
  func_8002DA8C(&usObjectAttributes,
              func_8002D690(pThis->m_pceObjectAttributes),
              0);
  variations = (CEnemyAttributes*) ( (void*) ( ((unsigned char*)((&usObjectAttributes)->m_pData)) + (2*sizeof(unsigned long)) ) );
  for (cEStatic=0; cEStatic<nEStatics; cEStatic++)
  {
   rpObjectAddress = D_8002DC24(&isObjectsIndex,
                  pThis->m_rpObjectsAddress,
                  romEStaticInstances[cEStatic].m_nObjType);
   func_8001F4E0(&gameStaticInstances[cEStatic],
                       &romEStaticInstances[cEStatic],
                       rpObjectAddress,
                       regions, variations,
                       pThis->m_LevelInfo.m_GridDistance);
  }
  for (cStatic=0; cStatic<nStatics; cStatic++)
  {
   rpObjectAddress = D_8002DC24(&isObjectsIndex,
                  pThis->m_rpObjectsAddress,
                  romStaticInstances[cStatic].m_nObjType);
   func_8001F2B4(&gameStaticInstances[cStatic + nEStatics],
                    &romStaticInstances[cStatic],
                    rpObjectAddress,
                    regions, variations);
  }
  offset += newStaticSize;
  ((unsigned long*) ((&isNewGridSection)->m_pData))[0] = ((unsigned long) (1));
  ((unsigned long*) ((&isNewGridSection)->m_pData))[1 + (((unsigned long*) (&isNewGridSection)->m_pData)[0])] = ((unsigned long) (offset));
  pbNewSimpleInstances = pBytes + offset;
                                                                   ;
  func_8002D7AC(&usSimpleInstances, pbNewSimpleInstances, 1);
  D_8002DA18(&usNewSimpleInstances,
                 pbNewSimpleInstances,
                 sizeof(CGameSimpleInstance),
                 nSimples,
                 0);
  romSimpleInstances = (CROMSimpleInstance*) ( (void*) ( ((unsigned char*)((&usSimpleInstances)->m_pData)) + (2*sizeof(unsigned long)) ) );
  gameSimpleInstances = (CGameSimpleInstance*) ( (void*) ( ((unsigned char*)((&usNewSimpleInstances)->m_pData)) + (2*sizeof(unsigned long)) ) );
  for (cSimple=0; cSimple<nSimples; cSimple++)
  {
   rpObjectAddress = D_8002DC24(&isObjectsIndex,
                  pThis->m_rpObjectsAddress,
                  romSimpleInstances[cSimple].m_nObjType);
   func_800203B0(&gameSimpleInstances[cSimple],
                    &romSimpleInstances[cSimple],
                    rpObjectAddress,
                    regions, variations);
   if (func_800320E4(pThis, &gameSimpleInstances[cSimple]))
    gameSimpleInstances[cSimple].m_wFlags |= (1 << 0);
  }
  offset += newSimpleSize;
  ((unsigned long*) ((&isNewGridSection)->m_pData))[0] = ((unsigned long) (2));
  ((unsigned long*) ((&isNewGridSection)->m_pData))[1 + (((unsigned long*) (&isNewGridSection)->m_pData)[0])] = ((unsigned long) (offset));
                                                ;
                                                    ;
                                              ;
                                     ;
                                     ;
                                        ;
                                          ;
 }
 func_8002D604(pceGridSection, pBytes, newSize);
                                               ;
                                      ;
                                            ;
                                            ;
}
