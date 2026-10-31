#include "common_local_source_4211.h"

#line 1 "reference.c"
void func_80035768(void)
{
	int	i ;

	// Set all matrices to identity matrix, just to be valid
	// incase something is pointing to them!!!
	for (i = 0 ; i < (MATTABLE_MATRICES * 2) ; i++)
		guMtxIdent(&D_8011A9E0[i]) ;

	D_801271E0.m_MtxsFree = MATTABLE_MATRICES ;
	D_801271E0.m_pmFreeMtx = D_8011A9E0 ;
	D_801271E0.m_MtxsRequested = 0 ;

#if SHOW_MATTABLE_STATS
	MaxMtxsRequested = 0 ;
	MtxsAllocated = 0 ;
#endif
}
