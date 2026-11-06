#include "common_local_source_5500.h"

#line 1284 "reference.c"
void UpdateEnvironmentSound(t_SoundPlayer	*sndplayer, INT16	i)
{
	t_Channel		*pChannel = &AW.VoiceChannels[i];
	static INT8		EnvFadeoutValue[MAX_VOICES];

	ASSERT(sndplayer->idlist[i] != -1);
	ASSERT(sndplayer->idlist[i] < MAX_VOICES);

	if((SetChannel(i) == AL_STOPPED) && (pChannel->ChannelFlags & CH_FLAG_ENV_UPDATE))
	{
		DeallocateChannel(i);
	}
	else
	{
		pChannel->ChannelFlags  |= CH_FLAG_ENV_UPDATE ;

		if((AW.sfx_timer - pChannel->theSFX.StartTime) > ENVIRONMENT_LIFE)
		{
			//rmonPrintf("env stopping(%d:%d)\n", i, AW.sfx_timer - pChannel->theSFX.StartTime);

			if((pChannel->ChannelFlags & CH_FLAG_ENV_FADEOUT) == 0)
			{
				// particle effect has finished do quick fade out
				EnvFadeoutValue[i] = 10;
				pChannel->ChannelFlags |= CH_FLAG_ENV_FADEOUT;
			}
			else
			{
				EnvFadeoutValue[i]--;
				pChannel->theSFX.Vol -= 3200;

				if(pChannel->theSFX.Vol < 0)
				{
					pChannel->theSFX.Vol = 0;
					StopChannel(i);
				}
				else
					modifySFX(AW.VoiceChannels[i].VirtualHandle);

			}
		}
	}
}
