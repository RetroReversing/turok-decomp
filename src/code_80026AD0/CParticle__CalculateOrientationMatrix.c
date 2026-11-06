#include "common_local_source_4023.h"

#line 2463 "reference.c"
void CParticle__CalculateOrientationMatrix(CParticle *pThis,
														 float *pDistanceFromPlayer /*=NULL*/,
														 BOOL *pIntersectWithGround  /*=NULL*/)
{
#if USE_ORIGINAL_MATRIX
	CMtxF						mfScale, mfPos,
								mfTemp2;
#endif
	CMtxF						mfRotate,
								mfTemp1,
								*pmfAlign;
	CVector3					vPos, vDelta;
	CGameObjectInstance	*pPlayer;
	float						scaler, ground;

	scaler = pThis->m_Size/2;
	vPos = pThis->ah.ih.m_vPos;

	if (		(SF2FLOAT(pThis->m_pEffect->m_RotationPivotX) == 0)
			&&	(SF2FLOAT(pThis->m_pEffect->m_RotationPivotY) == 0) )
	{
		CMtxF__RotateZ(mfRotate, pThis->m_Rotation) ;
	}
	else
	{
#if USE_ORIGINAL_MATRIX
		CMtxF__Translate(mfTemp1, -SF2FLOAT(pThis->m_pEffect->m_RotationPivotX), -SF2FLOAT(pThis->m_pEffect->m_RotationPivotY), 0);
		CMtxF__RotateZ(mfTemp2, pThis->m_Rotation) ;
		CMtxF__PostMult(mfRotate, mfTemp1, mfTemp2);
#else
		// Optimized matrix version
		CMtxF__RotateZ(mfRotate, pThis->m_Rotation) ;
		CMtxF__PreMultTranslate(mfRotate, -SF2FLOAT(pThis->m_pEffect->m_RotationPivotX), -SF2FLOAT(pThis->m_pEffect->m_RotationPivotY), 0);
#endif
	}

	pmfAlign = CParticle__GetAlignmentRotation(pThis);

	if (pIntersectWithGround)
		*pIntersectWithGround = FALSE;

	switch (pThis->m_Alignment)
	{
		case PARTICLE_UP:
			if (pThis->m_pEffect->m_WallBehavior != INTERSECT_BEHAVIOR_IGNORE)
				vPos.y = max(vPos.y, CGameRegion__GetGroundHeight(pThis->ah.ih.m_pCurrentRegion, vPos.x, vPos.z) + PARTICLE_RAISE);
			break;

		case PARTICLE_GROUND:
			if (pThis->m_pEffect->m_WallBehavior != INTERSECT_BEHAVIOR_IGNORE)
			{
				ground = CGameRegion__GetGroundHeight(pThis->ah.ih.m_pCurrentRegion, vPos.x, vPos.z);
				if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_INTERSECTION)
				{
					if (vPos.y < (ground + 0.1*SCALING_FACTOR))
					{
						vPos.y = ground;

						if (pIntersectWithGround)
							*pIntersectWithGround = TRUE;
					}
				}
				else
				{
					vPos.y = max(vPos.y, ground + PARTICLE_RAISE);
				}
			}
			break;

		case PARTICLE_CEILING:
			if (pThis->m_pEffect->m_WallBehavior != INTERSECT_BEHAVIOR_IGNORE)
				vPos.y = min(vPos.y, CGameRegion__GetCeilingHeight(pThis->ah.ih.m_pCurrentRegion, vPos.x, vPos.z) - PARTICLE_RAISE);
			break;

		case PARTICLE_SCREENY:
			if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_ALIGNONBOTTOM)
				vPos.y += pThis->m_Size/2;
			break;

		case 0:
		case 1:
		case 2:
			break;

		case PARTICLE_SCREEN:
		case PARTICLE_NOEDGE:
		default:
			if (pThis->m_pEffect->m_dwFlags & PARTICLE_BEHAVIOR_ALIGNONBOTTOM)
				vPos.y += pThis->m_Size/2;
			break;
	}

	CVector3__Clamp(&vPos, WORLD_LIMIT);

#if USE_ORIGINAL_MATRIX
	CMtxF__Scale(mfScale, scaler, scaler, scaler);
	CMtxF__Translate(mfPos, vPos.x, vPos.y, vPos.z);
	CMtxF__PostMult(mfTemp1, mfScale, mfRotate);
	CMtxF__PostMult(mfTemp2, mfTemp1, *pmfAlign);
	CMtxF__PostMult(mfTemp1, mfTemp2, mfPos);
#else
	// Optimized matrix version
	CMtxF__PreMultScale(mfRotate, scaler, scaler, scaler);
	CMtxF__PostMult(mfTemp1, mfRotate, *pmfAlign);
	CMtxF__PostMultTranslate(mfTemp1, vPos.x, vPos.y, vPos.z);
#endif

	CMtxF__ToMtx(mfTemp1, CParticle__GetOrientationMatrix(pThis));

	if (pDistanceFromPlayer)
	{
		pPlayer = CEngineApp__GetPlayer(GetApp());
		if (pPlayer)
		{
			CVector3__Subtract(&vDelta, &vPos, &pPlayer->ah.ih.m_vPos);
			*pDistanceFromPlayer = CVector3__Magnitude(&vDelta);
		}
		else
		{
			*pDistanceFromPlayer = 0;
		}
	}
}
