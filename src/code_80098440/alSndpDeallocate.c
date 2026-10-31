#include "common.h"

typedef struct {u8 pad[0x1c]; void *sound;u8 pad2[8];s32 state;u32 tail;} SoundState; typedef struct {u8 pad[0x3c];s32 target;SoundState *sndState;} SndPlayer;
void alSndpDeallocate(SndPlayer *sndp,s16 id)
{
 SoundState *sState=sndp->sndState;
 if((sState+id)->state!=0) return;
 sState[id].sound=0;
 if(sndp->target==id) sndp->target=-1;
}
