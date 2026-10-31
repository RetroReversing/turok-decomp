#include "context_c1dcaaa54495.h"
#line 1 "func.c"
#line 1 "reference.c"
void func_800727E0(CGameObjectInstance *pAI)
{
	float		projectileang;
//				dist;
	CVector3	vDestPos;

#ifdef ALLOW_SNIPER_TURNING
	float		turnAng;
	BOOL		negative;
//	int		curAnim,
//				curAnimTest;

	int		picked;

	int		turn180type1[]={AI_ANIM_RTURN180, AI_ANIM_RTURNR90,
									 AI_ANIM_WTURN180, AI_ANIM_WTURNR90,
									 AI_ANIM_TURN180,  AI_ANIM_TURNR90 };

	int		turn180type2[]={AI_ANIM_RTURN1802, AI_ANIM_RTURNR902,
									 AI_ANIM_WTURN1802, AI_ANIM_WTURNR902,
									 AI_ANIM_TURN1802,  AI_ANIM_TURNR902 };

	int		turn180weight[]={100,     1,
									  10,      1,
									  1000000, 10000 };

	int		turnl90type1[]={AI_ANIM_RTURNL90,
									 AI_ANIM_WTURNL90,
									 AI_ANIM_TURNL90   };

	int		turnl90type2[]={AI_ANIM_RTURNL902,
									 AI_ANIM_WTURNL902,
									 AI_ANIM_TURNL902   };

	int		turnl90weight[]={1, 10000, 1000000};

	int		turnr90type1[]={AI_ANIM_RTURNR90,
									 AI_ANIM_WTURNR90,
									 AI_ANIM_TURNR90   };

	int		turnr90type2[]={AI_ANIM_RTURNR902,
									 AI_ANIM_WTURNR902,
									 AI_ANIM_TURNR902   };

	int		turnr90weight[]={1, 10000, 1000000};
#endif


	// only assist sniper if he is alive
	if (AI_GetDyn(pAI)->m_Health <= 0)
		return;

	// get projectile angle
	vDestPos = AI_GetPos(pAI->m_pAttackerCGameObjectInstance);
//	dist = AI_DistanceSquared(pAI, vDestPos);
	projectileang = func_80071DA4(pAI, vDestPos);

#ifdef ALLOW_SNIPER_TURNING
	if (projectileang < 0)
	{
		turnAng = -projectileang;
		negative = TRUE;
	}
	else
	{
		turnAng = projectileang;
		negative = FALSE;
	}

	if (turnAng > ANGLE_DTOR(135))
	{
		// 135 - 180
		if (AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
			picked = func_8001C348(pAI, 6, turn180type2, turn180weight, NULL);
		else
			picked = func_8001C348(pAI, 6, turn180type1, turn180weight, NULL);

		if (picked==-1)
		{
			func_80072110(pAI, D_800B6B00*projectileang/AI_RUNTURN_SMOOTHNESS);
			AI_GetDyn(pAI)->m_dwStatusFlags &= (~AI_WAITFOR_CYCLE);
		}
		else
		{
			func_8005FCA0(pAI, picked, FALSE);
			AI_GetDyn(pAI)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
		}
	}
	else if (turnAng > ANGLE_DTOR(20))
	{
		// 20 - 135		(note: threshold at 20 prevents oscillating)
		if (AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
			picked = func_8001C348(pAI, 6, negative ? turnl90type2 : turnr90type2, negative ? turnl90weight : turnr90weight, NULL);
		else
			picked = func_8001C348(pAI, 6, negative ? turnl90type1 : turnr90type1, negative ? turnl90weight : turnr90weight, NULL);

		if (picked==-1)
		{
			func_80072110(pAI, D_800B6B00*projectileang/AI_TURN_SMOOTHNESS);
		}
		else
		{
			func_8005FCA0(pAI, picked, FALSE);
			AI_GetDyn(pAI)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
		}
	}
	else
	{
		// 0 - 20
		func_80072110(pAI, D_800B6B00*projectileang/AI_TURN_SMOOTHNESS);
	}
#else
		func_80072110(pAI, D_800B6B00*projectileang/AI_TURN_SMOOTHNESS);
#endif
}

