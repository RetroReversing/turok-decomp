#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef int BOOL;typedef struct {float x,y,z;} CVector3;
typedef struct {u8 pad[16];float m_ProjectileRadius;u8 gap[20];float m_AttackRadius;u8 gap2[12];u32 m_dwTypeFlags;} EA;
typedef struct CGameObjectInstance_t {u8 head[4];CVector3 pos;u8 pad[8];EA*ea;u8 pad2[0x64-0x1c];float m_RotY;u8 pad3[0x130-0x68];u32 m_dwFlags;u8 pad4[0x1bc-0x134];float m_AvoidanceAngle;u8 pad5[0x1d0-0x1c0];u32 m_dwStatusFlags;u8 pad6[0x224-0x1d4];struct CGameObjectInstance_t*m_pAttackerCGameObjectInstance;} CGameObjectInstance;
typedef CGameObjectInstance CAnimInstanceHdr;
extern float D_800B6B00;
int func_800137A0(void);float func_8009E7A0(float);float __cosf(float);float __sinf(float);
void func_8001E080(CAnimInstanceHdr*,float,float);float func_800747C0(CGameObjectInstance*,CVector3,CGameObjectInstance*,float);
void func_80013588(float*);int func_800719B4(CGameObjectInstance*);void func_8007170C(CGameObjectInstance*);
int func_8001C348(CGameObjectInstance*,int,int*,int*,int*);void func_8005FCA0(CGameObjectInstance*,int,int);
#define CGameObjectInstance__GetRandomAnimIndex func_8001C348
#define AI_SetDesiredAnimByIndex func_8005FCA0
#define frame_increment D_800B6B00
#define AI_GetEA(p) ((p)->ea)
#define AI_GetDyn(p) (p)
#define AI_GetPos(p) ((p)->pos)
#define RANDOM(x) (func_800137A0()%(x))
#define sqrt func_8009E7A0
#define cosf __cosf
#define sinf __sinf
#define CAnimInstanceHdr__Teleport func_8001E080
#define AI_GetAvoidanceAngle func_800747C0
#define AI_GetWaterStatus func_800719B4
#define AI_CompletelyKillOff func_8007170C
#define CGameObjectInstance__SetGone(p) ((p)->m_dwFlags|=0x200000)
#define NormalizeRotation func_80013588
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
static __inline void AI_NudgeRotY(CGameObjectInstance *pAI, float Angle)
{
	pAI->m_RotY += Angle;
	NormalizeRotation(&pAI->m_RotY);
}















































void func_80072D08(CGameObjectInstance *pAI, float ang)
{
	int						picked;
	int						swimtype[]={AI_ANIM_SWIM, AI_ANIM_SWIM2};
	int						swimweight[]={4, 2};


	AI_GetDyn(pAI)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
	if (AI_GetDyn(pAI)->m_dwStatusFlags & AI_CYCLECOMPLETED)
	{
		// swimming
		picked = CGameObjectInstance__GetRandomAnimIndex(pAI, 2, swimtype, swimweight, NULL);
		AI_SetDesiredAnimByIndex(pAI, picked, FALSE);
	}

	// make ai turn
	if (ang<=ANGLE_DTOR(-AI_MAX_SWIMTURN)) ang=ANGLE_DTOR(-AI_MAX_SWIMTURN);
	if (ang>=ANGLE_DTOR(+AI_MAX_SWIMTURN)) ang=ANGLE_DTOR(+AI_MAX_SWIMTURN);
	AI_NudgeRotY(pAI, frame_increment*ang/AI_SWIMTURN_SMOOTHNESS);
}

