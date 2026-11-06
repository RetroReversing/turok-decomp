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


