#include "decompdecomp_sync_6cbc72cad54ce98e4008.h"
#line 1 "func.c"
#line 2837 "reference.c"
void CLoad__ExtractData(void)
{
//	float				VolChange;
	CPersistantData	*persist ;
	persist = (CPersistantData *)CScene__GetPersistantDataStruct((CScene*)D_800FA3C8) ;

	//rmonPrintf("ptr:%08x\n", persist) ;
	//rmonPrintf("data:%08x\n", persistant_data) ;

	CTurokMovement.SemiAutomaticPistolFlag		= persist->SemiAutomaticPistolFlag ;
	CTurokMovement.RiotShotgunFlag				= persist->RiotShotgunFlag ;
	CTurokMovement.AutomaticShotgunFlag			= persist->AutomaticShotgunFlag ;
	CTurokMovement.AssaultRifleFlag				= persist->AssaultRifleFlag ;
	CTurokMovement.MachineGunFlag					= persist->MachineGunFlag ;
	CTurokMovement.MiniGunFlag						= persist->MiniGunFlag ;
	CTurokMovement.GrenadeLauncherFlag			= persist->GrenadeLauncherFlag ;
	CTurokMovement.TechWeapon1Flag				= persist->TechWeapon1Flag ;
	CTurokMovement.RocketFlag						= persist->RocketFlag ;
	CTurokMovement.ShockwaveFlag					= persist->ShockwaveFlag ;
	CTurokMovement.TechWeapon2Flag				= persist->TechWeapon2Flag;
	CTurokMovement.ChronoscepterFlag				= persist->ChronoSceptorFlag;

	CTurokMovement.ArmorFlag						= persist->ArmorFlag ;
	CTurokMovement.BackPackFlag					= persist->BackPackFlag ;

	CTurokMovement.BulletPool						= persist->BulletPool,
	CTurokMovement.ShotgunPool						= persist->ShotgunPool,
	CTurokMovement.EnergyPool						= persist->EnergyPool,
	CTurokMovement.ExpTekBowAmmo					= persist->ExpTekBowAmmo,
	CTurokMovement.ExpShotgunPool					= persist->ExpShotgunPool,
	CTurokMovement.TekBowAmmo						= persist->TekBowAmmo,
	CTurokMovement.MiniGunAmmo						= persist->MiniGunAmmo,
	CTurokMovement.GrenadeLauncherAmmo			= persist->GrenadeLauncherAmmo,
	CTurokMovement.RocketAmmo						= persist->RocketAmmo,
	CTurokMovement.TechWeapon2Ammo				= persist->TechWeapon2Ammo;
	CTurokMovement.ChronoscepterAmmo				= persist->ChronoSceptorAmmo;

	CTurokMovement.WeaponSelectIndex				= persist->WeaponUsing ;

	CTurokMovement.ArmorAmount						= persist->ArmorAmount ;
	CTurokMovement.Level2Keys						= persist->Level2Keys ;
	CTurokMovement.Level3Keys						= persist->Level3Keys ;
	CTurokMovement.Level4Keys						= persist->Level4Keys ;
	CTurokMovement.Level5Keys						= persist->Level5Keys ;
	CTurokMovement.Level6Keys						= persist->Level6Keys ;
	CTurokMovement.Level7Keys						= persist->Level7Keys ;
	CTurokMovement.Level8Keys						= persist->Level8Keys ;
	CTurokMovement.Level2Access					= persist->Level2Access ;
	CTurokMovement.Level3Access					= persist->Level3Access ;
	CTurokMovement.Level4Access					= persist->Level4Access ;
	CTurokMovement.Level5Access					= persist->Level5Access ;
	CTurokMovement.Level6Access					= persist->Level6Access ;
	CTurokMovement.Level7Access					= persist->Level7Access ;
	CTurokMovement.Level8Access					= persist->Level8Access ;

	CTurokMovement.ChronoSceptorPieces			= persist->ChronoSceptorPieces ;


	CTurokMovement.RunWalkToggle					= persist->RunWalk ;
	GetApp()->m_Options.m_RHControl				= persist->ControlSide ;
	GetApp()->m_Options.m_Blood					= persist->Blood ;
//	GetApp()->m_Options.m_Stereo					= persist->Stereo ;
  	GetApp()->m_Options.m_MusicVolume			= persist->MusicVolume ;
  	GetApp()->m_Options.m_SFXVolume				= persist->SFXVolume ;
  	GetApp()->m_Options.m_Opacity					= persist->Opacity ;	
  	GetApp()->m_Options.m_HAnalog					= persist->HAnalog	;
  	GetApp()->m_Options.m_VAnalog					= persist->VAnalog	;

	CTControl__CTControl(GetApp()->m_Options.m_RHControl) ;

	// set music volume
	GetApp()->m_ActualMusicVolume = ((float)GetApp()->m_Options.m_MusicVolume / 255.0);
//	VolChange = GetApp()->m_Options.m_MusicVolume/255.0;
//	__GlobalSEQvolume = (INT16)(VolChange * MAX_SEQ_VOL);
//	alCSPSetVol(seqp, __GlobalSEQvolume);
	// set sfx volume
	GetApp()->m_ActualSFXVolume = ((float)GetApp()->m_Options.m_SFXVolume / 255.0);
//	__GlobalSFXscalar = GetApp()->m_Options.m_SFXVolume/255.0;


//	rmonPrintf("analog read:%d\n", persist->Analog) ;

	GetApp()->m_Difficulty							= persist->Difficulty ;

	D_8010201C->m_AI.m_Health = persist->Health ;
	CTurokMovement.MaxHealth = persist->MaxHealth ;
	
	CTurokMovement.Tokens							= persist->Tokens ;
	CTurokMovement.Lives								= persist->Lives ;

	//rmonPrintf("load health:%d\n", persist->Health) ;
	//rmonPrintf("load lives:%d\n", persist->Lives) ;

	//GetApp()->m_WarpID								= persist->Checkpoint ;
	CTurokMovement.CurrentCheckpoint				= persist->Checkpoint ;
	GetApp()->m_dwCheatFlags 						= persist->CheatFlags ;
	GetApp()->m_dwEnabledCheatFlags 				= persist->EnabledCheatFlags ;

	GetApp()->m_BestTrainTime		 				= persist->BestTrainTime ;

	GetApp()->m_BossFlags			 				= persist->BossFlags ;
}

