#include "source_func_800607AC.h"
#line 1 "func.c"
#line 1 "reference.c"
void func_800607AC (CInstanceHdr *pThis, CVector3 vPos, int nKnife, int nHits)
{
	int						nType=-1, redblood, greenblood, spark;
	CGameObjectInstance	*pAnim;


	// is blood off ?
//	if (!GetApp()->m_Options.m_Blood)
//		return;

	if (nHits == AI_MORTAL_WOUND_KT_HITS)
	{
		redblood   = PARTICLE_TYPE_KTFATAL_BLOOD;
		greenblood = PARTICLE_TYPE_KTFATAL_GBLOOD;
		spark      = PARTICLE_TYPE_KTFATAL_SPARK;
	}
	else
	{
		switch (nKnife)
		{
			case AI_KNIFE_LEFT_ATTACK:
				redblood   = PARTICLE_TYPE_KNIFELEFT_BLOOD;
				greenblood = PARTICLE_TYPE_KNIFELEFT_GBLOOD;
				spark      = PARTICLE_TYPE_KNIFELEFT_SPARK;
				break;

			case AI_KNIFE_RIGHT_ATTACK:
				redblood   = PARTICLE_TYPE_KNIFERIGHT_BLOOD;
				greenblood = PARTICLE_TYPE_KNIFERIGHT_GBLOOD;
				spark      = PARTICLE_TYPE_KNIFERIGHT_SPARK;
				break;

			case AI_KNIFE_FORWARD_ATTACK:
				redblood   = PARTICLE_TYPE_KNIFEFORWARD_BLOOD;
				greenblood = PARTICLE_TYPE_KNIFEFORWARD_GBLOOD;
				spark      = PARTICLE_TYPE_KNIFEFORWARD_SPARK;
				break;

			case AI_TOMAHAWK_LEFT_ATTACK:
				redblood   = PARTICLE_TYPE_TOMAHAWKLEFT_BLOOD;
				greenblood = PARTICLE_TYPE_TOMAHAWKLEFT_GBLOOD;
				spark      = PARTICLE_TYPE_TOMAHAWKLEFT_SPARK;
				break;

			case AI_TOMAHAWK_RIGHT_ATTACK:
				redblood   = PARTICLE_TYPE_TOMAHAWKRIGHT_BLOOD;
				greenblood = PARTICLE_TYPE_TOMAHAWKRIGHT_GBLOOD;
				spark      = PARTICLE_TYPE_TOMAHAWKRIGHT_SPARK;
				break;

			case AI_TOMAHAWK_FORWARD_ATTACK:
				redblood   = PARTICLE_TYPE_TOMAHAWKFORWARD_BLOOD;
				greenblood = PARTICLE_TYPE_TOMAHAWKFORWARD_GBLOOD;
				spark      = PARTICLE_TYPE_TOMAHAWKFORWARD_SPARK;
				break;
		}
	}


	switch (pThis->m_Type)
	{
		case I_ANIMATED:
			pAnim = (CGameObjectInstance*) pThis;
//			if (AI_GetEA(pAnim)->m_dwTypeFlags2 & AI_TYPE2_NOBLOOD)
//				break;

			// don't generate blood if enemy is invincible
			if (AI_GetDyn(pAnim)->m_Invincible)
				break;

			// which character is standing on what ?
			switch (CGameObjectInstance__TypeFlag(pAnim))
			{
				case AI_OBJECT_CHARACTER_PLAYER:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_GENERICRED:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_GENERICGREEN:
					nType = greenblood;
					break;

				case AI_OBJECT_CHARACTER_GENERICMETAL:
					nType = spark;
					break;

				case AI_OBJECT_CHARACTER_RAPTOR:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_HUMAN1:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_SABERTIGER:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_DIMETRODON:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_TRICERATOPS:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_MOSCHOPS:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_PTERANODON:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_SUBTERRANEAN:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_LEAPER:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_ALIEN:
					nType = greenblood;
					break;

				case AI_OBJECT_CHARACTER_PLANT:
					nType = greenblood;
					break;

				case AI_OBJECT_CHARACTER_SLUDGEBOY:
					nType = greenblood;
					break;

				case AI_OBJECT_CHARACTER_HULK:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_ROBOT:
					nType = spark;
					break;

				case AI_OBJECT_CHARACTER_BADFISH:
					nType = redblood;
					break;

				case AI_OBJECT_CHARACTER_GOODFISH:
					nType = redblood;
					break;

				// Bosses
				case AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS:
				case AI_OBJECT_CHARACTER_LONGHUNTER_BOSS:
				case AI_OBJECT_CHARACTER_TREX_BOSS:
					nType = redblood;
					break ;

				case AI_OBJECT_CHARACTER_MANTIS_BOSS:
					nType = greenblood;
					break ;
			}

			if (nType!=-1)
				func_80060464(pThis, nType, vPos, ANGLE_DTOR(360));

			break;
	}
}

