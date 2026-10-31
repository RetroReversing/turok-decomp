#include "common.h"

typedef struct {u8 pad[0x3c];s32 target;char *sndState;} SndPlayer;
typedef struct {s16 type;u16 pad;void *state;u8 value;char pad2[8-sizeof(u8)];} Event;
void alEvtqPostEvent(void*,Event*,s32);
void alSndpSetFXMix(SndPlayer *sndp,u8 value)
{
 Event evt;
 char *sState=sndp->sndState;
 evt.type=8;
 evt.state=sState+sndp->target*48;
 evt.value=value;
 alEvtqPostEvent((char*)sndp+20,&evt,0);
}
