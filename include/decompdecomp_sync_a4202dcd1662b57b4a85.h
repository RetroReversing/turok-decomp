typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL;typedef unsigned long DWORD;typedef unsigned short WORD;typedef unsigned char BYTE;
typedef struct {float x,y,z;} CVector3;typedef struct CGameRegion_t CGameRegion;
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
typedef struct CAIDynamic_t
{
	float			m_ViewAngleOffset,				// offset to direction angle to get view angle
					m_RetreatTimer,					// time that the ai will retreat for
					m_TeleportTime,					// max time for teleport slow move
					m_Time1,
					m_Time2,
					m_InteractiveTimer,
					m_AvoidanceAngle,					// Current avoidance angle
					m_cRegenerateAppearance,
					m_cRegenerateAppearanceWhite,
					m_MeltTimer,
					m_FreezeTimer;
	DWORD			m_dwStatusFlags,
					m_dwStatusFlags2;					// various bit flags
	short			m_Agitation,
					m_PrevAgitation,					// agitation level of ai
					m_Health,							// health count of ai (goes down as ai takes hits)
//					m_MaxHealth,  						// maximum health count of ai (upgradable with pickups)
					m_Evade,								// evade mode (ai collided with something & they are trying to get around it)
					m_Regenerate;						// no. of times this ai will regenerate
	CVector3		m_vExplosion,						// explosion vector
					m_vLeashCoor,						// leash coordinates
					m_vStartPos;
	BOOL			m_Invincible,						// ai can't loose any health at the moment
					m_FirstRun;							// ai in first run mode
	int			m_DeathAnimType;					// last death animation type
	struct CGameRegion_t	*m_pStartRegion;
	short			m_HeadTexture,						// which texture to use for head
					m_BodyTexture ;					// which texture to use on body
	short			m_WeaponModel,						// which weapon model to use
					m_ExtraModel ;						// shins or shoulders for footsoldier

} CAIDynamic;
typedef struct {BYTE m_Type,m_bActiveFlags;WORD m_nObjType;CVector3 m_vPos;float m_CollisionHeightOffset;CGameRegion*m_pCurrentRegion;CEnemyAttributes*m_pEA;} CInstanceHdr;
typedef struct {CInstanceHdr ih;CVector3 m_vVelocity;} CAnimInstanceHdr;
typedef struct CGameObjectInstance_t {CAnimInstanceHdr ah;u8 pad28[0x64-0x28];float m_RotY,m_cMelt;u8 pad6C[0x11A-0x6C];WORD m_nTypeFlag;u8 pad11C[0x130-0x11C];DWORD m_dwFlags;u8 pad134[0x1A4-0x134];CAIDynamic m_AI;} CGameObjectInstance;
extern CGameObjectInstance*D_8010201C;extern float D_801197E8;
float AI_DistanceSquared(CGameObjectInstance*,CVector3);void CAIDynamic__SetHealth(CAIDynamic*,CEnemyAttributes*,int);
#define AI_DistanceSquared AI_DistanceSquared
#define CAIDynamic__SetHealth CAIDynamic__SetHealth
#define AI_GetDyn(p) (&(p)->m_AI)
#define AI_GetEA(p) ((p)->ah.ih.m_pEA)
#define AI_GetPos(p) ((p)->ah.ih.m_vPos)
#define CGameObjectInstance__IsVisible(p) ((p)->m_dwFlags & (1<<16))
#define CGameObjectInstance__TypeFlag(p) ((p)->m_nTypeFlag)
#define SCALING_FACTOR (1024.0/100.0)
#define	AI_WAITFOR_CYCLE					(1<<4)				// wait for cycle completed
#define	AI_ALREADY_DEAD					(1<<12)				// ai is already dead flag (death animation has been played)
#define	AI_RESURRECTION					(1<<16)				// ai is to be randomly resurrected when turok is not close
#define	AI_FEIGNDEATH						(1<<17)				// ai is to be going to fake death & resurrect when turok gets close
#define	AI_WOUNDEDMORTALLY				(1<<30)				// this ai has been wounded mortally
#define	AI_GENERATED_PICKUPS				(1<<3)


