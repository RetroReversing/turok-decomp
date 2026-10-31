#include "common_local_source_5317.h"

#line 8206 "reference.c"
float func_800747C0(CGameObjectInstance *pAI, CVector3 vPos, CGameObjectInstance *pTarget, float radiusFactor)
{
	int					cAng, direction;
	float					goalAngle, offsetAngle, tryAngle, returnOffset;
	CVector3				vTryPos;
	BOOL					rightHanded;
	CCollisionInfo2	*pCI;


	if (AI_GetEA(pAI)->m_wTypeFlags3 & AI_TYPE3_WALKINSTRAIGHTLINE)
		return 0.0;

	goalAngle = func_80071DA4(pAI, vPos);

	// it's okay to act stupid if nobody's looking
	if (!CGameObjectInstance__IsVisible(pAI))
		return goalAngle;

	if (!func_8001DF50(&pAI->ah, vPos, &pCI))
	{
		//rmonPrintf("unobstructed\r\n");
		return goalAngle;
	}

	// set collided flag
	if (pCI->pWallCollisionRegion)
		AICollidedWithWall = TRUE;

	//rightHanded = (((DWORD) pAI) & 0x100) ? 1 : 0;
	rightHanded = ((((DWORD) pAI) % sizeof(CGameObjectInstance)) & 1) ? 1 : 0;

	vTryPos.y = pAI->ah.ih.m_vPos.y;
	for (cAng=1; cAng<6; cAng++)
	{
		offsetAngle = cAng*ANGLE_DTOR(30);

		// make direction random
		for (direction=0; direction<2; direction++)
		{
			tryAngle = goalAngle;

			if (direction ^ rightHanded)
			{
				tryAngle += offsetAngle;
				returnOffset = ANGLE_DTOR(15);
			}
			else
			{
				tryAngle -= offsetAngle;
				returnOffset = ANGLE_DTOR(-15);
			}

			//vTryPos.x = pAI->ah.ih.m_vPos.x + sin(pAI->m_RotY + ANGLE_PI + tryAngle)*(AVOIDANCE_DISTANCE*SCALING_FACTOR);
			//vTryPos.z = pAI->ah.ih.m_vPos.z + cos(pAI->m_RotY + ANGLE_PI + tryAngle)*(AVOIDANCE_DISTANCE*SCALING_FACTOR);
			vTryPos.x = pAI->ah.ih.m_vPos.x + sin(pAI->m_RotY + ANGLE_PI + tryAngle)*(radiusFactor*pAI->ah.ih.m_pEA->m_CollisionRadius);
			vTryPos.z = pAI->ah.ih.m_vPos.z + cos(pAI->m_RotY + ANGLE_PI + tryAngle)*(radiusFactor*pAI->ah.ih.m_pEA->m_CollisionRadius);

			if (!func_8001DF50(&pAI->ah, vTryPos, NULL))
			{
				//rmonPrintf("offset:%f\r\n", (tryAngle - goalAngle)*180/ANGLE_PI);
				tryAngle += returnOffset;
				func_80013588(&tryAngle);
				return tryAngle;
			}
		}
	}

	// go toward goal
	return goalAngle;

/*
	if (RANDOM(2))
	{
		// go toward goal
		return goalAngle;
	}
	else
	{
		return ANGLE_DTOR(RANDOM(360)) - ANGLE_DTOR(180);
	}
*/
}
