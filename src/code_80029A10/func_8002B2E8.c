#include "decompdecomp_sync_4169c997c7badf2dd093.h"
#line 1 "func.c"
#line 10 "reference.c"
void func_8002B2E8(CParticleSystem *pThis, CCartCache *pCache,
											 ROMAddress *rpParticleEffectsAddress,
											 DWORD ParticleEffectsSize,
											 CCacheEntry *pceTextureSetsIndex)
{
	pThis->m_pCache = pCache;
	pThis->m_pceTextureSetsIndex = pceTextureSetsIndex;

   pThis->m_pceParticleEffects = NULL;
	CCartCache__RequestBlock(pThis->m_pCache,
									 pThis, (pfnCACHENOTIFY) CParticleSystem__DecompressParticles, NULL,
									 &pThis->m_pceParticleEffects,
									 rpParticleEffectsAddress, ParticleEffectsSize,
									 D_800F17D0);
}

