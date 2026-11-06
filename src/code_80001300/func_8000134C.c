#include "decompdecomp_sync_4b7546230e1cb96ad526.h"
#line 1 "func.c"
void CEngineApp__Boot(CEngineApp *); /* Address alias retains the observed caller ABI; the canonical entry is CEngineApp__Idle. */ int sub_80001D30(CEngineApp *,s32);
void func_80001300(void) {
    CEngineApp__Boot(&D_800F9F10);
}
void idle(s32 pArg) {
    sub_80001D30(&D_800F9F10,pArg);
}
#line 430 "reference.c"
void func_8000134C(void *pArg)
{
	OSMesg				msg = NULL;		// supresses warning
	OSTime				startTime;
	int					fpstat;
	OSThread				*curr;
	CGameObjectInstance *pPlayer ;
	//static OSThread	*curr, *last;


	osSetEventMesg(OS_EVENT_FAULT, &D_800F9870, (OSMesg) MSG_FAULT);


	// fetch the current floating-point control/status register
	fpstat = __osGetFpcCsr();

	// enable divide-by-zero exception for floating point
	fpstat |= (short)FPCSR_EZ;

	// _Disable_ unimplemented operation exception for floating point.
	// The trunc.w.s instruction causes this exception when the input
	// value is larger than the maximum fixed point value.  This is
	// can happen in the game, so I'm disabling the exception.
	//fpstat &= ~(FPCSR_CE | FPCSR_FS | FPCSR_EV | FPCSR_FI | FPCSR_RM_RN);
	//fpstat &= ~FPCSR_CE;
	//fpstat = 0;

	__osSetFpcCsr(fpstat);

	//last = (OSThread*) NULL;

	while (TRUE)
	{
		osRecvMesg(&D_800F9870, (OSMesg*) &msg, OS_MESG_BLOCK);

              
	// create the persistant data block
	if (		D_800B6B38
			&& (GetApp()->m_Mode == MODE_GAME)
			&& CEngineApp__GetPlayer(GetApp()) )
	{
		pPlayer = CEngineApp__GetPlayer(GetApp());

		if (D_800B6AF0 > 150)
		{
			D_8014F660 = 0x4341524c ;
			func_8000E9BC() ;
		}
		else
			D_8014F660 = 0x4341524d ;

		//CrashMode = GetApp()->m_Mode ;

		//CrashFrame = game_frame_number ;

		D_8014F670.m_vPos = pPlayer->ah.ih.m_vPos;
		D_8014F670.m_RotY = pPlayer->m_RotY;
		D_8014F670.m_nLevel = GetApp()->m_Scene.m_nLevel;
		if (pPlayer->ah.ih.m_pCurrentRegion)
			D_8014F670.m_nRegion = ((DWORD)pPlayer->ah.ih.m_pCurrentRegion - (DWORD)D_8011A610)/sizeof(CGameRegion);
		else
			D_8014F670.m_nRegion = -1;
	}
	else
	{
		D_8014F660 = 0;
	}
/*

	pPlayer = CEngineApp__GetPlayer(GetApp());
	if (pPlayer)
	{
		CrashId = 0x4341524c ;
		CSave__PrepareData() ;
		CrashMode = GetApp()->m_Mode ;

		CrashFrame = game_frame_number ;

		CrashWarp.m_vPos = pPlayer->ah.ih.m_vPos;
		CrashWarp.m_RotY = pPlayer->m_RotY;
		CrashWarp.m_nLevel = GetApp()->m_Scene.m_nLevel;
		if (pPlayer->ah.ih.m_pCurrentRegion)
			CrashWarp.m_nRegion = ((DWORD)pPlayer->ah.ih.m_pCurrentRegion - (DWORD)p_regions)/sizeof(CROMRegion);
		else
			CrashWarp.m_nRegion = -1;
	}
*/
	osWritebackDCacheAll();


	osSetIntMask(OS_IM_NONE) ;
	((pfnReboot)0x80000400)() ;
      
//#else

		// returns the most recent faulted thread
		curr = func_8009D2C0();

		if (D_800EC0B4 == THREAD_MAIN)
			curr = &D_800F9280;

		if (curr)
		{
			// wait for 1 second for display lists to finish up
			startTime = osGetTime();

			while ((__ull_to_f(CYCLES_TO_NSEC(osGetTime() - startTime))/1000000) < 2);

			if (D_80000300 == 0)
				osViSetMode(&osViModeTable[OS_VI_PAL_HPF1]);
			else if (D_80000300 == 1)
				osViSetMode(&osViModeTable[OS_VI_NTSC_HPF1]);
			else
				osViSetMode(&osViModeTable[OS_VI_MPAL_HPF1]);


			osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
			osViSwapBuffer(D_80200000);

			printFaultData(curr);

			while (TRUE);

			// recover?
		}

//#endif
	}
}

