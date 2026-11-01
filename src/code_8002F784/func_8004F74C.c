#include "decompdecomp_sync_0b1af8a7ba620c0a34f7.h"
#line 1 "func.c"
#line 2484 "reference.c"
void func_8004F74C(CGameObjectInstance *pThis, CCampaigner *pCampaigner)
{
	CCamera	*pCamera = &GetApp()->m_Camera ;

	// Start off final flash?
	if (pCampaigner->m_Boss.m_EventFlags & BF_EVENT1)
	{
		CSpecialFx__StartScript(&pCampaigner->m_SpecialFx, CampaignerFxFinalDeath) ;

		// Make camera goto final track
		pCamera->m_Stage++ ;
		pCamera->m_StageTime = 0 ;
	}

 if (pCampaigner->m_Boss.m_AnimPlayed) {
  *(s32 *)((u8 *)pCampaigner + 0x168) = 0;
  *(s32 *)((u8 *)pThis + 0x1d0) |= 0x1000;
 }
}

