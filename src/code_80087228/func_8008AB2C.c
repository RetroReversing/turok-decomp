#include "common_local_source_5500.h"

#line 1284 "reference.c"
void func_8008AB2C(t_SoundPlayer	*sndplayer, INT16	i)
{
	t_Channel		*pChannel = &AW.VoiceChannels[i];
	static INT8		EnvFadeoutValue[MAX_VOICES];

	ASSERT(sndplayer->idlist[i] != -1);
	ASSERT(sndplayer->idlist[i] < MAX_VOICES);

	if((func_80089EC4(i) == AL_STOPPED) && (pChannel->ChannelFlags & CH_FLAG_ENV_UPDATE))
	{
		func_80089F10(i);
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
					func_8008A3B8(AW.VoiceChannels[i].VirtualHandle);

			}
		}
	}
}
