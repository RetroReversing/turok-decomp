#include "common_local_source_4845.h"

#line 6281 "reference.c"
void func_8005CEBC(CTMove *pThis, CEngineApp *pApp, CTControl *pCTControl)
{
	float						botCliff,
								topCliff,
								dm,
								ang;
	CGameRegion				*pRegion;
	CGameObjectInstance	*pPlayer;


	// get current region player is in
	pPlayer = CEngineApp__GetPlayer(GetApp());
	ASSERT(pPlayer);

	pRegion = pPlayer->ah.ih.m_pCurrentRegion;
	if (!pRegion) return;

	func_80055768(pThis);


#define	TMOVE_PLAYER_BCLIFF		(6*SCALING_FACTOR)
#define	TMOVE_PLAYER_TCLIFF		(18*SCALING_FACTOR)//(25*SCALING_FACTOR)


	// if player is not on the ground don't do any climbing camera stuff
	if (!func_8001D3DC(&pPlayer->ah.ih))
		return;

	// get heights
	botCliff = CEngineApp__GetPlayerHeightFromBottomOfCliff(pApp);
	topCliff = CEngineApp__GetPlayerHeightFromTopOfCliff(pApp);

	if (botCliff<0 || topCliff<0)
		return;

	// are we at the bottom of the cliff ?
	if (pThis->OnLadder)
	{
		// player is on a ladder
		if (topCliff <= TMOVE_PLAYER_TCLIFF)
		{
			// player at top of ladder
			pThis->ActualRotXPlayer  = ANGLE_DTOR( 75) * topCliff / TMOVE_PLAYER_TCLIFF;
			pThis->ActualRotXPlayer += ANGLE_DTOR(-30) * (TMOVE_PLAYER_TCLIFF-topCliff) / TMOVE_PLAYER_TCLIFF;
		}
		else
		{
			// player at bottom or in middle of ladder
			pThis->ActualRotXPlayer = ANGLE_DTOR(75);
		}
	}
	else if (botCliff <= TMOVE_PLAYER_BCLIFF)
	{
		// player at bottom of cliff
		pThis->ActualRotXPlayer = ANGLE_DTOR(90) * (botCliff/TMOVE_PLAYER_BCLIFF);
	}
	else if (topCliff <= TMOVE_PLAYER_TCLIFF)
	{
		// player at top of cliff
		pThis->ActualRotXPlayer  = ANGLE_DTOR( 90) * topCliff / TMOVE_PLAYER_TCLIFF;
		pThis->ActualRotXPlayer += ANGLE_DTOR(-50) * (TMOVE_PLAYER_TCLIFF-topCliff) / TMOVE_PLAYER_TCLIFF;
	}
	else
	{
		// player somewhere in middle of the cliff
		pThis->ActualRotXPlayer = ANGLE_DTOR(90);
	}

	// make player orientate towards the cliff
	pThis->ActualRotYPlayer = pThis->ClimbSideStepLookAng;
	ang = func_80013620(pPlayer->m_RotY, func_80020638(pRegion));
	ang = (0 - ang) / 12;
	pPlayer->m_RotY += ang;

	if (pThis->ClimbSideStep)
	{
		// make head tilt down as player side steps left & right on cliff face
		ang  = ANGLE_RTOD(pThis->ActualRotYPlayer);
		if (ang < -110) ang = -110;
		if (ang >  110) ang =  110;
		if (ang <   0) ang = -ang;
		pThis->ActualRotXPlayer += ANGLE_DTOR(-ang*1.2);
	}

	// allow player to look left & right while on ladder & moving
	if (pThis->OnLadder)
	{
		ang = ANGLE_DTOR(90) - pThis->ActualRotYPlayer;
		pThis->ActualRotYPlayer += CTControl__IsClimbLookRight(pCTControl)*ang/80;

		ang = pThis->ActualRotYPlayer + ANGLE_DTOR(90);
		pThis->ActualRotYPlayer -= CTControl__IsClimbLookLeft(pCTControl)*ang/80;

		// make head tilt down as player looks left or right
		ang  = ANGLE_RTOD(pThis->ActualRotYPlayer);
		if (ang < -110) ang = -110;
		if (ang >  110) ang =  110;
		if (ang <   0) ang = -ang;
		pThis->ActualRotXPlayer += ANGLE_DTOR(-ang);

		// do up & down
		ang = ANGLE_DTOR(110) - pThis->ActualRotXPlayer;
		pThis->ActualRotXPlayer += CTControl__IsLookDown(pCTControl)*ang / 80;

		ang = pThis->ActualRotXPlayer + ANGLE_DTOR(90);
		pThis->ActualRotXPlayer -= CTControl__IsLookUp(pCTControl)*ang / 80;
	}
	// allow player to look left & right while on cliff while they are not moving
	else if (!pThis->ClimbOneHand && !pThis->ClimbSideStep)
	{
		// left hand holding on can look more to the right
		ang = ANGLE_DTOR(200) - pThis->ActualRotYPlayer;
		pThis->ActualRotYPlayer += CTControl__IsClimbLookRight(pCTControl)*ang/80;

		ang = pThis->ActualRotYPlayer + ANGLE_DTOR(200);
		pThis->ActualRotYPlayer -= CTControl__IsClimbLookLeft(pCTControl)*ang/80;

//		pThis->ActualRotYPlayer  = CTControl__IsClimbLookRight(pCTControl)*ANGLE_DTOR( 270)/80;
//		pThis->ActualRotYPlayer += CTControl__IsClimbLookLeft (pCTControl)*ANGLE_DTOR(-100)/80;

		// make head tilt down as player looks left or right
		ang  = ANGLE_RTOD(pThis->ActualRotYPlayer);
		if (ang < -110) ang = -110;
		if (ang >  110) ang =  110;
		if (ang <   0) ang = -ang;
		pThis->ActualRotXPlayer += ANGLE_DTOR(-ang);

		// do up & down
		ang = ANGLE_DTOR(110) - pThis->ActualRotXPlayer;
		pThis->ActualRotXPlayer += CTControl__IsLookDown(pCTControl)*ang / 80;

		ang = pThis->ActualRotXPlayer + ANGLE_DTOR(90);
		pThis->ActualRotXPlayer -= CTControl__IsLookUp(pCTControl)*ang / 80;
	}

	// set head rotation
	dm = (pThis->ActualRotXPlayer - pThis->RotXPlayer) / 12;
	pThis->RotXPlayer += dm * frame_increment * 2;

	dm = (pThis->ActualRotYPlayer - pThis->RotYPlayer) / 12;
	pThis->RotYPlayer += dm * frame_increment * 2;

}
