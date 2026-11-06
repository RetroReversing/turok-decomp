typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef struct {float x,y,z;} CVector3;
typedef struct {u8 m_Type;u8 flags;u16 m_nObjType;} CInstanceHdr;
typedef struct {struct {CInstanceHdr ih;} ah;} CGameObjectInstance;
typedef struct {u8 pad[0xb8];CInstanceHdr*m_pSource;} CParticle;
void AI_DoHit(CGameObjectInstance*,int);void AI_SetAttacker(CGameObjectInstance*,CInstanceHdr*);void AI_MEvent_WeaponImpact(CGameObjectInstance*,CInstanceHdr*,CVector3,float);
#define AI_DoHit AI_DoHit
#define AI_SetAttacker AI_SetAttacker
#define AI_MEvent_WeaponImpact AI_MEvent_WeaponImpact
#define I_ANIMATED 1
#define I_PARTICLE 2
#define TRACE0(x)
#define NULL ((void*)0)


