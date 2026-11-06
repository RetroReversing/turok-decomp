#include "decompdecomp_sync_0679f4893938129fe870.h"
#line 1 "func.c"
#line 848 "reference.c"
void CParticleSystem__Construct(CParticleSystem *pThis)
{
	int	i, v;
	Vtx	*pV;

	TRACE0("CParticleSystem construction\r\n");

	ASSERT(PARTICLES_MAX_COUNT >= 1);

	p_particle_glare = NULL;

	pThis->m_pFreeHead = &pThis->m_Particles[0];
	pThis->m_pActiveHead = pThis->m_pActiveTail = NULL;
	pThis->m_pDrawHead = pThis->m_pDrawTail = NULL;

	for (i=0; i<(PARTICLES_MAX_COUNT-1); i++)
		pThis->m_Particles[i].m_pNext = &pThis->m_Particles[i+1];

	pThis->m_Particles[PARTICLES_MAX_COUNT-1].m_pNext	= NULL;

	CEnemyAttributes__SetDefaults(&particle_attributes);
	particle_attributes.m_dwTypeFlags     &= ~AI_TYPE_COLLISION;
	particle_attributes.m_dwTypeFlags     |= AI_TYPE_TRACKGROUND;
	particle_attributes.m_CollisionRadius  = 0*SCALING_FACTOR;
	particle_attributes.m_CollisionHeight = 0.0;

	for (v=0; v<4; v++)
	{
		pV = &particle_vtxs[v];

		// 64 is max texture size
		switch (v)
		{
			case 0:
				pV->v.ob[0] = -1;
				pV->v.ob[1] = 1;
				//pV->v.tc[0] = 64*(1 << 6);
				//pV->v.tc[1] = 64*(1 << 6);
				pV->v.tc[0] = 64*(1 << 7);
				pV->v.tc[1] = 64*(1 << 7);
				break;
			case 1:
				pV->v.ob[0] = 1;
				pV->v.ob[1] = 1;
				pV->v.tc[0] = 0;
				//pV->v.tc[1] = 64*(1 << 6);
				pV->v.tc[1] = 64*(1 << 7);
				break;
			case 2:
				pV->v.ob[0] = 1;
				pV->v.ob[1] = -1;
				pV->v.tc[0] = 0;
				pV->v.tc[1] = 0;
				break;
			case 3:
				pV->v.ob[0] = -1;
				pV->v.ob[1] = -1;
				//pV->v.tc[0] = 64*(1 << 6);
				pV->v.tc[0] = 64*(1 << 7);
				pV->v.tc[1] = 0;
				break;
		}
		pV->v.ob[2] = 0;

		pV->v.flag = 0;

		pV->v.cn[0] = 255;
		pV->v.cn[1] = 255;
		pV->v.cn[2] = 255;
		pV->v.cn[3] = 255;
	}

	CMtxF__RotateX(mf_particle_faceup, ANGLE_PI/2) ;

	for (i=0; i<PARTICLES_MAX_COUNT; i++)
		CParticle__Construct(&pThis->m_Particles[i]);

   pThis->m_pceParticleEffects = NULL;
	pThis->m_pCache = NULL;
	pThis->m_pceTextureSetsIndex = NULL;
}

