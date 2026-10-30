#include "common_local_source_4824.h"

#line 5192 "reference.c"
void func_8005A9F8(CTMove *pThis, CEngineApp *pApp, CTControl *pCTControl)
{
	// declare variables
	float						dm,
								sinSideY,
								cosSideY;
	int						waterFlag;
	CVector3					vDesiredPos;
	CGameObjectInstance	*pIns;


	// get instance pointer to turok
	pIns = CEngineApp__GetPlayer(pApp);
	if (pIns == NULL) return;

	// initialize current position into desired position before we change it
	vDesiredPos = pIns->ah.ih.m_vPos;

	// calculate sin & cos for side stepping right direction
	sinSideY = sin(pIns->m_RotY - ANGLE_PI/2);
	cosSideY = cos(pIns->m_RotY - ANGLE_PI/2);


	// if player is underwater make keel over slower
	waterFlag = CEngineApp__GetPlayerWaterStatus(pApp);
	switch (waterFlag)
	{
		case	PLAYER_BELOW_WATERSURFACE:
			pThis->HeadZRot += ANGLE_DTOR(0.1*frame_increment);
			pThis->HeadXRot += ANGLE_DTOR(0.1*frame_increment);
			pThis->HeadYRot += ANGLE_DTOR(0.1*frame_increment);

			CAnimInstanceHdr__Collision3(&pIns->ah, vDesiredPos, &ci_playerunderwater);
			pThis->pLastCI = &ci_playerunderwater;
			break;

		case	PLAYER_ON_WATERSURFACE:
			// make camera rotate on z all way over
			if (pThis->HeadZRot >= 0)
			{
				dm = ((ANGLE_PI/8) - pThis->HeadZRot) / 8;
				pThis->HeadZRot += dm;
				vDesiredPos.x += dm*frame_increment * sinSideY;
				vDesiredPos.z += dm*frame_increment * cosSideY;
			}
			else
			{
				dm = ((-ANGLE_PI/8) - pThis->HeadZRot) / 8;
				pThis->HeadZRot += dm;
				vDesiredPos.x += dm*frame_increment * sinSideY;
				vDesiredPos.z += dm*frame_increment * cosSideY;
			}

			CAnimInstanceHdr__Collision3(&pIns->ah, vDesiredPos, &ci_playeronwatersurface);
			pThis->pLastCI = &ci_playeronwatersurface;
			break;

		default:
			// make camera rotate on z all way over
			if (pThis->HeadZRot >= 0)
			{
				dm = ((+ANGLE_PI/8) - pThis->HeadZRot) / 8;
				pThis->HeadZRot += dm;
				vDesiredPos.x += dm*frame_increment * sinSideY;
				vDesiredPos.z += dm*frame_increment * cosSideY;
			}
			else
			{
				dm = ((-ANGLE_PI/8) - pThis->HeadZRot) / 8;
				pThis->HeadZRot += dm;
				vDesiredPos.x += dm*frame_increment * sinSideY;
				vDesiredPos.z += dm*frame_increment * cosSideY;
			}

			CAnimInstanceHdr__Collision3(&pIns->ah, vDesiredPos, &ci_player);
			pThis->pLastCI = &ci_player;
			break;
	}

	// Update timer all the time just incase of a dodgy lockup
	CTMove__UpdateDeathTimer(pThis);
	if (func_8005ADF4(pThis))
		CEngineApp__DoDeath(pApp);
}
