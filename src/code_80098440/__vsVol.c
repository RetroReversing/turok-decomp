#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct {u8 pad[13];u8 sampleVolume;} Sound;
typedef struct {u8 pad[9];u8 vol;u8 rest[6];} Channel;
typedef struct {u8 pad[0x20];Sound *sound;u8 pad2[12];u8 envGain,channel,field32,velocity;u8 field34,field35,tremelo;} Voice;
typedef struct {u8 pad[0x32];s16 vol;u8 pad2[44];Channel *chanState;} Player;
s16 __vsVol(Voice *vs,Player *seqp)
{
 u32 t1,t2;
 t1=(vs->tremelo*vs->velocity*vs->envGain)>>6;
 t2=(vs->sound->sampleVolume*seqp->vol*seqp->chanState[vs->channel].vol)>>14;
 t1*=t2;t1>>=15;
 return (s16)t1;
}

