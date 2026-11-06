#include "decompdecomp_sync_9a8f52e3a70c6c7efa35.h"
#line 1 "func.c"
#line 4581 "reference.c"
void CTMove__FireBullet ( CTMove *pThis, int WFired )
{
	CEngineApp				*pApp;
	CGameObjectInstance	*pIns;
	DWORD						nType;
	CVector3					vBaseVelocity,
								vForward, vRotatedForward,
								vOffset,
								vParticlePos,
								vPos;
	CQuatern					qRotateDirection;
	CMtxF						mfRot;
	float						velocity,
								Angle;
	CGameRegion				*pParticleRegion;
	int						nParticle;
	BOOL						firedArrow = FALSE;


	// auto aim angle thresholds
//	#define	TMOVE_AUTOAIM_ANGLE_TEKBOW						22
//	#define	TMOVE_AUTOAIM_ANGLE_SEMIAUTOMATICPISTOL	22
//	#define	TMOVE_AUTOAIM_ANGLE_TECHWEAPON1				22
//
//	#define	TMOVE_AUTOAIM_ANGLE_ASSAULTRIFLE				14
//	#define	TMOVE_AUTOAIM_ANGLE_RIOTSHOTGUN				14
//
//	#define	TMOVE_AUTOAIM_ANGLE_AUTOMATICSHOTGUN		6
//	#define	TMOVE_AUTOAIM_ANGLE_MINIGUN					6
//	#define	TMOVE_AUTOAIM_ANGLE_MACHINEGUN				6
//	#define	TMOVE_AUTOAIM_ANGLE_CHRONOSCEPTER			6
//
//	#define	TMOVE_AUTOAIM_ANGLE_GRENADELAUNCHER			1
//	#define	TMOVE_AUTOAIM_ANGLE_ROCKET						1
//	#define	TMOVE_AUTOAIM_ANGLE_SHOCKWAVE					1
//	#define	TMOVE_AUTOAIM_ANGLE_TECHWEAPON2				1

	#define	TMOVE_AUTOAIM_ANGLE_TEKBOW						18
	#define	TMOVE_AUTOAIM_ANGLE_SEMIAUTOMATICPISTOL	18
	#define	TMOVE_AUTOAIM_ANGLE_TECHWEAPON1				18

	#define	TMOVE_AUTOAIM_ANGLE_ASSAULTRIFLE				12
	#define	TMOVE_AUTOAIM_ANGLE_RIOTSHOTGUN				12

	#define	TMOVE_AUTOAIM_ANGLE_AUTOMATICSHOTGUN		3
	#define	TMOVE_AUTOAIM_ANGLE_MINIGUN					3
	#define	TMOVE_AUTOAIM_ANGLE_MACHINEGUN				3
	#define	TMOVE_AUTOAIM_ANGLE_CHRONOSCEPTER			3

	#define	TMOVE_AUTOAIM_ANGLE_GRENADELAUNCHER			1
	#define	TMOVE_AUTOAIM_ANGLE_ROCKET						1
	#define	TMOVE_AUTOAIM_ANGLE_SHOCKWAVE					1
	#define	TMOVE_AUTOAIM_ANGLE_TECHWEAPON2				1


	// get pointer to engine app
	pApp = GetApp();
	if ( pApp == NULL ) return;

	// get instance pointer to turok
	pIns = CEngineApp__GetPlayer(pApp);
	if ( pIns == NULL ) return;

	// do weapon projectile particle fire (straight ahead out of gun)
	vBaseVelocity.x = vBaseVelocity.y = vBaseVelocity.z = 0;

	// get position for sfx
	vPos = D_80129520.Ears.vPos;

	// get offset for particle from this weapon
	nParticle=1;
	switch ( WFired )
	{

		case TWEAPON_TEKBOW:
			// turok has released arrow, which type of arrow did turok fire ?
			if (pThis->BowStarted>=TMOVE_SUPER_BOWPOSITION && pThis->BowStarted<=TMOVE_SUPER_BOWENDPOSITION)
			{
				// turok has fired the super arrow
				velocity = TMOVE_SUPERBOW_MAXVELOCITY;
			}
			else
			{
				// turok has fired a normal arrow
				if (pThis->BowStarted>TMOVE_NORMAL_BOWMAX)
					pThis->BowStarted=TMOVE_NORMAL_BOWMAX;

				velocity = TMOVE_BOW_MAXVELOCITY*pThis->BowStarted/TMOVE_SUPER_BOWPOSITION;
			}
			vForward.x = 0;
			vForward.y = 0;
			vForward.z = 1;

			vOffset.x = 0.02*SCALING_FACTOR;
			vOffset.y = -0.60*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;

			// get particle position
			D_8001DCF8(CEngineApp__GetPlayer(GetApp()),
																			vOffset,
																			&vParticlePos,
																			&pParticleRegion);

			qRotateDirection = CGameObjectInstance__GetAutoAimRotation(pIns, vParticlePos, NULL, TMOVE_AUTOAIM_ANGLE_TEKBOW);

			CQuatern__ToMatrix(&qRotateDirection, mfRot);
			CMtxF__VectorMult(mfRot, &vForward, &vRotatedForward);
			D_80013C2C(&vBaseVelocity, &vRotatedForward, velocity*15.0);

			if (pThis->ExpTekBowAmmo)
				nType = PARTICLE_TYPE_ARROWEXPLOSIVE;
			else
				nType = PARTICLE_TYPE_ARROW;
			CTMove__LoudNoise(pThis);
			firedArrow = TRUE;
			break;

		case TWEAPON_SEMIAUTOMATICPISTOL:
			vOffset.x = 1.28*SCALING_FACTOR;
			vOffset.y = -1*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;
			nType = PARTICLE_TYPE_BULLET;
			Angle = TMOVE_AUTOAIM_ANGLE_SEMIAUTOMATICPISTOL;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_ASSAULTRIFLE:
			vOffset.x = 1*SCALING_FACTOR;
			vOffset.y = -1*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;
			nType = PARTICLE_TYPE_BULLET;
			Angle = TMOVE_AUTOAIM_ANGLE_ASSAULTRIFLE;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_MACHINEGUN:
			vOffset.x = 1*SCALING_FACTOR;
			vOffset.y = -0.9*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;
			nType = PARTICLE_TYPE_LHGUN_PULSE;
			Angle = TMOVE_AUTOAIM_ANGLE_MACHINEGUN;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_RIOTSHOTGUN:
			vOffset.x = 1.2*SCALING_FACTOR;
			vOffset.y = -0.7*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;
			if (pThis->ExpShotgunPool)
				nType = PARTICLE_TYPE_SHOTGUNEXPLOSIVE;
			else
				nType = PARTICLE_TYPE_SHOTGUN;
			Angle = TMOVE_AUTOAIM_ANGLE_RIOTSHOTGUN;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_AUTOMATICSHOTGUN:
			vOffset.x = 1.2*SCALING_FACTOR;
			vOffset.y = -0.7*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;
			if (pThis->ExpShotgunPool)
				nType = PARTICLE_TYPE_SHOTGUNEXPLOSIVE;
			else
				nType = PARTICLE_TYPE_SHOTGUN;
			Angle = TMOVE_AUTOAIM_ANGLE_AUTOMATICSHOTGUN;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_MINIGUN:
			vOffset.x = 0.8*SCALING_FACTOR;
			vOffset.y = -1*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;
			nType = PARTICLE_TYPE_MINIGUN_BULLET;
			Angle = TMOVE_AUTOAIM_ANGLE_MINIGUN;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_GRENADELAUNCHER:
			vOffset.x = 1.8*SCALING_FACTOR;
			vOffset.y = -0.5*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;
			nType = PARTICLE_TYPE_GRENADE;
			Angle = TMOVE_AUTOAIM_ANGLE_GRENADELAUNCHER;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_TECHWEAPON1:
			vOffset.x = 0.4*SCALING_FACTOR;
			vOffset.y = -1.4*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;
			nType = PARTICLE_TYPE_PLASMA1;
			Angle = TMOVE_AUTOAIM_ANGLE_TECHWEAPON1;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_ROCKET:
			vOffset.x = 0.4*SCALING_FACTOR;
			vOffset.y = -1.4*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;
			nType = PARTICLE_TYPE_ROCKET;
			Angle = TMOVE_AUTOAIM_ANGLE_ROCKET;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_SHOCKWAVE:
			vOffset.x = 0.4*SCALING_FACTOR;
			vOffset.y = -1.4*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;

			if (pThis->ShockwaveStarted < 1.0)
			{
				CScene__DoSoundEffect(&GetApp()->m_Scene, SOUND_GENERIC_190, 0, NULL, &vPos, 0);
				nType = PARTICLE_TYPE_SHOCKWAVEPULSE1;
			}
			else if (pThis->ShockwaveStarted < 2.0)
			{
				CScene__DoSoundEffect(&GetApp()->m_Scene, SOUND_GENERIC_191, 0, NULL, &vPos, 0);
				nType = PARTICLE_TYPE_SHOCKWAVEPULSE2;
			}
			else if (pThis->ShockwaveStarted < 3.0)
			{
				CScene__DoSoundEffect(&GetApp()->m_Scene, SOUND_GENERIC_192, 0, NULL, &vPos, 0);
				nType = PARTICLE_TYPE_SHOCKWAVEPULSE3;
			}
			else if (pThis->ShockwaveStarted < 4.0)
			{
				CScene__DoSoundEffect(&GetApp()->m_Scene, SOUND_GENERIC_193, 0, NULL, &vPos, 0);
				nType = PARTICLE_TYPE_SHOCKWAVEPULSE4;
			}
			else
			{
				CScene__DoSoundEffect(&GetApp()->m_Scene, SOUND_GENERIC_194, 0, NULL, &vPos, 0);
				nType = PARTICLE_TYPE_SHOCKWAVEPULSE5;
			}

			Angle = TMOVE_AUTOAIM_ANGLE_SHOCKWAVE;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_TECHWEAPON2:
			vOffset.x = 0.4*SCALING_FACTOR;
			vOffset.y = -1.4*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;
			nType = PARTICLE_TYPE_PLASMA2;
			Angle = TMOVE_AUTOAIM_ANGLE_TECHWEAPON2;
			CTMove__LoudNoise(pThis);
			break;

		case TWEAPON_CHRONOSCEPTER:
			vOffset.x = 0.4*SCALING_FACTOR;
			vOffset.y = -1.4*SCALING_FACTOR;
			vOffset.z = 2.5*SCALING_FACTOR;

			// hold charge for long enough ?
			if (pThis->ChronoscepterStarted < TMOVE_CHRONOSCEPTER_CHARGE_TIME)
			{
				nParticle = 0;
			}
			else
			{
				nType = PARTICLE_TYPE_CHRONOSCEPTER;
				Angle = TMOVE_AUTOAIM_ANGLE_CHRONOSCEPTER;
				CTMove__LoudNoise(pThis);
			}
			break;

		default:
			ASSERT(FALSE);
		case TWEAPON_NONE:
		case TWEAPON_KNIFE:
		case TWEAPON_TOMAHAWK:
			nParticle=0;
			break;
	}

	// Record fire
	pThis->FiredParticle = TRUE ;
	pThis->FiredParticleType = nType ;


	if (nParticle)
	{
		if (!firedArrow)
		{
			// get particle position
			D_8001DCF8(CEngineApp__GetPlayer(GetApp()),
																			vOffset,
																			&vParticlePos,
																			&pParticleRegion);

			// weapons which auto aim
			if (D_8005A634(pThis, WFired))
				qRotateDirection = CGameObjectInstance__GetAutoAimRotation(pIns, vParticlePos, NULL, Angle);
			else
				qRotateDirection = D_8001D464(pIns);
		}

		// fire particle
		D_80028970(&pApp->m_Scene.m_ParticleSystem, &pIns->ah.ih, nType,
												  vBaseVelocity, qRotateDirection,
												  vParticlePos, pParticleRegion, PARTICLE_NOEDGE, TRUE);

		// Record projectile particle
		pThis->FiredProjectileParticle = TRUE ;
		pThis->FiredProjectileParticleType = nType ;
	}

	// fire out shell from weapon
	switch(WFired)
	{
		// don't do riot shotgun shell yet
		case TWEAPON_RIOTSHOTGUN:
			break;

		// do shell for weapon that has been fired
		default:
			CTMove__FireBulletShell(pThis, WFired);
	}



	// get offset for weapon effect from this weapon
	nParticle=1;
	switch(WFired)
	{
		case TWEAPON_SEMIAUTOMATICPISTOL:
			vOffset.x = 0.65*SCALING_FACTOR;
			vOffset.y = -0.35*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_PISTOL;
			break;

		case TWEAPON_ASSAULTRIFLE:
			vOffset.x = 0.50*SCALING_FACTOR;
			vOffset.y = -0.35*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_ASSAULTRIFLE;
			break;

		case TWEAPON_MACHINEGUN:
			vOffset.x = 0.5*SCALING_FACTOR;
			vOffset.y = -0.2*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_MACHINEGUN;
			break;

		case TWEAPON_RIOTSHOTGUN:
			vOffset.x = 0.65*SCALING_FACTOR;
			vOffset.y = -0.27*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_RIOTSHOTGUN;
			break;

		case TWEAPON_AUTOMATICSHOTGUN:
			vOffset.x = 0.65*SCALING_FACTOR;
			vOffset.y = -0.19*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_AUTOMATICSHOTGUN;
			break;

		case TWEAPON_MINIGUN:
			vOffset.x = 0.45*SCALING_FACTOR;
			vOffset.y = -0.31*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_MINIGUN;
			break;

		case TWEAPON_GRENADELAUNCHER:
			vOffset.x = 1.01*SCALING_FACTOR;
			vOffset.y = -0.05*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_GRENADELAUNCHER;
			break;

		case TWEAPON_TECHWEAPON1:
			vOffset.x = 0.2*SCALING_FACTOR;
			vOffset.y = -0.6*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_TECHWEAPON1;
			break;

		case TWEAPON_ROCKET:
			vOffset.x = 0.2*SCALING_FACTOR;
			vOffset.y = -0.6*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_ROCKET;
			break;

		case TWEAPON_SHOCKWAVE:
			vOffset.x = 0.2*SCALING_FACTOR;
			vOffset.y = -0.6*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_SHOCKWAVEPULSE;
			break;

		case TWEAPON_TECHWEAPON2:
			vOffset.x = 0.2*SCALING_FACTOR;
			vOffset.y = -0.6*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_TECHWEAPON2;
			break;

		case TWEAPON_CHRONOSCEPTER:
			vOffset.x = 0.2*SCALING_FACTOR;
			vOffset.y = -0.6*SCALING_FACTOR;
			vOffset.z = 2.9*SCALING_FACTOR;
			nType = PARTICLE_TYPE_WEFFECT_CHRONOSCEPTER;

			if (pThis->ChronoscepterStarted < TMOVE_CHRONOSCEPTER_CHARGE_TIME)
				nParticle = 0;

			break;

		default:
			ASSERT(FALSE);
		case TWEAPON_NONE:
		case TWEAPON_KNIFE:
		case TWEAPON_TOMAHAWK:
		case TWEAPON_TEKBOW:
			nParticle=0;
			break;
	}


	if (nParticle)
	{
		// get particle position
		D_8001DCF8(CEngineApp__GetPlayer(GetApp()),
																		vOffset,
																		&vParticlePos,
																		&pParticleRegion);

		// weapons which auto aim so there flashes have to be positioned correctly too
		if (D_8005A634(pThis, WFired))
			qRotateDirection = CGameObjectInstance__GetAutoAimRotation(pIns, vParticlePos, NULL, Angle);
		else
			qRotateDirection = D_8001D464(pIns);


		// fire particle
		D_80028970(&pApp->m_Scene.m_ParticleSystem, &pIns->ah.ih, nType,
												  vBaseVelocity, qRotateDirection,
												  vParticlePos, pParticleRegion, PARTICLE_NOEDGE, TRUE);
	}
}

