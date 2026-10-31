#include "common.h"

typedef struct {u8 pad[0x1c]; void *sound;u8 pad2[8];s32 state;u32 tail;} SoundState;
typedef struct {u8 pad[0x3c];s32 target;SoundState *sndState;} SndPlayer;
s32 alSndpGetState(SndPlayer *sndp)
{
 SoundState *sState = (SoundState *)sndp->sndState;
 return (sState + sndp->target)->state;
}
