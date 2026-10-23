#include "common.h"

extern const double D_800F2E98;
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
typedef struct CQuatern_t
{
  float x;
  float y;
  float z;
  float t;
} CQuatern;
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
extern void func_8001E080(CAnimInstanceHdr *pThis, float X, float Z);
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
extern void func_80063AE8(CInstanceHdr *pThis, CVector3 vPos, float Value);
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
typedef struct CDamage_t
{
  signed short m_Health;
  signed char m_Node1;
  signed char m_Node2;
  unsigned long m_Flags;
} CDamage;
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
typedef struct CBossScript_t
{
  signed short *m_pStart;
  signed short *m_pCurrent;
} CBossScript;
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
typedef struct CSpeacialFx_t
{
  CGameObjectInstance *m_pInst;
  signed long m_Command;
  float m_Time;
  float *m_pScriptStart;
  float *m_pScript;
  float m_Trans;
  float m_StartTrans;
  float m_FinalTrans;
  float m_TransFadeTime;
  float m_Color;
  float m_StartColor;
  float m_FinalColor;
  float m_ColorFadeTime;
  CRGB m_EnvColor;
  CRGB m_StartEnvColor;
  CRGB m_FinalEnvColor;
} CSpecialFx;
extern void func_8004305C(CSpecialFx *pThis, float *pScript);
enum SOUND_TYPES
{
  SOUND_MENU_OPTION_SELECT = 0,
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
  SOUND_STONEBOULDER_THUD,
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
struct CCollisionInfo2_t;
enum CampaignerModes
{
  CAMPAIGNER_IN_HOLE_IDLE_MODE,
  CAMPAIGNER_IN_HOLE_ATTACK_MODE,
  CAMPAIGNER_TALK_MODE,
  CAMPAIGNER_RAGE_MODE,
  CAMPAIGNER_VICTORY_MODE,
  CAMPAIGNER_IDLE_MODE,
  CAMPAIGNER_TURN180_MODE,
  CAMPAIGNER_TURN_LEFT90_MODE,
  CAMPAIGNER_TURN_RIGHT90_MODE,
  CAMPAIGNER_WALK_MODE,
  CAMPAIGNER_WALK_TURN180_MODE,
  CAMPAIGNER_WALK_TURN_LEFT90_MODE,
  CAMPAIGNER_WALK_TURN_RIGHT90_MODE,
  CAMPAIGNER_LIMP_MODE,
  CAMPAIGNER_LIMP_TURN180_MODE,
  CAMPAIGNER_LIMP_TURN_LEFT90_MODE,
  CAMPAIGNER_LIMP_TURN_RIGHT90_MODE,
  CAMPAIGNER_RUN_MODE,
  CAMPAIGNER_RUN_TURN180_MODE,
  CAMPAIGNER_RUN_TURN_LEFT90_MODE,
  CAMPAIGNER_RUN_TURN_RIGHT90_MODE,
  CAMPAIGNER_RUN_WEAPON_OVERHEAD_SMASH_MODE,
  CAMPAIGNER_WEAPON_FOREARM_SLASH_MODE,
  CAMPAIGNER_WEAPON_BACKHAND_SLASH_MODE,
  CAMPAIGNER_WEAPON_OVERHEAD_SLASH_MODE,
  CAMPAIGNER_WEAPON_FOREARM_SLASH2_MODE,
  CAMPAIGNER_WEAPON_BACKHAND_SLASH2_MODE,
  CAMPAIGNER_WEAPON_OVERHEAD_SLASH2_MODE,
  CAMPAIGNER_ATTACK_BACKHAND_MODE,
  CAMPAIGNER_ATTACK_SWIPE_MODE,
  CAMPAIGNER_ATTACK_BLOW_MODE,
  CAMPAIGNER_MAGIC_ENERGY_BLAST_MODE,
  CAMPAIGNER_MAGIC_SUMMON_EXPLOSION_MODE,
  CAMPAIGNER_MAGIC_SUPER_BLAST_MODE,
  CAMPAIGNER_MAGIC_SCATTER_BLAST_MODE,
  CAMPAIGNER_TELEPORT_MODE,
  CAMPAIGNER_WEAPON_IDLE_MODE,
  CAMPAIGNER_WEAPON_TURN180_MODE,
  CAMPAIGNER_WEAPON_TURN_LEFT90_MODE,
  CAMPAIGNER_WEAPON_TURN_RIGHT90_MODE,
  CAMPAIGNER_WEAPON_LAUGH_MODE,
  CAMPAIGNER_WEAPON_ATTACK_MODE,
  CAMPAIGNER_EVADE_BACK_FLIP_MODE,
  CAMPAIGNER_EVADE_MEGA_JUMP_MODE,
  CAMPAIGNER_RIGHT_SHOULDER_FLINCH_MODE,
  CAMPAIGNER_LEFT_SHOULDER_FLINCH_MODE,
  CAMPAIGNER_CHEST_FLINCH_MODE,
  CAMPAIGNER_BACK_FLINCH_MODE,
  CAMPAIGNER_DAMAGE_SHORTING_OUT_MODE,
  CAMPAIGNER_KNEE_FALL_FLINCH_MODE,
  CAMPAIGNER_KNEE_GETUP_MODE,
  CAMPAIGNER_EXPLODE_FRONT_MODE,
  CAMPAIGNER_EXPLODE_BACK_MODE,
  CAMPAIGNER_EXPLODE_LEFT_MODE,
  CAMPAIGNER_EXPLODE_RIGHT_MODE,
  CAMPAIGNER_DEATH_MODE,
  CAMPAIGNER_KILL_TUROK_MODE,
  CAMPAIGNER_END_MODE
};
typedef struct CampaignerStageInfo_t
{
  signed long HealthLimit;
  float AnimSpeed;
  float RunAttackTime;
  signed short EvadePercentage;
  float EvadeSpacing;
  signed short FlinchPercentage;
  float FlinchSpacing;
  signed short ExplodeFlinchPercentage;
  float ExplodeFlinchSpacing;
  signed short ShortOutPercentage;
  float ShortOutSpacing;
  signed short BlockWeaponsPercentage;
} CCampaignerStageInfo;
typedef struct CCampaigner_t
{
  CBoss m_Boss;
  CCampaignerStageInfo *m_pStageInfo;
  CSpecialFx m_SpecialFx;
  signed short m_HoleNumber;
  CVector3 m_vTeleportDest;
  int m_Limp;
  int m_TeleportToHole;
  int m_Teleported;
  int m_StartedFx;
  float m_RunTime;
  float m_RunAttackTime;
  float m_ExplosionAngle;
  float m_EvadeTime;
  float m_FlinchTime;
  float m_ExplodeFlinchTime;
  float m_ShortOutTime;
  CShield m_Shield;
  signed long m_WeaponToTakeOff;
  CDamage *m_pDamage;
  float m_TauntTimer;
  float m_PlayingSoundTimer;
  signed long m_LastSound;
  CBossScript m_RunAttackScript;
} CCampaigner;
extern signed long func_8004DACC(CGameObjectInstance *pThis, signed long nNewMode);
extern signed long func_8004DACC(CGameObjectInstance *pThis, signed long nNewMode);
extern void func_8004E248(CGameObjectInstance *pThis, CCampaigner *pCampaigner);
extern void func_8004EB14(CGameObjectInstance *pThis, CCampaigner *pCampaigner);
extern float D_800BD948[];
extern float D_800BD988[];
signed long func_8004DACC(CGameObjectInstance *pThis, signed long nNewMode);
void func_8004E248(CGameObjectInstance *pThis, CCampaigner *pCampaigner);
void func_8004E924(CGameObjectInstance *pThis, CCampaigner *pCampaigner);
void func_8004EB14(CGameObjectInstance *pThis, CCampaigner *pCampaigner);
void func_8004EB14(CGameObjectInstance *pThis, CCampaigner *pCampaigner)
{
  if ((!pCampaigner->m_StartedFx) && (pThis->m_asCurrent.m_cFrame >= 12))
  {
    pCampaigner->m_StartedFx = 1;
    func_8004305C(&pCampaigner->m_SpecialFx, D_800BD948);
    func_80063AE8(&pThis->ah.ih, pThis->ah.ih.m_vPos, SOUND_CAMPAIGNERS_SPELL);
  }
  if ((!pCampaigner->m_Teleported) && (pThis->m_asCurrent.m_cFrame >= 25))
  {
    func_8004E924(pThis, pCampaigner);
    pCampaigner->m_Teleported = 1;
    if (pCampaigner->m_TeleportToHole)
      func_8004E248(pThis, pCampaigner);
    else
    {
      pThis->m_RotY = pCampaigner->m_vTeleportDest.y;
      pThis->ah.ih.m_vPos.y = 0;
      pCampaigner->m_Boss.m_CollisionInfo.GravityAcceleration = ((-12) * (1024.0 / 100.0)) * 15;
      func_8001E080((CAnimInstanceHdr *) pThis, pCampaigner->m_vTeleportDest.x, pCampaigner->m_vTeleportDest.z);
    }
    func_8004305C(&pCampaigner->m_SpecialFx, D_800BD988);
    func_80063AE8(&pThis->ah.ih, pThis->ah.ih.m_vPos, SOUND_CAMPAIGNERS_SPELL);
  }
  if (pThis->m_asCurrent.m_cFrame >= (pThis->m_asCurrent.m_nFrames - 5))
  {
    if (pCampaigner->m_TeleportToHole)
      func_8004DACC(pThis, CAMPAIGNER_IN_HOLE_ATTACK_MODE);
    else
      if (pCampaigner->m_Boss.m_DistFromTarget > D_800F2E98)
      func_8004DACC(pThis, CAMPAIGNER_IDLE_MODE);
    else
      func_8004DACC(pThis, CAMPAIGNER_WEAPON_BACKHAND_SLASH2_MODE);
  }
}
