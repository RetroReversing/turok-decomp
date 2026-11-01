#include "decompdecomp_sync_89cf489574eb4b680c76.h"
#line 1 "func.c"
#line 9762 "reference.c"
int CGameObjectInstance__GetModelIndex(CGameObjectInstance *pThis, int nType, int nNode)
{
	int				type;
	//static DWORD	morphFrame = -1;
	//static float	cMorph = 0;

	switch (nType)
	{
		case AI_OBJECT_DEVICE_ACTION:
		case AI_OBJECT_DEVICE_ANIMOFFSCREENACTION:
			// trex stuff
			if ((D_80112BD8) &&
				 (CGameObjectInstance__TypeFlag(D_80112BD8) == AI_OBJECT_CHARACTER_TREX_BOSS))
			{
				// turok corpse
				if (pThis->ah.ih.m_pEA->m_Id == 1)
					return CGameObjectInstance__GetTurokCorpseModelIndex((CGameObjectInstance *)pThis, nNode) ;
				// turok feathers
				else if (pThis->ah.ih.m_pEA->m_Id == 2)
					return CGameObjectInstance__GetTurokFeathersModelIndex((CGameObjectInstance *)pThis, nNode) ;
			}
			break ;

		case AI_OBJECT_DEVICE_TREXELEVATOR:
             
			return 0 ;
     
             
      

		case 314:
			return 0 ;

		case AI_OBJECT_DEVICE_CRYSTAL:
			return CGameObjectInstance__GetCrystalModelIndex(pThis, nNode) ;

		case AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS:
			return CGameObjectInstance__GetCampaignerModelIndex(pThis, nNode) ;

		case AI_OBJECT_CHARACTER_LONGHUNTER_BOSS:
			return CGameObjectInstance__GetLonghunterModelIndex(pThis, nNode) ;

		case AI_OBJECT_CHARACTER_PLAYER:
			return CGameObjectInstance__GetTurokModelIndex(pThis, nNode) ;

		case AI_OBJECT_DEVICE_PORTAL:
			//if (morphFrame != frame_number)
			//{
			//	morphFrame = frame_number;

				//cMorph += frame_increment*((1.0/FRAME_FPS)*PORTAL_IDLE_SPEED*(PORTAL_MORPH_FRAMES/10.0));
			//	if (cMorph >= PORTAL_MORPH_FRAMES)
			//		cMorph -= PORTAL_MORPH_FRAMES;

			CGeometry__MorphInc(&pThis->m_Geometry, 0, frame_increment*((1.0/FRAME_FPS)*PORTAL_IDLE_SPEED*(PORTAL_MORPH_FRAMES/10.0)));
			//}
			return even_odd;

		// FootSoldier (only human with switchable models)
		case AI_OBJECT_CHARACTER_HUMAN1:
			// Bone
//			AI_GetEA(pThis)->m_AttackStyle = 0 ;
//			AI_GetDyn(pThis)->m_WeaponModel = 1 ;

			// Sword
//			AI_GetEA(pThis)->m_AttackStyle = 0 ;
//			AI_GetDyn(pThis)->m_WeaponModel = 14 ;

			// Mace
//			AI_GetEA(pThis)->m_AttackStyle = 0 ;
//			AI_GetDyn(pThis)->m_WeaponModel = 2 ;

			// Sceptre
//			AI_GetEA(pThis)->m_AttackStyle = 22 ;

			// Pole1
//			AI_GetEA(pThis)->m_AttackStyle = 3 ;
//			AI_GetDyn(pThis)->m_WeaponModel = 3 ;

			// Pole2
//			AI_GetEA(pThis)->m_AttackStyle = 3 ;
//			AI_GetDyn(pThis)->m_WeaponModel = 16 ;


			type = AI_GetEA(pThis)->m_AttackStyle ;

			// weapons
			if (nNode == RHAND)
			{
				// corpse should have no weapon....
				if (AI_GetEA(pThis)->m_wTypeFlags3 & AI_TYPE3_DUMB)
					return 0 ;

				switch (type)
				{
					// weapons
					case 0:
					case 1:
					case 3:
						return AI_GetDyn(pThis)->m_WeaponModel ;
					default:
						return pThis->ah.ih.m_pEA->m_nModel ;
				}
			}
              
			// shins
			else if ((nNode == LLOWLEG) || (nNode == RLOWLEG))
			{
				switch (type)
				{
					case 1:
					case 2:
					case 4:
					case 5:
					case 7:
						return AI_GetDyn(pThis)->m_ExtraModel ;
					default:
						return pThis->ah.ih.m_pEA->m_nModel ;
				}
			}

			// shoulders
			else if ((nNode == LSHOULDER) || (nNode == RSHOULDER))
			{
				switch (type)
				{
					case 3:
						return AI_GetDyn(pThis)->m_ExtraModel ;
					default:
						return pThis->ah.ih.m_pEA->m_nModel ;
				}
			}
      
			else
				return pThis->ah.ih.m_pEA->m_nModel ;
	}

	return pThis->ah.ih.m_pEA->m_nModel ;
}

