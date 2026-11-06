#include "decompdecomp_sync_37cc5f13d8d009a48950.h"
#line 1 "func.c"
#line 4428 "reference.c"
void AI_SEvent_Footfall (CInstanceHdr *pThis, CVector3 vPos, float Value )
{
	// which character is standing on what ?
	switch (CInstanceHdr__TypeFlag(pThis))
	{
		case AI_OBJECT_CHARACTER_PLAYER:
			break;

		case AI_OBJECT_CHARACTER_GENERICRED:
			break;

		case AI_OBJECT_CHARACTER_GENERICGREEN:
			break;

		case AI_OBJECT_CHARACTER_GENERICMETAL:
			break;

		case AI_OBJECT_CHARACTER_RAPTOR:
			AI_DoSound(pThis, SOUND_RAPTOR_FOOTFALL, 1, 0);
			break;

		case AI_OBJECT_CHARACTER_ALIEN:
		case AI_OBJECT_CHARACTER_HUMAN1:
			switch(CGameRegion__GetGroundMaterial(pThis->m_pCurrentRegion))
			{
				case REGMAT_WATERSURFACE:
					AI_DoSound(pThis, SOUND_WATER_FOOTFALL, 1, 0);
					break;

				case REGMAT_STONE:
					AI_DoSound(pThis, SOUND_STONE_FOOTFALL, 1, 0);
					break;

				case REGMAT_STEEL:
					AI_DoSound(pThis, SOUND_METAL_FOOTFALL, 1, 0);
					break;

				case REGMAT_GRASS:
					AI_DoSound(pThis, SOUND_LIGHT_JUNGLE_FOOTFALL, 1, 0);
					break;

				default:
					AI_DoSound(pThis, SOUND_STONE_FOOTFALL, 1, 0);
					break;
			}
			break;

		case AI_OBJECT_CHARACTER_SABERTIGER:
			AI_DoSound(pThis, SOUND_TIGER_FOOTFALL, 1, 0);
			break;

		case AI_OBJECT_CHARACTER_DIMETRODON:
			AI_DoSound(pThis, SOUND_DIMETRODON_FOOTFALL, 1, 0);
			break;

		case AI_OBJECT_CHARACTER_TRICERATOPS:
			AI_DoSound(pThis, SOUND_TRICERATOPS_FOOTFALL, 1, 0);
			break;

		case AI_OBJECT_CHARACTER_MOSCHOPS:
			AI_DoSound(pThis, SOUND_MOSCHOPS_FOOTFALL, 1, 0);
			break;

		case AI_OBJECT_CHARACTER_LEAPER:
			AI_DoSound(pThis, SOUND_LEAPER_FOOTFALL, 1, 0);
			break;

//		case AI_OBJECT_CHARACTER_ALIEN:
//			AI_DoSound(pThis, SOUND_ALIEN_FOOTFALL, 1, 0);
//			break;

		case AI_OBJECT_CHARACTER_HULK:
			AI_DoSound(pThis, SOUND_HULK_FOOTFALL, 1, 0);
			break;

		case AI_OBJECT_CHARACTER_ROBOT:
			AI_DoSound(pThis, SOUND_ROBOT_FOOTFALL, 1, 0);
			break;

		case AI_OBJECT_CHARACTER_BADFISH:
			break;

		case AI_OBJECT_CHARACTER_GOODFISH:
			break;

		case AI_OBJECT_CHARACTER_MANTIS_BOSS:
//			AI_DoSound(pThis, SOUND_MANTIS_INJURY, 1, 0);
			break;

		case AI_OBJECT_CHARACTER_TREX_BOSS:
			AI_DoSound(pThis, SOUND_TREX_FOOTFALL, 1, 0);
			break;

		case AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS:
		case AI_OBJECT_CHARACTER_LONGHUNTER_BOSS:
			AI_DoSound(pThis, SOUND_LIGHT_JUNGLE_FOOTFALL, 1, 0);
			break;
	}
}

