typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL;typedef unsigned long DWORD;typedef unsigned short WORD,SF;typedef unsigned char BYTE;typedef unsigned long ROMAddress;
typedef struct {float x,y,z;} CVector3;typedef struct {float x,y,z,t;} CQuatern;typedef float CMtxF[4][4];
typedef union {u64 align;u32 words[16];} Mtx;
typedef struct {CVector3 m_vMin,m_vMax;} CROMBounds;
typedef struct CCacheEntry_t CCacheEntry;typedef struct CCartCache_t CCartCache;
typedef struct CGameRegion_t {u8 data[28];} CGameRegion;
typedef struct CEnemyAttributes_t
{
	float			m_SightRadius,				// sight radius (squared)
					m_SightAngle,				// sight angle (/2, only need half of it)
					m_LoudRadius,				// loud hearing radius (squared)
					m_QuietRadius,				// quiet hearing radius (squared)
					m_ProjectileRadius,		// projectile radius (squared)
					m_FlyingHeight,			// flying height (feet, not squared)
					m_CollisionRadius,		// collision instance radius (not squared)		-- don't convert to SF --
					m_CollisionWallRadius,	// collision wall radius (not squared)
					m_CollisionHeight,		// collision height
					m_DeadHeight,				// dead height
					m_AttackRadius,			// attack radius (squared)
					m_LeashRadius,				// leash radius (squared)
					m_InteractiveAnimDelay;	// delay (in secs) before interactive animation takes place
	DWORD			m_dwSpecies,				// species type (flags 2^x)
					m_dwTypeFlags,				// general purpos flags
					m_dwTypeFlags2;			// pickup typs (flags 2^x)
	WORD			m_wTypeFlags3;

	short			m_StartHealth,				// health count of ai (goes down as ai takes hits)
					m_Id,							// id no. for this ai
					m_DeathId,					// id no. for ai on death
					m_Regenerate;				// no. of regenerations for this ai

	BYTE			m_Aggression,				// aggression (%) / Time 2
					m_InteractiveAnim,		// special anim ai will play at start of life
					m_nModel;
	signed char	m_nTexture,
					m_AttackStyle;				// Time 1
	BYTE			unused1;
} CEnemyAttributes;
typedef struct {BYTE m_Type,m_bActiveFlags;WORD m_nObjType;CVector3 m_vPos;float m_CollisionHeightOffset;CGameRegion*m_pCurrentRegion;CEnemyAttributes*m_pEA;} CInstanceHdr;
typedef struct {CCacheEntry*m_pceGeometry;int state;} CGeometry;
typedef struct CROMStaticInstance_t
{
   CVector3       m_vPos,
						m_vScale;
	SF					m_BoundsMinX, m_BoundsMinY, m_BoundsMinZ,
						m_BoundsMaxX, m_BoundsMaxY, m_BoundsMaxZ;
	WORD				m_nObjType,
						m_nCurrentRegion,
						m_nVariation;
	BYTE				m_bFlags,
						m_bActiveFlags;
	signed char		m_RotX, m_RotY, m_RotZ, m_RotT;
} CROMStaticInstance;
typedef struct {CInstanceHdr ih;CCacheEntry*m_pceObjectIndex,*m_pceStaticEvents;ROMAddress*m_rpObjectIndexAddress;Mtx m_mOrientation;CGeometry m_Geometry;CROMBounds m_Bounds;DWORD m_dwFlags;} CGameStaticInstance;
void CMtxF__ToMtxFast(CMtxF,Mtx*);void func_800130DC(CMtxF,float,float,float);void func_8001315C(CMtxF,float,float,float);
void CQuatern__Normalize(CQuatern*);void CQuatern__ToMatrix(CQuatern*,CMtxF);
#define CQuatern__Normalize CQuatern__Normalize
#define CQuatern__ToMatrix CQuatern__ToMatrix
#define CMtxF__PreMultScale func_800130DC
#define CMtxF__PostMultTranslate func_8001315C
#define CMtxF__ToMtx(mf,m) CMtxF__ToMtxFast((mf),&(m))
#define USE_ORIGINAL_MATRIX 0
#define I_STATIC 0
#define ORDERBYTES(x) (x)
#define NULL ((void*)0)
#define FALSE 0
#define ASSERT(x)















































































typedef struct {CInstanceHdr ih;CVector3 m_vVelocity;} CAnimInstanceHdr;
typedef struct {s16 m_WeaponModel,m_ExtraModel;} CAIDynamicView;
typedef struct CGameObjectInstance_t {CAnimInstanceHdr ah;u8 pad28[0xF0-0x28];CGeometry m_Geometry;u8 padF8[0x21C-0xF8];CAIDynamicView m_AI;} CGameObjectInstance;
extern CGameObjectInstance*D_80112BD8;extern int D_800B6AF4;extern float D_800B6B00;
int func_80016468(CGameObjectInstance*,int);int CGameObjectInstance__GetTurokFeathersModelIndex(CGameObjectInstance*,int);int CGameObjectInstance__GetTurokCorpseModelIndex(CGameObjectInstance*,int);
int CGameObjectInstance__GetCrystalModelIndex(CGameObjectInstance*,int);int CGameObjectInstance__GetCampaignerModelIndex(CGameObjectInstance*,int);int CGameObjectInstance__GetLonghunterModelIndex(CGameObjectInstance*,int);
void CGeometry__MorphInc(CGeometry*,int,float);
#define CGameObjectInstance__GetTurokModelIndex func_80016468
#define CGameObjectInstance__GetTurokCorpseModelIndex CGameObjectInstance__GetTurokCorpseModelIndex
#define CGameObjectInstance__GetTurokFeathersModelIndex CGameObjectInstance__GetTurokFeathersModelIndex
#define CGameObjectInstance__GetCrystalModelIndex CGameObjectInstance__GetCrystalModelIndex
#define CGameObjectInstance__GetCampaignerModelIndex CGameObjectInstance__GetCampaignerModelIndex
#define CGameObjectInstance__GetLonghunterModelIndex CGameObjectInstance__GetLonghunterModelIndex
#define CGameObjectInstance__TypeFlag(p) (*(u16*)((BYTE*)(p)+0x11A))
#define AI_GetEA(p) ((p)->ah.ih.m_pEA)
#define AI_GetDyn(p) (&(p)->m_AI)
#define CGeometry__MorphInc CGeometry__MorphInc
#define even_odd D_800B6AF4
#define frame_increment D_800B6B00
#define FRAME_FPS 15
#define PORTAL_MORPH_FRAMES 10
#define PORTAL_IDLE_SPEED 6
#define RHAND 17
#define LLOWLEG 2
#define RLOWLEG 6
#define LSHOULDER 10
#define RSHOULDER 14
#define AI_TYPE3_DUMB 0x20
#define	AI_OBJECT_CHARACTER_PLAYER							0
#define	AI_OBJECT_CHARACTER_HUMAN1							2
#define	AI_OBJECT_CHARACTER_TREX_BOSS						1001
#define	AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS				1002
#define	AI_OBJECT_CHARACTER_LONGHUNTER_BOSS				1003
#define AI_OBJECT_DEVICE_ACTION					301
#define AI_OBJECT_DEVICE_TREXELEVATOR	 		313
#define AI_OBJECT_DEVICE_PORTAL					317
#define AI_OBJECT_DEVICE_CRYSTAL					323
#define AI_OBJECT_DEVICE_ANIMOFFSCREENACTION	331


