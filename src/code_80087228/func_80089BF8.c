#include "common_local_source_5484.h"

#line 454 "reference.c"
INT16 func_80089BF8(INT32 VirtualHandle, CVector3 *vPos, int flags)
{
//	t_SoundPlayer	*sndplayer;
	INT16				Channel;
	ALSndPlayer		*Sndp;
	t_SndObject		*sndptr;
	OSPri				ospri;



	if(VirtualHandle == -1)
	{
		return -1;
	}

	Channel = SoundHandleToChannel(VirtualHandle, 0);
	if(Channel == -1)
	{
		return -1;
	}

	if(Channel == DUMMY_CHANNEL)
	{
		func_8008A0EC(DUMMY_CHANNEL, VirtualHandle, vPos);
		return -1;
	}

	ospri = osGetThreadPri(NULL);
	osSetThreadPri(NULL, PRIORITY_AUDIOLOCK);

//	sndplayer = &AW.SndPlayerList;
	Sndp = AW.VoiceChannels[Channel].SndPlayer;
	sndptr = &AW.VoiceChannels[Channel].theSFX;


	// Special case check for sounds that always need to be started!!!
	switch(AW.VoiceChannels[Channel].theSFX.CfxNum)
	{
		// minigun & shockwave looping sfx's
		case SOUND_MINI_GUN_WHIR:
		case SOUND_GENERIC_164:

		// trex sounds
		case SOUND_TREX_SERVO_1:		// laser
		case SOUND_TREX_FIRE_BREATHE:

		// humvee sounds
		case SOUND_GENERIC_82:
		case SOUND_GENERIC_83:
		case SOUND_GENERIC_84:
		case SOUND_GENERIC_85:
		case SOUND_GENERIC_86:
		case SOUND_GENERIC_87:
			break ;

		default:
			if ((sndptr->Vol == 0) && !( AW.VoiceChannels[Channel].ChannelFlags & VOL_ENV_ENABLED) )
			{
				// will get deallocated in UpdateWorldSound()
				AW.VoiceChannels[Channel].ChannelFlags  |= CH_FLAG_STARTED ;
				AW.ChannelLock = -1;

				osSetThreadPri(NULL, ospri);
				return 0;
			}
	}

	if(func_80089EC4(Channel)!= AL_STOPPED)
	{
		AW.ChannelLock = -1;
		osSetThreadPri(NULL, ospri);
		return 0;
	}

	alSndpSetPitch(Sndp, sndptr->Pitch);
#ifdef SOUND_USE_REVERB
	alSndpSetFXMix(Sndp, sndptr->FXmix);
#else
	alSndpSetFXMix(Sndp, 0);
#endif
   alSndpSetPan(Sndp, sndptr->Pan);

   alSndpSetVol(Sndp, sndptr->Vol*__GlobalSFXscalar);

	if(AW.VoiceChannels[Channel].delay == 0)
	{
		func_80089E70(Channel);
	}

	AW.ChannelLock = -1;
	osSetThreadPri(NULL, ospri);
	return 0;
}
