#include "common_local_source_4242.h"

#line 2 "reference.c"
void func_80037EEC(CCamera *pThis)
{
	//Mtx						mProjection[2];
	CMtxF						mfLookAt,
								mfHead, mfEye, mfGround, mfPos,
								mfRot180, mfViewMat, mfView,
								mfTemp1, mfTemp2,
								mfPerspective, mfFlipX,
								mfDirection ;
	CQuatern					qRotX, qRotY, qRotZ,
								qTemp1, qTemp2;
	float 					viewLength;
	CVector3					vCorners[5] ;
	int						i;
	CFrameData				*pFData;
	LookAt					*pl;
	FLOAT						fov, aspect, speed, blend ;

	CEngineApp				*pEngine;

	FLOAT  					RotY,
								RotXOffset, RotYOffset, RotZOffset,
								XPos, YPos, ZPos,
								YPosOffset ;
	CQuatern					qGround ;

	FLOAT						Chop ;

	pEngine = GetApp();

	// Do warp fx
	func_80037B3C(pThis) ;

	// Attract mode just finished?
	if (pEngine->m_CinemaFlags == -1)
		pThis->m_StartPressed = FALSE ;

	// Update movement ai
	if (CameraModeTable[pThis->m_Mode].Function)
		CameraModeTable[pThis->m_Mode].Function(pThis) ;

	// Clear vars
	pThis->m_NextCinematicStage = FALSE ;
	pThis->m_StartPressed = FALSE ;

	// Get current frame for correct view matrix and lookat structure
	pFData = CEngineApp__GetFrameData(pEngine);
	pl = &pFData->m_LookAt;
	guLookAtF(mfLookAt,
				 0, 0, 0,	// eye position
				 0, 0, 1,	// target position
				 0, 1, 0);	// up normal

	// Prepare engine variables during cinematic mode
	if (pThis->m_CinemaMode)
	{
		// Call collision to move turok during cinematics
		func_800396F8(pThis) ;
		CTurokMovement.DeathStage = TMOVE_HEALTH_ALIVE ;

		// Acclaim logo is special case!!
		if (pThis->m_Mode == CAMERA_INTRO_ACCLAIM_LOGO_MODE)
		{
			// Setup eye/focus view
			func_800378B8(&pThis->m_ViewA) ;

			// Blend eye/rotation biew
			func_80039368(&pThis->m_View, pThis->m_ViewBlend, &pThis->m_ViewA, &pThis->m_ViewB) ;
		}
		else
			func_800378B8(&pThis->m_View) ;


//		rmonPrintf("Rot x,y,z: %f,%f,%f\r\n",
//					  ANGLE_RTOD(vRotation.x),
//					  ANGLE_RTOD(vRotation.y),
//					  ANGLE_RTOD(vRotation.z)) ;

		// Set track rotation vars
		RotXOffset = pThis->m_View.m_vRotation.x ;
		RotY = pThis->m_View.m_vRotation.y ;
		RotYOffset = 0 ;
		RotZOffset = pThis->m_View.m_vRotation.z ;
		CQuatern__Identity(&qGround) ;

		// Set track position vars
		XPos = pThis->m_View.m_vEye.x ;
		YPos = pThis->m_View.m_vEye.y ;
		YPosOffset = 0 ;
		ZPos = pThis->m_View.m_vEye.z ;
	}
	else
	{
		// Engine view from turok's eyes
		RotY = pEngine->m_RotY ;
		RotYOffset = pEngine->m_RotYOffset ;
		RotXOffset = pEngine->m_RotXOffset ;
		RotZOffset = -pEngine->m_RotZOffset ;
		XPos = pEngine->m_XPos ;
		YPos = pEngine->m_YPos ;
		YPosOffset = pEngine->m_YPosOffset ;
		ZPos = pEngine->m_ZPos ;
		qGround =  pEngine->m_qGround ;
	}

	// Add tremor
	RotXOffset += pThis->m_vTremor.x ;
	YPos += pThis->m_vTremor.y ;
	RotZOffset += pThis->m_vTremor.z ;

	// Add warp spin - THIS CRASHES LEVEL 4!!!!!
//	RotZOffset += pThis->m_WarpSpin ;

	// Calculate head rotation
	CQuatern__BuildFromAxisAngle(&qRotZ, 0,0,1, RotZOffset) ;
	CQuatern__BuildFromAxisAngle(&qRotX, 1,0,0, RotXOffset) ;
	CQuatern__BuildFromAxisAngle(&qRotY, 0,1,0, RotY + RotYOffset) ;

	func_80014CB8(&qTemp1, &qRotX, &qRotY) ;
	func_80014CB8(&pEngine->m_qViewAlignNoZ, &qTemp1, &qGround) ;							// used to make particles face screen
	func_80014CB8(&pEngine->m_qViewAlign, &qRotZ, &pEngine->m_qViewAlignNoZ) ;	// used to make particles face screen

	func_80014CB8(&qTemp2, &qRotZ, &qTemp1) ;
	func_80014DC4(&qTemp2, mfHead) ;

	// Store camera position for ears
	pThis->m_vPos.x = XPos ;
	pThis->m_vPos.y = YPos+YPosOffset ;
	pThis->m_vPos.z = ZPos ;

	// Store camera rotation for ears
	pThis->m_vRotation.x = RotXOffset ;
	pThis->m_vRotation.y = RotY ;
	pThis->m_vRotation.z = RotZOffset ;



	// Eye heaight
	func_80015578(mfEye, 0, YPosOffset, 0) ;

	// Ground rot
	func_80014DC4(&qGround, mfGround) ;

	// Player pos + screen shake
	XPos += func_80037728(&pThis->m_ShakeX) ;
	YPos += func_80037728(&pThis->m_ShakeY) ;
	ZPos += func_80037728(&pThis->m_ShakeZ) ;
	func_80015578(mfPos, XPos, YPos, ZPos) ;

	// view orient
	func_80013224(mfTemp1, mfHead, mfEye) ;
	func_80013224(mfTemp2, mfTemp1, mfGround) ;

	func_80013224(pEngine->m_mfViewOrient, mfTemp2, mfPos) ;
	func_80012E6C(mfRot180, ANGLE_PI) ;
	func_80013224(mfTemp1, mfRot180, pEngine->m_mfViewOrient) ;
	func_80014FAC(mfViewMat, mfTemp1) ;

	// projection
	func_80013224(mfView, mfViewMat, mfLookAt) ;

#if WATER_WOBBLE
	// Add under water camera wobble
	if (		(CTurokMovement.WaterFlag == PLAYER_BELOW_WATERSURFACE)
			&&	(!CTurokMovement.InAntiGrav)
			&&	(!pThis->m_CinemaMode) )
	{
		// Perform shm
		pThis->m_XScale = 1+ (pThis->m_WaterWobbleXScale * ((1 + sin(pThis->m_WaterWobbleXAngle)) * 0.5)) ;
		pThis->m_YScale = 1+ (pThis->m_WaterWobbleYScale * ((1 + sin(pThis->m_WaterWobbleYAngle)) * 0.5)) ;
		pThis->m_WaterWobbleXAngle += frame_increment * pThis->m_WaterWobbleXSpeed ;
		pThis->m_WaterWobbleYAngle += frame_increment * pThis->m_WaterWobbleYSpeed ;

		// Get wobble speed from turok's speed
		speed = func_8005E6A4(&CTurokMovement) * 2.5 ;
		if (speed < 0)
			speed = 0 ;
		else
		if (speed > 1)
			speed = 1 ;


		// Zoom to under water vars
		func_80040B54(&pThis->m_WaterWobbleXScale,
										 CAMERA_UNDER_WATER_WOBBLE_X_SCALE,
										 CAMERA_ZOOM_TO_UNDER_WATER_WOBBLE_SCALE) ;

		func_80040B54(&pThis->m_WaterWobbleYScale,
										 CAMERA_UNDER_WATER_WOBBLE_Y_SCALE,
										 CAMERA_ZOOM_TO_UNDER_WATER_WOBBLE_SCALE) ;

		func_80040B54(&pThis->m_WaterWobbleXSpeed,
										 (speed * CAMERA_UNDER_WATER_WOBBLE_X_FAST_SPEED) +
										 ((1-speed) * CAMERA_UNDER_WATER_WOBBLE_X_SLOW_SPEED),
										 CAMERA_ZOOM_TO_UNDER_WATER_WOBBLE_SPEED) ;

		func_80040B54(&pThis->m_WaterWobbleYSpeed,
										 (speed * CAMERA_UNDER_WATER_WOBBLE_Y_FAST_SPEED) +
										 ((1-speed) * CAMERA_UNDER_WATER_WOBBLE_Y_SLOW_SPEED),
										 CAMERA_ZOOM_TO_UNDER_WATER_WOBBLE_SPEED) ;
	}
	else
#endif
		pThis->m_XScale = pThis->m_YScale = 1 ;

#if TEST_LETTERBOX_VIEW
	pThis->m_LetterBoxScale = LETTERBOX_SCALE ;
#endif

	// Setup field of view and aspect ratio
	fov = pEngine->m_FieldOfView*pThis->m_YScale ;

	// Keep pixels square
	aspect = (SCREEN_WD*pThis->m_XScale)/(SCREEN_HT*pThis->m_YScale*(1-pThis->m_LetterBoxScale)) ;

	// Keep x scale at 1
//	aspect = (SCREEN_WD*pThis->m_XScale)/(SCREEN_HT*pThis->m_YScale) ;

	// Keep copy
	pThis->m_Fov = fov ;
	pThis->m_AspectRatio = aspect ;

	// Perspective
	guPerspectiveF(mfPerspective, &pThis->m_PerspNorm,
						fov,							// field of view
						aspect,						// aspect ratio
						SCALING_NEAR_CLIP,		// near clip
						pEngine->m_FarClip,	// far clip
						1);							// precision scaler

	CMtxF__Scale(mfFlipX, -1, 1, 1);


	func_80015910(mfTemp1, mfView, mfPerspective);
	func_80015910(pEngine->m_mfProjection, mfTemp1, mfFlipX);

	//CMtxF__ToMtx(pEngine->m_mfProjection, mProjection[even_odd]);

	func_80015800(pEngine->m_mfProjection) ;
	CMtxF__ToMtx(pEngine->m_mfProjection, pFData->m_mProjection);

	// Update letter box
	Chop = SCREEN_HT * (pThis->m_LetterBoxScale/2) ;
	pThis->m_LetterBoxTop = Chop ;
	pThis->m_LetterBoxBottom = SCREEN_HT - Chop ;

	// Extract lookat from mfView
	CMtxF__Copy(mfDirection, mfView) ;

	// Rotate view direction for acclaim logo to keep reflection map moving
	if (pThis->m_Mode == CAMERA_INTRO_ACCLAIM_LOGO_MODE)
	{
		// Make blend go from 0 to 1
		blend = pThis->m_StageTime / SECONDS_TO_FRAMES(2.8) ;
		blend = COSINE_TWEEN(blend) ;

		func_80012C48(mfDirection, ANGLE_DTOR((blend*30) + (game_frame_number*0.5))) ;
		func_80012AB0(mfDirection, ANGLE_DTOR((blend*50) + (-game_frame_number*0.4))) ;
	}

	func_80015800(mfDirection) ;
	pl->l[0].l.dir[0] = FTOFRAC8(mfDirection[0][0]);
	pl->l[0].l.dir[1] = FTOFRAC8(mfDirection[1][0]);
	pl->l[0].l.dir[2] = FTOFRAC8(mfDirection[2][0]);
	pl->l[1].l.dir[0] = FTOFRAC8(mfDirection[0][1]);
	pl->l[1].l.dir[1] = FTOFRAC8(mfDirection[1][1]);
	pl->l[1].l.dir[2] = FTOFRAC8(mfDirection[2][1]);
	pl->l[0].l.col[0] = 0x00;
	pl->l[0].l.col[1] = 0x00;
	pl->l[0].l.col[2] = 0x00;
	pl->l[0].l.pad1 = 0x00;
	pl->l[0].l.colc[0] = 0x00;
	pl->l[0].l.colc[1] = 0x00;
	pl->l[0].l.colc[2] = 0x00;
	pl->l[0].l.pad2 = 0x00;
	pl->l[1].l.col[0] = 0x00;
	pl->l[1].l.col[1] = 0x80;
	pl->l[1].l.col[2] = 0x00;
	pl->l[1].l.pad1 = 0x00;
	pl->l[1].l.colc[0] = 0x00;
	pl->l[1].l.colc[1] = 0x80;
	pl->l[1].l.colc[2] = 0x00;
	pl->l[1].l.pad2 = 0x00;

//////////////////////////////////
//	// Should be off for specular highlights
//	gSPLookAt(pEngine->m_pDLP++, RSP_ADDRESS(pl));
//////////////////////////////////


	// Calculate view region (used for clipping)
	viewLength = SCALING_MAX_DIST(pEngine->m_FarClip, FIELD_OF_VIEW_ANGLE(fov, aspect));

	vCorners[0].x = 0;
	vCorners[0].y = 0;
	vCorners[0].z = 0;

	vCorners[1].x = viewLength*sin(ANGLE_DTOR(FIELD_OF_VIEW_ANGLE(fov, aspect)/2.0));
	vCorners[1].y = vCorners[1].x*aspect;
	vCorners[1].z = -pEngine->m_FarClip;

	vCorners[2].x = -vCorners[1].x;
	vCorners[2].y = vCorners[1].y;
	vCorners[2].z = vCorners[1].z;

	vCorners[3].x = vCorners[1].x;
	vCorners[3].y = -vCorners[1].y;
	vCorners[3].z = vCorners[1].z;

	vCorners[4].x = -vCorners[1].x;
	vCorners[4].y = -vCorners[1].y;
	vCorners[4].z = vCorners[1].z;

	for (i=0; i<5; i++)
		func_80015754(pEngine->m_mfViewOrient, &vCorners[i], &pEngine->m_vTCorners[i]);

	func_800847F0(&view_volume,
											&pEngine->m_vTCorners[0],
											&pEngine->m_vTCorners[1], &pEngine->m_vTCorners[2],
											&pEngine->m_vTCorners[3], &pEngine->m_vTCorners[4]);

	// Rectangle enclosing view region
	CBoundsRect__EncloseVectors(&view_bounds_rect, 5, pEngine->m_vTCorners);

	// Animate objects within FAR_CLIP in all directions
	D_800F9E30.m_MinX = pEngine->m_vTCorners[0].x - viewLength;
	D_800F9E30.m_MaxX = pEngine->m_vTCorners[0].x + viewLength;
	D_800F9E30.m_MinZ = pEngine->m_vTCorners[0].z - viewLength;
	D_800F9E30.m_MaxZ = pEngine->m_vTCorners[0].z + viewLength;
}
