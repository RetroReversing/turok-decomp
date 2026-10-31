#include "context_43183bda5f19.h"
#line 1 "func.c"
#line 1 "reference.c"
int func_80060AE4 (CGameObjectInstance *pThis, CInstanceHdr *pOrigin, CVector3 vPos, float rad, int nKnife)
{
	// object type hit points for knife & tomahawk
	// knife - left/right/forward | tomahawk - left/right/forward
	int	RaptorHits			[]={3,3,3, 3,3,3};
	int	Human1Hits			[]={15,15,15, 20,20,20};		// knife / (uInt)tomahawk needs to kill human with one hit
	int	SaberTigerHits		[]={1,1,1, 1,1,1};
	int	DimetrodonHits		[]={1,1,1, 1,1,1};
	int	TriceratopsHits	[]={1,1,1, 1,1,1};
	int	MoschopsHits		[]={1,1,1, 1,1,1};
	int	PteranodonHits		[]={1,1,1, 1,1,1};
	int	SubterraneanHits	[]={1,1,1, 1,1,1};
	int	LeaperHits			[]={7,7,7, 7,7,7};
	int	AlienHits			[]={1,1,1, 1,1,1};
	int	HulkHits				[]={1,1,1, 1,1,1};
	int	RobotHits			[]={-1,-1,-1, -1,-1,-1};
	int	BadFishHits			[]={10,10,10, 10,10,10};
	int	GoodFishHits		[]={10,10,10, 10,10,10};
	int	SludgeBoyHits		[]={1,1,1, 1,1,1};
	int	PlantHits			[]={1,1,1, 1,1,1};

#define TREX_KNIFE_HITS			25
#define CAMPAIGNER_KNIFE_HITS	20
#define LONGHUNTER_KNIFE_HITS	15
#define MANTIS_KNIFE_HITS		25


	int	*pHits = NULL;
	long	nHits=0;
	int	ey, py, angdiff;



	// special case for no collision
	if (!(AI_GetEA(pThis)->m_dwTypeFlags & AI_TYPE_COLLISION))
		return 0;

	if (func_8005FA10(pThis))
		return 0;

	if (AI_GetDyn(pThis)->m_dwStatusFlags2 & AI_HOLDINTANIMON1STFRAME)
		return 0;

	if (AI_GetDyn(pThis)->m_cRegenerateAppearance > 0)
		return 0;

	// did ai get hit
	rad *= SCALING_FACTOR;
	ey = ((int)ANGLE_RTOD(pThis->m_RotY))%360;
	py = ((int)ANGLE_RTOD(CEngineApp__GetPlayer(GetApp())->m_RotY))%360;
	if ((unsigned short)ey<0) ey+=360;
	if (py<0) py+=360;
	angdiff = (ey-py);

	// test for more accurate mortal wound hit - radius is smaller & enemy must be facing away from us
	if ( (sqrt(func_8005F34C(pThis, vPos)) <= ( (rad/2) + AI_GetEA(pThis)->m_CollisionRadius)) &&
		  (abs(angdiff)<=40)         &&
		  (AI_GetDyn(pThis)->m_Health>0)     )
	{
		// which character is standing on what ?
		switch (CGameObjectInstance__TypeFlag(pThis))
		{
			case AI_OBJECT_CHARACTER_PLAYER:
				nHits=0;
				break;

			case AI_OBJECT_CHARACTER_RAPTOR:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_GENERICRED:
			case AI_OBJECT_CHARACTER_GENERICGREEN:
			case AI_OBJECT_CHARACTER_GENERICMETAL:
			case AI_OBJECT_CHARACTER_HUMAN1:
				nHits = AI_MORTAL_DEATH_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_SABERTIGER:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_DIMETRODON:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_TRICERATOPS:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_MOSCHOPS:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_PTERANODON:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_SUBTERRANEAN:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_LEAPER:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_ALIEN:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_HULK:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_ROBOT:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_BADFISH:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			case AI_OBJECT_CHARACTER_GOODFISH:
				nHits = AI_MORTAL_WOUND_KT_HITS;
				break;

			// Bosses
			case AI_OBJECT_CHARACTER_TREX_BOSS:
				nHits = TREX_KNIFE_HITS	;
				break ;

			case AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS:
				nHits = CAMPAIGNER_KNIFE_HITS	;
				break ;

			case AI_OBJECT_CHARACTER_LONGHUNTER_BOSS:
				nHits = LONGHUNTER_KNIFE_HITS	;
				break ;

			case AI_OBJECT_CHARACTER_MANTIS_BOSS:
				nHits = MANTIS_KNIFE_HITS	;
				break ;

			default:
				break;
		}
		// do mortal hits
		func_80060A54(pThis, nHits);
		func_8005F228(pThis, pOrigin);
	}
	// hit another ai (do normal proper test between two ai's)
	else if ( sqrt(func_8005F34C(pThis, vPos)) <= ( rad + AI_GetEA(pThis)->m_CollisionRadius) )
	{
		// which character is standing on what ?
		switch (CGameObjectInstance__TypeFlag(pThis))
		{
			case AI_OBJECT_CHARACTER_PLAYER:
				break;

			case AI_OBJECT_CHARACTER_RAPTOR:
				pHits = &RaptorHits[0];
				break;

			case AI_OBJECT_CHARACTER_GENERICRED:
			case AI_OBJECT_CHARACTER_GENERICGREEN:
			case AI_OBJECT_CHARACTER_GENERICMETAL:
			case AI_OBJECT_CHARACTER_HUMAN1:
				pHits = &Human1Hits[0];
				break;

			case AI_OBJECT_CHARACTER_SABERTIGER:
				pHits = &SaberTigerHits[0];
				break;

			case AI_OBJECT_CHARACTER_DIMETRODON:
				pHits = &DimetrodonHits[0];
				break;

			case AI_OBJECT_CHARACTER_TRICERATOPS:
				pHits = &TriceratopsHits[0];
				break;

			case AI_OBJECT_CHARACTER_MOSCHOPS:
				pHits = &MoschopsHits[0];
				break;

			case AI_OBJECT_CHARACTER_PTERANODON:
				pHits = &PteranodonHits[0];
				break;

			case AI_OBJECT_CHARACTER_SUBTERRANEAN:
				pHits = &SubterraneanHits[0];
				break;

			case AI_OBJECT_CHARACTER_LEAPER:
				pHits = &LeaperHits[0];
				break;

			case AI_OBJECT_CHARACTER_ALIEN:
				pHits = &AlienHits[0];
				break;

			case AI_OBJECT_CHARACTER_HULK:
				pHits = &HulkHits[0];
				break;

			case AI_OBJECT_CHARACTER_ROBOT:
				pHits = &RobotHits[0];
				break;

			case AI_OBJECT_CHARACTER_BADFISH:
				pHits = &BadFishHits[0];
				break;

			case AI_OBJECT_CHARACTER_GOODFISH:
				pHits = &GoodFishHits[0];
				break;

			case AI_OBJECT_CHARACTER_SLUDGEBOY:
				pHits = &SludgeBoyHits[0];
				break;

			case AI_OBJECT_CHARACTER_PLANT:
				pHits = &PlantHits[0];
				break;

			// Bosses
			case AI_OBJECT_CHARACTER_TREX_BOSS:
				nHits = TREX_KNIFE_HITS	;
				break ;

			case AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS:
				nHits = CAMPAIGNER_KNIFE_HITS	;
				break ;

			case AI_OBJECT_CHARACTER_LONGHUNTER_BOSS:
				nHits = LONGHUNTER_KNIFE_HITS	;
				break ;

			case AI_OBJECT_CHARACTER_MANTIS_BOSS:
				nHits = MANTIS_KNIFE_HITS	;
				break ;


			default:
				pHits = NULL;
				nHits = 0;
				break;

		}


		// do damage ?
		if (pHits)
		{
			switch (nKnife)
			{
				case AI_KNIFE_LEFT_ATTACK:
					nHits = *(pHits+0);
					break;

				case AI_KNIFE_RIGHT_ATTACK:
					nHits = *(pHits+1);
					break;

				case AI_KNIFE_FORWARD_ATTACK:
					nHits = *(pHits+2);
					break;

				case AI_TOMAHAWK_LEFT_ATTACK:
					nHits = *(pHits+3);
					break;

				case AI_TOMAHAWK_RIGHT_ATTACK:
					nHits = *(pHits+4);
					break;

				case AI_TOMAHAWK_FORWARD_ATTACK:
					nHits = *(pHits+5);
					break;
			}

			// do hit damage to object
			if (nHits<0)
			{
				// knife / tomahawk does no damage on this creature
				// return a hit so particle effect still takes place
				nHits = 1;
			}
			else
			{
				func_80060A54(pThis, nHits);
				func_8005F228(pThis, pOrigin);

				// was mortal wound caused ?
				if (AI_GetDyn(pThis)->m_Health==0)
					AI_GetDyn(pThis)->m_dwStatusFlags |= AI_WOUNDEDMORTALLY;

			}
		}
	}

	// do knife slash sound
	if (nHits)
		AI_DoSound(&pThis->ah.ih, SOUND_TOMAHAWK_IMPACT_FLESH, 1, RANDOMIZE_PITCH);

	return nHits;
}

