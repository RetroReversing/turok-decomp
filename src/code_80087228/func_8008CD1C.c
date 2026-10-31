#include "source_func_8008CD1C.h"

#line 942 "reference.c"
void func_8008CD1C()
{
	t_AmbientSounds		*pSoundList = D_800ECF94;
	int						s, Prob ;
	static int				ambient_timer = 0;
	int						rand_type;

	if (!cache_is_valid)
		return;

	if((ambient_timer % AMBIENT_SOUND_RATE) != 0)
	{
		ambient_timer++;
		return;
	}

	ambient_timer++;

	if (		(CTurokMovement.WaterFlag == PLAYER_BELOW_WATERSURFACE)
			&&	(!CTurokMovement.InAntiGrav) )
	{
		return;
	}

	// we dont want to add to confusion of battle
	if(CTMove__IsInCombat(&CTurokMovement))
	{
		return;
	}

	// get region set ambient type
	rand_type = AMB_RANDOMIZE_FAR;

	switch(CTurokMovement.AmbientSound)
	{
		case	REG_AMBIENTJUNGLE:
			D_800ECF78 = AMB_RGN_JUNGLE;
			break;

		case	REG_AMBIENTWATER:
			D_800ECF78 = AMB_RGN_WATER;
			break;

		case	REG_AMBIENTCAVES:
			D_800ECF78 = AMB_RGN_CAVES;
			break;

		case	REG_AMBIENTCATACOMBS:
			D_800ECF78 = AMB_RGN_CATACOMBS;
			break;

		case	REG_AMBIENTLOSTLANDS:
			D_800ECF78 = AMB_RGN_LOSTLANDS;
			break;

		case	REG_AMBIENTCAMPAIGNERSLAIR:
			D_800ECF78 = AMB_RGN_CAMPAINER;
			break;

		case	REG_AMBIENTCATACOMBLARGE:
			D_800ECF78 = AMB_RGN_CATACOMBS_LARGE;
			break;

		case REG_AMBIENTCITY:
			D_800ECF78 = AMB_RGN_CITY;
			break;

		case REG_AMBIENTRUINS:
			D_800ECF78 = AMB_RGN_RUINS;
			break;

		case REG_AMBIENTTREETOP:
			D_800ECF78 = AMB_RGN_TREETOP;
			break;

		case REG_AMBIENTWARP:
			D_800ECF78 = AMB_RGN_WARP;
			break;

		default:
		case	REG_AMBIENTNONE:
			D_800ECF78 = -1;
			break;
	}

	if(D_800ECF78 == AMB_RGN_CATACOMBS_LARGE)
		D_800ECF78 = AMB_RGN_CATACOMBS;	// same sounds as small catacombs

	if(D_800ECF78 >= 0)
	{
		pSoundList = &D_800ECF94[D_800ECF78];

		if(pSoundList->TotalNum == 0)
			return;

		// Make intro have bigger probabilities
		Prob = pSoundList->Probability ;
		if ((GetApp()->m_Mode == MODE_INTRO) || (GetApp()->m_Mode == MODE_TITLE))
			Prob *= 2 ;

		if(CheckProbability(Prob) == TRUE)
		{
			s = SOUND_RANDOM(pSoundList->TotalNum);

			if(pSoundList->SoundNum[s] >= 0)
				func_80031974(&GetApp()->m_Scene, pSoundList->SoundNum[s], 0, NULL, &AW.Ears.vPos, rand_type);
		}
	}

	//audio_ambient_flags = 0;	// clear flag
}
