#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct LiveFilter LiveFilter;
struct LiveFilter {void *next;void *handler;s32(*setParam)(LiveFilter*,s32,void*);};
typedef struct {u8 pad[12];LiveFilter *channelKnob;u8 pad2[200];s32 offset;} LivePVoice;
typedef struct {u8 pad[8];LivePVoice *pvoice;} LiveVoice;
typedef struct {u8 pad[28];s32 paramSamples;} LiveSynth;
typedef struct {void *next;s32 delta;s16 type;LivePVoice *pvoice;} LiveFreeParam;
void *__allocParam(void);void _freePVoice(LiveSynth*,LivePVoice*);
void alSynFreeVoice(LiveSynth *drvr,LiveVoice *voice)
{
 LiveFilter *f;
 LiveFreeParam *update;
 if(voice->pvoice) {
  if(voice->pvoice->offset) {
   update=__allocParam();
   if(!update) return;
   {
    update->delta=drvr->paramSamples+voice->pvoice->offset;
    update->type=0;
    update->pvoice=voice->pvoice;
    f=voice->pvoice->channelKnob;
    (*f->setParam)(f,3,update);
   }
  } else {
   _freePVoice(drvr,voice->pvoice);
  }
  voice->pvoice=0;
 }
}

