#include "source_CParticle__Advance.h"

extern u32 D_801195EC;
#line 1 "reference.c"
static __inline float ParticleMagnitude(CParticle *p){char scratch[4];return CVector3__Magnitude(&p->ah.m_vVelocity);}
void CParticle__Advance(CParticle *pThis)
{
	//CMtxF			mfRot;
	
	float			newSize;

	if (pThis->m_cFrame < 0)
		return;

	if (pThis->m_pEffect->m_FpsVelThreshold)
		pThis->m_FPS = pThis->m_pEffect->m_FPS * min(1, ParticleMagnitude(pThis) / func_8001F298(pThis->m_pEffect->m_FpsVelThreshold));

	pThis->m_cFramePos += D_800B6B00*pThis->m_FPS*(1.0/FRAME_FPS)*D_800B6B08;

	if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_SCALELINEAR)
	{
		pThis->m_Size += pThis->m_SizeScaler*SCALING_FACTOR*D_800B6B00;
		pThis->m_Size = min(400*SCALING_FACTOR, pThis->m_Size);
	}
	else
	{
		newSize = min(400*SCALING_FACTOR, pThis->m_Size*pThis->m_SizeScaler);
		pThis->m_Size += (newSize - pThis->m_Size)*D_800B6B00;
		if (pThis->m_Size < 0)
		{
			func_80029C48(pThis);
			CParticleSystem__DeallocateParticle(&GetApp()->m_Scene.m_ParticleSystem, pThis);
			return;
		}
	}

	if ((D_801195EC & CHEATFLAG_QUACKMODE) == 0)
	{
	//	pThis->m_Rotation += (SF2FLOAT(pThis->m_pEffect->m_RotationInc)*frame_increment);
		pThis->m_Rotation += (pThis->m_RotationInc * D_800B6B00);
	}

	// update every frame particle stuff
	func_8002A1A0(pThis);

	// don't do collision if particle has come to rest
	if (		((pThis->m_CI.GravityAcceleration == 0) || ((pThis->ah.ih.m_vPos.y == 0) && (pThis->m_CI.GravityAcceleration < 0)))
			&& (CVector3__MagnitudeSquared(&pThis->ah.m_vVelocity) < 0.001) )
	{
		return;
	}

	func_8009A4D8(&pThis->ah, pThis->ah.ih.m_vPos, &pThis->m_CI);

	// update glare effect on particle ?
	if (pThis == D_8011A0D0)
		D_8011A0C0 = pThis->ah.ih.m_vPos;

	// velocity delay ?
//	if (pThis->m_nVelocityDelay)
//	{
//		if (--pThis->m_nVelocityDelay == 0)
//		{
//			// Check for starting swoosh
//			CParticle__CheckForStartingSwoosh(pThis) ;
//
//			vDirection.x = SF2FLOAT(pThis->m_pEffect->m_DirectionX);
//			vDirection.y = SF2FLOAT(pThis->m_pEffect->m_DirectionY);
//			vDirection.z = SF2FLOAT(pThis->m_pEffect->m_DirectionZ);
//
//			// TEMP - vDirection needs to rotate as turok changes view direction
//			CMtxF__VectorMult(mfRot, &vDirection, &vRotDir);
//			vDirection = CVector3__RandomizeDirection(&vRotDir, SF2FLOAT(pThis->m_pEffect->m_DirectionSpray));
//
//			// set particle velocity with no velocity delay
//			CVector3__MultScaler(&pThis->ah.m_vVelocity, &vDirection,
//										SF2FLOAT(pThis->m_pEffect->m_Velocity) + CParticle__GetRandomFloat(SF2FLOAT(pThis->m_pEffect->m_VelocityRandom)));
//		}
//	}

	// collision
	if (pThis->m_CI.pWaterCollisionRegion)
	{
		func_8002A800(pThis);

		pThis->m_dwFlags |= PARTICLE_HASHITGROUND;
	}

	if (pThis->m_dwFlags & PARTICLE_ALLOCATED)
	{
		if (pThis->m_CI.pWallCollisionRegion)
		{
			if (!(pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_NOWALLSPAWN))
				func_8002AA38(pThis);

			pThis->m_dwFlags |= PARTICLE_HASHITWALL;
			if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_BOUNCEONLYONCE)
				pThis->m_CI.WallBehavior = INTERSECT_BEHAVIOR_STICK;
		}

		if (pThis->m_dwFlags & PARTICLE_ALLOCATED)
		{
			if (pThis->m_CI.pInstanceCollision)
				func_80029F14(pThis);

			if (pThis->m_dwFlags & PARTICLE_ALLOCATED)
			{
				if (		(pThis->m_CI.nGroundCollisionType != GROUNDCOLLISION_NONE)
						&& !(pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_NOGRDSPAWN) )
				{
					if (pThis->m_CI.nGroundCollisionType == GROUNDCOLLISION_GROUND)
							func_8002A5C8(pThis);
					else	// (pThis->m_CI.nGroundCollisionType == GROUNDCOLLISION_CEILING)
							func_8002A3B0(pThis);

					pThis->m_dwFlags |= PARTICLE_HASHITGROUND;
				}
			}
		}
	}
}
