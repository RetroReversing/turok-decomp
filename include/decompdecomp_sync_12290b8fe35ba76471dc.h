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
void func_80012290(CMtxF,Mtx*);void func_800130DC(CMtxF,float,float,float);void func_8001315C(CMtxF,float,float,float);
void func_80014538(CQuatern*);void func_80014DC4(CQuatern*,CMtxF);
#define CQuatern__Normalize func_80014538
#define CQuatern__ToMatrix func_80014DC4
#define CMtxF__PreMultScale func_800130DC
#define CMtxF__PostMultTranslate func_8001315C
#define CMtxF__ToMtx(mf,m) func_80012290((mf),&(m))
#define USE_ORIGINAL_MATRIX 0
#define I_STATIC 0
#define ORDERBYTES(x) (x)
#define NULL ((void*)0)
#define FALSE 0
#define ASSERT(x)















































































typedef union {struct {u32 w0,w1;} words;u64 align;} Gfx;
typedef struct {void*m_pData;BOOL m_AutoDeleteData;} CIndexedSet;
extern s16 D_80112C20;extern u8 D_800F0D84;typedef struct DrawAppView_t DrawAppView;extern DrawAppView D_80109F10;
void CIndexedSet__ConstructFromRawData(CIndexedSet*,void*,BOOL);void*CCacheEntry__GetData(CCacheEntry*);
ROMAddress*func_8002DBF8(CIndexedSet*,ROMAddress*,int,DWORD*);void*func_8002DC68(CIndexedSet*,void*,int);
void func_8002D1F8(CCartCache*,void*,void*,void*,CCacheEntry**,ROMAddress*,DWORD,void*);
void func_800237C0(CGeometry*,CCartCache*,ROMAddress*,DWORD,CCacheEntry*);
void CGeometry__DrawPart(CGeometry*,Gfx**,CCartCache*,int,int,BOOL,BOOL,int);
#define CIndexedSet__GetROMAddressAndSize func_8002DBF8
#define CIndexedSet__GetBlock(p,n) func_8002DC68((p),(p)->m_pData,(n))
#define CCartCache__RequestBlock func_8002D1F8
#define CGeometry__RequestBlock func_800237C0
#define CGeometry__GetCacheEntry(p) ((p)->m_pceGeometry)
#define CIndexedSet__Destruct(p)
#define CAMERA_CINEMA_TUROK_PICKUP_KEY_MODE 23
#define AI_TYPE3_DONTDRAWONCINEMA 0x800
#define CART_GRAPHOBJ_nItems 4
#define IS_INDEX_SIZE(n) 24
#define CART_GRAPHOBJ_isGeometry 1
#define CART_GEOMETRY_isNodes 1
#define STATIC_INSTANCE_GEOMVER_MASK 3
#define CACHE_BLOCK_VERSION(v) ((v)<<30)
#define RSP_ADDRESS(p) (p)
#define G_MTX_MODELVIEW 0
#define G_MTX_LOAD 2
#define G_MTX_NOPUSH 0
#define gSPMatrix(pkt,mp,params) {Gfx*_g=(pkt);_g->words.w0=0x01020040;_g->words.w1=(u32)(mp);}
#define MODE_INTRO 2
#define MODE_TITLE 3
#define MODE_LEGALSCREEN 1

struct DrawAppView_t {u8 prefix[0xF6D4];int m_Mode;u8 gap[0xF888-0xF6D8];int m_bPause;};
#define DrawApp() (&D_80109F10)


