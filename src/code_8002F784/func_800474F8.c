#include "decompdecomp_sync_06d89f2a775789456659.h"
#line 1 "func.c"
#line 2969 "reference.c"
void func_800474F8(CGameObjectInstance *pThis, CMantis *pMantis)
{
	CGameObjectInstance *pTurok = D_8010201C;
	pMantis->m_Boss.m_Mode = MANTIS_DEATH_FLOOR_MODE ;
	pMantis->m_Boss.m_MoveTime = -1 ;

	GetApp()->m_BossFlags |= BOSS_FLAG_MANTIS_DEAD	;


	AI_Event_Dispatcher(&pTurok->ah.ih, &pTurok->ah.ih, 231, pTurok->ah.ih.m_pEA->m_dwSpecies, pTurok->ah.ih.m_vPos, 300.0f);
	GetApp()->tracked = pThis;
	GetApp()->pickupActive = 0 ;

	func_8003983C(D_80112C18,64) ;
}

