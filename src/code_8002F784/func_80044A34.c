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
typedef struct CBossScript_t
{
 signed short *m_pStart ;
 signed short *m_pCurrent ;
} CBossScript ;
extern signed long func_8004045C(CGameObjectInstance *pThis, CVector3 *pvPos, signed long Length) ;
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
typedef struct CSpeacialFx_t
{
 CGameObjectInstance *m_pInst ;
 signed long m_Command ;
 float m_Time ;
 float *m_pScriptStart ;
 float *m_pScript ;
 float m_Trans ;
 float m_StartTrans ;
 float m_FinalTrans ;
 float m_TransFadeTime ;
 float m_Color ;
 float m_StartColor ;
 float m_FinalColor ;
 float m_ColorFadeTime ;
 CRGB m_EnvColor ;
 CRGB m_StartEnvColor ;
 CRGB m_FinalEnvColor ;
} CSpecialFx ;
struct CCollisionInfo2_t;
typedef struct MantisStageInfo_t
{
 signed long HealthLimit ;
 float AnimSpeed ;
 float FlySpeed ;
 float MaxWalkTime ;
 signed long FlySpitSkips ;
 signed long HitsBeforeExplosion ;
 float *pAttackGlowFx ;
 signed short *pFloorAttackScript ;
 signed short *pFloorCloseAttackScript ;
 signed short *pCeilingAttackScript ;
 signed short *pLeftWallAttackScript ;
 signed short *pRightWallAttackScript ;
} CMantisStageInfo ;
typedef struct CMantis_t
{
 CBoss m_Boss ;
 signed short m_ScriptStage ;
 CMantisStageInfo *m_pStageInfo ;
 CBossScript m_FloorAttackScript ;
 CBossScript m_FloorCloseAttackScript ;
 CBossScript m_CeilingAttackScript ;
 CBossScript m_LeftWallAttackScript ;
 CBossScript m_RightWallAttackScript ;
 int m_WallBroken[4] ;
 signed short m_WallsToBreak ;
 signed short m_WallToAimFor ;
 signed short m_WallToAimForJumpPos ;
 CGameRegion *m_pWallCollisionRegion ;
 CVector3 m_vWallPos ;
 float m_WallCollapseTime ;
 int m_GotoFloor ;
 float m_FlyTargetY ;
 float m_FlySpeed ;
 float m_FlyTime ;
 float m_WallAngle ;
 float m_WalkTime ;
 signed short m_FlySpitTotal ;
 int m_FlinchGlow ;
 int m_ChoosePosition ;
 CSpecialFx m_SpecialFx ;
 CSpecialFx m_FlashSpecialFx ;
 signed long m_ExplosionHits ;
 int m_AcidHurtTurok ;
} CMantis ;
signed long func_80044908(CGameObjectInstance *pThis);
extern CVector3 D_800BC640[];
signed long func_80044A34(CGameObjectInstance *pThis, CMantis *pMantis);
signed long func_80044A34(CGameObjectInstance *pThis, CMantis *pMantis){
 signed long Chosen = -1 ;
 if (pMantis->m_WallToAimFor != -1)
 {
  switch(pMantis->m_WallToAimFor)
  {
   case 0:
    if (func_80044908(pThis) == 0)
     Chosen = 1 ;
    else
    if (func_80044908(pThis) == 3)
     Chosen = 0 ;
    break ;
   case 1:
    if (func_80044908(pThis) == 0)
     Chosen = 2 ;
    else
    if (func_80044908(pThis) == 1)
     Chosen = 3 ;
    break ;
   case 2:
    if (func_80044908(pThis) == 1)
     Chosen = 4 ;
    else
    if (func_80044908(pThis) == 2)
     Chosen = 5 ;
    break ;
   case 3:
    if (func_80044908(pThis) == 2)
     Chosen = 6 ;
    else
    if (func_80044908(pThis) == 3)
     Chosen = 7 ;
    break ;
  }
  if (Chosen != -1)
   pMantis->m_WallToAimForJumpPos = Chosen ;
  else
  {
   Chosen = pMantis->m_WallToAimFor ;
   pMantis->m_WallToAimForJumpPos = (Chosen * 2) +
             func_8004045C(pThis, &D_800BC640[Chosen * 2], 2) ;
  }
 }
 return pMantis->m_WallToAimForJumpPos ;
}
