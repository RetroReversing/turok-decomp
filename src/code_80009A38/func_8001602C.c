#include "common_local_source_3891.h"

#line 9156 "reference.c"
int func_8001602C(CGameObjectInstance *pThis, int nNode)
{
	int type;

	type = AI_GetEA(pThis)->m_AttackStyle ;

	// FootSoldier
	if (type < 9)
	{
#ifdef GERMAN
		return AI_GetDyn(pThis)->m_HeadTexture ;
#else
		switch (nNode)
		{
			case HEAD:
				return AI_GetDyn(pThis)->m_HeadTexture ;

			case TORSO:
			case ROOT:
			case LSHOULDER:
			case LUPARM:
			case LLOWARM:
			case LHAND:
			case RSHOULDER:
			case RUPARM:
			case RLOWARM:
			case RHAND:
				return AI_GetDyn(pThis)->m_BodyTexture ;

			// Legs and Neck
			default:
				return 0 ;
		}
#endif
	}

	// Longhunters men
	else if (type < 18)
	{
#ifdef GERMAN
		return pThis->ah.ih.m_pEA->m_nTexture;
#else
		switch (nNode)
		{
			case HEAD:
				return AI_GetDyn(pThis)->m_HeadTexture ;

			case TORSO:
			case ROOT:
				return 6-1 ;

			case LSHOULDER:
			case LUPARM:
			case LLOWARM:
			case LHAND:
			case RSHOULDER:
			case RUPARM:
			case RLOWARM:
			case RHAND:
				return 1-1 ;

			case LUPLEG:
			case LLOWLEG:
			case LFOOT:
			case RUPLEG:
			case RLOWLEG:
			case RFOOT:
				return 3-1 ;

			default:
				return 0 ;
		}
#endif
	}

	// Ancient Warrior 1-3
	else if (type < 22)
	{
#ifdef GERMAN
		return pThis->ah.ih.m_pEA->m_nTexture;
#else
		switch (nNode)
		{
			case HEAD:
				return 0 ;

			case NECK:
				return 2-1 ;

			case LSHOULDER:
			case LUPARM:
			case LLOWARM:
			case LHAND:
			case RSHOULDER:
			case RUPARM:
			case RLOWARM:
			case RHAND:
			case TORSO:
			case ROOT:
				return 3-1 ;

			default:
				return 0 ;
		}
#endif
	}

	// Ancient Warrior 4-5
	else if (type < 25)
	{
#ifdef GERMAN
		return pThis->ah.ih.m_pEA->m_nTexture;
#else
		switch (nNode)
		{
			case NECK:
				return 3-1 ;

			case LSHOULDER:
			case LUPARM:
			case LLOWARM:
			case LHAND:
			case RSHOULDER:
			case RUPARM:
			case RLOWARM:
			case RHAND:
			case TORSO:
			case ROOT:
				return 4-1 ;

			case LUPLEG:
			case LLOWLEG:
			case LFOOT:
			case RUPLEG:
			case RLOWLEG:
			case RFOOT:
				return 2-1 ;

			default:
				return 0 ;
		}
#endif
	}

	// Cyborg
	else if (type < 27)
	{
#ifdef GERMAN
		return pThis->ah.ih.m_pEA->m_nTexture;
#else
		switch (nNode)
		{
			case NECK:
			case LSHOULDER:
			case LUPARM:
			case LLOWARM:
			case LHAND:
			case RSHOULDER:
			case RUPARM:
			case RLOWARM:
			case RHAND:
			case LUPLEG:
			case LLOWLEG:
			case LFOOT:
			case RUPLEG:
			case RLOWLEG:
			case RFOOT:
			case ROOT:
			case TORSO:
				if (type == 25)
					return 1-1 ;
				else
					return 2-1 ;

			case HEAD:
				if (type == 25)
					return game_frame_number%9 ;
				else
					return (game_frame_number%9)+9 ;

			default:
				return 0 ;
		}
#endif
	}
	// Robosuit (same as regular human without armor and face)
	else if (type <28)
	{
#ifdef GERMAN
		return pThis->ah.ih.m_pEA->m_nTexture;
#else
		switch (nNode)
		{
			case TORSO:
			case ROOT:
			case LSHOULDER:
			case LUPARM:
			case LLOWARM:
			case LHAND:
			case RSHOULDER:
			case RUPARM:
			case RLOWARM:
			case RHAND:
				return 5-1 ;		// no armor

			case LUPLEG:
			case LLOWLEG:
			case LFOOT:
			case RUPLEG:
			case RLOWLEG:
			case RFOOT:
				return 2-1 ;

			case NECK:
				return 4-1 ;

			case HEAD:
			default:
				return 0;
		}
#endif
	}
	// Demon / Zombie
	else if (type < 30)
	{
#ifdef GERMAN
		return pThis->ah.ih.m_pEA->m_nTexture;
#else
		switch (nNode)
		{
			case NECK:
				if (type == 28)
					return 5-1 ;
				else
					return 6-1 ;

			case LUPLEG:
			case LLOWLEG:
			case LFOOT:
			case RUPLEG:
			case RLOWLEG:
			case RFOOT:
				if (type == 28)
					return 3-1 ;
				else
					return 4-1 ;

			case ROOT:
			case TORSO:
				if (type == 28)
					return 7-1 ;
				else
					return 8-1 ;


			case LSHOULDER:
			case LUPARM:
			case LLOWARM:
			case LHAND:
			case RSHOULDER:
			case RUPARM:
			case RLOWARM:
			case RHAND:
				if (type == 28)
					return 7-1 ;
				else
					return 8-1 ;

			default:
				return 0 ;
		}
#endif
	}
	return 0 ;
}
