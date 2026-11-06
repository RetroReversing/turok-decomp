#include "common_local_source_4685.h"

#line 1 "reference.c"
void CAttractDemo__CheckForNewDemoRequest(void)
{
#if PLAY_ROM_DEMOS
	CAttractDemo	*pThis = &D_80128140 ;

	// Requesting a demo?
	if ((pThis->m_DemoRequested) && (func_8004FCA0(*pThis->m_pCurrentDemo)))
	{
		pThis->m_DemoRequested = FALSE ;

		// Goto demo for next time
		pThis->m_pCurrentDemo++ ;
		if (*pThis->m_pCurrentDemo == 0)
			pThis->m_pCurrentDemo = D_800BDE80 ;
	}
#endif
}
