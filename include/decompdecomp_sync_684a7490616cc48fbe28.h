typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef struct {float x,y,z;} CVector3;
typedef struct {u8 m_Type;u8 flags;u16 m_nObjType;} CInstanceHdr;
typedef struct {struct {CInstanceHdr ih;} ah;} CGameObjectInstance;
typedef struct {u8 pad[0xb8];CInstanceHdr*m_pSource;} CParticle;
void func_80060A54(CGameObjectInstance*,int);void func_8005F228(CGameObjectInstance*,CInstanceHdr*);void func_800619EC(CGameObjectInstance*,CInstanceHdr*,CVector3,float);
#define AI_DoHit func_80060A54
#define AI_SetAttacker func_8005F228
#define AI_MEvent_WeaponImpact func_800619EC
#define I_ANIMATED 1
#define I_PARTICLE 2
#define TRACE0(x)
#define NULL ((void*)0)


