#include "common.h"

extern const double D_800F2410;
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
extern float func_80013A24(CVector3 *pThis);
typedef struct CQuatern_t
{
  float x;
  float y;
  float z;
  float t;
} CQuatern;
extern void func_80013588(float *pTheta);
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
typedef struct CFlinchInfo_t
{
  float RotYOffset;
  float HeadHeight;
  float ShoulderHeight;
  float StomachHeight;
  signed long HeadMode;
  signed long BackMode;
  signed long StomachMode;
  signed long KneeMode;
  signed long LeftShoulderMode;
  signed long RightShoulderMode;
} CFlinchInfo;
extern signed long func_800402A0(CGameObjectInstance *pThis, CBoss *pBoss, CFlinchInfo *pInfo, CParticle *pParticle);
extern float func_80040CB0(float Phi, float Theta);
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
struct CCollisionInfo2_t;
signed long func_800402A0(CGameObjectInstance *pThis, CBoss *pBoss, CFlinchInfo *pInfo, CParticle *pParticle);
float func_80040CB0(float Phi, float Theta);
signed long func_800402A0(CGameObjectInstance *pThis, CBoss *pBoss, CFlinchInfo *pInfo, CParticle *pParticle)
{
  float VelAngle;
  float Dist;
  float PosAngle;
  float Height;
  CVector3 vPos;
  VelAngle = func_80013A24(&pParticle->m_CI.vCollisionVelocity) + pInfo->RotYOffset;
  Dist = func_80040CB0(VelAngle, pThis->m_RotY);
  vPos = pThis->ah.ih.m_vPos;
  vPos.x -= pParticle->m_CI.vInstanceCollisionPos.x;
  vPos.y -= pParticle->m_CI.vInstanceCollisionPos.y;
  vPos.z -= pParticle->m_CI.vInstanceCollisionPos.z;
  PosAngle = (func_80013A24(&vPos) + pThis->m_RotY) + pInfo->RotYOffset;
  func_80013588(&PosAngle);
  Height = pParticle->m_CI.vInstanceCollisionPos.y - pThis->ah.ih.m_vPos.y;
  pBoss->m_OldMode = -1;
  if (Dist < D_800F2410)
  {
    if (Height > pInfo->HeadHeight)
      return pInfo->HeadMode;
    else
      if (Height > pInfo->StomachHeight)
      return pInfo->BackMode;
    else
      return pInfo->KneeMode;
  }
  else
  {
    if (Height > pInfo->HeadHeight)
      return pInfo->HeadMode;
    else
      if (Height > pInfo->ShoulderHeight)
    {
      if (PosAngle < 0)
        return pInfo->LeftShoulderMode;
      else
        return pInfo->RightShoulderMode;
    }
    else
      if (Height > pInfo->StomachHeight)
      return pInfo->StomachMode;
    else
      return pInfo->KneeMode;
  }
}
