#include "context_e5d78c1e00f1.h"
#line 1 "func.c"
#line 1 "reference.c"
BOOL func_8007223C ( CGameObjectInstance *pAI, float ang )
{
	float	turnAng;
	BOOL	negative;
	int	curAnim,
			curAnimTest,
			waterFlag;

	s32		picked;

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

	int		swimtype[]={AI_ANIM_IDLE_SWIM};
	int		swimweight[]={2};

	//TRACE("ang:%f\r\n", ang*180.0/ANGLE_PI);

	waterFlag = func_800719B4(pAI);

	if (ang < 0)
	{
		register turnAng = -ang;
		negative = TRUE;
	}
	else
	{
		turnAng = ang;
		negative = FALSE;
	}

	switch(waterFlag)
	{
		case AI_BELOW_WATERSURFACE:
		case AI_ON_WATERSURFACE:
			AI_GetDyn(pAI)->m_dwStatusFlags &= ~AI_WAITFOR_CYCLE;
			if (ang<=ANGLE_DTOR(-AI_MAX_SWIMTURN)) ang=ANGLE_DTOR(-AI_MAX_SWIMTURN);
			if (ang>=ANGLE_DTOR(+AI_MAX_SWIMTURN)) ang=ANGLE_DTOR(+AI_MAX_SWIMTURN);
			func_80072110(pAI, D_800B6B00*ang/AI_TURN_SMOOTHNESS);

			if (turnAng < ANGLE_DTOR(4))
				return TRUE;

			break;

		default:
			if (turnAng > ANGLE_DTOR(135))
			{
				// 135 - 180
				if (AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
					picked = func_8001C348(pAI, 6, turn180type2, turn180weight, NULL);
				else
					picked = func_8001C348(pAI, 6, turn180type1, turn180weight, NULL);

				if (picked==-1)
				{
					func_80072110(pAI, D_800B6B00*ang/AI_RUNTURN_SMOOTHNESS);
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
					func_80072110(pAI, D_800B6B00*ang/AI_TURN_SMOOTHNESS);
				}
				else
				{
					func_8005FCA0(pAI, picked, FALSE);
					AI_GetDyn(pAI)->m_dwStatusFlags &= ~AI_WAITFOR_CYCLE;
				}
			}
			else
			{
				// 0 - 20
				curAnim = func_80071C8C(pAI);
				if (AI_GetEA(pAI)->m_dwTypeFlags2 & AI_TYPE2_USE2NDSETOFMOVES)
				{
					curAnimTest = func_800186FC(pAI, AI_ANIM_IDLE2);
					if (curAnim == curAnimTest)
						func_8005FCF4(pAI, AI_ANIM_IDLE2, FALSE);
				}
				else
				{
					curAnimTest = func_800186FC(pAI, AI_ANIM_IDLE);

					if (curAnim == curAnimTest)
						func_8005FCF4(pAI, AI_ANIM_IDLE, FALSE);
				}

				AI_GetDyn(pAI)->m_dwStatusFlags &= ~AI_WAITFOR_CYCLE;
				func_80072110(pAI, D_800B6B00*ang/AI_TURN_SMOOTHNESS);

				if (turnAng < ANGLE_DTOR(2))
				{
					// 0 - 2

					// pointing at desired direction
					// allow avoidance
				}
				return TRUE;
			}
			break;
	}

	// don't do avoidance yet
	return FALSE;
}

