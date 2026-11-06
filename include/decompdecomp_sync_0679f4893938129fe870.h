typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;

typedef int BOOL;typedef unsigned long DWORD;typedef unsigned short WORD;typedef unsigned char BYTE,UINT8;
typedef struct {float x,y,z;} CVector3;
typedef struct CGameRegion_t CGameRegion;typedef struct CEnemyAttributes_t CEnemyAttributes;
typedef struct CInstanceHdr_t {BYTE m_Type,m_bActiveFlags;WORD m_nObjType;CVector3 m_vPos;float m_CollisionHeightOffset;CGameRegion*m_pCurrentRegion;CEnemyAttributes*m_pEA;} CInstanceHdr;
typedef struct {CInstanceHdr ih;CVector3 m_vVelocity;} CAnimInstanceHdr;
typedef union {s64 align;u32 words[16];} Mtx;
typedef struct {void*m_pceTextureSet;int*m_rpTextureSet;DWORD m_TextureSetSize;} CTextureLoader;
#define PARTICLE_IMPACTS_AMT 14
typedef struct CROMParticleImpact_t
{
	float			m_ImpactEventNumber[PARTICLE_IMPACTS_AMT];
	WORD			m_ImpactParticleType[PARTICLE_IMPACTS_AMT],
					m_ImpactEventType[PARTICLE_IMPACTS_AMT],
					m_ImpactSoundType[PARTICLE_IMPACTS_AMT];
                                
                     
      
} CROMParticleImpact;
typedef struct CCollisionInfo2_t
{
	// input
	DWORD							dwFlags;
	int							InstanceBehavior,
									WallBehavior,
									GroundBehavior;
	float							GravityAcceleration,
									BounceReturnEnergy,
									GroundFriction,
									AirFriction,
									WaterFriction;

	// output
	struct CInstanceHdr_t	*pInstanceCollision;			// NULL if no collision
	struct CGameRegion_t		*pInstanceCollisionRegion;
	CVector3						vInstanceCollisionPos;

	struct CGameRegion_t		*pWallCollisionRegion;		// NULL if no collision
	CVector3						vWallCollisionPos;
	int							nWallCollisionEdge;

	int							nGroundCollisionType;		// GROUNDCOLLISION_NONE
	struct CGameRegion_t		*pGroundCollisionRegion;	//   if no collision
	CVector3						vGroundCollisionPos;

	struct CGameRegion_t		*pWaterCollisionRegion;		// NULL if no collision
	CVector3						vWaterCollisionPos;

	CVector3						vCollisionVelocity;			// velocity of last
																		//   collision
} CCollisionInfo2;
typedef struct {CROMParticleImpact*m_pImpact;DWORD m_dwFlags;} CROMParticleEffect;
typedef struct CParticle_t
{
	CAnimInstanceHdr		ah;

	Mtx						m_mOrientation[2];
	CROMParticleEffect	*m_pEffect;
	CTextureLoader			m_TextureLoader;
	CInstanceHdr			*m_pSource;
	DWORD						m_dwFlags;
	float						m_cFrame,
								m_cFramePos,
								m_FPS;
	int						m_nFrames,
								m_cAnimFrame,
								m_nRandomFrame;
	float						m_Size, m_SizeScaler,
								m_Rotation,
								m_RotationInc,
								m_DistanceSquared;
	UINT8						m_AlphaScaler ;
	UINT8						m_ActiveSwooshes ;
	CCollisionInfo2		m_CI;
	short						m_Alignment;
	BYTE						m_WhiteColor[3],
								m_BlackColor[3];

	struct CParticle_t	*m_pLast, *m_pNext,
								*m_pDrawLast, *m_pDrawNext;
} CParticle;
typedef struct CCacheEntry_t CCacheEntry;typedef struct CCartCache_t CCartCache;
#define PARTICLES_MAX_COUNT 128
typedef struct CParticleSystem_t
{
	CParticle	m_Particles[PARTICLES_MAX_COUNT],
					*m_pFreeHead,
					*m_pActiveHead, *m_pActiveTail,
					*m_pDrawHead, *m_pDrawTail;
	CCartCache	*m_pCache;
   CCacheEntry	*m_pceParticleEffects,
					*m_pceTextureSetsIndex;
} CParticleSystem;

extern int D_800B6AF4;
extern u8 D_80112E10[];
extern CParticle*D_8011A0D0;
extern CAnimInstanceHdr*D_8010201C;
void CParticle__CalculateOrientationMatrix(CParticle*,void*,void*);
void CFxSystem__CheckForAddingParticleSwooshEdge(void*,CParticle*,Mtx*);
void CFxSystem__StopSwooshesOnParticle(void*,CParticle*);
void CVector3__Subtract(CVector3*,CVector3*,CVector3*);
#define CParticle__CalculateOrientationMatrix CParticle__CalculateOrientationMatrix
#define CFxSystem__CheckForAddingParticleSwooshEdge CFxSystem__CheckForAddingParticleSwooshEdge
#define CFxSystem__StopSwooshesOnParticle CFxSystem__StopSwooshesOnParticle
#define CParticle__GetOrientationMatrix(p) ((p)->m_mOrientation[D_800B6AF4])
#define CVector3__Subtract CVector3__Subtract
#define CVector3__MagnitudeSquared(p) ((p)->x*(p)->x+(p)->y*(p)->y+(p)->z*(p)->z)
#define PARTICLE_ALLOCATED 1
#define PARTICLE_PERMANENT (1 << 3)
#define PARTICLE_BEHAVIOR_DRAWONBOTTOM (1 << 13)
#define NULL ((void*)0)
#define ASSERT(x)
struct CEnemyAttributes_t
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
};

typedef float CMtxF[4][4];
typedef union {struct {short ob[3];u16 flag;short tc[2];u8 cn[4];} v;u64 align;} Vtx;
extern Vtx D_80119F70[4];extern CMtxF D_8011A030;extern CEnemyAttributes D_8011A070;
void CEnemyAttributes__SetDefaults(CEnemyAttributes*);void CMtxF__RotateX(CMtxF,float);
#define CEnemyAttributes__SetDefaults CEnemyAttributes__SetDefaults
#define CMtxF__RotateX CMtxF__RotateX

#define p_particle_glare D_8011A0D0
#define particle_attributes D_8011A070
#define particle_vtxs D_80119F70
#define mf_particle_faceup D_8011A030
#define TRACE0(x)
#define AI_TYPE_COLLISION 1
#define AI_TYPE_TRACKGROUND 8
#define SCALING_FACTOR (2.0/3.0)
#define ANGLE_PI 3.14159265358979323846

#define I_PARTICLE 2























































































































































































































































































































































































































































































































































































































#define CParticle__Construct(pThis) { (pThis)->ah.ih.m_CollisionHeightOffset = 0; (pThis)->ah.ih.m_pEA = &particle_attributes; (pThis)->ah.ih.m_Type = I_PARTICLE; (pThis)->m_dwFlags = 0; }


