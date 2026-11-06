typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL;typedef struct {float x,y,z;} CVector3;
typedef struct {u8 pad[16];float m_ProjectileRadius;u8 gap[20];float m_AttackRadius;u8 gap2[12];u32 m_dwTypeFlags;} EA;
typedef struct CGameObjectInstance_t {u8 head[4];CVector3 pos;u8 pad[8];EA*ea;u8 pad2[0x64-0x1c];float m_RotY;u8 pad3[0x130-0x68];u32 m_dwFlags;u8 pad4[0x1bc-0x134];float m_AvoidanceAngle;u8 pad5[0x1d0-0x1c0];u32 m_dwStatusFlags;u8 pad6[0x224-0x1d4];struct CGameObjectInstance_t*m_pAttackerCGameObjectInstance;} CGameObjectInstance;
typedef CGameObjectInstance CAnimInstanceHdr;
extern float D_800B6B00;
int RandomSwapWord(void);float sqrtf(float);float __cosf(float);float __sinf(float);
void CAnimInstanceHdr__Teleport(CAnimInstanceHdr*,float,float);float AI_GetAvoidanceAngle(CGameObjectInstance*,CVector3,CGameObjectInstance*,float);
void NormalizeRotation(float*);int AI_GetWaterStatus(CGameObjectInstance*);void AI_CompletelyKillOff(CGameObjectInstance*);
int CGameObjectInstance__GetRandomAnimIndex(CGameObjectInstance*,int,int*,int*,int*);void AI_SetDesiredAnimByIndex(CGameObjectInstance*,int,int);
#define CGameObjectInstance__GetRandomAnimIndex CGameObjectInstance__GetRandomAnimIndex
#define AI_SetDesiredAnimByIndex AI_SetDesiredAnimByIndex
#define frame_increment D_800B6B00
#define AI_GetEA(p) ((p)->ea)
#define AI_GetDyn(p) (p)
#define AI_GetPos(p) ((p)->pos)
#define RANDOM(x) (RandomSwapWord()%(x))
#define sqrt sqrtf
#define cosf __cosf
#define sinf __sinf
#define CAnimInstanceHdr__Teleport CAnimInstanceHdr__Teleport
#define AI_GetAvoidanceAngle AI_GetAvoidanceAngle
#define AI_GetWaterStatus AI_GetWaterStatus
#define AI_CompletelyKillOff AI_CompletelyKillOff
#define CGameObjectInstance__SetGone(p) ((p)->m_dwFlags|=0x200000)
#define NormalizeRotation NormalizeRotation
#define ANGLE_PI 3.14159265358979323846
#define ANGLE_DTOR(deg) ((deg)*(ANGLE_PI/180))
#define AVOIDANCE_RADIUS_DISTANCE_FACTOR 1.5
#define AI_TYPE_AVOIDWATER (1<<23)
#define AI_NOT_NEAR_WATER 0
#define FALSE 0
#define TRUE 1
#define NULL ((void*)0)
#define AI_ANIM_SWIM									2500
#define AI_ANIM_SWIMRETREAT						2505
#define AI_ANIM_SWIM2								2510
#define AI_SWIMTURN_SMOOTHNESS		12
#define	AI_CYCLECOMPLETED					(1<<3)				// current animation cycle has finished
#define	AI_WAITFOR_CYCLE					(1<<4)				// wait for cycle completed
#define	AI_MAX_SWIMTURN			50.0				// max turn angle when ai is swimming
#line 8292 "reference.c"
static __inline void AI_NudgeRotY(CGameObjectInstance *pAI, float Angle)
{
	pAI->m_RotY += Angle;
	NormalizeRotation(&pAI->m_RotY);
}


typedef struct {int values[1];} SwimArray;
extern SwimArray D_800BE418,D_800BE41C;
















































