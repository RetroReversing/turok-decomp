#include "common.h"

typedef struct {u8 pad[0x3c];s32 target;char *sndState;} SndPlayer;
typedef struct {s16 type;u16 pad;void *state;s16 value;char pad2[8-sizeof(s16)];} Event;
void alEvtqPostEvent(void*,Event*,s32);
void alSndpSetVol(SndPlayer *sndp,s16 value)
{
 Event evt;
 char *sState=sndp->sndState;
 evt.type=3;
 evt.state=sState+sndp->target*48;
 evt.value=value;
 alEvtqPostEvent((char*)sndp+20,&evt,0);
}
