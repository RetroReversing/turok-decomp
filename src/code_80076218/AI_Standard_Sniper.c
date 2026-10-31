#include "source_AI_Standard_Sniper.h"
#line 1 "func.c"
#line 1 "reference.c"
void AI_Standard_Sniper(CGameObjectInstance *pMe, CGameObjectInstance *pDest)
{
	float		projectileang,
				dist;
//				turnang;
	int		random;
	CVector3	vDestPos;


#if DEBUG_STAND_AI
	rmonPrintf("AI_Standard_Sniper\r\n") ;
#endif


	// get projectile angle - is it worth firing ?
	vDestPos = AI_GetPos(pDest);
//	projectileang = AI_GetAngle(pMe, vDestPos);
	dist = func_8005F34C(pMe, vDestPos);
//	turnang = AI_GetAngle(pMe, vDestPos);
	random = RANDOM(99);

//	AI_GetDyn(pMe)->m_AvoidanceAngle = projectileang;
//	AI_PerformTurn(pMe, ANGLE_DTOR(60));
	projectileang = func_80071DA4(pMe, vDestPos);

	// ai is not within close attack range - does ai fire projectiles ?
	if (	  (func_80071770(pMe))
//		  && (fabs(projectileang) <= ANGLE_DTOR(7))		//5
		  && (dist <= AI_GetEA(pMe)->m_ProjectileRadius)
		  && (random < AI_GetEA(pMe)->m_Aggression) )
	{
		// make sniper less likely to fire at a greater distance
		dist = sqrt(dist) * 100 / max(1, sqrt(AI_GetEA(pMe)->m_ProjectileRadius));
		if (RANDOM(100) >= dist)
		{
			func_80076824(pMe, projectileang, FALSE);
//			AI_GetDyn(pMe)->m_dwStatusFlags |= AI_WAITFOR_CYCLE;
		}
		else
		{
			func_8005FCF4(pMe, AI_ANIM_IDLE, FALSE);
			AI_GetDyn(pMe)->m_dwStatusFlags &= ~AI_WAITFOR_CYCLE;
		}
	}
	else
	{
		func_8005FCF4(pMe, AI_ANIM_IDLE, FALSE);
		AI_GetDyn(pMe)->m_dwStatusFlags &= ~AI_WAITFOR_CYCLE;
	}
}

