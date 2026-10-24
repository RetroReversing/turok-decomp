#include "common.h"

extern const float D_800F1FEC; extern const float D_800F1FE8; extern const double D_800F1FF0;
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
typedef union 
{
  struct 
  {
    sa_f32 f_odd;
    sa_f32 f_even;
  } f;
  sa_f64 d;
} __OSfp;
typedef struct 
{
  sa_u64 at;
  sa_u64 v0;
  sa_u64 v1;
  sa_u64 a0;
  sa_u64 a1;
  sa_u64 a2;
  sa_u64 a3;
  sa_u64 t0;
  sa_u64 t1;
  sa_u64 t2;
  sa_u64 t3;
  sa_u64 t4;
  sa_u64 t5;
  sa_u64 t6;
  sa_u64 t7;
  sa_u64 s0;
  sa_u64 s1;
  sa_u64 s2;
  sa_u64 s3;
  sa_u64 s4;
  sa_u64 s5;
  sa_u64 s6;
  sa_u64 s7;
  sa_u64 t8;
  sa_u64 t9;
  sa_u64 gp;
  sa_u64 sp;
  sa_u64 sa_s8;
  sa_u64 ra;
  sa_u64 lo;
  sa_u64 hi;
  sa_u32 sr;
  sa_u32 pc;
  sa_u32 cause;
  sa_u32 badvaddr;
  sa_u32 rcp;
  sa_u32 fpcsr;
  __OSfp fp0;
  __OSfp fp2;
  __OSfp fp4;
  __OSfp fp6;
  __OSfp fp8;
  __OSfp fp10;
  __OSfp fp12;
  __OSfp fp14;
  __OSfp fp16;
  __OSfp fp18;
  __OSfp fp20;
  __OSfp fp22;
  __OSfp fp24;
  __OSfp fp26;
  __OSfp fp28;
  __OSfp fp30;
} __OSThreadContext;
typedef struct 
{
  sa_u32 flag;
  sa_u32 count;
  sa_u64 time;
} __OSThreadprofile_s;
typedef struct OSThread_s
{
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
typedef struct OSMesgQueue_s
{
  OSThread *mtqueue;
  OSThread *fullqueue;
  sa_s32 validCount;
  sa_s32 first;
  sa_s32 msgCount;
  OSMesg *msg;
} OSMesgQueue;
typedef struct 
{
  sa_u32 errStatus;
  void *dramAddr;
  void *C2Addr;
  sa_u32 sectorSize;
  sa_u32 C1ErrNum;
  sa_u32 C1ErrSector[4];
} __OSBlockInfo;
typedef struct 
{
  sa_u32 cmdType;
  sa_u16 transferMode;
  sa_u16 blockNum;
  sa_s32 sectorNum;
  sa_u32 devAddr;
  sa_u32 bmCtlShadow;
  sa_u32 seqCtlShadow;
  __OSBlockInfo block[2];
} __OSTranxInfo;
typedef struct OSPiHandle_s
{
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
typedef struct 
{
  sa_s32 active;
  OSThread *thread;
  OSMesgQueue *cmdQueue;
  OSMesgQueue *evtQueue;
  OSMesgQueue *acsQueue;
  sa_s32 (*dma)(sa_s32, sa_u32, void *, sa_u32);
  sa_s32 (*edma)(OSPiHandle *, sa_s32, sa_u32, void *, sa_u32);
} OSDevMgr;
typedef sa_u64 OSTime;
typedef struct 
{
  sa_u16 button;
  sa_s8 stick_x;
  sa_s8 stick_y;
  sa_u8 errno;
} OSContPad;
typedef struct 
{
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
typedef union 
{
  OSTask_t t;
  long long int force_structure_alignment;
} OSTask;
typedef struct 
{
  short ob[3];
  unsigned short flag;
  short tc[2];
  unsigned char cn[4];
} Vtx_t;
typedef struct 
{
  short ob[3];
  unsigned short flag;
  short tc[2];
  signed char n[3];
  unsigned char a;
} Vtx_tn;
typedef union 
{
  Vtx_t v;
  Vtx_tn n;
  long long int force_structure_alignment;
} Vtx;
typedef struct 
{
  unsigned char flag;
  unsigned char v[3];
} Tri;
typedef long Mtx_t[4][4];
typedef union 
{
  Mtx_t m;
  long long int force_structure_alignment;
} Mtx;
typedef struct 
{
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
  signed char dir[3];
  char pad3;
} Light_t;
typedef union 
{
  Light_t l;
  long long int force_structure_alignment[2];
} Light;
typedef struct 
{
  Light l[2];
} LookAt;
typedef struct 
{
  int cmd : 8;
  unsigned int par : 8;
  unsigned int len : 16;
  unsigned int addr;
} Gdma;
typedef struct 
{
  int cmd : 8;
  int pad : 24;
  Tri tri;
} Gtri;
typedef struct 
{
  int cmd : 8;
  int pad1 : 24;
  int pad2 : 24;
  unsigned char param : 8;
} Gpopmtx;
typedef struct 
{
  int cmd : 8;
  int pad0 : 8;
  int mw_index : 8;
  int number : 8;
  int pad1 : 8;
  int base : 24;
} Gsegment;
typedef struct 
{
  int cmd : 8;
  int pad0 : 8;
  int sft : 8;
  int len : 8;
  unsigned int data : 32;
} GsetothermodeL;
typedef struct 
{
  int cmd : 8;
  int pad0 : 8;
  int sft : 8;
  int len : 8;
  unsigned int data : 32;
} GsetothermodeH;
typedef struct 
{
  unsigned char cmd;
  unsigned char lodscale;
  unsigned char tile;
  unsigned char on;
  unsigned short s;
  unsigned short t;
} Gtexture;
typedef struct 
{
  int cmd : 8;
  int pad : 24;
  Tri line;
} Gline3D;
typedef struct 
{
  int cmd : 8;
  int pad1 : 24;
  short int pad2;
  short int scale;
} Gperspnorm;
typedef struct 
{
  int cmd : 8;
  unsigned int fmt : 3;
  unsigned int siz : 2;
  unsigned int pad : 7;
  unsigned int wd : 12;
  unsigned int dram;
} Gsetimg;
typedef struct 
{
  int cmd : 8;
  unsigned int muxs0 : 24;
  unsigned int muxs1 : 32;
} Gsetcombine;
typedef struct 
{
  int cmd : 8;
  unsigned char pad;
  unsigned char prim_min_level;
  unsigned char prim_level;
  unsigned long D_80130D78;
} Gsetcolor;
typedef struct 
{
  int cmd : 8;
  int x0 : 10;
  int x0frac : 2;
  int y0 : 10;
  int y0frac : 2;
  unsigned int pad : 8;
  int x1 : 10;
  int x1frac : 2;
  int y1 : 10;
  int y1frac : 2;
} Gfillrect;
typedef struct 
{
  int cmd : 8;
  unsigned int fmt : 3;
  unsigned int siz : 2;
  unsigned int pad0 : 1;
  unsigned int line : 9;
  unsigned int tmem : 9;
  unsigned int pad1 : 5;
  unsigned int tile : 3;
  unsigned int palette : 4;
  unsigned int ct : 1;
  unsigned int mt : 1;
  unsigned int maskt : 4;
  unsigned int shiftt : 4;
  unsigned int cs : 1;
  unsigned int ms : 1;
  unsigned int masks : 4;
  unsigned int shifts : 4;
} Gsettile;
typedef struct 
{
  int cmd : 8;
  unsigned int sl : 12;
  unsigned int tl : 12;
  int pad : 5;
  unsigned int tile : 3;
  unsigned int sh : 12;
  unsigned int th : 12;
} Gloadtile;
typedef Gloadtile Gsettilesize;
typedef Gloadtile Gloadtlut;
typedef struct 
{
  unsigned int w0;
  unsigned int w1;
} Gwords;
typedef union 
{
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
typedef int ROMAddress;
struct CCartCache_t;
typedef struct CCacheEntry_t
{
  void *m_pData;
  unsigned long m_DataLength;
  ROMAddress *m_rpAddress;
  unsigned long m_rLength;
  struct CCartCache_t *m_pOwner;
  unsigned long m_LastAccessed;
  int m_InHashTable;
  int m_Compressed;
  unsigned long m_Allocated;
  const char *m_szDescription;
  struct CCacheEntry_t *m_pLast;
  struct CCacheEntry_t *m_pNext;
  struct CCacheEntry_t *m_pNextFree;
} CCacheEntry;
typedef void (*pfnCACHENOTIFY)(void *pNotifyPtr, CCacheEntry **ppceTarget);
typedef struct CNotifyEntry_t
{
  void *m_pNotifyPtr;
  pfnCACHENOTIFY m_pfnDecompress;
  pfnCACHENOTIFY m_pfnBlockReceived;
  CCacheEntry **m_ppceTarget;
  ROMAddress *m_rpRequestedAddress;
  unsigned long m_rLength;
  const char *m_szDescription;
  struct CNotifyEntry_t *m_pLast;
  struct CNotifyEntry_t *m_pNext;
  struct CNotifyEntry_t *m_pNextFree;
} CNotifyEntry;
typedef struct CCartCache_t
{
  CHashTable m_HashTable;
  CNotifyEntry *m_pNotifyHead;
  CNotifyEntry *m_pNotifyTail;
  CCacheEntry *m_pCacheHead;
  CCacheEntry *m_pCacheTail;
  int m_DiscardAge;
  CCacheEntry m_CacheEntries[512];
  CCacheEntry *m_pCacheFreeHead;
  CNotifyEntry m_NotifyEntries[16];
  CNotifyEntry *m_pNotifyFreeHead;
} CCartCache;
struct CQuatern_t;
typedef struct CVector3_t
{
  float x;
  float y;
  float z;
} CVector3;
typedef float CMtxF[4][4];
typedef struct CQuatern_t
{
  float x;
  float y;
  float z;
  float t;
} CQuatern;
typedef struct CGameAnimateState_t
{
  CCacheEntry *m_pceAnim;
  unsigned long m_nAnim;
  unsigned long m_nDesiredAnim;
  unsigned long m_nFrames;
  float m_cFrame;
  int m_CycleCompleted;
} CGameAnimateState;
typedef struct CGeometry_t
{
  CCacheEntry *m_pceGeometry;
  CCacheEntry *m_pceTextureSetsIndex;
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
  float m_SightRadius;
  float m_SightAngle;
  float m_LoudRadius;
  float m_QuietRadius;
  float m_ProjectileRadius;
  float m_FlyingHeight;
  float m_CollisionRadius;
  float m_CollisionWallRadius;
  float m_CollisionHeight;
  float m_DeadHeight;
  float m_AttackRadius;
  float m_LeashRadius;
  float m_InteractiveAnimDelay;
  unsigned long m_dwSpecies;
  unsigned long m_dwTypeFlags;
  unsigned long m_dwTypeFlags2;
  unsigned short m_wTypeFlags3;
  short m_StartHealth;
  short m_Id;
  short m_DeathId;
  short m_Regenerate;
  unsigned char m_Aggression;
  unsigned char m_InteractiveAnim;
  unsigned char m_nModel;
  signed char m_nTexture;
  signed char m_AttackStyle;
  unsigned char unused1;
} CEnemyAttributes;
typedef struct CAIDynamic_t
{
  float m_ViewAngleOffset;
  float m_RetreatTimer;
  float m_TeleportTime;
  float m_Time1;
  float m_Time2;
  float m_InteractiveTimer;
  float m_AvoidanceAngle;
  float m_cRegenerateAppearance;
  float m_cRegenerateAppearanceWhite;
  float m_MeltTimer;
  float m_FreezeTimer;
  unsigned long m_dwStatusFlags;
  unsigned long m_dwStatusFlags2;
  short m_Agitation;
  short m_PrevAgitation;
  short m_Health;
  short m_Evade;
  short m_Regenerate;
  CVector3 m_vExplosion;
  CVector3 m_vLeashCoor;
  CVector3 m_vStartPos;
  int m_Invincible;
  int m_FirstRun;
  int m_DeathAnimType;
  struct CGameRegion_t *m_pStartRegion;
  short m_HeadTexture;
  short m_BodyTexture;
  short m_WeaponModel;
  short m_ExtraModel;
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
  unsigned short m_nRegionSet;
  unsigned short m_wFlags;
  CROMCorner *m_pCorners[3];
  struct CGameRegion_t *m_pNeighbors[3];
} CGameRegion;
typedef struct CROMBounds_t
{
  CVector3 m_vMin;
  CVector3 m_vMax;
} CROMBounds;
typedef struct CBoundsRect_t
{
  float m_MinX;
  float m_MinZ;
  float m_MaxX;
  float m_MaxZ;
} CBoundsRect;
typedef struct CInstanceHdr_t
{
  unsigned char m_Type;
  unsigned char m_bActiveFlags;
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
  CCacheEntry *m_pceObjectIndex;
  CCacheEntry *m_pceStaticEvents;
  ROMAddress *m_rpObjectIndexAddress;
  Mtx m_mOrientation[2];
  Mtx m_mShadow[2];
  CGeometry m_Geometry;
  CVector3 vRotAxis;
  float m_RotAngle;
  float m_AngleVel;
  CROMBounds m_Bounds;
  float m_Scale;
  float m_OffsetY;
  unsigned short m_wFlags;
  unsigned short m_nID;
  float m_Time;
  float m_MorphInc;
} CGameSimpleInstance;
typedef struct CGameStaticInstance_t
{
  CInstanceHdr ih;
  CCacheEntry *m_pceObjectIndex;
  CCacheEntry *m_pceStaticEvents;
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
  CQuatern m_qRot;
  CQuatern m_qGround;
  CQuatern m_qShadow;
  float m_RotY;
  float m_cMelt;
  float m_ShadowPercentage;
  Mtx m_mOrientation[2];
  CGeometry m_Geometry;
  Mtx *pmtDrawMtxs;
  ROMAddress *m_rpObject;
  ROMAddress *m_rpObjectInfo;
  ROMAddress *m_rpAnims;
  CCacheEntry *m_pceObjectIndex;
  CCacheEntry *m_pceObjectInfo;
  CCacheEntry *m_pceAnimsHeader;
  CCacheEntry *m_pceAnimsIndex;
  unsigned short m_ObjectInfoSize;
  unsigned short m_nTypeFlag;
  short m_nAnims;
  short m_nDesiredAnim;
  CBoundsRect m_BoundsRect;
  unsigned long m_dwFlags;
  CGameAnimateState m_asCurrent;
  CGameAnimateState m_asBlend;
  short m_BlendLength;
  short m_WaitingForAnim;
  short m_StartupAnimType;
  signed short m_Mode;
  float m_ModeTime;
  float m_ModeMisc1;
  float m_uBlender;
  float m_BlendPos;
  struct CBoss_t *m_pBoss;
  void (*m_pCollisionFunction)(void *pThis, struct CCollisionInfo2_t *pCollisionInfo);
  CQuatern (*m_pCalculateOrientation)(void *pThis);
  unsigned char m_BlendStart;
  unsigned char m_BlendFinish;
  signed short m_ActiveSwooshes;
  float m_HeadTrackBlend;
  float m_HeadTurnAngle;
  float m_HeadTurnAngleVel;
  float m_HeadTiltAngle;
  float m_HeadTiltAngleVel;
  struct CHeadTrackInfo_t *m_pHeadTrackInfo;
  CAIDynamic m_AI;
  struct CGameObjectInstance_t *m_pEventCGameObjectInstance;
  struct CGameObjectInstance_t *m_pAttackerCGameObjectInstance;
} CGameObjectInstance;
typedef struct CROMLevel_t
{
  float m_GridDistance;
  unsigned char m_BlackColor[3];
  unsigned char m_WhiteColor[3];
  unsigned char m_DirectionalLight[3];
  unsigned char m_AmbientLight[3];
  unsigned char m_bFlags;
  signed char m_Direction[3];
} CROMLevel;
typedef struct CROMParticleImpact_t
{
  float m_ImpactEventNumber[14];
  unsigned short m_ImpactParticleType[14];
  unsigned short m_ImpactEventType[14];
  unsigned short m_ImpactSoundType[14];
} CROMParticleImpact;
typedef struct CROMParticleEffect_t
{
  CROMParticleImpact *m_pImpact;
  unsigned long m_dwFlags;
  SF m_BounceEnergy;
  SF m_DirectionSpray;
  SF m_SprayX;
  SF m_SprayY;
  SF m_SprayZ;
  SF m_DirectionX;
  SF m_DirectionY;
  SF m_DirectionZ;
  SF m_Gravity;
  SF m_GravityRandom;
  SF m_GroundFriction;
  SF m_FpsVelThreshold;
  SF m_AirFriction;
  SF m_WaterFriction;
  SF m_Size;
  SF m_SizeRandom;
  SF m_Scaler;
  SF m_ScalerRandom;
  SF m_Velocity;
  SF m_VelocityRandom;
  SF m_PosRandomX;
  SF m_PosRandomY;
  SF m_PosRandomZ;
  SF m_Rotation;
  SF m_RotationRandom;
  SF m_RotationInc;
  SF m_RotationIncRandom;
  SF m_RotationPivotX;
  SF m_RotationPivotY;
  SF m_PosX;
  SF m_PosY;
  SF m_PosZ;
  short m_nTextureSet;
  short m_nParticles;
  short m_nParticleRandom;
  short m_nParticleFrames;
  short m_nParticleFrameRandom;
  short m_nParticleDelayFramesRandom;
  unsigned char m_FPS;
  unsigned char m_InstanceBehavior;
  unsigned char m_WallBehavior;
  unsigned char m_GroundBehavior;
  unsigned char m_Alignment;
  unsigned char m_WhiteColor[3];
  unsigned char m_BlackColor[3];
  unsigned char m_RandomizeHue;
  unsigned char m_RandomizeSaturation;
  unsigned char m_RandomizeBrightness;
  unsigned char m_Priority;
  unsigned char m_Playback;
  unsigned char m_Visibility;
  unsigned char m_nFadeInDelay;
  unsigned char m_nFadeOutDelay;
  unsigned char unused;
} CROMParticleEffect;
typedef struct CROMWarpPoint_t
{
  CVector3 m_vPos;
  float m_RotY;
  unsigned short m_nLevel;
  unsigned short m_nRegion;
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
  CVector3 vNextVelocity;
  CVector3 vNextDesired;
  CVector3 vIntersect;
  CVector3 *pvIntersectPos;
  struct CGameRegion_t **ppRegion;
  int *pCollType;
  int CollType;
  CInstanceHdr **ppInst;
  CInstanceHdr *pInstType;
} CClosestIntersect;
typedef struct CCollide_t
{
  struct CAnimInstanceHdr_t *pInst;
  struct CCollisionInfo2_t *pCI;
  CClosestIntersect clint;
  CVector3 vDesired;
  CVector3 vDelta;
  CVector3 vSliding;
  CVector3 vNextSliding;
  float SlidingRadius;
  float NextSlidingRadius;
  int SlidingType;
  int NextSlidingType;
  int AllowRedirection;
  int UsePhysics;
  int TrackingGround;
  int StartedInDeathFall;
} CCollide;
struct CInstanceHdr_t;
struct CGameRegion_t;
typedef struct CCollisionInfo2_t
{
  unsigned long dwFlags;
  int InstanceBehavior;
  int WallBehavior;
  int GroundBehavior;
  float GravityAcceleration;
  float BounceReturnEnergy;
  float GroundFriction;
  float AirFriction;
  float WaterFriction;
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
  float m_cFrame;
  float m_cFramePos;
  float m_FPS;
  int m_nFrames;
  int m_cAnimFrame;
  int m_nRandomFrame;
  float m_Size;
  float m_SizeScaler;
  float m_Rotation;
  float m_RotationInc;
  float m_DistanceSquared;
  unsigned char m_AlphaScaler;
  unsigned char m_ActiveSwooshes;
  CCollisionInfo2 m_CI;
  short m_Alignment;
  unsigned char m_WhiteColor[3];
  unsigned char m_BlackColor[3];
  struct CParticle_t *m_pLast;
  struct CParticle_t *m_pNext;
  struct CParticle_t *m_pDrawLast;
  struct CParticle_t *m_pDrawNext;
} CParticle;
typedef struct CParticleSystem_t
{
  CParticle m_Particles[2];
  CParticle *m_pFreeHead;
  CParticle *m_pActiveHead;
  CParticle *m_pActiveTail;
  CParticle *m_pDrawHead;
  CParticle *m_pDrawTail;
  CCartCache *m_pCache;
  CCacheEntry *m_pceParticleEffects;
  CCacheEntry *m_pceTextureSetsIndex;
} CParticleSystem;
struct CScene_t;
typedef struct CDynamicSimple_t
{
  CGameSimpleInstance s;
  float m_LifeTime;
  float m_SparkleTime;
  unsigned long m_dwFlags;
  struct CDynamicSimple_t **m_ppPickup;
  struct CDynamicSimple_t *m_pLast;
  struct CDynamicSimple_t *m_pNext;
} CDynamicSimple;
typedef struct CSimplePool_t
{
  CDynamicSimple m_Simples[32];
  CDynamicSimple *m_pFreeHead;
  CDynamicSimple *m_pActiveHead;
  CDynamicSimple *m_pActiveTail;
  CCartCache *m_pCache;
  CCacheEntry *m_pceObjectsIndex;
  ROMAddress *m_rpObjectsAddress;
  int m_Initialized;
} CSimplePool;
typedef struct CPickupGenerator_t
{
  float m_Time;
  CDynamicSimple *m_pPickup;
  CVector3 m_vPos;
  CGameRegion *m_pRegion;
} CPickupGenerator;
typedef struct CPickupMonitor_t
{
  int m_Active;
  CPickupGenerator m_Generators[16];
  signed long m_NoOfGenerators;
} CPickupMonitor;
typedef struct CScene_t
{
  CCartCache m_Cache;
  ROMAddress *m_rpBaseAddress;
  CCacheEntry *m_pceIndex;
  ROMAddress *m_rpObjectsAddress;
  ROMAddress *m_rpTextureSetsAddress;
  ROMAddress *m_rpLevelsAddress;
  ROMAddress *m_rpLevelAddress;
  ROMAddress *m_rpGridSectionsAddress;
  ROMAddress *m_rpObjectTypesAddress;
  ROMAddress *m_rpObjectAttributesAddress;
  ROMAddress *m_rpParticleEffectsAddress;
  ROMAddress *m_rpGridBoundsAddress;
  ROMAddress *m_rpWarpPointsAddress;
  ROMAddress *m_rpBinaries;
  CCacheEntry *m_pceObjectAttributes;
  CCacheEntry *m_pceObjectTypes;
  CCacheEntry *m_pceObjectsHeader;
  CCacheEntry *m_pceObjectsIndex;
  CCacheEntry *m_pceCollision;
  CCacheEntry *m_pceInstances;
  CCacheEntry *m_pceTextureSetsHeader;
  CCacheEntry *m_pceTextureSetsIndex;
  CCacheEntry *m_pceLevelsHeader;
  CCacheEntry *m_pceLevelsIndex;
  CCacheEntry *m_pceLevelIndex;
  CCacheEntry *m_pceGridBounds;
  CCacheEntry *m_pceGridSectionsIndex;
  CCacheEntry *m_pcePersistantCounts;
  CCacheEntry *m_pceSkyTextureSet;
  CCacheEntry *m_pceWarpPoints;
  CCacheEntry *m_pceSoundEffects;
  CCacheEntry *m_pceLevelInfo;
  CCacheEntry *m_pceBinariesIndex;
  CCacheEntry *m_pceBinaryTypes;
  unsigned long m_ObjectTypesSize;
  unsigned long m_ObjectAttributesSize;
  unsigned long m_ParticleEffectsSize;
  unsigned long m_GridBoundsSize;
  unsigned long m_WarpPointsSize;
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
  int m_SkyTextureReady;
  int m_SkyHeightSet;
  int m_LevelInfoReceived;
  float m_SkyHeight;
  float m_RotYPickup;
  CQuatern m_qRotYPickup;
  int m_nLevel;
  int m_nWarpID;
  int m_WarpFound;
  CROMWarpPoint m_WarpPoint;
  float m_cSendStaticEventsFrame;
  unsigned long pad1;
  unsigned long pad2;
  unsigned long pad3;
  unsigned long m_bPlayerActiveFlags;
  CPickupMonitor m_PickupMonitor;
} CScene;
typedef struct COverlay_t
{
  int m_OnScreen;
  signed long *m_pScript;
  signed long m_Mode;
  signed long m_Time;
  float m_X;
  float m_Y;
  float m_FinalX;
  float m_FinalY;
  float m_XVel;
  float m_YVel;
  float m_XAccel;
  float m_YAccel;
  float m_ZoomFactor;
} COverlay;
typedef struct COnScreen_t
{
  signed short m_SelectionTimer;
  int m_ExplosiveAmmo;
  int m_BarrelDirection;
  int m_AirMode;
  float m_AirOpacity;
  int m_BossBarMode;
  float m_BossBarOpacity;
  float m_FlashTimer;
  char m_FlashDraw;
  int m_TopR;
  int m_TopG;
  int m_TopB;
  int m_BottomR;
  int m_BottomG;
  int m_BottomB;
  float m_FontXScale;
  float m_FontYScale;
  int m_ShadowXOff;
  int m_ShadowYOff;
  int m_HealthAlert;
  int m_ArmorAlert;
  signed long m_Ammo;
  signed long m_Health;
  signed long m_Armor;
  signed long m_HealthArmourIcon;
  signed long m_Lives;
  signed long m_Tokens;
  signed long m_WalkRunIcon;
  float m_CompassPos;
  float m_CompassAccel;
  COverlay m_AmmoOverlay;
  COverlay m_HealthOverlay;
  COverlay m_LivesOverlay;
  COverlay m_TokensOverlay;
  COverlay m_WeaponOverlay;
  COverlay m_RunWalkOverlay;
  struct CBoss_t *m_pBoss;
  sa_u8 m_SelectPosition;
} COnScreen;
typedef struct CRequestor_t
{
  float m_Alpha;
  signed short m_Mode;
  int b_Active;
  signed long m_Selection;
  char **Selections;
  char *Line1;
  char *Line2;
} CRequestor;
typedef struct CMessageBox_t
{
  float m_Alpha;
  signed short m_Mode;
  int b_Active;
  signed long m_Selection;
  char *Line1;
  char *Line2;
} CMessageBox;
typedef struct CLoad_t
{
  float m_Alpha;
  signed short m_Mode;
  int b_Active;
  signed short m_LoadType;
  sa_s32 m_Side;
  signed long m_ASelection;
  signed long m_BSelection;
  signed long m_FirstVisible;
  signed long m_MaxVisible;
  signed long m_Selection;
  signed long m_SubSelection;
  signed long m_EntryPos;
} CLoad;
typedef struct CSave_t
{
  float m_Alpha;
  signed short m_Mode;
  int b_Active;
  signed short m_SaveType;
  sa_s32 m_Side;
  signed long m_ASelection;
  signed long m_BSelection;
  signed long m_FirstVisible;
  signed long m_MaxVisible;
  int m_ShowAll;
  signed long m_Selection;
} CSave;
typedef struct CGamePak_t
{
  float m_Alpha;
  signed short m_Mode;
  int b_Active;
  signed long m_Selection;
  signed long m_Timer;
} CGamePak;
typedef struct CCheatCode_t
{
  float m_Alpha;
  signed short m_Mode;
  int b_Active;
  signed long m_Selection;
  signed long m_SubSelection;
  signed long m_EntryPos;
} CCheatCode;
typedef struct CGiveCheatCode_t
{
  float m_Alpha;
  signed short m_Mode;
  int b_Active;
  int *m_Codes;
  signed long m_Selection;
} CGiveCheatCode;
typedef struct COption_t
{
  signed long m_Mode;
  float m_Alpha;
  int b_Active;
  int m_RHControl;
  int m_Blood;
  signed long m_Selection;
  signed long m_MusicVolume;
  signed long m_SFXVolume;
  signed long m_Opacity;
  signed long m_HAnalog;
  signed long m_VAnalog;
  int m_OptionsStored;
  signed long m_Storage_CheatFlags;
  int m_Storage_RHControl;
  int m_Storage_Blood;
  signed long m_Storage_Opacity;
  signed long m_Storage_HAnalog;
  signed long m_Storage_VAnalog;
  signed long m_Storage_Difficulty;
} COptions;
typedef struct CKeys_t
{
  signed long m_Mode;
  float m_Alpha;
  int b_Active;
} CKeys;
typedef struct CCheat_t
{
  signed long m_Mode;
  float m_Alpha;
  int b_Active;
  signed long m_Selection;
  int m_RealSelection;
} CCheat;
typedef struct CGInst_t
{
  signed long m_Mode;
  float m_Alpha;
  int b_Active;
  signed long m_Selection;
} CGInst;
typedef struct CPause_t
{
  signed long m_Mode;
  float m_Alpha;
  signed long m_Selection;
  int m_RealSelection;
} CPause;
typedef struct CBossVars_t
{
  signed long m_SwitchesOn;
  unsigned long m_SwitchFlags;
  float m_TurokSpeed;
  CGameRegion *m_pRegionList[4];
  float m_StartBossTimer;
  CGameObjectInstance *m_pMantisInstance;
  CVector3 m_vTurokLastPos;
  CVector3 m_vTurokDir;
} CBossVars;
typedef struct t_RGB
{
  float Red;
  float Green;
  float Blue;
  float Alpha;
} CRGB;
typedef struct t_PsuedoColor
{
  CRGB m_WhiteColor;
  CRGB m_BlackColor;
} CPsuedoColor;
typedef struct CShield_t
{
  signed short m_Health;
  signed short m_StartHealth;
  signed short m_Mode;
  signed short m_TotalColors;
  CPsuedoColor *m_pColors;
  float m_Alpha;
  float m_Time;
  CParticle *m_pParticle;
  CPsuedoColor *m_pColor;
  CGameObjectInstance *m_pOwner;
  signed long m_SoundHandle;
} CShield;
typedef struct CBoss_t
{
  int m_Alive;
  int m_Initialized;
  signed long m_ObjectType;
  signed long m_StartHealth;
  signed long m_LastHealth;
  signed long m_LastPercentageHealth;
  signed long m_PercentageHealth;
  signed long m_EventFlags;
  signed long m_Mode;
  signed long m_OldMode;
  signed long m_LastMode;
  float m_ModeTime;
  signed long m_OldModeFlags;
  signed long m_ModeFlags;
  float m_MoveTime;
  signed long m_AnimPlayed;
  signed long m_AnimEndFrame;
  int m_AnimPastEnd;
  signed long m_AnimRepeats;
  signed long m_Stage;
  CCollisionInfo2 m_CollisionInfo;
  float m_AnimSpeed;
  float m_ModeAnimSpeed;
  float m_PlaybackAnimSpeed;
  float m_Speed;
  float m_RotX;
  float m_RotZ;
  CVector3 m_LastPos;
  CVector3 m_LastVel;
  CVector3 m_LastDir;
  signed short m_Action;
  signed short m_ActionStage;
  float m_ActionTime;
  float m_LookDeltaAngle;
  float m_DeltaAngle;
  CVector3 m_vTarget;
  float m_DistFromTarget;
  float m_DistFromTargetSqr;
  float m_Rot1;
  float m_Rot2;
  float m_Rot3;
  float m_Rot4;
  float m_Rot5;
  float m_DistFromTurok;
  float m_TurokAngle;
  float m_TurokAngleDiff;
  float m_TurokAngleDist;
  float m_AtTargetDist;
  float m_TurokDeltaAngle;
  float m_LastTurokDeltaAngle;
  float m_AbsTurokDeltaAngle;
  CShield *m_pShield;
  void (*m_pInitializeFunction)(void *pThis, void *pBoss);
  void (*m_pUpdateFunction)(void *pThis, void *pBoss);
  void (*m_pHitByParticleFunction)(void *pThis, void *pBoss, void *pParticle);
  struct CBossModeInfo_t *m_pModeTable;
  void (*m_pPreDrawFunction)(void *pThis, void *pBoss, Gfx **ppDLP);
  void (*m_pPostDrawFunction)(void *pThis, void *pBoss, Gfx **ppDLP);
  void (*m_pPauseFunction)(void *pThis, void *pBoss);
  void (*m_pRestoreFunction)(void *pThis, void *pBoss);
} CBoss;
typedef struct CBossModeInfo_t
{
  void (*m_pSetupFunction)(CGameObjectInstance *pThis, CBoss *pBoss);
  void (*m_pUpdateFunction)(CGameObjectInstance *pThis, CBoss *pBoss);
  signed long m_Anim;
  float m_AnimSpeed;
  signed long m_Flags;
} CBossModeInfo;
typedef struct CBossEvent_t
{
  CInstanceHdr *m_pInst;
  CVector3 m_vPos;
  int m_nType;
  float m_Value;
} CBossEvent;
typedef struct CBossPickup_t
{
  int m_nType;
  CVector3 m_vPos;
} CBossPickup;
typedef struct CBossData_t
{
  CGameObjectInstance *m_pObject;
  CBoss *m_pBossVars;
  void (*m_pCollisionFunction)(CGameObjectInstance *pThis, CCollisionInfo2 *pCollisionInfo);
  CVector3 m_vPos;
  float m_RotY;
  int m_IsGone;
  signed long m_Anim;
  signed long m_CurrentAnimFrame;
  unsigned long m_BossDataSize;
  unsigned char m_BossData[800];
  CAIDynamic m_AIDynamicData;
  signed short m_Mode;
  float m_ModeTime;
  float m_ModeMisc1;
} CBossData;
typedef struct CBossesStatus_t
{
  CGameObjectInstance *m_pBossActive;
  CBossData m_BossData[3];
  CBossEvent m_EventData[20];
  signed long m_CurrentEvent;
  int m_PickupMonitorActive;
  CBossPickup m_PickupData[20];
  signed long m_CurrentPickup;
} CBossesStatus;
typedef struct CNode_t
{
  struct CNode_t *m_pPrev;
  struct CNode_t *m_pNext;
} CNode;
typedef struct CList_t
{
  CNode *m_pHead;
  CNode *m_pTail;
  signed long m_Length;
} CList;
typedef struct CDynamicList_t
{
  CList m_FreeList;
  CList m_ActiveList;
} CDynamicList;
typedef struct CSwooshVertex_t
{
  CVector3 m_vPos;
  CRGB m_Color;
  float m_Alpha;
} CSwooshVertex;
typedef struct CSwooshEdgeVertexInfo_t
{
  CSwooshVertex m_Start;
  CSwooshVertex m_End;
} CSwooshEdgeVertexInfo;
typedef struct CSwooshInfo_t
{
  float m_LifeTime;
  float m_FadeOutTime;
  float m_EdgeLifeTime;
  signed short m_Node;
  float m_Scale;
  signed short m_Flags;
  signed short m_NoOfEdgeVertices;
  CSwooshEdgeVertexInfo *m_pEdgeVertexList;
} CSwooshInfo;
typedef struct CSwooshEdge_t
{
  CNode m_Node;
  float m_LifeTime;
  float m_TotalLifeTime;
  Mtx m_mMatrix;
} CSwooshEdge;
typedef struct CSwoosh_t
{
  CNode m_Node;
  signed short m_Type;
  float m_LifeTime;
  CSwooshInfo *m_pInfo;
  CGameObjectInstance *m_pObject;
  CParticle *m_pParticle;
  CList m_EdgeList;
} CSwoosh;
typedef struct CTimerFx_t
{
  CNode m_Node;
  float m_Time;
  float m_Spacing;
  signed long m_Count;
  CGameObjectInstance *m_pInst;
  void (*m_pFunction)(void *pThis);
} CTimerFx;
typedef struct CFxSystem_t
{
  Vtx m_VertexList[2][400];
  signed long m_VtxsFree;
  Vtx *m_pFreeVertex;
  CSwooshEdge m_SwooshEdgeVars[150];
  CList m_SwooshEdgeList;
  CSwoosh m_SwooshVars[32];
  CDynamicList m_SwooshList;
  CTimerFx m_TimerFxVars[3];
  CDynamicList m_TimerFxList;
} CFxSystem;
typedef struct 
{
  short type;
  char misc[30];
} OSScMsg;
typedef struct OSScTask_s
{
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
  float m_StartYRotOffset;
  float m_FinalYRotOffset;
  float m_StartRadius;
  float m_FinalRadius;
  float m_StartEyeYOffset;
  float m_FinalEyeYOffset;
  float m_StartFocusYOffset;
  float m_FinalFocusYOffset;
} CCameraTrackInfo;
typedef struct CCameraView_t
{
  float m_Time;
  CVector3 m_vEye;
  CVector3 m_vFocus;
  CVector3 m_vRotation;
  float m_YRotOffset;
  float m_Radius;
  float m_EyeYOffset;
  float m_FocusYOffset;
} CCameraView;
typedef struct CShake_t
{
  float m_Shake;
  float m_LastShake;
  float m_Amp;
  float m_Angle;
} CShake;
typedef struct CCamera_t
{
  float m_PixelXScale;
  float m_PixelYScale;
  signed short m_Mode;
  float m_Time;
  int m_CinemaMode;
  int m_CinemaFadingOut;
  int m_NextCinematicStage;
  int m_StartPressed;
  signed short m_Stage;
  float m_StageTime;
  sa_u16 m_PerspNorm;
  float m_LetterBoxScale;
  signed short m_LetterBoxTop;
  signed short m_LetterBoxBottom;
  float m_Fov;
  float m_AspectRatio;
  CCameraView m_View;
  float m_ViewBlend;
  CCameraView m_ViewA;
  CCameraView m_ViewB;
  CCameraView m_ViewC;
  CVector3 m_vPos;
  CVector3 m_vRotation;
  CGameObjectInstance *m_pObject;
  CCameraTrackInfo *m_pTrackInfo;
  CVector3 m_vPos1;
  CVector3 m_vPos2;
  float m_XScale;
  float m_YScale;
  float m_WaterWobbleXScale;
  float m_WaterWobbleYScale;
  float m_WaterWobbleXAngle;
  float m_WaterWobbleYAngle;
  float m_WaterWobbleXSpeed;
  float m_WaterWobbleYSpeed;
  CShake m_ShakeX;
  CShake m_ShakeY;
  CShake m_ShakeZ;
  CVector3 m_vTremor;
  signed long m_WarpMode;
  float m_WarpTime;
  CVector3 m_vWarpPos;
  float m_WarpXScale;
  float m_WarpYScale;
  float m_WarpSpin;
  signed long m_UserSoundHandles[8];
  signed long m_Flags;
} CCamera;
typedef struct CSunFrameData_t
{
  sa_u64 m_DepthData[2];
  int m_DepthPos;
  int m_Visible;
  int m_VisibleZ;
  int align;
} CSunFrameData;
typedef struct CTraining_t
{
  signed long m_Mode;
  float m_Alpha;
  sa_s32 m_ID;
} CTraining;
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
  OSScTask m_Task;
  OSScTask m_LineTask;
  GFXMsg m_Msg;
  void *m_pFrameBuffer;
  Gfx *m_pDisplayList;
  Gfx *m_pLineList;
  unsigned long m_DisplayListSize;
  unsigned long m_LineListSize;
  unsigned long m_nPredictFields;
  int m_DrawMap;
} CFrameData;
typedef struct CPersistantData_t
{
  int SemiAutomaticPistolFlag;
  int RiotShotgunFlag;
  int AutomaticShotgunFlag;
  int AssaultRifleFlag;
  int MachineGunFlag;
  int MiniGunFlag;
  int GrenadeLauncherFlag;
  int TechWeapon1Flag;
  int RocketFlag;
  int ShockwaveFlag;
  int TechWeapon2Flag;
  int ChronoSceptorFlag;
  int ArmorFlag;
  int BackPackFlag;
  int BulletPool;
  int ShotgunPool;
  int EnergyPool;
  int ExpTekBowAmmo;
  int ExpShotgunPool;
  int TekBowAmmo;
  int MiniGunAmmo;
  int GrenadeLauncherAmmo;
  int RocketAmmo;
  int TechWeapon2Ammo;
  int ChronoSceptorAmmo;
  int ArmorAmount;
  int WeaponUsing;
  int D_800ED8F0;
  int D_800ED92C;
  int D_800ED968;
  int D_800ED9A4;
  int D_800ED9E0;
  int D_800EDA1C;
  int D_800EDA4C;
  int Level2Access;
  int Level3Access;
  int Level4Access;
  int Level5Access;
  int Level6Access;
  int Level7Access;
  int Level8Access;
  int ChronoSceptorPieces;
  int Difficulty;
  int RunWalk;
  int ControlSide;
  int Blood;
  int Stereo;
  sa_u32 MusicVolume;
  sa_u32 SFXVolume;
  sa_u32 Opacity;
  sa_u32 HAnalog;
  sa_u32 VAnalog;
  sa_u32 CheatFlags;
  sa_u32 EnabledCheatFlags;
  int Health;
  int MaxHealth;
  int Tokens;
  int Lives;
  sa_u16 Checkpoint;
  float BestTrainTime;
  signed long BossFlags;
  sa_u32 Crash;
} CPersistantData;
typedef struct CEngineApp_t
{
  CFrameData m_FrameData[3];
  CFrameData *m_pCurrentFrameData;
  CPersistantData *m_pPersistant;
  CScene m_Scene;
  COnScreen m_OnScreen;
  CBossesStatus m_BossesStatus;
  signed long m_BossFlags;
  CGameObjectInstance *m_pBossActive;
  CBossVars m_BossVars;
  CCamera m_Camera;
  CFxSystem m_FxSystem;
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
  unsigned long m_Mode;
  unsigned long m_NextMode;
  unsigned long m_dwCheatFlags;
  unsigned long m_dwEnabledCheatFlags;
  int m_Level;
  int m_BossLevel;
  signed long m_hMusic;
  sa_u8 m_FadeFast;
  sa_u8 m_FadeStatus;
  sa_u8 unused1;
  sa_u8 unused2;
  unsigned char m_PortraitNameMode;
  float m_FadeAlpha;
  float m_RotY;
  float m_RotXOffset;
  float m_RotYOffset;
  float m_RotZOffset;
  float m_XPos;
  float m_YPos;
  float m_ZPos;
  float m_YPosOffset;
  float m_TranslateHorizontal;
  float m_TranslateVertical;
  CQuatern m_qGround;
  CQuatern m_qViewAlign;
  CQuatern m_qViewAlignNoZ;
  CMtxF m_mfViewOrient;
  CMtxF m_mfProjection;
  CVector3 m_vTCorners[5];
  Gfx *m_pDLP;
  void *m_pStaticSegment;
  int m_DebugMode;
  int m_DoIdle;
  int m_SloMo;
  int m_LegalBypass;
  int m_GamePakCheck;
  int m_FirstRun;
  int m_JustLoadedGame;
  int m_MapMode;
  int m_LegalTimer;
  float m_MapAlpha;
  sa_u16 m_MapStatus;
  float m_GameOverAlpha;
  float m_GameOverMode;
  float m_GameOverTime;
  float m_TitleAlpha;
  float m_LevelTime;
  float m_BestTrainTime;
  float m_ModeTime;
  int m_bTrainingMode;
  int m_bTraining;
  int m_TrainingType;
  CTraining m_Training;
  int m_Difficulty;
  int m_bGameOver;
  int m_bReset;
  int m_bPause;
  int m_bOptions;
  int m_bKeys;
  int m_bLoad;
  int m_bSave;
  int m_bRequestor;
  int m_bMessageBox;
  int m_bCheatCode;
  int m_bGiveCheatCode;
  int m_bCheat;
  int m_bGInst;
  int m_bGamePak;
  int m_bDebug;
  int m_UnderWater;
  sa_u8 m_Flash;
  sa_u8 m_FlashDec;
  sa_u8 m_Alpha;
  sa_u8 m_AlphaDec;
  unsigned long m_nCurrentRegionSet;
  float m_cRegionSetBlend;
  unsigned char m_FogColor[4];
  unsigned char m_LastFogColor[4];
  unsigned char m_FlashColor[4];
  float m_FarClip;
  float m_LastFarClip;
  float m_FieldOfView;
  float m_LastFieldOfView;
  float m_SkySpeed;
  float m_SkyElevation;
  float m_LastSkySpeed;
  float m_LastSkyElevation;
  unsigned long m_FogStart;
  unsigned long m_LastFogStart;
  int m_Warp;
  int m_WarpID;
  int m_CurrentWarpID;
  int m_WarpSound;
  int m_WarpBase;
  int m_PlayedSound;
  float m_uWarp;
  float m_WarpLength;
  unsigned char m_WarpColors[4];
  int m_Death;
  float m_uDeath;
  int m_ReturnWarpSaved;
  CROMWarpPoint m_ReturnWarp;
  signed long m_CinemaFlags;
  CROMWarpPoint m_CinemaWarp;
  int m_UseCinemaWarp;
  float m_PortraitZoom;
  float m_ActualPortraitZoom;
  float m_ActualPortraitRotXSpd;
  float m_ActualPortraitRotYSpd;
  float m_ActualPortraitRotZSpd;
  float m_PortraitRotXSpd;
  float m_PortraitRotYSpd;
  float m_PortraitRotZSpd;
  float m_PortraitAlpha;
  float m_PortraitTimer;
  CVector3 m_vPortrait;
  int m_Portrait;
  int m_PortraitName;
  CQuatern m_qPortraitOrientation;
  int m_PortraitExit;
  int m_LastSaveMapLevel;
  float m_MenuUpChangeCount;
  float m_MenuDownChangeCount;
  float m_MenuLeftChangeCount;
  float m_MenuRightChangeCount;
  float m_ActualMusicVolume;
  float m_ActualSFXVolume;
  float m_MusicVolume;
  float m_SFXVolume;
  int m_RecordMode;
  int m_AttractMode;
  unsigned char *m_pAttractData;
  signed long m_AttractCurrentBit;
  unsigned char m_AttractPadFrames;
  OSContPad m_AttractPad;
} CEngineApp;
extern sa_u64 dram_stack[];
extern CEngineApp D_800F9F10;
struct CCollisionInfo2_t;
extern void func_8003BCD0(CCamera *pThis);
enum CameraModes
{
  CAMERA_LEGALSCREEN_MODE,
  CAMERA_INTRO_ACCLAIM_LOGO_MODE,
  CAMERA_INTRO_IGGY_MODE,
  CAMERA_INTRO_TUROK_DRAWING_BOW_MODE,
  CAMERA_INTRO_ZOOM_TO_LOGO_MODE,
  CAMERA_GAME_INTRO_MODE,
  CAMERA_GAME_INTRO_KEY_MODE,
  CAMERA_TUROK_EYE_MODE,
  CAMERA_CINEMA_TUROK_DEATH_MODE,
  CAMERA_CINEMA_TUROK_FALL_DEATH_MODE,
  CAMERA_CINEMA_TUROK_WATER_DEATH_MODE,
  CAMERA_CINEMA_TUROK_RESURRECT_MODE,
  CAMERA_GALLERY_IDLE_MODE,
  CAMERA_CINEMA_LONGHUNTER_MODE,
  CAMERA_CINEMA_FIRST_HUMVEE_MODE,
  CAMERA_CINEMA_FINAL_HUMVEE_MODE,
  CAMERA_CINEMA_TUROK_KILL_MANTIS_MODE,
  CAMERA_CINEMA_MANTIS_KILL_TUROK_MODE,
  CAMERA_CINEMA_TUROK_KILL_TREX_MODE,
  CAMERA_CINEMA_TREX_KILL_TUROK_MODE,
  CAMERA_CINEMA_TUROK_KILL_LONGHUNTER_MODE,
  CAMERA_CINEMA_TUROK_KILL_CAMPAIGNER_MODE,
  CAMERA_CINEMA_CAMPAIGNER_KILL_TUROK_MODE,
  CAMERA_CINEMA_TUROK_PICKUP_KEY_MODE,
  CAMERA_CINEMA_END_SEQUENCE_MODE,
  CAMERA_CINEMA_END_SEQUENCE2_MODE,
  CAMERA_CINEMA_CREDIT_MODE,
  CAMERA_CINEMA_TUROK_VICTORY_MODE,
  CAMERA_END_MODE
};
void func_8003BCD0(CCamera *pThis);
void func_8003BCD0(CCamera *pThis)
{
  CGameObjectInstance *pTurok = (&D_800F9F10)->m_Scene.m_pPlayer;
  pThis->m_Mode = CAMERA_CINEMA_FINAL_HUMVEE_MODE;
  pThis->m_CinemaMode = 1;
  pThis->m_LetterBoxScale = D_800F1FE8;
  pThis->m_View.m_FocusYOffset = D_800F1FEC;
  pThis->m_View.m_vEye.x = pTurok->ah.ih.m_vPos.x;
  pThis->m_View.m_vEye.y = pTurok->ah.ih.m_vPos.y + D_800F1FF0;
  pThis->m_View.m_vEye.z = pTurok->ah.ih.m_vPos.z;
}
