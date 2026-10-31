#include "source_func_8008CFC0.h"

#line 1062 "reference.c"
void func_8008CFC0()
{
	static	int	SoundCount = 0;
	static	int	CurtainUp = 0;
	static	int	CurrentSound = 0;
	static	int	CurrentDelay = 0;
	static INT16	PrevSound, PrevPrevSound;
	static INT16	*pSoundScene = D_800ED1FC;
	static	int	SoundSceneCounter = 0;
	//int				dwFlags;


	if (!cache_is_valid)
		return;

	if((AW.sfx_timer%(15)) != 0)
		return;

	SoundSceneCounter++;

//	if (!audio_ambient_flags)
//		return ;

	//dwFlags = audio_ambient_flags;

	if (		(CTurokMovement.AmbientSound == REG_AMBIENTCAVES)
			||	(		(CTurokMovement.WaterFlag == PLAYER_BELOW_WATERSURFACE)
					&&	(!CTurokMovement.InAntiGrav) )
			||	(CTMove__IsInCombat(&CTurokMovement)) )
	{
		CurtainUp = 0;
		return;
	}

/*	if((dwFlags & REGFLAG_AMBIENTCAVES) || (CTurokMovement.WaterFlag == PLAYER_BELOW_WATERSURFACE) || (CTMove__IsInCombat(&CTurokMovement)))
 	{
		CurtainUp = 0;
		return;
	}
*/

	if((CheckProbability(10) == TRUE)&& (SoundSceneCounter%20 == 0) && !CurtainUp)
	//if(((AW.sfx_timer%(60*6)) == 0) && !CurtainUp)
	{
		//rmonPrintf("SoundScene started...\n");
		pSoundScene = D_800ED1FC + (8*SOUND_RANDOM(MAX_SOUND_SCENES));
		CurtainUp = 1;
		CurrentDelay = 0;
		SoundCount = 0;
		PrevSound = 0;
		PrevPrevSound = 0;
	}

	if(CurtainUp)
	{
		if(CurrentDelay <= 0)
		{
			PrevSound = CurrentSound ;
			PrevPrevSound = PrevSound ;

			if(SoundCount == 6)
				CurrentSound = pSoundScene[7];
			else
				CurrentSound = pSoundScene[SOUND_RANDOM(6)];

			// three in a row sounds bad
			if((PrevPrevSound == PrevSound) && (PrevPrevSound == CurrentSound) && (SoundCount >= 3))
				CurrentSound = pSoundScene[SOUND_RANDOM(6)];

			func_80031974(&GetApp()->m_Scene, CurrentSound, 0, NULL, &AW.Ears.vPos, AMB_SCENE_POSITION);
			SoundCount++;
			//CurrentDelay = RANDOM(90);
			CurrentDelay = SOUND_RANDOM(6);
		}
		else
			CurrentDelay--;

		if((SoundCount == 7) && (CurrentDelay == 0))
		{
			CurtainUp = 0;
			//rmonPrintf("SoundScene done...\n");
		}
	}
}
