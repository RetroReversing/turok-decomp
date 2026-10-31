#include "common_local_source_4823.h"

#line 5055 "reference.c"
void func_8005A670 ( CTMove *pThis, int WFired )
{
	CEngineApp				*pApp;
	CGameObjectInstance	*pIns;
	DWORD						nType;
	CVector3					vBaseVelocity,
								vOffset,
								vPos,
								vParticlePos;
	CQuatern					qRotateDirection;
	CGameRegion				*pParticleRegion;
	int						nParticle;
	float						Angle;


	// get pointer to engine app
	pApp = GetApp();
	if (pApp == NULL) return;

	// get instance pointer to turok
	pIns = CEngineApp__GetPlayer(pApp);
	if (pIns == NULL) return;

	// do weapon projectile particle fire (straight ahead out of gun)
	vBaseVelocity.x = vBaseVelocity.y = vBaseVelocity.z = 0;

	// do weapon projectile for shell coming out of weapon
	// get offset for particle from this weapon
	nParticle=1;
	switch ( WFired )
	{
		case TWEAPON_SEMIAUTOMATICPISTOL:
			vOffset.x = 1*SCALING_FACTOR;
			vOffset.y = -1*SCALING_FACTOR;
			vOffset.z = 2.7*SCALING_FACTOR;
			nType = PARTICLE_TYPE_BULLET_SHELL;
			Angle = TMOVE_AUTOAIM_ANGLE_SEMIAUTOMATICPISTOL;
			break;

		case TWEAPON_ASSAULTRIFLE:
			vOffset.x = 1*SCALING_FACTOR;
			vOffset.y = -1*SCALING_FACTOR;
			vOffset.z = 2.7*SCALING_FACTOR;
			nType = PARTICLE_TYPE_BULLET_SHELL;
			Angle = TMOVE_AUTOAIM_ANGLE_ASSAULTRIFLE;
			break;

		case TWEAPON_RIOTSHOTGUN:
			vOffset.x = 1.1*SCALING_FACTOR;
			vOffset.y = -0.8*SCALING_FACTOR;
			vOffset.z = 2.7*SCALING_FACTOR;


			vPos.x  = AW.Ears.vPos.x;
			vPos.y  = AW.Ears.vPos.y;
			vPos.z  = AW.Ears.vPos.z;
			func_80031974(&GetApp()->m_Scene,
										 SOUND_READY_SHOTGUN, 1,
										 pIns, &vPos, 0);
	      //here

			if (pThis->ExpShotgunPool)
				nType = PARTICLE_TYPE_SHOTGUN_EXPLOSIVE_SHELL;
			else
				nType = PARTICLE_TYPE_SHOTGUN_SHELL;

			Angle = TMOVE_AUTOAIM_ANGLE_RIOTSHOTGUN;
			break;

		case TWEAPON_AUTOMATICSHOTGUN:
			vOffset.x = 1.4*SCALING_FACTOR;
			vOffset.y = -1.2*SCALING_FACTOR;
			vOffset.z = 2.7*SCALING_FACTOR;

			vPos.x  = AW.Ears.vPos.x;
			vPos.y  = AW.Ears.vPos.y;
			vPos.z  = AW.Ears.vPos.z;
			func_80031974(&GetApp()->m_Scene,
										 SOUND_RELOAD_AUTO_SHOTGUN, 1,
										 pIns, &vPos, 0);

			if (pThis->ExpShotgunPool)
				nType = PARTICLE_TYPE_SHOTGUN_EXPLOSIVE_SHELL;
			else
				nType = PARTICLE_TYPE_SHOTGUN_SHELL;

			Angle = TMOVE_AUTOAIM_ANGLE_AUTOMATICSHOTGUN;
			break;

		case TWEAPON_MINIGUN:
			vOffset.x = 1*SCALING_FACTOR;
			vOffset.y = -1*SCALING_FACTOR;
			vOffset.z = 2.7*SCALING_FACTOR;
			nType = PARTICLE_TYPE_BULLET_SHELL;
			Angle = TMOVE_AUTOAIM_ANGLE_MINIGUN;
			break;

		case TWEAPON_MACHINEGUN:
		case TWEAPON_TEKBOW:
		case TWEAPON_GRENADELAUNCHER:
		case TWEAPON_TECHWEAPON1:
		case TWEAPON_ROCKET:
		case TWEAPON_SHOCKWAVE:
		case TWEAPON_TECHWEAPON2:
		case TWEAPON_CHRONOSCEPTER:
			nParticle=0;
			break;

		default:
			ASSERT(FALSE);
	}


	if (nParticle)
	{
		// get particle position
		CGameObjectInstance__GetOffsetPositionAndRegion(CEngineApp__GetPlayer(GetApp()),
																		vOffset,
																		&vParticlePos,
																		&pParticleRegion);

		if (CTMove__DoesWeaponAutoAim(pThis, WFired))
			qRotateDirection = func_8001D8F0(pIns, vParticlePos, NULL, Angle);
		else
			qRotateDirection = CGameObjectInstance__GetAimRotation(pIns);

		// shoot shell
		CParticleSystem__CreateParticle(&pApp->m_Scene.m_ParticleSystem, &pIns->ah.ih, nType,
												  vBaseVelocity, qRotateDirection,
												  vParticlePos, pParticleRegion, PARTICLE_NOEDGE, TRUE);
	}
}
